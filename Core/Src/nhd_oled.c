#include "nhd_oled.h"

const uint8_t NHD_OLED_Init_Sequence[] = {
  SEPS525_REG_REDUCE_CURRENT, 0x01,
  SEPS525_REG_REDUCE_CURRENT, 0x00,
  SEPS525_REG_DISP_ON_OFF, 0x00,
  SEPS525_REG_OSC_CTL, 0x01,
  SEPS525_REG_CLOCK_DIV, 0x30,
  SEPS525_REG_DUTY, 0x7F,
  SEPS525_REG_DSL, 0x00,
  SEPS525_REG_RGB_IF, 0x11,
  SEPS525_REG_MEMORY_WRITE_MODE, 0x26,
  SEPS525_REG_DRIVING_CURRENT_R, 0x45,
  SEPS525_REG_DRIVING_CURRENT_G, 0x34,
  SEPS525_REG_DRIVING_CURRENT_B, 0x33,
  SEPS525_REG_PRECHARGE_TIME_R, 0x04,
  SEPS525_REG_PRECHARGE_TIME_G, 0x05,
  SEPS525_REG_PRECHARGE_TIME_B, 0x05,
  SEPS525_REG_PRECHARGE_CURRENT_R, 0x9D,
  SEPS525_REG_PRECHARGE_CURRENT_G, 0x8C,
  SEPS525_REG_PRECHARGE_CURRENT_B, 0x57,
  SEPS525_REG_IREF, 0x00,
  SEPS525_REG_DISPLAY_MODE_SET, 0x80,
  SEPS525_REG_MX1_ADDR, 0x00,
  SEPS525_REG_MX2_ADDR, 0x9F,
  SEPS525_REG_MY1_ADDR, 0x00,
  SEPS525_REG_MY2_ADDR, 0x7F,
  SEPS525_REG_DISP_ON_OFF, 0x01,
};

const unsigned char NHD_OLED_Ascii_1[97][5] = {     // Refer to "Times New Roman" Font Database...
    //   Basic Characters
    {0x00,0x00,0x00,0x00,0x00},     //   (  0)    - 0x0000 Empty set
    {0x00,0x00,0x4F,0x00,0x00},     //   (  1)  ! - 0x0021 Exclamation Mark
    {0x00,0x07,0x00,0x07,0x00},     //   (  2)  " - 0x0022 Quotation Mark
    {0x14,0x7F,0x14,0x7F,0x14},     //   (  3)  # - 0x0023 Number Sign
    {0x24,0x2A,0x7F,0x2A,0x12},     //   (  4)  $ - 0x0024 Dollar Sign
    {0x23,0x13,0x08,0x64,0x62},     //   (  5)  % - 0x0025 Percent Sign
    {0x36,0x49,0x55,0x22,0x50},     //   (  6)  & - 0x0026 Ampersand
    {0x00,0x05,0x03,0x00,0x00},     //   (  7)  ' - 0x0027 Apostrophe
    {0x00,0x1C,0x22,0x41,0x00},     //   (  8)  ( - 0x0028 Left Parenthesis
    {0x00,0x41,0x22,0x1C,0x00},     //   (  9)  ) - 0x0029 Right Parenthesis
    {0x14,0x08,0x3E,0x08,0x14},     //   ( 10)  * - 0x002A Asterisk
    {0x08,0x08,0x3E,0x08,0x08},     //   ( 11)  + - 0x002B Plus Sign
    {0x00,0x50,0x30,0x00,0x00},     //   ( 12)  , - 0x002C Comma
    {0x08,0x08,0x08,0x08,0x08},     //   ( 13)  - - 0x002D Hyphen-Minus
    {0x00,0x60,0x60,0x00,0x00},     //   ( 14)  . - 0x002E Full Stop
    {0x20,0x10,0x08,0x04,0x02},     //   ( 15)  / - 0x002F Solidus
    {0x3E,0x51,0x49,0x45,0x3E},     //   ( 16)  0 - 0x0030 Digit Zero
    {0x00,0x42,0x7F,0x40,0x00},     //   ( 17)  1 - 0x0031 Digit One
    {0x42,0x61,0x51,0x49,0x46},     //   ( 18)  2 - 0x0032 Digit Two
    {0x21,0x41,0x45,0x4B,0x31},     //   ( 19)  3 - 0x0033 Digit Three
    {0x18,0x14,0x12,0x7F,0x10},     //   ( 20)  4 - 0x0034 Digit Four
    {0x27,0x45,0x45,0x45,0x39},     //   ( 21)  5 - 0x0035 Digit Five
    {0x3C,0x4A,0x49,0x49,0x30},     //   ( 22)  6 - 0x0036 Digit Six
    {0x01,0x71,0x09,0x05,0x03},     //   ( 23)  7 - 0x0037 Digit Seven
    {0x36,0x49,0x49,0x49,0x36},     //   ( 24)  8 - 0x0038 Digit Eight
    {0x06,0x49,0x49,0x29,0x1E},     //   ( 25)  9 - 0x0039 Dight Nine
    {0x00,0x36,0x36,0x00,0x00},     //   ( 26)  : - 0x003A Colon
    {0x00,0x56,0x36,0x00,0x00},     //   ( 27)  ; - 0x003B Semicolon
    {0x08,0x14,0x22,0x41,0x00},     //   ( 28)  < - 0x003C Less-Than Sign
    {0x14,0x14,0x14,0x14,0x14},     //   ( 29)  = - 0x003D Equals Sign
    {0x00,0x41,0x22,0x14,0x08},     //   ( 30)  > - 0x003E Greater-Than Sign
    {0x02,0x01,0x51,0x09,0x06},     //   ( 31)  ? - 0x003F Question Mark
    {0x32,0x49,0x79,0x41,0x3E},     //   ( 32)  @ - 0x0040 Commercial At
    {0x7E,0x11,0x11,0x11,0x7E},     //   ( 33)  A - 0x0041 Latin Capital Letter A
    {0x7F,0x49,0x49,0x49,0x36},     //   ( 34)  B - 0x0042 Latin Capital Letter B
    {0x3E,0x41,0x41,0x41,0x22},     //   ( 35)  C - 0x0043 Latin Capital Letter C
    {0x7F,0x41,0x41,0x22,0x1C},     //   ( 36)  D - 0x0044 Latin Capital Letter D
    {0x7F,0x49,0x49,0x49,0x41},     //   ( 37)  E - 0x0045 Latin Capital Letter E
    {0x7F,0x09,0x09,0x09,0x01},     //   ( 38)  F - 0x0046 Latin Capital Letter F
    {0x3E,0x41,0x49,0x49,0x7A},     //   ( 39)  G - 0x0047 Latin Capital Letter G
    {0x7F,0x08,0x08,0x08,0x7F},     //   ( 40)  H - 0x0048 Latin Capital Letter H
    {0x00,0x41,0x7F,0x41,0x00},     //   ( 41)  I - 0x0049 Latin Capital Letter I
    {0x20,0x40,0x41,0x3F,0x01},     //   ( 42)  J - 0x004A Latin Capital Letter J
    {0x7F,0x08,0x14,0x22,0x41},     //   ( 43)  K - 0x004B Latin Capital Letter K
    {0x7F,0x40,0x40,0x40,0x40},     //   ( 44)  L - 0x004C Latin Capital Letter L
    {0x7F,0x02,0x0C,0x02,0x7F},     //   ( 45)  M - 0x004D Latin Capital Letter M
    {0x7F,0x04,0x08,0x10,0x7F},     //   ( 46)  N - 0x004E Latin Capital Letter N
    {0x3E,0x41,0x41,0x41,0x3E},     //   ( 47)  O - 0x004F Latin Capital Letter O
    {0x7F,0x09,0x09,0x09,0x06},     //   ( 48)  P - 0x0050 Latin Capital Letter P
    {0x3E,0x41,0x51,0x21,0x5E},     //   ( 49)  Q - 0x0051 Latin Capital Letter Q
    {0x7F,0x09,0x19,0x29,0x46},     //   ( 50)  R - 0x0052 Latin Capital Letter R
    {0x46,0x49,0x49,0x49,0x31},     //   ( 51)  S - 0x0053 Latin Capital Letter S
    {0x01,0x01,0x7F,0x01,0x01},     //   ( 52)  T - 0x0054 Latin Capital Letter T
    {0x3F,0x40,0x40,0x40,0x3F},     //   ( 53)  U - 0x0055 Latin Capital Letter U
    {0x1F,0x20,0x40,0x20,0x1F},     //   ( 54)  V - 0x0056 Latin Capital Letter V
    {0x3F,0x40,0x38,0x40,0x3F},     //   ( 55)  W - 0x0057 Latin Capital Letter W
    {0x63,0x14,0x08,0x14,0x63},     //   ( 56)  X - 0x0058 Latin Capital Letter X
    {0x07,0x08,0x70,0x08,0x07},     //   ( 57)  Y - 0x0059 Latin Capital Letter Y
    {0x61,0x51,0x49,0x45,0x43},     //   ( 58)  Z - 0x005A Latin Capital Letter Z
    {0x00,0x7F,0x41,0x41,0x00},     //   ( 59)  [ - 0x005B Left Square Bracket
    {0x02,0x04,0x08,0x10,0x20},     //   ( 60)  \ - 0x005C Reverse Solidus
    {0x00,0x41,0x41,0x7F,0x00},     //   ( 61)  ] - 0x005D Right Square Bracket
    {0x04,0x02,0x01,0x02,0x04},     //   ( 62)  ^ - 0x005E Circumflex Accent
    {0x40,0x40,0x40,0x40,0x40},     //   ( 63)  _ - 0x005F Low Line
    {0x01,0x02,0x04,0x00,0x00},     //   ( 64)  ` - 0x0060 Grave Accent
    {0x20,0x54,0x54,0x54,0x78},     //   ( 65)  a - 0x0061 Latin Small Letter A
    {0x7F,0x48,0x44,0x44,0x38},     //   ( 66)  b - 0x0062 Latin Small Letter B
    {0x38,0x44,0x44,0x44,0x20},     //   ( 67)  c - 0x0063 Latin Small Letter C
    {0x38,0x44,0x44,0x48,0x7F},     //   ( 68)  d - 0x0064 Latin Small Letter D
    {0x38,0x54,0x54,0x54,0x18},     //   ( 69)  e - 0x0065 Latin Small Letter E
    {0x08,0x7E,0x09,0x01,0x02},     //   ( 70)  f - 0x0066 Latin Small Letter F
    {0x06,0x49,0x49,0x49,0x3F},     //   ( 71)  g - 0x0067 Latin Small Letter G
    {0x7F,0x08,0x04,0x04,0x78},     //   ( 72)  h - 0x0068 Latin Small Letter H
    {0x00,0x44,0x7D,0x40,0x00},     //   ( 73)  i - 0x0069 Latin Small Letter I
    {0x20,0x40,0x44,0x3D,0x00},     //   ( 74)  j - 0x006A Latin Small Letter J
    {0x7F,0x10,0x28,0x44,0x00},     //   ( 75)  k - 0x006B Latin Small Letter K
    {0x00,0x41,0x7F,0x40,0x00},     //   ( 76)  l - 0x006C Latin Small Letter L
    {0x7C,0x04,0x18,0x04,0x7C},     //   ( 77)  m - 0x006D Latin Small Letter M
    {0x7C,0x08,0x04,0x04,0x78},     //   ( 78)  n - 0x006E Latin Small Letter N
    {0x38,0x44,0x44,0x44,0x38},     //   ( 79)  o - 0x006F Latin Small Letter O
    {0x7C,0x14,0x14,0x14,0x08},     //   ( 80)  p - 0x0070 Latin Small Letter P
    {0x08,0x14,0x14,0x18,0x7C},     //   ( 81)  q - 0x0071 Latin Small Letter Q
    {0x7C,0x08,0x04,0x04,0x08},     //   ( 82)  r - 0x0072 Latin Small Letter R
    {0x48,0x54,0x54,0x54,0x20},     //   ( 83)  s - 0x0073 Latin Small Letter S
    {0x04,0x3F,0x44,0x40,0x20},     //   ( 84)  t - 0x0074 Latin Small Letter T
    {0x3C,0x40,0x40,0x20,0x7C},     //   ( 85)  u - 0x0075 Latin Small Letter U
    {0x1C,0x20,0x40,0x20,0x1C},     //   ( 86)  v - 0x0076 Latin Small Letter V
    {0x3C,0x40,0x30,0x40,0x3C},     //   ( 87)  w - 0x0077 Latin Small Letter W
    {0x44,0x28,0x10,0x28,0x44},     //   ( 88)  x - 0x0078 Latin Small Letter X
    {0x0C,0x50,0x50,0x50,0x3C},     //   ( 89)  y - 0x0079 Latin Small Letter Y
    {0x44,0x64,0x54,0x4C,0x44},     //   ( 90)  z - 0x007A Latin Small Letter Z
    {0x00,0x08,0x36,0x41,0x00},     //   ( 91)  { - 0x007B Left Curly Bracket
    {0x00,0x00,0x7F,0x00,0x00},     //   ( 92)  | - 0x007C Vertical Line
    {0x00,0x41,0x36,0x08,0x00},     //   ( 93)  } - 0x007D Right Curly Bracket
    {0x02,0x01,0x02,0x04,0x02},     //   ( 94)  ~ - 0x007E Tilde
    {0x08,0x0C,0x0E,0x0C,0x08},     //   ( 95)  upward facing triangle/arrow
    {0x08,0x18,0x38,0x18,0x08},     //   ( 96)  downward facing triangle/arrow
};

/*
SCK         <==     SCL_PIN 13
MOSI        <==     SDI_PIN 11
DC          <==     RS_PIN  4
OLEDCS      <==     CS_PIN  5
RES         <==     RES_PIN 6
*/

void NHD_OLED_Command(NHD_OLED_HandleTypeDef* holed, uint8_t Value)
{
    NHD_OLED_CS_LOW();
    NHD_OLED_DC_LOW();
    NHD_OLED_DataWrite(holed, &Value, 1);
    NHD_OLED_CS_HIGH();
}

void NHD_OLED_Data(NHD_OLED_HandleTypeDef* holed, uint8_t Value)
{
    NHD_OLED_CS_LOW();
    NHD_OLED_DC_HIGH();
    NHD_OLED_DataWrite(holed, &Value, 1);
    NHD_OLED_CS_HIGH();
}

void NHD_OLED_SerialPixelData16(NHD_OLED_HandleTypeDef* holed, uint16_t Value)
{
    NHD_OLED_CS_LOW();
    NHD_OLED_DC_HIGH();
    NHD_OLED_DataWrite(holed, (uint8_t*)&Value, 2);
    NHD_OLED_CS_HIGH();
}

void NHD_OLED_SerialPixelData8(NHD_OLED_HandleTypeDef* holed, uint8_t Value)
{
    NHD_OLED_CS_LOW();
    NHD_OLED_DC_HIGH();
    NHD_OLED_DataWrite(holed, &Value, 1);
    NHD_OLED_CS_HIGH();
}

void NHD_OLED_SetColumnAddress(NHD_OLED_HandleTypeDef* holed, uint8_t x_start, uint8_t x_end)
{
    NHD_OLED_Command(holed, SEPS525_REG_MX1_ADDR);
    NHD_OLED_Data(holed, x_start);
    NHD_OLED_Command(holed, SEPS525_REG_MX2_ADDR);
    NHD_OLED_Data(holed, x_end);
}

void NHD_OLED_SetRowAddress(NHD_OLED_HandleTypeDef* holed, uint8_t y_start, uint8_t y_end)
{
    NHD_OLED_Command(holed, SEPS525_REG_MY1_ADDR);
    NHD_OLED_Data(holed, y_start);
    NHD_OLED_Command(holed, SEPS525_REG_MY2_ADDR);
    NHD_OLED_Data(holed, y_end);
}

void NHD_OLED_SetWindow(NHD_OLED_HandleTypeDef* holed, uint8_t x_start, uint8_t y_start, uint8_t x_end, uint8_t y_end)
{
    NHD_OLED_SetColumnAddress(holed, x_start, x_end);
    NHD_OLED_SetRowAddress(holed, y_start, y_end);
}

void NHD_OLED_WriteMemoryStart(NHD_OLED_HandleTypeDef* holed)
{
    NHD_OLED_Command(holed, SEPS525_REG_DDRAMDATAACCESSPORT);
}

void NHD_OLED_SetPosition(NHD_OLED_HandleTypeDef* holed, unsigned char x_pos, unsigned char y_pos)    // write one pixel of a given color
{
    NHD_OLED_Command(holed, SEPS525_REG_MEMORY_ACCESS_POINTERX);
    NHD_OLED_Data(holed, x_pos);
    NHD_OLED_Command(holed, SEPS525_REG_MEMORY_ACCESS_POINTERY);
    NHD_OLED_Data(holed, y_pos);
}

void NHD_OLED_FillScreen(NHD_OLED_HandleTypeDef* holed, uint16_t color)    // fill screen with a given color
{
    NHD_OLED_SetPosition(holed, 0, 0);
    NHD_OLED_SetWindow(holed, 0, 0, 159, 127);
    NHD_OLED_WriteMemoryStart(holed);
    for(size_t i=0;i<20480;i++)
    {
        NHD_OLED_SerialPixelData16(holed, color);
    }
}

void NHD_OLED_Init(NHD_OLED_HandleTypeDef* holed)
{
    NHD_OLED_RES_LOW();
    HAL_Delay(2);
    NHD_OLED_RES_HIGH();
    HAL_Delay(2);

    for (size_t i = 0; i < sizeof(NHD_OLED_Init_Sequence); i+=2)
    {
        NHD_OLED_Command(holed, NHD_OLED_Init_Sequence[i]);
        NHD_OLED_Data(holed, NHD_OLED_Init_Sequence[i+1]);

        if (i <= 3)
            HAL_Delay(1);
    }
}

////////////////////////////////////////////////////////////////////////

/*********************************/
/***** HIGH LEVEL FUNCTIONS ******/
/************ START **************/
/*********************************/

void NHD_OLED_Char(NHD_OLED_HandleTypeDef* holed, unsigned char x_pos, unsigned char y_pos, unsigned char letter, uint16_t textColor, uint16_t backgroundColor)  // function to show text
{
    int i;
    int count;
    unsigned char mask = 0x80;
    letter -= 0x20;
    
    NHD_OLED_SetPosition(holed,x_pos,y_pos);
    NHD_OLED_SetWindow(holed,x_pos,y_pos,x_pos+4,y_pos+7);
    NHD_OLED_WriteMemoryStart(holed);
    for(i=0;i<8;i++)     // each character is 8 pixels tall
    {
        for (count=0;count<5;count++)    // each character is 5 pixels wide
        {
            if((NHD_OLED_Ascii_1[letter][count] & mask) == mask)
                NHD_OLED_SerialPixelData16(holed,textColor);
            else
                NHD_OLED_SerialPixelData16(holed,backgroundColor);
        }
        mask = mask >> 1;
    }
}

void NHD_OLED_Char2x(NHD_OLED_HandleTypeDef* holed, unsigned char x_pos, unsigned char y_pos, unsigned char letter, uint16_t textColor, uint16_t backgroundColor)  // function to show text (2x size)
{
    int i;
    int count;
    unsigned char mask = 0x80;
    letter -= 0x20;
    
    NHD_OLED_SetPosition(holed,x_pos,y_pos);
    NHD_OLED_SetWindow(holed,x_pos,y_pos,x_pos+9,y_pos+15);
    NHD_OLED_WriteMemoryStart(holed);
    for(i=1;i<=16;i++)     // each character is 16 pixels tall
    {
        for (count=0;count<10;count++)    // each character is 10 pixels wide
        {
            if((NHD_OLED_Ascii_1[letter][(count/2)] & mask) == mask)
                NHD_OLED_SerialPixelData16(holed,textColor);
            else
                NHD_OLED_SerialPixelData16(holed,backgroundColor);
        }
        if((i%2)==0)
        {
            mask = mask >> 1;
        }
    }
}

void NHD_OLED_Text(NHD_OLED_HandleTypeDef* holed, unsigned char x_pos, unsigned char y_pos, char* message, uint16_t textColor, uint16_t backgroundColor)
{
    char* pCurrent = message;
    while((*pCurrent) != 0)
    {
        uint16_t offset = ((pCurrent - message) * 6);
        NHD_OLED_Char(holed, x_pos + offset, y_pos, *pCurrent++, textColor, backgroundColor);
    }
}

void NHD_OLED_Text2x(NHD_OLED_HandleTypeDef* holed, unsigned char x_pos, unsigned char y_pos, char* message, uint16_t textColor, uint16_t backgroundColor)
{
    char* pCurrent = message;
    while((*pCurrent) != 0)
    {
        uint16_t offset = ((pCurrent - message) * 11);
        NHD_OLED_Char2x(holed, x_pos + offset, y_pos, *pCurrent++, textColor, backgroundColor);
    }
}
