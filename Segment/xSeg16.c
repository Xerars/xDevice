//[Custom Lib Include]
#include "xSeg16.h"

///@Function: Seg16_Set
///@Descript: Segment16 Set Value
void Seg16_Set(Seg16_t *Seg,SG16_U32 Value)
{
  Seg->Data = Value;
  //Swap
  if(Seg->Seq == SEG16_SEQ_A2G)    //a,b,c,d,e,f,g
    SWAP_ENDIAN17(Seg->Data);
}


///@Function: Seg16_ParseSet
///@Descript: Parse Character and Set Segment-16 Data
void Seg16_ParseSet(Seg16_t *Seg,SG16_U8 Ch)
{
  SG16_U8 COM = (Seg->CMode == SEG16_COMM_HIGH);   //Boolean

  switch(Ch)
  { //Num
    case '0': Seg->Data = (COM)?COMH_0:COML_0;                break;
    case '1': Seg->Data = (COM)?COMH_1:COML_1;                break;
    case '2': Seg->Data = (COM)?COMH_2:COML_2;                break;
    case '3': Seg->Data = (COM)?COMH_3:COML_3;                break;
    case '4': Seg->Data = (COM)?COMH_4:COML_4;                break;
    case '5': Seg->Data = (COM)?COMH_5:COML_5;                break;
    case '6': Seg->Data = (COM)?COMH_6:COML_6;                break;
    case '7': Seg->Data = (COM)?COMH_7:COML_7;                break;
    case '8': Seg->Data = (COM)?COMH_8:COML_8;                break;
    case '9': Seg->Data = (COM)?COMH_9:COML_9;                break;
    case '.': Seg->Data = (COM)?COMH_DOT:COML_DOT;            break;

    //High Case
    case 'A':  Seg->Data = (COM)?COMH_A:COML_A;               break;
    case 'B':  Seg->Data = (COM)?COMH_B:COML_B;               break;
    case 'C':  Seg->Data = (COM)?COMH_C:COML_C;               break;
    case 'D':  Seg->Data = (COM)?COMH_D:COML_D;               break;
    case 'E':  Seg->Data = (COM)?COMH_E:COML_E;               break;
    case 'F':  Seg->Data = (COM)?COMH_F:COML_F;               break;
    case 'G':  Seg->Data = (COM)?COMH_G:COML_G;               break;
    case 'H':  Seg->Data = (COM)?COMH_H:COML_H;               break;
    case 'I':  Seg->Data = (COM)?COMH_I:COML_I;               break;
    case 'J':  Seg->Data = (COM)?COMH_J:COML_J;               break;
    case 'K':  Seg->Data = (COM)?COMH_K:COML_K;               break;
    case 'L':  Seg->Data = (COM)?COMH_L:COML_L;               break;
    case 'M':  Seg->Data = (COM)?COMH_M:COML_M;               break;
    case 'N':  Seg->Data = (COM)?COMH_N:COML_N;               break;
    case 'O':  Seg->Data = (COM)?COMH_O:COML_O;               break;
    case 'P':  Seg->Data = (COM)?COMH_P:COML_P;               break;
    case 'Q':  Seg->Data = (COM)?COMH_Q:COML_Q;               break;
    case 'R':  Seg->Data = (COM)?COMH_R:COML_R;               break;
    case 'S':  Seg->Data = (COM)?COMH_S:COML_S;               break;
    case 'T':  Seg->Data = (COM)?COMH_T:COML_T;               break;
    case 'U':  Seg->Data = (COM)?COMH_U:COML_U;               break;
    case 'V':  Seg->Data = (COM)?COMH_V:COML_V;               break;
    case 'W':  Seg->Data = (COM)?COMH_W:COML_W;               break;
    case 'X':  Seg->Data = (COM)?COMH_X:COML_X;               break;
    case 'Y':  Seg->Data = (COM)?COMH_Y:COML_Y;               break;
    case 'Z':  Seg->Data = (COM)?COMH_Z:COML_Z;               break;

    //Low Case
    case 'a':  Seg->Data = (COM)?COMH_a:COML_a;               break;
    case 'b':  Seg->Data = (COM)?COMH_b:COML_b;               break;
    case 'c':  Seg->Data = (COM)?COMH_c:COML_c;               break;
    case 'd':  Seg->Data = (COM)?COMH_d:COML_d;               break;
    case 'e':  Seg->Data = (COM)?COMH_e:COML_e;               break;
    case 'f':  Seg->Data = (COM)?COMH_f:COML_f;               break;
    case 'g':  Seg->Data = (COM)?COMH_g:COML_g;               break;
    case 'h':  Seg->Data = (COM)?COMH_h:COML_h;               break;
    case 'i':  Seg->Data = (COM)?COMH_i:COML_i;               break;
    case 'j':  Seg->Data = (COM)?COMH_j:COML_j;               break;
    case 'k':  Seg->Data = (COM)?COMH_k:COML_k;               break;
    case 'l':  Seg->Data = (COM)?COMH_l:COML_l;               break;
    case 'm':  Seg->Data = (COM)?COMH_m:COML_m;               break;
    case 'n':  Seg->Data = (COM)?COMH_n:COML_n;               break;
    case 'o':  Seg->Data = (COM)?COMH_o:COML_o;               break;
    case 'p':  Seg->Data = (COM)?COMH_p:COML_p;               break;
    case 'q':  Seg->Data = (COM)?COMH_q:COML_q;               break;
    case 'r':  Seg->Data = (COM)?COMH_r:COML_r;               break;
    case 's':  Seg->Data = (COM)?COMH_s:COML_s;               break;
    case 't':  Seg->Data = (COM)?COMH_t:COML_t;               break;
    case 'u':  Seg->Data = (COM)?COMH_u:COML_u;               break;
    case 'v':  Seg->Data = (COM)?COMH_v:COML_v;               break;
    case 'w':  Seg->Data = (COM)?COMH_w:COML_w;               break;
    case 'x':  Seg->Data = (COM)?COMH_x:COML_x;               break;
    case 'y':  Seg->Data = (COM)?COMH_y:COML_y;               break;
    case 'z':  Seg->Data = (COM)?COMH_z:COML_z;               break;

    //Others
    case '%':  Seg->Data = (COM)?COMH_PERCENT:COML_PERCENT;   break;
    case '+':  Seg->Data = (COM)?COMH_PLUS:COML_PLUS;         break;
    case '-':  Seg->Data = (COM)?COMH_MINUS:COML_MINUS;       break;
    case '*':  Seg->Data = (COM)?COMH_MUTIPLE:COML_MUTIPLE;   break;
    case '/':  Seg->Data = (COM)?COMH_DIVIDE:COML_DIVIDE;     break;
  //case '\':  Seg->Data = (COM)?COMH_MOD:COML_MOD;           break;
    case '[':  Seg->Data = (COM)?COMH_FBRACKET:COML_FBRACKET; break;
    case ']':  Seg->Data = (COM)?COMH_BBRACKET:COML_BBRACKET; break;
    case '=':  Seg->Data = (COM)?COMH_EQ:COML_EQ;             break;
    case '>':  Seg->Data = (COM)?COMH_GT:COML_GT;             break;
    case '<':  Seg->Data = (COM)?COMH_LT:COML_LT;             break;
    case '}':  Seg->Data = (COM)?COMH_GTEQ:COML_GTEQ;         break;  //Substitute
    case '{':  Seg->Data = (COM)?COMH_LTEQ:COML_LTEQ;         break;  //Substitute
    case '^':  Seg->Data = (COM)?COMH_XOR:COML_XOR;           break;
    default:   Seg->Data = (COM)?COMH_NONE:COML_NONE;         break;
  }

  if(Seg->Seq == SEG16_SEQ_A2G)    //a1,a2,b,c,d1,d2,e,f,g1,g2,h,j,k,l,m,n
    SWAP_ENDIAN17(Seg->Data);
}


///@Function: Seg16_Upload
///@Descript: Upload Segment16 Output Status
void Seg16_Upload(Seg16_t *Seg)
{
  //Upload
  Seg->Cb.S16_A1((Seg->Data & 0x00001));
  Seg->Cb.S16_A2((Seg->Data & 0x00002)>>1);
  Seg->Cb.S16_B ((Seg->Data & 0x00004)>>2);
  Seg->Cb.S16_C ((Seg->Data & 0x00008)>>3);
  Seg->Cb.S16_D1((Seg->Data & 0x00010)>>4);
  Seg->Cb.S16_D2((Seg->Data & 0x00020)>>5);
  Seg->Cb.S16_E ((Seg->Data & 0x00040)>>6);
  Seg->Cb.S16_F ((Seg->Data & 0x00080)>>7);
  Seg->Cb.S16_G1((Seg->Data & 0x00100)>>8);
  Seg->Cb.S16_G2((Seg->Data & 0x00200)>>9);
  Seg->Cb.S16_H ((Seg->Data & 0x00400)>>10);
  Seg->Cb.S16_J ((Seg->Data & 0x00800)>>11);
  Seg->Cb.S16_K ((Seg->Data & 0x01000)>>12);
  Seg->Cb.S16_L ((Seg->Data & 0x02000)>>13);
  Seg->Cb.S16_M ((Seg->Data & 0x04000)>>14);
  Seg->Cb.S16_N ((Seg->Data & 0x08000)>>15);
  Seg->Cb.S16_DOT((Seg->Data & 0x010000)>>16);
}