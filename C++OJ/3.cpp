#include <iostream>
using namespace std;

//��֪��Automobille��������Car���Wagon�࣬�������߹�ͬ������StationWagon�࣬����Ķ��弰main�еĴ��루������Ķ������£���ʵ�ָ�����ĳ�Ա�����������Ӧ�������
/*��������
108 3 10
�������
StationWagon:
Power:108
Seat:3
Load:10*/
class Automobile              //������

{

private:

    int power;   //����

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
class Car :virtual  public Automobile   //С�ͳ���

{

private:

    int seat;     //��λ

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

class Wagon :virtual  public Automobile //С������
{
private:
    int load;     //װ����
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

class StationWagon :public Car, public Wagon  //�ͻ����ó���

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