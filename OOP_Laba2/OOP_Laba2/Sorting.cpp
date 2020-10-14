#include "Sorting.h"

Sorting::Sorting(int size, const std::string& name_file): scan_file(new ScanFile), print_file(new PrintFile) {
	scan_file->Recording(size, name_file);
}

Sorting::~Sorting() {}

void Sorting::outInFile(int n) const {
	print_file->outFile(scan_file->GetArray(), n);
}

void Sorting::swap(int* arr, int i, int j) {
	int a = arr[i];
	arr[i] = arr[j];
	arr[j] = a;
}
