# xSeg

## Tooling
Tooling Seg7_Tool and Seg16_Tool is Simple Tool for Check Seg7 and Seg16 Value

## 7-Segment
We can Use a Very Simple Method to Set the Value to be Output by 7-Segment,
and then Use the Upload Method to Update the Value.
The Following is an Example that can be well Demostrated

``` c
//[Custom Lib Include]
#include "xSeg7.h"

//[STC Lib Include]
#include "STC8A8K64D4.h"

//[Variable Declare]
Seg7_t Segment;   // Create Variable


void PINA_Set(unsigned char Status)   { P00 = (status)?1:0; }
void PINB_Set(unsigned char Status)   { P01 = (status)?1:0; }
void PINC_Set(unsigned char Status)   { P02 = (status)?1:0; }
void PIND_Set(unsigned char Status)   { P03 = (status)?1:0; }
void PINE_Set(unsigned char Status)   { P04 = (status)?1:0; }
void PINF_Set(unsigned char Status)   { P05 = (status)?1:0; }
void PING_Set(unsigned char Status)   { P06 = (status)?1:0; }
void PINDOT_Set(unsigned char Status) { P07 = (status)?1:0; }

///@Function: Segment_Init
///@Descript: Segment Initial
void Segment_Init(void)
{
  //Set Necessary Variable and Function
  Segment.CMode = SEG7_COMM_HIGH;     //Common High
  Segment.Seq   = SEG7_SEQ_G2A;       //Sequence : GFEDCBA

  //Set Callback Function
  Segment.Cb.S7_A = PINA_Set;
  Segment.Cb.S7_B = PINB_Set;
  Segment.Cb.S7_C = PINC_Set;
  Segment.Cb.S7_D = PIND_Set;
  Segment.Cb.S7_E = PINE_Set;
  Segment.Cb.S7_F = PINF_Set;
  Segment.Cb.S7_G = PING_Set;
  Segment.Cb.S7_DOT = PINDOT_Set;
}

//Main Code
void main(void)
{
  Segment_Init();

  while(1)
  {
    //Method 1
    Seg7_Set(&Segment,COM7H_5);    //Set Value
    Seg7_Upload(&Segment);

    //Method 2
    Seg7_ParseSet(&Segment,'1');  //Set Character
    Seg7_Upload(&Segment);
  }
}

```

## 16-Segment
We can Use a Very Simple Method to Set the Value to be Output by 16-Segment,
and then Use the Upload Method to Update the Value.
The Following is an Example that can be well Demostrated
``` c
//[Custom Lib Include]
#include "xSeg16.h"

//[STC Lib Include]
#include "STC8A8K64D4.h"

//[Variable Declare]
Seg16_t Segment;   // Create Variable


void PINA1_Set(unsigned char Status)  { P00 = (status)?1:0; }
void PINA2_Set(unsigned char Status)  { P01 = (status)?1:0; }
void PINB_Set(unsigned char Status)   { P02 = (status)?1:0; }
void PINC_Set(unsigned char Status)   { P03 = (status)?1:0; }
void PIND1_Set(unsigned char Status)  { P04 = (status)?1:0; }
void PIND2_Set(unsigned char Status)  { P05 = (status)?1:0; }
void PINE_Set(unsigned char Status)   { P06 = (status)?1:0; }
void PINF_Set(unsigned char Status)   { P07 = (status)?1:0; }
void PING1_Set(unsigned char Status)  { P10 = (status)?1:0; }
void PING2_Set(unsigned char Status)  { P11 = (status)?1:0; }
void PINH_Set(unsigned char Status)   { P12 = (status)?1:0; }
void PINJ_Set(unsigned char Status)   { P13 = (status)?1:0; }
void PINK_Set(unsigned char Status)   { P14 = (status)?1:0; }
void PINL_Set(unsigned char Status)   { P15 = (status)?1:0; }
void PINM_Set(unsigned char Status)   { P16 = (status)?1:0; }
void PINN_Set(unsigned char Status)   { P17 = (status)?1:0; }
void PINDOT_Set(unsigned char Status) { P20 = (status)?1:0; }

///@Function: Segment_Init
///@Descript: Segment Initial
void Segment_Init(void)
{
  //Set Necessary Variable and Function
  Segment.CMode = SEG7_COMM_HIGH;     //Common High
  Segment.Seq   = SEG7_SEQ_G2A;       //Sequence : GFEDCBA

  //Set Callback Function
  Segment.S16_A1  = PINA1_Set;
  Segment.S16_A2  = PINA2_Set;
  Segment.S16_B   = PINB_Set;
  Segment.S16_C   = PINC_Set;
  Segment.S16_D1  = PIND1_Set;
  Segment.S16_D2  = PIND2_Set;
  Segment.S16_E   = PINE_Set;
  Segment.S16_F   = PINF_Set;
  Segment.S16_G1  = PING1_Set;
  Segment.S16_G2  = PING2_Set;
  Segment.S16_H   = PINH_Set;
  Segment.S16_J   = PINJ_Set;
  Segment.S16_K   = PINK_Set;
  Segment.S16_L   = PINL_Set;
  Segment.S16_M   = PINM_Set;
  Segment.S16_N   = PINN_Set;
  Segment.S16_DOT = PINDOT_Set;
}

//Main Code
void main(void)
{
  Segment_Init();

  while(1)
  {
    //Method 1
    Seg16_Set(&Segment,COM16H_5);    //Set Value
    Seg16_Upload(&Segment);

    //Method 2
    Seg16_ParseSet(&Segment,'1');  //Set Character
    Seg16_Upload(&Segment);
  }
}
`