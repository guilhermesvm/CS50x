#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do{
        cents = get_int("How much do I owe you? ");
    }while(cents < 0);

    return cents;
}

int calculate_quarters(int cents){
    int quarter = 0;
    while(cents >= 25){
        cents = cents - 25;
        quarter++;
    }
    return quarter;
}


int calculate_dimes(int cents)
{
    int dime = 0;
    while(cents >= 10){
        cents = cents - 10;
        dime++;
    }
    return dime;
}

int calculate_nickels(int cents)
{
    int nickel = 0;
    while(cents >= 5){
        cents = cents - 5;
        nickel++;
    }
    return nickel;
}

int calculate_pennies(int cents)
{
    int penny = 0;
    while(cents >=1){
        cents = cents - 1;
        penny++;
    }
    return penny;
}
