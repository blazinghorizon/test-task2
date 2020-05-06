/**
 * rle.cpp -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <assert.h>
#include <stdio.h>
#include "rle_needed.h"
#include "text/text.h"


static void rle_line(int index, string contents, int cursor, void *data);

int rle_needed(text txt)
{
   /* Применяем функцию rle_line к каждой строке текста и удаляем текст после курсора*/
   process_forward(txt, rle_line, NULL);

   int res = rle_str(txt);

   return res;

}

static void rle_line(int index, string contents, int cursor, void *data)
{
    /*Получаем на вход существующую строку*/
    assert(!(contents.empty()));

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    int a;
    int i = 0;
    /* Выводим строку на экран */
        if (cursor != -1) {
                while (i != cursor){
                        if ((a = contents.size()) == cursor && i + 1 == cursor) a = -1; else
                        cout << contents.substr(i, 1);
                        i++;
                }
                        printf("|");
			printf("\n");
        } else cout << contents.substr(i, contents.size());
}


