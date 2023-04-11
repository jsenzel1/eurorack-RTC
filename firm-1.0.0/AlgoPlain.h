#include <stdio.h>
#include "pico/stdlib.h"
#include "jfunc.h" 
class AlgoPlain
{

  private: 
	
	  int seq[64]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		
	  int seqMax=0;
	  int seqInd=0;
	  
	  bool played=false;

	  int weekday;
	  int cyclePos;

  public:
      int inPin;
	  int outPin;
	  
	  void init();
	  void tick();

	  bool stepVal;

      //inpin outpin ledpin, weekday, cycle
	  AlgoPlain(int,int,int,int);

	  ~AlgoPlain();
};
