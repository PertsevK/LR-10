#include <iostream>
using namespace std;

void Param73(); // Використовуючи тип TTime (див. Param71), описати процедуру PrevSec (T) з
// параметром типу TTime, яка змінює час на - 1 секунду(якщо час T є
// неправильним, то воно не змінюється).Запис T є вхідним і вихідним
// параметром.Застосувати процедуру PrevSec до п'яти заданих моментів часу.

void Begin21(); // Дано координати трьох вершин трикутника: (x1, y1), (x2, y2), (x3, y3). Знайти його
// периметр і площу, використовуючи формулу для відстані між двома точками на
// площині(див.Begin20).Для знаходження площі трикутника зі сторонами a, b, c
// використовувати формулу Герона : S = (p ·(p - a) ·(p - b) ·(p - c)) 1 / 2, де p = (a + b + c)
// / 2 - напівпериметр.

void Boolean9(); // Дано два цілих числа: A, B. Перевірити істинність висловлювання: «Хоча б
// одне з чисел A і B непарне».

bool cor_main(int); // Допоміжнi функції

int main()
{ // Перемикання між завданнями
    setlocale(LC_ALL, "Ukrainian");
    int num; // Оголошення
    do
    {
        cout << "Введiть номер завдання (вихiд - 4)\n";
        cin >> num; // Введення даних
        if (cor_main(num))
        {
            switch (num)
            {
            case 1: Param73(); break; // Завдання 1
            case 2: Begin21(); break; // Завдання 2
            case 3: Boolean9(); break; // Завдання 3
            case 4: cout << "Вихiд..."; break;
            }
        }
        else cout << "Помилка. Потрiбно ввести 1, 2, 3, 4\n"; // Повідомлення про помилку
    } while (num != 4);
}

bool cor_main(int n) // Допоміжна
{
    if (n == 1 || n == 2 || n == 3 || n == 4) return true;
    else return false;
}

struct TTime { // Структура TTime
    int Hour, Min, Sec;
};

void PrevSec(TTime& T) // Функція зміни секунд
{
    if (T.Hour >= 0 && T.Hour < 24 && T.Min >= 0 && T.Min < 60 && T.Sec >= 0 && T.Sec < 60)
    {
        T.Sec = T.Sec - 1; // Зміщення секунди
        if (T.Sec == -1) T.Min = T.Min - 1, T.Sec = 59; // Зміщення хвилин
        if (T.Min == -1) T.Hour = T.Hour - 1, T.Min = 59; // Зміщення годин
        if (T.Hour == -1) T.Hour = 23; // Якщо час - 00:00:00
    }
}

void Param73()
{
    TTime T; // Змінна часу
    for (int k = 1; k <= 5; k++)
    {
        cout << "Введiть час\n";
        cin >> T.Hour >> T.Min >> T.Sec;
        PrevSec(T); // Функція перевірки та зміни
        cout << T.Hour << ":" << T.Min << ":" << T.Sec << endl;
    }
}

double ab, bc, ac; // Сторони трикутника

struct TPoint {// Структура TPoint
    double x, y;
};

struct TTriangle {
    TPoint A, B, C;
    double Square() // Метод, що реалізує обробку структури відповідно до задачі
    {
        double p = (ab + bc + ac) / 2, S = sqrt(p * (p - ab) * (p - bc) * (p - ac));
        return S;
    }
    double Perim() // Метод, що реалізує обробку структури відповідно до задачі
    {
        return ab + bc + ac;
    }
    bool cor_Begin21() // Mетод, що перевіряє на коректність і заповнює відповідні поля вхідних даних стуктури
    {
        cout << "Введiть координати вершин (A, B, C)\n";
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y; // Введення координат вершин
        ab = sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y)); // Розрахунок ab
        bc = sqrt((C.x - B.x) * (C.x - B.x) + (C.y - B.y) * (C.y - B.y)); // Розрахунок bc
        ac = sqrt((C.x - A.x) * (C.x - A.x) + (C.y - A.y) * (C.y - A.y)); // Розрахунок ac
        if (ab > 0 && bc > 0 && ac > 0) return true; // Сторони повинні бути більше 0
        else return false;
    }
};

void Begin21()
{
    TTriangle Cord;
    if (Cord.cor_Begin21()) // Введення та перевірка даних
        cout << "Площа - " << Cord.Square() << endl << "Периметр - " << Cord.Perim() << endl;
    else cout << "Помилка\n";
}

struct int2 {
    int A, B;
    void in_Boolean9(int& A, int& B) // Mетод, що заповнює відповідні поля вхідних даних стуктури
    {
        cout << "Введiть два числа\n";
        cin >> A >> B; // Введення А, И
    }
    bool proc_Boolean() // Mетод, що реалізує обробку структури відповідно до задачі
    {
        int c, d; // Оголошення змінних
        in_Boolean9(A, B);
        c = (A % 2 == 0) ? 0 : 1;
        d = (B % 2 == 0) ? 0 : 1;
        if (c==1 || d==1) return true;
        else return false;
    }
};

void Boolean9()
{
    int2 AB;
    if (AB.proc_Boolean()==0)  // Введення та перевірка даних
        cout << "Непарних немає\n";
    else cout << "Одне з чисел непарне\n";
}