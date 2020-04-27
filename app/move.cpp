/**
 * move.cpp -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include "move.h"
#include "text/text.h"
#include <string.h>
#include <assert.h>

int move(text txt, int str, int col)
{
    /* Меняем позицию курсора и выводим*/
    int res = move_cursor(txt, str, col);

    if (res == 0)
        return 0;

    if (res == -1)
        return -1;

    return 1;
}

