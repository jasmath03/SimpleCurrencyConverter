#include <stdio.h>
#include <stdlib.h>
#include "currency.h"
const char* currency_names[CURRENCY_COUNT] = {
    "USD", "EUR", "GBP", "JPY", "AUD", "CAD", "CHF", "CNY", "INR", "RUB",
    "BRL", "MXN", "ZAR", "HKD", "SGD", "KRW", "NZD", "SEK", "NOK", "DKK",
    "PLN", "TRY", "THB", "MYR", "IDR", "PHP", "VND", "SAR", "AED"
};
double exchangeRates[] = {
    1.0,         // USD = 1 (Base currency)
    0.96070132,  // EUR = 0.96070132
    0.798658,    // GBP = 0.798658
    157.605263,  // JPY = 157.605263
    1.607961,    // AUD = 1.607961
    1.441272,    // CAD = 1.441272
    0.899481,    // CHF = 0.899481
    7.298884,    // CNY = 7.298884
    85.305930,   // INR = 85.305930
    100.000666,  // RUB = 100.000666
    6.742290,    // BRL = 6.742290
    20.229547,   // MXN = 20.229547
    18.864284,   // ZAR = 18.864284
    7.766336,    // HKD = 7.766336
    1.360385,    // SGD = 1.360385
    1485.199989, // KRW = 1485.199989
    1.779176,    // NZD = 1.779176
    11.063234,   // SEK = 11.063234
    11.408109,   // NOK = 11.408109
    7.166329,    // DKK = 7.166329
    4.097096,    // PLN = 4.097096
    35.243430,   // TRY = 35.243430
    34.183209,   // THB = 34.183209
    4.477700,    // MYR = 4.477700
    16238.503879,// IDR = 16238.503879
    57.856309,   // PHP = 57.856309
    3.750000,    // SAR = 3.750000
    3.672500     // AED = 3.672500
};

const char* get_currency_name(enum Currencies currency) {
    if (currency >= 0 && currency < CURRENCY_COUNT) {
        return currency_names[currency];
    }
    return "Unknown";
}

int is_valid_currency(enum Currencies currency) {
    return currency >= 0 && currency < CURRENCY_COUNT;
}
struct Currency* convert(enum Currencies from, enum Currencies to, double amount) {
    struct Currency* new_currency = (struct Currency*)malloc(sizeof(struct Currency));
    if (!is_valid_currency(from) || !is_valid_currency(to)) {
        fprintf(stderr, "Invalid currency code(s) provided!\n");
        return NULL;
    }
    double amount_in_usd = amount / exchangeRates[from];
    double converted_amount = amount_in_usd * exchangeRates[to];
    new_currency->currency = to;
    new_currency->amount = converted_amount;
    return new_currency;
}
void print_currency(const struct Currency* currency) {
    if (is_valid_currency(currency->currency)) {
        printf("\nCurrency: %s, Amount: $%.2f\n", get_currency_name(currency->currency), currency->amount);
    } else {
        printf("\nInvalid currency!\n");
    }
}
