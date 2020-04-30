/**
 * place_first.cpp -- функция добавления строки в начало файла
 *
 * Copyright (c) 2020, Nikita Semenov <ndsemeno@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "place_first.h"
#include "show.h"

void place_first(text txt, const string line)
{
    add_begin(txt, line);
    show(txt);
}
