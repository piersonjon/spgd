# cr_creat.h

#### Creature class that handles character implementation

###### Private Values
 * string name- an easy ID
 * bool empty- a boolean flag to let us know if this was created as a placeholder
 * bool isPlayer- a boolean flag to determine if this is the user's character
 * CRM tools- see cr_misc.md

###### Constructors
 * Ceature()
 * Creature(string iName)- allows the user to declare a creature's name at declaration time

###### Methods / Public Values
 * Stat stats- an array system for any character related math values
 * EquipSlot gear[4]- slotting class for Equipment objects
 * string getName()
 * void setName(string iName)
 * Stat getStats()
 * void setStats(Stat iStats)
 * Equipment getGear(int slot) - returns an Equipment item for a slot.
 * void setGear(int slot, Equipment iEquip)- allows the user to equip an item into a slot.
 * void emptyCreature()- a method for sanitizing a Creature object to make it a placeholder.
 * bool isEmpty()
 * bool isHuman()
 * void setHuman(bool tru)
 * void generate()- generates a player character.
 * void statBot(bool melee)- creates a statistical layout for a bot depending on if the bot is ranged or melee.
 * vector[Action] getValidActions()- returns all valid actions a user can execute.
