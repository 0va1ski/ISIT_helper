//Вариант 11: Написать программу объединения трех строк без использования функции sprintf().

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <format>
using namespace std;

void Massiv() {
    char str1[20], str2[20], str3[20];
    cout << "Введите строку 1: ";
    cin.getline(str1, 20);
    cout << "Введите строку 2: ";
    cin.getline(str2, 20);
    cout << "Введите строку 3: ";
    cin.getline(str3, 20);

    char result[60];
    strcpy(result, str1);
    strcat(result, " ");
    strcat(result, str2);
    strcat(result, " ");
    strcat(result, str3);

    cout << "Итог: " << result << endl;
}

void Stroki() {
    string str1, str2, str3;
    cout << "Введите строку 1: ";
    getline(cin, str1);
    cout << "Введите строку 2: ";
    getline(cin, str2); 
    cout << "Введите строку 3: ";
    getline(cin, str3);
    
    cout << format("Итог: {} {} {}", str1, str2, str3) << endl;
}

int main() {
    cout << "ЧЕРЕЗ МАССИВЫ (С-СТРОКИ)" << endl;
    Massiv();
    cout << "ЧЕРЕЗ СТРОКИ" << endl;
    Stroki();
}