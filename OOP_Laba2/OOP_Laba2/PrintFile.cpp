#include "PrintFile.h"

PrintFile::PrintFile() = default;

void PrintFile::outFile(const ArrayOfNumber& arr, int size) const {
	std::ofstream fout("sort_array.txt");
	for (int i = 0; i < size; ++i) {
		fout << arr[i] << "\n";
	}
	fout.close();
}