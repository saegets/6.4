#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, int num)
{
    for (int i = 0; i < num; i++)
        a[i] = -10 + rand() % -36;
}

void dobutok(int* a, int num, int& dob)
{
    for (int i = 0; i < num; i++)
        if (i % 2 == 0)
        {
           dob *= a[i];
        }
}

void sum(int* a, int num, int& suma)
{
    for (int i = 1; i < (num - 1); i++)
    {
        suma += a[i];
    }

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

void print(int* a, int num, int& dob, int& suma)
{
    cout << setw(4) << "a[" << num << "] = { ";
    for (int i = 0; i < num; i++)
        cout << setw(4) << a[i] << ",";

    cout << " }" << endl;

    cout << "dobutok =" << dob << endl;

    cout << "suma[1; n - 1] = " << suma << endl;

    replace(a, num);
    cout << "replaced a[" << num << "] ={ ";
    for (int r = 0; r < num; r++)
    {
        cout << a[r] << ", ";
    }
    cout << "}" << endl;
   
    cout << endl;
}



int main()
{
    srand((unsigned)time(NULL));

    int num;
    cout << "array size: "; cin >> num;
    int* a = new int[num];
    int dob = 1;
    int suma = 0;
    Create(a, num);
    dobutok(a, num, dob);
    sum(a, num, suma);
    print(a, num, dob, suma);
 
    return 0;
}