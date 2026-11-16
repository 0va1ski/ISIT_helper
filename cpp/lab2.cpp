//Вариант 11: i = 0,5*x^5 + 3*cos(x+y) + e^-0,1*y*z - ^|x*y|
//ОДЗ: не ограничено -> проверка значений не нужна

#include <iostream>
#include <cmath>
#include <cstdio>
#include <format>
using namespace std;

int main() {
    double i, x, y, z;

    printf("Введите значения переменных x, y, z через пробел: ");
    if (scanf("%lf %lf %lf", &x, &y, &z) != 3) {
        printf("Ошибка ввода\n");
        return 1;
    }

    i = 0.5*pow(x,5) + 3*cos(x+y) + exp(-0.1*y*z) - sqrt(fabs(x*y));
    cout << format("i = {:.3f}", i) << endl;
}