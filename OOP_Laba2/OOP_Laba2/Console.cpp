#include "Console.h"

Console::Console() = default;

void Console::run() {
    setlocale(LC_ALL, "Russian");

    std::string name_file;
    int check, size;

    do {
        std::cout << "Какую сортировку выбрать?:\n 0. Choice\n 1. Quick" << std::endl;
        std::cin >> check;
    } while (check < 0 || check > 1);

    std::cout << "Название файла: " << std::endl;
    std::cin >> name_file;
    std::cout << "Сколько элементов считать с файла?: " << std::endl;
    std::cin >> size;

    try {
        ArrayOfNumber arr(size);
        ScanFile scan_file;
        scan_file.Recording(arr, size, name_file);
        PrintFile print_file;

        Sorting* sort = nullptr;
        if (!check) {
            sort = new Choice;
        } else {
            sort = new Quick;
        }
        sort->SortArr(arr, size);
        print_file.outFile(arr, size);
        delete sort;
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
    }
}