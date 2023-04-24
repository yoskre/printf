#ifndef MAIN_H
#define MAIN_H
#include <stdio.h> /* debug */

int _printf(const char *format, ...);
int get_fs(const char *format);
char *get_c(const char *format, int i, int arg);
char *get_s(const char *format, int i, char *arg);
char *get_esc(const char *format, int i, char arg);

#endif
