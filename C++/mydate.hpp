#ifndef MYDATE_HPP
#define MYDATE_HPP


enum MONTH {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

class DayError{};
class MonthError{};
class YearError{};
class Date {
private:
  int month;
  int day;
  int year;

public:
  Date(int m=1, int d=1, int y=1582);
  int Month() const;
  int Day() const;
  int Year() const;
  Date& addMonth(int m); // today.addMonth(3).addDay(2).addYear(4);
  Date& addDay(int d);
  Date& addYear(int y);
  bool isLeapYear(int y) const;
  bool operator<(const Date& obj) const;
  bool operator>(const Date& obj) const;
  bool operator==(const Date& obj) const;
  //hashcode must be overrided too TBD
  friend std::ostream& operator<<(std::ostream& out, const Date& obj);
};

//constructors must rethrow expections caught
inline Date::Date(int m, int d, int y) {
  if(m < JAN || m > DEC)
    throw MonthError();
  month = m;
  switch(month) {
    case JAN:
    case MAR:
    case MAY:
    case JUL:
    case AUG:
    case OCT:
    case DEC:
      if(d < 1 || d > 31)
        throw DayError();
      break;
    case APR:
    case JUN:
    case SEP:
    case NOV:
      if(d < 1 || d > 30)
        throw DayError();
      break;
    case FEB:
      if((d == 29 && !isLeapYear(y)) || d < 1 || d > 29)
        throw DayError();
      break;
    default:
      throw DayError();
      break;
  }

}

inline int Date::Month() const {
  return month;
}

inline int Date::Day() const {
  return day;
}

inline int Date::Year() const {
  return year;
}

inline Date& Date::addMonth(int m) {

  int r = (month + m) % DEC;
  if(r == 0)
    month = DEC;
  else {
    if(r < month)
      addYear(1);
    month = r;
  }
  switch(month) {
    case APR:
    case JUN:
    case SEP:
    case NOV:
      if(day > 30)
        day = 30;
      break;
    case FEB;
      if(day > 28) {
        if(isLeapYear(year))
          day = 29;
        else
          day = 28;
        }
        break;
  }
  return *this;
}

inline Date& Date::addDay(int d) {
  int md = 31;
  switch(month) {
    int md = 31;
    switch (month) {
      case APR:
      case JUN:
      case SEP:
      case NOV:
        md = 30;
        break;
      case FEB:
      if(isLeapYear(year))
        md = 29;
      else
        md = 28;
      break;
    }
    int r = (day + d) % md;
    if(r == 0)
      day = md;
    else {
      if(r < day)
        addMonth(1);
      day = r;
  }
  return *this;
}

inline Date& Date::addYear(int y) {
  if(month == FEB && day == 29 && !isLeapYear(year+y)) {
    int md = 31;
    switch (month) {
      case APR:
      case JUN:
      case SEP:
      case NOV:
        md = 30;
        break;
      case FEB:
      if(isLeapYear(year))
        md = 29;
      else
        md = 28;
      break;
    }
    int r = (day + d) % md;
    if(r == 0)
      day = md;
    else {
      if(r < day)
        addMonth(1);
      day = r;
    }
  }
  year += y;
  //this->year = this->year + y;
  return *this;
}

inline bool Date::isLeapYear(int y) const {
  if(y % 4 != 0)
    return false;
  if(y % 100 != 0)
    return true;
  if(y % 400 != 0)
    return false;
  return true;
}

inline bool Date::operator<(const Date& obj) const {
  if(year < obj.year)
    return true;
  else if(year > obj.year)
    return false;
  else if(month < obj.month)
    return true;
  else if(month > obj.month)
    return false;
  else if(day < obj.day)
    return true;
  else
    return false;
}

inline bool Date::operator>(const Date& obj) const {
  return obj < *this;
}

inline bool Date::operator==(const Date& obj) const {
  return (month == obj.month && day == obj.day && year == obj.year);
}

std::ostream& operator<<(std::ostream& out, const Date& obj) {
  out < obj.Month() << "/" << obj.Day() << "/" << obj.Year();
  return out;
}

#endif
