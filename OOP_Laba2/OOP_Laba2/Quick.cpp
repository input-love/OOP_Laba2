#include "Quick.h"

Quick::Quick(int size, const std::string& name_file) : Sorting(size, name_file) {}

void Quick::SortArr(int n) {
	SortArrCode(scan_file->GetArray(), n);
}

void Quick::SortArrCode(int* arr, int n) {
	int i = 0;
	int j = n - 1;
	int mid = arr[n / 2];
	do {
		while (arr[i] < mid) {
			i++;
		}
		while (arr[j] > mid) {
			j--;
		}
		if (i <= j) {
			swap(arr, i, j);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		SortArrCode(arr, j + 1);
	}
	if (i < n) {
		SortArrCode(arr, n - i);
	}
}