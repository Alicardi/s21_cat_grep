#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0
DIFF=""

gcc -Werror -Wextra -Wall s21_cat.c -o s21_cat

all_flags=("b" "e" "n" "s" "t")
input_files=("test_case_cat.txt" "test_test.txt" "test_t.txt" "test_v.txt")

echo ""
echo "###################"
echo "#### LET'S GO! ####"
echo "###################"
echo ""

for ((num_flags = 1; num_flags <= ${#all_flags[@]}; num_flags++))
do
    for flag_1 in "${all_flags[@]}"
    do
        for flag_2 in "${all_flags[@]}"
        do
            for flag_3 in "${all_flags[@]}"
            do
                for flag_4 in "${all_flags[@]}"
                do
                    for flag_5 in "${all_flags[@]}"
                    do
                        if [ "$flag_1" != "$flag_2" ] && [ "$flag_1" != "$flag_3" ] && [ "$flag_1" != "$flag_4" ] && [ "$flag_1" != "$flag_5" ] && [ "$flag_2" != "$flag_3" ] && [ "$flag_2" != "$flag_4" ] && [ "$flag_2" != "$flag_5" ] && [ "$flag_3" != "$flag_4" ] && [ "$flag_3" != "$flag_5" ] && [ "$flag_4" != "$flag_5" ]
                        then
                            if [ $num_flags == 1 ]
                            then
                                flag="-${flag_1}"
                            elif [ $num_flags == 2 ]
                            then
                                flag="-${flag_1}${flag_2}"
                            elif [ $num_flags == 3 ]
                            then
                                flag="-${flag_1}${flag_2}${flag_3}"
                            elif [ $num_flags == 4 ]
                            then
                                flag="-${flag_1}${flag_2}${flag_3}${flag_4}"
                            elif [ $num_flags == 5 ]
                            then
                                flag="-${flag_1}${flag_2}${flag_3}${flag_4}${flag_5}"
                            fi

                            for file_1 in "${input_files[@]}"
                            do
                                for file_2 in "${input_files[@]}"
                                do
                                    if [ "$flag_1" != "$flag_2" ]
                                    then
                                echo ""
                                echo "$flag $file_1 $file_2:"
                                # Выполнение вашей программы
                                ./s21_cat "$flag" "$file_1" "$file_2" > your_output.txt
                                # Выполнение оригинального grep
                                cat "$flag" "$file_1" "$file_2" > original_output.txt

                                # Сравнение результатов
                                if diff -q your_output.txt original_output.txt >/dev/null 2>&1;
                                then
                                    let "COUNTER++"
                                    let "SUCCESS++"
                                    echo "\033[92m$COUNTER\033[0m - Success"
                                else 
                                    let "COUNTER++"
                                    let "FAIL++"
                                    echo "\033[31m$FAIL\033[0m - Fail"
                                fi

                                # Удаление временных файлов
                                rm your_output.txt
                                rm original_output.txt
                                    fi
                                done
                            done
                        fi
                    done
                done
            done
        done
    done
done


echo ""
echo "###################"
echo "##### THE END #####"
echo "###################"
echo ""
echo "Total: $COUNTER, Success: $SUCCESS, Fail: $FAIL"
echo ""