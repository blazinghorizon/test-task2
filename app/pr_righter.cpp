/**
 * Copyright (c) 2020, Nikita Semenov <ndsemeno@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "pr_righter.h"
#include "text/text.h"
#include <assert.h>
#include <iostream>

static void print_r(int index, string contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void pr_righter(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, print_r, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void print_r(int index, string contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(!(contents.empty()));

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    /* Выводим подстроку, которая находится справа от курсора */
    if (cursor != -1)
    std::cout << contents.substr(cursor, contents.size() - cursor);
}
