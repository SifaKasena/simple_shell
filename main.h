#ifndef _MAIN_H_
#define _MAIN_H_

extern char **environ;
int call_child(char **argv, char **envp);
void call_commands(char **commands);
char **split_string(char *s, char *c);
char *_strtok(char *str, const char *delim);
char *_which(char *file);
char *_getenv(char *env);

#endif
