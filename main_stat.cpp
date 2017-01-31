#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <vector>

using namespace std;
const bool DEBUG=true;  // enable & disable as needed for testing.

enum StatType { HP, cHP, cMP, MP, Str, Wis, Def, Res, Spd, Lck, XP, Lvl };
class Stat {
  StatType type;    // using the aforementioned enumerated type
  int value;        // double? we'll see if it's relevant later
public:
  Stat(StatType iType, int iValue);     // iType and iValue for initial values of a Stat
};

Stat::Stat(StatType iType, int iValue) {
  type = iType;
  value = iValue;
}

class Creature {
  vector<Stat> stats;
  string name;
public:
  Creature();
};

Creature::Creature() {
/*
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
  */
  name="character";
  if (DEBUG) {
    cout << "[character '" << name << "' created.]\n";
    //printf("[stats: {%i %i %i %i %i %i %i/%i %i/%i}]",str,wis,def,res,spd,lck,hp,hp,mp,mp);
  }
}

int main() {
  if (DEBUG) {        // what is life without a little vanity?
    printf("");
  }
  srand(time(NULL));  // seed for randomness at the current time.
  Creature test;      // a demo creature for testing.
  return 0;           // the very basics!
}
