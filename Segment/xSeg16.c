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
    case '0': Seg->Data = (COM)?COM16H_0:COM16L_0;                break;
    case '1': Seg->Data = (COM)?COM16H_1:COM16L_1;                break;
    case '2': Seg->Data = (COM)?COM16H_2:COM16L_2;                break;
    case '3': Seg->Data = (COM)?COM16H_3:COM16L_3;                break;
    case '4': Seg->Data = (COM)?COM16H_4:COM16L_4;                break;
    case '5': Seg->Data = (COM)?COM16H_5:COM16L_5;                break;
    case '6': Seg->Data = (COM)?COM16H_6:COM16L_6;                break;
    case '7': Seg->Data = (COM)?COM16H_7:COM16L_7;                break;
    case '8': Seg->Data = (COM)?COM16H_8:COM16L_8;                break;
    case '9': Seg->Data = (COM)?COM16H_9:COM16L_9;                break;
    case '.': Seg->Data = (COM)?COM16H_DOT:COM16L_DOT;            break;

    //High Case
    case 'A':  Seg->Data = (COM)?COM16H_A:COM16L_A;               break;
    case 'B':  Seg->Data = (COM)?COM16H_B:COM16L_B;               break;
    case 'C':  Seg->Data = (COM)?COM16H_C:COM16L_C;               break;
    case 'D':  Seg->Data = (COM)?COM16H_D:COM16L_D;               break;
    case 'E':  Seg->Data = (COM)?COM16H_E:COM16L_E;               break;
    case 'F':  Seg->Data = (COM)?COM16H_F:COM16L_F;               break;
    case 'G':  Seg->Data = (COM)?COM16H_G:COM16L_G;               break;
    case 'H':  Seg->Data = (COM)?COM16H_H:COM16L_H;               break;
    case 'I':  Seg->Data = (COM)?COM16H_I:COM16L_I;               break;
    case 'J':  Seg->Data = (COM)?COM16H_J:COM16L_J;               break;
    case 'K':  Seg->Data = (COM)?COM16H_K:COM16L_K;               break;
    case 'L':  Seg->Data = (COM)?COM16H_L:COM16L_L;               break;
    case 'M':  Seg->Data = (COM)?COM16H_M:COM16L_M;               break;
    case 'N':  Seg->Data = (COM)?COM16H_N:COM16L_N;               break;
    case 'O':  Seg->Data = (COM)?COM16H_O:COM16L_O;               break;
    case 'P':  Seg->Data = (COM)?COM16H_P:COM16L_P;               break;
    case 'Q':  Seg->Data = (COM)?COM16H_Q:COM16L_Q;               break;
    case 'R':  Seg->Data = (COM)?COM16H_R:COM16L_R;               break;
    case 'S':  Seg->Data = (COM)?COM16H_S:COM16L_S;               break;
    case 'T':  Seg->Data = (COM)?COM16H_T:COM16L_T;               break;
    case 'U':  Seg->Data = (COM)?COM16H_U:COM16L_U;               break;
    case 'V':  Seg->Data = (COM)?COM16H_V:COM16L_V;               break;
    case 'W':  Seg->Data = (COM)?COM16H_W:COM16L_W;               break;
    case 'X':  Seg->Data = (COM)?COM16H_X:COM16L_X;               break;
    case 'Y':  Seg->Data = (COM)?COM16H_Y:COM16L_Y;               break;
    case 'Z':  Seg->Data = (COM)?COM16H_Z:COM16L_Z;               break;

    //Low Case
    case 'a':  Seg->Data = (COM)?COM16H_a:COM16L_a;               break;
    case 'b':  Seg->Data = (COM)?COM16H_b:COM16L_b;               break;
    case 'c':  Seg->Data = (COM)?COM16H_c:COM16L_c;               break;
    case 'd':  Seg->Data = (COM)?COM16H_d:COM16L_d;               break;
    case 'e':  Seg->Data = (COM)?COM16H_e:COM16L_e;               break;
    case 'f':  Seg->Data = (COM)?COM16H_f:COM16L_f;               break;
    case 'g':  Seg->Data = (COM)?COM16H_g:COM16L_g;               break;
    case 'h':  Seg->Data = (COM)?COM16H_h:COM16L_h;               break;
    case 'i':  Seg->Data = (COM)?COM16H_i:COM16L_i;               break;
    case 'j':  Seg->Data = (COM)?COM16H_j:COM16L_j;               break;
    case 'k':  Seg->Data = (COM)?COM16H_k:COM16L_k;               break;
    case 'l':  Seg->Data = (COM)?COM16H_l:COM16L_l;               break;
    case 'm':  Seg->Data = (COM)?COM16H_m:COM16L_m;               break;
    case 'n':  Seg->Data = (COM)?COM16H_n:COM16L_n;               break;
    case 'o':  Seg->Data = (COM)?COM16H_o:COM16L_o;               break;
    case 'p':  Seg->Data = (COM)?COM16H_p:COM16L_p;               break;
    case 'q':  Seg->Data = (COM)?COM16H_q:COM16L_q;               break;
    case 'r':  Seg->Data = (COM)?COM16H_r:COM16L_r;               break;
    case 's':  Seg->Data = (COM)?COM16H_s:COM16L_s;               break;
    case 't':  Seg->Data = (COM)?COM16H_t:COM16L_t;               break;
    case 'u':  Seg->Data = (COM)?COM16H_u:COM16L_u;               break;
    case 'v':  Seg->Data = (COM)?COM16H_v:COM16L_v;               break;
    case 'w':  Seg->Data = (COM)?COM16H_w:COM16L_w;               break;
    case 'x':  Seg->Data = (COM)?COM16H_x:COM16L_x;               break;
    case 'y':  Seg->Data = (COM)?COM16H_y:COM16L_y;               break;
    case 'z':  Seg->Data = (COM)?COM16H_z:COM16L_z;               break;

    //Others
    case '%':  Seg->Data = (COM)?COM16H_PERCENT:COM16L_PERCENT;   break;
    case '+':  Seg->Data = (COM)?COM16H_PLUS:COM16L_PLUS;         break;
    case '-':  Seg->Data = (COM)?COM16H_MINUS:COM16L_MINUS;       break;
    case '*':  Seg->Data = (COM)?COM16H_MUTIPLE:COM16L_MUTIPLE;   break;
    case '/':  Seg->Data = (COM)?COM16H_DIVIDE:COM16L_DIVIDE;     break;
  //case '\':  Seg->Data = (COM)?COM16H_MOD:COM16L_MOD;           break;
    case '[':  Seg->Data = (COM)?COM16H_FBRACKET:COM16L_FBRACKET; break;
    case ']':  Seg->Data = (COM)?COM16H_BBRACKET:COM16L_BBRACKET; break;
    case '=':  Seg->Data = (COM)?COM16H_EQ:COM16L_EQ;             break;
    case '>':  Seg->Data = (COM)?COM16H_GT:COM16L_GT;             break;
    case '<':  Seg->Data = (COM)?COM16H_LT:COM16L_LT;             break;
    case '}':  Seg->Data = (COM)?COM16H_GTEQ:COM16L_GTEQ;         break;  //Substitute
    case '{':  Seg->Data = (COM)?COM16H_LTEQ:COM16L_LTEQ;         break;  //Substitute
    case '^':  Seg->Data = (COM)?COM16H_XOR:COM16L_XOR;           break;
    default:   Seg->Data = (COM)?COM16H_NONE:COM16L_NONE;         break;
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