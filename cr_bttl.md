# cr_bttl.h

#### Encounter class which handles the elements of Battles

###### Private Values
 * bool endFlag- used to determine if an agent is dead
 * Creature player
 * Creature enemy
 * CRM tools

###### Constructors
 * Encounter(Creature plr, Creature nmy)

###### Methods / Public Values
 * Creature Battle()- the battle circumstance in which the winning player is returned
 * Creature TakeTurn(Creature atk, Creature def)- the recursive turn-taking element of a Battle
 * void evaluateMove(int id, Creature atk, Creature def)- the element of a turn where move effects are applied
