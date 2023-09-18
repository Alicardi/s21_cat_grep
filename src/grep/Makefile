G = gcc
WWW = -Wall -Wextra -Werror

all: clean s21_grep style leaks

s21_grep: s21_grep.c s21_grep.h
		$(G) $(WWW) s21_grep.c -o s21_grep

clean: 
		rm -rf s21_grep
		rm -rf .clang-format

style: 
		cp ~/C3_SimpleBashUtils-1/materials/linters/.clang-format ~/C3_SimpleBashUtils-1/src/grep
		clang-format -n s21_grep.c s21_grep.h

leaks: leaks_e leaks_i leaks_v leaks_c leaks_l leaks_n leaks_h leaks_s leaks_f leaks_o

leaks_e: #1
		leaks -atExit -- ./s21_grep -e Depp -e Alice test_1.txt

leaks_i: #2
		leaks -atExit -- ./s21_grep -i depp test_1.txt

leaks_v: #3
		leaks -atExit -- ./s21_grep -v Depp test_1.txt

leaks_c: #4
		leaks -atExit -- ./s21_grep -c Depp test_1.txt

leaks_l: #5
		leaks -atExit -- ./s21_grep -l Depp test_1.txt test_2.txt

leaks_n: #6
		leaks -atExit -- ./s21_grep -n Depp test_1.txt test_2.txt

leaks_h: #7
		leaks -atExit -- ./s21_grep -h Depp test_1.txt test_2.txt

leaks_s: #8
		leaks -atExit -- ./s21_grep -s Depp test_1.txt test_2.tx

leaks_f: #9
		leaks -atExit -- ./s21_grep -f i_pattern.txt -f i_pattern_2.txt test_1.txt

leaks_o: #10
		leaks -atExit -- ./s21_grep -o Depp test_1.txt

autotest: my_test_grep.sh
		sh my_test_grep.sh

rebuild:
		$(MAKE) clean
		$(MAKE) s21_grep