#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class car {
	string name;
	unsigned int year;
	double engine;
	short price;

public:
	car(string name, unsigned int year, double engine, short price)
		: name(name), year(year), engine(engine), price(price) {}

	friend ostream& operator<< (ostream& o, const car& car) {
		o << "Название - " << car.name << endl;
		o << "Год выпуска - " << car.year << endl;
		o << "Объём двигателя - " << car.engine << endl;
		o << "Цена - " << car.price << endl << endl;
		return o;
	}

	bool operator== (const string otherName) const {
		return (this->name == otherName);
	}

	bool operator== (const short otherPrice) const {
		return (this->price == otherPrice);
	}

	bool operator== (const double otherEngine_capacity) const {
		return (this->engine == otherEngine_capacity);
	}

	bool operator== (const unsigned int otherYear) {
		return (this->year == otherYear);
	}

	void operator[] (const car& c) const {
		cout << "Название - " << c.name << endl;
		cout << "Год выпуска - " << c.year << endl;
		cout << "Объём двигателя - " << c.engine << endl;
		cout << "Цена - " << c.price << endl << endl;
	}

	double get_price() const {
		return price;
	}

	unsigned int get_year() const {
		return year;
	}

	double get_engine_capacity() const {
		return engine;
	}

	string get_name() const {
		return name;
	}
};

class database {
	vector<car> cars{};

public:
	void AddCar() {
		string name;
		unsigned int year;
		double engine_capacity;
		short price;
		cout << "Введите название машины >> ";
		cin >> name;
		cout << "Введите год выпуска машины >> ";
		cin >> year;
		cout << "Введите объём двигателя машины >> ";
		cin >> engine_capacity;
		cout << "Введите цену машины >> ";
		cin >> price;

		car newCar(name, year, engine_capacity, price);
		cars.push_back(newCar);
		cout << "Машина успешно добавлена!" << endl;
		system("cls");
		interface();
		print();

	}

	void remove() {
		unsigned int index{};
		cout << "Введите номер, который хотите удалить из списка >> ";
		cin >> index;
		cars.erase(cars.begin() + index - 1);
		system("cls");
		interface();
	}

	void print() {
		for (auto c : cars)
			cout << c;
		system("pause");
		system("cls");
		interface();
	}

	void search_name() {
		int isFound = 0;
		string search{};
		cout << "Введите название для поиска >> ";
		cin >> search;
		for (auto& c : cars) {
			if (c.get_name() == search) {
				cout << c;
				++isFound;
			}
		}
		if (isFound == 0) {
			cout << "Not found" << endl;
		}
		system("pause");
		system("cls");
		interface();
	}

	void search_price() {
		int isFound = 0;
		double search{};
		cout << "Введите цену для поиска >> ";
		cin >> search;
		for (auto& c : cars) {
			if (c.get_price() == search) {
				cout << c;
				++isFound;
			}
		}
		if (isFound == 0) {
			cout << "Not found" << endl;
		}
		system("pause");
		system("cls");
		interface();
	}

	void search_engine_capacity() {
		int isFound = 0;
		double search{};
		cout << "Введите объём двигателя для поиска >> ";
		cin >> search;
		for (auto& c : cars) {
			if (c.get_engine_capacity() == search) {
				cout << c;
				++isFound;
			}
		}
		if (isFound == 0) {
			cout << "Not found" << endl;
		}
		system("pause");
		system("cls");
		interface();
	}

	void search_year() {
		int isFound = 0;
		unsigned int search{};
		cout << "Введите год выпуска для поиска >> ";
		cin >> search;
		for (auto& c : cars) {
			if (c.get_year() == search) {
				cout << c;
				++isFound;
			}
		}
		if (isFound == 0) {
			cout << "Not found" << endl;
		}
		system("pause");
		system("cls");
		interface();
	}

	void sort_price() {
		sort(cars.begin(), cars.end(), [](const car& a, const car& b) {
			return a.get_price() < b.get_price();
			});
		print();
		system("pause");
		system("cls");
		interface();
	}

	void sort_year() {
		sort(cars.begin(), cars.end(), [](const car& a, const car& b) {
			return a.get_year() < b.get_year();
			});
		print();
		system("pause");
		system("cls");
		interface();
	}

	void sort_engine_capacity() {
		sort(cars.begin(), cars.end(), [](const car& a, const car& b) {
			return a.get_engine_capacity() < b.get_engine_capacity();
			});
		print();
		system("pause");
		system("cls");
		interface();
	}

	void sort_name() {
		sort(cars.begin(), cars.end(), [](const car& a, const car& b) {
			return a.get_name() < b.get_name();
			});
		print();
		system("pause");
		system("cls");
		interface();
	}

	void interface() {

		unsigned int choice{};
		cout << "--------------- Меню базы ---------------" << endl;
		cout << "\t1. Добавить машину" << endl;
		cout << "\t2. Удалить машину " << endl;
		cout << "\t3. Вывод списка " << endl;
		cout << "\t4. Поиск по названию " << endl;
		cout << "\t5. Поиск по году выпуска" << endl;
		cout << "\t6. Поиск по объёму двигателя" << endl;
		cout << "\t7. Поиск по цене" << endl;
		cout << "\t8. Сортировка по названию" << endl;
		cout << "\t9. Сортировка по году выпуска" << endl;
		cout << "\t10. Сортировка по объёму двигателя" << endl;
		cout << "\t11. Сортировка по цене" << endl;
		cout << "\t0 для выхода" << endl;
		cout << "Ввод >> ";
		cin >> choice;
		switch (choice) {
		case 1:
		{
			system("cls");
			AddCar();
			break;
		}
		case 2:
		{
			system("cls");
			remove();
			break;
		}
		case 3:
		{
			system("cls");
			print();
			break;
		}
		case 4:
		{
			system("cls");
			search_name();
			break;
		}
		case 5:
		{
			system("cls");
			search_year();
			break;
		}
		case 6:
		{
			system("cls");
			search_engine_capacity();
			break;
		}
		case 7:
		{
			system("cls");
			search_price();
			break;
		}
		case 8:
		{
			system("cls");
			sort_name();
			break;
		}
		case 9:
		{
			system("cls");
			sort_year();
			break;
		}
		case 10:
		{
			system("cls");
			sort_engine_capacity();
			break;
		}
		case 11:
		{
			system("cls");
			sort_year();
			break;
		}
		case 0:
		{
			break;
		}
		}
	}

};

int main() {
	setlocale(LC_ALL, "rus");
	database db;
	db.interface();
	return 0;
}