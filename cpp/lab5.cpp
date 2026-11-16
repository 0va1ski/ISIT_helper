//Вариант 11:
//1. В векторе Y[m] поменять местами макс. с первым и мин. с последним
//2. Задана матрица P[7][7]. Найти в каждой строке макс. и поменять его местами с гл.диагонали

#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

const int MAX = 50; //максимальный размер вектора

//Для первой задачи
void Vector() {
    int m, Y[MAX];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-25, 25);

    do {
        cout << "Введите размер вектора (от 1 до " << MAX << "): ";
        cin >> m;
        if (m <= 0 || m > MAX) {
            cout << "Ошибка! Размер должен быть от 1 до " << MAX << ".\n";
        }
    } while (m <= 0 || m > MAX);

    cout << "Вектор Y[m]: ";
    for (int i = 0; i < m; i++) {
        Y[i] = dist(gen);
        cout << Y[i] << " ";
    }

    int maxIndex = max_element(Y, Y+m) - Y;
    swap(Y[0], Y[maxIndex]);
    int minIndex = min_element(Y, Y+m) - Y;
    swap(Y[m-1], Y[minIndex]);

    cout << "\nПеределанный вектор Y[m]: ";
    for (int i = 0; i < m; i++) {
        cout << Y[i] << " ";
    }
    cout << endl;
}

//Для второй задачи
void Matric() {
    int P[7][7];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(-25, 25);

    cout << "Матрица P[7][7]:\n";
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            P[i][j] = dist(gen);
            cout << P[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < 7; i++) {
        int maxIndex = max_element(P[i], P[i]+7) - P[i];
        swap(P[i][i], P[i][maxIndex]);
    }

    cout << "\nПеределанная матрица P[7][7]:\n";
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cout << P[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    cout << "ЗАДАНИЕ 1" << endl;
    Vector();
    cout << "ЗАДАНИЕ 2" << endl;
    Matric();
}