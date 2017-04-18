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
  Turn (Character actor, Character target);
};

Turn::Turn(Character actor, Character target) {
  if (actor.isPlayer()) {
    //get list of moves and display them, prompting the user for a choice.
  }
}

///////////////////////////////////////////////////
// class: Encounter
class Encounter {
  Creature player;
  Creatuyre enemy;
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
  while (player.getCurrentHP() > 0 || enemy.getCurrentHP() > 0) {
    if (player.getSPD() > enemy.getSPD()) {
      Turn (player, enemy);
      Turn (enemy, player);
    }
    else {
      Turn (enemy, player);
      Turn (player, enemy);
    }

  }
  if (player.getCurrentHP() <= 0) {
    cout << player.getName() << " has perished in combat! "
    return enemy;
  }
  else {
    cout << enemy.getName() << " has perished in combat! "
    return player;
  }
}

#endif
