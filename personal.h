#ifndef PERSONAL_H
#define PERSONAL_H
#include<fstream>
#include<cstring>
#include<iostream>
using namespace std;

class Personal
{

    friend ostream&operator<<(ostream&out,Personal&p);     //输出Personal
    friend istream&operator>>(istream&in,Personal&p);      //输入Personal
public:
    Personal();
    Personal(char*ssn,char*n,char*c,int y,long s);
    ~Personal();

    void writeToFile(fstream&out)const;                     //将数据成员以二进制的形式写入文件
    void readFromFile(fstream&in);                          //从二进制文件上为数据成员赋值
    void readKey();                                         //从键盘输入SSN号码

    int size()const;                                        //返回所有数据成员的字节数之和
    bool operator==(const Personal&p)const;                 //重载==用于比较Personal对象的社会安全号码SSN是否相等


protected:
    ostream& writeLegibly(ostream& out);                    //将数据成员信息打印到控制台窗口
    istream& readFromConsole(istream& in);                  //从控制台窗口为数据成员赋值

    const int nameLen,cityLen;                              //姓名和城市名的长度
    char SSN[10],*name,*city;                               //社会安全号码，姓名，城市
    int year;                                               //出生年份
    long salary;                                            //薪水


};

#endif // PERSONAL_H
