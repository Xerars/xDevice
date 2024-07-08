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
    case '0': Seg->Data = (COM)?COMH_0:COML_0;       break;
    case '1': Seg->Data = (COM)?COMH_1:COML_1;       break;
    case '2': Seg->Data = (COM)?COMH_2:COML_2;       break;
    case '3': Seg->Data = (COM)?COMH_3:COML_3;       break;
    case '4': Seg->Data = (COM)?COMH_4:COML_4;       break;
    case '5': Seg->Data = (COM)?COMH_5:COML_5;       break;
    case '6': Seg->Data = (COM)?COMH_6:COML_6;       break;
    case '7': Seg->Data = (COM)?COMH_7:COML_7;       break;
    case '8': Seg->Data = (COM)?COMH_8:COML_8;       break;
    case '9': Seg->Data = (COM)?COMH_9:COML_9;       break;
    case '.': Seg->Data = (COM)?COMH_DOT:COML_DOT;   break;
    //High Case
    case 'A': Seg->Data = (COM)?COMH_A:COML_A;       break;
    case 'C': Seg->Data = (COM)?COMH_C:COML_C;       break;
    case 'E': Seg->Data = (COM)?COMH_E:COML_E;       break;
    case 'F': Seg->Data = (COM)?COMH_F:COML_F;       break;
    case 'G': Seg->Data = (COM)?COMH_G:COML_G;       break;
    case 'H': Seg->Data = (COM)?COMH_H:COML_H;       break;
    case 'I': Seg->Data = (COM)?COMH_I:COML_I;       break;
    case 'L': Seg->Data = (COM)?COMH_L:COML_L;       break;
    case 'N': Seg->Data = (COM)?COMH_N:COML_N;       break;
    case 'O': Seg->Data = (COM)?COMH_O:COML_O;       break;
    case 'P': Seg->Data = (COM)?COMH_P:COML_P;       break;
    case 'S': Seg->Data = (COM)?COMH_S:COML_S;       break;
    case 'Y': Seg->Data = (COM)?COMH_Y:COML_Y;       break;
    //Low Case
    case 'b': Seg->Data = (COM)?COMH_b:COML_b;       break;
    case 'c': Seg->Data = (COM)?COMH_c:COML_c;       break;
    case 'd': Seg->Data = (COM)?COMH_d:COML_d;       break;
    case 'g': Seg->Data = (COM)?COMH_g:COML_g;       break;
    case 'h': Seg->Data = (COM)?COMH_h:COML_h;       break;
    case 'i': Seg->Data = (COM)?COMH_i:COML_i;       break;
    case 'j': Seg->Data = (COM)?COMH_j:COML_j;       break;
    case 'l': Seg->Data = (COM)?COMH_l:COML_l;       break;
    case 'n': Seg->Data = (COM)?COMH_n:COML_n;       break;
    case 'o': Seg->Data = (COM)?COMH_o:COML_o;       break;
    case 'q': Seg->Data = (COM)?COMH_q:COML_q;       break;
    case 'r': Seg->Data = (COM)?COMH_r:COML_r;       break;
    case 't': Seg->Data = (COM)?COMH_t:COML_t;       break;
    case 'u': Seg->Data = (COM)?COMH_u:COML_u;       break;
    default:  Seg->Data = (COM)?COMH_NONE:COML_NONE; break;
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