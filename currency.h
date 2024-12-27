#ifndef CURRENCY_H
#define CURRENCY_H

enum Currencies {
    USD, EUR, GBP, JPY, AUD, CAD, CHF, CNY, INR, RUB, BRL, MXN, ZAR, HKD,
    SGD, KRW, NZD, SEK, NOK, DKK, PLN, TRY, THB, MYR, IDR, PHP, VND, SAR, AED,
    CURRENCY_COUNT
};

struct Currency {
    enum Currencies currency;
    double amount;
};

extern const char* currency_names[CURRENCY_COUNT];

const char* get_currency_name(enum Currencies);
int is_valid_currency(enum Currencies);
void print_currency(const struct Currency*);
struct Currency* convert(enum Currencies, enum Currencies, double);
#endif
