
/* 
 * File:   Exception.h
 * Author: daniele
 *
 * Created on 9 aprile 2017, 16.37
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

#ifdef __cplusplus
extern "C" {
#endif
#include "Object.h"
#include <setjmp.h>
    
#define NO_EXC 0
    
    typedef unsigned int exc_code;
    
    jmp_buf jmpBuff;

    void throw(exc_code);

#ifdef __cplusplus
}
#endif

#endif /* EXCEPTION_H */

