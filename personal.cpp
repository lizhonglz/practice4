#include "personal.h"
//friend function of Personal*****************************************************
//********************************************************************************
ostream &operator<<(ostream &out, Personal &p)
{
    return p.writeLegibly(out);
}
istream &operator>>(istream &in, Personal &p)
{
    return p.readFromConsole(in);
}


//Personal:************************************************************************
//*********************************************************************************
Personal::Personal()
    :nameLen(10),cityLen(10)
{
    name=new char[nameLen+1];
    city=new char[nameLen+1];

}
Personal::Personal(char *ssn, char *n, char *c, int y, long s)
    :nameLen(10),cityLen(10)
{
    name=new char[nameLen+1];
    city=new char[cityLen+1];
    strcpy(name,n);
    strcpy(SSN,ssn);
    strcpy(city,c);
    year=y;
    salary=s;

}
Personal::~Personal()
{

}


void Personal::writeToFile(fstream &out) const
{
    out.write(SSN,9);
    out.write(name,nameLen);
    out.write(city,cityLen);
    out.write(reinterpret_cast<const char*>(&year),sizeof(int));
    out.write(reinterpret_cast<const char*>(&salary),sizeof(long));


}
void Personal::readFromFile(fstream &in)
{
    in.read(SSN,9);
    in.read(name,nameLen);
    in.read(city,cityLen);
    in.read(reinterpret_cast<char*>(&year),sizeof(int));
    in.read(reinterpret_cast<char*>(&salary),sizeof(long));

}
void Personal::readKey()
{
    char s[90];
    cout<<"Enter key:"<<endl;
    cin.getline(s,90);
    strncpy(SSN,s,9);

}

int Personal::size() const
{
    return 9+nameLen+cityLen+sizeof(year)+sizeof(salary);

}

bool Personal::operator==(const Personal &p) const
{
    return strncmp(SSN,p.SSN,9);

}
ostream &Personal::writeLegibly(ostream &out)
{
    SSN[9]=name[nameLen]=city[cityLen]='\0';
    out<<"SSN= "<<SSN<<", name= "<<name
        <<",city= "<<city<<",year= "<<year
        <<", salary= "<<salary;
    return out;

}
istream &Personal::readFromConsole(istream &in)
{
    SSN[9]=name[nameLen]=city[cityLen]='\0';
    char s[90];
    cout<<"SSN:"<<endl;
    in.getline(s,90);
    strncpy(SSN,s,9);
    cout<<"name:"<<endl;
    in.getline(s,90);
    strncpy(name,s,nameLen);
    cout<<"city:"<<endl;
    in.getline(s,90);
    strncpy(city,s,cityLen);
    cout<<"birthyear:";
    in>>year;
    cout<<"salary:";
    in>>salary;
    in.ignore();
    return in;


}

