#include <iostream>;
#include <cstring>;
#include <typeinfo>;

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

	virtual void cloading(const int& value) = 0;

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

	void cloading(const int& value) override
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

	void cloading(const int& value) override
	{
		_cargo._number = value;
	}

protected:
	cargo _cargo;
};



class train
{
public:
	virtual int tloading(const int& value) = 0;
protected:
};

class PasTrain : train
{
public:
	PasTrain()
	{
		_carriages = new PassengerCarriage[20];
	}

	int tloading(const int& value) override
	{
		int t = value;
		for (int i = 0; i < 20; i++)
		{			
			if (t >= 0 || t < 50)
				_carriages[i].cloading(t);
			else if (t >= 50)
			{
				t -= 50;
				_carriages[i].cloading(50);
			}
		}
		return t;
	}

protected:
	PassengerCarriage* _carriages;
};

class CarTrain : train
{
public:
	CarTrain()
	{
		_carriages = new CargoCarriage[20];
	}

	int tloading(const int& value) override
	{
		int t = value;
		for (int i = 0; i < 20; i++)
		{
			if (t >= 0 || t < 50)
				_carriages[i].cloading(t);
			else if (t >= 50)
			{
				t -= 50;
				_carriages[i].cloading(50);
			}
		}
		return t;
	}

protected:
	CargoCarriage* _carriages;
};

class PasCarTrain : train
{
public:
	PasCarTrain()
	{
		_carriages1 = new CargoCarriage[10];
		_carriages2 = new PassengerCarriage[10];
	}

	int tloading(const int& cargo) override
	{
		int t = cargo;
		for (int i = 0; i < 20; i++)
		{
			if (t >= 0 || t < 50)
				_carriages1[i].cloading(t);
			else if (t >= 50)
			{
				t -= 50;
				_carriages1[i].cloading(50);
			}
		}
		return t;
	}

	int addloading(const int& passengers)
	{
		int t = passengers;
		for (int i = 0; i < 20; i++)
		{
			if (t >= 0 || t < 50)
				_carriages2[i].cloading(t);
			else if (t >= 50)
			{
				t -= 50;
				_carriages2[i].cloading(50);
			}
		}
		return t;
	}

protected:
	CargoCarriage* _carriages1;
	PassengerCarriage* _carriages2;
};



class station
{
public:
protected:
	int _passengers;
	int _wood;
	int _coal;
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