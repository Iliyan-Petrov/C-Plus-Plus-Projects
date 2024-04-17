
//Obrabotka na Izklucheniq Exceptions C++

#include <iostream>
#include <exception>
#include <typeinfo>
#include "Header.h"

using namespace std;



int main ()
{try {CheckedArray<double>test1(100);
test1[25]=3.14;
}

catch (exception& e)
{cout<<"Exc:" <<e.what();}
system("pause");
return 0;
}