#include "ProcessTree.h"

static void * * pidList;
static int maxPid;

static void cleanupProcessTree(void) {
    munmap(pidList, sizeof(pidList));
}

void initProcessTree(void) {
    char buff[10];
    FILE *f;
    atexit(cleanupProcessTree);
    if (!pidList) {
        f = fopen("/proc/sys/kernel/pid_max", "r");
        fread(buff, sizeof(char), 10, f);
        fclose(f);
        maxPid = atoi(buff);
        pidList = mmap(NULL, sizeof(void *)*maxPid, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    }
}

void addProcess(void * process, int pid) {
    struct Process * obj = process;
    int val = 1;
    if (pid > 0) {
        pidList[pid] = process;
        obj->instRunning ++;
    }
}

void removeProcess(int pid, void * process) {
    struct Process * obj = process;
    int val = 1;
    assert(pid > 0 && pid < maxPid);
    pidList[pid] = 0;
    obj->instRunning --;
    if (!obj->instRunning) {
        write(obj->fdPipe[1], &val, sizeof(int));
    } 
}

int * getPids(void * process) {
    struct Process * obj = process;
    int i, j = 0, running;
    running = obj->instRunning;
    int * ret = calloc(running + 1, sizeof(int));
    for (i=0; i<maxPid; i++) {
        if (pidList[i] == process) {
            ret[j] = i;
            j++;
        }
    }
    ret[running] = 0;
    return ret;
}

void * getObj(int pid) {
    assert(pid > 0 && pid < maxPid);
    return pidList[pid];
}