#include "lib.h"

using namespace ham;
int main()
{
    fstream file;
    file.open("file.txt",std::ios::out);
    vector<ham::DayofYearSet::DayOfYear> vec_day1;
    vec_day1.push_back(DayofYearSet::DayOfYear(7,4));
    vec_day1.push_back(DayofYearSet::DayOfYear(3,3));
    vec_day1.push_back(DayofYearSet::DayOfYear(4,4));
    vec_day1.push_back(DayofYearSet::DayOfYear(5,5));
    vec_day1.push_back(DayofYearSet::DayOfYear(6,6));
    vec_day1.push_back(DayofYearSet::DayOfYear(7,8));
    DayofYearSet obj1(vec_day1);
    cout<<"obj1's output"<<" Size of obj1 is "<<obj1.get_day_size()<<endl<<endl;
    cout<<obj1<<endl;
    file<<"outputs of obj1's opeartor<< "<<"and it's size is "<<obj1.get_day_size()<<endl;
    DayofYearSet:: savefile(file,obj1);
    vector<ham::DayofYearSet::DayOfYear> vec_day2;
    vec_day2.push_back(DayofYearSet::DayOfYear(1,1));
    vec_day2.push_back(DayofYearSet::DayOfYear(2,2));
    vec_day2.push_back(DayofYearSet::DayOfYear(4,8));
    vec_day2.push_back(DayofYearSet::DayOfYear(5,8));
    vec_day2.push_back(DayofYearSet::DayOfYear(6,8));
    vec_day2.push_back(DayofYearSet::DayOfYear(7,8));
    DayofYearSet obj2(vec_day2);
    cout<<"obj2's output"<<" Size of obj1 is "<<obj1.get_day_size()<<endl<<endl;
    cout<<obj2<<endl;
    file<<endl<<"outputs of obj2's opeartor<< "<<"and it's size is "<<obj2.get_day_size()<<endl;
    DayofYearSet:: savefile(file,obj2);
    if(obj1==obj2)
    {
        cout<<"objects are equal "<<endl;
        file<<endl<<"objects are equal"<<endl;
    }
    else if(obj1!=obj2)
    {
        cout<<"objects are not equal "<<endl;
        file<<endl<<"objects are not equal"<<endl;
    }
    DayofYearSet obj3=obj1+obj2;
    cout<<"Testing of DayofYearSet operator+ function"<<endl;
    cout<<obj3<<endl;
    file<<endl<<"Testing of DayofYearSet operator+ function"<<endl<<obj3<<endl;
    
    cout<<obj3.get_day_size()<<"---------------------- "<<obj2.get_day_size()<<endl;
    DayofYearSet obj4=obj2-obj1;
    cout<<"Testing of DayofYearSet operator- function for obj4"<<endl;
    cout<<obj4<<endl;
    file<<endl<<"Testing of DayofYearSet operator- function"<<endl<<obj4<<endl;
    DayofYearSet obj5=obj1^obj2;
    cout<<"Testing of operation^ function for obj5"<<endl<<obj5<<endl;
    file<<"Testing of operation^ "<<endl<<obj5<<endl;
    cout<<"DEMORGAN"<<endl;
    cout<< "Morgan says that !(object1 + object2) == !object1 ^ !object2\nChecking De Morgan Law:\n";
    if(!(obj1+obj2)==((!obj1 )^ (!obj2)))   cout << " == TRUE\n\n";

    file << "Morgan says that !(object1 + object2) == !object1 ^ !object2\nChecking De Morgan Law:\n";
    if(!(obj4+obj5)==((!obj4 )^ (!obj5))) file << " == TRUE\n\n";
    for(int i=0;i<obj1.get_day_size();i++)
        cout<<obj1[i]<<endl;
    
}