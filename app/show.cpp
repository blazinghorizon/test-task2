/**
 * show.cpp -- функция отображения содержимого файла
 *
 * Copyright (c) 2020, Nikita Semenov <ndsemeno@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "text/text.h"
#include "show.h"

static void show_line(int index, string contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
    printf("\n");
}

static void show_line(int index, string contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(!(contents.empty()));

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    string line = contents;

    if (cursor != -1) {
        line.insert(cursor, 1, '|');
    }

    /* Выводим строку на экран */
    printf("%s", line.c_str());

}
