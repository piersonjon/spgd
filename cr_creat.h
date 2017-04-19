///////////////////////////////////////////////////
// cr_creat.h: Creature class for CROWNS
// Jonathan Pierson et none.
// rev. 4/19/17 (checkpoint build: due to term)

///////////////////////////////////////////////////
// definition check
#ifndef __CR_CREAT_H_INCLUDED__
#define __CR_CREAT_H_INCLUDED__


///////////////////////////////////////////////////
// include dependencies
#include <string>
#include "cr_stat.h"
#include "cr_equip.h"
#include "cr_act.h"
#include "cr_misc.h"
using namespace std;

///////////////////////////////////////////////////
// class: Creature
class Creature {
  string name;
  bool empty,isPlayer;
  CRM tools;
public:
  Creature();
  Creature(string iName);
  Stat stats;             // moving gear and stats to public so we can use their class methods from the Creature object.
  EquipSlot gear[4];
  string getName();
  void setName(string iName);
  Stat getStats();
  void setStats(Stat iStats);
  Equipment getGear (int slot);
  void setGear (int slot, Equipment iEquip);
  void emptyCreature();
  bool isEmpty();
  bool isHuman();
  void setHuman(bool tru);
  void generate(bool isPlayer);
  void statBot(bool melee);
  vector<Action> getValidActions();
};

Creature::Creature() {name="Empty";empty=true;}
Creature::Creature(string iName) {name=iName;empty=false;}
string Creature::getName() {return name;}
void Creature::setName(string iName) {name = iName;}
Stat Creature::getStats() {return stats;}
void Creature::setStats(Stat iStats) {stats = iStats;}
void Creature::setHuman(bool tru) {isPlayer = tru;}
Equipment Creature::getGear(int slot) {
  if (slot<1||slot>4) {
    if (tools.isDEBUG()) {printf("SETGEAR) cannot get gear for invalid slot %i\n",slot);}
  }
  else {
    return gear[slot].getItem();
  }
}
void Creature::setGear(int slot, Equipment iEquip) {
  if (slot<1||slot>4) {
    if (tools.isDEBUG()) {printf("SETGEAR) cannot set gear for invalid slot %i\n",slot);}
  }
  else {
    gear[slot].setItem(iEquip);
  }
}
void Creature::emptyCreature() {name="Empty";empty=true;}
bool Creature::isEmpty() {return empty;}
bool Creature::isHuman() {return isPlayer;}

void Creature::statBot(bool melee) {
  int dice[7];
  for (int i=0;i<7;i++) {
    dice[i] = tools.rd() + tools.rd() + tools.rd();
  }
  for(int k=0;k<7;k++) {				// we need to run this as many times as we have values in our array
  	for (int i=0;i<6;i++) {	// for every value in the array (stopping one short of the end)...
  		if (dice[i] < dice[i+1]) {		// if the value is greater than the one on the right...
        int tmp = dice[i];
        dice[i] = dice[i+1];
        dice[i+1] = tmp;
      }
    }
  }
  if (melee) {
    stats.setSTR(dice[1]);
    stats.setDEF(dice[2]);
    stats.setRES(dice[3]);
    stats.setWIS(dice[4]);
    stats.setSPD(dice[5]);
    stats.setLCK(dice[6]);
    stats.setMaxHP((4 * dice[1]) + (2 * dice[2]));
    stats.setCurrentHP((4 * dice[1]) + (2 * dice[2]));
    stats.setMaxMP((4 * dice[4]) + (2 * dice[3]));
    stats.setCurrentMP((4 * dice[4]) + (2 * dice[3]));
  }
  else {
    stats.setWIS(dice[1]);
    stats.setRES(dice[2]);
    stats.setDEF(dice[3]);
    stats.setSTR(dice[4]);
    stats.setSPD(dice[5]);
    stats.setLCK(dice[6]);
    stats.setMaxHP((4 * dice[4]) + (2 * dice[3]));
    stats.setCurrentHP((4 * dice[4]) + (2 * dice[3]));
    stats.setMaxMP((4 * dice[1]) + (2 * dice[2]));
    stats.setCurrentMP((4 * dice[1]) + (2 * dice[2]));
  }
}

void Creature::generate(bool isPlayer) {
  int tmp = 0;
  string tmpName = "";
  bool filled[] = {false,false,false,false,false,false};
  bool dieUsed[] = {false,false,false,false,false,false};
  string statNames[] = {"Strength","Wisdom","Defense","Resistance","Speed","Luck"};
  printf("Every good hero needs a name.\nWhat shall we call this hero? ");
  cin >> tmpName;
  cout << "Very well- this hero shall be known as " << tmpName << ".\n\n";
  printf("Combat in CROWNS is split into two kinds: physical and magical.\n");
  printf("Creatures with higher STRength deal more physical damage.\n");
  printf("Creatures with higher WISdom deal more magical damage.\n");
  printf("Creatures with higher DEFense resist more physical damage.\n");
  printf("Creatures with higher RESistance deal more magical damage.\n");
  printf("Creatures with higher SPeeD act more frequently.\n");
  printf("Creatures with higher LuCK simply have the side of fortune.\n");
  printf("Think carefully about the person you would like to become.\n\n");
  printf("Now, you will look at your stat numbers and decide what your strentghs and weaknesses are.\nAn average stat is 16 and the maximum stat is 30.\n");
  int dice[7];
  for (int i=0;i<7;i++) {
    dice[i] = tools.rd() + tools.rd() + tools.rd();
  }
  for(int k=0;k<7;k++) {				// we need to run this as many times as we have values in our array
  	for (int i=0;i<6;i++) {	// for every value in the array (stopping one short of the end)...
  		if (dice[i] < dice[i+1]) {		// if the value is greater than the one on the right...
        int tmp = dice[i];
        dice[i] = dice[i+1];
        dice[i+1] = tmp;
      }
    }
  }

  if (tools.isDEBUG()) {
    printf("GENERATE) [stats: %i %i %i %i %i %i], drop %i\n",dice[0],dice[1],dice[2],dice[3],dice[4],dice[5],dice[6]);
  }
  printf("Here are your stats:\n");
  for(int i=0;i<6;i++) {
    if (!dieUsed[i]) {
      printf("[%i] ",dice[i]);
    }
  }
  printf("\n");
  for(int i=0;i<6;i++) {
    printf("Please pick a stat to assign [%i] to.\n1) Strength\n2) Wisdom\n3) Defense\n4) Resistance\n5) Speed\n6) Luck\n\nWhat is your choice? ",dice[i]);
    tmp = -1;
    tmp = tools.getVal();
    if (tmp>0&tmp<7) {    // consider rewriting this entire area for efficiency later on, this is bad to look at nevermind to run
      switch(tmp) {
        case 1:
          if (dieUsed[tmp]) {
            printf("You've already assigned [%i] to that stat.\n",stats.getSTR());
            i--;
          }
          else {
            dieUsed[tmp] = true;
            stats.setSTR(dice[i]);
          }
          break;
        case 2:
          if (dieUsed[tmp]) {
            printf("You've already assigned [%i] to that stat.\n",stats.getWIS());
            i--;
          }
          else {
            dieUsed[tmp] = true;
            stats.setWIS(dice[i]);
          }
          break;
        case 3:
          if (dieUsed[tmp]) {
            printf("You've already assigned [%i] to that stat.\n",stats.getDEF());
            i--;
          }
          else {
            dieUsed[tmp] = true;
            stats.setDEF(dice[i]);
          }
          break;
        case 4:
          if (dieUsed[tmp]) {
            printf("You've already assigned [%i] to that stat.\n",stats.getRES());
            i--;
          }
          else {
            dieUsed[tmp] = true;
            stats.setRES(dice[i]);
          }
          break;
        case 5:
          if (dieUsed[tmp]) {
            printf("You've already assigned [%i] to that stat.\n",stats.getSPD());
            i--;
          }
          else {
            dieUsed[tmp] = true;
            stats.setSPD(dice[i]);
          }
          break;
        case 6:
          if (dieUsed[tmp]) {
            printf("You've already assigned [%i] to that stat.\n",stats.getLCK());
            i--;
          }
          else {
            dieUsed[tmp] = true;
            stats.setLCK(dice[i]);
          }
          break;
        default:
          for(;;) {printf("huh?");}
          break;
      }
    }
    else {printf("That's not a valid option to choose.\n");i--;}
  }

  printf("\nVery good. Now all that's left is to choose your starting gear.\nFirst comes your weapon.\n\n");
  printf("1) A sword, designed for the strong.\n2) A wand, designed for the wise.\n\nWhat will you choose? ");
  tmp = -1;
  tmp = tools.getVal();
  switch(tmp) {
    case 1:
    Equipment startWep;
    case 2:
    Equipment startWep;
    break;
  }
  printf("DEBUG LINE 1\n");

  stats.setMaxHP((2*stats.getDEF()) + (4*stats.getSTR()));
  stats.setCurrentHP(stats.getMaxHP());
  stats.setMaxMP((2*stats.getRES()) + (4*stats.getWIS()));
  stats.setCurrentMP(stats.getMaxMP());
  printf("DEBUG LINE 2\n");
}

vector<Action> Creature::getValidActions() {
  printf("DEBUG LINE 3\n");
  vector<Action> goodMoves;
  goodMoves.resize(5);
  for (int i=0;i<4;i++) {
    printf("DEBUG LINE 4\n");
    if (gear[i].isFilled()) {
      int mpReq = gear[i].getItem().getAction().pullVal(1);
      int curMP = stats.getCurrentMP();
      printf("MPREQ: %i CURMP: %i\n",mpReq,curMP);
      if (mpReq < curMP) {
        printf("PUSHING BACK VALID MOVE %i\n",i);
        goodMoves.push_back(gear[i].getItem().getAction());
      }
    }
  }
}

#endif
