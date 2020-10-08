#include "Console.h"

Console::Console() = default;

void Console::run() {
    setlocale(LC_ALL, "Russian");
    while (true) {
        std::cout << "Какую сортировку выбрать?:\n 0. Choice\n 1. Quick" << std::endl;
        std::cin >> _x;
        if (!_x) {
            std::cout << "Название файла: " << std::endl;
            std::cin >> _str;
            std::cout << "Сколько элементво в очереди?: " << std::endl;
            std::cin >> _x;
            try {
                Choice choice(_x, _str);
                Sorting* sort = &choice;
                sort->SortArr();
            } catch (const Error& err) {
                std::cout << err.what() << std::endl;
            }
        }
        else {
            std::cout << "Название файла: " << std::endl;
            std::cin >> _str;
            std::cout << "Сколько элементво в очереди?: " << std::endl;
            std::cin >> _x;
            try {
                Quick quick(_x, _str);
                Sorting* sort = &quick;
                sort->SortArr();
            } catch (const Error& err) {
                std::cout << err.what() << std::endl;
            }
        }
    }
}