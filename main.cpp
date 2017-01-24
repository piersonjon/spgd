#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;
const bool DEBUG=true;  // enable & disable as needed for testing.

// the default class for any living entity in our game.
// so far, they've got some basic stats computed with some basic formulae.
// str: a measure of strength. determines hp and physical damage.
// wis: a measure of wisdom. determines mp and magical damage.
// def: a measure of defense. determines physical guard and boosts hp.
// res: a measure of resistance. determines magical guard and boosts mp.
// spd: a measure of speed. determines when the character acts.
// lck: a measure of luck. determines probability of criticals.
// xp: experience points. how many do you need?
// lvl: the character's level.
// name: what's in a name?

// from jon to jon: move these to the readme, nerd!


class Creature {
  int hp,mp,str,wis,def,res,spd,lck,xp,lvl;
  string name;
public:
  Creature();
};

Creature::Creature() {
  str=1;
  wis=1;
  def=1;
  res=1;
  spd=1;
  lck=1;
  hp=(4*str)+(1.5*def);       // intentional, albeit rough conversion dbl>int
  mp=(4*wis)+(1.5*res);       // we can funnel this properly later, although the implicit conversion should be fine.
  xp=0;
  lvl=1;
  name="character";
  if (DEBUG) {
    cout << "[character '" << name << "' created.]\n";
    printf("[stats: {%i %i %i %i %i %i %i/%i %i/%i}]",str,wis,def,res,spd,lck,hp,hp,mp,mp);
  }
}

int main() {
  srand(time(NULL));  // seed for randomness at the current time.
  Creature test;
  return 0;           // the very basics!
}
