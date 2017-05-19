#include <math.h>
#include <malloc.h>
#include "time.h"
#include "fft_32fc.h"
#include "nmpp.h"

int main()
{
	int i, tm;
	nm32fcr *src, *dst, *outInv1;
	// best config (tm = 5389, src - malloc, dst - malloc1)
	src = (nm32fcr *)malloc(512 * sizeof(nm32fcr));
	dst = (nm32fcr *)malloc(512 * sizeof(nm32fcr));
	for(i = 0; i < 512; i++) {
		src[i].im = 0;
		src[i].re = i;
		dst[i].im = 0;
		dst[i].re = 0;
	}
	NmppsFFTSpec_32fc *rat;
	tm = nmppsFFT512FwdInitAlloc_32fc(&rat);
	if(tm < 0) {
		return 123;
	}
	nmppsFFT512Fwd_32fc(src, dst, rat);
	tm = nmppsFFTFree_32fc(rat);
	unsigned int crc = 0;
	nmppsCrcAcc_32f((nm32f *)dst, 16, 512*2, &crc);
	return crc>>2;
}