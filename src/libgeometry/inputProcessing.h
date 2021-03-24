#pragma once

#include <string>
#include <vector>


using std::string;
using std::vector;

void processing(string command);
void normalization(string& command);

vector<string> splitting(string& command);

bool numberParser(string& strNumber, double& number);

void parser(vector<string>& details);
void circleParser(vector<string>& details, double& x, double& y, double& radius);
void triangleParser(vector<string>& details, double& x1, double& y1, double& x2, double& y2, double& x3, double& y3);
