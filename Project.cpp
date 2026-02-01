#include <iostream>
using namespace std;

// Function Prototypes
bool authenticate(int enteredPin, int actualPin);
void showMenu();
void checkBalance(float balance);
float depositMoney(float balance);
float withdrawMoney(float balance);

int main() {
    int actualPin = 1234;
    int enteredPin;
    float balance = 1000.0;
    int choice;
    char again;

    cout << "=============================\n";
    cout << "     WELCOME TO ATM SYSTEM   \n";
    cout << "=============================\n";

    // ?? PIN Authentication
    cout << "Enter your PIN: ";
    cin >> enteredPin;

    if (!authenticate(enteredPin, actualPin)) {
        cout << "Incorrect PIN. Access Denied!\n";
        return 0;
    }

    cout << "PIN Verified Successfully!\n";

    // ?? ATM Menu Loop
    do {
        showMenu();
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;

            case 2:
                balance = depositMoney(balance);
                break;

            case 3:
                balance = withdrawMoney(balance);
                break;

            case 4:
                cout << "Thank you for using ATM. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }

        cout << "\nDo you want another transaction? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "Session Ended. Please take your card.\n";
    return 0;
}

// ?? Authenticate Function
bool authenticate(int enteredPin, int actualPin) {
    return (enteredPin == actualPin);
}

// ?? Display Menu
void showMenu() {
    cout << "\n====== ATM MENU ======\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
}

// ?? Balance Inquiry
void checkBalance(float balance) {
    cout << "Your current balance is: Rs. " << balance << endl;
}

// ? Deposit
float depositMoney(float balance) {
    float amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful!\n";
    } else {
        cout << "Invalid amount!\n";
    }

    return balance;
}

// ? Withdraw
float withdrawMoney(float balance) {
    float amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount > balance) {
        cout << "Insufficient balance!\n";
    } else if (amount <= 0) {
        cout << "Invalid amount!\n";
    } else {
        balance -= amount;
        cout << "Please collect your cash.\n";
    }

    return balance;
}
