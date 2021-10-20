#include <iostream>
#include <vector>
using namespace std;
#include "Card.h"


vector<Card> buildDeck ()
{
  vector<Card> deck (52);

  int index = 0;
  for (int suit = 0; suit <= 3; suit++) {
    for (int rank = 1; rank <= 13; rank++) {
      deck[index].suit = suit;
      deck[index].rank = rank;
      index++;
    }
  }
  return deck;
}

bool equals (const Card& c1, const Card& c2) { // as a non-member function
  return ((c1.rank == c2.rank) && (c1.suit == c2.suit));
}

int findBisect (const Card& card, const vector<Card>& deck,
		int low, int high) {

  cout << low << ", " << high << endl;

  if (high < low) // not in deck
    return -1;

  int mid = (high + low) / 2;

  if (equals (deck[mid], card)) // we found it!
    return mid;

  if (deck[mid].isGreater (card)) { // search some more
    return findBisect (card, deck, low, mid-1);
  } else {
    return findBisect (card, deck, mid+1, high);
  }
}


int find (const Card& card, const vector<Card>& deck) {
  for (int i = 0; i < deck.size(); i++) {
    if (equals (deck[i], card)) return i;
  }
  return -1;
}

void printDeck (const vector<Card>& deck) {
  for (int i = 0; i < deck.size(); i++) {
    deck[i].print ();
  }
}

int main ()
{
  Card card;
  vector<Card> deck;
  int index;
  deck = buildDeck();
  //printDeck(deck);
  card = deck[23];
  cout << "Looking for the: ";
  card.print();
  cout << "Linear search (called two different ways):\n";
  cout << find (card, deck) << endl;
  cout << card.find (deck) << endl;
  cout << "Binary search:\n";
  index = findBisect (card, deck, 0, deck.size()-1);
  cout << "I found the card at index = " << index << endl;
  Card fakeCard(1,15);
  cout << "Looking for the 15 of Diamonds using binary search)\n";
  index = findBisect (fakeCard, deck, 0, deck.size()-1);
  cout << "I found the card at index = " << index << endl;
  return 0;
}
