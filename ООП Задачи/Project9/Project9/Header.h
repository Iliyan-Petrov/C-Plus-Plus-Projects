#define CHECKEDARRAY_H
#define CHECKEDARRAY_H
#include <stdexcept>
template<class T>
class CheckedArray 
{private:int size; 
T* a; 
public:

CheckedArray<T>(int max) 
{size = max;a = new T[size];}
T& CheckedArray<T>::operator[](int index) 
{if (index < 0 || index >= size) 
{throw out_of_range("CheckedArray");}
return a[index];
  }
};