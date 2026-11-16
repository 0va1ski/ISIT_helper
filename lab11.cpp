//Есть машины: обычные (бензиновые) и электромобили.
//У всех есть общее (class Car): марка, тип кузова, максимальная скорость.
//У электромобиля есть свое (class Car_electric от Car): заряд батареи, зарядка.

#include <iostream>
#include <string>
using namespace std;

//Общий класс всех машин
class Car {
protected: //доступен из Car и Car_electric
    string brand, body;
    int maxSpeed; //км/ч

public:    //доступен из Car, Car_electric, main-функции
    Car(string br, string bod, int speed) {
        brand = br;
        body = bod;
        maxSpeed = speed;
    }

    //Наследуемая ф-ия 1: вывод информации о машине
    void Info() {
        cout << brand << " [" << body << "] | макс. скорость: " << maxSpeed << " км/ч" << endl;
    }

    //Наследуемая ф-ия 2: время в пути на расстояние distance (км)
    void TravelTime(double distance) {
        cout << distance << " км проедет за " << distance / maxSpeed << " ч" << endl;
    }
};

//Класс электромобиля, наследуется от Car
class Car_electric : public Car {
private:   //доступен только из Car_electric
    int charge; //заряд батареи в %

public:    //доступен из Car_electric и main-функции
    //сначала вызывается конструктор Car, батарея изначально заряжена на 50%
    Car_electric(string br, string bod, int speed) : Car(br, bod, speed) {
        charge = 50;
    }

    //Ненаследуемая ф-ия 1: вывод заряда батареи
    void BatteryInfo() {
        cout << "Заряд батареи: " << charge << "%" << endl;
    }

    //Ненаследуемая ф-ия 2: зарядка на percent % (не больше 100%)
    void Charge(int percent) {
        if (charge == 100) {
            cout << "Батарея уже полностью заряжена" << endl;
            return;
        }
        charge += percent;
        if (charge > 100) charge = 100;
        cout << "Машина заряжена до " << charge << "%" << endl;
    }
};

int main() {
    Car lada("Lada Vesta", "Седан", 180);
    Car kamaz("КамАЗ 5490", "Грузовик", 110);
    Car_electric tesla("Tesla Model 3", "Седан", 225);

    cout << "--- Lada ---" << endl;
    lada.Info();
    lada.TravelTime(360);

    cout << "\n--- КамАЗ ---" << endl;
    kamaz.Info();
    kamaz.TravelTime(220);

    cout << "\n--- Tesla ---" << endl;
    tesla.Info();           //наследуемая ф-ия из Car
    tesla.TravelTime(450);  //наследуемая ф-ия из Car
    tesla.BatteryInfo();    //ненаследуемая ф-ия, есть только у Car_electric

    tesla.Charge(30);       //ненаследуемая ф-ия
    tesla.Charge(40);       //больше 100% не зарядится
    tesla.Charge(10);       //уже полная
    tesla.BatteryInfo();

    //lada.Charge(30);      //ошибка: у Car нет этой ф-ии

    return 0;
}
