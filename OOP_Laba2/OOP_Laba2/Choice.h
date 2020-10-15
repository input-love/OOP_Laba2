#pragma once
#include "Sorting.h"

class Choice final : public Sorting {
public:
	Choice();

	Choice(int size, const std::string& name_file);

	void SortArr(int n);

private:
	void SortArrCode(int* arr, int n) const;
};
