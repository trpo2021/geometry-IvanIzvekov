#include "infoOutput.h"
#include <iostream>


using std::cout;
using std::endl;


const double PI = 3.141592653589793238463;


void circleInfo(double x, double y, double radius)
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

	cout << "radius = " << radius << endl;
	cout << "P = " << 2 * PI * radius << endl;
	cout << "S = " << PI * radius * radius << endl;
}