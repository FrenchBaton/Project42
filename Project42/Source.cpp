#include<iostream>
using namespace std;

struct IWorker {
	virtual void Work() = 0;
	virtual int GetSalary() = 0;
	virtual void Print() = 0;
};


class Employee : public IWorker
{
protected:
	string name;
	int workYears;
	int salary;
	int allSalary;
public:
	Employee(string n, int y, int s) : workYears(y), name(n), salary(s), allSalary(0){}
	Employee(string n, int y, int s, int as) : workYears(y), name(n), salary(s){}
	void Print() { cout << "Name: " << name << "\nWork years: " << workYears << "\n-----------\n"; }
};

class Programmer: public Employee
{
public:
	Programmer(string n, int y, int s) : Employee(n, y,s) {}
	Programmer(string n, int y, int s, int as) : Employee(n, y, s,as) {}
	virtual void Work() { cout << "I am starting to program. Add to salary " << salary << endl; allSalary += salary;}
	virtual int GetSalary() { return allSalary; }
};

class Designer : public Employee
{
public:
	Designer(string n, int y, int s) : Employee(n, y, s) {}
	Designer(string n, int y, int s, int as) : Employee(n, y, s, as) {}
	virtual void Work() { cout << "I am starting to draw. Add to salary " << salary << endl; allSalary += salary; }
	virtual int GetSalary() { return allSalary; }
};

class Manager : public Employee
{
public:
	Manager(string n, int y, int s) : Employee(n, y,s) {}
	Manager(string n, int y, int s, int as) : Employee(n, y, s,as) {}
	virtual void Work() { cout << "I am start to calculate. Add to salary " << salary << endl;allSalary += salary; }
	virtual int GetSalary() { return allSalary; }
};



int CalcSalary(IWorker**ptr, int size) {
	int rez = 0;
	for (int i = 0; i < size; i++) {
		rez += ptr[i]->GetSalary();
	}
	return rez;
}


int main() {
	IWorker* w[3];

	w[0] = new Programmer("PR", 2, 1000);
	w[1] = new Designer("DS", 6, 5000);
	w[2] = new Manager("MN", 3, 2000);

	for (int i = 0; i < 3; i++) {
		w[i]->Print();
	}
	cout << endl;

	for (int i = 0; i < 3; i++) {
		w[i]->Work();
	}
	cout << endl;

	cout << "Total salary: " << CalcSalary(w, 3) << endl;

	for (int i = 0; i < 3; i++) {
		delete w[i];
	}

	return 0;
}