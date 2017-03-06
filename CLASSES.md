# classes

## Zone
The class designed to encapsulate three Encounters. Five of these compose the game's "map."
### values
### methods

## Encounter
The class designed to encapsulate the parameters of a single instance of combat.
This contains a list of the combatants on both sides of the battlefield.

## Battle
The class that handles the logistics of the turn-based combat mechanics in our game.
Receives a single Encounter to setup these battles.

## Turn
A class that handles the preemptive, main, and end phase actions that happen when a Creature is at the top of the action stack in combat.

## Action
The class that defines an action to be taken. A result of equipped items.
