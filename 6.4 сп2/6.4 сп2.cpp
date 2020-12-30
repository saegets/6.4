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

void replace(int* a, int num)
{
    for (int i = 1; i < num; ++i)
    {
        for (int r = 0; r < num - i; r++)
        {
            if (a[r] < a[r + 1])
            {
                // obmin
                int temp = a[r];
                a[r] = a[r + 1];
                a[r + 1] = temp;
            }
        }
    }
}

void Print(int* a, const int num, int i, int& dob, int& sum)
{
    if (i == 0)
        cout << "a[" << num << "]={ ";
    cout << setw(4) << a[i] << ", ";
    if (i < num - 1)
        Print(a, num, i + 1, dob, sum);
    else
        cout << " }" << '\n' << "dobutok = " << dob << '\n' << "suma [1, n-1] = " << sum << endl;
}
void printr(int* a, int num, int r)
{
    replace(a, num);
    if (r == 0)
         cout << "replaced a[" << num << "] ={ ";
    cout << setw(4) << a[r] << ", ";
    if (r < num - 1)
        printr(a, num, r + 1);
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

int suma(int* a, const int num, int i, int& sum)
{
    if (i > 0)
        sum += a[i];
    if (i < num - 2)
        return suma(a, num, i + 1, sum);
    if (i = num -1)
        return sum;
}

int main()
{
    srand((unsigned)time(NULL));

    int num;
    cout << "array size: "; cin >> num;
    int* a = new int[num];
    int dob = 1;
    int sum = 0;
    Create(a, num, 0);
    dobutok(a, num, 0, dob);
    suma(a, num, 0, sum);
    Print(a, num, 0, dob, sum);
    printr(a, num, 0);

    return 0;
}


