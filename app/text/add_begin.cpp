/**
 * Copyright (c) 2020, Nikita Semenov <ndsemeno@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

void add_begin(text txt, string contents)
{
    /* Ставим строку в начало и обновляем положение курсора */
    contents = contents + '\n';
    txt->lines.push_front(contents);
    txt->cursor->line = txt->lines.begin();
    txt->cursor->pos = contents.size() - 1;
}
