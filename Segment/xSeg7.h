#ifndef __XSEG7_H__  //__XSEG7_H__
#define __XSEG7_H__  //__XSEG7_H__

//      _____
//     |  A  |
//   F |_____| B
//     |  G  |
//   E |_____| C  O(DP)
//        D

//[Typedef Declare]
typedef unsigned char   SG7_U8;     //U8
typedef unsigned int    SG7_U16;    //U16
typedef unsigned long   SG7_U32;    //U32

typedef signed char     SG7_S8;     //S8
typedef signed int      SG7_S16;    //S16
typedef signed long     SG7_S32;    //S32

//[Macro Declare]
//COM High(Sort: .GFEDCBA)
#define COMH_NONE       0xFF        //1111-1111
#define COMH_0          0xC0        //1100-0000
#define COMH_1          0xF9        //1111-1001
#define COMH_2          0xA4        //1010-0100
#define COMH_3          0xB0        //1011-0000
#define COMH_4          0x99        //1001-1001
#define COMH_5          0x92        //1001-0010
#define COMH_6          0x82        //1000-0010
#define COMH_7          0xF8        //1111-1000
#define COMH_8          0x80        //1000-0000
#define COMH_9          0x90        //1001-0000
#define COMH_DOT        0x7F        //0111-1111

//COM Low(Sort: .GFEDCBA)
#define COML_NONE       ~COMH_NONE  //0000-0000
#define COML_0          ~COMH_0     //0011-1111
#define COML_1          ~COMH_1     //0000-0110
#define COML_2          ~COMH_2     //0101-1011
#define COML_3          ~COMH_3     //0100-1111
#define COML_4          ~COMH_4     //0110-0110
#define COML_5          ~COMH_5     //0110-1101
#define COML_6          ~COMH_6     //0111-1101
#define COML_7          ~COMH_7     //0000-0111
#define COML_8          ~COMH_8     //0111-1111
#define COML_9          ~COMH_9     //0110-1111
#define COML_DOT        ~COMH_DOT   //1000-0000

//COM High(Advance Sort: .GFEDCBA)
#define COMH_A          0x88        //1000-1000(A)
#define COMH_C          0xC6        //1100-0110(C)
#define COMH_E          0x86        //1000-0110(E)
#define COMH_F          0x8E        //1000-1110(F)
#define COMH_G          0xC2        //1100-0010(G)
#define COMH_H          0x89        //1000-1001(H)
#define COMH_I          0xF9        //1111-1001(I)
#define COMH_L          0xC7        //1100-0111(L)
#define COMH_N          0xC8        //1100-1000(N)
#define COMH_O          0xC0        //1100-0000(O)
#define COMH_P          0x8C        //1000-1100(P)
#define COMH_S          0xC1        //1100-0001(D)
#define COMH_Y          0x99        //1001-1001(Y)

#define COMH_b          0x83        //1000-0011(b)
#define COMH_c          0xA7        //1010-0111(c)
#define COMH_d          0xA1        //1010-0001(d)
#define COMH_g          0x90        //1001-0000(g)
#define COMH_h          0x8B        //1000-1011(h)
#define COMH_i          0x7A        //0111-1010(i)
#define COMH_j          0xF2        //1111-0010(j)
#define COMH_l          0xAF        //1100-1111(l)
#define COMH_n          0xAB        //1010-1011(n)
#define COMH_o          0xA3        //1010-0011(o)
#define COMH_q          0x98        //1001-1000(q)
#define COMH_r          0xAF        //1100-1111(e)
#define COMH_t          0x87        //1000-0111(t)
#define COMH_u          0xE3        //1110-0011(u)

//COM Low(Advance Sort: .GFEDCBA)
#define COML_A          ~COMH_A     //0111-0111(A)    
#define COML_C          ~COMH_C     //0011-1001(C)     
#define COML_E          ~COMH_E     //0111-1001(E)     
#define COML_F          ~COMH_F     //0111-0001(F)     
#define COML_G          ~COMH_G     //0011-1101(G)     
#define COML_H          ~COMH_H     //0111-0110(H)     
#define COML_I          ~COMH_I     //0000-0110(I)     
#define COML_L          ~COMH_L     //0011-1000(L)     
#define COML_N          ~COMH_N     //0011-0111(N)     
#define COML_O          ~COMH_O     //0011-1111(O)     
#define COML_P          ~COMH_P     //0111-0011(P)     
#define COML_S          ~COMH_S     //0011-1110(D)     
#define COML_Y          ~COMH_Y     //0110-0110(Y)     

#define COML_b          ~COMH_b     //1000-0011(b)
#define COML_c          ~COMH_c     //1010-0111(c)
#define COML_d          ~COMH_d     //1010-0001(d)
#define COML_g          ~COMH_g     //1001-0000(g)
#define COML_h          ~COMH_h     //1000-1011(h)
#define COML_i          ~COMH_i     //0111-1010(i)
#define COML_j          ~COMH_j     //1111-0010(j)
#define COML_l          ~COMH_l     //1100-1111(l)
#define COML_n          ~COMH_n     //1010-1011(n)
#define COML_o          ~COMH_o     //1010-0011(o)
#define COML_q          ~COMH_q     //1001-1000(q)
#define COML_r          ~COMH_r     //1100-1111(e)
#define COML_t          ~COMH_t     //1000-0111(t)
#define COML_u          ~COMH_u     //1110-0011(u)

//[Enum Declare]
typedef enum _SEG7_PIN
{
  SEG7_PIN_A    = 0,        //PIN A
  SEG7_PIN_B    = 1,        //PIN B
  SEG7_PIN_C    = 2,        //PIN C
  SEG7_PIN_D    = 3,        //PIN D
  SEG7_PIN_E    = 4,        //PIN E
  SEG7_PIN_F    = 5,        //PIN F
  SEG7_PIN_G    = 6,        //PIN G
  SEG7_PIN_DOT  = 7,        //PIN DOT
  SEG7_MAX,
} SEG_PIN_E;

typedef enum _SEG_CMODE
{
  SEG7_COMM_LOW  = 0,       //Common Pin Low
  SEG7_COMM_HIGH = 1,       //Common Pin High
} SEG_CMODE_E;

typedef enum _SEG_SEQUENCE
{
  SEG7_SEQ_G2A   = 0,       //Sequence Low to High
  SEG7_SEQ_A2G   = 1,       //Sequence High to Low
} SEG7_SEQ_E;

//[Callback Function Declare]
typedef void (*SEG7_Ctrl)(SG7_U8 Status);

//[Struct Declare]
//Segment-7 Active Function
typedef struct _Seg7Cb
{
  SEG7_Ctrl S7_A;           //Seg7 A   Control
  SEG7_Ctrl S7_B;           //Seg7 B   Control
  SEG7_Ctrl S7_C;           //Seg7 C   Control
  SEG7_Ctrl S7_D;           //Seg7 D   Control
  SEG7_Ctrl S7_E;           //Seg7 E   Control
  SEG7_Ctrl S7_F;           //Seg7 F   Control
  SEG7_Ctrl S7_G;           //Seg7 G   Control
  SEG7_Ctrl S7_DOT;         //Seg7 DOT Control
} Seg7Cb;

//Segment-7
typedef struct _Seg7
{
  SG7_U8 Data;              //Digit Data
  SG7_U8 CMode;             //Common Mode
  SG7_U8 Seq;               //Sequence
  Seg7Cb Cb;                //Action Function
} Seg7_t;

#ifdef __cplusplus
extern "C"{
#endif
//[Prototype Declare]
void Seg7_Set(Seg7_t *Seg,SG7_U8 Value);
void Seg7_ParseSet(Seg7_t *Seg,SG7_U8 Ch);
void Seg7_Upload(Seg7_t *Seg);

#ifdef __cplusplus
}
#endif

//[Macro Function Declare]
//Solve Big Endian and Small Endian Problem
//(.GFEDCBA -> ABCDEFG.)
#define SWAP_ENDIAN8(V) (((V & 0x01)<<7)|((V & 0x02)<<5)|((V & 0x04)<<3)|((V & 0x08)<<1) | \
                         ((V & 0x10)>>1)|((V & 0x20)>>3)|((V & 0x40)>>5)|((V & 0x80)>>7))

#endif  //__XSEG7_H__
