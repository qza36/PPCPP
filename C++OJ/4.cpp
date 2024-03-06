#include <iostream>
#include <cmath>
using namespace std;

//����һ��������Shape�����ó�����Shape����Բ��Circle��Բ��Circle��������Բ���ڽ���������In_Square��Բ��������������Ex_Square��main������ָ��������ָ��ʵ����Բ��Բ���ڽ������κ�Բ�����������ε�������ܳ��ļ��㡣��ʵ�ָ�����ĳ�Ա��������֪����Ķ��弰main�еĴ������£��������޸ģ���
class Shape
{
public:
    virtual double Area() = 0;
    virtual double Perimeter() = 0;
};
class Circle :public Shape
{
public:
    Circle(double rr);
    double Area();
    double Perimeter();
protected:
    double r; //Բ�İ뾶��Ҳ���Խ�Radius����ȥ����r����Ϊprotected���ԣ������������п���ֱ��ʹ��r��
};
Circle::Circle(double rr)
{
	r = rr;
}
double Circle::Area()
{
	return 3.14 * r * r;
}
double Circle::Perimeter()
{
	return 2 * 3.14 * r;
}
class In_Square :public Circle
{
public:
    In_Square(double rr);
    double Area();
    double Perimeter();
};
In_Square::In_Square(double rr) :Circle(rr)
{
}
double In_Square::Area()
{
	return 2 * r * r;
}
double In_Square::Perimeter()
{
	return 4*sqrt(2)*r;
}
class Ex_Square :public Circle
{
public:
    Ex_Square(double r);
    double Area();
    double Perimeter();
};
Ex_Square::Ex_Square(double rr) :Circle(rr)
{
}
double Ex_Square::Area()
{
	return 4 * r * r;
}
double Ex_Square::Perimeter()
{
	return 8 * r;
}
int main()
{
    Shape* ptr;
    double r;
    cin >> r;
    ptr = new Circle(r);
    cout << "Circle's area:" << ptr->Area() << endl;
    cout << "Circle's perimeter:" << ptr->Perimeter() << endl;
    ptr = new In_Square(r);
    cout << "In_Square's area:" << ptr->Area() << endl;
    cout << "In_Square's perimeter:" << ptr->Perimeter() << endl;
    ptr = new Ex_Square(r);
    cout << "Ex_Square's area:" << ptr->Area() << endl;
    cout << "Ex_Square's perimeter:" << ptr->Perimeter() << endl;
    return 0;
}
//Բ����PIֵȡ3.14��