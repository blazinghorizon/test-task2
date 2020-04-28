/**
 * load.cpp -- функция загрузки текста из файла
 *
 * Copyright (c) 2020, Filin Nikolay  <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include "load.h"
#include "text/text.h"


void load(text txt, char* filename)
{
    FILE *f;
    char buf[MAXLINE + 1];

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen(filename, "r")) == NULL) {
        printf("The file %s cannot be opened\n", filename);
        return;
    }

    /* Удаляем предыдущее содержимое */
    remove_all(txt);

    /* Считываем содержимое строка за строкой и загружаем*/
    while (fgets(buf, MAXLINE, f)) {
        string s = (char*) buf;
	append_line(txt, s);
    }
    fclose(f);
}
