//just prototypes in the header file
struct Time {
  int hour, minute;
  double second;
};

void printTime (const Time& time);

bool after (const Time& time1, const Time& time2);

void increment (Time& time, double secs);

double convertToSeconds (const Time& time);

Time makeTime (double secs);

Time addTime (const Time& t1, const Time& t2);
