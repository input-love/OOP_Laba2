#include "Console.h"

Console::Console() = default;

void Console::run() const {
    setlocale(LC_ALL, "Russian");

    std::string name_file;
    int check, size;

    do {
        std::cout << "����� ���������� �������?:\n 0. Choice\n 1. Quick" << std::endl;
        std::cin >> check;
    } while (check < 0 || check > 1);

    std::cout << "�������� �����: " << std::endl;
    std::cin >> name_file;
    std::cout << "������� ��������� ������� � �����?: " << std::endl;
    std::cin >> size;
    
    try {
        Sorting* sort = nullptr;
        if (!check) {
            sort = new Choice(size, name_file);
        } else {
            sort = new Quick(size, name_file);
        }
        sort->SortArr(size);
        sort->outInFile(size);
        delete sort;
    } catch (const std::exception& exept) {
        std::cout << exept.what() << std::endl;
    }
}