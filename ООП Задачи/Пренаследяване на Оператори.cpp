#include <iostream>
#include <math.h>
using namespace std;

class Point
{protected: int x,y;
public: 

Point() //default
{x=y=0;}
Point (int x1, int y1) //explicit
{x=x1; y=y1;}

//copy
Point (const Point& p)
{x=p.x; y=p.y;}

double dist()
{ return sqrt(x*x + y*y);}

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

Point operator+(Point& p)
{Point res;
res.x=this->x+p.x;
res.y=this->y+p.y;
return res;
}

Point operator- (Point& p)
{return Point(this->x-p.x, y-p.y);}

bool operator==(Point& p)
{if(x==p.x && y==p.y) return true;
return false;}

bool operator<(Point& p)
{if (this-> dist()<p.dist()) return true; 
 return false;}

Point operator*(int n)
{return Point(x*n,y*n);}

Point& operator++ ()
{x++; y++;
return *this;} //референцията ( & ) остава след Point защото се връща *this

Point& operator= (Point& p)
{this->x=p.x;
 this->y=p.y;
 return *this;} //референцията ( & ) остава след Point защото се връща *this

friend istream& operator>>(istream& istr, Point& p)
{
	istr>>p.x>>p.y;
	return istr;
}

friend ostream& operator<<(ostream& ostr, Point& p)
{ostr<<p.x<<" "<<p.y<<endl;
return ostr;}

};

int main() 
{Point p1(3,4), p2(5,6),p3;
p3= p1 + p2;
p3.print();

p3= p1-p2;
p3.print();

if(p1==p2)
	cout<<"p1 == p2 \n";
else cout << "p1!=p2 \n";

if (p1<p2)
	cout <<"p1 < p2 \n";
else cout << "p1 > p2 \n";

p3=p2; p3.print();
++p3; p3.print();

p3=p1*12;
p3.print();

cin>>p3;
cout<<p3;

system("pause");
return 0;
}

