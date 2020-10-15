#pragma once
#include "ArrayOfNumber.h"
#include <algorithm>

class Sorting {
public:
	Sorting();

	virtual ~Sorting();

	virtual void SortArr(const ArrayOfNumber& arr, int size) const = 0;

};