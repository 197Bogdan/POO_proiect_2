#pragma once
#include <string>

class Person
{
public:
	Person();
	Person(std::string, int, std::string);
	Person(const Person&);
	virtual ~Person();

	void SetBirthYear(int);
	int GetBirthYear() const;
	void SetName(std::string);
	std::string GetName() const;
	void SetGender(std::string);
	std::string GetGender() const;

	virtual void Read(std::istream&) = 0;
	virtual void Print(std::ostream&);
	friend std::istream& operator>>(std::istream& i, Person&);
	friend std::ostream& operator<<(std::ostream& i, Person&);
	bool operator==(Person&);
	bool operator!=(Person&);
	virtual void operator=(const Person&);

private:
	int birth_year;
	std::string name;
	std::string gender;
};

class Building
{
public:
	Building();
	Building(std::string, std::string, int, int);
	Building(const Building&);
	virtual ~Building();

	void SetSurface(int);
	int GetSurface() const;
	void SetAddress(std::string);
	std::string GetAddress() const;
	void SetName(std::string);
	std::string GetName() const;
	void SetFloorsNumber(int);
	int GetFloorsNumber() const;
	
	virtual void Read(std::istream&) = 0;
	virtual void Print(std::ostream&);
	friend std::istream& operator>>(std::istream&, Building&);
	friend std::ostream& operator<<(std::ostream&, Building&);
	virtual void operator=(const Building&);

private:
	int surface;
	std::string address;
	std::string name;
	int floors_number;
};
