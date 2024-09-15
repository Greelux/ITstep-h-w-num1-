#include <iostream>
#include <string>
#include <Windows.h>

int main() { 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "");
    bool hasLibraryCard = false;
    std::string author;
    std::string bookTitle;
    std::string bookCode;

    std::cout << "Добро пожаловать в библиотеку!" << std::endl;
    std::cout << "У вас есть читательский билет? (1 - да, 0 - нет): ";
    std::cin >> hasLibraryCard;

    if (!hasLibraryCard) {
        std::cout << "Пожалуйста, предъявите паспорт для открытия читательского билета." << std::endl;
        std::string fullName, address;

        std::cout << "Введите ФИО: ";
        std::cin.ignore();
        std::getline(std::cin, fullName);

        std::cout << "Введите адрес: ";
        std::getline(std::cin, address);

        hasLibraryCard = true;
        std::cout << "Читательский билет успешно открыт!" << std::endl;
    }
    std::cout << "Введите автора или название книги: ";
    std::cin.ignore();
    std::getline(std::cin, author);

    std::cout << "Введите шифр книги: ";
    std::cin >> bookCode;

    std::cout << "Книга с шифром " << bookCode << " готова к выдаче!" << std::endl;
    std::cout << "Спасибо за посещение библиотеки. Хорошего дня!" << std::endl;


    return 0;
}