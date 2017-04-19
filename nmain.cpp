//nmain.cpp: senior design main, redesign 1 to unify changes and merge back to main
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <vector>
#include <ios>
#include <limits>
#include "cr_creat.h"
#include "cr_act.h"
#include "cr_equip.h"
#include "cr_stat.h"
#include "cr_misc.h"
#include "cr_bttl.h"

using namespace std;
const bool DEBUG=false;  // enable & disable as needed for testing.

int main() {
  CRM dbg;
  //printf("Build OK!\n");
  srand(time(NULL));          // allows RTC to create random data
  printf("   C R O W N S\n");
  printf("  Build 4/19/17  \n\n");
  int chooseVal;
  string istream;
  bool mmLoop = true;
  while(mmLoop) {
    printf("Main menu:\n1) New Game\n2) About\n3) Exit\n\n");
    printf("Please select an option. ");
    chooseVal = dbg.getVal();
    switch(chooseVal) {
      case 1:
      mmLoop = false;
      break;
      case 2:
      printf("\nCROWNS is a game about a single hero aspiring to sieze control of the kingdom! More to follow.\n\n");
      break;
      case 3:
      return 0;
      break;
      default:
      if (DEBUG) {printf("VALUE OOB\n\n");}
      break;
    }
  }
  //printf("GAMELOOP\n");
  Creature player;
  player.generate();

  player.setHuman(true);
  //setup enemy for encounter 1
  //begin fight with player and enemy 1
  //if we return the living player, then move onto encounter 2. otherwise, just break
  Creature enemy1("Good Knight");
  enemy1.statBot(true);
  enemy1.setHuman(false);
    //Action esAct;
    //esAct.setAName("Big Swing");
    //esAct.setADesc("The user performs a large slice. Costs 20 mana to use and deals 20 damage. 75% chance to hit.\n");
    //esAct.pushVal(1,20);
    //Equipment enemySword("Big Sword","A huge sword.",0,esAct);
    //enemy1.gear[0].setItem(enemySword);
  enemy1.stats.setCurrentHP(-1);
  Encounter enc1(player,enemy1);
  Creature winner = enc1.Battle();
  if (winner.isHuman()) {
    Encounter enc2(player,enemy1);
    Creature winner2 = enc2.Battle();
    if (winner2.isHuman()) {
      cout << "Congratulations, " << winner2.getName() << "! You have claimed the crown for your own!\n\n";
    }
  }
  else {
    printf("You were not strong enough to sieze the crown.\n\n");
  }

  return 0;
}
