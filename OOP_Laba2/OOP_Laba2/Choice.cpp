#include "Choice.h"

Choice::Choice() = default;

void Choice::SortArr(const ArrayOfNumber& arr, int size) const {
	for (int i = 0; i < size - 1; ++i) {
		int i_min = i;
		for (int j = i + 1; j < size; ++j) {
			if (arr[j] < arr[i_min]) {
				i_min = j;
			}
		}
		std::swap(arr[i], arr[i_min]);
	}
}