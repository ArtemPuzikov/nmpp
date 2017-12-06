//------------------------------------------------------------------------
//
//  $Workfile:: vTransform. $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:02 $
//
//! \if file_doc
//!
//! \file   vTransform.h
//! \author ������ �������
//! \brief  ����������� ������� �������������� �� �������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#ifndef _VTRANSFORM_H_INCLUDED_
#define _VTRANSFORM_H_INCLUDED_


    /**
    \defgroup VEC_QSort VEC_QSort
    \ingroup vTransform
    \brief
        \ru ���������� ������� �� ��������. 
        \en Descending sort of an array. 
		\~
    \param	pSrcDstVec	
        \ru ������� � �������������� ������. 
        \en Input and result vec. 
		\~
    \param	nSize		
        \ru ������ ������� � ���������. 
        \en Vector size in elements. 
		\~
    \return \e void
    
    \restr 
        \ru ������� �������� ����������, ��������� ��������� ����� ����,
			������� ������ ����� ������ ���� ������ 4*log2(nSize) 32-������ ����
			� ������ ������ (�������� ������� ����������� ������������)
			� ������ 6*nSize 32-������ ���� � ������ ������
			(�������� ������� ��� �����������) 
        \en The function operates recursively and transfers elements using the stack. 
			That is why the stack size should be greater than 4*log2(nSize) 32-bit words
			at best (elements of the array are located at random) and greater than 6*nSize 32-bit words
			at worst (elements of the array are already ordered) 
		\~
    \par
    \xmlonly
        <testperf> 
			<init> 	
				nmppsRandUniform_32u((nm32u*)L,1024);
				nmppsRShiftC_32s((nm32s*)L, 1, (nm32s*)L, 1024);
				nmppsRandUniform_32u((nm32u*)G,1024);
				nmppsRShiftC_32s((nm32s*)G, 1, (nm32s*)G, 1024);
             </init>
             <param> pSrcDstVec </param> <values> L G 	  	</values>
             <param> nSize </param> <values> 256 	</values>
        </testperf>
        <testperf> 
			<init> 
				nmppsRandUniform_32u((nm32u*)G,1024);
				nmppsRShiftC_32s((nm32s*)G, 1, (nm32s*)G, 1024);
             </init>
             <param> pSrcDstVec </param> <values> G </values>
             <param> nSize </param> <values> 8 128 256 </values>
        </testperf>
    \endxmlonly

    */
    //! \{
void nmppsQSort_32s(nm32s* pSrcDstVec, int nSize);
    //! \}

//*****************************************************************************

    /**
    \defgroup nmppsRemap_ nmppsRemap_
    \ingroup vTransform
    \brief
        \ru ������������������ ��������� ������� �� �������. 
        \en Reodering of vector eements by table . 
	
		\~
	
	\f[ 
        pDstVec[i]=pSrcVec[pRemapTable[i]],
    \f]
    
	\f[ i = \overline{0 \ldots nSize-1} \f]
    
		\~
    \param pSrcVec     
        \ru ������� ������. 
        \en Input vec. 
		\~
    \param pRemapTable 
        \ru ������� ����� �������� ��� ������������������. 
        \en Index reordering table. 
		\~
    \param nDstVecSize  
        \ru ������ ��������������� ������� � ���������. 
        \en Size in elements for destination vec. 
		\~
    \param pTmpBuf1     
        \ru ��������� ������ nm32u pTmpBuf1[nSrcVecSize]. 
        \en Temporary buffer nm32u pTmpBuf1[nSrcVecSize]. 
		\~
    \param pTmpBuf2     
        \ru ��������� ������ nm32u pTmpBuf2[nDstVecSize]. 
        \en Temporary buffer nm32u pTmpBuf2[nDstVecSize]. 


    \retval pDstVec		
        \ru �������������� ������ nm8u pDstVec[nDstVecSize]. 
        \en Result vec nm8u pDstVec[nDstVecSize]. 

		\~
    \return \e void 
    
	\code 
		// ������� 
		// void nmppsRemap_8u(nm8u* pSrcVec, nm8u* pDstVec, nm32s* pRemapTable, int nSrcVecSize, int nDstVecSize, void* pTmpBuf1, void* pTmpBuf2);
		// ��������� �������� ��������: 
	    nmppsConvert_8u((nm8u*) pSrcVec, (nm32u*)pTmpBuf1,nSrcVecSize);
	    nmppsRemap_32u((nm32u*)pTmpBuf1,(nm32u*)pTmpBuf2,RemapTable,DstVecSize);
	    nmppsConvert_32s((nm32s*)pTmpBuf2,(nm8s*) pDstVec, DstVecSize);
	\endcode
	
	\note
        \ru ����������� ������������� inplace ���������� ������������ ������ �� 
	        ������������������ ��������� ������/������: \n
        \en Possible using of in place parameters can be determined from
		\~
            the folowing sequence of actions : \n
	    \~ - pSrcVec => pTmpBuf1 - \ru inplace ��������; \n 
                                   \en inplace is not valid; \n
	    \~ - pTmpBuf1=>pTmpBuf2 -  \ru inplace ��������; \n 
                                   \en inplce is not valid; \n 
	    \~ - pTmpBuf2=>pDstVec  -  \ru inplace ��������; \n
                                   \en inplace is not valid; \n 

								   
    \par
    \xmlonly
        <testperf> 
             <param> pSrcVec </param> <values> L G </values>
             <param> pDstVec </param> <values> L G </values>
             <param> pRemapTable </param> <values> L G </values>
             <param> nDstVecSize </param> <values> 10240 </values>
        </testperf>
        <testperf> 
             <param> pSrcVec </param> <values> L </values>
             <param> pDstVec </param> <values> G </values>
             <param> pRemapTable </param> <values> G </values>
             <param> nDstVecSize </param> <values> 8 128 1024 10240 </values>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppsRemap_32u(nm32u* pSrcVec, nm32u* pDstVec, nm32s* pRemapTable, int nDstVecSize);
void nmppsRemap_8u(nm8u* pSrcVec, nm8u* pDstVec, nm32s* pRemapTable, int nSrcVecSize, int nDstVecSize, void* pTmpBuf1, void* pTmpBuf2);
    //! \}




	/**
	\internal
	\defgroup Manipulation Manipulation
	\ingroup vTransform
	\brief
		\ru ����������� ������� �� ��������� ��������� ��������
		\en Array splitting to several arrays
		
		\~
		
	\f[ pDst4Vec[i][j]=pSrcVec[j][i] \f]	
	\~
    \param pSrcVec     
        \ru ������� ������. 
        \en Input vec. 
		\~
	\param pDst4Vec
		\ru ������ �� 4 ���������� �� ��������� �������
		\en Array of 4 pointers to separeted arrays
		\~
	\param nSize
		\ru ������ ��������
		\en Size of arrays

		\~
    \par
    \xmlonly
		<testperf>
			<param> pSrcVec </param> <values> L G	</values>
			<param> pDstVec </param> <values> L G	</values>
			<param> nSize	</param> <values> 1024 10240 </values>
		</testperf>
	\endxmlonly
	
	\todo 	Impelenment NM versin of nmppsSplit_(v4nm16s* pSrcVec, nm16s** pDst4Vec, int nSize);

	*/
	//! \{
void nmppsSplit_(v4nm16s* pSrcVec, nm16s** pDst4Vec, int nSize);
	//! \}
	
	
	/**
	    \defgroup nmppSplit nmppSplit
        \ingroup vTransform
    
	 *  \brief ���������� ������ �� ���, ��������� �� ������ � �������� ���������
	 *  
	 *  \param [in]  src  ������� ������
	 *  \param [out] dst1 �������� ������ ������� size/2 
	 *  \param [out] dst2 �������� ������ ������� size/2 
	 *  \param [in]  size ������ ��������� ������� � ���������. ��������� ��������� size ������ �������������� ���� ������� 64-�. ������. 
	 *  \param [in]  tmpSizeofDst ��������� ������ ������� size/2 
	 *  \return 
	 *  
	 *  \details Details 
	 *  ������������ ������������������ ����������� ��� ���������� �������, �������� � ��������� �������� � ������ ������ ������. ������� dst1 � dst2 ����� ��������� � ����� �����.
	 *  ����  �����������������  �� 64-�. ����� ���������� = 2.1 ����� (��� size=10240 ����) � 2.5 ����� (��� size=4096 ����)
	 */
	void nmppsSplit_8s(nm8s* src, nm8s* dst1, nm8s* dst2, int size, nm8s* tmpSizeofDst);
	
   /**
	    \defgroup nmppSplitEco nmppSplitEco
        \ingroup vTransform
    
	 *  \brief ���������� ������ �� ���, ��������� �� ������ � �������� ���������
	 *  
	 *  \param [in]  src  ������� ������
	 *  \param [out] dst1 �������� ������ ������� size/2 
	 *  \param [out] dst2 �������� ������ ������� size/2 
	 *  \param [in]  size ������ ��������� ������� � ���������. ��������� ��������� size ������ �������������� ���� ������� 64-�. ������. 
	 *  \return 
	 *  
	 *  \details Details 
	 *  ������������ ������������������ ����������� ��� ���������� �������, �������� �������� � ������ ������ ������. ������� dst1 � dst2 ����� ��������� � ����� �����.
	 *  ����  �����������������  �� 64-�. ����� ���������� = 2.14 ����� (��� size=10240 ����) � 2.6 ����� (��� size=4096 ����)
	 */
	void nmppsSplitEco_8s(nm8s* src, nm8s* dst1, nm8s* dst2, int size);	

#endif //_VTRANSFORM_H_INCLUDED_