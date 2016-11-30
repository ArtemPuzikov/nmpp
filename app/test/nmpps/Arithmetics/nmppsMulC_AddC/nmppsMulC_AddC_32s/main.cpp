#include "nmpp.h"



/////////////////////////////////////////////////////////////////////////////////////////
nm64s *L0;
nm64s *L1;
nm64s *G0;
nm64s *G1;
const int KB=1024/8;
const int SizeL0=30*KB;
const int SizeL1=30*KB;

const int SizeG0=30*KB;
const int SizeG1=30*KB;

int main()
{
	

	L0=nmppsMalloc_64s(SizeL0);
	L1=nmppsMalloc_64s(SizeL1);
	G0=nmppsMalloc_64s(SizeG0);
	G1=nmppsMalloc_64s(SizeG1);
	if ((L0==0)||(L1==0)||(G0==0)||(G1==0)) return -1;


	unsigned int crc = 0;

	int	MaxIntSize=1024;
	MaxIntSize=MIN(MaxIntSize,SizeL0*8);
	MaxIntSize=MIN(MaxIntSize,SizeG0*8);

	nmppsRandUniform_32u((nm32u*)L0,SizeL0*2);
	nmppsSet_32s((nm32s*)G0,(int)0xCCCCCCCC,(SizeG0*2));
	
	for(int IntSize=0;IntSize<=MaxIntSize;IntSize+=2)
	{
		int MulN=nmppcRand();
		int AddN=nmppcRand();
		nmppsMulC_AddC_32s((nm32s*)L0,MulN,AddN,(nm32s*)G0,IntSize);	
		nmppsCrcAcc_32u((nm32u*)G0,MIN(IntSize+128,SizeG0*2),&crc);
	}
	//! \fn void nmppsMulC_AddC(nm32s*,int,int,nm32s*,int)

	nmppsFree(L0);
	nmppsFree(L1);
	nmppsFree(G0);
	nmppsFree(G1);

	

	return crc>>2;
}