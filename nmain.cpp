//nmain.cpp: senior design main, redesign 1 to unify changes and merge back to main
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <vector>

using namespace std;
const bool DEBUG=true;  // enable & disable as needed for testing.

////
// rd() : rolls a d10 and returns the result.
// rd(int d) : rolls a die with d sides and returns the result.
////
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

////
// Class: Action
// A move that the player wishes to execute.
// Separated into types, extended by values.
// Get/Set: Name, Desc, Type, Value.
// Contains default constructor.
// Type 0: waiting move.
// Type 1: damage move.
// Type 2: stun move.
// Type 3: ???
////

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
string Action::getAName() {return name;}
void Action::setAName(string iName) {name = iName;}
string Action::getADesc() {return desc;}
void Action::setADesc(string iDesc) {desc = iDesc;}
int Action::getAType() {return type;}
void Action::setAType(int iType) {type = iType;}
int Action::getAValue() {return value;}
void Action::setAValue(int iVal) {value = iVal;}

////
// Class: Stat
// The array of character stats. It's easier this way!
//
////

class Stat {
  int HP,cHP,MP,cMP,STR,WIS,DEF,RES,SPD,LCK,XP,tXP,Lvl;
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

  void setCurrentHP(int n);
  void setMaxHP(int n);
  void setCurrentMP(int n);
  void setMaxMP(int n);
  void setSTR(int n);
  void setWIS(int n);
  void setDEF(int n);
  void setRES(int n);
  void setSPD(int n);
  void setLCK(int n);
  void setXP(int n);
  void setLvl(int n);
};

int Stat::getCurrentHP() {return cHP;}
int Stat::getMaxHP() {return HP;}
int Stat::getCurrentMP() {return cMP;}
int Stat::getMaxMP() {return MP;}
int Stat::getSTR() {return STR;}
int Stat::getWIS() {return WIS;}
int Stat::getDEF() {return DEF;}
int Stat::getRES() {return RES;}
int Stat::getSPD() {return SPD;}
int Stat::getLCK() {return LCK;}
int Stat::getXP() {return XP;}
int Stat::getTotalXP() {return tXP;}
int Stat::getLvl() {return Lvl;}
void Stat::setCurrentHP(int n) {cHP=n;}
void Stat::setMaxHP(int n) {HP=n;}
void Stat::setCurrentMP(int n) {cMP=n;}
void Stat::setMaxMP(int n) {MP=n;}
void Stat::setSTR(int n) {STR=n;}
void Stat::setWIS(int n) {WIS=n;}
void Stat::setDEF(int n) {DEF=n;}
void Stat::setRES(int n) {RES=n;}
void Stat::setSPD(int n) {SPD=n;}
void Stat::setLCK(int n) {LCK=n;}
void Stat::setXP(int n) {XP=n;}
void Stat::setLvl(int n) {Lvl=n;}
