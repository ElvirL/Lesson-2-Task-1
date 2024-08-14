/*
Задание 1. Реализация записи в ведомость учёта
Что нужно сделать
В одном из прошлых заданий мы уже создавали программу чтения и анализа ведомости выплат. Теперь требуется создать простую программу 
записи в эту ведомость.
Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, далее располагается дата выдачи в формате ДД.ММ.ГГГГ. 
Завершает запись сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой записи должен быть расположен перевод 
строки.
При старте программы пользователь последовательно вводит данные для новой записи, которые записываются затем в файл в текстовом режиме. 
Программа должна добавлять новые записи в конец файла, не удаляя его текущее содержимое.
Советы и рекомендации
Введённые данные рекомендуется хотя бы минимально валидировать перед их записью.
Для валидации даты в указанном формате можно использовать функции std::stoi и std::subtr с корректно указанным диапазоном символов в дате. 
К примеру, вызов std::stoi(date.substr(3, 2)) вычленит из строковой даты целочисленный месяц для последующего анализа.
Что оценивается
Корректность работы программы. Программа должна дозаписывать данные в конец существующего списка.
Как отправить задание на проверку
Прислать ссылку на repl.it или файл .срр с решением.
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
    cout << "Сколько людей вы хотите добавить: ";
    int count_people;
    cin >> count_people;

    ofstream file("salary.txt", ios::app);

    for (int i=0; i<count_people; ++i){
        cout << "Введите имя: ";
        string name;
        cin >> name;
        while (!check_name_surname(name)){
            cout << "Имя и фамилия должны состоять только из английких букв" << endl;
            cout << "Введите имя: ";
            cin >> name;
        }

        cout << "Введите фамилию: ";
        string surname;
        cin >> surname;
        while (!check_name_surname(surname)){
            cout << "Имя и фамилия должны состоять только из английких букв" << endl;
            cout << "Введите фамилию: ";
            cin >> surname;
        }

        cout << "Введите дату в формате ДД.ММ.ГГГГ: ";
        string date;
        cin >> date;
        while (!check_date(date)){
            cout << "Некорректная форма даты" << endl;
            cout << "Введите дату в формате ДД.ММ.ГГГГ: ";
            cin >> date;
        }

        cout << "Введите сумму выплаты: ";
        double salary;
        cin >> salary;

        file << name << " " << surname << " " << date << " " << salary << endl;
        cout << name << " " << surname << " успешно добавлен" << endl;
        cout << endl;
    }

    file.close();
}