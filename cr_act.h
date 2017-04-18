///////////////////////////////////////////////////
// cr_act.h: Action class for CROWNS
// Jonathan Pierson et none.
// rev. 4/19/17 (checkpoint build: due to term)

///////////////////////////////////////////////////
// definition check
#ifndef __CR_ACT_H_INCLUDED__
#define __CR_ACT_H_INCLUDED__

///////////////////////////////////////////////////
// forward class declarations
class Creature;

///////////////////////////////////////////////////
// include dependencies
#include <string>
using namespace std;

///////////////////////////////////////////////////
// class: Action
class Action {
  string name,desc;
  int data[10];
public:
  string getAName();
  void setAName(string iName);
  string getADesc();
  void setADesc(string iDesc);
  int pullVal(int i);
  void pushVal(int i, int iVal);
  Action();
  Action(string iName, string iDesc);
};

Action::Action() {
  name = "None";
  desc = "N/A";
  for (int i=0;i<10;i++) {data[i]=0;}
}
Action::Action(string iName, string iDesc) {
  name = iName;
  desc = iDesc;
}
string Action::getAName() {return name;}
void Action::setAName(string iName) {name = iName;}
string Action::getADesc() {return desc;}
void Action::setADesc(string iDesc) {desc = iDesc;}
int Action::pullVal(int i) {return data[i];}
void Action::pushVal(int i, int iVal) {data[i] = iVal;}

#endif
