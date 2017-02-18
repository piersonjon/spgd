#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <vector>

using namespace std;
const bool DEBUG=true;  // enable & disable as needed for testing.

int rd() {          // rd: roll die. in the event of no args, we assume it's a d10.
  int x = (rand()%10)+1;
  if (DEBUG) {
    printf("[d10: %i]\n",x);
  }
  return x;
}
int rd(int d) {     // rd: roll die. requires an int for the number of sides.
  int x = (rand()%d)+1;
  if (DEBUG) {
    printf("[d%i: %i]\n",d,x);
  }
  return x;
}

// Class: Action
// A move that the player wishes to execute.
// Separated into types, extended by values.
// Get/Set: Name, Desc, Type, Value.
// Contains default constructor.
// Type 0: waiting move.
// Type 1: damage move.
// Type 2: stun move.
// Type 3:

class Action {
  string name,desc;
  int type, value;
public:
  string getAName();
  void setAName(string iName);
  string getADesc();
  void setADesc(string iDesc);
  int getAType();
  void setAType(int iType);
  int getAValue();
  void setAValue(int iVal);
  Action();
  Action(string iName, string iDesc, int iType, int iVal);
};

Action::Action() {
  name = "action";
  desc = "a thing that Creatures can do.";
  type = 0;
  value = 1;
  if (DEBUG) {
    cout << "[action " << name << " created.]\n";
    cout << "[" << name << ": " << desc << "]\n";
    printf("[type: %i value: %i]\n", type, value);
  }
}
Action::Action(string iName, string iDesc, int iType, int iVal) {
  name = iName;
  desc = iDesc;
  type = iType;
  value = iVal;
}
string Action::getAName() {
  return name;
}
void Action::setAName(string iName) {
  name = iName;
}
string Action::getADesc() {
  return desc;
}
void Action::setADesc(string iDesc) {
  desc = iDesc;
}
int Action::getAType() {
  return type;
}
void Action::setAType(int iType) {
  type = iType;
}
int Action::getAValue() {
  return value;
}
void Action::setAValue(int iVal) {
  value = iVal;
}

// Class: Creature
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

// rev 1/29: added sc: stun counter. every time the player should be up, but sc!=0, sc-- (skips turn, reduces stunned cool by 1).

class Stat {
  int HP,cHP,MP,cMP,STR,WIS,DEF,RES,SPD,LCK,XP,Lvl;
public:
  int getCurrentHP();
  int getMaxHP();
  int getCurrentMP();
  int getMaxMP();
  int getSTR();
  int getWIS();
  int getDEF();
  int getRES();
  int getSPD();
  int getLCK();
  int getXP();
  int getTotalXP();
  int getLvl();

  void setCurrentHP();
  void setMaxHP();
  void setCurrentMP();
  void setMaxMP();
  void setSTR();
  void setWIS();
  void setDEF();
  void setRES();
  void setSPD();
  void setLCK();
  void setXP();
  void setLvl();
};

class Creature {
  int hp,chp,mp,cmp,str,wis,def,res,spd,lck,xp,lvl,sc;
  // vector<Stat> stats;
  string name;
  enum Race { Dog, Cat };
  vector<Action> moveset;
public:
  Creature();
  int spoke(int index);
  void spush(int index, int newVal);
  void genHero();
  void genHero(bool m);
  void genHero(int lvl, bool m);
  void genUnit();
  void genUnit(bool m);
  void genUnit(int lvl, bool m);
};

Creature::Creature() {
  str=1;
  wis=1;
  def=1;
  res=1;
  spd=1;
  lck=1;
  hp=(4*str)+(1.5*def);       // intentional, albeit rough conversion dbl>int
  chp = hp;
  mp=(4*wis)+(1.5*res);       // we can funnel this properly later, although the implicit conversion should be fine.
  cmp = mp;
  xp=0;
  lvl=1;
  name="character";
  if (DEBUG) {
    cout << "[character '" << name << "' created.]\n";
    printf("[stats: {%i %i %i %i %i %i %i/%i %i/%i}]\n",str,wis,def,res,spd,lck,hp,hp,mp,mp);
  }
}

int Creature::spoke(int index) {
  switch(index) {
    case 1:
      return str;
    case 2:
      return wis;
    case 3:
      return def;
    case 4:
      return res;
    case 5:
      return spd;
    case 6:
      return lck;
    case 7:
      return hp;
    case 8:
      return (4*str)+(1.5*def);   //max hp
    case 9:
      return mp;
    case 10:
      return (4*wis)+(1.5*res);   //max mp
    case 11:
      return xp;
    case 12:
      //return total xp
    case 13:
      return lvl;
  }
}
void Creature::spush(int index, int newVal) {
  switch(index) {
    case 1:
      str = newVal;
    case 2:
      wis = newVal;
    case 3:
      def = newVal;
    case 4:
      res = newVal;
    case 5:
      spd = newVal;
    case 6:
      lck = newVal;
    case 7:
      hp = newVal;
    case 8:
      //maxhp = newval??
    case 9:
      mp = newVal;
    case 10:
      //maxmp = newval??
    case 11:
      xp = newVal;
    case 12:
      //return total xp
    case 13:
      lvl = newVal;
  }
}
void Creature::genHero() {
  int sarr[6];
  for(int i=0;i<6;i++) {
    int tarr[3];
    for(int j=0;j<3;j++) {
      tarr[j]=rd();
    }
    sarr[i]=tarr[0]+tarr[1]+tarr[2];
    if (DEBUG) {
      printf("GENHERO) [stat: %i (%i+%i+%i)]\n",sarr[i],tarr[0],tarr[1],tarr[2]);
    }
  }

  for(int k=0;k<6;k++) {				// we need to run this as many times as we have values in our array
  	for (int i=0;i<5;i++) {	// for every value in the array (stopping one short of the end)...
  		if (sarr[i] < sarr[i+1]) {		// if the value is greater than the one on the right...
        int tmp = sarr[i];
        sarr[i] = sarr[i+1];
        sarr[i+1] = tmp;
      }
    }
  }

  if (DEBUG) {
    printf("GENHERO) [stats: %i %i %i %i %i %i]\n",sarr[0],sarr[1],sarr[2],sarr[3],sarr[4],sarr[5]);
  }
}

int main() {
  srand(time(NULL));  // seed for randomness at the current time.
  Creature char1;
  Creature char2;
  char1.genHero();
  /* while ((char1.spoke(7) > 0)&&(char2.spoke(7) > 0)) {
    //game loop!
  } */
  return 0;           // the very basics!
}
