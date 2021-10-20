#include "Deck.h"
#include "Card.h"

Deck::Deck(int n) {
  vector<Card> temp (n);
  cards = temp;
}

Deck::Deck() {
  vector<Card> temp (52);
  cards = temp;

  int i = 0;
  for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit+1)) {
    for (Rank rank = ACE; rank <= KING; rank = Rank(rank+1)) {
      cards[i].suit = suit;
      cards[i].rank = rank;
      i++;
    }
  }
}

void Deck::print () const {
  for (int i = 0; i < cards.size(); i++) {
    cards[i].print ();
  }
}

int Deck::find (const Card& card) const { //linear search
  for (int i = 0; i < cards.size(); i++) {
    if (card.equals (cards[i])) return i;
  }
  return -1;
}

void Deck::swapCards (int i, int j)
{
  Card temp = cards[i];
  cards[i] = cards[j];
  cards[j] = temp;
}

int randomInt (int low, int high)
{
  return low + rand() % (high-low+1);
}

void Deck::shuffle ()
{
  for (int i=0; i<cards.size(); i++) {
    int j = randomInt (i, 51);
    swapCards (i, j);
  }
}

int Deck::findLowestCard (int low, int high) const
{
  int mindex = low;

  for (int i=low+1; i<=high; i++) {
    if (cards[mindex].isGreater (cards[i])) {
      mindex = i;
    }
  }
  return mindex;
}

void Deck::sort ()
{
  for (int i=0; i<cards.size(); i++) {
    int j = findLowestCard (i, 51);
    swapCards (i, j);
  }
}

Deck Deck::mergeSort (Deck deck) const {
  // if the deck is 0 or 1 cards, return it
  // find the midpoint of the deck
  // divide the deck into two subdecks
  // sort the subdecks using mergesort
  // merge the two halves and return the result
}


Deck Deck::subdeck (int low, int high) const {
  Deck sub (high-low+1);

  for (int i = 0; i<sub.cards.size(); i++) {
    sub.cards[i] = cards[low+i];
  }
  return sub;
}
