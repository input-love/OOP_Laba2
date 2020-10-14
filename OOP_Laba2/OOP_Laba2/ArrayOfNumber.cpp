#include "ArrayOfNumber.h"

ArrayOfNumber::ArrayOfNumber(): _size(15), _arr(new int[_size]) {}

ArrayOfNumber::ArrayOfNumber(int n): _size(n), _arr(new int[_size]) {}

ArrayOfNumber::~ArrayOfNumber() {
	delete[] _arr;
}

int& ArrayOfNumber::operator [] (int i) {
	return _arr[i];
}