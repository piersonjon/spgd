///////////////////////////////////////////////////
// cr_misc.h: Miscellaneous functions class for CROWNS
// Jonathan Pierson et none.
// rev. 4/19/17 (checkpoint build: due to term)

///////////////////////////////////////////////////
// definition check
#ifndef __CR_MISC_H_INCLUDED__
#define __CR_MISC_H_INCLUDED__

///////////////////////////////////////////////////
// include dependencies
#include <string>
using namespace std;

///////////////////////////////////////////////////
// class: CRM
class CRM {
  bool dbg;
public:
  CRM();
  CRM(bool d);
  bool isDEBUG();  // enable & disable as needed for testing.
  int rd();
  int rd(int d);
  int getVal();
};

CRM::CRM() {
  dbg=false;
}

CRM::CRM(bool d) {
  dbg=d;
}

bool CRM::isDEBUG() {return dbg;}

int CRM::rd() {          // rd: roll die. in the event of no args, we assume it's a d10.
  int x = (rand()%10)+1;
  if (dbg) {
    printf("RD) [d10: %i]\n",x);
  }
  return x;
}
int CRM::rd(int d) {     // rd: roll die. requires an int for the number of sides.
  int x = (rand()%d)+1;
  if (dbg) {
    printf("RDX) [d%i: %i]\n",d,x);
  }
  return x;
}

int CRM::getVal() {
  int iVal = 0;
  cin >> iVal;
  if(!cin)
  {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (dbg) {printf("GETVAL) BAD INPUT\n");
      }
  }
  else {
    if (dbg) {
      printf("GETVAL) INPUT OK\n");
    }
  }
  return iVal;
}

#endif
