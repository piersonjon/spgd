# cr_misc.h

#### Miscellaneous functions that can be served to a header as needed.

###### Private Values
 * dbg (bool)- flag used to tell if debug messages should be displayed

###### Constructors
 * CRM()
 * CRM(bool d)- allows the user to declare if CRM should enable debug messages.

###### Methods
 * bool isDEBUG()- returns true if CRM is enabled for debug messages.
 * int rd()- rolls a 10-sided die.
 * int rd(int d)- rolls a d-sided die.
 * int getVal()- safely parses integer input from the terminal.
