#include "Deck.h"
#include "Card.h"

Card::Card () {
  suit = CLUBS;  rank = TWO;
}

Card::Card (Suit s, Rank r) {
  suit = s;  rank = r;
}

string suitToString(Suit suit){
    switch (suit) {
        case CLUBS:  return "Clubs";
        case DIAMONDS:  return "Diamonds";
        case HEARTS:  return "Hearts";
        case SPADES:  return "Spades";
        default:  return "Not a valid suit";
    }
}

void Card::print () const {

  vector<string> ranks (14, "narf");
  ranks[ACE] = "Ace";
  ranks[TWO] = "2";
  ranks[THREE] = "3";
  ranks[FOUR] = "4";
  ranks[FIVE] = "5";
  ranks[SIX] = "6";
  ranks[SEVEN] = "7";
  ranks[EIGHT] = "8";
  ranks[NINE] = "9";
  ranks[TEN] = "10";
  ranks[JACK] = "Jack";
  ranks[QUEEN] = "Queen";
  ranks[KING] = "King";

  cout << ranks[rank] << " of " << suitToString(suit) << endl;
}

bool Card::equals (const Card& c2) const {
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

int Card::find (const Deck& deck) const { //linear search
  for (int i = 0; i < deck.cards.size(); i++) {
    if (equals (deck.cards[i])) return i;
  }
  return -1;
}
