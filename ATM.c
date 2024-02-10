#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void checkBalance(float balance);
void moneyDeposit(float *balance);
void moneyWithdraw(float *balance);

int main() {
    float balance = 0.0; // Initial account balance
    int pin = 1234; // Correct pin number
    int enteredPin;
    int choice;
    int exit = 0;

    while (!exit) {
        printf("Enter your pin number: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) {
            while (exit == 0) {
                printf("\n1. Check balance\n2. Deposit money\n3. Withdraw money\n4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        checkBalance(balance);
                        break;
                    case 2:
                        moneyDeposit(&balance);
                        break;
                    case 3:
                        moneyWithdraw(&balance);
                        break;
                    case 4:
                        exit = 1;
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            }
        } else {
            printf("Incorrect pin number. Please try again.\n");
        }
    }

    return 0;
}

void checkBalance(float balance) {
    printf("Your current balance is: $%.2f\n", balance);
}

void moneyDeposit(float *balance) {
    float amount;

    printf("Enter the amount you want to deposit: $");
    scanf("%f", &amount);

    if (amount > 0) {
        *balance += amount;
        printf("Amount deposited successfully. Your new balance is: $%.2f\n", *balance);
    } else {
        printf("Invalid amount. Please try again.\n");
    }
}

void moneyWithdraw(float *balance) {
    float amount;

    printf("Enter the amount you want to withdraw: $");
    scanf("%f", &amount);

    if (amount > 0 && amount <= *balance) {
        *balance -= amount;
        printf("Amount withdrawn successfully. Your new balance is: $%.2f\n", *balance);
    } else {
        printf("Invalid amount or insufficient balance. Please try again.\n");
    }
}