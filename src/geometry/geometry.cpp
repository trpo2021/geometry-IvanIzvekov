#include <iostream>
#include <vector>
#include <cmath>
#include "libgeometry/inputProcessing.h"
#include "libgeometry/Circle.h"


using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	vector<Circle> circles;

	string input;
	while (true) {
		getline(cin, input, '\n');
		if (processing(circles, input)) {
			cout << "Пересечения:" << endl;
			Circle ncircle = circles.back();
                for (unsigned int i = 0; i < circles.size() - 1; i++) {
				if (circles[i].radius + ncircle.radius > sqrt(pow(circles[i].x - ncircle.x, 2) + pow(circles[i].y - ncircle.y, 2))) {
					cout << "  circle(" << circles[i].x << " " << circles[i].y << ", " << circles[i].radius << ")" << endl;
				}
			}
		}
		cout << endl;
	}

	return 0;
}
