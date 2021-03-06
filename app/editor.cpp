/**
 * editor.cpp -- строковый текстовый редактор
 *
 * Copyright (c) 2020, Nikita Semenov <ndsemeno@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "text/text.h"
#include "showtrimmedfromstart.h"
#include "cp.h"
#include "move.h"
#include "save.h"
#include "load.h"
#include "rle.h"
#include "show.h"
#include "place_first.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    int i = 0;
    int line, col, k;
    int a;

    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");

        /* Получаем команду */
        if (fgets(cmdline, MAXLINE, stdin) == NULL)
            continue;

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

        /*Сохраняем*/
         if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
               save(txt, arg);
            }
            continue;
        }

	/*Выводим без ведущих пробелов*/
	  if (strcmp(cmd, "showtrimmedfromstart") == 0) {
            showfromstart(txt);
            continue;
        }

      if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }

	/*Перемещение курсора*/
          if (strcmp(cmd, "move") == 0) {
	     col = 0;
	     line = 0;
	     i = 0;
             while (i != -1 && (arg = strtok(NULL, " \n")) != NULL) {
		a = strlen(arg);
		i++;
		k = 0;
		switch (i){
			case 1:
				while(i != -1 && k!= a){
					if (arg[a - k - 1] - 48 <=9 && arg[a - k - 1] - 48 >=0) line += pow(10,k) *  (arg[a - k - 1] - 48); else i = -1;
					k ++;
				}
				break;
			case 2:
				 while(i != -1 && k!= a){
                                        if (arg[a - k - 1] - 48 <=9 && arg[a - k - 1] - 48 >=0) col += pow(10,k) *  (arg[a - k - 1] - 48); else i = -1;
                                        k ++;
                                }
				break;
			default:
				i = -1;
		}
            }
        if (i < 2)
            fprintf(stderr, "Usage: move numberline numbercolumn\n");
        else
            move(txt ,line ,col);
            continue;
        }

	/*Удаление символов после курсора*/
	if (strcmp(cmd, "rle") == 0) {
            rle(txt);
            continue;
        }

    /* Помещаем строку в начало файла */
            if (strcmp(cmd, "p1") == 0) {
                if ((arg = strtok(NULL, "\n")) == NULL) {
                    fprintf(stderr, "Usage: p1 <string>\n");
                } else {
                    place_first(txt, arg);
                }
                continue;
            }

        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }
    return 0;
}
