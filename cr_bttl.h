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
#include "cr_misc.h"
using namespace std;

///////////////////////////////////////////////////
// class: Encounter
class Encounter {
  bool endFlag;
  Creature player;
  Creature enemy;
  CRM tools;
public:
  Encounter(Creature plr, Creature nmy);
  Creature Battle();
  Creature TakeTurn(Creature atk, Creature def);
  void evaluateMove(int id, Creature atk, Creature def);
};

Encounter::Encounter(Creature plr, Creature nmy) {
  player = plr;
  enemy = nmy;
  endFlag = false;
}

void Encounter::evaluateMove(int id, Creature atk, Creature def) {
  int tmp = 0;
  switch (id) {
    case 1:
    atk.stats.setCurrentMP(atk.stats.getCurrentMP() - 15);
    cout << atk.getName() << " swings their mighty blade...\n";
    tmp = tools.rd(20);
    if (tmp >= 16) {
      cout << "...and strikes a devastating blow!\n";
      tmp = 15 + atk.stats.getSTR();
      tmp -= def.stats.getDEF();
      def.stats.setCurrentHP(def.stats.getCurrentHP() - tmp);
      cout << atk.getName() << " strikes their target for " << tmp << " damage, leaving them with" << def.stats.getCurrentHP() << " HP.\n";
    }
    else {
      cout << "...and misses the target.\n";
    }
    break;
    case 2:
    atk.stats.setCurrentMP(atk.stats.getCurrentMP() - 15);
  }
}

Creature Encounter::Battle() {
  cout << "Battle between " << player.getName() << " and " << enemy.getName() << " has begun!\n";
  Creature winner = TakeTurn(player, enemy);
  if (winner.isHuman()) {
    cout << enemy.getName() << " has perished in combat!\n";
    return player;
  }
  else {
    cout << player.getName() << " has perished in combat!\n";
    return enemy;
  }
}

Creature Encounter::TakeTurn(Creature atk, Creature def) {
  cout << "It is now " << atk.getName() << "'s turn.\n";
  printf("ACTOR HP: %i\nTARGET HP: %i\n",atk.stats.getCurrentHP(),def.stats.getCurrentHP());
  vector<Action> possibleMoves;
  possibleMoves = atk.getValidActions();
  int moveCt = possibleMoves.size();
  printf("MOVELIST SIZE %i\n",moveCt);
  if (moveCt >0) {
    if (atk.isHuman()) {
      printf("Here are the moves you can use this turn:\n");
      for (int i=0;i<moveCt;i++) {
        cout << (i+1) << ") " << possibleMoves[i].getAName() << ": " << possibleMoves[i].getADesc() << "\n";
      }
      printf("\nWhich move do you want to use? ");
      int moveNum = tools.getVal();
      while (moveNum > (moveCt+1) || moveNum < 1) {
        moveNum = tools.getVal();
      }
      evaluateMove(possibleMoves[moveNum - 1].pullVal(0),atk,def);
    }
    else {
      printf("LET AI PICK A MOVE\n");
      int mvIndx = tools.rd(moveCt);
      printf("INDEX ACQUIRED\n");
      Action selectedMove = possibleMoves[mvIndx];
      if (true) { //if (tools.isDEBUG()) {
        cout << "TAKETURN) " << atk.getName() << " has decided to use move '" << selectedMove.getAName() <<"'.\n";
      }
      evaluateMove(selectedMove.pullVal(0),atk,def);
    }
  }
  else {
    cout << atk.getName() << " has no moves and must concede the turn.\n";
  }
  if (def.stats.getCurrentHP() <=0) {
    return atk;
  }
  else {
    return TakeTurn(def,atk);
  }
}

#endif
