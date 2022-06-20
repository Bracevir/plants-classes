#include<iostream>
#include <string>
using namespace std;

class Plants {
public:
	static int fruit_;
	static int berries_;
	Plants() { // счётчик растений
		count_++;
	}
	Plants(string name, int value) :Plants() {
		name_ = name;
		fruit_ += value;
	}
	virtual~Plants() {
		count_--;
	}
	void set_name(string name) { //сеттер
		this->name_ = name;
	}
	string get_name() { //геттер
		return name_;
	}
	static int get_count() {
		return count_;
	}
	static int get_fruits() {
		return fruit_;
	}
	static int get_berries() {
		return berries_;
	}
private:
	//static int fruit_;
	//static int berries_;
	string name_;
	static int count_;
};

class Tree :public Plants {  //наследование дерева
public:
	Tree() {}
	Tree(string name, int value) : Plants(name, value) {}
	virtual~Tree() {}
};

class Bushes: public Plants { //наследование куста
public:
	Bushes() {}
	Bushes(string name, int value) {
		Plants::set_name(name);
		Plants::berries_ += value;
	}
	virtual~Bushes() {}
};

class Fetus { // базовый класс плодов
public:
	Fetus() {}
	virtual~Fetus() {}
	static int all_fetus() {
		return Plants::fruit_ + Plants::berries_;
	}

};

class Fruits :public Fetus { //наследование фруктов
public:

	Fruits() {}

	virtual~Fruits() {}
	static int fetus_picking(int fetus) {
		Plants::fruit_ -= fetus;
		return Plants::fruit_;
	}
};

class Berries :public Fetus { //наследование ягод
public:
	Berries() {}
	virtual~Berries() {}
	static int fetus_picking(int fetus) {
		Plants::berries_ -= fetus;
		return Plants::berries_;
	}

};
//int Plants::fruit_ = 0;
//int Plants::count_ = 0;
//int Plants::berries_ = 0;


int main() {
	system("chcp 1251>nul");
	Tree tree1("Яблоня", 50);
	Tree tree2("Груша", 50);
	Bushes bush1("Жимолость", 4000);
	Bushes bush2("Клубника", 150);


	cout << "Количество растений: " << Plants::get_count() << endl;
	cout << "Количестов всего фруктов: " << Plants::fruit_ << endl;
	cout << "Количество всего ягод: " << Plants::berries_ << endl;
	int n = 10;
	cout << "Осталось фруктов, когда собрали " << n << " штук =  " << Fruits::fetus_picking(n) << endl;
	cout << "Осталось ягод, когда собрали " << n << " штук =  " << Berries::fetus_picking(n) << endl;
	cout << "Общее количество плодов = " << Fetus::all_fetus() << " шт " << endl;


	system("pause>nul");
	return 0;
}