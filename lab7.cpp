//Вариант 11: Написать функцию вычисления числа сочетаний с повторениями

#include <iostream>
#include <cmath>
using namespace std;

int Combinations(int n, int k) {
    long long C;
    C = (tgamma((n+k-1)+1)) / ((tgamma(k+1))*(tgamma((n-1)+1)));
    return C;
}

int main() {
    int vars, objs;

    cout << "Введите кол-во вариантов: ";
    cin >> vars;
    cout << "Введите кол-во объектов в группе: ";
    cin >> objs;

    cout << "Число сочетаний с повторениями: " << Combinations(vars, objs) << endl;
}