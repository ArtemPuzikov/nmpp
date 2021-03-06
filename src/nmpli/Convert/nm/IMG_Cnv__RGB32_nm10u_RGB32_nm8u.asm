//------------------------------------------------------------------------
//
//  $Workfile:: ConvertRGB30_RGB24.ASM $
//
//  ���������� ��������� �����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/02/10 12:36:38 $
//
//! \if file_doc
//!
//! \file   ConvertRGB30_RGB24.asm
//! \author ������ ��������.
//! \brief  ������� ������������ �������� RGB �� 10-�� ���������� �������������
//!         � 8-�� ���������. 
//!
//! \endif
//!
//------------------------------------------------------------------------
extern vec_vsum_data_0: label;
global _IMG_Convert__F13RGB32_nm10uP12RGB32_nm8uPi: label;
global _void._.8.8IMG_Convert.1class._RGB32_nm10u._.0.9._class._RGB32_nm8u._.0.9._int.2 :label;

    //--------------------------------------------------------------------
begin ".text_nmpli"
Weights:	long[8] = (
		00000000000000001hl,
		00000000000000100hl,
		00000000000010000hl,
		00000000000000000hl,
		00000000100000000hl,
		00000010000000000hl,
		00001000000000000hl,
		00000000000000000hl);

    //--------------------------------------------------------------------
    //! \fn  void IMG_Convert(RGB32_nm10u* pSrcImg, RGB32_nm8u* pDstImg, int nSize); 
    //!
	//! \perfinclude _IMG_Convert__F11RGB32_nm10uP10RGB32_nm8uPi.html
    //--------------------------------------------------------------------
<_IMG_Convert__F13RGB32_nm10uP12RGB32_nm8uPi>
<_void._.8.8IMG_Convert.1class._RGB32_nm10u._.0.9._class._RGB32_nm8u._.0.9._int.2>
    ar5 = sp - 2;
    push ar0, gr0 with gr0 = false;
    push ar5, gr5 with gr0++;
    push ar6, gr6 with gr0++;

    ar0 = [--ar5] with gr6 = gr0;
    ar6 = [--ar5];
    gr5 = [--ar5];
    
    nb1 = 080808080h;
	sb = 080200802h;
	ar5 = Weights;
	rep 8 wfifo = [ar5++], ftw, wtw;

    call vec_vsum_data_0 with gr5 >>= 1;
    
    pop ar6, gr6;
    pop ar5, gr5;
    pop ar0, gr0;
    return;
    //--------------------------------------------------------------------
end ".text_nmpli";
