#include <iostream>
#include <cmath>
using namespace std;
const int MaxSize = 100;

class Array
{
public:
    Array();
    int Length();
    double Get(int pos);
    void Insert(int pos, double x);
    void Display();
protected:
    double data[MaxSize];
    int length;
};

Array::Array()
{
    length = 0;
}

int Array::Length()
{
    return length;
}

double Array::Get(int pos)
{
    return data[pos];
}

void Array::Insert(int pos, double x)
{
    for (int i = length; i > pos; i--)
    {
        data[i] = data[i - 1];
    }
    data[pos] = x;
    length++;
}

void Array::Display()
{
    cout << "The length:" << length << endl;
    cout << "The elements:";
    for (int i = 0; i < length; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

class SortArray : private Array
{
public:
    SortArray();
    int Length();
    double Get(int pos);
    void Display();
    void Insert(double x);
};

SortArray::SortArray() : Array()
{
}

int SortArray::Length()
{
    return Array::Length();
}

double SortArray::Get(int pos)
{
    return Array::Get(pos);
}

void SortArray::Display()
{
    Array::Display();

}

void SortArray::Insert(double x)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (x < data[i])
        {
            break;
        }
    }
    Array::Insert(i, x);
}

int main()
{
    SortArray sa;
    double num;
    while (1)
    {
        cin >> num;
        if (fabs(num) <= 1e-6)
            break;
        try
        {
            sa.Insert(num);
        }
        catch (char* message)
        {
            cout << message << endl;
        }
    }
    sa.Display();

    return 0;
}