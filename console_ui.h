#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "currency.h"

struct Currency* make_currency(void);
enum Currencies get_currency(void);
struct Currency* convert_currency(struct Currency*);
double get_amount(void);

#endif
