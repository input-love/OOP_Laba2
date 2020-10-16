#pragma once
#include "Sorting.h"

class Choice final : public Sorting {
public:
	Choice();

	void SortArr(const ArrayOfNumber& arr, int size) const;

};
