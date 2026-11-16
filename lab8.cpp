//Вариант 11: Написать программу поиска сотрудников, зарплата которых ниже средней по предприятию

#include <iostream>
#include <string>
using namespace std;

const int MAX = 10; //максимальное кол-во сотрудников

//Структура для описания работника (имя, зарплата)
struct Worker {
    string name;
    double salary;
};

//Ф-ия вычисления средней зарплаты
double Average(Worker w[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += w[i].salary;
    }
    return sum / n;
}

//Ф-ия поиска сотрудников с зарплатой ниже среднего
void BelowAverage(Worker w[], int n, double avg) {
    int count = 0;
    cout << "\nСотрудники с зарплатой ниже средней:\n";
    for (int i = 0; i < n; i++) {
        if (w[i].salary < avg) {
            cout << w[i].name << " - " << w[i].salary << endl;
            count++;
        }
    }
    if (count == 0) {
        cout << "Таких сотрудников нет\n";
    }
}

int main() {
    Worker w[MAX];
    int n;

    do {
        cout << "Введите кол-во сотрудников (от 1 до " << MAX << "): ";
        cin >> n;
        if (n <= 0 || n > MAX) {
            cout << "Ошибка! Кол-во должно быть от 1 до " << MAX << ".\n";
        }
    } while (n <= 0 || n > MAX);

    for (int i = 0; i < n; i++) {
        cout << "\nСотрудник " << i+1 << endl;
        cout << "ФИО: ";
        cin.ignore(); //убираем '\n', оставшийся после cin >>
        getline(cin, w[i].name);
        cout << "Зарплата: ";
        cin >> w[i].salary;
    }

    double avg = Average(w, n);
    cout << "\nСредняя зарплата по предприятию: " << avg << endl;

    BelowAverage(w, n, avg);

    return 0;
}
