#include <iostream>
#include <vector>
#include <string>
#include "university.h"


std::vector<std::string> Teacher::valid_subjects = { "mate", "info" };
std::vector<std::string> Teacher::GetValidSubjects()
{
	return valid_subjects;
}
void Teacher::SetValidSubjects(std::vector < std::string> s)
{
	valid_subjects = s;
}
void Teacher::AddValidSubject(std::string s)
{
	valid_subjects.push_back(s);
}
void Teacher::ResetValidSubjects()
{
	valid_subjects.clear();
}

Teacher::Teacher(std::string name, int birth_year, std::string gender, std::string subject, int experience_years): Person(name, birth_year, gender), subject(subject), experience_years(experience_years) {}

Teacher::Teacher(const Teacher& t): Person(t), subject(t.subject), experience_years(t.experience_years) {}

Teacher::Teacher(): subject(""), experience_years(0) {}


void Teacher::SetSubject(std::string subject)
{
	this->subject = subject;
}
std::string Teacher::GetSubject() const
{
	return subject;
}
void Teacher::SetExperienceYears(int years)
{
	experience_years = years;
}
int Teacher::GetExperienceYears() const
{
	return experience_years;
}


void Teacher::Read(std::istream& in)
{
	std::cout << "Introduceti datele profesorului." << std::endl;
	std::string nume, materie, gen, nastere, exp;
	while (true)
	{
		try
		{
			std::cout << "Nume: " << std::endl;
			getline(in, nume);
			SetName(nume);
			std::cout << "Anul nasterii: " << std::endl;
			getline(in, nastere);
			SetBirthYear(stoi(nastere));
			std::cout << "Sex: " << std::endl;
			getline(in, gen);
			SetGender(gen);
			std::cout << "Materie: " << std::endl;
			getline(in, materie);
			SetSubject(materie);
			std::cout << "Ani experienta: " << std::endl;
			getline(in, exp);
			SetExperienceYears(stoi(exp));
			break;
		}
		catch (std::invalid_argument)
		{
			std::cout << "Input invalid. Reintroduceti datele." << std::endl;
		}
	}
}
void Teacher::Print(std::ostream& out)
{
	out << GetName() << ", " << GetBirthYear() << ", " <<GetGender() << ", " << GetSubject() << ", " << GetExperienceYears() << " ani experienta." << std::endl;
}

std::istream& operator>>(std::istream& in, Teacher& teacher)
{
	teacher.Read(in);
	return in;
}
std::ostream& operator<<(std::ostream& out, Teacher& teacher)
{
	teacher.Print(out);
	return out;
}
void Teacher::operator=(const Teacher& t)
{
	SetName(t.GetName());
	SetBirthYear(t.GetBirthYear());
	SetGender(t.GetGender());
	subject = t.subject;
	experience_years = t.experience_years;
}



//////////////////////////

Student::Student(std::string name, int birth_year, std::string gender, int credits_number, double grades_average): Person(name, birth_year, gender), credits_number(credits_number), grades_average(grades_average) {}

Student::Student(const Student& s): Person(s), credits_number(s.credits_number), grades_average(s.grades_average) {}

Student::Student(): credits_number(0), grades_average(0) {}


void Student::SetCredits(int c)
{
	credits_number = c;
}
int Student::GetCredits() const
{
	return credits_number;
}
void Student::SetGradeAvg(double g)
{
	grades_average = g;
}
double Student::GetGradeAvg() const
{
	return grades_average;
}

void Student::Read(std::istream& in)
{
	std::cout << "Introduceti datele studentului." << std::endl;
	std::string nume, sex, medie, credite, an;
	while (true)
	{
		try
		{
			std::cout << "Nume: " << std::endl;
			getline(in, nume);
			SetName(nume);
			std::cout << "Anul nasterii: " << std::endl;
			getline(in, an);
			SetBirthYear(stoi(an));
			std::cout << "Sex: " << std::endl;
			getline(in, sex);
			SetGender(sex);
			std::cout << "Medie: " << std::endl;
			getline(in, medie);
			SetGradeAvg(stof(medie));
			std::cout << "Credite: " << std::endl;
			getline(in, credite);
			SetCredits(stoi(credite));

			break;
		}
		catch (std::invalid_argument)
		{
			std::cout << "Input invalid. Reintroduceti datele." << std::endl;
		}
	}


}
void Student::Print(std::ostream& out)
{
	out << GetName() << ", " << GetBirthYear() << ", " << GetGender() << ", " << GetGradeAvg() << ", " << GetCredits() << " credite." << std::endl;
}

std::istream& operator>>(std::istream &in, Student& student)
{
	student.Read(in);
	return in;
}
std::ostream& operator<<(std::ostream& out, Student& student)
{
	student.Print(out);
	return out;
}
void Student::operator=(const Student& student) 
{
	SetName(student.GetName());
	SetBirthYear(student.GetBirthYear());
	SetGender(student.GetGender());
	credits_number = student.credits_number;
	grades_average = student.grades_average;
}



/// ///////////////////////////////////

StudentTeacher::StudentTeacher(): Person(), Student(), Teacher() {}

StudentTeacher::StudentTeacher(std::string name, int birth_year, std::string gender, int credits, double grades_avg, std::string subject, int experience_years): 
													Person(name, birth_year, gender), Student(name, birth_year, gender, credits, grades_avg), Teacher(name, birth_year, gender, subject, experience_years) {}

StudentTeacher::StudentTeacher(const StudentTeacher& st): Person(st), Student(st), Teacher(st) {}

StudentTeacher::~StudentTeacher()
{
	std::cout << "Profesorul student a fost sters." << std::endl;
}

void StudentTeacher::Read(std::istream& in)
{
	std::cout << "Introduceti datele studentului profesor." << std::endl;
	std::string nume, materie, gen, nastere, exp, medie, credite;
	while (true)
	{
		try
		{
			std::cout << "Nume: " << std::endl;
			getline(in, nume);
			SetName(nume);
			std::cout << "Anul nasterii: " << std::endl;
			getline(in, nastere);
			SetBirthYear(stoi(nastere));
			std::cout << "Sex: " << std::endl;
			getline(in, gen);
			SetGender(gen);
			std::cout << "Medie: " << std::endl;
			getline(in, medie);
			SetGradeAvg(stof(medie));
			std::cout << "Credite: " << std::endl;
			getline(in, credite);
			SetCredits(stoi(credite));
			std::cout << "Materie: " << std::endl;
			getline(in, materie);
			SetSubject(materie);
			std::cout << "Ani experienta: " << std::endl;
			getline(in, exp);
			SetExperienceYears(stoi(exp));
			break;
		}
		catch (std::invalid_argument)
		{
			std::cout << "Input invalid. Reintroduceti datele." << std::endl;
		}
	}
}
void StudentTeacher::Print(std::ostream& out)
{
	out << GetName() << ", " << GetBirthYear() << ", " << GetGender() << ", " << GetGradeAvg() << ", " << GetCredits() << " credite." << ", " << GetSubject() << ", " << GetExperienceYears() << " ani de experienta." << std::endl;
}
std::istream& operator>>(std::istream& in, StudentTeacher& st)
{
	st.Read(in);
	return in;
}
std::ostream& operator<<(std::ostream& out, StudentTeacher& st)
{
	st.Print(out);
	return out;
}
void StudentTeacher::operator=(const StudentTeacher& st)
{
	SetName(st.GetName());
	SetBirthYear(st.GetBirthYear());
	SetGender(st.GetGender());
	SetCredits(st.GetCredits());
	SetGradeAvg(st.GetGradeAvg());
	SetSubject(st.GetSubject());
	SetExperienceYears(st.GetExperienceYears());
}


/// ///////////////////////////////////


Group::Group(std::string group_name, std::vector<Student> students, std::vector<Teacher> teachers)
{
	this->group_name = group_name;
	student_count = students.size();
	this->students = students;
	double suma_note = 0;
	if (students.size() > 0)
	{
		for (Student student : students)
			suma_note += student.GetGradeAvg();
		average_grade = suma_note / student_count;
	}
	else average_grade = 0;
	this->teachers = teachers;
}

Group::Group(Group& group)
{
	group_name = group.group_name;
	student_count = group.student_count;
	students = group.students;
	teachers = group.teachers;
	average_grade = group.average_grade;
}

Group::Group()
{
	group_name = "";
	student_count = 0;
	students = {};
	teachers = {};
	average_grade = 0;
}

Group::~Group()
{
	std::cout << "Grupa a fost stearsa." << std::endl;
}


void Group::GetStudents(std::vector<Student>& v)
{
	v = students;
}
void Group::SetStudents(std::vector<Student>& v)
{
	students = v;
	student_count = students.size();
	average_grade = GetGradeAvg();

}
void Group::GetTeachers(std::vector<Teacher>& t)
{
	t = teachers;
}
void Group::SetTeachers(std::vector<Teacher>& t)
{
	teachers = t;
}
std::string Group::GetGroupName()
{
	return group_name;
}
void Group::SetGroupName(std::string name)
{
	group_name = name;
}
const int Group::GetStudentCount()
{
	return student_count;
}
double Group::GetGradeAvg()
{
	return average_grade;
}
int Group::GetTeacherCount()
{
	return teachers.size();
}



void Group::AddStudent(Student& student)
{
	if (student.GetName() == "")
		return;
	students.push_back(student);
	average_grade = (average_grade * student_count + student.GetGradeAvg()) / (student_count + 1);
	student_count++;
	std::cout << "Studentul a fost adaugat." << std::endl;
}

void Group::AddStudents(std::vector<Student> &students)
{
	this->students.insert(this->students.end(), students.begin(), students.end());
	double suma = 0;
	for (Student student : students)
		suma += student.GetGradeAvg();
	average_grade = (average_grade*student_count + suma)/(student_count + students.size());
	student_count += students.size();
	std::cout << "Studentii au fost adaugati." << std::endl;

}

void Group::RemoveStudent(Student& student)
{
	for (unsigned int i = 0; i<students.size(); i++)
		if (students[i] == student)
		{
			if(student_count > 1)
				average_grade = (average_grade * student_count - student.GetGradeAvg()) / (student_count - 1);
			else average_grade = 0;
			students.erase(students.begin() + i);
			student_count--;
			std::cout << "Studentul a fost eliminat." << std::endl;
			return;
		}
	std::cout << "Studentul nu face parte din grupa." << std::endl;

}

void Group::RemoveStudent(std::string name)
{
	for (unsigned int i = 0; i<students.size(); i++)
		if (students[i].GetName() == name)
		{
			if (student_count > 1)
				average_grade = (average_grade * student_count - students[i].GetGradeAvg()) / (student_count - 1);
			else average_grade = 0;
			students.erase(students.begin() + i);
			student_count--;
			std::cout << "Studentul a fost eliminat." << std::endl;
			return;
		}
	std::cout << "Studentul nu face parte din grupa." << std::endl;
}

bool Group::IsStudent(std::string name)
{
	for (Student student : students)
		if (student.GetName() == name)
			return true;
	return false;
}
void Group::AddTeacher(Teacher& teacher)
{
	if (teacher.GetName() == "")
		return;
	teachers.push_back(teacher);
	std::cout << "Profesorul a fost adaugat." << std::endl;
}
void Group::RemoveTeacher(std::string name)
{
	for (unsigned int i = 0; i<teachers.size(); i++)
		if (teachers[i].GetName() == name)
		{
			teachers.erase(teachers.begin() + i);
			std::cout << "Profesorul a fost eliminat." << std::endl;
			return;
		}
	std::cout << "Profesorul nu face parte din grupa." << std::endl;
}

void Group::RemoveTeacher(Teacher& teacher)
{
	for (unsigned int i = 0; i < teachers.size(); i++)
		if (teachers[i] == teacher)
		{
			teachers.erase(teachers.begin() + i);
			std::cout << "Profesorul a fost eliminat." << std::endl;
			return;
		}
	std::cout << "Profesorul nu face parte din grupa." << std::endl;
}
bool Group::IsTeacher(std::string name)
{
	for (Teacher teacher : teachers)
		if (teacher.GetName() == name)
			return true;
	return false;
}

std::istream& operator>>(std::istream& in, Group& group)
{
	std::string nume;
	int numar;
	std::cout << "Numele grupei: ";
	in >> nume;
	group.SetGroupName(nume);
	std::cout << "Numarul de studenti: ";
	in >> numar;
	std::cout << "Introduceti " << numar << " linii. Format linie: <Nume> <An_nastere> <Gen> <Credite> <Medie>" << std::endl;
	for (int i = 0; i<numar; i++)
	{
		std::string nume_student, gen;
		int an;
		int credite;
		double medie;
		in >> nume;
		in >> an;
		in >> gen;
		in >> credite;
		in >> medie;
		Student student(nume_student, an, gen, credite, medie);
		group.AddStudent(student);
	}
	return in;
}
std::ostream& operator<<(std::ostream& out, Group& group)
{
	out << "Numele grupei: " << group.GetGroupName() << std::endl;
	out << "Media grupei: " << group.GetGradeAvg() << std::endl << std::endl;
	out << "Numarul de studenti: " << group.GetStudentCount() << std::endl;
	std::vector<Student> students;
	group.GetStudents(students);
	for (Student student : students)
		out << student;
	out << std::endl;
	out << "Numarul de profesori: " << group.GetTeacherCount() << std::endl;

	std::vector<Teacher> teachers;
	group.GetTeachers(teachers);
	for (Teacher teacher : teachers)
		out << teacher;
	return out;
}

Group& Group::operator+(Group& group)
{
	average_grade = (average_grade * student_count + group.GetGradeAvg() * group.GetStudentCount()) / (student_count+group.GetStudentCount());
	student_count += group.student_count;
	students.insert(students.end(), group.students.begin(), group.students.end());
	teachers.insert(teachers.end(), group.teachers.begin(), group.teachers.end());

	return *this;
}
Group& Group::operator+(Student& student)
{
	average_grade = student.GetGradeAvg() * (float(student_count) / (student_count + 1)) + student.GetGradeAvg() / (student_count + 1);
	student_count++;
	students.push_back(student);

	return *this;
}
void Group::operator+=(Student& student)
{
	average_grade = student.GetGradeAvg() * (float(student_count) / (student_count + 1)) + student.GetGradeAvg() / (student_count + 1);
	student_count++;
	students.push_back(student);
}
Group& Group::operator-(Student& student)
{
	if (IsStudent(student.GetName()))
	{
		average_grade = (average_grade * student_count - student.GetGradeAvg()) / (student_count - 1);
		RemoveStudent(student);
		return *this;
	}
	else std::cout << "Studentul nu e parte din grupa." << std::endl;
	return *this;
}
void Group::operator-=(Student& student)
{
	if (IsStudent(student.GetName()))
	{
		average_grade = (average_grade * student_count - student.GetGradeAvg()) / (student_count - 1);
		RemoveStudent(student);
	}
	else std::cout << "Studentul nu e parte din grupa." << std::endl;
}

Group& Group::operator+(Teacher& teacher)
{
	AddTeacher(teacher);
	return *this;
}
void Group::operator+=(Teacher& teacher)
{
	AddTeacher(teacher);
}

Group& Group::operator-(Teacher& teacher)
{
	RemoveTeacher(teacher);
	return *this;
}
void Group::operator-=(Teacher& teacher)
{
	RemoveTeacher(teacher);
}
bool Group::operator==(Group& group)
{
	if (this->group_name == group.group_name && this->average_grade == group.average_grade
		&& this->student_count == group.student_count)
	{
		for (int i = 0; i < student_count; i++)
			if (!(this->students[i] == group.students[i]))
				return false;
		for (unsigned int i = 0; i < teachers.size(); i++)
			if (!(this->teachers[i] == group.teachers[i]))
				return false;
		return true;
	}


	return false;

}
bool Group::operator!=(Group& group)
{
	return !(*this == group);
}

//////////////////////////////////

Faculty::Faculty(): amphitheater_count(0), classroom_count(0), laboratory_count(0) {}


Faculty::Faculty(std::string address, std::string name, int surface, int floors_count, int amphitheater_count, int classroom_count, int laboratory_count, std::unordered_map < std::string, int> laboratory_distribution):
	Building(address, name, surface, floors_count), amphitheater_count(amphitheater_count), classroom_count(classroom_count), laboratory_count(laboratory_count), laboratory_distribution(laboratory_distribution) {}

Faculty::Faculty(const Faculty& f): Building(f), amphitheater_count(f.amphitheater_count), classroom_count(f.classroom_count), laboratory_count(f.laboratory_count), laboratory_distribution(f.laboratory_distribution) {}

Faculty::~Faculty()
{
	std::cout << "Facultatea a fost stearsa." << std::endl;
}

int Faculty::GetAmphitheaterCount() const
{
	return amphitheater_count;
}
int Faculty::GetClassroomCount() const
{
	return classroom_count;
}
int Faculty::GetLaboratoryCount() const
{
	return laboratory_count;
}
std::unordered_map<std::string, int> Faculty::GetLaboratoryDistribution() const
{
	return laboratory_distribution;
}

void Faculty::AddAmphitheaters(int count)
{
	amphitheater_count += count;
}
void Faculty::RemoveAmphitheaters(int count)
{
	amphitheater_count -= count;
}
void Faculty::AddClassrooms(int count)
{
	classroom_count += count;
}
void Faculty::RemoveClassrooms(int count)
{
	classroom_count -= count;
}
void Faculty::AddLaboratories(int count, std::string type = "General")
{
	laboratory_count += count;
	laboratory_distribution[type] += count;
}
void Faculty::RemoveLaboratories(int count, std::string type = "General")
{
	laboratory_count -= count;
	laboratory_distribution[type] -= count;
}


void Faculty::Read(std::istream& in)
{
	std::cout << "Introduceti datele facultatii." << std::endl;
	std::string nume, adresa, suprafata, nr_etaje, nr_amfi, nr_sali;
	while (true)
	{
		try
		{
			std::cout << "Nume: " << std::endl;
			getline(in, nume);
			SetName(nume);
			std::cout << "Adresa: " << std::endl;
			getline(in, adresa);
			SetAddress(adresa);
			std::cout << "Suprafata: " << std::endl;
			getline(in, suprafata);
			SetSurface(stoi(suprafata));
			std::cout << "Numar de etaje: " << std::endl;
			getline(in, nr_etaje);
			SetFloorsNumber(stoi(nr_etaje));
			std::cout << "Numar de amfiteatre: " << std::endl;
			getline(in, nr_amfi);
			amphitheater_count = 0;
			AddAmphitheaters(stoi(nr_amfi));
			std::cout << "Numar de sali de clasa: " << std::endl;
			getline(in, nr_sali);
			classroom_count = 0;
			AddClassrooms(stoi(nr_sali));
			std::cout << "Introduceti tipul de laborator si numarul de astfel de laboratoare sau '0' daca ati terminat citirea." << std::endl;
			laboratory_distribution.clear();
			laboratory_count = 0;
			while (true)
			{
				std::cout << "Numar de laboratoare: " << std::endl;
				std::string user_input, user_input_2;
				getline(in, user_input);
				if (user_input == "0")
					break;
				std::cout << "Tip de laboratoare: " << std::endl;
				getline(in, user_input_2);
				AddLaboratories(stoi(user_input), user_input_2);
			}
			break;
		}
		catch (std::invalid_argument)
		{
			std::cout << "Input invalid. Reintroduceti datele." << std::endl;
		}
	}
}
void Faculty::Print(std::ostream& out)
{
	out << "Nume: " << GetName() << std::endl;
	out << "Adresa: " << GetAddress() << std::endl;
	out << "Suprafata: " << GetSurface() << std::endl;
	out << "Numar de etaje: " << GetFloorsNumber() << std::endl;
	out << "Amfiteatre: " << amphitheater_count << std::endl;
	out << "Sali de clasa: " << classroom_count << std::endl;
	out << "Laboratoare: " << laboratory_count;
	if(laboratory_count) out << ", dintre care" << std::endl;
	for (auto pair : laboratory_distribution)
		out << pair.first << ": " << pair.second << std::endl;
}

std::istream& operator>>(std::istream& in, Faculty& f)
{
	f.Read(in);
	return in;
}
std::ostream& operator<<(std::ostream& out, Faculty& f)
{
	f.Print(out);
	return out;
}
void Faculty::operator=(const Faculty& f)
{
	SetAddress(f.GetAddress());
	SetName(f.GetName());
	SetSurface(f.GetSurface());
	SetFloorsNumber(f.GetFloorsNumber());
	amphitheater_count = f.amphitheater_count;
	classroom_count = f.classroom_count;
	laboratory_count = f.laboratory_count;
	laboratory_distribution = f.laboratory_distribution;
}


///////////////////////////////////////////////////


StudentDorm::StudentDorm(): room_count(0), housing_capacity(0) {}

StudentDorm::StudentDorm(std::string address, std::string name, int surface, int floors_number, int room_count, int housing_capacity, std::unordered_map<int, int> room_distribution):
	Building(address, name, surface, floors_number), room_count(room_count), housing_capacity(housing_capacity), room_distribution(room_distribution) {}

StudentDorm::StudentDorm(const StudentDorm& s): Building(s), room_count(s.room_count), housing_capacity(s.housing_capacity), room_distribution(s.room_distribution) {}

StudentDorm::~StudentDorm()
{
	std::cout << "Caminul a fost sters." << std::endl;
}
int StudentDorm::GetRoomCount() const
{
	return room_count;
}
int StudentDorm::GetHousingCapacity() const
{
	return housing_capacity;
}
std::unordered_map<int, int> StudentDorm::GetRoomDistribution()
{
	return room_distribution;
}

void StudentDorm::AddRooms(int count, int capacity)
{
	room_count += count;
	housing_capacity += count * capacity;
	room_distribution[capacity] += count;
}
void StudentDorm::RemoveRooms(int count, int capacity)
{
	room_count -= count;
	housing_capacity -= count * capacity;
	room_distribution[capacity] -= count;
}

void StudentDorm::Read(std::istream& in)
{
	std::cout << "Introduceti datele caminului." << std::endl;
	std::string nume, adresa, suprafata, nr_etaje;
	while (true)
	{
		try
		{
			std::cout << "Nume: " << std::endl;
			getline(in, nume);
			SetName(nume);
			std::cout << "Adresa: " << std::endl;
			getline(in, adresa);
			SetAddress(adresa);
			std::cout << "Suprafata: " << std::endl;
			getline(in, suprafata);
			SetSurface(stoi(suprafata));
			std::cout << "Numar de etaje: " << std::endl;
			getline(in, nr_etaje);
			SetFloorsNumber(stoi(nr_etaje));
			std::cout << "Introduceti tipul de camere(capacitatea) si numarul acestora sau '0' daca ati terminat citirea." << std::endl;
			room_distribution.clear();
			housing_capacity = 0;
			room_count = 0;
			while (true)
			{
				std::cout << "Numar de camere: " << std::endl;
				std::string user_input, user_input_2;
				getline(in, user_input);
				if (user_input == "0")
					break;
				std::cout << "Tipul de camere: " << std::endl;
				getline(in, user_input_2);
				AddRooms(stoi(user_input), stoi(user_input_2));
			}
			break;
		}
		catch (std::invalid_argument)
		{
			std::cout << "Input invalid. Reintroduceti datele." << std::endl;
		}
	}
}
void StudentDorm::Print(std::ostream& out)
{
	out << "Nume: " << GetName() << std::endl;
	out << "Adresa: " << GetAddress() << std::endl;
	out << "Suprafata: " << GetSurface() << std::endl;
	out << "Numar de etaje: " << GetFloorsNumber() << std::endl;
	out << "Numar de camere: " << room_count << std::endl;
	out << "Capacitate totala: " << housing_capacity;
	if(housing_capacity)
		out << ", impartita astfel" << std::endl;

	for (auto pair : room_distribution)
		out << "Capacitate " << pair.first << ": " << pair.second << std::endl;
}

std::istream& operator>>(std::istream& in, StudentDorm& s)
{
	s.Read(in);
	return in;
}
std::ostream& operator<<(std::ostream& out, StudentDorm& s)
{
	s.Print(out);
	return out;
}
void StudentDorm::operator=(const StudentDorm& s)
{
	SetAddress(s.GetAddress());
	SetName(s.GetName());
	SetSurface(s.GetSurface());
	SetFloorsNumber(s.GetFloorsNumber());
	room_count = s.room_count;
	housing_capacity = s.housing_capacity;
	room_distribution = s.room_distribution;
}
