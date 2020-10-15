#pragma once
#include <fstream>
#include "ArrayOfNumber.h"
#include "Error.h"

class PrintFile {
public:
	PrintFile();

	void outFile(const ArrayOfNumber& arr, int n) const;

};