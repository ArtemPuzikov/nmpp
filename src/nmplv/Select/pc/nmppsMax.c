//------------------------------------------------------------------------
//
//  $Workfile:: GetMax.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.2 $      $Date: 2005/07/13 14:19:56 $
//
//! \if file_doc
//!
//! \file   GetMax.cpp
//! \author ������ �������
//! \brief  �������������� �������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmplv.h"


/////////////////////////////////////////////////////////////////////////////////////////
// Search of maximum value in 8-bit buffer
void nmppsMax_8s7b(
		const	nm8s7b*		pSrcVec,	// input buffer					:long Local [Size/8]
				int			nSize,		// buffer size in 8-bit words	:nSize=[512,768,1024.....]
				int8b*		pMaxValue)	// Maximum
{
	int i;
	*pMaxValue=pSrcVec[0];
	for(i=1; i<nSize; i++){
		if(	*pMaxValue<pSrcVec[i])
			*pMaxValue= pSrcVec[i];
	}

}
/////////////////////////////////////////////////////////////////////////////////////////
// Search of maximum value in 16-bit buffer
void nmppsMax_16s15b(
		const	nm16s15b*		pSrcVec,	// input buffer					:long Local [Size/4]
				int			nSize,		// buffer size in 16-bit words	:nSize=[256,384,512...]
				int16b*		pMaxValue)	// Maximum
{
	int i;
	*pMaxValue=pSrcVec[0];
	for(i=1; i<nSize; i++){
		if(	*pMaxValue<pSrcVec[i])
			*pMaxValue= pSrcVec[i];
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
// Search of maximum value in 32-bit buffer
void nmppsMax_32s31b(
		const	nm32s31b*		pSrcVec,	// input buffer					:long Local [Size/2]
				int			nSize,		// buffer size in 32-bit words	:nSize=[128,192,256..]
				int*		pMaxValue)	// Maximum
{
	int i;
	*pMaxValue=pSrcVec[0];
	for(i=1; i<nSize; i++){
		if(	*pMaxValue<pSrcVec[i])
			*pMaxValue= pSrcVec[i];
	}
}
/////////////////////////////////////////////////////////////////////////////////////////
// Search of maximum value in 64-bit buffer
void nmppsMax_64s63b(
		const	nm64s63b*	pSrcVec,	// input buffer					:long Local [Size/2]
				int			nSize,		// buffer size in 32-bit words	:nSize=[128,192,256..]
				int64b*		pMaxValue)	// Maximum
{
	int i;
	*pMaxValue=pSrcVec[0];
	for(i=1; i<nSize; i++){
		if( *pMaxValue<pSrcVec[i])
			*pMaxValue= pSrcVec[i];
	}
}
