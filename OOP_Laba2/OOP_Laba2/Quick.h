#pragma once
#include "Sorting.h"

class Quick final : public Sorting {
public:
	Quick() = default;

	Quick(const int size, std::string name_file);

	virtual ~Quick();

	void SortArr() override;

private:
	void QuickCode(int* arr, int n);

};
