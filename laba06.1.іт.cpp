
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Перевірка критерію
bool ShouldReplace(int value, int index)
{
    return value % 2 == 0 || index % 8 != 0;
}

// 1. Створення масиву
void Create(int c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        c[i] = 5 + rand() % 86;
    }
}

// 2. Виведення масиву
void Print(const int c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << c[i];
    }
    cout << endl;
}

// 3. Обчислення кількості
int Count(const int c[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (ShouldReplace(c[i], i))
        {
            count++;
        }
    }

    return count;
}

// 4. Обчислення суми
int Sum(const int c[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (ShouldReplace(c[i], i))
        {
            sum += c[i];
        }
    }

    return sum;
}

// 5. Заміна елементів нулями
void Replace(int c[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (ShouldReplace(c[i], i))
        {
            c[i] = 0;
        }
    }
}

int main()
{
    const int n = 25;
    int c[n];

    srand(static_cast<unsigned int>(time(nullptr)));

    Create(c, n);

    cout << "Original array:" << endl;
    Print(c, n);

    int quantity = Count(c, n);
    int sum = Sum(c, n);

    Replace(c, n);

    cout << "Quantity = " << quantity << endl;
    cout << "Sum = " << sum << endl;

    cout << "Modified array:" << endl;
    Print(c, n);

    return 0;
}
