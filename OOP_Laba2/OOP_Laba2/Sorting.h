#pragma once
#include "Error.h"
#include "ArrayOfNumber.h"

class Sorting {
public:
	Sorting();

	virtual ~Sorting();

	virtual void SortArr(const ArrayOfNumber& array_num, int n) = 0;

};