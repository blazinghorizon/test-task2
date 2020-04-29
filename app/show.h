#ifndef SHOW_H
#define SHOW_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

void show(text txt);

#endif // SHOW_H
