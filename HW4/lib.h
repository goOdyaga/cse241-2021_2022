#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<fstream>

using namespace std;
namespace ham
{
    class DayofYearSet
    {
        public:
            class DayOfYear
            {
                public:
                    DayOfYear();/*constructor for cretan abj that date is 1 JAN*/
                    DayOfYear(int month_,int day_);
                    void set_month(int _month);
                    void set_day(int _day);
                    inline const int get_month()const{ return month;};
                    inline const int get_day()const{ return day;};
                    bool operator==(DayOfYear &obj1);
                    bool operator!=(DayOfYear &obj1);
                    friend ostream & operator<<(ostream &outputstream,const DayofYearSet::DayOfYear  & object );
                    DayOfYear & operator =(DayOfYear & other_to_assign);

                private:
                    int month;
                    int day;
            };
            DayofYearSet(vector<DayOfYear> vec_dayofyear);
            DayofYearSet(DayOfYear *day_arr_,int size);
            DayofYearSet();
            //~DayOfYearSet(); 
            DayofYearSet(const DayofYearSet &obj);
            
            bool add( DayOfYear &obj) ;
            bool remove( DayofYearSet:: DayOfYear &obj) ;
            bool const search(DayOfYear &obj) const;

            inline int get_day_size() const{ return day_arr_size;};
            inline void set_day_size(int i){ day_arr_size=i; };
            inline DayOfYear * get_day_array() const{ return day_arr;};
            inline void set_day_array( DayOfYear *temp){ day_arr=temp;};
            friend ostream& operator<<(ostream&outputstream,const DayofYearSet &obj);
            friend const DayofYearSet operator+(  const DayofYearSet &obj1,const   DayofYearSet &obj2);
            friend const DayofYearSet operator-( const  DayofYearSet &obj1, const  DayofYearSet &obj2);
            friend const DayofYearSet operator^( const  DayofYearSet &obj1, const DayofYearSet &obj2);
            friend const DayofYearSet operator!( const  DayofYearSet &obj1);
            DayofYearSet *operator=( DayofYearSet &other_to_assign);
            friend  bool operator==(const DayofYearSet &obj1,const DayofYearSet &obj2);
            friend  bool operator!=(const DayofYearSet &obj1,const DayofYearSet &obj2);
            inline  DayofYearSet::DayOfYear operator[](int size){return get_day_array()[size];};
            static void savefile(fstream &file,DayofYearSet &obj);
        private:
            DayOfYear *day_arr;
            int day_arr_size;
    };          

}

