/*
 * Author: Zhylko Barys
 *
 * Главный модуль программы.
 * Программа получает строку из аргументов командной строки,
 * удаляет из неё пробелы и разделяет символы по четным/нечетным индексам.
 * 
 * Использование: ./program "исходная строка с пробелами"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_proc.h"

#define MAX_STR_LEN 1024

/*
 * Функция: print_result
 * Назначение: выводит результаты обработки на экран
 */
static void print_result(const char *original, 
                        const char *no_spaces,
                        const char *even,
                        const char *odd)
{
    printf("Исходная строка: \"%s\"\n", original);
    printf("Строка без пробелов: \"%s\"\n", no_spaces);
    printf("Четные индексы (0,2,4,...): \"%s\"\n", even);
    printf("Нечетные индексы (1,3,5,...): \"%s\"\n", odd);
}

/*
 * Функция: main
 * Назначение: точка входа в программу
 * Возвращает: 0 при успешном выполнении, 1 при ошибке
 */
int main(int argc, char *argv[])
{
    char no_spaces[MAX_STR_LEN];
    char even_chars[MAX_STR_LEN];
    char odd_chars[MAX_STR_LEN];
    if (argc < 2)
    {
        fprintf(stderr, "Ошибка: не указана входная строка\n");
        fprintf(stderr, "Использование: %s \"строка для обработки\"\n", 
                argv[0]);
        return 1;
    }
    remove_spaces(argv[1], no_spaces);
    split_by_indices(no_spaces, even_chars, odd_chars);
    print_result(argv[1], no_spaces, even_chars, odd_chars);
    return 0;
}