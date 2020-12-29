#ifndef __NHD_OLED_H
#define __NHD_OLED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f3xx_hal.h"

typedef struct __NHD_OLED_HandleTypeDef {
    GPIO_TypeDef* RES_GPIO_Port;
    uint16_t RES_Pin;
    GPIO_TypeDef* CS_GPIO_Port;
    uint16_t CS_Pin;
    GPIO_TypeDef* DC_GPIO_Port;
    uint16_t DC_Pin;
    GPIO_TypeDef* LED_GPIO_Port;
    uint16_t LED_Pin;
    SPI_HandleTypeDef* hspi;
} NHD_OLED_HandleTypeDef;

#define SEPS525_PIXEL_WIDTH                ((uint8_t)160)
#define SEPS525_PIXEL_HEIGHT               ((uint8_t)128)
#define SEPS525_PIXEL_TOTAL                ((uint16_t)SEPS525_PIXEL_WIDTH*SEPS525_PIXEL_HEIGHT)

#define SEPS525_REG_INDEX                   0x00
#define SEPS525_REG_STATUS_RD               0x01
#define SEPS525_REG_OSC_CTL                 0x02
#define SEPS525_REG_IREF                    0x80
#define SEPS525_REG_CLOCK_DIV               0x03
#define SEPS525_REG_REDUCE_CURRENT          0x04
#define SEPS525_REG_SOFT_RST                0x05
#define SEPS525_REG_DISP_ON_OFF             0x06
#define SEPS525_REG_PRECHARGE_TIME_R        0x08
#define SEPS525_REG_PRECHARGE_TIME_G        0x09
#define SEPS525_REG_PRECHARGE_TIME_B        0x0A
#define SEPS525_REG_PRECHARGE_CURRENT_R     0x0B
#define SEPS525_REG_PRECHARGE_CURRENT_G     0x0C
#define SEPS525_REG_PRECHARGE_CURRENT_B     0x0D
#define SEPS525_REG_DRIVING_CURRENT_R       0x10
#define SEPS525_REG_DRIVING_CURRENT_G       0x11
#define SEPS525_REG_DRIVING_CURRENT_B       0x12
#define SEPS525_REG_DISPLAY_MODE_SET        0x13
#define SEPS525_REG_RGB_IF                  0x14
#define SEPS525_REG_RGB_POL                 0x15
#define SEPS525_REG_MEMORY_WRITE_MODE       0x16
#define SEPS525_REG_MX1_ADDR                0x17
#define SEPS525_REG_MX2_ADDR                0x18
#define SEPS525_REG_MY1_ADDR                0x19
#define SEPS525_REG_MY2_ADDR                0x1A
#define SEPS525_REG_MEMORY_ACCESS_POINTERX  0x20
#define SEPS525_REG_MEMORY_ACCESS_POINTERY  0x21
#define SEPS525_REG_DDRAMDATAACCESSPORT     0x22
#define SEPS525_REG_GRAY_SCALE_TABLE_INDEX  0x50
#define SEPS525_REG_GRAY_SCALE_TABLE_DAT    0x51
#define SEPS525_REG_DUTY                    0x28
#define SEPS525_REG_DSL                     0x29
#define SEPS525_REG_D1_DDRAM_FAC            0x2E
#define SEPS525_REG_D1_DDRAM_FAR            0x2F
#define SEPS525_REG_D1_DDRAM_SAC            0x31
#define SEPS525_REG_D1_DDRAM_SAR            0x32
#define SEPS525_REG_SCR1_FX1                0x33
#define SEPS525_REG_SCR1_FX2                0x34
#define SEPS525_REG_SCR1_FY1                0x35
#define SEPS525_REG_SCR1_FY2                0x36
#define SEPS525_REG_SCR1_SX1                0x37
#define SEPS525_REG_SCR1_SX3                0x38
#define SEPS525_REG_SCR1_SY1                0x39
#define SEPS525_REG_SCR1_SY2                0x3A
#define SEPS525_REG_SCREEN_SAVER_CONTROL    0x3B
#define SEPS525_REG_SS_SLEEP_TIMER          0x3C
#define SEPS525_REG_SCREEN_SAVER_MODE       0x3D
#define SEPS525_REG_SS_SCR1_FU              0x3E
#define SEPS525_REG_SS_SCR1_MXY             0x3F
#define SEPS525_REG_SS_SCR2_FU              0x40
#define SEPS525_REG_SS_SCR2_MXY             0x41
#define SEPS525_REG_MOVING_DIRECTION        0x42
#define SEPS525_REG_SS_SCR2_SX1             0x47
#define SEPS525_REG_SS_SCR2_SX2             0x48
#define SEPS525_REG_SS_SCR2_SY1             0x49
#define SEPS525_REG_SS_SCR2_SY2             0x4A

#define NHD_OLED_CS_LOW() HAL_GPIO_WritePin(holed->CS_GPIO_Port, holed->CS_Pin, GPIO_PIN_RESET)
#define NHD_OLED_CS_HIGH() HAL_GPIO_WritePin(holed->CS_GPIO_Port, holed->CS_Pin, GPIO_PIN_SET)
#define NHD_OLED_RES_LOW() HAL_GPIO_WritePin(holed->RES_GPIO_Port, holed->RES_Pin, GPIO_PIN_RESET)
#define NHD_OLED_RES_HIGH() HAL_GPIO_WritePin(holed->RES_GPIO_Port, holed->RES_Pin, GPIO_PIN_SET)
#define NHD_OLED_DC_LOW() HAL_GPIO_WritePin(holed->DC_GPIO_Port, holed->DC_Pin, GPIO_PIN_RESET)
#define NHD_OLED_DC_HIGH() HAL_GPIO_WritePin(holed->DC_GPIO_Port, holed->DC_Pin, GPIO_PIN_SET)
#define NHD_OLED_LED_BLINK() HAL_GPIO_TogglePin(holed->LED_GPIO_Port, holed->LED_Pin)

#define NHD_OLED_RGB565(R,G,B) ((R&0x1F)<<11)|(B&0x1F)<<3|(G&0x7)|((G&0x38)<<5)
static const uint16_t RGB565[16] = {
  NHD_OLED_RGB565(0x00, 0x00, 0x00), // Black  
  NHD_OLED_RGB565(0x00, 0x00, 0x0F), // Blue
  NHD_OLED_RGB565(0x00, 0x1F, 0x00), // Green
  NHD_OLED_RGB565(0x00, 0x1F, 0x0F), // Aqua
  NHD_OLED_RGB565(0x0F, 0x00, 0x00), // Red
  NHD_OLED_RGB565(0x0F, 0x00, 0x0F), // Purple Y
  NHD_OLED_RGB565(0x0F, 0x1F, 0x00), // Yellow
  NHD_OLED_RGB565(0x0F, 0x1F, 0x0F), // White B
  NHD_OLED_RGB565(0x07, 0x0F, 0x07), // Gray  1
  NHD_OLED_RGB565(0x00, 0x00, 0x1F), // Blue  G
  NHD_OLED_RGB565(0x00, 0x3F, 0x00), // Green B
  NHD_OLED_RGB565(0x00, 0x3F, 0x1F), // Aqua  1
  NHD_OLED_RGB565(0x1F, 0x00, 0x00), // Red   1
  NHD_OLED_RGB565(0x1F, 0x00, 0x1F), // Purple
  NHD_OLED_RGB565(0x1F, 0x3F, 0x00), // Yellow
  NHD_OLED_RGB565(0x1F, 0x3F, 0x1F), // Bright White
};

static const uint32_t RGB888[16] = {
  0x000000, // Black
  0x000080, // Blue
  0x008000, // Green
  0x008080, // Aqua
  0x800000, // Red
  0x800080, // Purple
  0x808000, // Yellow
  0xC0C0C0, // White
  0x808080, // Gray
  0x0000FF, // Light Blue
  0x00FF00, // Light Green
  0x00FFFF, // Light Aqua
  0xFF0000, // Light Red
  0xFF00FF, // Light Purple
  0xFFFF00, // Light Yellow
  0xFFFFFF, // Bright White
}; 

extern void NHD_OLED_DataWrite(NHD_OLED_HandleTypeDef* holed, uint8_t* pData, size_t size);

void NHD_OLED_Command(NHD_OLED_HandleTypeDef* holed, uint8_t Value);
void NHD_OLED_Data(NHD_OLED_HandleTypeDef* holed, uint8_t Value);
void NHD_OLED_SerialPixelData8(NHD_OLED_HandleTypeDef* holed, uint8_t Value);
void NHD_OLED_SerialPixelData16(NHD_OLED_HandleTypeDef* holed, uint16_t Value);
void NHD_OLED_SetColumnAddress(NHD_OLED_HandleTypeDef* holed, uint8_t x_start, uint8_t x_end);
void NHD_OLED_SetRowAddress(NHD_OLED_HandleTypeDef* holed, uint8_t y_start, uint8_t y_end);
void NHD_OLED_WriteMemoryStart(NHD_OLED_HandleTypeDef* holed);
void NHD_OLED_Pixel_RGB888(NHD_OLED_HandleTypeDef* holed, uint16_t color);
void NHD_OLED_SetPosition(NHD_OLED_HandleTypeDef* holed, unsigned char x_pos, unsigned char y_pos);
void NHD_OLED_FillScreen(NHD_OLED_HandleTypeDef* holed, uint16_t color);
void NHD_OLED_Init(NHD_OLED_HandleTypeDef* holed);

void NHD_OLED_Text(NHD_OLED_HandleTypeDef* holed, unsigned char x_pos, unsigned char y_pos, char* message, uint16_t textColor, uint16_t backgroundColor);
void NHD_OLED_Text2x(NHD_OLED_HandleTypeDef* holed, unsigned char x_pos, unsigned char y_pos, char* message, uint16_t textColor, uint16_t backgroundColor);
void NHD_OLED_Char(NHD_OLED_HandleTypeDef* holed, unsigned char x_pos, unsigned char y_pos, unsigned char letter, uint16_t textColor, uint16_t backgroundColor);
void NHD_OLED_Char2x(NHD_OLED_HandleTypeDef* holed, unsigned char x_pos, unsigned char y_pos, unsigned char letter, uint16_t textColor, uint16_t backgroundColor);

#ifdef __cplusplus
}
#endif

#endif /* __NHD_OLED_H */