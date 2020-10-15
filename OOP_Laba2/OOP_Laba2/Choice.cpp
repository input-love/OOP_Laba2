#include "Choice.h"

Choice::Choice() = default;

void Choice::SortArr(const ArrayOfNumber& arr, int n) {
	for (int i = 0; i < n - 1; ++i) {
		int i_min = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[i_min]) {
				i_min = j;
			}
		}
		std::swap(arr[i], arr[i_min]);
	}
}