#pragma once
#include <fstream>
#include "Choice.h"
#include "Quick.h"
#include "Error.h"

class Sorting {
public:
	Sorting() = default;

	Sorting(int size, const std::string& name_file);

	virtual ~Sorting();

	virtual void SortArr() = 0;

protected:
	int* _arr;
	const int _n;

	void swap(int i, int i_min);

};

class Choice final: public Sorting {
public:
	Choice() = default;

	Choice(int size, const std::string& name_file);

	virtual ~Choice();

	void SortArr() override;

};

class Quick final: public Sorting {
public:
	Quick() = default;

	Quick(int size, const std::string& name_file);

	virtual ~Quick();

	void SortArr() override;

private:
	void QuickCode(int* arr, int n);

};