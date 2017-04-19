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
// class: Encounter
class Encounter {
  Creature player;
  Creature enemy;
public:
  Encounter(Creature plr, Creature nmy);
  Creature Battle();
  void TakeTurn(Creature actor, Creature target);
};

Encounter::Encounter(Creature plr, Creature nmy) {
  player = plr;
  enemy = nmy;
}

Creature Encounter::Battle() {
  cout << "Battle between " << player.getName() << " and " << enemy.getName() << " has begun!\n";
  while (player.stats.getCurrentHP() > 0 && enemy.stats.getCurrentHP() > 0) {
    if (player.stats.getSPD() > enemy.stats.getSPD()) {
      printf("player turn first\n");
      TakeTurn(player, enemy);
      printf("...\n");
      TakeTurn(enemy, player);
    }
    else {
      printf("enemy turn first\n");
      TakeTurn(enemy, player);
      TakeTurn(player, enemy);
    }

  }
  if (player.stats.getCurrentHP() <= 0) {
    cout << player.getName() << " has perished in combat! ";
    return enemy;
  }
  else {
    cout << enemy.getName() << " has perished in combat! ";
    return player;
  }
}

void Encounter::TakeTurn(Creature actor, Creature target) {
  printf("DEBUG: TICK\n");
  if (actor.isHuman()) {
    //get list of moves and display them, prompting the user for a choice.
    vector<Action> possibleMoves;
    possibleMoves.resize(5);
    printf("here we go...\n");
    actor.getValidActions(possibleMoves);
    printf("getActs complete!\n");
  }
  printf("turn took\n");
}

#endif
