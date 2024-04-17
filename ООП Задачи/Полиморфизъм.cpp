#include <iostream>
using namespace std;

class Figure 
{protected:
int a,b;
public:

Figure ()
{a=b=0;}

Figure (int a1, int b1)
{a=a1; b=b1;}

void seta (int a1)
{a=a1;}

void setb (int b1)
{b=b1;}

int geta ()
{return a;}

int getb ()
{return b;}

virtual double lice()=0;
virtual double perim()=0;
virtual void Output (ostream& ostr)
{ostr<<a<<" "<<b<<endl;}

virtual bool operator<(Figure& f)
{return lice()<f.lice();}
};


class Rect: public Figure
{public:
double lice()
{return a*b;}
double perim()
{return 2*a + 2*b;}

Rect() {}
Rect(int a1, int b1):Figure(a1,b1)
{}

bool operator< (Figure& f)
{return lice() < f.lice();}
};

class Triangle: public Figure 
{ protected:
int c;

public:
	Triangle ()
	{c=0;}

	Triangle (int a, int b, int c1): Figure (a,b)
	{c1=c;}

	void setc(int c1)
	{c=c1;}

	int getc()
	{return c;}
	
double perim()
{return a + b + c;}

double lice()
{return a*b/c;}

};

int main ()
{
Rect r1(5,6);
r1.Output (cout);

Figure *mas[4];
mas[0]= new Rect (5,10);
mas[1]= new Triangle (3,4,5);
mas[2]= new Rect (4,6);
mas[3]= new Triangle (6,8,10);
for (int i=0; i<4; i++)
{mas[i] -> Output(cout);
cout<<"Lice =" << mas[i]->lice()<<endl;
cout<<"P= "<<mas[i] -> perim()<<endl;
}
Figure *max;
max=mas[0];
for (int i=0; i<4; i++)
{
if(*mas[0]<*mas[i])
{max=mas[i];}
}
max->Output(cout);

system("pause");
return 0;}