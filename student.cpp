#include "student.h"
//Student友元函数：*************************************************************************
//****************************************************************************************
ostream &operator<<(ostream &out, Student &st)
{
    return st.writeLegibly(out);

}

istream &operator>>(istream &in, Student &st)
{
    return st.readFromConsole(in);
}
//Student成员函数***************************************************************************
//*****************************************************************************************
Student::Student():majorLen(10)
{
    Personal();
    major=new char[majorLen+1];


}

Student::Student(char *ssn, char *n, char *c, int y, int s, char *m):majorLen(10)
{
    Personal(ssn,n,c,y,s);
    major=new char[majorLen+1];
    strcpy(major,m);

}

Student::~Student()
{

}

void Student::writeToFile(fstream &out) const
{
    Personal::writeToFile(out);
    out.write(major,majorLen);

}

void Student::readFromFile(fstream &in)
{
    Personal::readFromFile(in);
    in.read(major,majorLen);

}

ostream &Student::writeLegibly(ostream &out)
{
    Personal::writeLegibly(out);
    major[majorLen]='\0';
    out<<",major:="<<major;
    return out;

}

istream &Student::readFromConsole(istream &in)
{
    Personal::readFromConsole(in);
    major[majorLen]='\0';
    cout<<"major:"<<endl;
    char s[90];
    in.getline(s,90);
    strncpy(major,s,9);
    return in;

}

