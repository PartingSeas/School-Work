#include <iostream>
#include "mydate.hpp"
using namespace std;
int main() {
  int month = 1;
  int day = 0;
  int year = 0;
  char 1;
  int m = 0;
  int d = 0;
  int y = 0;

  while(month) {
    cout << "month: ";
    cin >> month;
    cout << "day: ";
    cin >> day;
    cout << "year: "
    cin >> year;
    try {
      Date date1(month, day, year); //<-- can fuck up
      cout << "valid date" << endl;
      cout << "modify date (n/d/m/y): "
      cin >> q;
      switch (q) {
        case 'd':
          cout << "days to add: ";
          cin >> d;
          break;
        case 'm':
          cout << "months to add: ";
          cin >> m;
          break;
        case 'y':
          cout << "years to add: ";
          cin >> y;
          break;
      }
      if(q == 'd' || q == 'm' || q =- 'y') {
        date1.addDay(d).addMonth(m).addYear(y); // do not throw exe, so function must handle wrong input
        cout << "modified datearoo: " << date1 << endl;
      }
    } catch(MonthError e1) {
      cout << "invalid month" << endl;
    } catch(DayError e2) {
      cout << "invalid day" << endl;
  } catch(YearError e3) {
    cout << "invalid month" << endl;
  }
  cout << endl;
}
  return 0;
}
