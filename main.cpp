#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "student.h"

using namespace std;

    int main()
    {
        struct Student stud_arr[20];
        struct Class classes[20];
        int i = 0;
        int j = 0;
      
       i = readClass("classHours.txt", classes);
       j = readStudent("students.txt",stud_arr,classes,i);

       outputinfo("pamoutput.txt", stud_arr,j);
       return 0;
    }

    void outputinfo(string fileName, struct Student stud_arr[],int size)
    {
       ofstream logFile;
       logFile.open("logFile.txt", std::ios_base::app);
       logFile << "Opening outputinfo" << endl;

       ofstream pamoutput;
       pamoutput.open(fileName);

       for (int i = 0; i < size - 1; i++)
       {
           cout << stud_arr[i].first << "," << stud_arr[i].last << "," << stud_arr[i].identity << "," << stud_arr[i].gpa << setprecision(2) << endl;
           pamoutput << stud_arr[i].first << "," << stud_arr[i].last << "," << stud_arr[i].identity << "," << stud_arr[i].gpa << setprecision(2) << endl;
       }

       logFile << "Closing outputinfo" << endl;
    }

    int readClass(string fileName, struct Class classes[]) {
       int i = 0;
       ifstream class_file;
       class_file.open(fileName);

       ofstream logFile;
       logFile.open("logFile.txt", std::ios_base::app);

       logFile << "Opening readClass" << endl;
       while (!class_file.eof())
       {
           class_file >> classes[i].designation;
           class_file >> classes[i].classHours;
           i++;
       }
       logFile << "Closing readClass" << endl;
       return i;
    }
   
    int readStudent(string fileName, struct Student stud_arr[], struct Class classes[], int n) {
       int i = 0;
       int no_class_grade;
       string subject;
       char grade;
       double total = 0, tot_cred_Hours = 0;
       ifstream stud_file;
       stud_file.open(fileName);

       ofstream logFile;
       logFile.open("logFile.txt", std::ios_base::app);
       logFile << "Opening readStudent" << endl;
       while (!stud_file.eof())
       {
           stud_file >> stud_arr[i].first;
           stud_file >> stud_arr[i].last;
           stud_file >> stud_arr[i].identity;
           stud_file >> no_class_grade;
           while (no_class_grade > 0)
           {
               stud_file >> subject;
               stud_file >> grade;

               switch (grade)
               {
               case 'A': {
                   total += get_classHours(classes, subject, i) * 4.0;
                   tot_cred_Hours += get_classHours(classes, subject, i);
                   break;
               }
               case 'B': {
                   total += get_classHours(classes, subject, i) * 3.0;
                   tot_cred_Hours += get_classHours(classes, subject, i);
                   break;
               }
               case 'C': {
                   total += get_classHours(classes, subject, i) * 2.0;
                   tot_cred_Hours += get_classHours(classes, subject, i);
                   break;
               };
               case 'D': {
                   total += get_classHours(classes, subject, i) * 1.0;
                   tot_cred_Hours += get_classHours(classes, subject, i);
                   break;
               }
               case 'F': {
                   total += get_classHours(classes, subject, i) * 0.0;
                   tot_cred_Hours += get_classHours(classes, subject, i);
                   break;
               }
               }
               no_class_grade--;
           }

           stud_arr[i].gpa = total / tot_cred_Hours;
           i++;
           total = 0;
           tot_cred_Hours = 0;

       }
       logFile << "Closing readStudent" << endl;
       return i;
    }

    int get_classHours(struct Class classes[], string class_name, int size)
    {
       ofstream logFile;
       logFile.open("logFile.txt", std::ios_base::app);
       logFile << "Opening get_Credit_Hours" << endl;
       for (int i = 0; i < size - 1; i++)
       {
           if (classes[i].designation.compare(class_name) == 0)
           {
               return classes[i].classHours;
           }
       }
       logFile << "Closing get_classHours" << endl;
    return 0;
    }
