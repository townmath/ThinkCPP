#include <iostream>
using std::cout;
using std::endl;
#include "time.h" //include it here too

//this file is where the function definitions go
void printTime (const Time& time) {
  cout << time.hour << ":" << time.minute << ":" << time.second << endl;
}

bool after (const Time& time1, const Time& time2) {
  if (time1.hour > time2.hour) return true;
  if (time1.hour < time2.hour) return false;

  if (time1.minute > time2.minute) return true;
  if (time1.minute < time2.minute) return false;

  if (time1.second > time2.second) return true;
  return false;
}

void increment (Time& time, double secs) {
  time.second += secs;

  if (time.second >= 60.0) {
    time.second -= 60.0;
    time.minute += 1;
  }
  if (time.minute >= 60) {
    time.minute -= 60;
    time.hour += 1;
  }
}

double convertToSeconds (const Time& time) {
  int minutes = time.hour * 60 + time.minute;
  double seconds = minutes * 60 + time.second;
  return seconds;
}

Time makeTime (double secs) {
  Time time;
  time.hour = (int) (secs / 3600.0);
  secs -= time.hour * 3600.0;
  time.minute = (int) (secs / 60.0);
  secs -= time.minute * 60;
  time.second = secs;
  return time;
}

Time addTime (const Time& t1, const Time& t2) {
  double seconds = convertToSeconds (t1) + convertToSeconds (t2);
  return makeTime (seconds);
}
