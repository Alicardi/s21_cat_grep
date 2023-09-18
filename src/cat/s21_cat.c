#include "s21_cat.h"

int main(int argc, char **argv) {
  if (argc > 1) {
    if (arguments(argc, argv) == 0) analiz_fun(argc, argv);
  }
  return 0;
}

int arguments(int argc, char **argv) {
  int opt = 0;
  int fail = 0;

  while ((opt = getopt_long(argc, argv, "+benstvTE", long_options, NULL)) !=
         -1) {
    switch (opt) {
      case 'b':
        bflag = 1;
        break;
      case 'e':
        eflag = vflag = 1;
        break;
      case 'n':
        nflag = 1;
        break;
      case 's':
        sflag = 1;
        break;
      case 't':
        tflag = vflag = 1;
        break;
      case 'v':
        vflag = 1;
        break;
      case 'T':
        tflag = 1;
        break;
      case 'E':
        eflag = 1;
        break;
      default:
        printf(
            "usage: cat [-benstvTE] or [--number-nonblank --number "
            "--squeeze-blank] [file...]\n");
        fail = 1;
        break;
    }
  }
  return fail;
}

void analiz_fun(int argc, char *argv[]) {
  FILE *fp = NULL;
  int now_line;
  int count = 0;

  for (int i = optind; i < argc; i++) {
    int last_line = '\n';
    int Num_bn = 1;
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      fprintf(stderr, "%s: %s: No such file or derectory", argv[0], argv[i]);
      continue;
    }

    while ((now_line = fgetc(fp)) != EOF) {
      if (sflag && last_line == '\n' && now_line == '\n')
        count++;
      else
        count = 0;
      if (count <= 1) {
        if ((nflag && last_line == '\n' && !bflag) ||
            (bflag && now_line != '\n' && last_line == '\n'))
          printf("%6d\t", Num_bn++);
        if (tflag) work_t(&now_line);
        if (vflag) work_v(&now_line);
        if (eflag) work_e(&now_line);
        printf("%c", now_line);
        last_line = now_line;
      }
    }
    fclose(fp);
  }
}

void work_v(int *now_line) {
  if ((*now_line >= 0 && *now_line <= 31 && *now_line != '\n' &&
       *now_line != '\t') ||
      *now_line == 127) {
    if (*now_line == 127) {
      printf("^");
      *now_line = *now_line - 64;
    } else {
      printf("^");
      *now_line = *now_line + 64;
    }
  }
}

void work_t(int *now_line) {
  if (*now_line == '\t') {
    printf("^");
    *now_line = 'I';
  }
}

void work_e(int *now_line) {
  if (*now_line == '\n') printf("$");
}
