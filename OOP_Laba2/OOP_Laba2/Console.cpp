#include "Console.h"

Console::Console() = default;

void Console::run() {
    setlocale(LC_ALL, "Russian");
    while (true) {
        int check, size;
        do {
            std::cout << "Какую сортировку выбрать?:\n 1. Choice\n 2. Quick" << std::endl;
            std::cin >> check;
        } while (check < 1 || check > 2);

        std::cout << "Название файла: " << std::endl;
        std::cin >> _str;
        std::cout << "Сколько элементво в очереди?: " << std::endl;
        std::cin >> size;

        switch (check) {
        case 1:
            try {
                Choice choice(check, _str);
                Sorting* sort = &choice;
                sort->SortArr();
            }
            catch (const Error& err) {
                std::cout << err.what() << std::endl;
            }
            break;
        case 2:
            try {
                Quick quick(check, _str);
                Sorting* sort = &quick;
                sort->SortArr();
            }
            catch (const Error& err) {
                std::cout << err.what() << std::endl;
            }
            break;
        }
    }
}