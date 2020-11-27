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

	virtual void loading(const int& value) = 0;

protected:

};

class PassengerCarriage : carriage
{
public:

	PassengerCarriage()
	{
		_passengers._number = 0;
	}

	PassengerCarriage(const int number)
	{
		_passengers._number = number;
	}

	void loading(const int& value) override
	{
		_passengers._number = value;
	}

protected:
	passenger _passengers;
};

class CargoCarriage : carriage
{
public:

	CargoCarriage()
	{
		_cargo._number = 0;
	}

	CargoCarriage(const int number)
	{
		_cargo._number = number;
	}

	void loading(const int& value) override
	{
		_cargo._number = value;
	}

protected:
	cargo _cargo;
};



class train
{
public:
protected:
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