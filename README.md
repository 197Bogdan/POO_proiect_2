# POO_proiect_2

Programul modeleaza o universitate, avand in componenta clasele Student, Teacher, StudentTeacher (derivate din Person) si Faculty, StudentDorm (derivate din Building). <br>
Atributele claselor sunt urmatoarele: <br>

Person: name, birth_year, gender<br>
Student: Person + credits, average_grade<br>
Teacher: Person + subject, experience_years + (static) valid_subjects<br>
TeacherStudent: Student + Teacher<br>

Building: name, address, surface, floors_count<br>
Faculty: Building + amphitheatre_count, classroom_count, lab_count, lab_distribution<br>
StudentDorm: Building + room_count, housing_capacity, room_distribution<br>
lab_distribution, respectiv room_distribution sunt structuri de tip unordered_map care memoreaza distributia laboratoarelor/camerelor (tip laborator/camera -> numar)<br>

Toate atributele au functii de get/set, toate clasele au operatori de initializare, parametrizati, de copiere, dar si operatorii "=", "<<", ">>" supraincarcati.<br>
Exista functii virtuale de citire/afisare ("Read", respectiv "Print") care pot fi folosite cu un vector de pointeri la clasa de baza (Person sau Building, dupa caz)<br>
Exista functiile AddRooms, RemoveRooms, AddLaboratories, RemoveLaboratories, care permit modificarea map-urilor ce memoreaza distributiile. Parametrii primiti sunt tipul camerei/laboratorului si numarul acestora.<br>

Programul dispune de un meniu interactiv care permite adaugarea, modificarea sau stergerea obiectelor de orice fel (adresele lor fiind memorate intr-un vector de pointeri)<br>
Meniul poate de asemenea sa afiseze lista materiilor valide, lista obiectelor de un tip specific (toti studentii, de exemplu) sau afisarea tuturor componentelor universitatii (toate obiectele)<br>
Daca este introdus input invalid, se afiseaza o eroare si se cere reintroducerea altui input pana cand acesta este valid.<br>
