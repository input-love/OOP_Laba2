#include "Console.h"

Console::Console() = default;

void Console::run() {
    setlocale(LC_ALL, "Russian");

    std::string str;
    int check, size;

    do {
        std::cout << "Какую сортировку выбрать?:\n 0. Choice\n 1. Quick" << std::endl;
        std::cin >> check;
    } while (check < 0 || check > 1);

    std::cout << "Название файла: " << std::endl;
    std::cin >> str;
    std::cout << "Сколько элементов в очереди?: " << std::endl;
    std::cin >> size;
    
    try {
        Sorting* sort = nullptr;
        if (!check) {
            sort = new Choice(size, str);
        } else {
            sort = new Quick(size, str);
        }
        sort->SortArr(size);
        delete sort;
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
    }
}