// Implement a class `Date`. This class must meet the following requirements:
// - it has three **private** attributes to represent day, month and year
// - use a scoped enum for month
// - it has the following **public** functions:
// 	- constructor that takes as arguments a day, a month and a year. (Forget about the validation for now)
// 	- `day()` function that returns the day
// 	- `month()` function that returns the month
// 	- `year()` function that returns the year
// 	- `add_days(const unsigned int n)` which adds `n` days. You have to take care to increment months and years accordingly (neglect leap years)

#include <iostream>

enum class en_month
{
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec 
};

class Date 
{
        public:

        //default constructor
        inline Date() noexcept = default;

        //constructor
        Date (int dd, en_month mm, int yy) : d{dd}, m{mm}, y{yy} {};

        //default destructor
        ~Date(){};

        //functions returning the date
        int day() const {return d;}
        en_month month() const {return m;}
        int year() const {return y;}

        Date& add_day(int n);
        Date& add_month(int n);
        Date& add_year (int n);
        
    private:
        int d; //day
        en_month m; //month
        int y; //year
};

Date& Date::add_year (int n)
{
    if(d==29 && m==static_cast<en_month>(2) && ((y+n)%4==0))
    {
        d=1;
        m=static_cast<en_month>(3);
    }
    y += n;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Date& printing)
{
    os << "Here: " << printing.day() << " / " << printing.month() << " / " << printing.year() << "\n";
}


int main()
{
    Date my_bith (13,static_cast<en_month>(1),1996);

    std::cout << my_bith << std::endl;

    return 0;
}