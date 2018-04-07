#ifndef DATABASE_H
#define DATABASE_H
#include"personal.h"
#include"student.h"
template<class T>
class Database
{
    friend ostream&operator <<(ostream&out,Database&db)
    {
        return db.print(out);
    }

public:
    Database();
    ~Database();

    void run();
private:
    fstream database;
    char fName[20];
    void add(T&d);
    void modify(const T&d);
    bool find(const T&d);
    ostream &print(ostream&out);
};



template<class T>
Database<T>::Database()
{

}
template<class T>
Database<T>::~Database()
{

}
template<class T>
void Database<T>::run()
{
    cout<<"fileName:";
    cin>>fName;
    char option[5];
    T rec;
    cout<<"1.add,2.find,3.modify a record,4.exit\n";
    cout<<"Enter an option:";
    cin.getline(option,4);
    while(cin.getline(option,4))
    {
        if(*option=='1')
        {
            cin>>rec;
            add (rec);
        }
        else if(*option=='2')
        {
            rec.readKey();
            cout<<"the record is:";
            if(find(rec)==false)
            {
                cout<<"not";
            }
            cout<<"in the database"<<endl;

        }
        else if(*option=='3')
        {
            rec.readKey();
            modify(rec);
        }
        else if(*option=='4')
        {
            return;
        }
        else
        {
            cout<<"wrong option"<<endl;
        }
        cout<<*this;
        cout<<"Enter an option:";

    }

}
template<class T>
void Database<T>::add(T &d)
{
    database.open(fName,ios::in|ios::out|ios::binary);
    if(!database)
    {
        cout<<"file address is wrong in add()"<<endl;
    }
    database.seekp(0,ios::end);
    d.writeToFile(database);
    database.close();

}
template<class T>
void Database<T>::modify(const T &d)
{
    T temp;
    database.open(fName,ios::in|ios::out|ios::binary);
    if(!database)
    {
        cout<<"file address is wrong in modify()"<<endl;
    }

    while(!database.eof())
    {
        temp.readFromFile(database);
        if(temp==d)
        {
            cin>>temp;
            database.seekp(-d.size(),ios::cur);
            temp.writeToFile(database);
            database.close();
            return;
        }


    }
    database.close();
    cout<<"the record to be modified is not in the database\n";

}
template<class T>
bool Database<T>::find(const T &d)
{
    T temp;
    database.open(fName,ios::in|ios::out|ios::binary);
    if(!database)
    {
        cout<<"file address is wrong in find()"<<endl;
    }

    while(!database.eof())
    {
        temp.readFromFile(database);
        if(temp==d)
        {
            database.close();
            return true;
        }
    }
    database.close();
    return false;

}
template<class T>
ostream &Database<T>::print(ostream &out)
{
    T temp;
    database.open(fName,ios::in|ios::out|ios::binary);
    if(!database)
    {
        cout<<"file address is wrong in print()"<<endl;
    }
    while(true)
    {
        temp.readFromFile(database);
        if(database.eof())
        {
            break;
        }
        cout<<temp<<endl;
    }
    database.close();
    return out;
}

#endif // DATABASE_H
