#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <vector>
using namespace std;

enum Suit { CLUBS, DIAMONDS, HEARTS, SPADES };

enum Rank { ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
TEN, JACK, QUEEN, KING };

struct Deck;

struct Card
{
  Rank rank;
  Suit suit;

  Card ();
  Card (Suit s, Rank r);

  void print () const;
  bool equals (const Card& c2) const;
  bool isGreater (const Card& c2) const;
  int find (const Deck& deck) const;
};
#endif
