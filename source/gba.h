// hardware reader

#ifndef GBA_H
#define GBA_H

typedef unsigned short u16; 
typedef unsigned int u32;
typedef unsigned char u8;

// define MEM_IO; the base address for I/O registers in GBA at 0x04000000
#define MEM_IO          0x04000000
#define MEM_VRAM        0x06000000
#define REG_DISPCNT     (*(volatile u16*)(MEM_IO+0x0000))
// VRAM: one long line of pixels (index 0 to 38,399) (240 * 160)
// index VRAM = (y x 240) + x
#define VRAM            ((volatile u16*)(MEM_VRAM+0x0000))
#define REG_VCOUNT      (*(volatile u16*)(MEM_IO+0x0006))  // which line the screen is drawing at any point
#define REG_KEYINPUT    (*(volatile u16*)(MEM_IO+0x0130))

#define KEY_A       (1<<0)
#define KEY_B       (1<<1)
#define KEY_SELECT  (1<<2)
#define KEY_START   (1<<3)
#define KEY_RIGHT   (1<<4)
#define KEY_LEFT    (1<<5)
#define KEY_UP      (1<<6)
#define KEY_DOWN    (1<<7)
#define KEY_R       (1<<8)
#define KEY_L       (1<<9)

static inline u16 RGB15(u16 r, u16 g, u16 b) {
    return r | g<<5 | b<<10; // packs three small numbers into one 16-bit number
    // this is the format GBA reads colours in
}

#endif

// colours
/* bit:  15 | 14 13 12 11 10 | 9 8 7 6 5 | 4 3 2 1 0
        -- |      blue      |   green   |    red
*/
/*
3          = 0b00000 00000 00011
3 << 5     = 0b00000 00011 00000   ← now sitting in the green slot
*/
