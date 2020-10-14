#pragma once
#include "ScanFile.h"
#include "PrintFile.h"
#include "Error.h"

class Sorting {
public:
	Sorting() = default;

	Sorting(int size, const std::string& name_file);

	virtual ~Sorting();

	virtual void SortArr(int n) = 0;

	void outInFile(int n) const;

protected:
	ScanFile* scan_file;
	PrintFile* print_file;

	void swap(int* arr, int i, int j);

};