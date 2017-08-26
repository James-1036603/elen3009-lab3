#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Exercise 2.1
// Comment out this test after inspecting the output.
// Tests which require manual verification should not be lumped
// with tests which are automatically verified!

//TEST_CASE("Date has uninitialised state") {	 
    // make some prior memory allocations - which will be the case in a typical program
//    auto i = {1.0,1.3,1.4,1.5,1.6,1.7,1.8,1.9,10.2,11.0,1.2,1.3,1.23};
//    auto i2 = 1.0;
//    
//    Date today;	
//    std::cout << "Today is: " << endl;
//    printDate(today);
//}

// Write code to make this test pass
TEST_CASE("Valid Date is initialised correctly") {
	Date heritage_day{24, Month::September, 2000};
	CHECK(heritage_day.day() == 24);
	CHECK(heritage_day.month() == Month::September);
	CHECK(heritage_day.year() == 2000);
}


// Exercise 2.2
// Supply additional tests for the constructor here, which
// verify that an exception is thrown when an attempt is made
// to construct an invalid date. Think carefully about which
// invalid dates to test.
TEST_CASE("Invalid Date- too many days in month"){
	CHECK_THROWS_AS(Date testDate(30, Month::February, 2000), DateNotValid);
}

TEST_CASE("Check date is valid"){
	CHECK_NOTHROW(Date testDate(04, Month::April, 2012));
}

// Exercise 2.3
TEST_CASE("Identical Dates are Equal") {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::January, 2000);

    CHECK(date_1 == date_2);
}

// Supply at least three additional tests for
// the equality operator here, to ensure that
// it is working correctly.
TEST_CASE("Unidentical Dates are not equal"){
	Date date_1(1, Month::January, 2000);
	Date date_2(4, Month::April, 2012);
	CHECK_FALSE(date_1==date_2);
}

TEST_CASE("Dates with unidentical years are not equal"){
	Date date_1(1, Month::January, 2001);
	Date date_2(1, Month::January, 2000);
	CHECK_FALSE(date_1==date_2);
}

TEST_CASE("Dates with unidentical months are not equal"){
	Date date_1(1, Month::January, 2000);
        Date date_2(1, Month::April, 2000);
        CHECK_FALSE(date_1==date_2);
}

TEST_CASE("Dates with unidentical days are not equal"){
	Date date_1(1, Month::January, 2000);
        Date date_2(2, Month::January, 2000);
        CHECK_FALSE(date_1==date_2);
}

// Exercise 2.4
// Provide tests for a new member function of the Date class
// which will increase the date by one day.
TEST_CASE("Date increases by one day"){
	Date date_1(6, Month::May, 2007);
	Date date_2(7, Month::May, 2007);
	date_1 = date_1.FindNextDate();
	CHECK(date_1==date_2);
}
TEST_CASE("Check that the month changes when getting the next date"){
	Date date_1(31, Month::May, 2007);
        Date date_2(1, Month::June, 2007);
        date_1 = date_1.FindNextDate();
        CHECK(date_1==date_2);
}
TEST_CASE("Check that the year increases when getting the next date"){
	Date date_1(31, Month::December, 2007);
        Date date_2(1, Month::January, 2008);
        date_1 = date_1.FindNextDate();
        CHECK(date_1==date_2);
}


// Exercise 2.5
// Write tests for the new default constructor and the
// setDefaultDate method.
