#include "ScanFile.h"

ScanFile::ScanFile() = default;

void ScanFile::Recording(const ArrayOfNumber& arr, int size, const std::string& name_file) const {
	std::ifstream fin(name_file);
	if (!fin.is_open()) {
		throw Error("Нет такого файла...");
	}
	else {
		for (int i = 0; i < size; ++i) {
			if (!(fin >> arr[i])) {
				throw Error("Недопустимое количество элементов...");
			}
		}
	}
	fin.close();
}