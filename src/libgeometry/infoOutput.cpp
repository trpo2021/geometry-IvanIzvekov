#include "infoOutput.h"
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

const double PI = 3.141592653589793238463;


void circleInfo(double x, double y, double radius)
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

	cout << "radius = " << radius << endl;
	cout << "P = " << circlePerimetr(radius) << endl;
	cout << "S = " << circleArea(radius) << endl;
	
}
double circleArea(double radius){
	return round(PI * radius * radius*1000)/1000;
}
double circlePerimetr(double radius){
	return round(2 * PI * radius*1000)/1000;
}
bool intersection (const Circle& A,const Circle& B)
{
	if (A.radius + B.radius > sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2))) {
					return true;
				}
				return false;
}
