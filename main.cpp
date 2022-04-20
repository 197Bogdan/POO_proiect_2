#include <iostream>
#include <vector>
#include <string>
#include "university.h"

using namespace std;

void ClearScreen()
{
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}

string user_input;
int person_count = 0, building_count = 0;
Person* p_person[100];
Building* p_building[100];

void meniu()
{

	while (true)										/////// meniu
	{
		cout << "Alege o optiune: " << endl;
		cout << "1. Studenti" << endl;
		cout << "2. Profesori" << endl;
		cout << "3. Studenti profesori" << endl;
		cout << "4. Facultati" << endl;
		cout << "5. Camine" << endl;
		cout << "6. Inchide progrmaul" << endl;
		cout << "7. Afiseaza toate informatiile facultatii" << endl;

		getline(cin, user_input);
		try
		{
			if (user_input.size() != 1 || char(user_input[0]) > '7' || char(user_input[0]) < '1')
				throw 1;
			ClearScreen();
			if (char(user_input[0]) == '1')			/// meniu student
				while (true)
				{
					cout << "Meniu student:" << endl;
					cout << "1. Adauga un student" << endl;
					cout << "2. Modifica un student" << endl;
					cout << "3. Sterge un student" << endl;
					cout << "4. Afiseaza toti studentii" << endl;
					cout << "5. Inapoi" << endl;
					getline(cin, user_input);
					try
					{
						if (user_input.size() != 1 || char(user_input[0]) > '5' || char(user_input[0]) < '1')
							throw 2;
						else if (char(user_input[0]) == '1')
						{
							p_person[person_count] = new Student;
							cin >> *p_person[person_count];
							person_count++;
							ClearScreen();
						}
						else if (char(user_input[0]) == '2')
						{
							ClearScreen();
							int count = 0;
							for (int i = 0; i < person_count; i++)
							{

								Student* p = dynamic_cast<Student*>(p_person[i]);
								if (p)
								{
									cout << "Nr. " << i << ": ";
									cout << *p;
									count++;
								}
							}
							if (!count)
							{
								cout << "Nu exista studenti.";
								throw 10;
							}
							cout << "Introduceti numarul studentului." << endl;
							while (true)
							{
								try
								{
									getline(cin, user_input);
									Student* p = dynamic_cast<Student*>(p_person[stoi(user_input)]);
									if (!p)
										throw 'e';
									break;
								}
								catch (invalid_argument)
								{
									cout << endl << endl;
									cout << "Input invalid! Reintroduceti datele." << endl << endl;
								}
								catch (char)
								{
									cout << endl << endl;
									cout << "Numarul introdus nu corespunde unui profesor! Reintroduceti datele." << endl << endl;
								}
							}
							cin >> *p_person[stoi(user_input)];
							ClearScreen();

						}
						else if (char(user_input[0]) == '3')
						{
							ClearScreen();
							int count = 0;
							for (int i = 0; i < person_count; i++)
							{

								Student* p = dynamic_cast<Student*>(p_person[i]);
								if (p)
								{
									cout << "Nr. " << i << ": ";
									cout << *p;
									count++;
								}
							}
							if (!count)
							{
								cout << "Nu exista studenti.";
								throw 10;
							}
							cout << "Introduceti numarul studentului." << endl;
							while (true)
							{
								try
								{
									getline(cin, user_input);
									if (stoi(user_input) > person_count)
										throw 'f';
									Student* p = dynamic_cast<Student*>(p_person[stoi(user_input)]);
									if (!p)
										throw 'e';
									break;
								}
								catch (invalid_argument)
								{
									cout << endl << endl;
									cout << "Input invalid! Reintroduceti datele."<< endl << endl;
								}
								catch (char)
								{
									cout << endl << endl;
									cout << "Numarul introdus nu corespunde unui student! Reintroduceti datele." << endl << endl;
								}
							}



							delete p_person[stoi(user_input)];
							for (int i = stoi(user_input); i < person_count-1; i++)
								p_person[i] = p_person[i + 1];
							person_count--;
							ClearScreen();
						}
						else if (char(user_input[0]) == '4')
						{
						ClearScreen();
							int count = 0;
							for (int i = 0; i < person_count; i++)
							{

								Student* p = dynamic_cast<Student*>(p_person[i]);
								if (p)
								{
									cout << "Nr. " << i << ": ";
									cout << *p;
									count++;
								}
							}
							if (!count)
							{
								cout << "Nu exista studenti.";
							}
							cout << endl << endl;
						}
						else if (char(user_input[0]) == '5')
						{
							user_input = "0";
							ClearScreen();
							break;
						}
					}
					catch (int err)
					{
						cout << endl << endl;
						cout << "Input invalid! Reintroduceti datele." << err << endl << endl;
					}
				}

			else if (char(user_input[0]) == '2')			/// meniu profesor
				while(true)
				{
					cout << "Meniu profesor:" << endl;
					cout << "1. Adauga un profesor" << endl;
					cout << "2. Modifica un profesor" << endl;
					cout << "3. Sterge un profesor" << endl;
					cout << "4. Afiseaza toti profesorii" << endl;
					cout << "5. Inapoi" << endl;
					cout << "6. Adauga o materie" << endl;
					cout << "7. Arata lista materiilor" << endl;
					cout << "8. Reseteaza lista materiilor" << endl;
					getline(cin, user_input);
					try
					{
						if (user_input.size() != 1 || char(user_input[0]) > '8' || char(user_input[0]) < '1')
							throw 2;
						else if ((char(user_input[0]) == '8'))
						{
							Teacher::ResetValidSubjects();
							ClearScreen();
						}
						else if ((char(user_input[0]) == '7'))
						{
							ClearScreen();
							cout << "Lista materii: " << endl;
							for (string s : Teacher::GetValidSubjects())
								cout << s << endl;
							cout << endl;
						}
						
						else if ((char(user_input[0]) == '6'))
						{
							ClearScreen();
							cout << "Introduceti numele materiei" << endl;
							getline(cin, user_input);
							Teacher::AddValidSubject(user_input);
						}
						else if (char(user_input[0]) == '1')
						{
							p_person[person_count] = new Teacher;
							cin >> *p_person[person_count];
							person_count++;
							ClearScreen();
						}
						else if (char(user_input[0]) == '2')
						{
							ClearScreen();
							int count = 0;
							for (int i = 0; i < person_count; i++)
							{

								Teacher* p = dynamic_cast<Teacher*>(p_person[i]);
								if (p)
								{
									cout << "Nr. " << i << ": ";
									cout << *p;
									count++;
								}
							}
							if (!count)
							{
								cout << "Nu exista profesori.";
								throw 10;
							}
							cout << "Introduceti numarul profesorului." << endl;
							while (true)
							{
								try
								{
									getline(cin, user_input);
									Teacher* p = dynamic_cast<Teacher*>(p_person[stoi(user_input)]);
									if (!p)
										throw 'e';
									break;
								}
								catch (invalid_argument)
								{
									cout << endl << endl;
									cout << "Input invalid! Reintroduceti datele." << endl << endl;
								}
								catch (char)
								{
									cout << endl << endl;
									cout << "Numarul introdus nu corespunde unui profesor! Reintroduceti datele." << endl << endl;
								}
							}
							cin >> *p_person[stoi(user_input)];
							ClearScreen();

						}
						else if (char(user_input[0]) == '3')
						{
							ClearScreen();
							int count = 0;
							for (int i = 0; i < person_count; i++)
							{

								Teacher* p = dynamic_cast<Teacher*>(p_person[i]);
								if (p)
								{
									cout << "Nr. " << i << ": ";
									cout << *p;
									count++;
								}
							}
							if (!count)
							{
								cout << "Nu exista profesori.";
								throw 10;
							}
							cout << "Introduceti numarul profesorului." << endl;
							while (true)
							{
								try
								{
									getline(cin, user_input);
									if (stoi(user_input) > person_count)
										throw 'f';
									Teacher* p = dynamic_cast<Teacher*>(p_person[stoi(user_input)]);
									if (!p)
										throw 'e';
									break;
								}
								catch (invalid_argument)
								{
									cout << endl << endl;
									cout << "Input invalid! Reintroduceti datele." << endl << endl;
								}
								catch (char)
								{
									cout << endl << endl;
									cout << "Numarul introdus nu corespunde unui profesor! Reintroduceti datele." << endl << endl;
								}
							}
							delete p_person[stoi(user_input)];
							for (int i = stoi(user_input); i < person_count - 1; i++)
								p_person[i] = p_person[i + 1];
							person_count--;
							ClearScreen();
						}
						else if (char(user_input[0]) == '4')
						{
						ClearScreen();
						int count = 0;
						for (int i = 0; i < person_count; i++)
						{

							Teacher* p = dynamic_cast<Teacher*>(p_person[i]);
							if (p)
							{
								cout << "Nr. " << i << ": ";
								cout << *p;
								count++;
							}
						}
						if (!count)
						{
							cout << "Nu exista profesori.";
						}
						cout << endl << endl;
						}
						if (char(user_input[0]) == '5')
						{
							user_input = "0";
							ClearScreen();
							break;
						}
					}
					catch (int err)
					{
						cout << endl << endl;
						cout << "Input invalid! Reintroduceti datele." << err << endl << endl;
					}
				}
			else if (char(user_input[0]) == '3')			/// meniu student profesor
				while(true)
				{
					cout << "Meniu student profesor:" << endl;
					cout << "1. Adauga un student profesor" << endl;
					cout << "2. Modifica un student profesor" << endl;
					cout << "3. Sterge un student profesor" << endl;
					cout << "4. Afiseaza toti studentii profesori" << endl;
					cout << "5. Inapoi" << endl;
					getline(cin, user_input);
					try
					{
						if (user_input.size() != 1 || char(user_input[0]) > '5' || char(user_input[0]) < '1')
							throw 2;
						else if (char(user_input[0]) == '1')
						{
							p_person[person_count] = new StudentTeacher;
							cin >> *p_person[person_count];
							person_count++;
							ClearScreen();
						}
						else if (char(user_input[0]) == '2')
						{
							ClearScreen();
							int count = 0;
							for (int i = 0; i < person_count; i++)
							{

								StudentTeacher* p = dynamic_cast<StudentTeacher*>(p_person[i]);
								if (p)
								{
									cout << "Nr. " << i << ": ";
									cout << *p;
									count++;
								}
							}
							if (!count)
							{
								cout << "Nu exista studenti profesori.";
								throw 10;
							}
							cout << "Introduceti numarul studentului profesor." << endl;
							while (true)
							{
								try
								{
									getline(cin, user_input);
									StudentTeacher* p = dynamic_cast<StudentTeacher*>(p_person[stoi(user_input)]);
									if (!p)
										throw 'e';
									break;
								}
								catch (invalid_argument)
								{
									cout << endl << endl;
									cout << "Input invalid! Reintroduceti datele." << endl << endl;
								}
								catch (char)
								{
									cout << endl << endl;
									cout << "Numarul introdus nu corespunde unui student profesor! Reintroduceti datele." << endl << endl;
								}
							}
							cin >> *p_person[stoi(user_input)];
							ClearScreen();

						}
						else if (char(user_input[0]) == '3')
						{
							ClearScreen();
							int count = 0;
							for (int i = 0; i < person_count; i++)
							{

								StudentTeacher* p = dynamic_cast<StudentTeacher*>(p_person[i]);
								if (p)
								{
									cout << "Nr. " << i << ": ";
									cout << *p;
									count++;
								}
							}
							if (!count)
							{
								cout << "Nu exista studenti profesori.";
								throw 10;
							}
							cout << "Introduceti numarul studentului profesor." << endl;
							while (true)
							{
								try
								{
									getline(cin, user_input);
									if (stoi(user_input) > person_count)
										throw 'f';
									StudentTeacher* p = dynamic_cast<StudentTeacher*>(p_person[stoi(user_input)]);
									if (!p)
										throw 'e';
									break;
								}
								catch (invalid_argument)
								{
									cout << endl << endl;
									cout << "Input invalid! Reintroduceti datele." << endl << endl;
								}
								catch (char)
								{
									cout << endl << endl;
									cout << "Numarul introdus nu corespunde unui student profesor! Reintroduceti datele." << endl << endl;
								}
							}
							delete p_person[stoi(user_input)];
							for (int i = stoi(user_input); i < person_count - 1; i++)
								p_person[i] = p_person[i + 1];
							person_count--;
							ClearScreen();
						}
						else if (char(user_input[0]) == '4')
						{
						ClearScreen();
						int count = 0;
						for (int i = 0; i < person_count; i++)
						{

							StudentTeacher* p = dynamic_cast<StudentTeacher*>(p_person[i]);
							if (p)
							{
								cout << "Nr. " << i << ": ";
								cout << *p;
								count++;
							}
						}
						if (!count)
						{
							cout << "Nu exista studenti profesori.";
						}
						cout << endl << endl;
						}
						if (char(user_input[0]) == '5')
						{
							user_input = "0";
							ClearScreen();
							break;
						}
					}
					catch (int err)
					{
						cout << endl << endl;
						cout << "Input invalid! Reintroduceti datele." << err << endl << endl;
					}
				}
			else if (char(user_input[0]) == '4')			/// meniu facultate
				while(true)
				{
					cout << "Meniu facultate:" << endl;
					cout << "1. Adauga o facultate" << endl;
					cout << "2. Modifica o facultate" << endl;
					cout << "3. Sterge o facultate" << endl;
					cout << "4. Afiseaza toate facultatile" << endl;
					cout << "5. Inapoi" << endl;
					getline(cin, user_input);
					try
					{
						if (user_input.size() != 1 || char(user_input[0]) > '5' || char(user_input[0]) < '1')
							throw 2;
						else if (char(user_input[0]) == '1')
						{
							p_building[building_count] = new Faculty;
							cin >> *p_building[building_count];
							building_count++;
							ClearScreen();
						}
						else if (char(user_input[0]) == '2')
						{
							ClearScreen();
							int count = 0;
							for (int i = 0; i < building_count; i++)
							{

								Faculty* p = dynamic_cast<Faculty*>(p_building[i]);
								if (p)
								{
									cout << "Nr. " << i << ": ";
									cout << *p << endl;
									count++;
								}
							}
							if (!count)
							{
								cout << "Nu exista facultati.";
								throw 10;
							}
							cout << "Introduceti numarul facultatii." << endl;
							while (true)
							{
								try
								{
									getline(cin, user_input);
									Faculty* p = dynamic_cast<Faculty*>(p_building[stoi(user_input)]);
									if (!p)
										throw 'e';
									break;
								}
								catch (invalid_argument)
								{
									cout << endl << endl;
									cout << "Input invalid! Reintroduceti datele." << endl << endl;
								}
								catch (char)
								{
									cout << endl << endl;
									cout << "Numarul introdus nu corespunde unei facultati! Reintroduceti datele." << endl << endl;
								}
							}
							cin >> *p_building[stoi(user_input)];
							ClearScreen();

						}
						else if (char(user_input[0]) == '3')
						{
							ClearScreen();
							int count = 0;
							for (int i = 0; i < building_count; i++)
							{

								Faculty* p = dynamic_cast<Faculty*>(p_building[i]);
								if (p)
								{
									cout << "Nr. " << i << ": ";
									cout << *p << endl;
									count++;
								}
							}
							if (!count)
							{
								cout << "Nu exista facultati.";
								throw 10;
							}
							cout << "Introduceti numarul facultatii." << endl;
							while (true)
							{
								try
								{
									getline(cin, user_input);
									if (stoi(user_input) > building_count)
										throw 'f';
									Faculty* p = dynamic_cast<Faculty*>(p_building[stoi(user_input)]);
									if (!p)
										throw 'e';
									break;
								}
								catch (invalid_argument)
								{
									cout << endl << endl;
									cout << "Input invalid! Reintroduceti datele." << endl << endl;
								}
								catch (char)
								{
									cout << endl << endl;
									cout << "Numarul introdus nu corespunde unei facultati! Reintroduceti datele." << endl << endl;
								}
							}
							delete p_building[stoi(user_input)];
							for (int i = stoi(user_input); i < building_count - 1; i++)
								p_building[i] = p_building[i + 1];
							building_count--;
							ClearScreen();
						}
						else if (char(user_input[0]) == '4')
						{
							ClearScreen();
							int count = 0;
							for (int i = 0; i < building_count; i++)
							{

								Faculty* p = dynamic_cast<Faculty*>(p_building[i]);
								if (p)
								{
									cout << "Nr. " << i << ": ";
									cout << *p << endl;
									count++;
								}
							}
							if (!count)
							{
								cout << "Nu exista facultati.";
							}
							cout << endl << endl;
						}
						if (char(user_input[0]) == '5')
						{
							user_input = "0";
							ClearScreen();
							break;
						}
					}
					catch (int err)
					{
						cout << endl << endl;
						cout << "Input invalid! Reintroduceti datele." << err << endl << endl;
					}
				}
			else if (char(user_input[0]) == '5')			/// meniu camin
				while(true)
				{
					cout << "Meniu camin:" << endl;
					cout << "1. Adauga un camin" << endl;
					cout << "2. Modifica un camin" << endl;
					cout << "3. Sterge un camin" << endl;
					cout << "4. Afiseaza toate caminele" << endl;
					cout << "5. Inapoi" << endl;
					getline(cin, user_input);
					try
					{
						if (user_input.size() != 1 || char(user_input[0]) > '5' || char(user_input[0]) < '1')
							throw 2;
						else if (char(user_input[0]) == '1')
						{
							p_building[building_count] = new StudentDorm;
							cin >> *p_building[building_count];
							building_count++;
							ClearScreen();
						}
						else if (char(user_input[0]) == '2')
						{
							ClearScreen();
							int count = 0;
							for (int i = 0; i < building_count; i++)
							{

								StudentDorm* p = dynamic_cast<StudentDorm*>(p_building[i]);
								if (p)
								{
									cout << "Nr. " << i << ": ";
									cout << *p << endl;
									count++;
								}
							}
							if (!count)
							{
								cout << "Nu exista camine.";
								throw 10;
							}
							cout << "Introduceti numarul caminului." << endl;
							while (true)
							{
								try
								{
									getline(cin, user_input);
									StudentDorm* p = dynamic_cast<StudentDorm*>(p_building[stoi(user_input)]);
									if (!p)
										throw 'e';
									break;
								}
								catch (invalid_argument)
								{
									cout << endl << endl;
									cout << "Input invalid! Reintroduceti datele." << endl << endl;
								}
								catch (char)
								{
									cout << endl << endl;
									cout << "Numarul introdus nu corespunde unui camin! Reintroduceti datele." << endl << endl;
								}
							}
							cin >> *p_building[stoi(user_input)];
							ClearScreen();

						}
						else if (char(user_input[0]) == '3')
						{
							ClearScreen();
							int count = 0;
							for (int i = 0; i < building_count; i++)
							{

								StudentDorm* p = dynamic_cast<StudentDorm*>(p_building[i]);
								if (p)
								{
									cout << "Nr. " << i << ": ";
									cout << *p << endl;
									count++;
								}
							}
							if (!count)
							{
								cout << "Nu exista camine.";
								throw 10;
							}
							cout << "Introduceti numarul caminului." << endl;
							while (true)
							{
								try
								{
									getline(cin, user_input);
									if (stoi(user_input) > building_count)
										throw 'f';
									StudentDorm* p = dynamic_cast<StudentDorm*>(p_building[stoi(user_input)]);
									if (!p)
										throw 'e';
									break;
								}
								catch (invalid_argument)
								{
									cout << endl << endl;
									cout << "Input invalid! Reintroduceti datele." << endl << endl;
								}
								catch (char)
								{
									cout << endl << endl;
									cout << "Numarul introdus nu corespunde unui camin! Reintroduceti datele." << endl << endl;
								}
							}
							delete p_building[stoi(user_input)];
							for (int i = stoi(user_input); i < building_count - 1; i++)
								p_building[i] = p_building[i + 1];
							building_count--;
							ClearScreen();
						}
						else if (char(user_input[0]) == '4')
						{
							ClearScreen();
							int count = 0;
							for (int i = 0; i < building_count; i++)
							{

								StudentDorm* p = dynamic_cast<StudentDorm*>(p_building[i]);
								if (p)
								{
									cout << "Nr. " << i << ": ";
									cout << *p << endl;
									count++;
								}
							}
							if (!count)
							{
								cout << "Nu exista camine.";
							}
							cout << endl << endl;
						}
						if (char(user_input[0]) == '5')
						{
							ClearScreen();
							user_input = "0";
							break;
						}
					}
					catch (int err)
					{
						cout << endl << endl;
						cout << "Input invalid! Reintroduceti datele." << err << endl << endl;
					}
				}
			else if (char(user_input[0]) == '6')
				break;
			else if (char(user_input[0]) == '7')
			{
				cout << "		Persoane:" << endl;
				for (int i=0; i<person_count;i++)
					cout << *p_person[i] << endl;
				cout << "		Cladiri:" << endl;
				for (int i = 0; i < building_count; i++)
					cout << *p_building[i] << endl;

			}

		}
		catch (int err)
		{
				cout << endl << endl;
				cout << "Input invalid! Reintroduceti datele." << err << endl << endl;
		}
	}
} 

int main()
{
	p_person[0] = new Student();											// constructor neparametrizat
	p_person[1] = new Student("Dan", 2001, "m", 40, 7.5);					// constructor parametrizat
	p_person[2] = new Student(*dynamic_cast<Student*>(p_person[1]));		// downcast pentru a folosi constructorul de copiere
	p_person[3] = new Teacher("Mark", 1977, "m", "mate", 10);
	p_person[4] = new Teacher("Ela", 1989, "f", "info", 4);
	p_person[5] = new StudentTeacher("Liviu", 1999, "m", 45, 10, "Algebra", 1);			// clasa cu 2 mosteniri virtuale
	p_person[6] = new StudentTeacher();										
	*dynamic_cast<StudentTeacher*>(p_person[6]) = *dynamic_cast<StudentTeacher*>(p_person[5]);						// operator de atribuire 
	person_count = 7;

	p_building[0] = new Faculty("FMI", "universitate", 1200, 4, 3, 30, 25, { {"Info", 15}, {"Mate", 10} });	
	p_building[1] = new Faculty("Litere", "universitate", 1320, 5, 5, 15, 20, { {"Romana", 10}, {"Franceza", 10} });
	p_building[2] = new Faculty(*dynamic_cast<Faculty*>(p_building[0]));
	p_building[3] = new StudentDorm("Nr. 4", "piata romana", 900, 3, 50, 100, { {3, 25}, {1, 25} });
	p_building[4] = new StudentDorm("Nr. 7", "militari", 1203, 4, 40, 120, { {3, 40} });
	building_count = 5;

	cout << "Materii: ";
	for (string s : Teacher::GetValidSubjects())					// exemplu de functie statica
		cout << s << " ";
	cout << endl;

	for (int i = 0; i < building_count; i++)
		cout << *p_building[i] << endl;					// afisare corecta pe baza functiei virtuale Print
	for (int i = 0; i < person_count; i ++)
	{
		if (typeid(*p_person[i]) == typeid(Student))							// afisare corecta pe baza downcasting ului
		{
			Student* s = dynamic_cast<Student*>(p_person[i]);
			cout << *s << endl;
		}
		else if (typeid(*p_person[i]) == typeid(Teacher))
		{
			Teacher* t = dynamic_cast<Teacher*>(p_person[i]);
			cout << *t << endl;
		}
		else if (typeid(*p_person[i]) == typeid(StudentTeacher))
		{
			StudentTeacher* st = dynamic_cast<StudentTeacher*>(p_person[i]);
			cout << *st << endl;
		}
									
	}
	system("pause");
	meniu();		// meniu interactiv
								
}

