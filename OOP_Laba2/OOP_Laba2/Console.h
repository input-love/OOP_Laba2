#pragma once
#include <iostream>
#include <clocale>
#include "Sort.h"
#include "Error.h"

class Console {
public:

    Console();

    void run();

private:
    int _x;
    std::string _str;

};