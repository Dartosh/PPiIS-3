#include <iostream>;
#include <cstring>;
#include <vector>;

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
	virtual int cunloading() = 0;

protected:

};

class PassengerCarriage : public carriage
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

	int cunloading() override
	{
		int t;
		t = _passengers._number;
		_passengers._number = 0;
		return t;
	}

protected:
	passenger _passengers;
};

class CargoCarriage : public carriage
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

	int cunloading() override
	{
		int t;
		t = _cargo._number;
		_cargo._number = 0;
		return t;
	}

protected:
	cargo _cargo;
};



class train
{
public:
	virtual void tloading(const int& value) = 0;
	virtual int tunloading() = 0;
protected:
};

class PasTrain : public train
{
public:
	PasTrain()
	{
		_carriages = new PassengerCarriage[20];
	}

	void tloading(const int& value) override
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
	}

	int tunloading() override
	{
		int t = 0;
		for (int i = 0; i < 20; i++)
		{
			t = _carriages[i].cunloading();
		}
		return t;
	}

protected:
	PassengerCarriage* _carriages;
};

class CarTrain : public train
{
public:
	CarTrain()
	{
		_carriages = new CargoCarriage[20];
	}

	void tloading(const int& value) override
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
	}

	int tunloading() override
	{
		int t = 0;
		for (int i = 0; i < 20; i++)
		{
			t = _carriages[i].cunloading();
		}
		return t;
	}

protected:
	CargoCarriage* _carriages;
};

/*
class PasCarTrain : public train
{
public:
	PasCarTrain()
	{
		_carriages1 = new CargoCarriage[10];
		_carriages2 = new PassengerCarriage[10];
	}
	void tloading(const int& cargo) override
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
	}
	int addtloading(const int& passengers)
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
	int tunloading() override
	{
		int t = 0;
		for (int i = 0; i < 20; i++)
		{
			t = _carriages1[i].cunloading();
		}
		return t;
	}
	int addtunloading()
	{
		int t = 0;
		for (int i = 0; i < 20; i++)
		{
			t = _carriages2[i].cunloading();
		}
		return t;
	}

protected:
	CargoCarriage* _carriages1;
	PassengerCarriage* _carriages2;
};
*/


class station
{
public:
	station()
	{
		_passengers = 3000;
		_cargo = 3000;
		_name = "Minsk";
		_quantity++;
	}

	station(const int cargo, const int passengers, const string name, const int quantity) :
		_cargo(cargo),
		_passengers(passengers),
		_name(name),
		_quantity(quantity)
	{	}

	virtual void loading(train& train, const int& cargo, const int& passengers)
	{
		if (cargo == 0 && passengers > 0)
		{
			if (passengers >= 400 && passengers <= _passengers)
			{
				train.tloading(400);
				_passengers -= 400;
			}
			else if (passengers >= _passengers && passengers <= 400)
			{
				train.tloading(_passengers);
				_passengers = 0;
			}
			else if (passengers <= _passengers && passengers <= 400)
			{
				train.tloading(passengers);
				_passengers -= passengers;
			}
		}
		else if (cargo > 0 && passengers == 0)
		{
			if (cargo >= 400 && cargo <= _cargo)
			{
				train.tloading(400);
				_cargo -= 400;
			}
			else if (cargo >= _cargo && cargo <= 400)
			{
				train.tloading(_cargo);
				_cargo = 0;
			}
			else if (cargo <= _cargo && cargo <= 400)
			{
				train.tloading(cargo);
				_cargo -= cargo;
			}
		}
		else if (cargo > 0 && passengers > 0)
			cout << "\nChoose only one!";
		/*
		else if (cargo > 0 && passengers > 0)
		{
			if (cargo >= 200 && cargo <= _cargo && passengers >= 200 && passengers <= _passengers)
			{
				train.tloading(200);
				_cargo -= 200;
			}
			else if (cargo >= _cargo && cargo <= 200 && passengers <= 200 && passengers >= _passengers)
			{
				train.tloading(_cargo);
				_cargo = 0;
			}
			else if (cargo <= _cargo && cargo <= 200 && passengers <= 200 && passengers <= _passengers)
			{
				train.tloading(cargo);
				_cargo -= cargo;
			}
			else if (cargo <= _cargo && cargo <= 200 && passengers <= 200 && passengers >= _passengers)
			{
				train.tloading(cargo);
				_cargo -= cargo;
			}
		}
		*/
	}

	virtual int unloading(train& train)
	{
		return train.tunloading();
	}

	virtual string GetNameOfStation()
	{
		return _name;
	}

	friend class map;
protected:
	int _quantity;
	string _name;
	int _passengers;
	int _cargo;
};

/*
class railway
{
public:
	railway() :
		_from("Minsk"),
		_to("Vitebsk"),
		_length(200)
	{	}
	railway(const string from, const string to, const int length) :
		_from(from),
		_to(to),
		_length(length)
	{	}

	friend class map;
protected:
	string _from;
	string _to;
	int _length;
};

class map
{
public:
	void CreateStation(const station& station)
	{
		_Stations.push_back(station);
	}
	void CreateRailway(const railway& railway)
	{
		_Railways.push_back(railway);
	}
	void FindAWay(string& from, const string& to)
	{
		vector<railway> way;
		int* buf = new int;
		string cur;
		cur = from;
		for (int i = 0; i < _Railways.size(); i++)
		{
			if(cur == _Railways[i]._from)
			{
				buf += _Railways[i]._length;
				way.push_back(_Railways[i]);
				cur = _Railways[i]._to;
			}
		}
	}
private:
	int _dimension;
	vector<station> _Stations;
	vector<railway> _Railways;
};
*/


class map
{
public:
	map() :
		_vertexes(0),
		_edges(0)
	{	}
	map(const int vertexes, const int edges) :
		_vertexes(vertexes),
		_edges(edges)
	{	}
	void CreateWays()
	{
		for (int i = 0; i < _edges; i++)
		{
			string from, to;
			int weight;

			int dispatch, arrival;

			cout << "Write dispatch station: ";
			cin >> from;
			for (int k = 0; k < _stations.size(); k++)
				if (from == _stations[k]->_name)
					dispatch = _stations[k]->_quantity;

			cout << "Write arrival station: ";
			cin >> to; 
			for (int k = 0; k < _stations.size(); k++)
				if (to == _stations[k]->_name)
					arrival = _stations[k]->_quantity;

			cout << "Write way length: ";
			cin >> weight;
		}
	}

	void CreateStations(const int numbers)
	{
		for (int i = 0; i < numbers; i++)
		{
			station* cur = new station;

			cout << "Write name of the station: ";
			cin >> cur->_name;

			cout << "\nWrite quantity of cargo: ";
			cin >> cur->_cargo;

			cout << "\nWrite quantity of passengers: ";
			cin >> cur->_passengers;

			cur->_quantity = i;

			_stations.push_back(cur);

			system("cls");
		}
	}
private:
	int _vertexes;
	int _edges;
	int _graph[30][30];
	vector<station*> _stations;
};


int main()
{
	return 0;
}