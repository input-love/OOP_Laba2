#pragma once
#include "ArrayOfNumber.h"
#include "Error.h"
#include <fstream>
#include <string>

class ScanFile {
public:
	ScanFile();
	
	void Recording(int size, const std::string& name_file);

	int* GetArray();

private:
	ArrayOfNumber* array_num = nullptr;

};