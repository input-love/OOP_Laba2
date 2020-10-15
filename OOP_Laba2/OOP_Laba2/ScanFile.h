#pragma once
#include "ArrayOfNumber.h"
#include "Error.h"
#include <fstream>
#include <string>

class ScanFile {
public:
	ScanFile();

	ScanFile(int size);

	~ScanFile();
	
	void Recording(int size, const std::string& name_file) const;

	int* GetArray() const;

private:
	ArrayOfNumber* array_num;

};