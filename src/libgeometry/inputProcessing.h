#pragma once

#include <string>
#include <vector>
#include "Circle.h"


using std::string;
using std::vector;

bool processing(vector<Circle>& circles, string command);
int normalization(string& command);

vector<string> splitting(string& command);

bool numberParser(string& strNumber, double& number);

bool parser(vector<Circle>& circles, vector<string>& details);
bool circleParser(vector<string>& details, double& x, double& y, double& radius);
