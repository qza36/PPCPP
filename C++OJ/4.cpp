#include <iostream>
#include <cmath>
using namespace std;

//定义一个抽象类Shape，利用抽象类Shape派生圆类Circle，圆类Circle再派生出圆的内接正方形类In_Square和圆的外切正方形类Ex_Square。main中利用指向抽象类的指针实现求圆、圆的内接正方形和圆的外切正方形的面积和周长的计算。请实现各个类的成员函数，已知各类的定义及main中的代码如下（不允许修改）：
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
    double r; //圆的半径（也可以将Radius函数去掉，r定义为protected属性，这样在子类中可以直接使用r）
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
//圆周率PI值取3.14。