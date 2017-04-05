#ifndef COMMON_H
#define COMMON_H
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stack;
using std::ifstream;

inline bool file_exists(const string& name) {
    ifstream f(name.c_str());
    return f.good();
}
#endif // COMMON_H
