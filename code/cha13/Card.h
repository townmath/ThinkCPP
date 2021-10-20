#include <iostream>
#include <vector>
using namespace std;

struct Card
{
  int suit, rank;

  Card ();
  Card (int s, int r);

  void print () const;
  bool equals (const Card& c2) const;
  bool isGreater (const Card& c2) const;
  int find (const vector<Card>& deck) const;
};
