/**
 * move_cursor.cpp -- создает в памяти структуры для представления текста
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

int move_cursor(text txt, int str, int col)
{
    /* Проверяем, имеется ли текст */
    if (txt->lines.size() == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return -1;
    }

   if (str >= 0 && txt->lines.size() >= (size_t)str) {
       list<string>::iterator it = txt->lines.begin();
       advance(it, str);
       txt->cursor->line = it;
   } else {
       return 0;
   }
   
   if (col > -1 && (*(txt->cursor->line)).size() > (size_t) col) {
       txt->cursor->pos = col;
   } else {
       return 0;
   }

   return 1;
}


