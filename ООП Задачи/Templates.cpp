#include <iostream>
#include <string>
using namespace std;


template<class T>
T getMax(T a, T b)
{if (a>b)return a;
return b;}

template <class T>
T maxArr (T mas[], int n)
{T max=mas[0];
for(int i=1; i<n; i++)
{if(mas[i]>max)
{max=mas[i];}
}
return max;
}

template <class L, class R>
class Dvoika
{ L a;
  R b;

public:
	Dvoika ()
	{}

	Dvoika(L a1, R b1)
	{a=a1;b=b1;}

	void seta (L a1)
	{a1 = a;}
	void setb (R b1)
	{b1 = b;}

	int geta ()
	{return L a;}

	int getb ()
	{return R b;}

	friend ostream& operator<< (ostream& ostr, Dvoika& d)
	{
		ostr<<d.a<<" "<<d.b;
		return ostr;
	}

	bool operator > (Dvoika <L, R>& d)
	{if(b>d.b) return true;
	return false;}
};

int main()
{double a=5.3, b=6.7;
cout<<"Max int: "<<getMax<int>(5,8)<<endl;
cout<<"Max dbl: "<<getMax<double>(a,b)<<endl;
cout<<"Max str: "<<getMax<string>("abc", "pqr")<<endl;

double m[4] = {2.5, 7.8, 3.6, 5.9};

cout<<"Max arr: "<<maxArr<double>(m,4);
cout<< endl;

Dvoika <string, double> p1("Lemon", 3.6), p2("Kiwi", 4.2);

if(p1 > p2)
{cout<<p1.getb()<<" is greater than "<< p2.getb();}
else
{cout<<p2.getb()<<" is greater than "<< p1.getb();}
system("pause");
return 0;
}