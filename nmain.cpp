//nmain.cpp: senior design main, redesign 1 to unify changes and merge back to main
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <vector>
#include <ios>
#include <limits>

using namespace std;
const bool DEBUG=true;  // enable & disable as needed for testing.

////
// rd() : rolls a d10 and returns the result.
// rd(int d) : rolls a die with d sides and returns the result.
////
int rd() {          // rd: roll die. in the event of no args, we assume it's a d10.
  int x = (rand()%10)+1;
  if (DEBUG) {
    printf("RD) [d10: %i]\n",x);
  }
  return x;
}
int rd(int d) {     // rd: roll die. requires an int for the number of sides.
  int x = (rand()%d)+1;
  if (DEBUG) {
    printf("RDX) [d%i: %i]\n",d,x);
  }
  return x;
}

int getVal() {
  int iVal = 0;
  cin >> iVal;
  if(!cin)
  {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (DEBUG) {printf("GETVAL) BAD INPUT\n");
      }
  }
  else {
    if (DEBUG) {
      printf("GETVAL) INPUT OK\n");
    }
  }
  return iVal;
}

////
// Class: Action
////

class Action {
  string name,desc;
  int data[10];
public:
  string getAName();
  void setAName(string iName);
  string getADesc();
  void setADesc(string iDesc);
  int pullVal(int i);
  void pushVal(int i, int iVal);
  Action();
  Action(string iName, string iDesc);
};

Action::Action() {
  name = "None";
  desc = "N/A";
  for (int i=0;i<10;i++) {data[i]=0;}
}
Action::Action(string iName, string iDesc) {
  name = iName;
  desc = iDesc;
}
string Action::getAName() {return name;}
void Action::setAName(string iName) {name = iName;}
string Action::getADesc() {return desc;}
void Action::setADesc(string iDesc) {desc = iDesc;}
int Action::pullVal(int i) {return data[i];}
void Action::pushVal(int i, int iVal) {data[i] = iVal;}

////
// Class: Stat
////

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

class Equipment {
  string name, desc;
  int slot;
  Action act;
public:
  Equipment();
  Equipment(string iName, string iDesc, int iSlot, Action iAct);
  string getName();
  void setName(string iName);
  string getDesc();
  void setDesc(string iDesc);
  int getSlot();
  void setSlot(int iSlot);
  Action getAction();
  void setAction(Action iAct);
};

Equipment::Equipment() {
  name = "None";
  desc = "N/A";
  slot = -1;
  Action emptyAct;
  act = emptyAct;
}

Equipment::Equipment(string iName, string iDesc, int iSlot, Action iAct) {
  name = iName;
  desc = iDesc;
  slot = iSlot;
  act = iAct;
}

string Equipment::getName() {return name;}
string Equipment::getDesc() {return desc;}
int Equipment::getSlot() {return slot;}
Action Equipment::getAction() {return act;}
void Equipment::setName(string iName) {name=iName;}
void Equipment::setDesc(string iDesc) {desc=iDesc;}
void Equipment::setSlot(int iSlot) {slot=iSlot;}
void Equipment::setAction(Action iAct) {act=iAct;}

class EquipSlot {
  Equipment item;
  bool filled;
public:
  EquipSlot();
  Equipment getItem();
  void setItem (Equipment i);
  bool isFilled();
  void clear();
};

EquipSlot::EquipSlot() {clear();}
Equipment EquipSlot::getItem() {return item;}
void EquipSlot::setItem(Equipment i) {item=i;filled=true;}
bool EquipSlot::isFilled() {return filled;}
void EquipSlot::clear() {Equipment e;item=e;filled=false;}

// the debate for the ages:
// do we try to implement the game state in

class Agent {
  int type;
  vector<Action> getValidMoves();


};

class Creature {
  string name;
  bool empty,isPlayer;
public:
  Creature();
  Creature(string iName);
  Stat stats;             // moving gear and stats to public so we can use their class methods from the Creature object.
  EquipSlot gear[4];
  string getName();
  void setName(string iName);
  Stat getStats();
  void setStats(Stat iStats);
  Equipment getGear (int slot);
  void setGear (int slot, Equipment iEquip);
  void emptyCreature();
  bool isEmpty();
  bool isHuman();
  void generate(bool isPlayer);
};

Creature::Creature() {name="Empty";empty=true;}
Creature::Creature(string iName) {name=iName;empty=false;}
string Creature::getName() {return name;}
void Creature::setName(string iName) {name = iName;}
Stat Creature::getStats() {return stats;}
void Creature::setStats(Stat iStats) {stats = iStats;}
Equipment Creature::getGear(int slot) {
  if (slot<1||slot>4) {
    if (DEBUG) {printf("SETGEAR) cannot get gear for invalid slot %i\n",slot);}
  }
  else {
    return gear[slot].getItem();
  }
}
void Creature::setGear(int slot, Equipment iEquip) {
  if (slot<1||slot>4) {
    if (DEBUG) {printf("SETGEAR) cannot set gear for invalid slot %i\n",slot);}
  }
  else {
    gear[slot].setItem(iEquip);
  }
}
void Creature::emptyCreature() {name="Empty";empty=true;}
bool Creature::isEmpty() {return empty;}
bool Creature::isHuman() {return isPlayer;}
void Creature::generate(bool isPlayer) {
  int tmp = 0;
  string tmpName = "";
  bool filled[] = {false,false,false,false,false,false};
  bool dieUsed[] = {false,false,false,false,false,false};
  string statNames[] = {"Strength","Wisdom","Defense","Resistance","Speed","Luck"};
  printf("Every good hero needs a name.\nWhat shall we call this hero? ");
  cin >> tmpName;
  cout << "Very well- this hero shall be known as " << tmpName << ".\n\n";
  printf("Combat in CROWNS is split into two kinds: physical and magical.\n");
  printf("Creatures with higher STRength deal more physical damage.\n");
  printf("Creatures with higher WISdom deal more magical damage.\n");
  printf("Creatures with higher DEFense resist more physical damage.\n");
  printf("Creatures with higher RESistance deal more magical damage.\n");
  printf("Creatures with higher SPeeD act more frequently.\n");
  printf("Creatures with higher LuCK simply have the side of fortune.\n");
  printf("Think carefully about the person you would like to become.\n\n");
  printf("Now, you will look at your stat numbers and decide what your strentghs and weaknesses are.\nAn average stat is 16 and the maximum stat is 30.\n");
  int dice[7];
  for (int i=0;i<7;i++) {
    dice[i] = rd() + rd() + rd();
  }
  for(int k=0;k<7;k++) {				// we need to run this as many times as we have values in our array
  	for (int i=0;i<6;i++) {	// for every value in the array (stopping one short of the end)...
  		if (dice[i] < dice[i+1]) {		// if the value is greater than the one on the right...
        int tmp = dice[i];
        dice[i] = dice[i+1];
        dice[i+1] = tmp;
      }
    }
  }

  if (DEBUG) {
    printf("GENERATE) [stats: %i %i %i %i %i %i]\n",dice[0],dice[1],dice[2],dice[3],dice[4],dice[5]);
  }
  printf("Here are your stats:\n");
  for(int i=0;i<6;i++) {
    if (!dieUsed[i]) {
      printf("[%i] ",dice[i]);
    }
  }
  printf("\n");
  for(int i=0;i<6;i++) {
    printf("Please pick a stat to assign [%i] to.\n1) Strength\n2) Wisdom\n3) Defense\n4) Resistance\n5) Speed\n6) Luck\n\nWhat is your choice? ",dice[i]);
    tmp = -1;
    tmp = getVal();
    if (tmp>0&tmp<7) {    // consider rewriting this entire area for efficiency later on, this is bad to look at nevermind to run
      switch(tmp) {
        case 1:
          if (dieUsed[tmp]) {
            printf("You've already assigned [%i] to that stat.\n",stats.getSTR());
            i--;
          }
          else {
            dieUsed[tmp] = true;
            stats.setSTR(tmp);
          }
          break;
        case 2:
          if (dieUsed[tmp]) {
            printf("You've already assigned [%i] to that stat.\n",stats.getWIS());
            i--;
          }
          else {
            dieUsed[tmp] = true;
            stats.setWIS(tmp);
          }
          break;
        case 3:
          if (dieUsed[tmp]) {
            printf("You've already assigned [%i] to that stat.\n",stats.getDEF());
            i--;
          }
          else {
            dieUsed[tmp] = true;
            stats.setDEF(tmp);
          }
          break;
        case 4:
          if (dieUsed[tmp]) {
            printf("You've already assigned [%i] to that stat.\n",stats.getRES());
            i--;
          }
          else {
            dieUsed[tmp] = true;
            stats.setRES(tmp);
          }
          break;
        case 5:
          if (dieUsed[tmp]) {
            printf("You've already assigned [%i] to that stat.\n",stats.getSPD());
            i--;
          }
          else {
            dieUsed[tmp] = true;
            stats.setSPD(tmp);
          }
          break;
        case 6:
          if (dieUsed[tmp]) {
            printf("You've already assigned [%i] to that stat.\n",stats.getLCK());
            i--;
          }
          else {
            dieUsed[tmp] = true;
            stats.setLCK(tmp);
          }
          break;
        default:
          for(;;) {printf("huh?");}
          break;
      }
    }
    else {printf("That's not a valid option to choose.\n");i--;}
  }

  stats.setMaxHP((2*stats.getDEF()) + (4*stats.getSTR()));
  stats.setCurrentHP(stats.getMaxHP());
  stats.setMaxMP((2*stats.getRES()) + (4*stats.getWIS()));
  stats.setCurrentMP(stats.getMaxMP());
}

class Turn {
  vector<Action> preActions;
  vector<Action> mainActions;
  vector<Action> postActions;
public:
  vector<Action> getActions();
  void runPre();
  void runMain();
  void runPost();
};

class Encounter {
  Creature playerTeam[4];
  Creature enemyTeam[4];
public:
  Encounter();  // character array here, i think. add character first. tweak the other way around and make the Character the integral class!
  Creature addChar(bool playerTeam, Creature iChar);
  void rotate(bool team, int slot1, int slot2);
  void begin();
};

Encounter::Encounter() {}
Creature Encounter::addChar(bool isPlayerTeam, Creature iChar) {
  for (int i=0;i<4;i++) {
    if (i<3) {
      if (isPlayerTeam) {
        if (playerTeam[i].isEmpty()) {
          playerTeam[i] = iChar;
        }}
      else {
        if (enemyTeam[i].isEmpty()) {
          enemyTeam[i] = iChar;
        }}}
    else {
      if (isPlayerTeam) {
        if (playerTeam[i].isEmpty()) {
          playerTeam[i] = iChar;
        }
        else {
          if (DEBUG) {printf("DEBUG: player's team is too full to accept a new member\n");}
        }}
      else {
        if (enemyTeam[i].isEmpty()) {
          enemyTeam[i] = iChar;
        }
        else {
          if (DEBUG) {printf("DEBUG: enemy's team is too full to accept a new member\n");}
        }}}}}

class Zone {
  int id;
  Encounter fights[3];
  string transitions[3];
public:
  Zone();
  Zone(int zid, Encounter zfights[]);
  void addText(int id, string text);
  void Execute();
};
Zone::Zone() {
  id=-1;
}
Zone::Zone(int zid, Encounter zfights[3]) {id=zid; for (int i=0;i<3;i++) {fights[i]=zfights[i];}}
void Zone::addText(int id, string text) {if (id<3||id>=0) {transitions[id]=text;}}
void Zone::Execute() {}

int main() {
  printf("Build OK!\n");
  srand(time(NULL));          // allows RTC to create random data
  Zone map[5];
  for (int i=5;i<0;i--) {
    Encounter areaMap[3];
    Zone area(i,areaMap);
    map[i]=area;
  }
  string storyText[5][3];
  storyText[0][0] = "";
  storyText[0][1] = "";
  storyText[0][2] = "";
  storyText[1][0] = "";
  storyText[1][1] = "";
  storyText[1][2] = "";
  storyText[2][0] = "";
  storyText[2][1] = "";
  storyText[2][2] = "";
  storyText[3][0] = "";
  storyText[3][1] = "";
  storyText[3][2] = "";
  storyText[4][0] = "";
  storyText[4][1] = "";
  storyText[4][2] = "";

  for (int j=0;j<5;j++) { for (int k=0;k<3;k++) {
    map[j].addText(k,storyText[j][k]);
  }}

  Action testSwordAction("Mighty Swing","A powerful overhead swing meant to smash your opponent.");
  testSwordAction.pushVal(0,25);
  Equipment testSword("Golden Greatblade","A gleaming sword held by only the mightiest of men.",1,testSwordAction);

  Action testArmorAction("Goldlight Aura","Reduces the damage taken by the wearer.");
  testArmorAction.pushVal(0,10);
  Equipment testArmor("Crest of the Goldheart","Brilliant white and blue cloth draping chainmail.",2,testArmorAction);

  Action testCharmAction("Golden Touch","The ring allows the wearer to heal an ally slightly.");
  testCharmAction.pushVal(0,15);
  Equipment testCharm("Ring of the Golden Waves","A heavy ring stamped with the sigil of the king.",4,testCharmAction);

  Action testHelmAction("Gleam","The helmet is so polished, the light shining off can cause an enemy to miss.");
  testHelmAction.pushVal(0,10);
  Equipment testHelm("Shining Sallet","A polished helmet worn to guard the head and neck.",3,testHelmAction);

  Stat testStats(10,5,7,4,8,9,0,1);

  Creature demo("testguy");
  demo.stats = testStats;
  demo.gear[0].setItem(testSword);
  demo.gear[1].setItem(testArmor);
  demo.gear[2].setItem(testCharm);
  demo.gear[3].setItem(testHelm);



  printf("   C R O W N S\n");
  printf("  Build 3/31/17  \n\n");
  int chooseVal;
  string istream;
  bool mmLoop = true;
  while(mmLoop) {
    printf("Main menu:\n1) New Game\n2) About\n3) Exit\n\n");
    printf("Please select an option. ");
    chooseVal = getVal();
    switch(chooseVal) {
      case 1:
      mmLoop = false;
      break;
      case 2:
      printf("\n(THE ABOUT TEXT SHOULD PROBABLY BE HERE. IN THE EVENT THAT THERE'S NO ABOUT TEXT HERE TELLING YOU WHAT THE FUCK THIS GAME IS, CONTACT JON PIERSON AT ADMIN@KINIX.NET AND LET HIM KNOW HE GOTTA FINISH THIS ISH)\n\n");
      break;
      case 3:
      return 0;
      break;
      default:
      if (DEBUG) {printf("VALUE OOB\n\n");}
      break;
    }
  }
  printf("GAMELOOP\n");
  demo.generate(true);
  return 0;
}
