# cr_equip.h

#### Equipment classes that handle equipment/slotting implementation

## Equipment

###### Private Values
 * string name- an easy ID
 * string desc- gives the user some flair text
 * int slot- determines what slot "type" an item belongs in
 * Action act- the action you can do with the item

###### Constructors
 * Equipment()
 * Equipment(string iName, string iDesc, int iSlot, Action iAct)- allows the user to declare an equipment's information in advance.

###### Methods / Public Values
 * string getName()
 * void setName(string iName)
 * string getDesc()
 * void setDesc(string iDesc)
 * int getSlot()
 * void setSlot(int iSlot)
 * Action getAction()
 * void setAction(Action iAct)

## EquipSlot

###### Private Values
 * Equipment item- the thing that goes in the slot
 * bool filled- if we have anything in there or not

###### Constructors
 * EquipSlot()

###### Methods / Public Values
 * Equipment getItem()
 * void setItem (Equipment i)
 * bool isFilled()
 * void clear()- clears out an equipment slot.
