#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;

struct Pair {
    double first;   // �����-������
    double second;  // �������� �������

    // ����� �����������
    bool init(double a, double b) {
        // �������� ����������
        if (a == 0 && b == 0) {
            cout << "�������: ����� 0^0 �� ����������!" << endl;
            return false;
        }
        if (a < 0 && floor(b) != b) {
            cout << "�������: �䒺��� ������ ��� ��������� ������ �� ���������!" << endl;
            return false;
        }

        first = a;
        second = b;
        return true;
    }

    // ����� ��������
    void Read() {
        double a, b;
        cout << "������ ����� (������) �� �������� �������: ";
        cin >> a >> b;

        while (!init(a, b)) {
            cout << "��������� �� ���: ";
            cin >> a >> b;
        }
    }

    // ����� ���������
    void Display() const {
        cout << "������ = " << first << ", �������� = " << second << endl;
    }

    // ����� �������� � ������
    double power() const {
        return pow(first, second);
    }
};

// ����������
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Pair p;

    p.Read();
    p.Display();

    cout << "��������� �������� � ������: " << p.power() << endl;

    return 0;
}
