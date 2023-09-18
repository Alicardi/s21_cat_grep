#ifndef S21_GREP_H_
#define S21_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAT_COUNT 4096
#define STR_COUNT 4096
#define NEW_COUNT 4096

int arguments(int argc, char *argv[], char *buf);
void open_file(int argc, char *argv[], char *buf);
void only_e_flag(char *buf);
void only_f_flag(char *buf, char *argv[], int *fail);
void workspase(FILE *fp, char *buf, char *argv[], int *count_file);
void work_flag(regex_t *regex, char *str, int *line_n, int *line_c, int *flag,
               int *count_file, char *argv[], FILE *fp, int *new_line);
void only_o_flag(regmatch_t matchptr[1], char *str, char *argv[], int *line_n,
                 int *count_file, regex_t *regex, int *new_line, size_t nmatch);

int eflag = 0;
int iflag = 0;
int vflag = 0;
int cflag = 0;
int lflag = 0;
int nflag = 0;
int hflag = 0;
int sflag = 0;
int fflag = 0;
int oflag = 0;

#endif