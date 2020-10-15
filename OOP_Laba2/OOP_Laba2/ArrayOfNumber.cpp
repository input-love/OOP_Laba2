#include "ArrayOfNumber.h"

ArrayOfNumber::ArrayOfNumber(): _arr(new int[1000]) {}

ArrayOfNumber::ArrayOfNumber(int size): _arr(new int[size]) {}

ArrayOfNumber::~ArrayOfNumber() {
	delete[] _arr;
}

int& ArrayOfNumber::operator [] (int i) const {
	return _arr[i];
}