#include "Sorting.h"

Sorting::Sorting(const int size, std::string name_file): arr(new int[size]), _n(size) {
	std::ifstream fin(name_file + ".txt");
	if (!fin.is_open()) {
		throw Error("Файл не открылся!");
	}
	else {
		for (int i = 0; i < _n; ++i) {
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