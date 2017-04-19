# cr_stat.h

#### Stat class which handles math/logic-related aspects

###### Private Values
 * int HP,cHP,MP,cMP,STR,WIS,DEF,RES,SPD,LCK,XP,tXP,Lvl- stat ints

###### Constructors
 * Stat()
 * Stat(int iSTR, int iWIS, int iDEF, int iRES, int iSPD, int iLCK, int iXP, int iLvl) -without current HP/MP included
 * Stat(int iSTR, int iWIS, int iDEF, int iRES, int iSPD, int iLCK, int iXP, int iLvl, int icHP, int icMP)

###### Methods / Public Values
 * int getCurrentHP()
 * int getMaxHP()
 * int getCurrentMP()
 * int getMaxMP()
 * int getSTR()
 * int getWIS()
 * int getDEF()
 * int getRES()
 * int getSPD()
 * int getLCK()
 * int getXP()
 * int getTotalXP()
 * int getLvl()
 * void setCurrentHP(int n)
 * void setMaxHP(int n)
 * void setCurrentMP(int n)
 * void setMaxMP(int n)
 * void setSTR(int n)
 * void setWIS(int n)
 * void setDEF(int n)
 * void setRES(int n)
 * void setSPD(int n)
 * void setLCK(int n)
 * void setXP(int n)
 * void setLvl(int n)
