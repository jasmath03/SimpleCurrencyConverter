#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "console_ui.h"

struct Currency* make_currency(void) {
    struct Currency* user_currency = (struct Currency*)malloc(sizeof(struct Currency));
    if (user_currency == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }
    user_currency->currency = get_currency();
    
    printf("Please enter the amount: ");
    user_currency->amount = get_amount();
    
    return user_currency;
}

struct Currency* convert_currency(struct Currency* user) {
    printf("What currency would you like to convert to?\n");
    enum Currencies to_currency = get_currency();
    
    printf("\nYou have %.2f %s.\n", user->amount, get_currency_name(user->currency));
    printf("How much would you like to exchange? ");
    double amount = get_amount();
    
    while (amount > user->amount || amount <= 0) {
        printf("Unfortunately, you don't have enough money or entered a value of 0 or less.\n");
        printf("You have %.2f %s. Try again: ", user->amount, get_currency_name(user->currency));
        amount = get_amount();
    }
    
    struct Currency* result = convert(user->currency, to_currency, amount);
    if (!result) {
        fprintf(stderr, "Conversion failed.\n");
        return NULL;
    }
    
    return result;
}

enum Currencies get_currency(void) {
    enum Currencies curr = USD;
    char input[50];
    bool valid_currency = false;
    while (!valid_currency) {
        printf("Enter a valid currency code (e.g., USD, EUR): ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            input[strcspn(input, "\n")] = '\0';
            for (int i = 0; input[i] != '\0'; i++) {
                input[i] = toupper((unsigned char)input[i]);
            }
            for (int i = 0; i < CURRENCY_COUNT; i++) {
                if (strcmp(input, currency_names[i]) == 0) {
                    curr = i;
                    valid_currency = true;
                    break;
                }
            }
            if (!valid_currency) {
                printf("Invalid currency. Please try again.\n");
            }
        } else {
            fprintf(stderr, "Error reading input.\n");
        }
    }
    return curr;
}

double get_amount(void) {
    char input[50];
    double amount = 0.00;
    char* endptr;
    
    while (true) {
        if (fgets(input, sizeof(input), stdin) != NULL) {
            input[strcspn(input, "\n")] = '\0';
            amount = strtod(input, &endptr);
            if (endptr != input && *endptr == '\0' && amount > 0) {
                return amount;
            } else {
                printf("Invalid input. Please enter a positive number.\n");
            }
        } else {
            fprintf(stderr, "Error reading input.\n");
        }
    }
}
