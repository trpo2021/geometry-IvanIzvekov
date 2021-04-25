#pragma once

#include <string>
#include <vector>
#include "Circle.h"


using std::string;
using std::vector;

string normalization(string command);

vector<string> splitting(const string& command);

bool numberParser(string strNumber, double& number);

bool parser(vector<Circle>& circles, string command);
bool circleParser(vector<string>& details, double& x, double& y, double& radius);
