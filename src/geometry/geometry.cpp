#include "libgeometry/Circle.h"
#include "libgeometry/infoOutput.h"
#include "libgeometry/inputProcessing.h"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	vector<Circle> circles;

	string input;
	while (true) {
		getline(cin, input, '\n');
		if (parser(circles,input)) {
			cout << "Пересечения:" << endl;
                for (unsigned int i = 0; i < circles.size() - 1; i++) {
				if (intersection(circles[i],circles.back())) {
					cout << "  circle(" << circles[i].x << " " << circles[i].y << ", " << circles[i].radius << ")" << endl;
				}
			}
		}
		cout << endl;
	}

	return 0;
}
