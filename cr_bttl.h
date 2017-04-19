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

public:
  Turn (Creature actor, Creature target);
};

Turn::Turn(Creature actor, Creature target) {
  printf("DEBUG: TICK\n");
  if (actor.isHuman()) {
    //get list of moves and display them, prompting the user for a choice.
    vector<Action> possibleMoves;
    possibleMoves.resize(4);
    possibleMoves = actor.getValidActions();
  }
  else {
    printf("enemy turn, human lose 20hp\n");
    target.stats.setCurrentHP(target.stats.getCurrentHP() - 20);
    cout << "current hp: " << target.stats.getCurrentHP() << "\n";
    // get the list of valid actions and pick one at random.
  }
}

///////////////////////////////////////////////////
// class: Encounter
class Encounter {
  Creature player;
  Creature enemy;
public:
  Encounter(Creature plr, Creature nmy);
  Creature Battle();
};

Encounter::Encounter(Creature plr, Creature nmy) {
  player = plr;
  enemy = nmy;
}

Creature Encounter::Battle() {
  cout << "Battle between " << player.getName() << " and " << enemy.getName() << " has begun!\n";
  while (player.stats.getCurrentHP() > 0 && enemy.stats.getCurrentHP() > 0) {
    if (player.stats.getSPD() > enemy.stats.getSPD()) {
      Turn (player, enemy);
      Turn (enemy, player);
    }
    else {
      Turn (enemy, player);
      Turn (player, enemy);
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

#endif
