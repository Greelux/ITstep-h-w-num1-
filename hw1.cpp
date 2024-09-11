#include <iostream>
#include <string>

using namespace std;

int main() {
    string cardType, pinCode, operation;
    int attempts = 0;
    bool pinCorrect = false;
    int balance = 12000;
    int cash;

    cout << "Добро пожаловать в банкомат!\n";
    cout << "Пожалуйста, вставьте карту (введите 'chip' если карта с чипом, 'magstripe' если с магнитной полосой): ";
    cin >> cardType;

    if (cardType == "chip") {
        cout << "Вставьте карту чипом вперед.\n";
    } else if (cardType == "magstripe") {
        cout << "Вставьте карту магнитной полосой вниз.\n";
    } else {
        cout << "Неверный тип карты!\n";
        return 0;
    }

    cout << "Выберите язык: (1 - Русский, 2 - English): ";
    int language;
    cin >> language;

    if (language == 1) {
        cout << "Вы выбрали Русский.\n";
    } else if (language == 2) {
        cout << "You have chosen English.\n";
    } else {
        cout << "Неверный выбор языка!\n";
        return 0;
    }

    while (attempts < 3 && !pinCorrect) {
        if (language == 1) {
            cout << "Введите PIN-код: ";
        } else {
            cout << "Enter PIN code: ";
        }
        cin >> pinCode;

        if (pinCode == "1111") {
            pinCorrect = true;
        } else {
            attempts++;
            if (language == 1) {
                cout << "Неверный PIN-код. Попытка: " << attempts << " из 3.\n";
            } else {
                cout << "Incorrect PIN code. Attempt: " << attempts << " out of 3.\n";
            }
            if (attempts == 3) {
                if (language == 1) {
                    cout << "Ваша карта заблокирована.\n";
                } else {
                    cout << "Your card is blocked.\n";
                }
                return 0; 
            }
        }
    }

    if (language == 1) {
        cout << "Выберите операцию: (1 - Остаток на счете, 2 - Снятие наличных, 3 - Завершение работы): ";
    } else {
        cout << "Choose an operation: (1 - Balance Inquiry, 2 - Withdraw Cash, 3 - Exit): ";
    }

    int operationChoice;
    cin >> operationChoice;

    if (operationChoice == 1) {
        if (language == 1) {
            cout << "Ваш баланс: " << balance << " гривен.\n";
        } else {
            cout << "Your balance: " << balance << " UAN.\n";
        }
    } else if (operationChoice == 2) {
        if (language == 1) {
            cout << "Введите сумму для снятия: ";
        } else {
            cout << "Enter the amount to withdraw: ";
        }
        cin >> cash;

        if (cash <= balance) {
            balance -= cash;
            if (language == 1) {
                cout << "Вы сняли " << cash << " гривен.\n";
                cout << "Остаток на счете: " << balance << " гривен.\n";
            } else {
                cout << "You withdrew " << cash << " UAN.\n";
                cout << "Remaining balance: " << balance << " UAN.\n";
            }
        } else {
            if (language == 1) {
                cout << "Недостаточно средств на счете.\n";
            } else {
                cout << "Insufficient funds in the account.\n";
            }
        }
    } else if (operationChoice == 3) {
        if (language == 1) {
            cout << "Спасибо за использование банкомата. Ваша карта возвращена.\n";
        } else {
            cout << "Thank you for using the ATM. Your card is returned.\n";
        }
        return 0;
    } else {
        if (language == 1) {
            cout << "Неверный выбор операции.\n";
        } else {
            cout << "Invalid operation choice.\n";
        }
        return 0;
    }

    if (language == 1) {
        cout << "Спасибо за использование банкомата. Ваша карта возвращена.\n";
    } else {
        cout << "Thank you for using the ATM. Your card is returned.\n";
    }

    return 0;
}
