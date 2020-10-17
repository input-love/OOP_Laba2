#pragma once
#include "ArrayOfNumber.h"
#include "Error.h"
#include <fstream>

class ScanFile {
public:
	ScanFile();
	
	void Recording(const ArrayOfNumber& arr, int size, const std::string& name_file) const;

};