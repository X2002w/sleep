#ifndef _KPRINGF_H
#define _KPRINGF_H

#include <stdarg.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif


// console/stdout
int kprintf(const char* fmt, ...);
int kvprintf(const char* fmt, va_list ap);

// wtite to memory buffer

#ifdef __cplusplus
}
#endif

#endif