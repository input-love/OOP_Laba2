#include "Quick.h"

Quick::Quick() = default;

void Quick::SortArr(const ArrayOfNumber& arr, int n) {
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
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) {
		SortArr(arr, j + 1);
	}
	if (i < n) {
		SortArr(arr, n - i);
	}
}