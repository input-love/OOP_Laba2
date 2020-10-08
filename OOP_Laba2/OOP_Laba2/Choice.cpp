#include "Choice.h"

Choice::Choice(const int size, std::string name_file): Sorting(size, name_file) {}

Choice::~Choice() {}

void Choice::SortArr() {
	ChoiceCode();
}

void Choice::ChoiceCode() {
	for (int i = 0; i < _n - 1; ++i) {
		int i_min = i;
		for (int j = i + 1; j < _n; ++j) {
			if (*(arr + j) < *(arr + i_min)) {
				i_min = j;
			}
		}
		swap(i, i_min);
	}
}