#include "PrintFile.h"

PrintFile::PrintFile() = default;

void PrintFile::outFile(const ArrayOfNumber& arr, int n) const {
	std::ofstream fout("sort_array.txt");
	for (int i = 0; i < n; ++i) {
		fout << arr[i] << "\n";
	}
}