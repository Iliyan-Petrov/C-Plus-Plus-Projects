#include <iostream>
#include <string>
using namespace std;

enum Gender { male, female, other };

class Person
{
public:
	string name;
	string egn;
	Gender pol;

public:
	Person()
	{
		name = " ";
		egn = " ";
		pol = other;
	}

	Person(string name1, string egn1)
	{
		name1 = name;
		egn1 = egn;
	}
	Person(const Person& p)
	{
		pol=p.pol;
		name = p.name;
		egn = p.egn;
	}

	void getYMD(const string& egn, int& year, int& month, int& day)
	{}


	friend istream& operator>> (istream& istr, Person& p)
	{
		istr >> p.name >> p.egn;
		return istr;
	}

	friend ostream& operator<< (ostream& ostr, Person& p)
	{
		ostr << p.name << " " << p.egn << " " << p.pol;
		return ostr;
	}
};

class Address
{
protected:
	string street;
	int post_code;
	string city;

public:
	Address()
	{
		street = " ";
		post_code = 0;
		city = " ";
	}

	Address(string street1, int post_code1, string city1)
	{
		street = street1; post_code = post_code1; city = city1;
	}

	Address(const Address& p)
	{
		street = p.street; post_code = p.post_code; city = p.city;
	}

	friend istream& operator>> (istream& istr, Address& p)
	{
		istr >> p.street >> p.post_code >> p.city;
		return istr;
	}

	friend ostream& operator<< (ostream& ostr, Address& p)
	{
		ostr << p.street << " " << p.post_code << " " << p.city;
		return ostr;
	}
};


class GSM
{
public:
	string model;
	int data_plan;

public:

	GSM()
	{
		string model = " ";
		int data_plan = 0;
	}
	GSM(string model_a, int data)
	{
		model = model_a;
		data_plan = data;
	}

	virtual ostream& OutputGSM(ostream& toStream, GSM& p) const = 0;
	virtual string getGSMNumber()const = 0;
	virtual istream& InputGSM(istream& fromStream, GSM& p) = 0;

};
class Student : public Person
{
public:
	string fn;
	Address adr;
	int age;

public:
	Student()
	{
		fn = " ";
		age = 0;
	}

	Student(string name, Address address, string egn, int age1) : Person(name, egn)
	{
		address = adr; age1 = age;
	}

	Student(string name, Address address, string egn, string fn1, int age1) : Person(name, egn)
	{
		address = adr; age1 = age; fn = fn1;
	}

	Student(const Student& p)
	{
		name = p.name;
		adr = p.adr;
		egn = p.egn;
		fn = p.fn;
		age = p.age;
	}
	virtual istream& InputGSM(istream& fromStream, GSM& p)
	{
		fromStream >> p.model >> p.data_plan;
		return fromStream;
	}

	virtual ostream& OutputGSM(ostream& toStream, GSM& p)
	{
		toStream << p.model <<" "<< p.data_plan;
		return toStream;
	}

	friend istream& operator>> (istream& istr, Student& p)
	{
		istr >> p.name >> p.adr >> p.egn>> p.fn >> p.age;
		return istr;
	}

	friend ostream& operator<< (ostream& ostr, Student& p)
	{
		ostr << p.name << " " << p.adr << " " << p.age << " " << p.egn << " " << p.fn;
		return ostr;
	}

	void print()
	{
		cout << "name = " << name << endl;
		cout << "adr = " << adr << endl;
		cout << "egn = " << egn << endl;
		cout << "fn= " << fn << endl;
		cout << "age= " << age << endl;
	}

	void set_name(string name1)
	{
		name = name1;
	}

	void set_adr(Address adr1)
	{
		adr = adr1;
	}

	void set_egn(string egn1)
	{
		egn = egn1;
	}

	void set_fn(string fn1)
	{
		fn = fn1;
	}

	void set_age(int age1)
	{
		age = age1;
	}


	void get_name()
	{
		cout << name;
	}

	void get_adr()
	{
		cout << adr;
	}

	void get_egn()
	{
		cout << egn;
	}

	void get_fn()
	{
		cout << adr;
	}

	void get_age()
	{
		cout << age;
	}

	bool operator==(Student& p)
	{
		if (this->age == p.age)return true;
		return false;
	}

	bool operator!=(Student& p)
	{
		if (this->age != p.age)return true;
		return false;
	}
	bool operator<(Student& p)
	{
		if (this->age < p.age)return true;
		return false;
	}
	bool operator>=(Student& p)
	{
		if (this->age >= p.age)return true;
		return false;
	}
};

int main()
{
	Address adr_steven("Apple Street", 123, "Varna");
	Address adr_george("Palm Lane", 345, "Burgas");
	Address adr_shelly("Palm Springs", 789, "California");
	Student s1;
    s1.set_name("Steven");s1.set_adr(adr_steven); s1.set_egn("0968754343"); s1.set_age(18); s1.set_fn("19674563");
	s1.print();

	Student s2;
	s2.set_name("George"); s2.set_adr(adr_george); s1.set_egn("0963433907"); s1.set_age(19); s1.set_fn("19672346");
	s2.print();

	if (s1.age < s2.age)
	{cout << "s2 is older than s1 " << endl;}
	else
	{cout << "s1 is older than s2 " << endl;}

	if (s1.age != s2.age)
	{cout << "s1. age != s2.age" << endl;}
	else
	{cout << "s1. age == s2.age" << endl;}


	if (s1.age == s2.age)
	{cout << "s1. age == s2.age" << endl;}
	else
	{cout << "s1. age != s2.age" << endl;}


	if (s1.age >= s2.age)
	{cout << "s1. age >= s2.age" << endl;}
	else
	{cout << "s1. age <= s2.age" << endl;}

	Student s3;
	cin >> s3.egn;
	s3.set_name("Shelly"); s3.set_adr(adr_shelly); s3.set_age(20); s3.set_fn("19676675");
	s3.print();

	system("pause");
	return 0;
}