#include <iostream>

// functions
bool is_leap(const int y);

// error struct, useful for throwing exceptions
struct no_negative_pls{};


// enum class en_month (check for the best)
enum en_month
{
    jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec 
};


class Date 
{
        public:

        //constructor
        Date (int dd, en_month mm, int yy) : d{dd}, m{mm}, y{yy} {};

        //default destructor
        ~Date() = default;

        //functions returning the date
        int day() const {return d;}
        en_month month() const {return m;}
        int year() const {return y;}

        Date& add_day(const int n);
        Date& add_year (const int n);
        
    private:
        int d; //day
        en_month m; //month
        int y; //year
};

// member funtion
// add a number of day to the current date
Date& Date::add_year (const int n)
{
    if(!(is_leap(y+n)) && (d==29 && m==12)) // m == static_cast<en_month>(2)
    {
        d=1;
        m=static_cast<en_month>(3);
    }
    
    y += n;
    return *this;
}

// member funtion
// add a number of day to the current date
// p.s. it works for every number
Date& Date::add_day(int n)
{
    if (n < 0) throw no_negative_pls{};
    unsigned int j;
    while(n > 0)
    {
        switch (m)
        {
        case en_month::jan: case en_month::mar: case en_month::may: 
        case en_month::jul: case en_month::aug: 
        case en_month::oct: case en_month::dec:
            
            n > 31 ? j = 31 : j = n;

            if((d + j) > 31)
            {
                d = d + j - 31;

                if(m == 12) // m == static_cast<en_month>(12)
                {
                    y++;
                    m = static_cast<en_month>(1);
                }
                else
                {
                    m = static_cast<en_month>(m+1);
                //    m = static_cast<en_month>(static_cast<int>(m)+1);
                }
            }
            else
            {
                d += j;
            }
            n = n - 31;
        break;

        case en_month::apr: case en_month::jun: 
        case en_month::sep: case en_month::nov:

            n > 30 ? j = 30 : j = n;

            if((d + j) > 30)
            {
                d = d + j - 30;
                m = static_cast<en_month>(m+1);
            //    m = static_cast<en_month>(static_cast<int>(m)+1);
            }
            else
            {
                d += j;
            }
            n = n - 30;
        break;

        case en_month::feb:
            if(is_leap(y))
            {
                n > 29 ? j = 29 : j = n;
                
                if ((d + j) > 29)
                {
                    d = d + j - 29;
                    m = static_cast<en_month>(m+1);
                //    m = static_cast<en_month>(static_cast<int>(m)+1);
                }
                else
                {
                    d += j;
                }
                n = n - 29;
            }
            else
            {
                n > 28 ? j = 28 : j = n;
                
                if ((d + j) > 28)
                {
                    d = d + j - 28;
                    m = static_cast<en_month>(m+1);
                //    m = static_cast<en_month>(static_cast<int>(m)+1);
                }
                else
                {
                    d += j;
                }
                n = n - 28;
            }
        break;  
        }
    }
    return *this;
}

// non- member function
// check if the year is leap, returning true if it is
bool is_leap(const int y)
{
    bool flag = false;
    if(y%4 == 0 && (y%100 != 0 || y%400 == 0))
        flag = true;

    return flag;
}

// non- member function
// overloading ostream operator
std::ostream& operator<<(std::ostream& os, const Date& printing)
{
    os << printing.day() << " - "; 
    switch (printing.month())
    {
        case en_month::jan: os << "jan"; break;
        case en_month::feb: os << "feb"; break;
        case en_month::mar: os << "mar"; break; 
        case en_month::apr: os << "apr"; break;
        case en_month::may: os << "may"; break;
        case en_month::jun: os << "jun"; break;
        case en_month::jul: os << "jul"; break;
        case en_month::aug: os << "aug"; break;
        case en_month::sep: os << "sep"; break;
        case en_month::oct: os << "oct"; break;
        case en_month::nov: os << "nov"; break;
        case en_month::dec: os << "dec"; break;
    }
    os << " - " << printing.year() << "\n";
    
    return os;
}

// non- member function
// overloading == operator
bool operator==(const Date& lhs, const Date& rhs)
{
    bool flag;
    bool op = ((lhs.day() == rhs.day()) && (lhs.month() == rhs.month()) && (lhs.year() == rhs.year()));
    op ? flag = true : flag = false;
    return flag;
}

// non- member function
// overloading != operator
bool operator!=(const Date& lhs, const Date& rhs)
{
    bool flag;
    bool op = ((lhs.day() == rhs.day()) && (lhs.month() == rhs.month()) && (lhs.year() == rhs.year()));
    op ? flag = false : flag = true;
    return flag;
}


int main()
{
    Date my_bith (29,static_cast<en_month>(2),2100);
    Date check (29,static_cast<en_month>(2),2100);
    if (my_bith==check)
    {
        std::cout << my_bith << std::endl;
    }
    my_bith = my_bith.add_year(5);
    std::cout << my_bith << std::endl;
    my_bith = my_bith.add_day(2);
    std::cout << my_bith << std::endl;
    my_bith = my_bith.add_day(31);
    std::cout << my_bith << std::endl;
    if (my_bith==check)
    {
        std::cout << my_bith << std::endl;
    }
    my_bith = my_bith.add_day(100000);
    std::cout << my_bith << std::endl;
    my_bith = my_bith.add_day(0);
    if (my_bith!=check)
    {
        std::cout << my_bith << std::endl;
    }
    my_bith = my_bith.add_day(-1);
    std::cout << my_bith << std::endl;

    


    return 0;
}