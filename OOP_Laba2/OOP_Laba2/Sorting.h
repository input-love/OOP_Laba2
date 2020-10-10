#pragma once
#include <fstream>
#include "Error.h"

class Sorting {
public:
	Sorting() = default;

	Sorting(const int size, const std::string& name_file);

	virtual ~Sorting();

	virtual void SortArr(int n) = 0;

	void coutInFile(int n);

protected:
	int* _arr;

	void swap(int i, int j);

};

class Choice final: public Sorting {
public:
	Choice() = default;

	Choice(const int size, const std::string& name_file);

	~Choice();

	void SortArr(int n);

};

class Quick final: public Sorting {
public:
	Quick() = default;

	Quick(const int size, const std::string& name_file);

	~Quick();

	void SortArr(int n);

};