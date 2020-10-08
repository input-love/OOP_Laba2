#include "Console.h"

Console::Console() = default;

void Console::run() {
    setlocale(LC_ALL, "Russian");

    std::string str;
    int check, size;

    do {
        std::cout << "Какую сортировку выбрать?:\n 1. Choice\n 2. Quick" << std::endl;
        std::cin >> check;
    } while (check < 1 || check > 2);

    std::cout << "Название файла: " << std::endl;
    std::cin >> str;
    std::cout << "Сколько элементов в очереди?: " << std::endl;
    std::cin >> size;

    try {
        switch (check) {
        case 1: 
            {
                Sorting* sort = new Choice(size, str);
                sort->SortArr();
                delete sort;
            }
            break;
        case 2: 
            {
                Sorting* sort = new Quick(size, str);
                sort->SortArr();
                delete sort;
            }
            break;
        }
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
    }
}