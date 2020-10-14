#pragma once

class ArrayOfNumber {
public:
	ArrayOfNumber();

	ArrayOfNumber(int n);

	~ArrayOfNumber();

	int& operator [] (int i);

	int _size;
	int* _arr;

};