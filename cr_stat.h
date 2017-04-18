///////////////////////////////////////////////////
// cr_stat.h: Stat class for CROWNS
// Jonathan Pierson et none.
// rev. 4/19/17 (checkpoint build: due to term)

///////////////////////////////////////////////////
// definition check
#ifndef __CR_STAT_H_INCLUDED__
#define __CR_STAT_H_INCLUDED__

///////////////////////////////////////////////////
// include dependencies
using namespace std;

///////////////////////////////////////////////////
// class: Stat
class Stat {
  int HP,cHP,MP,cMP,STR,WIS,DEF,RES,SPD,LCK,XP,tXP,Lvl;
public:
  Stat();
  Stat(int iSTR, int iWIS, int iDEF, int iRES, int iSPD, int iLCK, int iXP, int iLvl);
  Stat(int iSTR, int iWIS, int iDEF, int iRES, int iSPD, int iLCK, int iXP, int iLvl, int icHP, int icMP);
  int getCurrentHP();
  int getMaxHP();
  int getCurrentMP();
  int getMaxMP();
  int getSTR();
  int getWIS();
  int getDEF();
  int getRES();
  int getSPD();
  int getLCK();
  int getXP();
  int getTotalXP();
  int getLvl();

  void setCurrentHP(int n);
  void setMaxHP(int n);
  void setCurrentMP(int n);
  void setMaxMP(int n);
  void setSTR(int n);
  void setWIS(int n);
  void setDEF(int n);
  void setRES(int n);
  void setSPD(int n);
  void setLCK(int n);
  void setXP(int n);
  void setLvl(int n);
};

Stat::Stat() {
  Lvl = 1;
  XP = 0;
  tXP = 0;
  STR = 1;
  WIS = 1;
  DEF = 1;
  RES = 1;
  SPD = 1;
  LCK = 1;
  HP = (4 * STR) + (2 * DEF);
  cHP = HP;
  MP = (4 * WIS) + (2 * RES);
  cMP = MP;
}
Stat::Stat(int iSTR, int iWIS, int iDEF, int iRES, int iSPD, int iLCK, int iXP, int iLvl) {
  Lvl = iLvl;
  XP = iXP;
  tXP = iXP;
  STR = iSTR;
  WIS = iWIS;
  DEF = iDEF;
  RES = iRES;
  SPD = iSPD;
  LCK = iLCK;
  HP = (4 * STR) + (2 * DEF);
  cHP = HP;
  MP = (4 * WIS) + (2 * RES);
  cMP = MP;
}
Stat::Stat(int iSTR, int iWIS, int iDEF, int iRES, int iSPD, int iLCK, int iXP, int iLvl, int icHP, int icMP) {
  Lvl = iLvl;
  XP = iXP;
  tXP = iXP;
  STR = iSTR;
  WIS = iWIS;
  DEF = iDEF;
  RES = iRES;
  SPD = iSPD;
  LCK = iLCK;
  HP = (4 * STR) + (2 * DEF);
  cHP = icHP;
  MP = (4 * WIS) + (2 * RES);
  cMP = icMP;
}

int Stat::getCurrentHP() {return cHP;}
int Stat::getMaxHP() {return HP;}
int Stat::getCurrentMP() {return cMP;}
int Stat::getMaxMP() {return MP;}
int Stat::getSTR() {return STR;}
int Stat::getWIS() {return WIS;}
int Stat::getDEF() {return DEF;}
int Stat::getRES() {return RES;}
int Stat::getSPD() {return SPD;}
int Stat::getLCK() {return LCK;}
int Stat::getXP() {return XP;}
int Stat::getTotalXP() {return tXP;}
int Stat::getLvl() {return Lvl;}
void Stat::setCurrentHP(int n) {cHP=n;}
void Stat::setMaxHP(int n) {HP=n;}
void Stat::setCurrentMP(int n) {cMP=n;}
void Stat::setMaxMP(int n) {MP=n;}
void Stat::setSTR(int n) {STR=n;}
void Stat::setWIS(int n) {WIS=n;}
void Stat::setDEF(int n) {DEF=n;}
void Stat::setRES(int n) {RES=n;}
void Stat::setSPD(int n) {SPD=n;}
void Stat::setLCK(int n) {LCK=n;}
void Stat::setXP(int n) {XP=n;}
void Stat::setLvl(int n) {Lvl=n;}

#endif
