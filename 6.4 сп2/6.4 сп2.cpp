#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, int i)
{
    a[i] = -10 + rand() % -36;

    if (i < size - 1)
        Create(a, size, i + 1);
}

void replace(int* a, int* b, int num)
{
    int k = 0; int j = 0;

    for (int i = 0; i < num; i++)
    {
        if (a[i] < 0)
        {
            b[num - 1 - k] = a[i];
            k++;
        }
        else
        {
            b[j] = a[i];
            j++;
        }
    }
}


void Print(int* a, int* b, const int num, int i, int& dob, int& sum)
{
    if (i == 0)
        cout << "a[" << num << "]={ ";
    cout << setw(4) << a[i] << ", ";
    if (i < num - 1)
        Print(a, b, num, i + 1, dob, sum);
    else
        cout << " }" << '\n' << "dobutok = " << dob << '\n' << "suma [1, n-1] = " << sum << endl;
}

void printr(int* a, int* b, int num, int i)
{
    replace(a, b, num);
    if (i == 0)
        cout << "replaced a[" << num << "] ={ ";
    cout << setw(4) << b[i] << ", ";
    if (i < num - 1)
        printr(a, b, num, i + 1);
    else cout << "}" << endl;
}

int dobutok(int* a, const int num, int i, int& dob)
{
    if (i % 2 == 0)
        dob *= a[i];
    if (i < num - 1)
        return dobutok(a, num, i + 1, dob);
    else
        return dob;
}

int sum(int* a, int num, int& suma)
{
    suma = 0;
    int n, i, k = 0, p = 0;
    for (i = 0; i < num; i++)
    {
        if (a[i] == 0)
        {
            k = i;
            break;
        }
    }
    for (i = num - 1; i >= 0; i--)
        if (a[i] == 0)
        {
            p = i;
            break;
        }
    for (i = k; i <= p; i++)
    {
        suma = suma + a[i];
    }

    return suma;
}


int main()
{
    srand((unsigned)time(NULL));
    int num;
    int j = 0;
    cout << "array size: "; cin >> num;
    int* a = new int[num];
    int* b = new int[j];
    int dob = 1;
    int suma = 0;
    Create(a, num, 0);
    dobutok(a, num, 0, dob);
    sum(a, num, suma);
    Print(a, b, num, 0, dob, suma);
    printr(a, b, num, 0);

    return 0;
}
