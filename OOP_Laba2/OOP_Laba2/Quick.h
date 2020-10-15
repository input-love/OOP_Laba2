#pragma once
#include "Sorting.h"

class Quick final : public Sorting {
public:
	Quick();

	void SortArr(const ArrayOfNumber& arr, int size) const;

};
