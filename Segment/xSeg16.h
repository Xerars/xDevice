#ifndef __XSEG16_H__  //__XSEG16_H__
#define __XSEG16_H__  //__XSEG16_H__

//   __A1___A2__
//  | \H J|  K/ |
// F|G1\__|__/G2|B
//  | N/  |M \L |
// E|_/___|___\_|C  O(DP:CA)
//    D1     D2

//[Typedef Declare]
typedef unsigned char   SG16_U8;        //U8
typedef unsigned int    SG16_U16;       //U16
typedef unsigned long   SG16_U32;       //U32

typedef signed char     SG16_S8;        //S8
typedef signed int      SG16_S16;       //S16
typedef signed long     SG16_S32;       //S32

//[Macro Declare]
//COM High(Sort: . N M L K J H G2 G1 F E D2 D1 C B A2 A1)
#define COM16H_NONE       0x1FFFF         //1-1111-1111-1111-1111
#define COM16H_0          0x1FF00         //1-1111-1111-0000-0000
#define COM16H_1          0x1FFF3         //1-1111-1111-1111-0011
#define COM16H_2          0x1FC88         //1-1111-1100-1000-1000
#define COM16H_3          0x1FCC0         //1-1111-1100-1100-0000
#define COM16H_4          0x1FC73         //1-1111-1100-0111-0011
#define COM16H_5          0x1FC44         //1-1111-1100-0100-0100
#define COM16H_6          0x1FC04         //1-1111-1100-0000-0100
#define COM16H_7          0x1FFF0         //1-1111-1111-1111-0000
#define COM16H_8          0x1FC00         //1-1111-1100-0000-0000
#define COM16H_9          0x1FC40         //1-1111-1100-0100-0000
#define COM16H_DOT        0x0FFFF         //0-1111-1111-1111-1111

//COM Low(Sort: .GFEDCBA)
#define COM16L_NONE       ~COM16H_NONE    //~(1-1111-1111-1111-1111)
#define COM16L_0          ~COM16H_0       //~(1-1111-1111-0000-0000)
#define COM16L_1          ~COM16H_1       //~(1-1111-1111-1111-0011)
#define COM16L_2          ~COM16H_2       //~(1-1111-1100-1000-1000)
#define COM16L_3          ~COM16H_3       //~(1-1111-1100-1100-0000)
#define COM16L_4          ~COM16H_4       //~(1-1111-1100-0111-0011)
#define COM16L_5          ~COM16H_5       //~(1-1111-1100-0100-0100)
#define COM16L_6          ~COM16H_6       //~(1-1111-1100-0000-0100)
#define COM16L_7          ~COM16H_7       //~(1-1111-1111-1111-0000)
#define COM16L_8          ~COM16H_8       //~(1-1111-1100-0000-0000)
#define COM16L_9          ~COM16H_9       //~(1-1111-1100-0100-0000)
#define COM16L_DOT        ~COM16H_DOT     //~(0-1111-1111-1111-1111)

//COM High(Advance Sort: . N M L K J H G2 G1 F E D2 D1 C B A2 A1)
#define COM16H_A          0x1FC30             //A
#define COM16H_B          0x1B5C0             //B
#define COM16H_C          0x1FF0C             //C
#define COM16H_D          0x1B7C0             //D
#define COM16H_E          0x1FC0C             //E
#define COM16H_F          0x1FC3C             //F
#define COM16H_G          0x1FD04             //G
#define COM16H_H          0x1FC33             //H
#define COM16H_I          0x1B7CC             //I
#define COM16H_J          0x1B7AC             //J
#define COM16H_K          0x1CE3F             //K
#define COM16H_L          0x1FF0F             //L
#define COM16H_M          0x1AB33             //M
#define COM16H_N          0x1DB33             //N
#define COM16H_O          0x1FF00             //O
#define COM16H_P          0x1FC38             //P
#define COM16H_Q          0x1DF00             //Q
#define COM16H_R          0x1DC38             //R
#define COM16H_S          0x1FC44             //S
#define COM16H_T          0x1B7FC             //T
#define COM16H_U          0x1FF03             //U
#define COM16H_V          0x16F3F             //V
#define COM16H_W          0x15733             //W
#define COM16H_X          0x14BFF             //X
#define COM16H_Y          0x1BC7B             //Y
#define COM16H_Z          0x16FCC             //Z

#define COM16H_a          0x1FC80             //a
#define COM16H_b          0x1FC07             //b
#define COM16H_c          0x1FC8F             //c
#define COM16H_d          0x1FC83             //d
#define COM16H_e          0x1FC08             //e
#define COM16H_f          0x1B4FD             //f
#define COM16H_g          0x1FC40             //g
#define COM16H_h          0x1FC37             //h
#define COM16H_i          0x1BECE             //i
#define COM16H_j          0x1FFC4             //j
#define COM16H_k          0x1DC3F             //k
#define COM16H_l          0x1B7DE             //l
#define COM16H_m          0x1BCB7             //m
#define COM16H_n          0x1FF30             //n
#define COM16H_o          0x1FC87             //o
#define COM16H_p          0x1EE3C             //p
#define COM16H_q          0x1EE70             //q
#define COM16H_r          0x1FCBF             //r
#define COM16H_s          0x1DDCF             //s
#define COM16H_t          0x1B4DF             //t
#define COM16H_u          0x1FF87             //u
#define COM16H_v          0x17FBF             //v
#define COM16H_w          0x15FB7             //w
#define COM16H_x          0x15CFF             //x
#define COM16H_y          0x1F5C3             //y
#define COM16H_z          0x17EEF             //z


//COM Low(Advance Sort: . N M L K J H G2 G1 F E D2 D1 C B A2 A1)
#define COM16L_A          ~COM16H_A           //A
#define COM16L_B          ~COM16H_B           //B
#define COM16L_C          ~COM16H_C           //C
#define COM16L_D          ~COM16H_D           //D
#define COM16L_E          ~COM16H_E           //E
#define COM16L_F          ~COM16H_F           //F
#define COM16L_G          ~COM16H_G           //G
#define COM16L_H          ~COM16H_H           //H
#define COM16L_I          ~COM16H_I           //I
#define COM16L_J          ~COM16H_J           //J
#define COM16L_K          ~COM16H_K           //K
#define COM16L_L          ~COM16H_L           //L
#define COM16L_M          ~COM16H_M           //M
#define COM16L_N          ~COM16H_N           //N
#define COM16L_O          ~COM16H_O           //O
#define COM16L_P          ~COM16H_P           //P
#define COM16L_Q          ~COM16H_Q           //Q
#define COM16L_R          ~COM16H_R           //R
#define COM16L_S          ~COM16H_S           //S
#define COM16L_T          ~COM16H_T           //T
#define COM16L_U          ~COM16H_U           //U
#define COM16L_V          ~COM16H_V           //V
#define COM16L_W          ~COM16H_W           //W
#define COM16L_X          ~COM16H_X           //X
#define COM16L_Y          ~COM16H_Y           //Y
#define COM16L_Z          ~COM16H_Z           //ZL

#define COM16L_a          ~COM16H_a           //a
#define COM16L_b          ~COM16H_b           //b
#define COM16L_c          ~COM16H_c           //c
#define COM16L_d          ~COM16H_d           //d
#define COM16L_e          ~COM16H_e           //e
#define COM16L_f          ~COM16H_f           //f
#define COM16L_g          ~COM16H_g           //g
#define COM16L_h          ~COM16H_h           //h
#define COM16L_i          ~COM16H_i           //i
#define COM16L_j          ~COM16H_j           //j
#define COM16L_k          ~COM16H_k           //k
#define COM16L_l          ~COM16H_l           //l
#define COM16L_m          ~COM16H_m           //m
#define COM16L_n          ~COM16H_n           //n
#define COM16L_o          ~COM16H_o           //o
#define COM16L_p          ~COM16H_p           //p
#define COM16L_q          ~COM16H_q           //q
#define COM16L_r          ~COM16H_r           //r
#define COM16L_s          ~COM16H_s           //s
#define COM16L_t          ~COM16H_t           //t
#define COM16L_u          ~COM16H_u           //u
#define COM16L_v          ~COM16H_v           //v
#define COM16L_w          ~COM16H_w           //w
#define COM16L_x          ~COM16H_x           //x
#define COM16L_y          ~COM16H_y           //y
#define COM16L_z          ~COM16H_z           //z

//COM High(Others Sort: . N M L K J H G2 G1 F E D2 D1 C B A2 A1)
#define COM16H_PERCENT    0x12456            // '%'
#define COM16H_PLUS       0x1B4FF            // '+'
#define COM16H_MINUS      0x1FCFF            // '-'
#define COM16H_MUTIPLE    0x100FF            // '*'
#define COM16H_DIVIDE     0x16FFF            // '/'
#define COM16H_MOD        0x1DBFF            // '\'
#define COM16H_FBRACKET   0x1FF2E            // '['
#define COM16H_BBRACKET   0x1FFDE            // ']'
#define COM16H_EQ         0x1FCCF            // '='
#define COM16H_GT         0x17BFF            // '>'
#define COM16H_LT         0x1CFFF            // '<'
#define COM16H_GTEQ       0x17BEF            // '>='
#define COM16H_LTEQ       0x1CFDF            // '<='
#define COM16H_XOR        0x15FFF            // 'XOR'

//COM Low(Others Sort: . N M L K J H G2 G1 F E D2 D1 C B A2 A1)
#define COM16L_PERCENT    ~COM16H_PERCENT    // '%'
#define COM16L_PLUS       ~COM16H_PLUS       // '+'
#define COM16L_MINUS      ~COM16H_MINUS      // '-'
#define COM16L_MUTIPLE    ~COM16H_MUTIPLE    // '*'
#define COM16L_DIVIDE     ~COM16H_DIVIDE     // '/'
#define COM16L_MOD        ~COM16H_MOD        // '\'
#define COM16L_FBRACKET   ~COM16H_FBRACKET   // '['
#define COM16L_BBRACKET   ~COM16H_BBRACKET   // ']'
#define COM16L_EQ         ~COM16H_EQ         // '='
#define COM16L_GT         ~COM16H_GT         // '>'
#define COM16L_LT         ~COM16H_LT         // '<'
#define COM16L_GTEQ       ~COM16H_GTEQ       // '>='
#define COM16L_LTEQ       ~COM16H_LTEQ       // '<='
#define COM16L_SIGMA      ~COM16H_SIGMA      // 'Sum'   
#define COM16L_XOR        ~COM16H_XOR        // 'XOR'

//[Enum Declare]
typedef enum _SEG16_PIN
{
  SEG16_PIN_A    = 0,    //PIN A
  SEG16_PIN_B    = 1,    //PIN B
  SEG16_PIN_C    = 2,    //PIN C
  SEG16_PIN_D    = 3,    //PIN D
  SEG16_PIN_E    = 4,    //PIN E
  SEG16_PIN_F    = 5,    //PIN F
  SEG16_PIN_G    = 6,    //PIN G
  SEG16_PIN_DOT  = 7,    //PIN DOT
  SEG16_MAX,
} SEG_PIN_E;

typedef enum _SEG_CMODE
{
  SEG16_COMM_LOW  = 0,   //Common Low
  SEG16_COMM_HIGH = 1,   //Common High
} SEG_CMODE_E;

typedef enum _SEG_SEQUENCE
{
  SEG16_SEQ_G2A    = 0,  //Sequence Low to High
  SEG16_SEQ_A2G    = 1,  //Sequence High to Low
} SEG16_SEQ_E;

//[Callback Function Declare]
typedef void (SEG16_Ctrl)(SG16_U8 Status);

//[Struct Declare]
typedef struct _Seg16Cb
{
  SEG16_Ctrl S16_A1;          //Seg16 A1  Control
  SEG16_Ctrl S16_A2;          //Seg16 A2  Control
  SEG16_Ctrl S16_B;           //Seg16 B   Control
  SEG16_Ctrl S16_C;           //Seg16 C   Control
  SEG16_Ctrl S16_D1;          //Seg16 D1  Control
  SEG16_Ctrl S16_D2;          //Seg16 D2  Control
  SEG16_Ctrl S16_E;           //Seg16 E   Control
  SEG16_Ctrl S16_F;           //Seg16 F   Control
  SEG16_Ctrl S16_G1;          //Seg16 G1  Control
  SEG16_Ctrl S16_G2;          //Seg16 G2  Control
  SEG16_Ctrl S16_H;           //Seg16 H   Control
  SEG16_Ctrl S16_J;           //Seg16 J   Control
  SEG16_Ctrl S16_K;           //Seg16 K   Control
  SEG16_Ctrl S16_L;           //Seg16 L   Control
  SEG16_Ctrl S16_M;           //Seg16 M   Control
  SEG16_Ctrl S16_N;           //Seg16 N   Control
  SEG16_Ctrl S16_DOT;         //Seg16 DOT Control
} Seg16Cb;


typedef struct _Seg16
{
  SG16_U32 Data;            //Digit Data
  SG16_U8 CMode;            //Common Mode
  SG16_U8 Seq;              //Sequence
  Seg16Cb Cb;               //Action Function
} Seg16_t;

#ifdef __cplusplus
extern "C"{
#endif
//[Prototype Declare]
void Seg16_Set(Seg16_t *Seg,SG16_U8 Value);
void Seg16_ParseSet(Seg16_t *Seg,SG16_U8 Ch);
void Seg16_Upload(Seg16_t *Seg);

#ifdef __cplusplus
}
#endif

//[Macro Function Declare]
//Solve Big Endian and Small Endian Problem
//(.NMLKJHG2G1FED2D1CBA2A1 -> A1A2BCD1D2EFG1G2HJKLMN.)
#define SWAP_ENDIAN17(V) (((V & 0x0001)<<16)|((V & 0x0002)<<14)|((V & 0x0004)<<12)|((V & 0x0008)<<10)|\
                          ((V & 0x0010)<<8) |((V & 0x0020)<<6) |((V & 0x0040)<<4) |((V & 0x0080)<<2) |\
                          ((V & 0x0100))    |\
                          ((V & 0x0200)>>2) |((V & 0x0400)>>4) |((V & 0x0800)>>6) |((V & 0x1000)>>8) |\
                          ((V & 0x2000)>>10)|((V & 0x4000)>>12)|((V & 0x8000)>>14)|((V & 0x10000)>>16))

#endif  //__XSEG16_H__
