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
#define COMH_NONE       0x1FFFF         //1-1111-1111-1111-1111
#define COMH_0          0x1FF00         //1-1111-1111-0000-0000
#define COMH_1          0x1FFF3         //1-1111-1111-1111-0011
#define COMH_2          0x1FC88         //1-1111-1100-1000-1000
#define COMH_3          0x1FCC0         //1-1111-1100-1100-0000
#define COMH_4          0x1FC73         //1-1111-1100-0111-0011
#define COMH_5          0x1FC44         //1-1111-1100-0100-0100
#define COMH_6          0x1FC04         //1-1111-1100-0000-0100
#define COMH_7          0x1FFF0         //1-1111-1111-1111-0000
#define COMH_8          0x1FC00         //1-1111-1100-0000-0000
#define COMH_9          0x1FC40         //1-1111-1100-0100-0000
#define COMH_DOT        0x0FFFF         //0-1111-1111-1111-1111

//COM Low(Sort: .GFEDCBA)
#define COML_NONE       ~COMH_NONE      //~(1-1111-1111-1111-1111)
#define COML_0          ~COMH_0         //~(1-1111-1111-0000-0000)
#define COML_1          ~COMH_1         //~(1-1111-1111-1111-0011)
#define COML_2          ~COMH_2         //~(1-1111-1100-1000-1000)
#define COML_3          ~COMH_3         //~(1-1111-1100-1100-0000)
#define COML_4          ~COMH_4         //~(1-1111-1100-0111-0011)
#define COML_5          ~COMH_5         //~(1-1111-1100-0100-0100)
#define COML_6          ~COMH_6         //~(1-1111-1100-0000-0100)
#define COML_7          ~COMH_7         //~(1-1111-1111-1111-0000)
#define COML_8          ~COMH_8         //~(1-1111-1100-0000-0000)
#define COML_9          ~COMH_9         //~(1-1111-1100-0100-0000)
#define COML_DOT        ~COMH_DOT       //~(0-1111-1111-1111-1111)

//COM High(Advance Sort: . N M L K J H G2 G1 F E D2 D1 C B A2 A1)
#define COMH_A          0x1FC30             //A
#define COMH_B          0x1B5C0             //B
#define COMH_C          0x1FF0C             //C
#define COMH_D          0x1B7C0             //D
#define COMH_E          0x1FC0C             //E
#define COMH_F          0x1FC3C             //F
#define COMH_G          0x1FD04             //G
#define COMH_H          0x1FC33             //H
#define COMH_I          0x1B7CC             //I
#define COMH_J          0x1B7AC             //J
#define COMH_K          0x1CE3F             //K
#define COMH_L          0x1FF0F             //L
#define COMH_M          0x1AB33             //M
#define COMH_N          0x1DB33             //N
#define COMH_O          0x1FF00             //O
#define COMH_P          0x1FC38             //P
#define COMH_Q          0x1DF00             //Q
#define COMH_R          0x1DC38             //R
#define COMH_S          0x1FC44             //S
#define COMH_T          0x1B7FC             //T
#define COMH_U          0x1FF03             //U
#define COMH_V          0x16F3F             //V
#define COMH_W          0x15733             //W
#define COMH_X          0x14BFF             //X
#define COMH_Y          0x1BC7B             //Y
#define COMH_Z          0x16FCC             //Z

#define COMH_a          0x1FC80             //a
#define COMH_b          0x1FC07             //b
#define COMH_c          0x1FC8F             //c
#define COMH_d          0x1FC83             //d
#define COMH_e          0x1FC08             //e
#define COMH_f          0x1B4FD             //f
#define COMH_g          0x1FC40             //g
#define COMH_h          0x1FC37             //h
#define COMH_i          0x1BECE             //i
#define COMH_j          0x1FFC4             //j
#define COMH_k          0x1DC3F             //k
#define COMH_l          0x1B7DE             //l
#define COMH_m          0x1BCB7             //m
#define COMH_n          0x1FF30             //n
#define COMH_o          0x1FC87             //o
#define COMH_p          0x1EE3C             //p
#define COMH_q          0x1EE70             //q
#define COMH_r          0x1FCBF             //r
#define COMH_s          0x1DDCF             //s
#define COMH_t          0x1B4DF             //t
#define COMH_u          0x1FF87             //u
#define COMH_v          0x17FBF             //v
#define COMH_w          0x15FB7             //w
#define COMH_x          0x15CFF             //x
#define COMH_y          0x1F5C3             //y
#define COMH_z          0x17EEF             //z


//COM Low(Advance Sort: . N M L K J H G2 G1 F E D2 D1 C B A2 A1)
#define COML_A          ~COMH_A            //A
#define COML_B          ~COMH_B            //B
#define COML_C          ~COMH_C            //C
#define COML_D          ~COMH_D            //D
#define COML_E          ~COMH_E            //E
#define COML_F          ~COMH_F            //F
#define COML_G          ~COMH_G            //G
#define COML_H          ~COMH_H            //H
#define COML_I          ~COMH_I            //I
#define COML_J          ~COMH_J            //J
#define COML_K          ~COMH_K            //K
#define COML_L          ~COMH_L            //L
#define COML_M          ~COMH_M            //M
#define COML_N          ~COMH_N            //N
#define COML_O          ~COMH_O            //O
#define COML_P          ~COMH_P            //P
#define COML_Q          ~COMH_Q            //Q
#define COML_R          ~COMH_R            //R
#define COML_S          ~COMH_S            //S
#define COML_T          ~COMH_T            //T
#define COML_U          ~COMH_U            //U
#define COML_V          ~COMH_V            //V
#define COML_W          ~COMH_W            //W
#define COML_X          ~COMH_X            //X
#define COML_Y          ~COMH_Y            //Y
#define COML_Z          ~COMH_Z            //ZL
#define COML_a          ~COMH_a            //a
#define COML_b          ~COMH_b            //b
#define COML_c          ~COMH_c            //c
#define COML_d          ~COMH_d            //d
#define COML_e          ~COMH_e            //e
#define COML_f          ~COMH_f            //f
#define COML_g          ~COMH_g            //g
#define COML_h          ~COMH_h            //h
#define COML_i          ~COMH_i            //i
#define COML_j          ~COMH_j            //j
#define COML_k          ~COMH_k            //k
#define COML_l          ~COMH_l            //l
#define COML_m          ~COMH_m            //m
#define COML_n          ~COMH_n            //n
#define COML_o          ~COMH_o            //o
#define COML_p          ~COMH_p            //p
#define COML_q          ~COMH_q            //q
#define COML_r          ~COMH_r            //r
#define COML_s          ~COMH_s            //s
#define COML_t          ~COMH_t            //t
#define COML_u          ~COMH_u            //u
#define COML_v          ~COMH_v            //v
#define COML_w          ~COMH_w            //w
#define COML_x          ~COMH_x            //x
#define COML_y          ~COMH_y            //y
#define COML_z          ~COMH_z            //z

//COM High(Others Sort: . N M L K J H G2 G1 F E D2 D1 C B A2 A1)
#define COMH_PERCENT    0x12456            // '%'
#define COMH_PLUS       0x1B4FF            // '+'
#define COMH_MINUS      0x1FCFF            // '-'
#define COMH_MUTIPLE    0x100FF            // '*'
#define COMH_DIVIDE     0x16FFF            // '/'
#define COMH_MOD        0x1DBFF            // '\'
#define COMH_FBRACKET   0x1FF2E            // '['
#define COMH_BBRACKET   0x1FFDE            // ']'
#define COMH_EQ         0x1FCCF            // '='
#define COMH_GT         0x17BFF            // '>'
#define COMH_LT         0x1CFFF            // '<'
#define COMH_GTEQ       0x17BEF            // '>='
#define COMH_LTEQ       0x1CFDF            // '<='
#define COMH_XOR        0x15FFF            // 'XOR'

//COM Low(Others Sort: . N M L K J H G2 G1 F E D2 D1 C B A2 A1)
#define COML_PERCENT    ~COMH_PERCENT      // '%'
#define COML_PLUS       ~COMH_PLUS         // '+'
#define COML_MINUS      ~COMH_MINUS        // '-'
#define COML_MUTIPLE    ~COMH_MUTIPLE      // '*'
#define COML_DIVIDE     ~COMH_DIVIDE       // '/'
#define COML_MOD        ~COMH_MOD          // '\'
#define COML_FBRACKET   ~COMH_FBRACKET     // '['
#define COML_BBRACKET   ~COMH_BBRACKET     // ']'
#define COML_EQ         ~COMH_EQ           // '='
#define COML_GT         ~COMH_GT           // '>'
#define COML_LT         ~COMH_LT           // '<'
#define COML_GTEQ       ~COMH_GTEQ         // '>='
#define COML_LTEQ       ~COMH_LTEQ         // '<='
#define COML_SIGMA      ~COMH_SIGMA        // 'Sum'   
#define COML_XOR        ~COMH_XOR          // 'XOR'

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
