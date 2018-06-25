// CPPFaqs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include<vector>

#include"OperatorOverLoading.h"
using namespace std;

class MoveCtor
{
public:
	MoveCtor(){}
	MoveCtor(const MoveCtor& obj) 
	{ 
		cout << "In MoveCtor Copy constructor\n";
		data = obj.data;
	}
	MoveCtor(const MoveCtor&& obj)
	{
		cout << "In MoveCtor Move constructor\n";
		data = obj.data;
	}
private:
	int data;
};

class ExplicitConversion
{
public:
	explicit ExplicitConversion(int x) { cout << "In ExplicitConversion, x = " << x << endl; }
};

void DemoExplicitConversion(ExplicitConversion ec)
{
	cout << "Inside DemoExplicitConversion\n";
}

MoveCtor DemoMoveCtorInvocation( MoveCtor mc)
{
	cout << "Inside DemoMoveCtorInvocation" << endl;
	return mc;
}

int main()
{
	ExplicitConversion ex(25);
	
	// This is error as long as we use explicit keyword for ctor
	// DemoExplicitConversion(10);
	// DemoExplicitConversion('2');
	// ExplicitConversion ec1 = 5;
	// ExplicitConversion ec2 = '9';


	//map <ExplicitConversion, int > customMap;

	//customMap.insert(pair<ExplicitConversion, int>(ex, 5));
	//customMap.insert(pair<ExplicitConversion, int>(ex, 15));

	//cout << "customMap size = " << customMap.size();

	vector<int> v1 = {1,2,3,10,20,30,100,200,300,999};
	vector<int> v2;

	cout << "Size of v1 before move = " << v1.size() << endl;
	cout << "Capacity of v1 before move = " << v1.capacity() << endl;

	v2 = std::move(v1);

	cout << "Size of v2 after move = " << v2.size() << endl;
	cout << "Capacity of v2 after move = " << v2.capacity() << endl;

	cout << "Size of v1 after move = " << v1.size() << endl;
	cout << "Capacity of v1 after move = " << v1.capacity() << endl;

	MoveCtor obj1;
	MoveCtor obj2 = obj1;

	MoveCtor obj3 = DemoMoveCtorInvocation(obj2);

	StudentManager &studentManager = StudentManager();

	Student std1("Sameer", "SA123");

	studentManager.addStudent(std1);
	studentManager.printList();
	studentManager.deleteStudent(std1.getId());
	studentManager.printList();

	studentManager.addStudent(std1);
	Student std2, std3, std4, std5;
	cin >> std2;
	studentManager.addStudent(std2);
	cin >> std3;
	studentManager.addStudent(std3);
	cin >> std4;
	studentManager.addStudent(std4);
	cin >> std5;
	studentManager.addStudent(std5);

	studentManager.printList();
    return 0;
}

