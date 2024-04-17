#include <iostream>
#include <math.h>
using namespace std;

class Point
{protected: int x,y;
public: 

double dist()
{ return sqrt(x*x + y*y);}

Point() //default
{x=y=0;}
Point (int x1, int y1) //explicit
{x=x1; y=y1;}

//copy
Point (const Point& p)
{x=p.x; y=p.y;}

void print()
{
	cout<<"x= "<<x<<endl;
	cout<<"y= "<<y<<endl;
}
void setx(int x1)
{x=x1;}

void sety(int y1)
{y=y1;}

int getx()
{return x;}

int gety()
{return y;}
};//endl

class Circle: public Point
{ protected: int r;

public:
	Circle() //default
	{r=0;}

	Circle (int a, int b, int c):Point(a,b) //explicit
	{r=c;}

	Circle (const Circle& c)
	{x=c.x; y=c.y; r=c.r;}

	void setr(int r1)
	{r=r1;}

	int getr()
	{return r;}

	void print() 
	{Point:: print();
	cout<<"r= "<<r<<endl;}

	double lice()
	{return  3.1415*r*r;}

	double perim()
	{return 2*3.1415*r;}
};

class Conus : public Circle
{ protected: int h;

public:
	Conus()//default
	{h = 0;}

	Conus (int a, int b, int c, int d): Circle(a,b, c)
	{h = d;}

	Conus(const Conus& d)
	{x = d.x; y = d.y; r = d.r; h = d.h;}

	void seth(int h1)
	{h = h1;}

	int geth()
	{return h;}

	void print()
	{Circle::print();
	cout << "h= " << h << endl;}

	double volume()
	{return (3.1415 * r * r * h) / 3;}

	friend istream& operator>> (istream& istr, Conus& p)
	{
		istr >> p.x >> p.y >> p.r >> p.h;
		return istr;
	}

	friend ostream& operator<< (ostream& ostr, Conus& p)
	{
		ostr << p.x <<" "<< p.y <<" "<< p.r <<" "<< p.h;
		return ostr;
	}

	bool operator<(Conus& h)
	{
		if (this->volume() < h.volume()) return true;
		return false;
	}
};

int main()
{
	Point p1;//def. constr
	p1.print(); p1.setx(2); p1.sety(4);
	p1.print();

	Point p2(5, 6); p2.print(); //explicit
	Point p3(p2); //copy
	p3.print();

	cout << "Dist p1= " << p1.dist() << endl;

	Circle c1(3, 4, 6);
	c1.print();
	cout << "S= " << c1.lice() << endl;
	cout << "L= " << c1.perim() << endl;

	Circle c2(c1);
	c2.print();
	cout << "S= " << c1.lice() << endl;
	cout << "L= " << c1.perim() << endl;

	Conus h1(2, 3, 4, 7);
	h1.print();
	cout << "V= " << h1.volume() << endl;

	Conus h2(3, 4, 6, 8);
	h2.print();
	cout << "V= " << h2.volume() << endl;


	if (h1.volume() < h2.volume())
		cout << "h1.volume < h2.volume \n";
	else cout << "h1.volume > h2.volume \n";


	cin >> h1;
	cout << h1;

	system("pause");
	return 0;
}