# s21_cat_grep

![Cat&&Grep](/img/cat&&grep.png)

## Содержание

1. [Cat](#Cat)
2. [Grep](#Grep)
3. [Использование утилит](#Использование-утилит)

## Cat

Команда `cat` используется для вывода содержимого любого файла в терминал. 

| № | Опции | Описание |
| --- | --- | --- |
| 1 | -b (GNU: --number-nonblank) | нумерует только непустые строки
| 2 | -e предполагает и -v (GNU only: -E то же самое, но без применения -v) | также отображает символы конца строки как $ |
| 3 | -n (GNU: --number) | нумерует все выходные строки | 
| 4 | -s (GNU: --squeeze-blank) | сжимает несколько смежных пустых строк |
| 5 | -t предполагает и -v (GNU: -T то же самое, но без применения -v) | также отображает табы как ^I |

## Grep

Команда `grep` используется для поиска определенно заданного значения в файле.

| № | Опции | Описаниe |
| --- | --- | --- |
| 1 | -e | Шаблон | 
| 2 | -i | Игнорирует различия регистра. |
| 3 | -v | Инвертирует смысл поиска соответствий. |
| 4 | -c | Выводит только количество совпадающих строк. | 
| 5 | -l | Выводит только совпадающие файлы. | 
| 6 | -n | Предваряет каждую строку вывода номером строки из файла ввода. |
| 7 | -h | Выводит совпадающие строки, не предваряя их именами файлов. |
| 8 | -s | Подавляет сообщения об ошибках о несуществующих или нечитаемых файлах. |
| 9 | -f file | Получает регулярные выражения из файла. | 
| 10 | -o | Печатает только совпадающие (непустые) части совпавшей строки. | 

## Использование утилит

- У каждой утилиты есть Makefile, благодаря ему можно совершить скомпиляцию, проверить на clang-format и утечки.
- После этого можно запускать программу с помощью `./s21_<название_утилиты>`
- Каждая утилита работает по аналогии с оригинальными утилитами Cat и Grep. 
