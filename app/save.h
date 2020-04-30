#ifndef SAVE_H
#define SAVE_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/*Сохранение*/
int save(text txt, const char *filename);

#endif // SAVE_H
