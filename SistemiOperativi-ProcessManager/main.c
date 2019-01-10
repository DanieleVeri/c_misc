/* 
 * File:   main.c
 * Author: daniele
 *
 * Created on 3 aprile 2017, 12.09
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include "Process.h" 

void f1(va_list * app);
void f2(va_list * app);
void succ(int r);
void fail(int r);

int main(int argc, char** argv) {
    void * p1, * p2;
    int i = 5;
    initProcess();
    p1 = new(Process, "Process 1", f1, succ, fail, 1000);
    p2 = new(Process, "Process 2", f2, succ, fail, 1000);
    while (i) {
        run(p1, i);
        i--;
    }
    sleep(10);
    run(p1, 99);
    delete(p1);  
    delete(p2);
    return EXIT_SUCCESS;
}

void f11(va_list * app) {
    printf("Running last [pid:%d]\n", getpid());
    sleep(1);
    fflush(stdout);
    return;
}

void f1(va_list * app) {
    int i = va_arg(*app, int);
    void * p = new(Process, "lol", f11, succ, fail, 100);
    printf("Running %d [pid:%d]\n", i, getpid());
    run(p);
    
    sleep(1);
    fflush(stdout);
    delete(p);
    return;
}

void f2(va_list * app) {
    fflush(stdout);
    return;
}

void succ(int r) {
    printf("Successo.\n");
    fflush(stdout);
    sleep(1);
}

void fail(int r) {
    printf("Fallito con codice %d.\n", r);
    fflush(stdout);
}