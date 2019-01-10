
/* 
 * File:   Process.h
 * Author: daniele
 *
 * Created on 4 aprile 2017, 12.44
 */

#ifndef PROCESS_H
#define PROCESS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include "Object.h"
#include "Exception.h"
#include "ProcessTree.h"
    
#define FORK_EXC 1
#define WAIT_EXC 2

    extern const void * Process, * ProcessClass;

    void initProcess(void);

    /* 
     *      Attributes
     */

    struct Process {
        const struct Object _;
        /* public */
        char * name;
        /* private */
        void (*func) (va_list * app);
        void (*onSuccess) (int retVal);
        void (*onFailure) (int retVal);
        int timeout;
        int fdPipe[2];
        int instRunning;
    };

    struct ProcessClass {
        const struct Class _;
        void (*run)(const void * _self, ...);
        void (*die)(const void * _self);
    };

    /*  
     *      Methods
     */

    void run(const void * self, ...);
    void die(const void * self);
    char * getName(const void * self);

#ifdef __cplusplus
}
#endif

#endif /* PROCESS_H */
