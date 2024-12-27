# Currency Converter in C

Welcome to my simple currency converter project! This program, written in C, allows you to convert between various currencies. It's designed with failsafes, user input validation, and dynamic memory allocation, ensuring a smooth user experience.

Completion Time: 2 days

## Features

- **Supports Multiple Currencies**: Convert between a variety of currencies, including USD, EUR, GBP, JPY, CNY, and many more.
- **Realistic Exchange Rates**: Uses exchange rates accurate as of December 26, 2024, sourced from [x-rates.com](https://www.x-rates.com/table/?from=USD&amount=1).
- **Input Validation**: Ensures only valid currencies and positive amounts are accepted.
- **Error Handling**: Handles invalid input and memory allocation failures.
- **Modular Design**: Functions are logically separated for ease of maintenance and readability.

## How to Use

1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Navigate to the project directory:
   ```bash
   cd SimpleCurrencyConverter
   ```
3. Compile the program:
   ```bash
   gcc -o SimpleCurrencyConverter main.c currency.c console_ui.c -Wall -Wextra
   ```
4. Run the program:
   ```bash
   ./SimpleCurrencyConverter
   ```
5. Follow the prompts to select your currency, enter an amount, and convert to another currency.

## Example

```text
Enter a valid currency code (e.g., USD, EUR): EUR
Please enter the amount: 1000.00

Currency: EUR, Amount: $1000.00
What currency would you like to convert to?
Enter a valid currency code (e.g., USD, EUR): USD

You have 1000.00 EUR.
How much would you like to exchange? 1000.00

Currency: USD, Amount: $1040.91
```

## Future Improvements

- Fetch live exchange rates from an API.
- Make it an overall more robust program.
- Implement multi-currency conversions in a single session.

## Acknowledgments

- Exchange rates were sourced from [x-rates.com](https://www.x-rates.com/table/?from=USD&amount=1).

## Permissions

This project is for fun and practice. Feel free to use, modify, and distribute it as you like.

---

Thank you for checking out my project! Feedback and suggestions are always welcome.

