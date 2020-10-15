#include "Choice.h"

Choice::Choice() = default;

Choice::Choice(int size, const std::string& name_file): Sorting(size, name_file) {}

void Choice::SortArr(int n) {
	SortArrCode(scan_file->GetArray(), n);
}

void Choice::SortArrCode(int* arr, int n) const {
	for (int i = 0; i < n - 1; ++i) {
		int i_min = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[i_min]) {
				i_min = j;
			}
		}
		swap(arr, i, i_min);
	}
}