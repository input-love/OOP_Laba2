#include "Sort.h"

// Общий класс

Sorting::Sorting(const int& size, std::string name_file) : arr(new int[size]), n(size) {
	std::ifstream fin(name_file + ".txt");
	if (!fin.is_open()) {
		throw Error("Файл не открылся!");
	}
	else {
		for (int i = 0; i < n; ++i) {
			fin >> *(arr + i);
		}
	}
	fin.close();
}

Sorting::~Sorting() {
	delete[] arr;
}

void Sorting::swap(int i, int i_min) {
	int a = *(arr + i);
	*(arr + i) = *(arr + i_min);
	*(arr + i_min) = a;
}

void Sorting::SortArr() {}

// Cортировка выбором

Choice::Choice(const int& size, std::string name_file) : Sorting(size, name_file) {}

Choice::~Choice() {}

void Choice::SortArr() {
	ChoiceCode();
}

void Choice::ChoiceCode() {
	for (int i = 0; i < n - 1; ++i) {
		int i_min = i;
		for (int j = i + 1; j < n; ++j) {
			if (*(arr + j) < *(arr + i_min)) {
				i_min = j;
			}
		}
		swap(i, i_min);
	}
}

// Быстрая сорти-ровка

Quick::Quick(const int& size, std::string name_file) : Sorting(size, name_file) {}

Quick::~Quick() {}

void Quick::SortArr() {
	QuickCode(arr, n);
}

void Quick::QuickCode(int* arr, int n) {
	int i = 0; // Начало массива
	int j = n - 1; // Конец массива
	int mid = *(arr + (n / 2)); // Центральный элемент массива
	do {
		// Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		// В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (*(arr + i) < mid) {
			i++;
		}
		// В правой части пропускаем элементы, которые больше центрального
		while (*(arr + j) > mid) {
			j--;
		}
		// Меняем элементы местами
		if (i <= j) {
			swap(i, j);
			i++;
			j--;
		}
	} while (i <= j);
	// Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) { // "Левый кусок"
		QuickCode(arr, j + 1);
	}
	if (i < n) { // "Правый кусок"
		QuickCode(&*(arr + i), n - i);
	}
}