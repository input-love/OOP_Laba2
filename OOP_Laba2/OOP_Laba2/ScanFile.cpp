#include "ScanFile.h"

ScanFile::ScanFile() = default;

void ScanFile::Recording(int size, const std::string& name_file) {
	std::ifstream fin(name_file);
	if (!fin.is_open()) {
		throw Error("��� ������ �����...");
	}
	else {
		array_num = new ArrayOfNumber(size);
		for (int i = 0; i < size; ++i) {
			if (!(fin >> array_num->operator[](i))) {
				throw Error("������������ ���������� ���������...");
			}
		}
	}
	fin.close();
}

int* ScanFile::GetArray() {
	return array_num->_arr;
}