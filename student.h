#ifndef STUDENT_H
#define STUDENT_H
#include"personal.h"

class Student :public Personal
{
    friend ostream&operator<<(ostream&out,Student&st);
    friend istream&operator>>(istream&in,Student&st);
public:
    Student();
    Student(char*ssn,char*n,char*c,int y,int s,char* m);
    ~Student();

    void writeToFile(fstream &out) const;
    void readFromFile(fstream &in);

protected:
    ostream&writeLegibly(ostream &out);
    istream&readFromConsole(istream &in);

    char*major;
    const int majorLen;

};



#endif // STUDENT_H
