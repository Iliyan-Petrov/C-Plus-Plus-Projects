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
		//pol
	}
	Person(const Person& p)
	{
		pol = p.pol;
		name = p.name;
		egn = p.egn;
	}

	void getYMD(int& year, int& month, int& day)
	{
		year = (int)(egn[0]) * 10 + (int)(egn[1]);
		month = (int)(egn[2]) * 10 + (int)(egn[3]);
		day = (int)(egn[4]) * 10 + (int)(egn[5]);

		if (month >= 1 && month <= 12)
		{
			year += 1900;
		}

		if (month >= 21 && month <= 32)
		{
			year += 1800;
		}

		if (month >= 41 && month <= 52)
		{
			year += 2000;
		}
	}
	int age()
	{
		int y, m, d;
		getYMD(y, m, d);
		return 2020 - y;
	}
	friend istream& operator>> (istream& istr, Person& p)
	{
		string pp;
		istr >> p.name >> p.egn >> pp;
		if (pp == "Male")
		{p.pol = male;}

		else if (pp == "Female")
		{p.pol = female;}

		else
		{p.pol = other;}
		return istr;
	}

	friend ostream& operator<< (ostream& ostr, const Person& p)
	{
		ostr << p.name << " " << p.egn << " " << p.GenderToString();
		return ostr;
	}

	string GenderToString() const
	{
		if (pol == 0)
		{
			return "Male";
		}
		if (pol == 1)
		{
			return "Female";
		}
		if (pol == 2)
		{
			return "Other";
		}
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

	friend ostream& operator<< (ostream& ostr, const Address& p)
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
	string phone_number;

public:

	GSM()
	{
		model = " ";
		data_plan = 0;
		phone_number = " ";
	}
	GSM(string model_a, int data, string number)
	{
		model = model_a;
		data_plan = data;
		phone_number = number;
	}

	virtual ostream& OutputGSM(ostream& toStream, GSM& p) const = 0;
	virtual string getGSMNumber()const = 0;
	virtual istream& InputGSM(istream& fromStream, GSM& p) = 0;

};
class Student : public Person, public GSM
{
public:
	string fn;
	Address adr;

public:
	Student()
	{
		fn = " ";
	}
	Student(string name, Address address, string egn) : Person(name, egn)
	{
		address = adr;
	}
	Student(string name, Address address,string egn, string fn1, string model, int data_plan, string phone_number): Person(name, egn), GSM(model, data_plan, phone_number)
	{
		address = adr; fn = fn1;
	}
	Student(const Student& p)
	{
		name = p.name;
		adr = p.adr;
		egn = p.egn;
		fn = p.fn;
		//pol, model, data_plan, phone_number
	}
	istream& InputGSM(istream& fromStream, GSM& p)
	{
		fromStream >> model >> data_plan >> phone_number;
		return fromStream;
	}

	ostream& OutputGSM(ostream& toStream, GSM& p) const
	{
		toStream << p.model << " " << p.data_plan << " " << p.phone_number;
		return toStream;
	}
	virtual string getGSMNumber()const
	{
		return phone_number;
	}
	friend istream& operator>> (istream& istr, Student& p)
	{//pol
		istr >> p.name >> p.adr >> p.egn >> p.fn>>p.model>>p.data_plan>>p.phone_number;
		return istr;
	}

	friend ostream& operator<< (ostream& ostr, const Student& p)
	{//pol
		ostr << p.name << " " << p.adr << " " << p.egn << " " << p.fn<<" "<<p.model<<" "<<p.data_plan<<" "<<p.phone_number;
		return ostr;
	}

	void print()
	{//pol
		cout << "name = " << name << endl;
		cout << "adr = " << adr << endl;
		cout << "egn = " << egn << endl;
		cout << "fn= " << fn << endl;
		cout << "model = "<<model << endl;
		cout << "model = "<<data_plan << endl;
		cout << "phone number = "<<phone_number << endl;
	}
	//correct set and get and move them to appropriate class
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

	void set_model(string model1)
	{
		model = model1;
	}

	void set_fn(int data1)
	{
		data_plan = data1;
	}

	void set_phone_number(string number1)
	{
		phone_number = number1;
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

		void set_model()
	{
		cout<<model;
	}

	void set_fn()
	{
		cout<<data_plan;
	}

	string get_phone_number()
	{
		return phone_number;
	}


	friend bool operator==(Student& p, Student& p2)
	{
		if (p.age() == p2.age())return true;
		return false;
	}

	bool operator!=(Student& p)
	{
		if (this->age() != p.age())return true;
		return false;
	}
	bool operator<(Student& p)
	{
		if (this->age() < p.age())return true;
		return false;
	}
	bool operator>=(Student& p)
	{
		if (this->age() >= p.age())return true;
		return false;
	}
	bool operator==(Student& p)
	{
		if (this->age() == p.age())return true;
		return false;
	}


	friend bool operator>(Student& p, Student& p2)
	{
		if (p.data_plan > p2.data_plan)return true;
		return false;
	}
};

int main()
{

	Address adr_steven("Apple Street", 123, "Varna");
	Address adr_george("Palm Lane", 345, "Burgas");
	Address adr_shelly("Palm Springs", 789, "California");

	Student s1("Steven", adr_steven, "0968754343", "19674563", "Nokia", 40, "67845604");
	s1.print();

	Student s2("George", adr_george, "0963433907", "19672346", "Samsung", 35, "25255569");
	s2.print();

	if (s1.data_plan > s2.data_plan)
	{
		cout << "s1's data plan > s2's data plan " << endl;
	}
	else
	{
		cout << "s1's data plan < s2's data plan  " << endl;
	}


	if (s1 < s2)
	{
		cout << "s2 is older than s1 " << endl;
	}
	else
	{
		cout << "s1 is older than s2 " << endl;
	}

	if (s1.age() != s2.age())
	{
		cout << "s1. age != s2.age" << endl;
	}
	else
	{
		cout << "s1. age == s2.age" << endl;
	}


	if (s1.age() == s2.age())
	{
		cout << "s1. age == s2.age" << endl;
	}
	else
	{
		cout << "s1. age != s2.age" << endl;
	}


	if (s1.age() >= s2.age())
	{
		cout << "s1. age >= s2.age" << endl;
	}
	else
	{
		cout << "s1. age <= s2.age" << endl;
	}

	system("pause");
	return 0;
}