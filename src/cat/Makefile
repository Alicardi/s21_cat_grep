G = gcc
WWW = -Wall -Wextra -Werror

all: clean s21_cat

s21_cat: s21_cat.c s21_cat.h
		$(G) $(WWW) s21_cat.c -o s21_cat

clean: 
		rm -rf s21_cat
		rm -rf .clang-format

style: 
		clang-format -style=Google -n *.c *.h

leaks:
		leaks -atExit -- ./s21_cat -benst test_test.txt

autotest: my_test_cat.sh
		sh my_test_cat.sh

rebuild:
		$(MAKE) clean
		$(MAKE) s21_cat