
/* 
 * File:   ProcessTree.h
 * Author: daniele
 *
 * Created on 12 aprile 2017, 17.29
 */

#ifndef PROCESSTREE_H
#define PROCESSTREE_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <assert.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include "Process.h"

    void initProcessTree(void);

    void addProcess(void * process, int pid);

    void removeProcess(int pid, void * process);

    void * getObj(int pid);

    int * getPids(void * process);

#ifdef __cplusplus
}
#endif

#endif /* PROCESSTREE_H */

