#pragma once
#include "Sorting.h"

class Quick final : public Sorting {
public:
	Quick() = default;

	Quick(int size, const std::string& name_file);

	void SortArr(int n);

private:
	void SortArrCode(int* arr, int n);
};
