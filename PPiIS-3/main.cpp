#include <iostream>;
#include <cstring>;

using namespace std;


struct passenger
{
	int _number;

	passenger() : 
		_number(0)
	{}

	passenger(int number) :
		_number(number)
	{}

	const passenger& operator+=(const passenger& r)
	{
		return
			passenger(this->_number + r._number);
	}
};

struct cargo
{
	int _number;

	cargo() :
		_number(0)
	{}

	cargo(const int number) :
		_number(number)
	{}
};



class carriage
{
public:
protected:
};

class PassengerCarriage : carriage
{
public:
protected:
	passenger _passengers;
};

class CargoCarriage : carriage
{
public:
protected:
	cargo _cargo;
};

class train
{
public:
protected:
	carriage _carriages[20];
};

class station
{
public:
protected:
	int _passengers;
	int _wood;
	int _coal;
	int _sand;
};


class railway
{
public:
protected:
	station _from;
	station _to;
	int _lenght;
};


int main()
{

	return 0;
}