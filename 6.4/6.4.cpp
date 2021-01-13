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

int dobutok(int* a, int num, int& dob)
{
    dob = 1;
    for (int i = 0; i < num; i++)
        if (i % 2 == 0)
        {
           dob *= a[i];
        }
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

void print(int* a, int* b, int num, int& dob, int& suma)
{
    cout << setw(4) << "a[" << num << "] = { ";
    for (int i = 0; i < num; i++)
        cout << setw(4) << a[i] << ",";

    cout << " }" << endl;

    cout << "dobutok =" << dobutok(a, num, dob) << endl;

    cout << "suma[1; n - 1] = " << sum(a, num, suma) << endl;

    replace(a, b, num);
    cout << "replaced a[" << num << "] ={ ";
    for (int i = 0; i < num; i++)
    {
        cout << b[i] << ", ";
    }
    cout << "}" << endl;
   
    cout << endl;
}



int main()
{
    srand((unsigned)time(NULL));

    int num, dob;
    cout << "array size: "; cin >> num;
    int* a = new int[num];
    int suma = 0;
    int* b = new int[num];
    Create(a, num);
    dobutok(a, num, dob);
    sum(a, num, suma);
    print(a, b, num, dob, suma);
 
    return 0;
}