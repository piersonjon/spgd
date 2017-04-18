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

using namespace std;
const bool DEBUG=false;  // enable & disable as needed for testing.

int main() {
  CRM dbg;
  printf("Build OK!\n");
  srand(time(NULL));          // allows RTC to create random data

  Action testSwordAction("Mighty Swing","A powerful overhead swing meant to smash your opponent.");
  testSwordAction.pushVal(0,25);
  Equipment testSword("Golden Greatblade","A gleaming sword held by only the mightiest of men.",1,testSwordAction);

  Action testArmorAction("Goldlight Aura","Reduces the damage taken by the wearer.");
  testArmorAction.pushVal(0,10);
  Equipment testArmor("Crest of the Goldheart","Brilliant white and blue cloth draping chainmail.",2,testArmorAction);

  Action testCharmAction("Golden Touch","The ring allows the wearer to heal an ally slightly.");
  testCharmAction.pushVal(0,15);
  Equipment testCharm("Ring of the Golden Waves","A heavy ring stamped with the sigil of the king.",4,testCharmAction);

  Action testHelmAction("Gleam","The helmet is so polished, the light shining off can cause an enemy to miss.");
  testHelmAction.pushVal(0,10);
  Equipment testHelm("Shining Sallet","A polished helmet worn to guard the head and neck.",3,testHelmAction);

  Stat testStats(10,5,7,4,8,9,0,1);

  Creature demo("testguy");
  demo.stats = testStats;
  demo.gear[0].setItem(testSword);
  demo.gear[1].setItem(testArmor);
  demo.gear[2].setItem(testCharm);
  demo.gear[3].setItem(testHelm);

  printf("   C R O W N S\n");
  printf("  Build 3/31/17  \n\n");
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
  printf("GAMELOOP\n");
  demo.generate(true);
  return 0;
}
