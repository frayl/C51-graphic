#include "vbuf.h"

unsigned char xdata vbuf[VBUF_ROWS * VBUF_COLS] _at_ 0x0000;

unsigned char code cmap[7][9] = 
    {
        {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, //space 
        {0x00, 0x20, 0x50, 0x88, 0x88, 0xF8, 0x88, 0x88, 0x00}, //A
        {0x00, 0xF0, 0x88, 0x88, 0xF0, 0x88, 0x88, 0xF0, 0x00}, //B
        {0x00, 0x78, 0x80, 0x80, 0x80, 0x80, 0x80, 0x78, 0x00}, //C
        {0x00, 0xF0, 0x88, 0x88, 0x88, 0x88, 0x88, 0xF0, 0x00}, //D
        {0x00, 0xF8, 0x80, 0x80, 0xF8, 0x80, 0x80, 0xF8, 0x00}, //E
        {0x00, 0xF8, 0x80, 0x80, 0xF8, 0x80, 0x80, 0x80, 0x00}  //F
    };
unsigned char code banner[BANNER_LEN] = 
{
    0x00,0x0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
    0x00,0x04,0x00,0x00,0x04,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20, 
    0x00,0x04,0x00,0x00,0x04,0x00,0x20,0x00,0x1C,0x0FC,0x0FC,0x0F0,0x7C,0x0FC,0x0C0,0x60, 
    0x00,0x00,0x80,0x00,0x0C,0x0F8,0x7C,0x0F0,0x30,0x10,0x00,0x10,0x7C,0x0FC,0x0C0,0x40, 
    0x1C,0x0FC,0x0FC,0x0E0,0x0C,0x0FC,0x7C,0x0F8,0x20,0x30,0x00,0x10,0x08,0x08,0x00,0x0C0, 
    0x3C,0x0FC,0x0FC,0x0F0,0x18,0x40,0x0C8,0x00,0x20,0x20,0x00,0x10,0x08,0x08,0x04,0x80, 
    0x20,0x00,0x00,0x10,0x10,0x40,0x8C,0x00,0x20,0x7C,0x0F8,0x10,0x08,0x08,0x0C,0x00 ,
    0x20,0x00,0x00,0x10,0x30,0x64,0x84,0x00,0x20,0x60,0x0C,0x10,0x08,0x08,0x18,0x00,
    0x20,0x00,0x00,0x10,0x20,0x24,0x04,0x00,0x20,0x0E0,0x08,0x10,0x08,0x08,0x70,0x00,
    0x2C,0x0FC,0x0FC,0x90,0x00,0x20,0x04,0x00,0x24,0x0B0,0x18,0x10,0x08,0x08,0x0C0,0x10,
    0x20,0x00,0x00,0x0A0,0x04,0x00,0x00,0x80,0x2C,0x18,0x10,0x10,0x08,0x08,0x00,0x10,
    0x00,0x00,0x0C,0x00,0x04,0x00,0x00,0x80,0x20,0x0C,0x20,0x10,0x08,0x08,0x00,0x30,
    0x00,0x00,0x38,0x00,0x04,0x00,0x00,0x80,0x20,0x04,0x0E0,0x10,0x08,0x08,0x00,0x60,
    0x00,0x00,0x60,0x00,0x08,0x7C,0x0FC,0x0F8,0x20,0x04,0x0C0,0x10,0x08,0x08,0x00,0x40,
    0x00,0x04,0x0C0,0x00,0x08,0x7C,0x0FC,0x0F8,0x20,0x0C,0x60,0x10,0x7C,0x0FC,0x0C0,0x0C0,
    0x00,0x0C,0x00,0x00,0x18,0x00,0x00,0x80,0x20,0x38,0x38,0x10,0x08,0x08,0x04,0x80,
    0x00,0x0C,0x00,0x00,0x18,0x08,0x00,0x80,0x24,0x0E0,0x0C,0x90,0x08,0x08,0x0C,0x00,
    0x00,0x04,0x80,0x00,0x38,0x08,0x00,0x80,0x2C,0x88,0x00,0x0D0,0x08,0x08,0x38,0x00,
    0x00,0x00,0x80,0x00,0x68,0x0C,0x00,0x80,0x20,0x0C,0x80,0x10,0x08,0x08,0x0E0,0x08,
    0x3C,0x0FC,0x0FC,0x0F8,0x0C8,0x04,0x00,0x80,0x20,0x00,0x0E0,0x10,0x08,0x08,0x80,0x18,
    0x3C,0x0FC,0x0FC,0x0F8,0x88,0x04,0x80,0x80,0x20,0x00,0x30,0x10,0x08,0x08,0x00,0x10,
    0x00,0x00,0x60,0x00,0x08,0x00,0x80,0x80,0x20,0x20,0x10,0x10,0x08,0x08,0x00,0x30,
    0x00,0x00,0x20,0x00,0x08,0x00,0x80,0x80,0x20,0x38,0x00,0x10,0x08,0x08,0x00,0x20,
    0x00,0x00,0x20,0x00,0x08,0x00,0x40,0x80,0x20,0x1C,0x80,0x10,0x18,0x08,0x00,0x40,
    0x00,0x00,0x20,0x00,0x08,0x00,0x40,0x80,0x20,0x00,0x0C0,0x10,0x10,0x08,0x00,0x0C0,
    0x00,0x00,0x20,0x00,0x08,0x00,0x00,0x80,0x20,0x00,0x70,0x10,0x10,0x08,0x04,0x80,
    0x00,0x00,0x20,0x00,0x08,0x00,0x00,0x80,0x20,0x00,0x18,0x10,0x10,0x08,0x0C,0x00,
    0x00,0x00,0x60,0x00,0x08,0x04,0x00,0x80,0x20,0x00,0x00,0x10,0x30,0x08,0x18,0x00,
    0x00,0x0C0,0x0C0,0x00,0x08,0x04,0x0E4,0x80,0x3C,0x0FC,0x0FC,0x0F0,0x20,0x08,0x70,0x00,
    0x00,0x0FC,0x0C0,0x00,0x08,0x00,0x7C,0x00,0x1C,0x0FC,0x0FC,0x0E0,0x60,0x08,0x40,0x00
};

void vbuf_block_write(
    vbufOffset_t top_left, 
    uint8_t width,
    uint8_t height,
    uint16_t buflen, 
    unsigned char *buf,
    uint8_t fillwith
) reentrant
{
    uint16_t char_count = 0;
    uint8_t row = 0, col = 0;
    vbufOffset_t offset;
    for( ; row < height; row++ ){
        offset = top_left + row * VBUF_COLS;
        for(col = 0 ; col < width; col++ ){
            if( char_count < buflen){
                vbuf[offset++] = buf[char_count++];
            }
            else{
                vbuf[offset++] = fillwith;
            }
        }
    }
}
