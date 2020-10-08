#include "Sort.h"

// ����� �����

Sorting::Sorting(const int& size, std::string name_file) : arr(new int[size]), n(size) {
	std::ifstream fin(name_file + ".txt");
	if (!fin.is_open()) {
		throw Error("���� �� ��������!");
	}
	else {
		for (int i = 0; i < n; ++i) {
			fin >> *(arr + i);
		}
	}
	fin.close();
}

Sorting::~Sorting() {
	delete[] arr;
}

void Sorting::swap(int i, int i_min) {
	int a = *(arr + i);
	*(arr + i) = *(arr + i_min);
	*(arr + i_min) = a;
}

void Sorting::SortArr() {}

// C��������� �������

Choice::Choice(const int& size, std::string name_file) : Sorting(size, name_file) {}

Choice::~Choice() {}

void Choice::SortArr() {
	ChoiceCode();
}

void Choice::ChoiceCode() {
	for (int i = 0; i < n - 1; ++i) {
		int i_min = i;
		for (int j = i + 1; j < n; ++j) {
			if (*(arr + j) < *(arr + i_min)) {
				i_min = j;
			}
		}
		swap(i, i_min);
	}
}

// ������� �����-�����

Quick::Quick(const int& size, std::string name_file) : Sorting(size, name_file) {}

Quick::~Quick() {}

void Quick::SortArr() {
	QuickCode(arr, n);
}

void Quick::QuickCode(int* arr, int n) {
	int i = 0; // ������ �������
	int j = n - 1; // ����� �������
	int mid = *(arr + (n / 2)); // ����������� ������� �������
	do {
		// ��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
		// � ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
		while (*(arr + i) < mid) {
			i++;
		}
		// � ������ ����� ���������� ��������, ������� ������ ������������
		while (*(arr + j) > mid) {
			j--;
		}
		// ������ �������� �������
		if (i <= j) {
			swap(i, j);
			i++;
			j--;
		}
	} while (i <= j);
	// ����������� ������, ���� ��������, ��� �����������
	if (j > 0) { // "����� �����"
		QuickCode(arr, j + 1);
	}
	if (i < n) { // "������ �����"
		QuickCode(&*(arr + i), n - i);
	}
}