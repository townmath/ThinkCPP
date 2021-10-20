#include <iostream>
#include <vector>
using namespace std;
#include "Card.h"
#include "Deck.h"



int find (const Card& card, const Deck& deck) { //linear search
  for (int i = 0; i < deck.cards.size(); i++) {
    if (card.equals (deck.cards[i])) return i;
  }
  return -1;
}

int findBisect (const Card& card, const Deck& deck,
		int low, int high) { //binary search

  cout << low << ", " << high << endl;

  if (high < low)
    return -1;

  int mid = (high + low) / 2;

  if (card.equals (deck.cards[mid]))
    return mid;

  if (deck.cards[mid].isGreater (card)) {
    return findBisect (card, deck, low, mid-1);
  } else {
    return findBisect (card, deck, mid+1, high);
  }
}

int main ()
{
  Deck deck;
  deck.shuffle ();
  //deck.print ();//test shuffle

  Deck hand1 = deck.subdeck (0, 4);
  hand1.print ();//test hand
  //Deck hand2 = deck.subdeck (5, 9);
  //Deck pack = deck.subdeck (10, 51);

  Card card (DIAMONDS, JACK);
  deck.sort();
  int index = findBisect (card, deck, 0, deck.cards.size()-1);
  cout << "I found the card at index = " << index << endl;
  cout << "The card we were looking for is the ";
  card.print();
  cout << "The card we we found is the ";
  deck.cards[index].print();

  return 0;

}
