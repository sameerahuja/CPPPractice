#include "stdafx.h"
#include "OperatorOverLoading.h"
#include<iostream>

std::string trim_right_copy(
	const std::string& s,
	const std::string& delimiters = " \f\n\r\t\v")
{
	size_t sz = s.find_last_not_of(delimiters);
	return s.substr(0, sz + 1);
}

std::string trim_left_copy(
	const std::string& s,
	const std::string& delimiters = " \f\n\r\t\v")
{
	size_t sz = s.find_first_not_of(delimiters);
	return s.substr(0,sz);
}

std::string trim_copy(
	const std::string& s,
	const std::string& delimiters = " \f\n\r\t\v")
{
	return trim_left_copy(trim_right_copy(s, delimiters), delimiters);
}

void StudentManager::addStudent(Student &student)
{
	std::string id = trim_copy(student.getId());
	if (id.empty())
	{
		std::cout << "Can't add a student with no id\n";
		return;
	}
	auto it = students.find(student.getId());

	if (it == students.end())
		students.insert(make_pair(student.getId(), student));

}

void StudentManager::deleteStudent(std::string id)
{
	std::cout << "About to delete student with id: " << id <<std::endl;
	std::cout << "Size of students list before deletion = " << students.size() << std::endl;

	auto it = students.find(id);

	if (it != students.end())
	{
		students.erase(id);
		std::cout << "Size of students list after deletion = " << students.size() << std::endl;
	}
	else
		std::cout << "Student with id = " << id << " not found" << std::endl;
}

void StudentManager::printList()
{
	auto it = students.begin();

	std::cout << "-------List of Students--------" << std::endl;
	while (it != students.end())
	{
		std::cout << it->second;
		it++;
	}
}