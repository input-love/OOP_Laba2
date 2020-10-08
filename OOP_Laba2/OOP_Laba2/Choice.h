#pragma once
#include "Sorting.h"

class Choice final : public Sorting {
public:
	Choice() = default;

	Choice(const int size, std::string name_file);

	virtual ~Choice();

	void SortArr() override;

private:
	void ChoiceCode();

};
