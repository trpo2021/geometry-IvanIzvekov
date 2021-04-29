#include "inputProcessing.h"
#include "infoOutput.h"
#include <iostream>

using std::cout;
using std::endl;



// ������������ ������� ������: ������ ��������� ���� �� ��������
string normalization(string command)
{
    for (unsigned int i = 0; i < command.size(); i++) {
        if (isupper(command[i])) {
            command[i] = tolower(command[i]);
        }
    }
    return command;
}

// ��������� ������� ������ �� ����� ��� ��������� ���������
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

// ������ �����: ��������� ������ � ����� � ��������� �� ���������� ������ ��������
bool numberParser(string strNumber, double& number)
{
	number=0.0;
    for (unsigned int countPoint = 0, i = 0; i < strNumber.size(); i++) {
        // ������� atof() ���������� ',' ��� ��������� ������� ����� ����� �� �����, ������� �������� '.' �� ','
        if (strNumber[i] == '.') {
            if (++countPoint > 1) {
                return false;
            }
        }
        else if ((strNumber[i] != '-') && (not isdigit(strNumber[i]))) {  // �������� ������ �� ���������� �������� �� ���������� ������
            return false;
        }
    }
    number = atof(strNumber.c_str());   // �������������� ������ � ����� double

    return true;
}

bool parser(vector<Circle>& circles, string command)
{
	command=normalization(command);

    vector<string> details = splitting(command);
    if (details.size() != 0) {
        // �������� �������� ������
        if (details[0] == "circle") {
            double x, y, radius;
            if (circleParser(details, x, y, radius)) {
                circleInfo(x, y, radius);

                circles.push_back(Circle(x, y, radius));

                return true;
            }
        }
        else {
            cout << "������: ����������� ������." << endl;
        }
    }
    else {
        cout << "������: ������ ������." << endl;
    }

    return false;
}
bool circleParser(vector<string>& details, double& x, double& y, double& radius)
{
    // �������� ������� ������� '(' (������������� ������)
    if ((details.size() < 2) || (details[1] != "(")) {
        cout << "������: �� ������� ������������� ������ \'(\'." << endl;
        return false;
    }

    // �������� ������� ��������� - ���������� X
    if ((details.size() > 2) && (!numberParser(details[2], x))) {
        cout << "������: ��������� �����: ���������� X." << endl;
        return false;
    }

    // �������� ������� ��������� - ���������� Y
    if ((details.size() > 3) && (!numberParser(details[3], y))) {
        cout << "������: ��������� �����: ���������� Y." << endl;
        return false;
    }

    // �������� ������� ������� ',' (������� ���������� ���������� �� �������)
    if ((details.size() < 5) || (details[4] != ",")) {
        cout << "������: �� ������� ������� \',\'." << endl;
        return false;
    }

    // �������� ������� ��������� - �������
    if ((details.size() > 5) && (!numberParser(details[5], radius))) {
        cout << "������: ��������� �����: raidus." << endl;
        return false;
    }
    if (radius < 0.0) {
        cout << "������: ������ �� ����� ���� �������������.";
    }

    // �������� ������� ������� ')' (������������� ������)
    if ((details.size() < 7) || (details[6] != ")")) {
        cout << "������: �� ������� ������������� ������ \')\'." << endl;
        return false;
    }

    // �������� �� ���������� ������ ������� ����� ')' (������������� ������)
    if (details.size() > 7) {
        cout << "������: " << endl;
        for (unsigned int i = 7; i < details.size(); i++) {
            cout << "\"" << details[i] << "\"";
            if ((int)(i + 1) != (int)details.size()) {  // ���� �� ��������� �������, �� ������� �������
                cout << ", ";
            }
        }
        cout << " - ����������� ������." << endl;
        return false;
    }

    return true;
}
