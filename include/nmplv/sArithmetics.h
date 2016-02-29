//------------------------------------------------------------------------
//
//  $Workfile:: vArithmetics.h             $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.2 $      $Date: 2005/06/23 15:15:15 $
//
//! \if file_doc
//!
//! \file   vArithm.h
//! \author ������ �������
//! \brief  ����������� ������� �������������� ������� ��� ���������
//!
//! \endif
//!
//------------------------------------------------------------------------

#ifndef _VARITHM_H_INCLUDED_
#define _VARITHM_H_INCLUDED_


#include "nmtype.h"
    /**
    \defgroup nmppsAbs nmppsAbs
    \ingroup vArithmetics
    \brief
        \ru ���������� ���������� �������� ��� ��������� �������. 
        \en Calculation of absolute values for vec elements. 
    
		\~
    
	\f[ 
        pDstVec[i]  =  abs \{  pSrcVec[i] \},
    \f]
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \restr
        \ru �������� ��������� ������� �� ������ ���� ����� ������������ 
            �������� ��� ���������������� ���� (�.�. -128, -2^15 � �.�).
            � ��������� ������, ���������� �������� ��� ����� ���������
            ����������� �������, ����� �� ������ �� �� ����� �����.
        \en Values of elements must not be equal
            to the minimum value of element type. (i.e. -128, -2^15 ...)
            Otherwise absolute values for such elements
            are calculated incorrectly resulting to the same value
            in the output vec.
            
		\~
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize   </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize   </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    
    */
    //! \{
void nmppsAbs_8s (nm8s* pSrcVec, nm8s* pDstVec, int nSize);
void nmppsAbs_16s(nm16s* pSrcVec, nm16s* pDstVec, int nSize);
void nmppsAbs_32s(nm32s* pSrcVec, nm32s* pDstVec, int nSize);
void nmppsAbs_64s(nm64s* pSrcVec, nm64s* pDstVec, int nSize);
    //! \}
void nmppsAbs_4s( nm4s* pSrcVec,  nm4s* pDstVec, int nSize);


 /**
    \defgroup nmppsAbs1 nmppsAbs1
    \ingroup vArithmetics
    \brief
        \ru ������� ����������� ���������� ������� ��������� �������. 
        \en Logical-based calculation of absolute values for vec elements. 
    
		\~
  
	\f[
        pDstVec[i]  =  \{ \begin{array}{*{20}c}
            pSrcVec[i],    &  if &  pSrcVec[i] \ge 0  \\
            -pSrcVec[i]-1,     &  if &  pSrcVec[i] < 0  \\
        \end{array}
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize   </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize   </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    
    */
    //! \{
//void nmppsAbs1(nm4s* pSrcVec, nm4s* pDstVec, int nSize);
//void nmppsAbs1(nm8s* pSrcVec, nm8s* pDstVec, int nSize);
//void nmppsAbs1(nm16s* pSrcVec, nm16s* pDstVec, int nSize);
//void nmppsAbs1(nm32s* pSrcVec, nm32s* pDstVec, int nSize);
//void nmppsAbs1(nm64s* pSrcVec, nm64s* pDstVec, int nSize);
    //! \}


//*****************************************************************************
    
    /**
    \defgroup nmppsNeg nmppsNeg
    \ingroup vArithmetics
    \brief
        \ru ��������� ����� ��������� ������� �� ���������������. 
        \en Change of the vec element sign for the opposite one.   
    
    
		\~
    
	\f[ 
        pDstVec[i]  =  - pDstVec[i]
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsNeg_8s (nm8s* pSrcVec, nm8s* pDstVec, int nSize);
void nmppsNeg_16s(nm16s* pSrcVec, nm16s* pDstVec, int nSize);
void nmppsNeg_32s(nm32s* pSrcVec, nm32s* pDstVec, int nSize);
void nmppsNeg_64s(nm64s* pSrcVec, nm64s* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsAddC nmppsAddC
    \ingroup vArithmetics
    \brief
        \ru ���������� � ������� ���������. 
        \en Addition of a constant to a vec. 
    
		\~
    
	\f[
        pDstVec[i]  =  pSrcVec[i]  +  nVal,
    \f]
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \param  pSrcVec 
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param  nVal    
        \ru ����������� ���������. 
        \en Added constant. 
		\~
    \param  pnVal   
        \ru ��������� �� ����������� ���������. 
        \en Pointer to the added constant. 
		\~
    \param  nSize   
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> nVal </param> <values> n </values>
             <param> pnVal </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> nVal </param> <values> n </values>
             <param> pnVal </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsAddC_8s (nm8s* pSrcVec,  int8b nVal,    nm8s* pDstVec,  int nSize);
void nmppsAddC_16s(nm16s* pSrcVec, int16b nVal,   nm16s* pDstVec, int nSize);
void nmppsAddC_32s(nm32s* pSrcVec, int32b nVal,   nm32s* pDstVec, int nSize);
void nmppsAddC_64s(nm64s* pSrcVec, int64b* pnVal, nm64s* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsAdd nmppsAdd
    \ingroup vArithmetics
    \brief
        \ru �������� ���� ��������. 
        \en Two vectors addition. 
    
		\~
    
	\f[
        pDstVec[i]  =  pSrcVec1[i]  +  pSrcVec2[i],
    \f]
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
    \param nSize    
        \ru ������ ������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsAdd_8s (nm8s* pSrcVec1, nm8s* pSrcVec2, nm8s* pDstVec, int nSize);
void nmppsAdd_16s(nm16s* pSrcVec1, nm16s* pSrcVec2, nm16s* pDstVec, int nSize);
void nmppsAdd_32s(nm32s* pSrcVec1, nm32s* pSrcVec2, nm32s* pDstVec, int nSize);
void nmppsAdd_64s(nm64s* pSrcVec1, nm64s* pSrcVec2, nm64s* pDstVec, int nSize);

		

    //! \}


//*****************************************************************************

    /**
    \defgroup nmppsAdd_AddC nmppsAdd_AddC
    \ingroup vArithmetics
    \brief
        \ru �������� ���� �������� � ������������ ���������. 
        \en Summation of two vectors with addition of a constant. 
    
		\~
    
	\f[
        pDstVec[i]  =  pSrcVec1[i]  +  pSrcVec2[i]  +  nVal,
    \f]
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
    \param nVal     
        \ru ����������� ���������. 
        \en Added constant. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> nVal </param> <values> n </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> nVal </param> <values> n </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
//void nmppsAdd_AddC(nm32s* pSrcVec1, nm32s* pSrcVec2, int nVal, nm32s* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsSubC nmppsSubC
    \ingroup vArithmetics
    \brief
        \ru ��������� ��������� ��  �������. 
        \en Subtraction of a constant from a vec.  
    
		\~
    
	\f[
        pDstVec[i]  =  pSrcVec[i]  -  nVal
    \f]
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nVal     
        \ru ���������� ���������. 
        \en The deducted constant. 
		\~
    \param  pnVal   
        \ru ��������� �� ���������� ���������. 
        \en Pointer to the deducted constant. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec	
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> nVal </param> <values> n </values>
             <param> pnVal </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> nVal </param> <values> n </values>
             <param> pnVal </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsSubC_8s (nm8s* pSrcVec,  int8b nVal,    nm8s*  pDstVec,  int nSize);
void nmppsSubC_16s(nm16s* pSrcVec, int16b nVal,   nm16s* pDstVec, int nSize);
void nmppsSubC_32s(nm32s* pSrcVec, int32b nVal,   nm32s* pDstVec, int nSize);
void nmppsSubC_64s(nm64s* pSrcVec, int64b* pnVal, nm64s* pDstVec, int nSize);
    //! \}

//*****************************************************************************
    
    /**
    \defgroup nmppsSubCRev nmppsSubCRev
    \ingroup vArithmetics
    \brief
        \ru ��������� ��������� ��  �������  � ��������� ����� ��������� �������. 
        \en Subtraction of a constant from a vec with change of the vec elements sign.  
    
		\~
    
	\f[
        pDstVec[i]  =  nVal - pSrcVec[i],
    \f]
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nVal     
        \ru ���������. 
        \en Constant. 
		\~
    \param  pnVal   
        \ru ��������� �� ���������. 
        \en Pointer to the constant. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec	
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> nVal </param> <values> n </values>
             <param> pnVal </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> nVal </param> <values> n </values>
             <param> pnVal </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
		void nmppsSubCRev_8s (nm8s* pSrcVec, int8b nVal, nm8s* pDstVec, int nSize);
		void nmppsSubCRev_16s(nm16s* pSrcVec, int16b nVal, nm16s* pDstVec, int nSize);
		void nmppsSubCRev_32s(nm32s* pSrcVec, int32b nVal, nm32s* pDstVec, int nSize);
		void nmppsSubCRev_64s(nm64s* pSrcVec, int64b* pnVal, nm64s* pDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsSub nmppsSub
    \ingroup vArithmetics
    \brief
        \ru ��������� ���� �������. 
        \en Two vectors subtraction. 
    
		\~
    
	\f[
        pDstVec[i] = pSrcVec1[i] - pSrcVec2[i]
    \f] 
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \param pSrcVec1 
        \ru ����������� ������. 
        \en Input vec. 
		\~
    \param pSrcVec2 
        \ru ���������� ������. 
        \en The deducted vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec	
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void
    
        
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsSub_8s (nm8s* pSrcVec1, nm8s* pSrcVec2, nm8s* pDstVec, int nSize);
void nmppsSub_16s(nm16s* pSrcVec1, nm16s* pSrcVec2, nm16s* pDstVec, int nSize);
void nmppsSub_32s(nm32s* pSrcVec1, nm32s* pSrcVec2, nm32s* pDstVec, int nSize);
void nmppsSub_64s(nm64s* pSrcVec1, nm64s* pSrcVec2, nm64s* pDstVec, int nSize);
    //! \}


//*****************************************************************************

    /**
    \defgroup nmppsAbsDiff nmppsAbsDiff
    \ingroup vArithmetics
    \brief
        \ru ���������� ������� ������� �������� ��������� ���� ��������. 
        \en Calculation of the vec of modules of two vectors difference.       
		\~
    
	\f[
        pDstVec[i]  =  abs \{ pSrcVec1[i]  -  pSrcVec2[i]\},
    \f]
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \param pSrcVec1 
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param pSrcVec2 
        \ru ���������� ������. 
        \en The deducted vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec	
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void

    \restr
        \ru �������� ��������� �������� �� ������ ���� ����� ������������ 
            �������� ��� ���������������� ���� (�.�. -128, -2^15 � �.�).
            � ��������� ������, ���������� �������� ��� ����� ���������
            ����������� �� �����, ����� �� ������ �� �� ����� �����.
         \en Difference between vec elements must not be equal
            to the minimum value of element type. (i.e. -128, -2^15 ...)
            Otherwise absolute values for such elements
            are calculated incorrectly resulting to the same value
            in the output vec.    
		\~
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly

    
    */
    //! \{
	void nmppsAbsDiff_8s (nm8s* pSrcVec1,  nm8s* pSrcVec2,  nm8s* pDstVec,  int nSize);
	void nmppsAbsDiff_16s(nm16s* pSrcVec1, nm16s* pSrcVec2, nm16s* pDstVec, int nSize);
	void nmppsAbsDiff_32s(nm32s* pSrcVec1, nm32s* pSrcVec2, nm32s* pDstVec, int nSize);
	void nmppsAbsDiff_64s(nm64s* pSrcVec1, nm64s* pSrcVec2, nm64s* pDstVec, int nSize);
    //! \}
	
//*****************************************************************************

    /**
    \defgroup nmppsAbsDiff1 nmppsAbsDiff1
    \ingroup vArithmetics
    \brief
        \ru ������� ����������� ���������� ������� ��������� ��������� ���� ��������. 
        \en Logical-based calculation of absolute values of two vec difference.     
		\~
    
	\f[
        pDstVec[i]  =  \{ \begin{array}{*{20}c}
        pSrcVec1[i] - pSrcVec2[i] ,    &  if &  pSrcVec1[i] - pSrcVec2[i] \ge 0  \\
        pSrcVec1[i] - pSrcVec2[i]-1,     &  if &  pSrcVec1[i] - pSrcVec2[i] < 0  \\
        \end{array}
    \f]
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \param pSrcVec1 
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param pSrcVec2 
        \ru ���������� ������. 
        \en The deducted vec. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec	
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void

    \restr
        \ru �������� ��������� �������� �� ������ ���� ����� ������������ 
            �������� ��� ���������������� ���� (�.�. -128, -2^15 � �.�).
            � ��������� ������, ���������� �������� ��� ����� ���������
            ����������� �� �����, ����� �� ������ �� �� ����� �����.
         \en Difference between vec elements must not be equal
            to the minimum value of element type. (i.e. -128, -2^15 ...)
            Otherwise absolute values for such elements
            are calculated incorrectly resulting to the same value
            in the output vec.    
		\~
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly

    
    */
    //! \{
		void nmppsAbs1Diff_8s(nm8s* pSrcVec1, nm8s* pSrcVec2, nm8s* pDstVec, int nSize);
    //! \}	

//*****************************************************************************

    /**
    \defgroup nmppsMulC nmppsMulC
    \ingroup vArithmetics
    \brief
        \ru ��������� ������� �� ���������. 
        \en Vector by constant multiplication. 
    
		\~
    
	\f[
        pDstVec[i] = nVal \cdot pSrcVec[i],
    \f]
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nVal     
        \ru ���������-���������. 
        \en Multiplier constant. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> nVal </param> <values> n </values>
             <param> pnVal </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> nVal </param> <values> n </values>
             <param> pnVal </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
//void nmppsMulC_8s8s		(nm8s* pSrcVec, int8b nVal, nm8s* pDstVec, int nSize);
//void nmppsMulC_8s16s 	(nm8s* pSrcVec, int16b nVal, nm16s* pDstVec, int nSize);
//void nmppsMulC_16s		(nm16s* pSrcVec, int16b nVal, nm16s* pDstVec, int nSize);
//void nmppsMulC_16s32s	(nm16s* pSrcVec, int32b nVal, nm32s* pDstVec, int nSize);
//void nmppsMulC_32s		(nm32s* pSrcVec, int32b nVal, nm32s* pDstVec, int nSize);
//void nmppsMulC_32s64s	(nm32s* pSrcVec, int64b nVal, nm64s* pDstVec, int nSize);
//void nmppsMulC_64s		(nm64s* pSrcVec, int64b nVal, nm64s* pDstVec, int nSize);
    //! \}


//*****************************************************************************

    /**
    \defgroup nmppsMulV_AddC nmppsMulV_AddC
    \ingroup vArithmetics
    \brief
        \ru ������������ ��������� �������� � ������������ ���������. 
        \en Elementwise multiplication of two vectors with constat addition 
    
		\~
    
	\f[
        pDstVec[i] = pSrcVec1[i] \cdot pSrcVec2[i] + nVal,
    \f]
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \param pSrcVec1  
        \ru ������� ������. 
        \en Input vec. 
		\~
	\param pSrcVec2  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nVal     
        \ru �������� �� ���������-���������. 
        \en pointer to increment-constant. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
			 <param> pSrcVec2 </param> <values> L G </values>
             <param> nVal </param> <values> n </values>
             <param> pnVal </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> nVal </param> <values> n </values>
             <param> pnVal </param> <values> &amp;n </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
//void nmppsMulV_AddC(nm64s* pSrcVec1,nm64s* pSrcVec2, nm64s* pnVal, nm64s* pDstVec, int nSize);
    //! \}
//*****************************************************************************

    /**
    \defgroup nmppsMulC_AddC nmppsMulC_AddC
    \ingroup vArithmetics
    \brief
        \ru ��������� ������� �� ��������� � ������������ ���������. 
        \en Vector by constant multiplication with addition of a constant. 
    
		\~
    
	\f[
        pDstVec[i]  =  nMulVal \cdot pSrcVec[i] + nAddal,
    \f]
    
	\f[
        \quad i = \overline{0 \ldots nSize-1}
    \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nMulVal   
        \ru ���������-���������. 
        \en Multiplier constant. 
		\~
    \param nAddal   
        \ru ����������� ���������.
        \en Addition constant. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> nMulVal </param> <values> m </values>
             <param> nAddal </param> <values>  n </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> nMulVal </param> <values> m </values>
             <param> nAddal </param> <values>  n </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
//void nmppsMulC_AddC(nm32s* pSrcVec, int nMulVal, int nAddal, nm32s* pDstVec, int nSize);
    //! \}

	


/**
 *   \ingroup nmppsMulC_AddC
 *
 *  \brief Sparse vector by constant multiplication with addition of constant. 
 *  \f[
 *       dataSparseDst[i \cdot stepSparseDst][k]  =  dataSparseSrc[i \cdot stepSparseSrc][k]\cdot mulArg[k] + addArg[k],
 *  \f]
 *	\f[
 *       i = \overline{0 \ldots size-1}; k = \overline{0 \ldots K-1},
 *  \f]
 *  where K is value of intWxK type
 *  
 *  \param [in] dataSparseSrc Input sparse vector of 64-bit packed words
 *  \param [in] mulArg Packed 64-bit word with values to multiply 
 *  \param [in] addArg Packed 64-bit word with values to add 
 *  \param [in] dataSparseDst Ouput sparse vector of 64-bit packed words
 *  \param [in] size actual amount of 64-bit packed words in sparse vector to be processed
 *  \param [in] stepSparseSrc 64-bit step between input packed words in memory .  By default=1 means that input vector is continuous 
 *  \param [in] stepSparseDst 64-bit step between output packed words in memory. By default=1 means that output vector is continuous
 *  \return  \e void 
 *  
 *  \details 
 */
//! \{
//void nmppsMulC_AddC(int32x2* dataSparseSrc,  int32x2& mulArg, int32x2& addArg, int32x2 *dataSparseDst,  int size, int stepSparseSrc=1, int stepSparseDst=1);
//! \}


/**
 *  \defgroup nmppsRShiftC_MulC_AddC nmppsRShiftC_MulC_AddC
 *  \ingroup vArithmetics
 *
 *  Sparse vector by constant multiplication with addition of constant. 
 *  \f[
 *       dataSparseDst[i \cdot stepSparseDst][k]  =  (dataSparseSrc[i \cdot stepSparseSrc][k]>>preshiftArg[k])\cdot mulArg[k] + addArg[k],
 *  \f]
 *	\f[
 *       i = \overline{0 \ldots size-1}; k = \overline{0 \ldots K-1},
 *  \f]
 *  where K is value of intWxK type
 *  
 *  \param [in] dataSparseSrc Input sparse vector of 64-bit packed words
 *  \param [in] preshiftArg  Packed 64-bit word of values for preshifting of input data = [2,4,6,8...28,30]
 *  \param [in] mulArg Packed 64-bit word with values to multiply 
 *  \param [in] addArg Packed 64-bit word with values to add 
 *  \param [in] dataSparseDst Ouput sparse vector of 64-bit packed words
 *  \param [in] size actual amount of 64-bit packed words in sparse vector to be processed
 *  \param [in] stepSparseSrc 64-bit step between input packed words in memory . By default=1 means that input vector is continuous 
 *  \param [in] stepSparseDst 64-bit step between output packed words in memory. By default=1 means that output vector is continuous
 *  \return  \e void 
 *  
 *  \details 
 */
//! \{
//void nmppsRShiftC_MulC_AddC(int32x2* dataSparseSrc,  int32x2& preshiftArg, int32x2& mulArg, int32x2& addArg, int32x2 *dataSparseDst,  int size, int stepSparseSrc=1, int stepSparseDst=1);
//! \}
	

//*****************************************************************************

    /**
    \defgroup nmppsMulC_Add_AddC nmppsMulC_Add_AddC
    \ingroup vArithmetics
    \brief
        \ru ��������� ������� �� ��������� � ������������ ������� � ���������. 
        \en Vector by constant multiplication with addition of a vec and a  constant. 
    
		\~
    
	\f[
        pDstVec[i]  =  nMulVal \cdot pSrcVec1[i] + pSrcVec2[i] +  nAddal,
    \f]
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \param pSrcVec1 
        \ru ������ ������� ������. 
        \en The first input vec. 
		\~
    \param nMulVal   
        \ru ���������-���������. 
        \en Multiplier constant. 
		\~
    \param pSrcVec2 
        \ru ������ ������� ������. 
        \en The second input vec. 
		\~
    \param nAddal   
        \ru ����������� ���������.
        \en Addition constant. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> nMulVal </param> <values> m </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> nAddal </param> <values>  n </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> L </values>
             <param> nMulVal </param> <values> m </values>
             <param> pSrcVec2 </param> <values> G </values>
             <param> nAddal </param> <values>  n </values>
             <param> pDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
//void nmppsMulC_Add_AddC(nm32s* pSrcVec1, int nMulVal, nm32s* pSrcVec2, int nAddal, nm32s* pDstVec, int nSize);
    //! \}
 
//*****************************************************************************

    /**
    \defgroup nmppsAddNV nmppsAddNV
    \ingroup vArithmetics
    \brief
        \ru �������� ���������� ��������. 
        \en Summation of several vectors. 
    
		\~
    
	\f[
        pDstVec[i]  =  \sum\limits_{j = 0}^{(nNumberOfVectors - 1)} {ppSrcVec(j)(i)}     
    \f]
    
    \param ppSrcVec 
        \ru ������ ���������� �� ����������� �������. 
        \en The array of pointers to the summable vectors. 
		\~
    \param nNumberOfVectors 
        \ru ����� ����������� ��������. 
        \en The number of summable vectors. 
		\~
    \param nSize    
        \ru ������ �������� � ��������� =[32*PACK]
        \en Vector size in elements =[32*PACK]
		\~
    \retval pDstVec 
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void 
    
    \par
    \xmlonly
        <testperf> 
             <init> 	
                long *pL[4]={L, L+1024, L+2048, L+4096};
	            long *pG[4]={G, G+1024, G+2048, G+4096};
             </init>
             <param> ppSrcVec </param> <values> pL pG </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nNumberOfVectors </param> <values> 4 </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <init> 	
                long *pL[4]={L, L+1024, L+2048, L+4096};
	            long *pG[4]={G, G+1024, G+2048, G+4096};
             </init>
             <param> ppSrcVec </param> <values> pL </values>
             <param> pDstVec </param> <values> G </values>
             <param> nNumberOfVectors </param> <values> 4 </values>
             <param> nSize </param> <values> 256 1024 10240 </values>
        </testperf>
    \endxmlonly

    */
    //! \{
//void nmppsAddNV_8s(nm8s  ** ppSrcVec, nm16s* pDstVec, int nSize, int nNumberOfVectors);
//void nmppsAddNV_16s(nm16s ** ppSrcVec, nm16s* pDstVec, int nSize, int nNumberOfVectors);
    //! \}


		
//*****************************************************************************

    /**
    \defgroup nmppsDivC  nmppsDivC
    \ingroup vArithmetics
    \brief
        \ru ������� ������� �� ���������. 
        \en Division of a vec by a constant. 
    
		\~
    
	\f[ 
        pDstVec[i]  =  \frac {pSrcVec[i]}{Divisor},
    \f]
    
	\f[
        i = \overline{0 \ldots nSize-1}
    \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param nDivisor	
        \ru ���������-��������. 
        \en Constant-divisor. 
		\~
    \param nSize	
        \ru ������ �������� ������� � ���������. 
        \en Input vec size in elements. 
		\~
    \param pTmpBuf1	
        \ru ��������� ������ �������� nSize 64-� ��������� ����. 
        \en Temporary array sized nSize of 64-bit words. 
		\~
    \param pTmpBuf2	
        \ru ��������� ������ �������� nSize 64-� ��������� ����. 
        \en Temporary array sized nSize of 64-bit words. 
		\~
    \retval pDstVec	
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return void
    
    \restr
        - \ru ���������� �������� ��� ��������� �������� ������� �����
            � ��������� [-4095,...,4095];
          \en Admissible values for input vec elements are in the range [-4095,...,4095];
		\~
        - \ru ���������� �������� ��� �������� ����� � ��������� [1,2,..145].
          \en Admissible values for devisor are in the range [1,2,..145]. 

		\~
    \note 
        \ru ��� ���������� ������������� in-place ����������
    	    ������� ��������� ������� ��������� ������������� �����������:\n
    	\en To use in-place parameters correctly one should take into account
		\~
    	    the order of obtaining intermediate results: \n
        \~  pSrcVec			=> pTmpBuf1		(1cpl:L<=>G)		- 1/x Multiplying	(in-place is supported)\n
    	    pTmpBuf1		=> pTmpBuf2		(1cpl:G<=>L)		- Scaling down		(in-place is supported)\n
    	    pTmpBuf2		=> pDstVec		(2cpl:L<=>G)		- Result correction	(in-place is supported)\n\n
    	\ru ������� ������������� in-place ����������:\n
    	\en Examples of in-place parameters use: \n
        \~  nmppsDiv(L0,G0,10240,3,G0,L0);\n
    	    nmppsDiv(L0,L0,10240,3,L0,L0);\n
    
         
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> nDivisor </param> <values> n </values>
             <param> pnDivisor </param> <values> &amp;n </values>
             <param> pTmpBuf1 </param> <values> L G </values>
             <param> pTmpBuf2 </param> <values> L G </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
             <param> nDivisor </param> <values> n </values>
             <param> pnDivisor </param> <values> &amp;n </values>
             <param> pTmpBuf1 </param> <values> G </values>
             <param> pTmpBuf2 </param> <values> L </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    \{
    */
//void nmppsDivC_32s(nm32s* pSrcVec, int nDivisor, nm32s* pDstVec, int nSize, void* pTmpBuf1, void* pTmpBuf2);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsSum nmppsSum
    \ingroup vArithmetics
    \brief
        \ru ���������� ����� ���� ��������� �������. 
        \en Returns the sum of all vec elements. 

		\~
    
	\f[
        return  =  \sum\limits_{i = 0}^{(nSize - 1)} {pSrcVec[i]}     
    \f]
    
    \param pSrcVec  
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param pTmpBuf  
        \ru ��������� ������ ������� nSize 64-� ��������� ����. 
        \en A temporary array sized nSize 64-bit words. 
		\~
    \param nSize    
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \return         
        \ru ����� ��������� �������. 
        \en The sum of vec elements. 
    
        
		\~
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pTmpBuf </param> <values> L G </values>
             <param> pnRes  </param> <values> &amp;n </values>
             <param> nSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> G </values>
             <param> pTmpBuf </param> <values> L </values>
             <param> pnRes  </param> <values> &amp;n </values>
             <param> nSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    
    */
    //! \{
void nmppsSum_1s (struct nm1* pSrcVec, int nSize, int32b *pnRes, void* pTmpBuf);
void nmppsSum_8s (nm8s* pSrcVec, int nSize, int32b *pnRes);
void nmppsSum_16s(nm16s* pSrcVec, int nSize, int64b *pnRes);
void nmppsSum_32s(nm32s* pSrcVec, int nSize, int64b *pnRes);
void nmppsSum_64s(nm64s* pSrcVec, int nSize, int64b *pnRes);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsDot nmppsDot
    \ingroup vArithmetics
    \brief
        \ru ��������� ��������� ���� ��������. 
        \en Scalar multiplication of two vectors. 
    
		\~
    
	\f[
        nRes = \sum_{i=}^{nSize-1} pSrcVec1[i] \cdot pSrcVec2[i] 
    \f]
    
    \param pSrcVec1  
        \ru ������ ������. 
        \en The first vec. 
		\~
    \param pSrcVec2  
        \ru ������ ������. 
        \en The second vec. 
		\~
    \param nSize     
        \ru ������ �������� � ���������. 
        \en Vector size in elements. 
		\~
    \retval pnRes    
        \ru ��������� �� �������������� ��������. 
        \en Pointer to the result value. 
		\~
	\return pTmpBuff
		\ru ��������� ������ �� nSize ���������.
		\en Temporary buffer of nSize elements.
		\~
    \return \e void
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec1 </param> <values> L G </values>
             <param> pSrcVec2 </param> <values> L G </values>
             <param> pTmpBuff </param> <values> L G </values>
             <param> pnRes  </param> <values> &amp;n </values>
             <param> nSize </param> <values> 8192 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec1 </param> <values> G </values>
             <param> pSrcVec2 </param> <values> L </values>
             <param> pTmpBuff </param> <values> G </values>
             <param> pnRes  </param> <values> &amp;n </values>
             <param> nSize </param> <values> 8 128 1024 8192 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
//void nmppsDot_8s(nm8s*  pSrcVec1,  nm8s* pSrcVec2, int nSize, int64b* pnRes, void* pTmpBuff);
//void nmppsDot_8s(nm8s*  pSrcVec1, nm16s* pSrcVec2, int nSize, int64b* pnRes, void* pTmpBuff);
//void nmppsDot_8s(nm8s*  pSrcVec1, nm32s* pSrcVec2, int nSize, int64b* pnRes, void* pTmpBuff);
//void nmppsDot_8s(nm8s*  pSrcVec1, nm64s* pSrcVec2, int nSize, int64b* pnRes);
//
//void nmppsDot_16s(nm16s* pSrcVec1, nm16s* pSrcVec2, int nSize, int64b* pnRes, void* pTmpBuff);
//void nmppsDot_16s(nm16s* pSrcVec1, nm32s* pSrcVec2, int nSize, int64b* pnRes, void* pTmpBuff);
//void nmppsDot_16s(nm16s* pSrcVec1, nm64s* pSrcVec2, int nSize, int64b* pnRes);
//
//void nmppsDot_32s(nm32s* pSrcVec1, nm32s* pSrcVec2, int nSize, int64b* pnRes, void* pTmpBuff);
//void nmppsDot_32s(nm32s* pSrcVec1, nm64s* pSrcVec2, int nSize, int64b* pnRes);
//
//void nmppsDot_64s(nm64s* pSrcVec1, nm64s* pSrcVec2, int nSize, int64b* pnRes);
    //! \}

	/**
	\internal
	\addtogroup nmppsDot
	*/
	//! \{
//void nmppsDot_16sc(nm16sc *pSrcVec1, nm64sc *pSrcVec2, int nSize, nm64sc *pnRes);//pc version is not available
//void nmppsDot_64sc(nm64sc *pSrcVec1, nm64sc *pSrcVec2, int nSize, nm64sc *pnRes);
	//! \}

//*****************************************************************************
	/**
	\defgroup nmppsWAdd2V nmppsWAdd2V
	\ingroup vArithmetics
	\brief
		\ru ������������ ���������� ������������ ��������� ���� ��������
		\en Elementwise weighted multiplication of two vectors

		\~
	
	\f[ 
        pDstVec[i]  =  nW1 \cdot pSrcVec1[i] + nW2 \cdot pSrcVec2[i], 
	\f]
	
	\f[  = \overline{0 \ldots nSize-1}    \f]

	\~
	\param pSrcVec1
		\ru 1-�� ������� ������. 
		\en 1-st input vec
		\~
	\param nW1
		\ru 1-�� ������� �����������
		\en 2-nd weight coefficient 
		\~
	\param pSrcVec2
		\ru 2-�� ������� ������. 
		\en 2-nd input vec
		\~
	\param nW2
		\ru 2-�� ������� �����������
		\en 2-nd weight coefficient 
		\~
	\param nSize
		\ru ������ �������� � ���������. 
		\en Vector size in elements
		\~
	\retval pDstVec
        \ru �������������� ������. 
        \en The result vec. 
		\~
   \return \e void 

  \par
	\xmlonly
	 <testperf> 
			<param> pSrcVec1 </param> <values> L G </values>
			<param> pSrcVec2 </param> <values> L G </values>
			<param> pDstVec </param> <values> L G </values>
			<param> nW1 </param> <values> 0 </values>
			<param> nW2 </param> <values> 0 </values>
			<param> nSize </param> <values> 8 128 1024 10240 </values>
			<size> nSize </size>
	 </testperf>
	\endxmlonly


	*/

   //! \{    
//void nmppsWAdd2V(nm8s* pSrcVec1,int nW1,nm8s* pSrcVec2,int nW2, nm16s* pDstVec, int nSize);
//void nmppsWAdd2V(nm16s* pSrcVec1,int nW1,nm16s* pSrcVec2,int nW2, nm32s* pDstVec, int nSize);
//void nmppsWAdd2V(nm32s* pSrcVec1,nm64s nW1,nm32s* pSrcVec2,nm64s nW2, nm64s* pDstVec, int nSize);
    //! \}


#endif // _VECARITM_H_INCLUDED_
