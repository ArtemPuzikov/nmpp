//------------------------------------------------------------------------
//
//  $Workfile:: iFiltration.h                $
//
//  Векторно-матричная библиотека
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/02/10 12:36:38 $
//
//! \if file_doc
//!
//! \file   vFilter.h
//! \author Сергей Мушкаев
//! \brief  Определение функций фильтраций для векторов.
//!
//! \endif
//!
//------------------------------------------------------------------------

#ifndef _IFILTRATION_H_INCLUDED_
#define _IFILTRATION_H_INCLUDED_

#include "iFilter.h"
//*****************************************************************************

    /**
	\internal
    \defgroup IMG_Median3x3 IMG_Median3x3
    \ingroup iFiltration
 	\brief
		\ru Медианная фильтрация окном 3х3
		\en Median filtration by 3x3 window

		\~
	\~
	\param pSrc
        \ru Исходное изображение. 
        \en Input image. 
		\~
	\param *pDst
        \ru Результирующее изображение; 
        \en Output image. 
		\~
	\param nWidth
        \ru Ширина изображения; Кратность согласно входному типу.
        \en Image width; 
		\~
	\param nHeight
        \ru Высота изображения [32,64,96....]. 
        \en Image height [32,64,96....]. 
		\~
	\param pLTmp
        \ru Временный буфер  размера  nm64s[3*nHeight] на локальной шине. 
        \en Temporary buffer with size of nm64s[3*nHeight] on local bus. 
		\~
	\param pGTmp
        \ru Временный буфер  размера  nm64s[3*nHeight] на глобальной шине. 
        \en Temporary buffer with size of nm64s[3*nHeight] on global bus. 
		
		\~
	\par
    \xmlonly
			<testperf> 
					 <param> pSrc </param> <values> L G </values>
					 <param> pDst </param> <values> L G </values>
					 <param> pLTmp </param> <values> L G </values>
					 <param> pGTmp </param> <values> L G </values>
					 <param> nWidth </param> <values>  128 512 </values>
					 <param> nHeight </param> <values> 128 512 </values>
					 <size> nWidth*nHeight </size>
			</testperf>
	\endxmlonly
	*/
    //! \{
void IMG_Median3x3(  nm8s7b * pSrc, nm8s7b *pDst, int nWidth, int nHeight, void* pLTmp , void* pGTmp );
    //! \}





#endif // _IFILTER_H_INCLUDED_


