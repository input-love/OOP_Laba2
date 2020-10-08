#include "Quick.h"

Quick::Quick(const int size, std::string name_file): Sorting(size, name_file) {}

Quick::~Quick() {}

void Quick::SortArr() {
	QuickCode(arr, _n);
}

void Quick::QuickCode(int* arr, int n) {
	int i = 0;
	int j = n - 1;
	int mid = *(arr + (n / 2));
	do {
		while (*(arr + i) < mid) {
			i++;
		}
		while (*(arr + j) > mid) {
			j--;
		}
		if (i <= j) {
			swap(i, j);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		QuickCode(arr, j + 1);
	}
	if (i < n) {
		QuickCode(&*(arr + i), n - i);
	}
}