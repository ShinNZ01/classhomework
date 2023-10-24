#include "1019.h"
#include <iostream>
using namespace std;

Student::Student() //建構子
{
	ID = 0;
	name = NULL;
}

Student::Student(int stud_id, const char* stud_name) //建構子
{
	ID = stud_id;
	name = new char[10];
	std::strcpy(name, stud_name);
}

int Student::SetID(int stud_id)
{
	ID = stud_id;
	return 1;
}

int Student::SetName(const char* stud_name)
{
	name = new char[10];
	std::strcpy(name, stud_name);
	return 1;
}

int Student::GetID()
{
	return ID;
}

char* Student::GetName()
{
	return name;
}


void Student::Print() 
{
	cout << "student's id is:" << ID << endl;
	cout << "student's name is:" << name << endl;
}





