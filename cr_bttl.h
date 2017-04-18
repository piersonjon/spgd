///////////////////////////////////////////////////
// cr_bttl.h: Battle system classes for CROWNS
// Jonathan Pierson et none.
// rev. 4/19/17 (checkpoint build: due to term)

///////////////////////////////////////////////////
// definition check
#ifndef __CR_BTTL_H_INCLUDED__
#define __CR_BTTL_H_INCLUDED__

///////////////////////////////////////////////////
// forward class declarations
class Stat;

///////////////////////////////////////////////////
// include dependencies
#include <string>
using namespace std;

///////////////////////////////////////////////////
// class: Turn
class Turn {
  vector<Action> preActions;
  vector<Action> mainActions;
  vector<Action> postActions;
public:
  vector<Action> getActions();
  void runPre();
  void runMain();
  void runPost();
};

///////////////////////////////////////////////////
// class: Encounter
class Encounter {
  Creature playerTeam[4];
  Creature enemyTeam[4];
public:
  Encounter();  // character array here, i think. add character first. tweak the other way around and make the Character the integral class!
  Creature addChar(bool playerTeam, Creature iChar);
  void rotate(bool team, int slot1, int slot2);
  void begin();
};

Encounter::Encounter() {}
Creature Encounter::addChar(bool isPlayerTeam, Creature iChar) {
  for (int i=0;i<4;i++) {
    if (i<3) {
      if (isPlayerTeam) {
        if (playerTeam[i].isEmpty()) {
          playerTeam[i] = iChar;
        }
      }
      else {
        if (enemyTeam[i].isEmpty()) {
          enemyTeam[i] = iChar;
        }
      }
    }
    else {
      if (isPlayerTeam) {
        if (playerTeam[i].isEmpty()) {
          playerTeam[i] = iChar;
        }
        else {
          if (DEBUG) {printf("DEBUG: player's team is too full to accept a new member\n");}
        }
      }
      else {
        if (enemyTeam[i].isEmpty()) {
          enemyTeam[i] = iChar;
        }
        else {
          if (DEBUG) {printf("DEBUG: enemy's team is too full to accept a new member\n");}
        }
      }
    }
  }
}

///////////////////////////////////////////////////
// class:

///////////////////////////////////////////////////
// class:

#endif
