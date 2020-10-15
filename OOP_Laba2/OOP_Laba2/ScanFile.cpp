#include "ScanFile.h"

ScanFile::ScanFile() = default;

ScanFile::ScanFile(int size): array_num(new ArrayOfNumber(size)) {}

ScanFile::~ScanFile() {
	delete array_num;
}

void ScanFile::Recording(int size, const std::string& name_file) const {
	std::ifstream fin(name_file);
	if (!fin.is_open()) {
		throw Error("Нет такого файла...");
	}
	else {
		for (int i = 0; i < size; ++i) {
			if (!(fin >> array_num->operator[](i))) {
				throw Error("Недопустимое количество элементов...");
			}
		}
	}
	fin.close();
}

int* ScanFile::GetArray() const {
	return array_num->_arr;
}