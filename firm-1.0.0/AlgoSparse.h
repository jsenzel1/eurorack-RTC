#include <stdio.h>
#include "pico/stdlib.h"
#include "jfunc.h" 
class AlgoSparse
{
	private:
		int seq[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

		int seqMax;
		int seqInd=0;

		bool played=false;

		int myWeekday;
		int cyclePos;
		int densityPercent;

	public:
        int ID;
		int inPin; int outPin;

        int resetLED; int resetOn; int resetDur;

		void init();
		void tick();

		AlgoSparse(int,int,int);
		~AlgoSparse();

};
