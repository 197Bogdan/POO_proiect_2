#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "common.h"

class Student: virtual public Person
{
public:
	Student(std::string name, int birth_year, std::string gender, int credits_number, double grades_average);
	Student(const Student&);
	Student();

	void SetCredits(int);
	int GetCredits() const;
	void SetGradeAvg(double);
	double GetGradeAvg() const;

	void Read(std::istream&);
	void Print(std::ostream&);
	friend std::istream& operator>>(std::istream &i, Student& student);
	friend std::ostream& operator<<(std::ostream& i, Student& student);
	void operator=(const Student& student);

private:
	int credits_number;
	double grades_average;
};

class Teacher: virtual public Person
{
public:
	Teacher(std::string name, int birth_year, std::string gender, std::string subject, int experience_years);
	Teacher(const Teacher&);
	Teacher();

	void SetSubject(std::string);
	std::string GetSubject() const;
	void SetExperienceYears(int years);
	int GetExperienceYears() const;
	static std::vector<std::string> GetValidSubjects();
	static void SetValidSubjects(std::vector < std::string>);

	static void AddValidSubject(std::string);
	static void ResetValidSubjects();

	void Read(std::istream&);
	void Print(std::ostream&);
	friend std::istream& operator>>(std::istream& i, Teacher& teacher);
	friend std::ostream& operator<<(std::ostream& i, Teacher& teacher);
	void operator=(const Teacher&);

private:
	static std::vector<std::string> valid_subjects;
	std::string subject;
	int experience_years;
};

class StudentTeacher : public Student, public Teacher
{
public:
	StudentTeacher();
	StudentTeacher(std::string name, int birth_year, std::string gender, int credits, double grades_avg, std::string subject, int experience_years);
	StudentTeacher(const StudentTeacher&);
	~StudentTeacher();

	void Read(std::istream& in);
	void Print(std::ostream& out);
	friend std::istream& operator>>(std::istream&, StudentTeacher&);
	friend std::ostream& operator<<(std::ostream&, StudentTeacher&);
	void operator=(const StudentTeacher&);
};


class Group
{
public:
	Group(std::string group_name, std::vector<Student> = {}, std::vector<Teacher> = {});
	Group(Group& group);
	Group();
	~Group();

	void GetStudents(std::vector<Student>& v);
	void SetStudents(std::vector<Student>& v);
	void GetTeachers(std::vector<Teacher>& t);
	void SetTeachers(std::vector<Teacher>& t);
	std::string GetGroupName();
	void SetGroupName(std::string name);
	const int GetStudentCount();
	double GetGradeAvg();
	int GetTeacherCount();
	

	void AddStudent(Student& student);
	void AddStudents(std::vector<Student> &students);
	void RemoveStudent(Student& student);
	void RemoveStudent(std::string name);
	bool IsStudent(std::string name);
	void AddTeacher(Teacher& teacher);
	void RemoveTeacher(Teacher& teacher);
	void RemoveTeacher(std::string name);
	bool IsTeacher(std::string name);

	friend std::istream& operator>>(std::istream& i, Group& group);
	friend std::ostream& operator<<(std::ostream& i, Group& group);
	Group& operator+(Group& group);
	Group& operator+(Student& student);
	void operator+=(Student& student);
	Group& operator-(Student& student);
	void operator-=(Student& student);
	bool operator==(Group& group);
	bool operator!=(Group& group);

	Group& operator+(Teacher& teacher);
	void operator+=(Teacher& teacher);
	Group& operator-(Teacher& teacher);
	void operator-=(Teacher& teacher);
	
private:
	std::vector<Student> students;
	std::vector<Teacher> teachers;
	std::string group_name;
	int student_count;
	double average_grade;
};

class Faculty : public Building
{
public:
	Faculty();
	Faculty(std::string, std::string, int, int, int, int, int, std::unordered_map < std::string, int>);
	Faculty(const Faculty&);
	~Faculty();

	int GetAmphitheaterCount() const;
	int GetClassroomCount() const;
	int GetLaboratoryCount() const;
	std::unordered_map<std::string, int> GetLaboratoryDistribution() const;
	
	void AddAmphitheaters(int);
	void RemoveAmphitheaters(int);
	void AddClassrooms(int);
	void RemoveClassrooms(int);
	void AddLaboratories(int, std::string);
	void RemoveLaboratories(int, std::string);

	void Read(std::istream&);
	void Print(std::ostream&);
	friend std::istream& operator>>(std::istream&, Faculty&);
	friend std::ostream& operator<<(std::ostream&, Faculty&);
	void operator=(const Faculty&);


private:
	int amphitheater_count;
	int classroom_count;
	int laboratory_count;
	std::unordered_map<std::string, int> laboratory_distribution;
};

class StudentDorm : public Building
{
public:
	StudentDorm();
	StudentDorm(std::string, std::string, int, int, int, int, std::unordered_map<int, int>);
	StudentDorm(const StudentDorm&);
	~StudentDorm();
	int GetRoomCount() const;
	int GetHousingCapacity() const;
	std::unordered_map<int, int> GetRoomDistribution();

	void AddRooms(int, int);
	void RemoveRooms(int, int);

	void Read(std::istream& in);
	void Print(std::ostream& out);
	friend std::istream& operator>>(std::istream&, StudentDorm&);
	friend std::ostream& operator<<(std::ostream&, StudentDorm&);
	void operator=(const StudentDorm&);

private:
	int room_count;
	int housing_capacity;
	std::unordered_map<int, int> room_distribution;
};