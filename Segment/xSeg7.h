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
#define COM7H_NONE       0xFF        //1111-1111
#define COM7H_0          0xC0        //1100-0000
#define COM7H_1          0xF9        //1111-1001
#define COM7H_2          0xA4        //1010-0100
#define COM7H_3          0xB0        //1011-0000
#define COM7H_4          0x99        //1001-1001
#define COM7H_5          0x92        //1001-0010
#define COM7H_6          0x82        //1000-0010
#define COM7H_7          0xF8        //1111-1000
#define COM7H_8          0x80        //1000-0000
#define COM7H_9          0x90        //1001-0000
#define COM7H_DOT        0x7F        //0111-1111

//COM Low(Sort: .GFEDCBA)
#define COM7L_NONE       ~COM7H_NONE //0000-0000
#define COM7L_0          ~COM7H_0    //0011-1111
#define COM7L_1          ~COM7H_1    //0000-0110
#define COM7L_2          ~COM7H_2    //0101-1011
#define COM7L_3          ~COM7H_3    //0100-1111
#define COM7L_4          ~COM7H_4    //0110-0110
#define COM7L_5          ~COM7H_5    //0110-1101
#define COM7L_6          ~COM7H_6    //0111-1101
#define COM7L_7          ~COM7H_7    //0000-0111
#define COM7L_8          ~COM7H_8    //0111-1111
#define COM7L_9          ~COM7H_9    //0110-1111
#define COM7L_DOT        ~COM7H_DOT  //1000-0000

//COM High(Advance Sort: .GFEDCBA)
#define COM7H_A          0x88        //1000-1000(A)
#define COM7H_C          0xC6        //1100-0110(C)
#define COM7H_E          0x86        //1000-0110(E)
#define COM7H_F          0x8E        //1000-1110(F)
#define COM7H_G          0xC2        //1100-0010(G)
#define COM7H_H          0x89        //1000-1001(H)
#define COM7H_I          0xF9        //1111-1001(I)
#define COM7H_L          0xC7        //1100-0111(L)
#define COM7H_N          0xC8        //1100-1000(N)
#define COM7H_O          0xC0        //1100-0000(O)
#define COM7H_P          0x8C        //1000-1100(P)
#define COM7H_S          0xC1        //1100-0001(D)
#define COM7H_Y          0x99        //1001-1001(Y)

#define COM7H_b          0x83        //1000-0011(b)
#define COM7H_c          0xA7        //1010-0111(c)
#define COM7H_d          0xA1        //1010-0001(d)
#define COM7H_g          0x90        //1001-0000(g)
#define COM7H_h          0x8B        //1000-1011(h)
#define COM7H_i          0x7A        //0111-1010(i)
#define COM7H_j          0xF2        //1111-0010(j)
#define COM7H_l          0xAF        //1100-1111(l)
#define COM7H_n          0xAB        //1010-1011(n)
#define COM7H_o          0xA3        //1010-0011(o)
#define COM7H_q          0x98        //1001-1000(q)
#define COM7H_r          0xAF        //1100-1111(e)
#define COM7H_t          0x87        //1000-0111(t)
#define COM7H_u          0xE3        //1110-0011(u)

//COM Low(Advance Sort: .GFEDCBA)
#define COM7L_A          ~COM7H_A    //0111-0111(A)    
#define COM7L_C          ~COM7H_C    //0011-1001(C)     
#define COM7L_E          ~COM7H_E    //0111-1001(E)     
#define COM7L_F          ~COM7H_F    //0111-0001(F)     
#define COM7L_G          ~COM7H_G    //0011-1101(G)     
#define COM7L_H          ~COM7H_H    //0111-0110(H)     
#define COM7L_I          ~COM7H_I    //0000-0110(I)     
#define COM7L_L          ~COM7H_L    //0011-1000(L)     
#define COM7L_N          ~COM7H_N    //0011-0111(N)     
#define COM7L_O          ~COM7H_O    //0011-1111(O)     
#define COM7L_P          ~COM7H_P    //0111-0011(P)     
#define COM7L_S          ~COM7H_S    //0011-1110(D)     
#define COM7L_Y          ~COM7H_Y    //0110-0110(Y)     

#define COM7L_b          ~COM7H_b    //1000-0011(b)
#define COM7L_c          ~COM7H_c    //1010-0111(c)
#define COM7L_d          ~COM7H_d    //1010-0001(d)
#define COM7L_g          ~COM7H_g    //1001-0000(g)
#define COM7L_h          ~COM7H_h    //1000-1011(h)
#define COM7L_i          ~COM7H_i    //0111-1010(i)
#define COM7L_j          ~COM7H_j    //1111-0010(j)
#define COM7L_l          ~COM7H_l    //1100-1111(l)
#define COM7L_n          ~COM7H_n    //1010-1011(n)
#define COM7L_o          ~COM7H_o    //1010-0011(o)
#define COM7L_q          ~COM7H_q    //1001-1000(q)
#define COM7L_r          ~COM7H_r    //1100-1111(e)
#define COM7L_t          ~COM7H_t    //1000-0111(t)
#define COM7L_u          ~COM7H_u    //1110-0011(u)

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
