#include "inputProcessing.h"
#include "infoOutput.h"
#include <iostream>

using std::cout;
using std::endl;



// Нормализация входных данных: замена заглавных букв на строчные
string normalization(string command)
{
    for (unsigned int i = 0; i < command.size(); i++) {
        if (isupper(command[i])) {
            command[i] = tolower(command[i]);
        }
    }
    return command;
}

// Разбиение входных данных на части для упрощения обработки
vector<string> splitting(const string& command)
{
    vector<string> details;

    string detail = "";
    for (unsigned int i = 0; i <= command.size(); i++) {
        if ((command[i] == ' ') || (command[i] == '(') || (command[i] == ',') || (command[i] == ')') || (command[i] == '\0')) {
            if (detail.size() != 0) {
                details.push_back(detail);
                detail = "";
            }
            if (command[i] == '(') {
                details.push_back("(");
            }
            else if (command[i] == ',') {
                details.push_back(",");
            }
            else if (command[i] == ')') {
                details.push_back(")");
            }
        }
        else {
            if (command[i] != ' ') {
                detail += command[i];
            }
        }
    }

    return details;
}

// Парсер числа: переводит строку в число и проверяет на отсутствие лишних символов
bool numberParser(string strNumber, double& number)
{
	number=0.0;
    for (unsigned int countPoint = 0, i = 0; i < strNumber.size(); i++) {
        // Функция atof() использует ',' для отделения дробной части числа от целой, поэтому заменяем '.' на ','
        if (strNumber[i] == '.') {
            if (++countPoint > 1) {
                return false;
            }
        }
        else if ((strNumber[i] != '-') && (not isdigit(strNumber[i]))) {  // Проверка строки на отсутствие символов не являющихся цифрой
            return false;
        }
    }
    number = atof(strNumber.c_str());   // Преобразование строки в число double

    return true;
}

bool parser(vector<Circle>& circles, string command)
{
	command=normalization(command);

    vector<string> details = splitting(command);
    if (details.size() != 0) {
        // Проверка названия фигуры
        if (details[0] == "circle") {
            double x, y, radius;
            if (circleParser(details, x, y, radius)) {
                circleInfo(x, y, radius);

                circles.push_back(Circle(x, y, radius));

                return true;
            }
        }
        else {
            cout << "Ошибка: неизвестная фигура." << endl;
        }
    }
    else {
        cout << "Ошибка: пустая строка." << endl;
    }

    return false;
}
bool circleParser(vector<string>& details, double& x, double& y, double& radius)
{
    // Проверка наличия символа '(' (открывающейся скобки)
    if ((details.size() < 2) || (details[1] != "(")) {
        cout << "Ошибка: не найдена открывающаяся скобка \'(\'." << endl;
        return false;
    }

    // Проверка наличия аргумента - координаты X
    if ((details.size() > 2) && (!numberParser(details[2], x))) {
        cout << "Ошибка: ожидалось число: координата X." << endl;
        return false;
    }

    // Проверка наличия аргумента - координаты Y
    if ((details.size() > 3) && (!numberParser(details[3], y))) {
        cout << "Ошибка: ожидалось число: координата Y." << endl;
        return false;
    }

    // Проверка наличия символа ',' (запятая отделяющая координаты от радиуса)
    if ((details.size() < 5) || (details[4] != ",")) {
        cout << "Ошибка: не найдена запятая \',\'." << endl;
        return false;
    }

    // Проверка наличия аргумента - радиуса
    if ((details.size() > 5) && (!numberParser(details[5], radius))) {
        cout << "Ошибка: ожидалось число: raidus." << endl;
        return false;
    }
    if (radius < 0.0) {
        cout << "Ошибка: радиус не может быть отрицательным.";
    }

    // Проверка наличия символа ')' (закрывающейся скобки)
    if ((details.size() < 7) || (details[6] != ")")) {
        cout << "Ошибка: не найдена закрывающаяся скобка \')\'." << endl;
        return false;
    }

    // Проверка на отсутствие лишних токенов после ')' (закрывающейся скобки)
    if (details.size() > 7) {
        cout << "Ошибка: " << endl;
        for (unsigned int i = 7; i < details.size(); i++) {
            cout << "\"" << details[i] << "\"";
            if ((int)(i + 1) != (int)details.size()) {  // Если не последний элемент, то выводим запятую
                cout << ", ";
            }
        }
        cout << " - неизвестные токены." << endl;
        return false;
    }

    return true;
}
