/*
 * uc1609.h
 *
 *  Created on: Apr 29, 2020
 *      Author: Li Jingchen
 */

#ifndef INC_UC1609_H_
#define INC_UC1609_H_

#include "main.h"

//定义LCD屏接线

//RST   PA3
//CS    PA4
//SCK   PA5
//CD    PA6
//SDA   PA7

extern uint8_t disp_buf[];

//声明功能函数
void lcd_init(void);
void lcd_cls(uint8_t rev);
void display_one_char(uint8_t x, uint8_t y, char char_data, uint8_t rev);
void display_list_char(uint8_t x, uint8_t y, char *data_s, uint8_t rev);
void display_816_char(uint8_t x, uint8_t y, char char_data, uint8_t rev);
void display_list_816(uint8_t x, uint8_t y, char *data_s, uint8_t rev);

void gui_point(uint8_t X, uint8_t Y, uint8_t draw_mode);
void glcd_line(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t show);
void glcd_circle(int16_t x, int16_t y, int16_t radius, uint8_t show);

#endif /* INC_UC1609_H_ */
