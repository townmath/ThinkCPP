#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <vector>
using namespace std;

struct Card;

struct Deck {
  vector<Card> cards;

  Deck ();
  Deck (int n);
  void print () const;
  int find (const Card& card) const;
  void swapCards (int i, int j);
  void shuffle ();
  int findLowestCard (int low, int high) const;
  void sort ();
  Deck mergeSort(Deck deck) const;
  Deck subdeck (int low, int high) const;
};
#endif
