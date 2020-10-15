#include "Quick.h"

Quick::Quick() = default;

void Quick::SortArr(const ArrayOfNumber& arr, int size) const {
	int i = 0;
	int j = size - 1;
	int mid = arr[size / 2];
	do {
		while (arr[i] < mid) {
			i++;
		}
		while (arr[j] > mid) {
			j--;
		}
		if (i <= j) {
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		SortArr(arr, j + 1);
	}
	if (i < size) {
		SortArr(arr, size - i);
	}
}