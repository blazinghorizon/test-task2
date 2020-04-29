#ifndef PR_RIGHTER_H
#define PR_RIGHTER_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

void pr_righter(text txt);

#endif // PR_RIGHTER_H
