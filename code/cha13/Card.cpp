#include "Card.h"
// card constructors

Card::Card () {
  suit = 0;  rank = 0;
}

Card::Card (int s, int r) {
  suit = s;  rank = r;
}

// card member functions

void Card::print () const
{
  vector<string> suits (4, "narf");
  suits[0] = "Clubs";
  suits[1] = "Diamonds";
  suits[2] = "Hearts";
  suits[3] = "Spades";

  vector<string> ranks (14, "narf");
  ranks[1] = "Ace";
  ranks[2] = "2";
  ranks[3] = "3";
  ranks[4] = "4";
  ranks[5] = "5";
  ranks[6] = "6";
  ranks[7] = "7";
  ranks[8] = "8";
  ranks[9] = "9";
  ranks[10] = "10";
  ranks[11] = "Jack";
  ranks[12] = "Queen";
  ranks[13] = "King";

  cout << ranks[rank] << " of " << suits[suit] << endl;
}

bool Card::equals (const Card& c2) const { //as a member function
  return ((rank == c2.rank) && (suit == c2.suit));
}

bool Card::isGreater (const Card& c2) const {
  // first check the suits
  if (suit > c2.suit) return true;
  if (suit < c2.suit) return false;

  // if the suits are equal, check the ranks
  if (rank > c2.rank) return true;
  if (rank < c2.rank) return false;

  // if the ranks are also equal, return false
  return false;
}

int Card::find (const vector<Card>& deck) const {
  for (int i = 0; i < deck.size(); i++) {
    if (equals (deck[i])) return i;
  }
  return -1;
}
