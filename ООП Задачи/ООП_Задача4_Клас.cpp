#include <iostream>
#include <math.h>
using namespace std;

class Point
{private: int x,y;
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


int main ()
{Point p1;//def. constr
p1.print();p1.setx(2);p1.sety(4);
p1.print();

Point p2 (5,6); p2.print(); //explicit
Point p3 (p2); //copy
p3.print();

cout<<"Dist p1= "<<p1.dist()<<endl;
	
system("pause");
return 0;
}