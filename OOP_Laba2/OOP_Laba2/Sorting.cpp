#include "Sorting.h"

Sorting::Sorting(int size, const std::string& name_file): _n(size), _arr(new int[_n]) {
	std::ifstream fin(name_file + ".txt");
	if (!fin.is_open()) {
		throw Error("Файл не открылся!");
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

Choice::Choice(int size, const std::string& name_file): Sorting(size, name_file) {}

Choice::~Choice() {}

void Choice::SortArr() {
	for (int i = 0; i < _n - 1; ++i) {
		int i_min = i;
		for (int j = i + 1; j < _n - 1; ++j) {
			if (_arr[j] < _arr[i_min]) {
				i_min = j;
			}
		}
		swap(i, i_min);
	}
}

//-------------

Quick::Quick(int size, const std::string& name_file): Sorting(size, name_file) {}

Quick::~Quick() {}

void Quick::SortArr() {
	QuickCode(_arr, _n);
}

void Quick::QuickCode(int* _arr, int n) {
	int i = 0;
	int j = n - 1;
	int mid = _arr[n / 2];
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
		QuickCode(_arr, j + 1);
	}
	if (i < n) {
		QuickCode(&_arr[i], n - i);
	}
}