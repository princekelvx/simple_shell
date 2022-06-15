#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

/* printing functions */
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/* loop */
void loop(void);
void _EOF(char *buff);
void handle(int signals);
void shell_exit(char **command);

/* create child */
void create_child(char **command, char *name, char **env, int cycles);
int change_dir(const char *path);

/* execute */
void execute(char **command, char *name, char **env, int cycles);
void print_env(char **env);
char **_getPATH(char **env);
void msgerror(char *name, int cycles, char **command);

/* tokening */
char **tokening(char *buffer, const char *s);

/* free memory */
void free_dp(char **command);
void free_exit(char **command);
#endif

