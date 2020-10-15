#pragma once
#include <fstream>
#include "Error.h"

class PrintFile {
public:
	PrintFile();

	void outFile(int* _arr, int n) const;

};