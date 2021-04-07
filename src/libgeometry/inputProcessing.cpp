#include "inputProcessing.h"
#include "infoOutput.h"
#include <iostream>

using std::cout;
using std::endl;

void processing(string command)
{
    normalization(command);

    vector<string> details = splitting(command);
    parser(details);
}
void normalization(string& command)
{
    for (unsigned int i = 0; i < command.size(); i++) {
        if (isupper(command[i])) {
            command[i] = tolower(command[i]);
        }
    }
}
vector<string> splitting(string& command)
{
    vector<string> details;

    string detail = "";
    for (unsigned int i = 0; i <= command.size(); i++) {
        if ((command[i] == ' ') || (command[i] == '(') || (command[i] == ',')
            || (command[i] == ')') || (command[i] == '\0')) {
            if (detail.size() != 0) {
                details.push_back(detail);
                detail = "";
            }
            if (command[i] == '(') {
                details.push_back("(");
            } else if (command[i] == ',') {
                details.push_back(",");
            } else if (command[i] == ')') {
                details.push_back(")");
            }
        } else {
            if (command[i] != ' ') {
                detail += command[i];
            }
        }
    }

    return details;
}
bool numberParser(string& strNumber, double& number)
{
    for (unsigned int countPoint = 0, i = 0; i < strNumber.size(); i++) {
        if (strNumber[i] == '.') {
            if (++countPoint > 1) {
                return false;
            }
            strNumber[i] = ',';
        } else if ((strNumber[i] != '-') && (not isdigit(strNumber[i]))) {
            return false;
        }
    }
    number = atof(strNumber.c_str());

    return true;
}

void parser(vector<string>& details)
{
    if (details.size() != 0) {
        if (details[0] == "circle") {
            double x, y, radius;
            circleParser(details, x, y, radius);
            circleInfo(x, y, radius);
        } else if (details[0] == "triangle") {
            double x1, y1;
            double x2, y2;
            double x3, y3;
            triangleParser(details, x1, y1, x2, y2, x3, y3);
            triangleInfo(x1, y1, x2, y2, x3, y3);
        } else {
            cout << "������: ����������� ������." << endl;
        }
    } else {
        cout << "������: ������ ������." << endl;
    }
}
void circleParser(vector<string>& details, double& x, double& y, double& radius)
{
    if ((details.size() < 2) || (details[1] != "(")) {
        cout << "������: �� ������� ������������� ������ \'(\'." << endl;
        return;
    }
    if ((details.size() > 2) && (!numberParser(details[2], x))) {
        cout << "������: ��������� �����: ���������� X." << endl;
        return;
    }
    if ((details.size() > 3) && (!numberParser(details[3], y))) {
        cout << "������: ��������� �����: ���������� Y." << endl;
        return;
    }
    if ((details.size() < 5) || (details[4] != ",")) {
        cout << "������: �� ������� ������� \',\'." << endl;
        return;
    }
    if ((details.size() > 5) && (!numberParser(details[5], radius))) {
        cout << "������: ��������� �����: raidus." << endl;
        return;
    }
    if (radius < 0.0) {
        cout << "������: ������ �� ����� ���� �������������.";
    }
    if ((details.size() < 7) || (details[6] != ")")) {
        cout << "������: �� ������� ������������� ������ \')\'." << endl;
        return;
    }
    if (details.size() > 7) {
        cout << "������: " << endl;
        for (unsigned int i = 7; i < details.size(); i++) {
            cout << "\"" << details[i] << "\"";
            if ((int)(i + 1) != (int)details.size()) {
                cout << ", ";
            }
        }
        cout << " - ����������� ������." << endl;
        return;
    }
}
void triangleParser(
        vector<string>& details,
        double& x1,
        double& y1,
        double& x2,
        double& y2,
        double& x3,
        double& y3)
{
    if ((details.size() < 2) || (details[1] != "(")) {
        cout << "������: �� ������� ������������� ������ \'(\'." << endl;
        return;
    }
    if ((details.size() < 3) || (details[2] != "(")) {
        cout << "������: �� ������� ������������� ������ \'(\'." << endl;
        return;
    }
    if ((details.size() > 3) && (!numberParser(details[3], x1))) {
        cout << "������: ��������� �����: ���������� X1." << endl;
        return;
    }
    if ((details.size() > 4) && (!numberParser(details[4], y1))) {
        cout << "������: ��������� �����: ���������� Y1." << endl;
        return;
    }
    if ((details.size() < 6) || (details[5] != ",")) {
        cout << "������: �� ������� ������� \',\'." << endl;
        return;
    }
    if ((details.size() > 6) && (!numberParser(details[6], x2))) {
        cout << "������: ��������� �����: ���������� X2." << endl;
        return;
    }
    if ((details.size() > 7) && (!numberParser(details[7], y2))) {
        cout << "������: ��������� �����: ���������� Y2." << endl;
        return;
    }
    if ((details.size() < 9) || (details[8] != ",")) {
        cout << "������: �� ������� ������� \',\'." << endl;
        return;
    }
    if ((details.size() > 9) && (!numberParser(details[9], x3))) {
        cout << "������: ��������� �����: ���������� X3." << endl;
        return;
    }
    if ((details.size() > 10) && (!numberParser(details[10], y3))) {
        cout << "������: ��������� �����: ���������� Y3." << endl;
        return;
    }
    if ((details.size() < 12) || (details[11] != ")")) {
        cout << "������: �� ������� ������������� ������ \')\'." << endl;
        return;
    }
    if ((details.size() < 13) || (details[12] != ")")) {
        cout << "������: �� ������� ������������� ������ \')\'." << endl;
        return;
    }
    if (details.size() > 13) {
        cout << "������: " << endl;
        for (unsigned int i = 13; i < details.size(); i++) {
            cout << "\"" << details[i] << "\"";
            if ((int)(i + 1) != (int)details.size()) {
                cout << ", ";
            }
        }
        cout << " - ����������� ������." << endl;
        return;
    }
}
