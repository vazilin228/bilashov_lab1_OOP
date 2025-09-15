#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

struct Pair {
    double first;   // число-основа
    double second;  // показник степеня

    // Метод ініціалізації
    bool init(double a, double b) {
        // Перевірка коректності
        if (a == 0 && b == 0) {
            cout << "Помилка: вираз 0^0 не визначений!" << endl;
            return false;
        }
        if (a < 0 && floor(b) != b) {
            cout << "Помилка: від’ємна основа при дробовому степені не визначена!" << endl;
            return false;
        }

        first = a;
        second = b;
        return true;
    }

    // Метод введення
    void Read() {
        double a, b;
        cout << "Введіть число (основа) та показник степеня: ";
        cin >> a >> b;

        while (!init(a, b)) {
            cout << "Спробуйте ще раз: ";
            cin >> a >> b;
        }
    }

    // Метод виведення
    void Display() const {
        cout << "Основа = " << first << ", Показник = " << second << endl;
    }

    // Метод зведення у степінь
    double power() const {
        return pow(first, second);
    }
};

// Тестування
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Pair p;

    p.Read();
    p.Display();

    cout << "Результат зведення у степінь: " << p.power() << endl;

    return 0;
}
