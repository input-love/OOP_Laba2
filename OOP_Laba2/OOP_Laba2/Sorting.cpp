#include "Sorting.h"
#include <iostream>

Sorting::Sorting(const int size, const std::string& name_file): _n(size), _arr(new int[_n]) {
	std::ifstream fin(name_file + ".txt");
	if (!fin.is_open()) {
		throw Error("Нет такого файла...");
	} else {
		for (int i = 0; i < _n; ++i) {
			fin >> _arr[i];
		}
	}
	fin.close();
}

Sorting::~Sorting() {
	delete[] _arr;
}

void Sorting::swap(int i, int i_min) {
	int a = _arr[i];
	_arr[i] = _arr[i_min];
	_arr[i_min] = a;
}

//-------------

Choice::Choice(const int size, const std::string& name_file): Sorting(size, name_file) {}

Choice::~Choice() {}

void Choice::SortArr() {
	for (int i = 0; i < _n - 1; ++i) {
		int i_min = i;
		for (int j = i + 1; j < _n; ++j) {
			if (_arr[j] < _arr[i_min]) {
				i_min = j;
			}
		}
		swap(i, i_min);
	}
}

//-------------

Quick::Quick(const int size, const std::string& name_file): Sorting(size, name_file) {}

Quick::~Quick() {}

void Quick::SortArr() {
	QuickCode(_n);
}

void Quick::QuickCode(int size) {
	int i = 0;
	int j = size - 1;
	int mid = _arr[size / 2];
	do {
		while (_arr[i] < mid) {
			i++;
		}
		while (_arr[j] > mid) {
			j--;
		}
		if (i <= j) {
			swap(i, j);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		QuickCode(j + 1);
	}
	if (i < size) {
		QuickCode(size - i);
	}
}