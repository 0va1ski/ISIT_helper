//Вариант 11: 
//1) Решить уравнение ax^2 + b = 0 для любых коэфициентов
//2) Написать программу перевода введенного символа от A до F в нижний регистр, все другие - z

#include <iostream>
#include <cmath>
using namespace std;

//Для первой задачи
int Equation() {
    double a, b, x, D;
    D = -b / a;

    cout << "Введите a и b: ";
    cin >> a >> b;
    
    if (a == 0) {
        if (b == 0)
            cout << "x - любое число" << endl;          
        else
            cout << "Решений нет" << endl;              
        return 0;
    }

    if (D > 0) {
        x = sqrt(D);
        cout << "x1 = " << x << ", x2 = " << -x << endl;
    }
    else if (D == 0) {
        cout << "x = 0" << endl;
    }
    else {
        x = sqrt(-D);
        cout << "Действительных корней нет" << endl;
    }
    return 0;
}

//Для второй задачи
char Translation() {
    char simbol, result;
    cout << endl << "Введите символ: ";
    cin >> simbol;

    switch (simbol) {
        case 'A': result = 'a'; break;
        case 'B': result = 'b'; break;
        case 'C': result = 'c'; break;
        case 'D': result = 'd'; break;
        case 'E': result = 'e'; break;
        case 'F': result = 'f'; break;
        default:  result = 'z'; break;
    }

    cout << "Результат: " << result << endl;
    return result;
}

int main() {
    Equation();
    Translation();
    return 0;
}