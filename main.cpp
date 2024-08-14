/*
������� 1. ���������� ������ � ��������� �����
��� ����� �������
� ����� �� ������� ������� �� ��� ��������� ��������� ������ � ������� ��������� ������. ������ ��������� ������� ������� ��������� 
������ � ��� ���������.
������ ��������� �������. ������� ��� ��� � ������� ���������� �������� �������, ����� ������������� ���� ������ � ������� ��.��.����. 
��������� ������ ����� ������� � ������. ������ ����������� ����� ����� ���������. � ����� ������ ������ ������ ���� ���������� ������� 
������.
��� ������ ��������� ������������ ��������������� ������ ������ ��� ����� ������, ������� ������������ ����� � ���� � ��������� ������. 
��������� ������ ��������� ����� ������ � ����� �����, �� ������ ��� ������� ����������.
������ � ������������
�������� ������ ������������� ���� �� ���������� ������������ ����� �� �������.
��� ��������� ���� � ��������� ������� ����� ������������ ������� std::stoi � std::subtr � ��������� ��������� ���������� �������� � ����. 
� �������, ����� std::stoi(date.substr(3, 2)) �������� �� ��������� ���� ������������� ����� ��� ������������ �������.
��� �����������
������������ ������ ���������. ��������� ������ ������������ ������ � ����� ������������� ������.
��� ��������� ������� �� ��������
�������� ������ �� repl.it ��� ���� .��� � ��������.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool check_name_surname(const string& s){
    for (size_t i=0; i<s.size(); ++i){
        if ((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z')){
            return false;
        }
    }
    return true;
}

bool check_date(const string& date){
    if (date.size() != 10){
        return false;
    }

    if (date[2] != '.' || date[5] != '.'){
        return false;
    }

    for (size_t i=0; i<date.size(); ++i){
        if ((date[i] < '0' && date[i] !='.') || date [i] > '9'){
            return false;
        }
    }

    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1)
        return false;
    
    return true;

}

int main(){
    setlocale(LC_ALL, "Russian");
    cout << "������� ����� �� ������ ��������: ";
    int count_people;
    cin >> count_people;

    ofstream file("salary.txt", ios::app);

    for (int i=0; i<count_people; ++i){
        cout << "������� ���: ";
        string name;
        cin >> name;
        while (!check_name_surname(name)){
            cout << "��� � ������� ������ �������� ������ �� ��������� ����" << endl;
            cout << "������� ���: ";
            cin >> name;
        }

        cout << "������� �������: ";
        string surname;
        cin >> surname;
        while (!check_name_surname(surname)){
            cout << "��� � ������� ������ �������� ������ �� ��������� ����" << endl;
            cout << "������� �������: ";
            cin >> surname;
        }

        cout << "������� ���� � ������� ��.��.����: ";
        string date;
        cin >> date;
        while (!check_date(date)){
            cout << "������������ ����� ����" << endl;
            cout << "������� ���� � ������� ��.��.����: ";
            cin >> date;
        }

        cout << "������� ����� �������: ";
        double salary;
        cin >> salary;

        file << name << " " << surname << " " << date << " " << salary << endl;
        cout << name << " " << surname << " ������� ��������" << endl;
        cout << endl;
    }

    file.close();
}