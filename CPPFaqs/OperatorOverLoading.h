#pragma once

#include<string>
#include<vector>
#include<utility>
#include<map>
#include<iostream>

enum class Subjects
{
	english,
	phycics,
	chemistry,
	maths,
	biology
};

class Student
{
	std::string name;
	std::string id;
	std::vector <std::pair<Subjects, short> > marks;

public:
	Student()
	{
		name = "";
		id = "";
	}
	Student(std::string studentName, std::string id) : name(studentName), id(id) {}

	std::string getName() { return name; }
	std::string getId() { return id; }
	std::vector<std::pair<Subjects, short> > getMarks() { return marks; }

	void setMarks() { }

	bool operator < (const Student& userObj) const
	{
		if (userObj.id < this->id)
			return true;
	}

	friend std::ostream & operator << (std::ostream &out, Student &student)
	{
		out << "ID: " << student.getId() << " Name: " << student.getName() << std::endl;
		return out;
	}

	friend std::istream & operator >> (std::istream &in, Student &student)
	{

		std::cout << "Enter id:" << std::endl;
		in >> student.id;
		std::cout << "Enter name:" << std::endl;
		in >> student.name;

		return in;
	}

};

class StudentManager
{
	std::map<std::string , Student> students;
public:
	void addStudent(Student &student);
	void deleteStudent(std::string id);
	void printList();
};