#include "Process.h"

/*
 *      Static
 */

static void waitChild(int sig) {
    int status, pid;
    struct Process * proc;
    while ((pid = waitpid((pid_t) (-1), &status, WNOHANG)) > 0) {
        proc = getObj(pid);
        removeProcess(pid, proc);
        if (WIFEXITED(status)) {
            fprintf(stdout, "\n\t[child terminated] pid: %d; instance of: %s; exit status %d;\n", pid, proc->name, WEXITSTATUS(status));
            fflush(stdout);
            if (WEXITSTATUS(status) == 0) {
                proc->onSuccess(0);
            } else {
                proc->onFailure(WEXITSTATUS(status));
            }
        } else if (WIFSIGNALED(status)) {
            fprintf(stdout, "\n\t[child terminated] pid: %d; instance of: %s; signal no. %d;\n", pid, proc->name, WTERMSIG(status));
            fflush(stdout);
            proc->onFailure(WTERMSIG(status));
        }
    }
}

/*
 *      Method implementation
 */

static void * ProcessClass_ctor(void * _self, va_list * app) {
    struct ProcessClass * self = super_ctor(ProcessClass, _self, app);
    typedef void (*voidf) ();
    voidf selector;
    va_list ap;
    va_copy(ap, *app);
    while ((selector = va_arg(ap, voidf))) {
        voidf method = va_arg(ap, voidf);
        if (selector == (voidf) run) {
            *(voidf *) & self->run = method;
        }
        if (selector == (voidf) die) {
            *(voidf *) & self->die = method;
        }
    }
    va_end(ap);
    return self;
}

static void * Process_ctor(void * _self, va_list * app) {
    //int val = 1;
    struct Process * self = super_ctor(Process, _self, app);
    self->name = va_arg(*app, char *);
    self->func = va_arg(*app, void *);
    self->onSuccess = va_arg(*app, void *);
    self->onFailure = va_arg(*app, void *);
    self->timeout = va_arg(*app, int);
    self->instRunning = 0;
    pipe(self->fdPipe);
    return self;
}

static void * Process_dtor(void * _self, va_list * app) {
    struct Process * self = _self;
    while (self->instRunning) {
        read(self->fdPipe[0], 0, sizeof (int));
    }
    close(self->fdPipe[0]);
    close(self->fdPipe[1]);
    return super_dtor(Process, self);
}

static void Process_run(void * _self, va_list * app) {
    int code, pid;
    struct Process * self = _self;
    struct sigaction sa;

    sa.sa_handler = &waitChild;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_NOCLDSTOP;
    if (sigaction(SIGCHLD, &sa, 0) == -1) {
        perror(0);
        exit(1);
    }

    switch (code = setjmp(jmpBuff)) {
        case NO_EXC:
            pid = fork();
            if (pid == 0) {
                alarm(self->timeout);
                self->func(app);
                exit(EXIT_SUCCESS);
            } else if (pid < 0) {
                throw(FORK_EXC);
            }
            addProcess(self, pid);
            break;
        case FORK_EXC:
            perror("Fork exception.\n");
            exit(FORK_EXC);
            break;
        case WAIT_EXC:
            perror("Wait exception.\n");
            exit(WAIT_EXC);
            break;
        default:
            fprintf(stderr, "Unhandled exception:\n"
                    "\tcode: %d\n"
                    "\tprocess name: %s\n"
                    "\t", code, self->name);
            exit(-1);
    }
}

static void Process_die(void * _self) {
    struct Process * self = _self;
    int * pids = getPids(self);
    while (*pids) {
        kill(*pids, SIGKILL);
        pids++;
    }
}

/*
 *      Global functions
 */

void run(const void * _self, ...) {
    const struct ProcessClass * class = classOf((const void *) _self);
    assert(class->run);
    va_list ap;
    va_start(ap, _self);
    class->run(_self, &ap);
    va_end(ap);
}

void die(const void * _self) {
    const struct ProcessClass * class = classOf(_self);
    assert(class->die);
    class->die(_self);
}

char * getName(const void * _self) {
    const struct Process * proc = _self;
    assert(proc->name);
    return proc->name;
}

/*
 *      Init
 */

const void * ProcessClass, * Process;

void initProcess(void) {
    initProcessTree();
    if (!ProcessClass) {
        ProcessClass = new(Class,
                "ProcessClass",
                Class,
                sizeof (struct ProcessClass),
                ctor, ProcessClass_ctor,
                0);
    }
    if (!Process) {
        Process = new(ProcessClass,
                "Process",
                Object,
                sizeof (struct ProcessClass),
                ctor, Process_ctor,
                dtor, Process_dtor,
                run, Process_run,
                die, Process_die,
                0);
    }
}