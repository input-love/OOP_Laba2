#pragma once

class ArrayOfNumber {
public:
	ArrayOfNumber();

	ArrayOfNumber(int size);

	~ArrayOfNumber();

	int& operator [] (int i) const;

private:
	int* _arr;

};