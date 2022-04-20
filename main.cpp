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

void FluxTestare1()
{
	Student s1, s2, s3, s4;
	Teacher t1, t2;
	string nume = "134";
	Group g(nume);	// cream o grupa goala, doar pe baza numelui

	cin >> s1;		// dan 1997 masculin 5.5 20
	cout << s1;		// afisam informatiile studentului
	cout << "--------------------" << endl;

	cin >> s2;		// denis 1998 7.25 40
	cin >> s3;		// max 1996 8.1 45
	cout << "--------------------" << endl;

	cin >> t1;		// Jim 1944 Mate 20
	cout << t1;		// afisam informatiile profesorului
	cout << "--------------------" << endl;

	cin >> t2;		// James 1945 Info 25
	cout << "--------------------" << endl;

	g.AddStudent(s1);	// adaugam un student
	g.AddTeacher(t1);	// adaugam un profesor
	vector<Student> studenti = { s2, s3 };
	g.AddStudents(studenti);	// adaugam un vector de studenti
	g.AddTeacher(t2);	// adaugam un profesor
	cout << g;	// afisam infomatiile grupei
	cout << "--------------------" << endl;
	system("pause");	// press any key to continue
	cout << endl;
	cout << "--------------------" << endl;
	cout << "--------------------" << endl;
	cout << "--------------------" << endl;

	g.RemoveStudent(s2);		// eliminam un student pe baza obiectului
	g.RemoveTeacher("Jim");		// eliminam un profesor pe baza numelui
	g.RemoveTeacher("Karl");	// incercam sa eliminam un profesor care nu exista
	cout << "--------------------" << endl;
	cout << g;		// afisam informatiile grupei
	cout << "--------------------" << endl;
	cout << "--------------------" << endl;
	cout << "--------------------" << endl;
	cout << "--------------------" << endl;
	cout << "--------------------" << endl;
}
void FluxTestare2()
{
	Group g1;
	cin >> g1;	// citim toate informatiile unei grupe
	//	134A 
	//	3 
	//	marius 1999 7.5 20 
	//	alex 2001 8.1 54 
	//	paul 2000 9 60
	// 1
	// Dumitran 1981 Info 7
	g1.SetGroupName("151B"); // redenumim grupa
	Teacher t("Damian", 1966, "Masculin", "Mate", 15);
	g1 += t;		// adaugam un profesor la grupa folosind +=
	g1.RemoveStudent("alex");	// eliminam un student dupa nume
	cout << g1; // afisam informatiile despre grupa
	system("pause");	// press any key to continue
	cout << endl;
	cout << "--------------------" << endl;
	cout << "--------------------" << endl;
	cout << "--------------------" << endl;
	Student s1("Dan", 1997, "masculin", 30, 5.5), s2("Denis", 2000, "masculin", 45, 6.1);		
	Teacher t1("Karl", 1967, "masculin", "Mate", 5);
	Group g2("140F", { s1, s2 }, { t1 });	// initializare directa a unei grupe

	cout << g1 + g2;		// concatenam studentii si profesorii grupei 2 la grupa 1



}
int main()
{
	string user_input;
	int person_count = 0, building_count = 0;
	Person* p_person[100];
	Building* p_building[100];
	while (true)										/////// meniu
	{
		cout << "Alege o categorie pe care s-o modifici: " << endl;
		cout << "1. Studenti" << endl;
		cout << "2. Profesori" << endl;
		cout << "3. Studenti profesori" << endl;
		cout << "4. Facultati" << endl;
		cout << "5. Camine" << endl;
		cout << "6. Inchide progrmaul" << endl;

		getline(cin, user_input);
		try
		{
			if (user_input.size() != 1 || char(user_input[0]) > '6' || char(user_input[0]) < '1')
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
						if (user_input.size() != 1 || char(user_input[0]) > '5' || char(user_input[0]) < '1')
							throw 2;
						else if ((char(user_input[0]) == '8'))
						{
							Teacher::ResetValidSubjects();
							ClearScreen();
						}
						else if ((char(user_input[0]) == '7'))
						{
							ClearScreen();
							for (string s : Teacher::GetValidSubjects())
								cout << s << endl;
						}
						else if ((char(user_input[0]) == '6'))
						{
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
			if (char(user_input[0]) == '6')
				break;

		}
		catch (int err)
		{
				cout << endl << endl;
				cout << "Input invalid! Reintroduceti datele." << err << endl << endl;
		}
	}
	return 0;


} 

