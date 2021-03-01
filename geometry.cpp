#include <iostream>
#include <string>
#include <vector>
 
 
using namespace std;
 
 
const double PI = 3.141592653589793238463;
 
 
// Нормализация входных данных: замена заглавных букв на строчные
void normalization(string& command)
{ 
    for (auto& c : command) {
        if (isupper(c)) {
            c = tolower(c);
        }
    }
}
 
// Разбиение входных данных на части для упрощения обработки
vector<string> splitting(string& command)
{
    vector<string> details;
 
    string detail = "";
    for (int i = 0; i <= command.size(); i++) {
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
bool numberParser(string& strNumber, double& number)
{
    for (int countPoint = 0, i = 0; i < strNumber.size(); i++) {
        // Функция atof() использует ',' для отделения дробной части числа от целой, поэтому заменяем '.' на ','
        if (strNumber[i] == '.') {
            if (++countPoint > 1) {
                return false;
            }
            strNumber[i] = ',';
        }
        else if ((strNumber[i] != '-') && (not isdigit(strNumber[i]))) {  // Проверка строки на отсутствие символов не являющихся цифрой
            return false;
        }
    }
    number = atof(strNumber.c_str());   // Преобразование строки в число double
 
    return true;
}
 
void circleParser(vector<string>& details)
{
    double x, y, radius;
 
    // Проверка наличия символа '(' (открывающейся скобки)
    if ((details.size() < 2) || (details[1] != "(")) {
        cout << "Ошибка: не найдена открывающаяся скобка \'(\'." << endl;
        return;
    }
 
    // Проверка наличия аргумента - координаты X
    if ((details.size() > 2) && (!numberParser(details[2], x))) {
        cout << "Ошибка: ожидалось число: координата X." << endl;
        return;
    }
 
    // Проверка наличия аргумента - координаты Y
    if ((details.size() > 3) && (!numberParser(details[3], y))) {
        cout << "Ошибка: ожидалось число: координата Y." << endl;
        return;
    }
 
    // Проверка наличия символа ',' (запятая отделяющая координаты от радиуса)
    if ((details.size() < 5) || (details[4] != ",")) {
        cout << "Ошибка: не найдена запятая \',\'." << endl;
        return;
    }
 
    // Проверка наличия аргумента - радиуса
    if ((details.size() > 5) && (!numberParser(details[5], radius))) {
        cout << "Ошибка: ожидалось число: raidus." << endl;
        return;
    }
    if (radius < 0.0) {
        cout << "Ошибка: радиус не может быть отрицательным.";
    }
 
    // Проверка наличия символа ')' (закрывающейся скобки)
    if ((details.size() < 7) || (details[6] != ")")) {
        cout << "Ошибка: не найдена закрывающаяся скобка \')\'." << endl;
        return;
    }
    
    // Проверка на отсутствие лишних токенов после ')' (закрывающейся скобки)
    if (details.size() > 7) {
        cout << "Ошибка: " << endl;
        for (int i = 7; i < details.size(); i++) {
            cout << "\"" << details[i] << "\"";
            if (i + 1 != details.size()) {  // Если не последний элемент, то выводим запятую
                cout << ", ";
            }
        }
        cout << " - неизвестные токены." << endl;
        return;
    }
 }
void triangleParser(vector<string>& details)
{
    double x1, y1;
    double x2, y2;
    double x3, y3;
 
    // Проверка наличия символа '(' (открывающейся скобки)
    if ((details.size() < 2) || (details[1] != "(")) {
        cout << "Ошибка: не найдена открывающаяся скобка \'(\'." << endl;
        return;
    }
 
    // Проверка наличия символа '(' (открывающейся скобки)
    if ((details.size() < 3) || (details[2] != "(")) {
        cout << "Ошибка: не найдена открывающаяся скобка \'(\'." << endl;
        return;
    }
 
    // Проверка наличия аргумента - координаты X1
    if ((details.size() > 3) && (!numberParser(details[3], x1))) {
        cout << "Ошибка: ожидалось число: координата X1." << endl;
        return;
    }
 
    // Проверка наличия аргумента - координаты Y1
    if ((details.size() > 4) && (!numberParser(details[4], y1))) {
        cout << "Ошибка: ожидалось число: координата Y1." << endl;
        return;
    }
 
    // Проверка наличия символа ',' (запятая отделяющая координаты вершины 1, от 2)
    if ((details.size() < 6) || (details[5] != ",")) {
        cout << "Ошибка: не найдена запятая \',\'." << endl;
        return;
    }
 
 
    // Проверка наличия аргумента - координаты X2
    if ((details.size() > 6) && (!numberParser(details[6], x2))) {
        cout << "Ошибка: ожидалось число: координата X2." << endl;
        return;
    }
 
    // Проверка наличия аргумента - координаты Y2
    if ((details.size() > 7) && (!numberParser(details[7], y2))) {
        cout << "Ошибка: ожидалось число: координата Y2." << endl;
        return;
    }
 
    // Проверка наличия символа ',' (запятая отделяющая координаты вершины 2, от 3)
    if ((details.size() < 9) || (details[8] != ",")) {
        cout << "Ошибка: не найдена запятая \',\'." << endl;
        return;
    }
 
    // Проверка наличия аргумента - координаты X3
    if ((details.size() > 9) && (!numberParser(details[9], x3))) {
        cout << "Ошибка: ожидалось число: координата X3." << endl;
        return;
    }
 
    // Проверка наличия аргумента - координаты Y3
    if ((details.size() > 10) && (!numberParser(details[10], y3))) {
        cout << "Ошибка: ожидалось число: координата Y3." << endl;
        return;
    }
 
    // Проверка наличия символа ')' (закрывающейся скобки)
    if ((details.size() < 12) || (details[11] != ")")) {
        cout << "Ошибка: не найдена закрывающаяся скобка \')\'." << endl;
        return;
    }
    // Проверка наличия символа ')' (закрывающейся скобки)
    if ((details.size() < 13) || (details[12] != ")")) {
        cout << "Ошибка: не найдена закрывающаяся скобка \')\'." << endl;
        return;
    }
 
    // Проверка на отсутствие лишних токенов после ')' (закрывающейся скобки)
    if (details.size() > 13) {
        cout << "Ошибка: " << endl;
        for (int i = 13; i < details.size(); i++) {
            cout << "\"" << details[i] << "\"";
            if (i + 1 != details.size()) {  // Если не последний элемент, то выводим запятую
                cout << ", ";
            }
        }
        cout << " - неизвестные токены." << endl;
        return;
    }
 }
void parser(vector<string>& details)
{
    if (details.size() != 0) {
        // Проверка названия фигуры
        if (details[0] == "circle") {
            circleParser(details);
        }
        else if (details[0] == "triangle") {
            triangleParser(details);
        }
        else {
            cout << "Ошибка: неизвестная фигура." << endl;
        }
    }
    else {
        cout << "Ошибка: пустая строка." << endl;
    }
}
 
void processing(string command)
{
    normalization(command);
 
    vector<string> details = splitting(command);
    parser(details);
}
 
 
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
