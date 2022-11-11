#include "lib.h"

namespace ham
{
    /*INNER CLASS DEFINITIONS*/
    DayofYearSet::DayOfYear::DayOfYear()
                            :month(1),day(1)
    { }
    DayofYearSet::DayOfYear::DayOfYear(int month_,int day_)
    { 
        if((month_>=0&&month_<13)&&(day_>=0&&day_<32))
        {
            set_day(day_);
            set_month(month_);
        }
        else
            cout<<"Invalid Date !! try again ..."<<endl;
    }

    bool DayofYearSet::DayOfYear::operator==(DayofYearSet::DayOfYear &obj1)
    {
        if((get_month()==obj1.get_month())&&(get_day()==obj1.get_day()))    
            return true;
        return false;
    }
    bool DayofYearSet::DayOfYear::operator!=(DayofYearSet::DayOfYear &obj1)
    {
        if(*this==obj1)    
            return false;
        return true;
    }
    void DayofYearSet::DayOfYear::set_day(int _day)
    {
        day=_day;
    }
    void DayofYearSet::DayOfYear::set_month(int _month)
    {
        month=_month;
    }
    ostream & operator<<(ostream &outputstream,const DayofYearSet::DayOfYear  & object )
    {
        outputstream<<" Month Number is : ";
        outputstream<<object.get_month()<<endl;
        outputstream<<" Day Number is : ";
        outputstream<<object.get_day()<<endl;
        return outputstream;
    }

    DayofYearSet:: DayOfYear & DayofYearSet::DayOfYear:: operator =(DayOfYear & other_to_assign)
    {
        set_day(other_to_assign.get_day());
        set_month(other_to_assign.get_month());
        return *this;
    }
                    /*CLASS DEFINITIONS*/
    DayofYearSet:: DayofYearSet(DayOfYear *day_arr_,int size)
    {
        set_day_array(day_arr_);
        set_day_size(size);
    }
    DayofYearSet:: DayofYearSet(vector<DayofYearSet::DayOfYear> vec_dayofyear)
    {
        DayofYearSet::DayOfYear *temp;
        temp= new DayofYearSet::DayOfYear[vec_dayofyear.size()];
        for(auto x=0;x<vec_dayofyear.size();x++)
            temp[x]=vec_dayofyear.at(x);
        day_arr=temp;
        day_arr_size=vec_dayofyear.size();
    }
    DayofYearSet:: DayofYearSet()
    {
        day_arr=nullptr;
        day_arr_size=0; 
    }
    bool DayofYearSet:: add( DayofYearSet:: DayOfYear &obj)  
    {
        DayofYearSet::DayOfYear *temp2=get_day_array();
        int i;
        for( i=0;i<day_arr_size;i++)
            if(temp2[i]==obj)
                return false;
        DayofYearSet::DayOfYear *temp=new DayOfYear[get_day_size()+1];
        for(i=0;i<get_day_size();i++)
            temp[i]=temp2[i];
        temp[i]=obj;
        delete []get_day_array();
        set_day_array(temp);
        set_day_size(get_day_size()+1);
        return true;
    }
    bool DayofYearSet::remove( DayofYearSet:: DayOfYear &obj)
    {
        //cout<<"3.kontrol"<<endl;
        DayOfYear *temp=get_day_array();
        int i=0;
        for (i=0;i<get_day_size();i++)
        {
            if(temp[i]==obj)
            {
                DayOfYear *temp2= new DayOfYear [get_day_size()-1];
                int count=0;
                for(int j=0;j<get_day_size();j++)
                {
                    if(j!=i)
                    {
                        temp2[count]=temp[j];
                        count++;
                    }
                }
                delete []get_day_array();
                day_arr = temp2;
                day_arr_size=count;
                return true;
            }
        }
        return false;
    }
    const bool DayofYearSet::search(DayofYearSet::DayOfYear &obj) const 
    {
        for(int i=0;i<get_day_size();i++)
        {
            if(day_arr[i]==obj)
                return true;
        }
        return false;
    }
    bool operator==( const DayofYearSet &obj1, const DayofYearSet &obj2)
    {
        if(obj1.get_day_size()!=obj2.get_day_size())
            return false;
        bool check=false;
        for(int i=0;i<obj1.get_day_size();i++)
        {
            for(int k=0;k<obj1.get_day_size();k++)
            {
                if(obj1.get_day_array()[i]==obj2.get_day_array()[k])
                {
                    check=true;
                    break;
                }
            }
            if(check==false)
            {
                return false;
            }
        }
        return true;
    }     
    bool operator!=(const DayofYearSet &obj1,const DayofYearSet &obj2)
    {
        if(obj1==obj2)
            return false;
        return true;
    }  
    ostream& operator<<(ostream&outputstream, const DayofYearSet &obj)
    {
        for(int i=0;i<obj.get_day_size();i++)
            outputstream<<obj.get_day_array()[i]<<endl;
        return outputstream;
    }
    const DayofYearSet operator+(const DayofYearSet &obj1, const DayofYearSet &obj2)
    {
        int obj1_size=obj1.get_day_size(),obj2_size=obj2.get_day_size();
        DayofYearSet temp;
        for(int i=0;i<obj1_size;i++)
            temp.add(obj1.get_day_array()[i]);
        //cout<<"*****************"<<endl<<temp<<"***********"<<endl;
        for(int i=0;i<obj2_size;i++)
        {
            if(obj2.search(obj1.get_day_array()[i])==false)
            {
                temp.add(obj2.get_day_array()[i]);
         //       cout<<"aaaaaaaaaaaaaaaaaaaaaaa"<<endl;
            }
        }

        return DayofYearSet(temp.get_day_array(),temp.get_day_size());
    }
    const DayofYearSet operator-(const DayofYearSet &obj1,  const DayofYearSet &obj2)
    {
        //cout<<"1.kontrol"<<endl;
        int obj1_size=obj1.get_day_size(),obj2_size=obj2.get_day_size();
        //cout<<" "<<obj1_size<<" "<<obj2_size<<endl;
        DayofYearSet temp;
        for(int i=0;i<obj1_size;i++)
            temp.add(obj1.get_day_array()[i]);
        for(int i=0;i<obj2_size;i++)
        {
            if(obj1.search(obj2.get_day_array()[i])==true)
            {
               // cout<<"--> "<<obj2.get_day_array()[i]<<endl;
                temp.remove(obj2.get_day_array()[i]);
                //i--;
              //  cout<<"flag"<<endl;
            }
        }
        //cout<<obj1<<endl;
        //cout<<"---------------------------"<<endl;
        //cout<<"2.kontrol"<<endl;
        return DayofYearSet(temp.get_day_array(),temp.get_day_size());
    }
    const DayofYearSet operator^( const DayofYearSet &obj1, const DayofYearSet &obj2)
    {
        DayofYearSet new_temp;
        for(int i=0;i<obj1.get_day_size();i++)
        {
            if(obj1.search(obj2.get_day_array()[i]))
                new_temp.add(obj2.get_day_array()[i]);
        }
    return DayofYearSet(new_temp.get_day_array(),new_temp.get_day_size());
    }
    const DayofYearSet operator!(const  DayofYearSet& object1)
    {
        decltype(365-object1.get_day_size()) size;
        size = 365-object1.get_day_size(); /* Size of new array that will be returned */
        DayofYearSet::DayOfYear* newArr = new DayofYearSet::DayOfYear[size]; /* New array declaration */
        int ct = 0; /* The next index of array that will be assigned */

        int day = 1;
        int month = 1;
        //cout<<object1<<endl;
        while(month<=12)
        {
           // cout<<day<<" " <<month<<endl;
            DayofYearSet::DayOfYear date(month,day);
            bool flag = true; /* Indicates whether the date ,that is generated, is in the object. If it is NOT in the object, flag will be true */
            /* Check whether the date that is generated is in the object */

            for(int i=0;i<object1.get_day_size();i++)
            {
                if(object1.get_day_array()[i]==date) 
                {
                    //cout<<"--> "<<object1.get_day_array()[i]<<endl;
                    flag = false;
                }
            }

            if(flag==true) /* The date that is generated is NOT in the object, add the date to array that will be returned */
            {
                newArr[ct] = date;
                ct++;
            }

            if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) /* If the month has 31 days */
            {
                if(day==31)
                {
                    day = 1;
                    month++;
                }
                else day++;
            }

            else if(month==2) /* If the month is February */
            {
                if(day==28)
                {
                    day = 1;
                    month++;
                }
                else day++;
            }

            else /* If the month has 30 days */
            {
                if(day==30)
                {
                    day = 1;
                    month++;
                }
                else day++;
            }
        }

        return DayofYearSet(newArr, size);
    }
    void DayofYearSet:: savefile(fstream &file,DayofYearSet &obj)
    {
        for(int i=0;i<obj.get_day_size();i++)
            file<<"index number of object "<<i<<" Month : "<<obj[i].get_month()<<" -> Day : "<<obj[i].get_day()<<endl;
        file<<endl<<endl;
    }
    DayofYearSet * DayofYearSet:: operator=( DayofYearSet &other_to_assign)
    {
        //DayofYearSet *temp=new DayofYearSet[1] ;
       for(int i=0;i<other_to_assign.get_day_size();i++) 
        {
            this->add(other_to_assign.get_day_array()[i]);
        }
    return this;
    }


}