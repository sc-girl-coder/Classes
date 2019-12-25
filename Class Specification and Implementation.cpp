/* Samantha Casler
Last Modified: 10/30/18*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Student.h"

using namespace std;


int main()
{
    const int numStudents = 15;
    const int numGrades = 10;

    ifstream fin;
    fin.open ("Project 7_Students_Input.txt");

    Student person;
    int studentId;
    string studentfName;
    string studentlName;

    for (int count = 0; count < numStudents; count++ )
    {


        fin >> studentId;
        fin >> studentfName;
        fin>>studentlName;
        int studentGrades[numGrades];
        for (int i = 0; i < numGrades; i++)
        {
            fin >> studentGrades [i];

        }
        person.setGrades(studentGrades);

        person.setId(studentId);
        person.setName(studentfName,studentlName);


        //for (int j = 0; j < numGrades; j++)
            person.setGrades(studentGrades);

        cout << "Here is student " << (count + 1) << "'s data: \n";
        cout << "ID: " << person.getId() << endl;
        cout << "Name: " << person.getName() << endl;
        cout << "Average: " << fixed << showpoint << setprecision(2) << person.calcAverage() << endl;

        for (int j = 0; j < numGrades; j++)
            cout << "Grade " << (j + 1) << ": " << person.getGrades(j) << endl;

        cout << endl;
    }

}

Contents of Student.h file:
//Specification file for the Student class.
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;

// Student calss declaration.

class Student
{
	private:
		int id;
		string fname, lname, name;
		int grades [10];

	public:
		void setId (int);
		void setName (string, string);
		void setGrades (int []);
		int getId () const;
		string getName () const;
		int getGrades (int);
		double calcAverage ();

};

#endif

Contents of Student.cpp file:
//Implementation file for the Student class.
#include "Student.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void Student::setId (int i)
{
    id = i;
}

void Student::setName (string m,string n)
{
    fname = m;
    lname= n;
    name =fname + " " +lname;
}

void Student::setGrades (int g[])
{
    for (int j = 0; j < 10; j++)
        grades[j]  = g[j] ;
}

int Student::getId () const
{
    return id;
}

string Student::getName() const
{
    return name;
}

int Student::getGrades (int index)
{
    return grades [index];
}

double Student::calcAverage()
{
    double total = 0.0;

    for (int count = 0; count < 10; count++)
        total += grades[count];

    return total/10;
}
