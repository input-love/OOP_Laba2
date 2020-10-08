#pragma once
#include <fstream>
#include "Error.h"

class Sorting {
protected:
	Sorting() = default;

	Sorting(const int& size, std::string name_file);

	virtual ~Sorting();

	/* Переменные */

	int* arr = nullptr;
	const int n;

	void swap(int i, int i_min);

public:
	virtual void SortArr();

};

class Choice final: public Sorting {
public:
	Choice() = default;

	Choice(const int& size, std::string name_file);

	virtual ~Choice();

	void SortArr() override;

private:
	void ChoiceCode();

};

class Quick final: public Sorting {
public:
	Quick() = default;

	Quick(const int& size, std::string name_file);

	virtual ~Quick();

	void SortArr() override;

private:
	void QuickCode(int* arr, int n);

};