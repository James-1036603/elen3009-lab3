// date.cpp
// Implementation of the Date class

#include "date.h"
Date::Date(const int& day, const Month& month, const int& year): _day{day}, _month{month}, _year{year}
{
	if(_day>Date::daysInMonth() || Date::daysInMonth() == -1) throw DateNotValid();
}

int Date::day() const
{
	return _day;
}

Month Date::month() const
{
    return _month;
}

int Date::year() const
{
	return _year;
}

bool Date::isLeapYear() const
{
    // leap years must be divisible by 4 but not by 100
    // or divisible by 400
    if(((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0))
        return true;
    else
        return false;
}

int Date::daysInMonth() const
{
	switch (_month) {
		case Month::January: 
		case Month::March: 
		case Month::May: 
		case Month::July:
		case Month::August: 
		case Month::October: 
		case Month::December:
			return 31;	
		case Month::April: 
		case Month::June: 
		case Month::September:
		case Month::November:
			return 30;	
		case Month::February:
			if ( isLeapYear() ) return 29;
			else return 28;
		default:
			// should never reach here 
			assert(false); // See: http://www.cplusplus.com/reference/cassert/assert/
            return -1;
	}    
}

// Note, this standalone function is not part of the Date class
void printDate(const Date& date)
{
	cout << date.day() << "/"
		// cast to an integer to allow the month to be sent to the stream
        << static_cast<int>(date.month()) << "/"
		<< date.year()
		<< endl;
}
//Overloaded operator
bool Date::operator==(const Date& rhs) const 
{
	if(_day==rhs._day && _month == rhs._month && _year == rhs._year) return true;
	else return false;
}
//Date to number
//NOTE: Algorithm adapted from http://www.c-jump.com/CIS60/hw3.htm
int Date::DateToNumberOfDays() const {
	int a = (14-static_cast<int>(_month))/12;
	int m = static_cast<int>(_month)+12*a-3;
	int y = _year +4800-a;
	return _day+ (153*m+2)/5+365*y +y/4 -y/100 + y/400 - 32044;
}

Date Date::NumberToDate(const int& number){
	int a = number+32044;
	int b = (4*a +3)/146097;
	int c = a-(146097*b)/4;
	int d = (4*c+3)/1461;
	int e = c-(1461*d)/4;
	int m  = (5*e+2)/153;
	int day = e-(153*m+2)/5 +1;
	int month = m+3 -12*(m/10);
	int year = 100*b + d-4800+ m/10;
	Date tempDate(day,static_cast<Month>(month), year);

	return tempDate;
}



Date Date::FindNextDate(){
	return Date::NumberToDate(Date::DateToNumberOfDays());
}
