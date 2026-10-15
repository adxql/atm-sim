#include <iostream>

bool running_login = true;
bool running_interface = true;
int balance = 200;
int pin_number = 1234;

void interface() {
    std::cout << "1. Check Balance\n"
        << "2. Deposit\n"
        << "3. Withdraw\n"
        << "4. Exit\n\n"
        << "Choice: ";
}

void login() {
    std::cout << "========== ATM ==========\n\n"; 
    std::cout << "Enter PIN: ";
}

int user_input() {
    int input;

    std::cin >> input;

    return input;
}

void deposit() {
    int input;

    std::cout << "Amount of deposit (press 0 to cancel): "; 
    std::cin >> input;

    if (input != 0) {
        if (input > 0) {
            balance = balance + input;

            std::cout << "\nSuccesfully deposit $" << input << " into the account\n\n"; 
        } else {
            std::cout << "\nThe amount cannot be negative, Exited...\n\n";
        }
    } else {
        std::cout << "\nExited\n\n";
    }
    
}

void withdraw() {
    int input;

    std::cout << "Amount of withdraw (press 0 to cancel): ";
    std::cin >> input;

    if (input != 0) {
        if (input <= balance) {
            if (input > 0) {
                balance = balance - input;

                std::cout << "\nSuccesfully withdraw $" << input << " from the account\n\n";
            } else {
                std::cout << "\nThe amount cannot be negative, Exited...\n\n";
            }
        } else {
            std::cout << "insufficient balance, Exited...\n\n";
        }
    } else {
        std::cout << "\nExited\n\n";
    }
}

void option(int input) {
    switch (input) {
        case 1:
            std::cout << "\nBalance: $" << balance << "\n\n";
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            std::cout << "\nThank you for using our services\n";
            running_interface = false;
            break;
        default:
            std::cout << "Invalid choice, choose between 1-4\n\n";
    }
}

void process() {
    interface();  
    option(user_input());
}

void pin_input() {
    int input;

    std::cin >> input;

    if (input == pin_number) {
        std::cout << "\nLogin successful!\n\n";

        running_login = false;
    } else {
        std::cout << "\nInvalid pin number\n\n";
    }
}

int main() {

    while (running_login) {
       login();
       pin_input();
    }

    while (running_interface) {
        process();
    }

    return 0;
}
