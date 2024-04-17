#include <iostream>
using namespace std;
class Rect 
{ private: int a,b;

public:
	void init(int s1, int s2)
{
	    a=s1;
	    b=s2;
}

void print()
	{
		cout<<"a= " << a << endl;
		cout<<"b= " << b << endl;
	}
bool IsSquare ()
	{ 
		if(a==b) return true;
	return false;
	}
 void seta(int s1)
{a=s1;}

void setb(int s2)
{b=s2;}

int geta()
{return a;}

int getb()
{return b;}

int area()
{return a*b;}

int perim()
{return 2*a+2*b;}

//default constr
Rect()
{a=b=0;}
//explicit - с параметър
Rect(int s1, int s2)
{a=s1;b=s2;}
//copy constr
Rect (const Rect &r)
{a=r.a; b=r.b;}

~Rect() //нищо не се пише защото деструктора вече знае къде се намират данните 
{ }

/*

ако в private променливите са с указатели, трябва в деструктора да се пише delete и променливата
*/
};





int main()
{
	Rect r1, r2;
	r1.init(3,4);
	r1.print();
	r2.init(6,8);
	r2.print();

	if(r1.IsSquare())
		cout<<"r1 is Square \n";
	else cout<<"r1 isn't \n";

	r1.seta(5);r1.setb(5);
	cout<<endl<<r1.geta()<<" "<<r1.getb()<<endl;

	cout<<"Area r1: "<<r1.area() << endl;

	Rect r3(5,8); //explicit
	r3.print();
	Rect r4(r2);//copy
	r4.print();

	cout<<endl;
	cout<<"Array: ";
	cout<< endl;
	Rect m[5]={r1, r2, r3, Rect(5,6), Rect (3,3)};
	
	for (int i=0; i<5; i++)
	{
		m[i].print();
	}

system("pause");
	return 0;
}







