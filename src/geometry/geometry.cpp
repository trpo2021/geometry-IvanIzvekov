#include <iostream>
#include "libgeometry/inputProcessing.h"


using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");


    string input;
    while (true) {
        getline(cin, input, '\n');
        processing(input);
        cout << endl;
    }

    return 0;
}
