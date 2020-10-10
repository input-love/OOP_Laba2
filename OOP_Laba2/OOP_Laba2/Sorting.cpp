#include "Sorting.h"

Sorting::Sorting(const int size, const std::string& name_file): _arr(new int[size]) {
	std::ifstream fin(name_file + ".txt");
	if (!fin.is_open()) {
		throw Error("Нет такого файла...");
	} else {
		for (int i = 0; i < size; ++i) {
			if (!(fin >> _arr[i])) {
				throw Error("Недопустимое количество элементов...");
			}
		}
	}
	fin.close();
}

Sorting::~Sorting() {
	delete[] _arr;
}

void Sorting::coutInFile(int n) {
	std::ofstream fout("sort_array.txt");
	for (int i = 0; i < n; ++i) {
		fout << _arr[i] << "\n";
	}
}

void Sorting::swap(int i, int j) {
	int a = _arr[i];
	_arr[i] = _arr[j];
	_arr[j] = a;
}

//-------------

Choice::Choice(const int size, const std::string& name_file): Sorting(size, name_file) {}

Choice::~Choice() {}

void Choice::SortArr(int n) {
	for (int i = 0; i < n - 1; ++i) {
		int i_min = i;
		for (int j = i + 1; j < n; ++j) {
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

void Quick::SortArr(int n) {
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
		SortArr(j + 1);
	}
	if (i < n) {
		SortArr(n - i);
	}
}