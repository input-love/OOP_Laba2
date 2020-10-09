#pragma once
#include <fstream>
#include "Error.h"

class Sorting {
public:
	Sorting() = default;

	Sorting(int size, const std::string& name_file);

	virtual ~Sorting();

	virtual void SortArr() = 0;

protected:
	int _n;
	int* _arr;

	void swap(int i, int i_min);

};

class Choice final: public Sorting {
public:
	Choice() = default;

	Choice(int size, const std::string& name_file);

	~Choice();

	void SortArr();

};

class Quick final: public Sorting {
public:
	Quick() = default;

	Quick(int size, const std::string& name_file);

	~Quick();

	void SortArr();

private:
	void QuickCode(int n);

};