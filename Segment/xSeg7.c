//[Custom Lib Include]
#include "xSeg7.h"

///@Function: Seg7_Set
///@Descript: Segment-7 Set Value
void Seg7_Set(Seg7_t *Seg,SG7_U8 Value)
{
  Seg->Data = Value;
  //Swap
  if(Seg->Seq == SEG7_SEQ_A2G)    //a,b,c,d,e,f,g
    SWAP_ENDIAN8(Seg->Data);
}


///@Function: Seg7_ParseSet
///@Descript: Parse Character and Set Segment-7 Data
void Seg7_ParseSet(Seg7_t *Seg,SG7_U8 Ch)
{
  SG7_U8 COM = (Seg->CMode == SEG7_COMM_HIGH);   //Boolean

  switch(Ch)
  { //Num
    case '0': Seg->Data = (COM)?COM7H_0:COM7L_0;       break;
    case '1': Seg->Data = (COM)?COM7H_1:COM7L_1;       break;
    case '2': Seg->Data = (COM)?COM7H_2:COM7L_2;       break;
    case '3': Seg->Data = (COM)?COM7H_3:COM7L_3;       break;
    case '4': Seg->Data = (COM)?COM7H_4:COM7L_4;       break;
    case '5': Seg->Data = (COM)?COM7H_5:COM7L_5;       break;
    case '6': Seg->Data = (COM)?COM7H_6:COM7L_6;       break;
    case '7': Seg->Data = (COM)?COM7H_7:COM7L_7;       break;
    case '8': Seg->Data = (COM)?COM7H_8:COM7L_8;       break;
    case '9': Seg->Data = (COM)?COM7H_9:COM7L_9;       break;
    case '.': Seg->Data = (COM)?COM7H_DOT:COM7L_DOT;   break;
    //High Case
    case 'A': Seg->Data = (COM)?COM7H_A:COM7L_A;       break;
    case 'C': Seg->Data = (COM)?COM7H_C:COM7L_C;       break;
    case 'E': Seg->Data = (COM)?COM7H_E:COM7L_E;       break;
    case 'F': Seg->Data = (COM)?COM7H_F:COM7L_F;       break;
    case 'G': Seg->Data = (COM)?COM7H_G:COM7L_G;       break;
    case 'H': Seg->Data = (COM)?COM7H_H:COM7L_H;       break;
    case 'I': Seg->Data = (COM)?COM7H_I:COM7L_I;       break;
    case 'L': Seg->Data = (COM)?COM7H_L:COM7L_L;       break;
    case 'N': Seg->Data = (COM)?COM7H_N:COM7L_N;       break;
    case 'O': Seg->Data = (COM)?COM7H_O:COM7L_O;       break;
    case 'P': Seg->Data = (COM)?COM7H_P:COM7L_P;       break;
    case 'S': Seg->Data = (COM)?COM7H_S:COM7L_S;       break;
    case 'Y': Seg->Data = (COM)?COM7H_Y:COM7L_Y;       break;
    //Low Case
    case 'b': Seg->Data = (COM)?COM7H_b:COM7L_b;       break;
    case 'c': Seg->Data = (COM)?COM7H_c:COM7L_c;       break;
    case 'd': Seg->Data = (COM)?COM7H_d:COM7L_d;       break;
    case 'g': Seg->Data = (COM)?COM7H_g:COM7L_g;       break;
    case 'h': Seg->Data = (COM)?COM7H_h:COM7L_h;       break;
    case 'i': Seg->Data = (COM)?COM7H_i:COM7L_i;       break;
    case 'j': Seg->Data = (COM)?COM7H_j:COM7L_j;       break;
    case 'l': Seg->Data = (COM)?COM7H_l:COM7L_l;       break;
    case 'n': Seg->Data = (COM)?COM7H_n:COM7L_n;       break;
    case 'o': Seg->Data = (COM)?COM7H_o:COM7L_o;       break;
    case 'q': Seg->Data = (COM)?COM7H_q:COM7L_q;       break;
    case 'r': Seg->Data = (COM)?COM7H_r:COM7L_r;       break;
    case 't': Seg->Data = (COM)?COM7H_t:COM7L_t;       break;
    case 'u': Seg->Data = (COM)?COM7H_u:COM7L_u;       break;
    default:  Seg->Data = (COM)?COM7H_NONE:COM7L_NONE; break;
  }

  if(Seg->Seq == SEG7_SEQ_A2G)    //a,b,c,d,e,f,g
    SWAP_ENDIAN8(Seg->Data);
}


///@Function: Seg7_Upload
///@Descript: Upload Segment-7 Output Status
void Seg7_Upload(Seg7_t *Seg)
{
  //Upload
  Seg->Cb.S7_A((Seg->Data & 0x01));
  Seg->Cb.S7_B((Seg->Data & 0x02)>>1);
  Seg->Cb.S7_C((Seg->Data & 0x04)>>2);
  Seg->Cb.S7_D((Seg->Data & 0x08)>>3);
  Seg->Cb.S7_E((Seg->Data & 0x10)>>4);
  Seg->Cb.S7_F((Seg->Data & 0x20)>>5);
  Seg->Cb.S7_G((Seg->Data & 0x40)>>6);
  Seg->Cb.S7_DOT((Seg->Data & 0x80)>>7);
}