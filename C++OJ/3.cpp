#include <iostream>
using namespace std;

//已知由Automobille类派生出Car类和Wagon类，而后两者共同派生出StationWagon类，各类的定义及main中的代码（不允许改动）如下，请实现各个类的成员函数，完成相应的输出：
/*样例输入
108 3 10
样例输出
StationWagon:
Power:108
Seat:3
Load:10*/
class Automobile              //汽车类

{

private:

    int power;   //马力

public:

    Automobile(int p);

    void Display();

};
Automobile::Automobile(int p) {
    	power = p;
}
void Automobile::Display() {
	cout << "Power:" << power << endl;
}
class Car :virtual  public Automobile   //小客车类

{

private:

    int seat;     //座位

public:

    Car(int p, int s);

    void Display();

};
Car::Car(int p, int s) :Automobile(p) {
		seat = s;
}
void Car::Display() {
   	cout << "Seat:" << seat << endl;
}

class Wagon :virtual  public Automobile //小货车类
{
private:
    int load;     //装载量
public:
    Wagon(int p, int l);
    void Display();
};
Wagon::Wagon(int p, int l) :Automobile(p) {
	load = l;
}
void Wagon::Display() {
    	cout << "Load:" << load << endl;
}

class StationWagon :public Car, public Wagon  //客货两用车类

{

public:

    StationWagon(int p, int s, int l);

    void Display();

};
StationWagon::StationWagon(int p, int s, int l) :Automobile(p), Car(p, s), Wagon(p, l) {
}
void StationWagon::Display() {
	//Display();
	cout << "StationWagon:" << endl;
	Automobile::Display();
	Car::Display();
	Wagon::Display();
}

int main()

{

    int power, load, seat;

    cin >> power >> seat >> load;

    StationWagon sw(power, seat, load);

    sw.Display();

    return 0;

}