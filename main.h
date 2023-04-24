#ifndef MAIN_H
#define MAIN_H

char *_strcpy(char *s1, const char *s2);
char *_strncpy(char *s1, const char *s2, int n);
int _strlen(const char *s);

int _printf(const char *format, ...);
int get_fs(const char *format);
char *get_c(const char *format, int i, int arg);
char *get_s(const char *format, int i, char *arg);
char *get_esc(const char *format, int i, char arg);

#endif
