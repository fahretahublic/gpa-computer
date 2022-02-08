// *******************************************************************************
// Program name: proj1.cpp
// Author: Fahreta Hublic
// This program reads student and class data and computes GPA
// *******************************************************************************

#pragma once
#ifndef student_h
#define student_h
#include <string>
using namespace std;


int readClass(string fileName, struct Class* classes);
int readStudent(string fileName, struct Student* stud_arr, struct Class* classes, int n);
int get_classHours(struct Class* classes, string class_name, int size);
void outputinfo(string fileName, struct Student* stud_arr, int size);

struct Student
{
   string first;
   string last;
   int identity;
   double gpa;
};

struct Class
{
   string designation;
   int classHours;
};

#endif /* student_h */

