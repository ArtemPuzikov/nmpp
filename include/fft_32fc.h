#ifndef _FFT_32FC_H_INCLUDED_
#define _FFT_32FC_H_INCLUDED_

#ifdef __cplusplus
		extern "C" {
#endif

#include "nmtype.h"


#define		NUMBUFF1		21
#define		NUMBUFF2		4

typedef struct
{   
    nm32fcr *Buffers[NUMBUFF1];
    nm32fcr *Buffs[NUMBUFF2];
    int order;
} NmppsFFTSpec_32fc;

typedef struct
{
  NmppsFFTSpec_32fc *specX;
  NmppsFFTSpec_32fc *specY;
} NmppiFFTSpec_32fc;

// sFFT_32fc


    /**
    \defgroup sFFT_Fwd FFTFwd_32fc
    \ingroup sFFT_32fc
   	\brief ������� ��� ���������� ������� ��� � ��������� ������ �� ��������� ����������� �����
	
	\param [in] x ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] X �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] spec ��������, ���������� ����������� ������������, ��� ���������� ������� ��� ������������� �������
    */
    //! \{
void nmppsDFT8Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
void nmppsFFT16Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
void nmppsFFT32Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
void nmppsFFT64Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
void nmppsFFT128Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
void nmppsFFT256Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
void nmppsFFT512Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
void nmppsFFT1024Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
void nmppsFFT2048Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
    //! \}
	


	
    /**
    \defgroup sFFT_Fwd FFTInv
    \ingroup sFFT_32fc
   	\brief ������� ��� ���������� ��������� ��� � ��������� ������ �� ��������� ����������� �����
	
	\param [in] x ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] X �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] ispec ��������, ���������� ����������� ������������, ��� ���������� ��������� ��� ������������� �������
    */
    //! \{
void nmppsDFT8Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
void nmppsFFT16Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
void nmppsFFT32Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
void nmppsFFT64Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
void nmppsFFT128Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
void nmppsFFT256Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
void nmppsFFT512Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
void nmppsFFT1024Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
void nmppsFFT2048Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
    //! \}	

/**
 *  \ingroup sFFT_32fc
 *  \brief ������� ��� ���������� ������� ��� � ��������� ������ �� ��������� ����������� �����
 *  
 *  \param [in] x ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
 *  \param [in] X �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
 *  \param [in] Spc ��������, ���������� ����������� ������������, ��� ���������� ������� ��� ������������� �������
 *  \return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 * 
 */
int nmppsFFTFwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *Spc);

/**
 *  \ingroup sFFT_32fc
 *  \brief ������� ��� ���������� ��������� ��� � ��������� ������ �� ��������� ����������� �����
 *  
 *  \param [in] ix ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
 *  \param [in] iX �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
 *  \param [in] iSpc ��������, ���������� ����������� ������������, ��� ���������� ��������� ��� ������������� �������
 *  \return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 * 
 */
int nmppsFFTInv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *iSpc);


    /**
    \defgroup sFFT_Fwd FFTInvInitAlloc
    \ingroup sFFT_32fc
   	\brief ������� ������������� �������� �������������, ����������� ��� ���������� ��������� ��� ������������� �������
	
	\param [in] iaddr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
    */
    //! \{
int nmppsFFT16InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
int nmppsFFT32InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
int nmppsFFT64InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
int nmppsFFT128InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
int nmppsFFT256InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
int nmppsFFT512InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
int nmppsFFT1024InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
int nmppsFFT2048InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
    //! \}	


    /**
    \defgroup sFFT_Fwd FFTFwdInitAlloc
    \ingroup sFFT_32fc
   	\brief ������� ������������� �������� �������������, ����������� ��� ���������� ������� ��� ������������� �������
	
	\param [in] addr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
    */
    //! \{
int nmppsFFT16FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
int nmppsFFT32FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
int nmppsFFT64FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
int nmppsFFT128FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
int nmppsFFT256FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
int nmppsFFT512FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
int nmppsFFT1024FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
int nmppsFFT2048FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
    //! \}	

/**
 *  \ingroup sFFT_32fc
 *  \brief ������� ������������� �������� �������������, ����������� ��� ���������� ������� ��� ������������� �������
 *  
 *  \param [in] Spec ������� ��������� �� ��������� �������������
 *  \param [in] Order ����������� ���, ������� ����� ���������, ��������, ��� ���256 ���� �������� ����� 8 (�.�. 2^8 = 256)
 *  \return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details 
 */
int nmppsFFTFwdInitAlloc_32fc(NmppsFFTSpec_32fc **Spec, int Order);

/**
 *  \ingroup sFFT_32fc
 *  \brief ������� ������������� �������� �������������, ����������� ��� ���������� ��������� ��� ������������� �������
 *  
 *  \param [in] iSpec ������� ��������� �� ��������� �������������
 *  \param [in] iOrder ����������� ���, ������� ����� ���������, ��������, ��� ���256 ���� �������� ����� 8 (�.�. 2^8 = 256)
 *  \return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details 
 */
int nmppsFFTInvInitAlloc_32fc(NmppsFFTSpec_32fc **iSpec, int iOrder);


/**
 *  \ingroup sFFT_32fc
 *  \brief ������� ����������� ������, ���������� ��� ������������, ���������� � ��������� spec
 *  
 *  \param [in] spec ��������� �� ��������� �������������
 *  \return ���������� 0 � ������ ��������� ������������ ������ � -1 � ������ ������
 */
int nmppsFFTFree_32fc(NmppsFFTSpec_32fc *spec);

#ifdef __cplusplus
		};
#endif

#endif // _FFT_32FC_H_INCLUDED_