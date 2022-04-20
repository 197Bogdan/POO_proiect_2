#include <string>
#include <iostream>
#include "common.h"



Person::Person()
{
	name = "None";
	birth_year = 0;
	gender = "None";
}

Person::Person(std::string name, int year, std::string gender)
{
	this->name = name;
	this->birth_year = year;
	this->gender = gender;
}
Person::Person(const Person& person)
{
	name = person.name;
	birth_year = person.birth_year;
	gender = person.gender;
}
Person::~Person()
{
	std::cout << "Persoana a fost stearsa." << std::endl;
}
void Person::SetBirthYear(int birth_year)
{
	this->birth_year = birth_year;
}
int Person::GetBirthYear() const
{
	return birth_year;
}
void Person::SetName(std::string name)
{
	this->name = name;
}
std::string Person::GetName() const
{
	return name;
}
void Person::SetGender(std::string gender)
{
	this->gender = gender;
}
std::string Person::GetGender() const
{
	return gender;
}

bool Person::operator==(Person& person)
{
	if (this->name == person.name && this->birth_year == person.birth_year && this->gender == person.gender)
		return true;
	return false;
}

bool Person::operator!=(Person& person)
{
	return !(*this == person);
}

void Person::operator=(const Person& person)
{
	name = person.name;
	birth_year = person.birth_year;
	gender = person.gender;
}

void Person::Read(std::istream& in)
{
	std::cout << "Introduceti numele, data nasterii si genul, separate prin spatiu." << std::endl;
	std::string name, gender;
	int year;
	in >> name;
	in >> year;
	in >> gender;
	SetName(name);
	SetBirthYear(year);
	SetGender(gender);
}
void Person::Print(std::ostream& out)
{
	out << GetName() << ", " << GetBirthYear() << ", " << GetGender() << std::endl;
}

std::istream& operator>>(std::istream& in, Person& person)
{
	person.Read(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, Person& person)
{
	person.Print(out);
	return out;
}



Building::Building()
{
	name = "None";
	address = "None";
	surface = 0;
	floors_number = 0;
}
Building::Building(std::string name, std::string address, int surface, int floors_number)
{
	this->name = name;
	this->address = address;
	this->surface = surface;
	this->floors_number = floors_number;
}
Building::Building(const Building& building)
{
	name = building.name;
	address = building.address;
	surface = building.surface;
	floors_number = building.floors_number;
}
Building::~Building()
{
	std::cout << "Cladirea a fost stearsa." << std::endl;
}

void Building::SetSurface(int surface)
{
	this->surface = surface;
}
int Building::GetSurface() const
{
	return surface;
}
void Building::SetAddress(std::string address)
{
	this->address = address;
}
std::string Building::GetAddress() const
{
	return address;
}
void Building::SetName(std::string name)
{
	this->name = name;
}
std::string Building::GetName() const
{
	return name;
}
void Building::SetFloorsNumber(int floors)
{
	floors_number = floors;
}
int Building::GetFloorsNumber() const
{
	return floors_number;
}

void Building::Read(std::istream& in)
{
	std::cout << "Introduceti numele, adresa si suprafata, separate prin spatii." << std::endl;
	std::string name, address;
	int surface;
	in >> name;
	in >> address;
	in >> surface;
	SetName(name);
	SetAddress(address);
	SetSurface(surface);
}
void Building::Print(std::ostream& out)
{
	out << GetName() << ", " << GetAddress() << ", " << GetSurface() << std::endl;
}

std::istream& operator>>(std::istream& in, Building& building)
{
	building.Read(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, Building& building)
{
	building.Print(out);
	return out;
}

void Building::operator=(const Building& building)
{
	name = building.name;
	address = building.address;
	surface = building.surface;
}