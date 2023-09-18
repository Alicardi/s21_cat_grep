#include "s21_grep.h"

int main(int argc, char **argv) {
  char buf[PAT_COUNT] = {0};
  if (argc > 2) {
    if (arguments(argc, argv, buf) == 0) open_file(argc, argv, buf);
  }
  return 0;
}

int arguments(int argc, char **argv, char *buf) {
  int opt = 0;
  int fail = 0;

  while ((opt = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) != -1) {
    switch (opt) {
      case 'e':
        eflag++;
        only_e_flag(buf);
        break;
      case 'i':
        iflag = 1;
        break;
      case 'v':
        vflag = 1;
        break;
      case 'c':
        cflag = 1;
        break;
      case 'l':
        lflag = 1;
        break;
      case 'n':
        nflag = 1;
        break;
      case 'h':
        hflag = 1;
        break;
      case 's':
        sflag = 1;
        break;
      case 'f':
        fflag++;
        only_f_flag(buf, argv, &fail);
        break;
      case 'o':
        oflag = 1;
        break;
      default:
        printf("usage: grep [eivcln] [pattern] [file...]\n");
        fail = 1;
        break;
    }
  }
  if (!eflag && !fflag) strcat(buf, argv[optind++]);
  return fail;
}

void open_file(int argc, char *argv[], char *buf) {
  int count_file = argc - optind;
  FILE *fp = NULL;
  for (; optind < argc; optind++) {
    fp = fopen(argv[optind], "r");
    if (fp == NULL) {
      if (!sflag)
        fprintf(stderr, "%s: %s: No such file or derectory", argv[0],
                argv[optind]);
      continue;
    }
    workspase(fp, buf, argv, &count_file);
  }
  // printf("%s", buf);
}

void only_e_flag(char *buf) {
  if (eflag > 1) strcat(buf, "|");
  strcat(buf, optarg);
}

void only_f_flag(char *buf, char *argv[], int *fail) {
  FILE *open_file = NULL;
  open_file = fopen(optarg, "r");
  int now_line;
  char f_str[2] = {0};
  if (open_file != NULL) {
    while ((now_line = fgetc(open_file)) != EOF) {
      if (now_line == '\n') {
        strcat(buf, "|");
        continue;
      } else {
        f_str[0] = now_line;
        strcat(buf, f_str);
      }
    }
    if (now_line == EOF) {
      strcat(buf, "|");
    }
    fclose(open_file);
  } else if (fflag < 2) {
    fprintf(stderr, "%s: %s: No such file or derectory", argv[0], argv[optind]);
    *fail = 1;
  }
}

void workspase(FILE *fp, char *buf, char *argv[], int *count_file) {
  int new_line = 0;
  int line_n = 1;
  int line_c = 0;
  int flag = 0;
  regex_t regex;
  char str[STR_COUNT] = {0};
  int reg_i = 0;
  if (fflag) buf[strlen(buf) - 1] = '\0';
  while (fgets(str, STR_COUNT, fp) != NULL) {
    if (iflag) {
      reg_i = REG_ICASE;
    }
    regcomp(&regex, buf, REG_EXTENDED | reg_i);
    work_flag(&regex, str, &line_n, &line_c, &flag, count_file, argv, fp,
              &new_line);
    line_n++;
  }
  if (cflag) {
    if (*count_file > 1) printf("%s:", argv[optind]);
    if (lflag && line_c > 0)
      printf("1\n");
    else
      printf("%d\n", line_c);
  }

  if (lflag && flag > 0) printf("%s\n", argv[optind]);
  fclose(fp);
}

void work_flag(regex_t *regex, char *str, int *line_n, int *line_c, int *flag,
               int *count_file, char *argv[], FILE *fp, int *new_line) {
  regmatch_t matchptr[1] = {0};
  size_t nmatch = 1;

  int regular = regexec(regex, str, nmatch, matchptr, 0);

  if (vflag) {
    if (regular == REG_NOMATCH)
      regular = 0;
    else
      regular = REG_NOMATCH;
  }

  if (regular == 0) {
    if (oflag && !cflag)
      only_o_flag(matchptr, str, argv, line_n, count_file, regex, new_line,
                  nmatch);
    if (!lflag && !oflag && !cflag) {
      if ((*count_file > 1) && !hflag) {
        printf("%s:", argv[optind]);
      }
      if (nflag) {
        printf("%d:", *line_n);
      }

      if (feof(fp)) {
        printf("%s\n", str);
      } else
        printf("%s", str);
    }
    (*line_c)++;
    (*flag)++;
  }
  regfree(regex);
}

void only_o_flag(regmatch_t matchptr[1], char *str, char *argv[], int *line_n,
                 int *count_file, regex_t *regex, int *new_line,
                 size_t nmatch) {
  char *s = str;
  while (*s != '\0') {
    if (regexec(regex, s, nmatch, matchptr, 0) == 0) {
      if ((*count_file > 1) && (*new_line != *line_n)) {
        printf("%s:", argv[optind]);
      }

      for (int i = matchptr[0].rm_so; i < matchptr[0].rm_eo; i++) {
        printf("%c", s[i]);
      }
      printf("\n");

      s += matchptr[0].rm_eo;
      *new_line = *line_n;
    } else
      s++;
  }
}