///////////////////////////////////////////////////
// cr_equip.h: Equipment classes for CROWNS
// Jonathan Pierson et none.
// rev. 4/19/17 (checkpoint build: due to term)

///////////////////////////////////////////////////
// definition check
#ifndef __CR_EQUIP_H_INCLUDED__
#define __CR_EQUIP_H_INCLUDED__

///////////////////////////////////////////////////
// forward class declarations
class Creature;

///////////////////////////////////////////////////
// include dependencies
#include <string>
#include "cr_equip.h"
#include "cr_act.h"
using namespace std;

///////////////////////////////////////////////////
// class: Equipment
class Equipment {
  string name, desc;
  int slot;
  Action act;
public:
  Equipment();
  Equipment(string iName, string iDesc, int iSlot, Action iAct);
  string getName();
  void setName(string iName);
  string getDesc();
  void setDesc(string iDesc);
  int getSlot();
  void setSlot(int iSlot);
  Action getAction();
  void setAction(Action iAct);
};

Equipment::Equipment() {
  name = "None";
  desc = "N/A";
  slot = -1;
  Action emptyAct;
  act = emptyAct;
}

Equipment::Equipment(string iName, string iDesc, int iSlot, Action iAct) {
  name = iName;
  desc = iDesc;
  slot = iSlot;
  act = iAct;
}

string Equipment::getName() {return name;}
string Equipment::getDesc() {return desc;}
int Equipment::getSlot() {return slot;}
Action Equipment::getAction() {return act;}
void Equipment::setName(string iName) {name=iName;}
void Equipment::setDesc(string iDesc) {desc=iDesc;}
void Equipment::setSlot(int iSlot) {if (slot>=0&&slot<4) {slot=iSlot;}}
void Equipment::setAction(Action iAct) {act=iAct;}

///////////////////////////////////////////////////
// class: EquipSlot
class EquipSlot {
  Equipment item;
  bool filled;
public:
  EquipSlot();
  Equipment getItem();
  void setItem (Equipment i);
  bool isFilled();
  void clear();
};

EquipSlot::EquipSlot() {clear();}
Equipment EquipSlot::getItem() {return item;}
void EquipSlot::setItem(Equipment i) {item=i;filled=true;}
bool EquipSlot::isFilled() {return filled;}
void EquipSlot::clear() {Equipment e;item=e;filled=false;}

#endif
