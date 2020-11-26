#include <iostream>;

using namespace std;

class carriage
{
public:
protected:
};

class PassengerCarriage : carriage
{
public:
protected:
	int _passengers;
};

class CargoCarriage : carriage
{
public:
protected:
	int _wood;
	int _coal;
	int _sand;
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
};


int main()
{

	return 0;
}