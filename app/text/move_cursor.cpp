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
    if (txt->lines.begin() == txt->lines.end()) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return -1;
    }
   /*Задание значений курсора*/
   list <string> :: iterator it = txt->lines.begin();

   if (str >= 0 && txt->lines.size() >= (size_t)str) {
       advance(it, str);
   } else {
       return 0;
   }

   txt->cursor->line = it;
   
   if ((*(txt->cursor->line)).size() >= (size_t) col) {
       txt->cursor->pos = col;
   } else {
       return 0;
   }

   return 1;
}


