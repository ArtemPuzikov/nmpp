
#ifndef INCLUDED_nmpls
#define INCLUDED_nmpls

//#include "nmtype.h"
//#include "nmdef.h"
//#include "nmpp.h"
#include "sfir.h"

/*! \ru 
	\page intro �������� 
	\en 
	\page intro Introduction
	\~
	\ingroup SIG_Group
	\ru 
����������� ������ ���������� �������� �������������� ������� ������� �� ��������� ��������  ��� ����������� NM6403,NM6404,NM6405. � ������ ���������� ������ ������� ���������� ��� ����������, ���������� ����������, �����������������. ���������� ������������� ��� ������� ���������� ����������� ���������������� �������� ��� �� ����� �������� ������(�++). 

������� ���������� ����� C++ ���������. ����������� ������� ���������� ����������� �� ����� ���������� � �������������� ��������� ���������� � �������������� ��� ����������� ����������� NM6403. 

��� �������� ���������� ���������� �������� ���������� �������� ����������� ���������� ������� ��� ����������� ����� x86, ����������� �� ����� �++. ������ ���������� ��������� ��������� ���������� � �������������� ������ ���������� ���������� ��������� �� ������������ ����������. 
	\en
The purpose of the library is to support the base functions for signal processing on  NM6403,NM6404,NM6405 processors. The library �ontains FIR-filters, non-linear filters and resampling functions. The library is meant for fast development of effective user programs in a high level language(�++). 

The library functions have a C++ interface. Most of the library functions are implemented in assembly language with using vector core instructions and optimized for the processor architecture. 

For convenience of application programs development the library has implementations of functions for processors of x86 series in C++. These implementations allow to execute application programs written by means of this library on a personal computer. 
	\~
*/


//*****************************************************************************


	/**
    *
    * \ru
    *     	\defgroup sConvolution �������
    * \en
    *     	\defgroup sConvolution Convolution
    * \~
	* \ingroup SIG_Group
	*/

#include "sCorrelation.h"
//*****************************************************************************

	/**
    *
    * \ru
    *     \defgroup sFiltration �������� ����������
    * \en
    *     \defgroup sFiltration Mask filtration
    * \~
	* \ingroup SIG_Group
	*/

//#include "sFiltration.h"


//*****************************************************************************

	/**
    *
    * \ru
    *     \defgroup sResample ��������� ��������
    * \en
    *     \defgroup sResample Resample
    * \~
	* \ingroup SIG_Group
	*/

#include "sResample.h"

//*****************************************************************************

	/**
    *
    * \ru
    *     \defgroup sFFT_32fc ������� �������������� �����
    * \en
    *     \defgroup sFFT_32fc Fast Fourier Trasform
    * \~
	* \ingroup SIG_Group
	*/


#include "fft.h"


#endif


