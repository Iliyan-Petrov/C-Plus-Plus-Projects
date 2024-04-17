#include <iostream>
#include <fstream>
using namespace std;

class Point
{
private:
	int x,y;
	char name;
	static int br;

public:
	Point()
	{x=0; y=0;
	br++;
	name = 64 + br;}

	Point (int x1, int y1)
	{
	x=x1;
	y=y1;
	br++;
	name= 64 + br;
	}

	Point (const Point& p)
	{x=p.x;
	y=p.y;
	name=p.name;
	br++;
	}

	~Point()
	{br--;}
	static void printbr()
	{cout<<"Br= "<<br<<endl;}

	void print()
	{cout<<name<<'('<<x<<','<<y<<')'<<endl;}

	static int InQuadrant (Point& p)
	{
		if((p.x<0)&&(p.y>0))
		{return 1;}
		else if((p.x>0)&&(p.y>0))
		{return 2;}
		else if((p.x>0)&&(p.y<0))
		{return 3;}
		else if((p.x<0)&&(p.y<0))
		{return 4;}

		else
		{return 0;}
	}

	friend istream& operator>>(istream& istr, Point& p)
	{istr>>p.name>>p.x>>p.y;
	return istr;}

	friend ostream& operator<<(ostream& ostr, Point& p)
	{ostr<<p.name<<" "<<p.x<<" "<<p.y;
	return ostr;}
};

int Point:: br=0;

int main()
{Point p1(3,4), p2(6,8);

p1.print();p2.print();
Point::printbr();

cout<<"Quadr(p1): "<< Point::InQuadrant(p1)<<endl;
Point p3;
cin>>p3;
cout<<p3;

Point arr[4]={p1,p2,p3, Point(6,7)};

	cout<<"\n Array: "<<endl;
for (int i=0;i<4;i++)
{
	arr[i].print();
}

ofstream ofile("points.txt");
for (int i=0; i<4;i++)
{
	cout<<arr[i];ofile<<arr[i];
}
ofile.close();

Point p, arr2[4]; int i=0;
ifstream ifile("point.txt");
while(!ifile.eof())
{
	ifile>>p; if (ifile.peek()>-1)
	{cout<<p;
	arr2[i]=p; i++;
	}
}

system("pause");
return 0;}