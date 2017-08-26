#include "date.h"
//#include <iostream>
using namespace std;
int main(){
	  Date myDate(30,Month::April, 1996);
        printDate(myDate);
        myDate = myDate.FindNextDate();
        printDate(myDate);
}
