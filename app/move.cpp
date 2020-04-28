/**
 * move.cpp -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "move.h"
#include "text/text.h"

int move(text txt, int str, int col)
{
    /* Меняем позицию курсора и выводим*/
    int res = move_cursor(txt, str, col);

    return res;
}

