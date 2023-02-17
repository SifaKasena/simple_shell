#ifndef _MAIN_H_
#define _MAIN_H_

extern char **environ;
char **split_string(char *s, char *c);
char *_which(char *file);
char *_getenv(char *env);

#endif
