#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); }~LC() { cin.get(); cin.get(); } } _;

// Создайте класс с именем Time для хранения времени(или используйте уже ранее созданный вами).
// Напишите соответствующие конструкторы и функции - члены.
// Используя перегрузку операторов реализуйте для него арифметические операции для работы с классом Time:
// a) операция "+" для целого числа секунд : к времени Time прибавить целое число секунд(Time + int).
// b) операция "-" для целого числа секунд : от времени Time отнять целое число секунд(Time - int).Результат типа Time.
// c) операция "-" для определения разницы между двумя веременами(Time - Time).Результат типа Time.
// Добавьте в класс метод для приращения времени(которое хранится в объкте Time) на 1 секунду.

class Time
{
private:
    int Data;
public:
    Time() : Data() {}
    Time(int val) : Data(val) {}

    int GetData() const { return Data; }
    void SetData(int val) { Data = val; }

    Time& operator = (int val)
    {
        this->Data = val;
        return *this;
    }

    // a) операция "+" для целого числа секунд : к времени Time прибавить целое число секунд(Time + int).
    Time operator + (const int obj) const
    {
        Time result;
        result = this->Data + obj;
        return result;
    }

    // b) операция "-" для целого числа секунд : от времени Time отнять целое число секунд(Time - int).Результат типа Time.
    Time operator - (const int obj) const
    {
        Time result;
        result = this->Data - obj;
        return result;
    }

    // c) операция "-" для определения разницы между двумя веременами(Time - Time).Результат типа Time.
    Time operator - (const Time& obj) const
    {
        Time result;
        result = this->Data - obj.Data;
        return result;
    }

    Time Inc()
    {
        return this->Data + 1;
    }

    friend ostream& operator<< (ostream& os, const Time& obj)
    {
        os << obj.GetData();
        return os;
    }

    friend istream& operator>> (istream& is, Time& obj)
    {
        int tmp;
        cout << "Enter time: ";
        (is >> tmp).ignore();
        obj.SetData(tmp);
        return is;
    }
};


int main()
{
    Time a, b = 10, c;
    int d = 5;

    cin >> a;
    cout << "--------------------------------------------------\n";
    cout << "a (Time) = " << a
        << "\nb (Time) = " << b
        << "\nd (int) = " << d << endl;
    cout << "--------------------------------------------------\n";
    c = a + d;
    cout << "a (Time) + d (int) = " << c << endl;
    cout << "--------------------------------------------------\n";
    c = a - d;
    cout << "a (Time) - d (int) = " << c << endl;
    cout << "--------------------------------------------------\n";
    c = a - b;
    cout << "a (Time) - b (Time) = " << c << endl;
    cout << "--------------------------------------------------\n";

    int i = 1;
    cout << "Приращения времени (которое хранится в объкте Time) на 1 секунду:" << endl;

    while (i < 5)
    {
        a = a.Inc();
        cout << "i = " << a << endl;
        i++;
    }
}