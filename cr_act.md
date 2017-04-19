# cr_act.h

#### Action class which handles the existence of Actions from Equipment

###### Private Values
 * string name, desc
 * int data[10]- a field for data that can be used as evaluation/move data

###### Constructors
 * Action()
 * Action(string iName, string iDesc)

###### Methods / Public Values
 * string getAName()
 * void setAName(string iName)
 * string getADesc()
 * void setADesc(string iDesc)
 * int pullVal(int i)
 * void pushVal(int i, int iVal)- used to push/pull the values in the array
