#include <iostream>
#include <string.h>
#define true 1
#define false 0
typedef int BOOL;
using namespace std;

class Date
{
private:
    
    int month, day, year, year1;
    string month1[12] ={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "Novemeber", "December"};
    
    
public:
    
    //Putting the constructor
    Date(int m = 12, /*string m1= "December"*/ int d = 25, int y= 2010)
    {
        // Checking for the valid input for the month
        if ( m < 1 || m > 12)
        {
        cout << "Error, month can only be between 1-12! \n";
        cout << "Terminating program\n";
            exit(EXIT_FAILURE);
        }
        
        // Checking the valid input for the day
        if ( d < 1 || d > 31 )
        {
            cout << "Error ,day can only be between 1-31! \n";
            cout <<"Terminating program\n";
            exit(EXIT_FAILURE);
        }
        
        month = m = 12;
        day = d = 25;
        year = y = 2010;
    };
    
    //Adding the getter functions
    
    int getMonth()
    {
        return month;
    }
    
    int getDay()
    {
        return day;
    }
    
    int getYear()
    {
        return year;
    }
    
    // Checking for valid input for month
    
    void setMonth(int m)
    {
        if (m < 1 || m > 12) {
            cout << "Error, month can only be between 1-12!\n";
            cout << "Now terminating!\n";
            exit(EXIT_FAILURE);
        }
        else
        {
            month = m;
        }
    }
    
    // Checking for valid input for day
    
    void setDay(int d)
    {
        if(d<1 || d>31)
        {
            cout << "Error, day can only be between 1 and 31!";
            cout << "Now terminating!\n";
            exit(EXIT_FAILURE);
        }
        else
        {
            day = d;
        }
    }
    
    void setYear(int y)
    {
        year = y;
    }
    
    // Printing out the functions
    
    void format()
    {
        cout << month << " / " << day << " / " << (year %100);
        cout << endl;
    }
    
    void format1()
    {
        // Indexing of month names which is m1 array
        // As it starts from 0
        cout << month1[month-1] << " ";
        cout << day <<", " << year;
        cout << endl;
    }
    
    void format2()
    {
        // Indexing of month names which is m1 varray
        //As it starts frin 9
        cout << day << " " << month1[month-1];
        cout << " " << year;
        cout << endl;
        
    }
    
    //Function to accept data from console
    void input()
    {
        cout << "Please enter the day: " << endl;
        cin >> day;
        cout << "Please enter the month: " << endl;
        cin >> month;
        cout << "Please enter your year: " << endl;
        cin >> year;
        
        
    };
    
    void display()
    {
        cout << day << " / " << month << " / " << year << "\n" << endl;
        cout << day << " / " << month1 << " / " << year << "\n" << endl;
    };
    
    void operator ++()
    {
        if(day > 31)
        ++month;
    }
    
    //function to validate the date that is entered
    bool validatedate()
    {
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((this->year%400==0 && this->year%100!=0)|| (this->year%4==0))
            months[1]=29;
        if(!(this->day>0 && this->day<=months[month-1]))
            return false;
        if(!(this->month>=1 && this->month<=12))
            return false;
        if(!(this->year>100 && this->year<9999))
            return false;
        else
            return true;
    }
    
    void addDay()
    {
        int DaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        bool flag;
        int theDays;
        cout << "Enter how many days to be added" << endl;
        cin >> theDays;
        
        if((this->year%400==0 && this->year%100!=0)||(this->year%4==0))
            DaysInMonth[1]=29;
        int tempDays=this->day;
        tempDays += theDays;
        
        do
        {
            flag = false;
            if(tempDays>DaysInMonth[this->month-1])
            {
                tempDays-=DaysInMonth[this->month-1];
                this->month++;
                flag = true;
            }
            if(this->month > 12)
            {
                this->month=1;
                this->year++;
            }
        }
    
        while(flag);
            {
                this->day =tempDays;
            }
    };

};

int main()
{
    Date object1;
    
    Date object2(12, 25, 2010);
    
    object1.format();
    object1.format1();
    object1.format2();
    cout << endl;
    
    return 0;
};
