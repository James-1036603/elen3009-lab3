#ifndef DATE_H
#define DATE_H
// date.h
// class Date declaration

#include <cassert>
#include <iostream>
using namespace std;
class DateNotValid {};



enum class Month 
{
	January = 1, 
	February,
	March, 
	April,
	May,
	June,
	July, 
	August, 
	September,
	October,
	November, 
	December
};
	
class Date
{
public:
	//Default Constructor
	Date();	
	//Constructor for date
	Date(const int& day, const Month& month, const int& year);
	// return the day of the month
	int	day () const;
	// return the month of the year
	Month month () const;
	// return the year
	int year () const;
	// return true if it is a leap-year, false if not
	bool isLeapYear () const;	
	//Operaor overload
	bool operator==(const Date& rhs) const;
	//Find next date
	Date FindNextDate();
	//Set default date
	static void setDefaultDate(const int& day,const Month& month,const int& year);

private:
	// return the number of days in the _month
	int	daysInMonth () const;	
	
	int	_day;
	Month _month;
	int	_year;
	//Date to number
	int DateToNumberOfDays() const;
	//Number to date
	Date NumberToDate(const int& number);	
	//Stastic Default date
	static Date _default;

};

// standalone function for printing the date
void printDate(const Date& date);
#endif
