#pragma once
#include <fstream>
#include "Choice.h"
#include "Quick.h"
#include "Error.h"

class Sorting {
public:
	Sorting() = default;

	Sorting(const int size, std::string name_file);

	virtual ~Sorting();

	virtual void SortArr();

protected:
	int* arr = nullptr;
	const int _n;

	void swap(int i, int i_min);

};