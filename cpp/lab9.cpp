//Вариант 11: Написать программу поиска сотрудников, зарплата которых ниже средней по предприятию
//(ввод-вывод через файлы: исходные данные - stuff.txt, результат - result.txt)

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 10;                      //максимальное число сотрудников
const string INPUT_FILE = "stuff.txt";   //файл с сотрудниками
const string OUTPUT_FILE = "result.txt"; //файл с результатом

//Структура для описания работника (ФИО, зп)
struct Worker {
    string name;
    double salary;
};

//1. Пользователь вводит сотрудников с клавиатуры, они записываются в файл
bool InputToFile() {
    ofstream file(INPUT_FILE);
    if (!file) return false;

    int n;
    do {
        cout << "Введите кол-во сотрудников (от 1 до " << MAX << "): ";
        cin >> n;
    } while (n <= 0 || n > MAX);

    for (int i = 0; i < n; i++) {
        Worker w;
        cout << "\nСотрудник " << i+1 << "\nФИО: ";
        cin.ignore(); //убираем '\n', оставшийся после cin >>
        getline(cin, w.name);
        cout << "Зарплата: ";
        cin >> w.salary;

        file << w.name << " - " << w.salary << endl; //строка вида "ФИО - зп"
    }
    return true;
}

//2. Чтение сотрудников из файла в массив структур, возвращает их кол-во
int ReadFromFile(Worker w[]) {
    ifstream file(INPUT_FILE);
    string line;
    int n = 0;
    while (n < MAX && getline(file, line)) {
        size_t pos = line.rfind(" - ");    //ищем разделитель с конца строки
        if (pos == string::npos) continue; //строка без разделителя - пропускаем

        w[n].name = line.substr(0, pos);          //всё до " - " это ФИО
        w[n].salary = stod(line.substr(pos + 3)); //всё после " - " это зп
        n++;
    }
    return n;
}

//3. Средняя зарплата
double Average(Worker w[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += w[i].salary;
    return sum / n;
}

//4. Запись сотрудников с зп ниже средней в файл результата
bool WriteResult(Worker w[], int n) {
    ofstream file(OUTPUT_FILE);
    if (!file) return false;

    double avg = Average(w, n);
    file << "Средняя зарплата: " << avg << endl;
    file << "Сотрудники с зарплатой ниже средней:" << endl;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (w[i].salary < avg) {
            file << w[i].name << " - " << w[i].salary << endl;
            count++;
        }
    }
    if (count == 0)
        file << "Таких сотрудников нет" << endl;
    return true;
}

int main() {
    Worker w[MAX];

    if (!InputToFile()) {
        cout << "Ошибка открытия файла " << INPUT_FILE << endl;
        return 1;
    }

    int n = ReadFromFile(w);
    if (n == 0) {
        cout << "Не удалось прочитать сотрудников из " << INPUT_FILE << endl;
        return 1;
    }

    if (!WriteResult(w, n)) {
        cout << "Ошибка открытия файла " << OUTPUT_FILE << endl;
        return 1;
    }

    cout << "\nГотово! Результат записан в " << OUTPUT_FILE << endl;
    return 0;
}
