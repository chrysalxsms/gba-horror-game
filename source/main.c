#include "gba.h"

void vsync() {
    while(REG_VCOUNT >= 160);
    while (REG_VCOUNT < 160);
}

int main() {
    REG_DISPCNT = 0x0403;
    for (int y=0; y<160; y++) {
        for (int x=0; x<240; x++) {
            VRAM[y * 240 + x] = RGB15(10, 0, 0);
        }
    }
    int x = 120;
    int y = 80;
    while(1) {
        vsync();
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                VRAM[(y+j) * 240 + (x+i)] = RGB15(10, 0, 0);
            }
        }
        if ((REG_KEYINPUT & KEY_RIGHT) == 0) {
            x++;
            if (x > 240 - 8) {
                x = 240 - 8;
            }
        }
        if ((REG_KEYINPUT & KEY_LEFT) == 0) {
            x--;
            if (x < 0) {
                x = 0;
            }
        }
        if ((REG_KEYINPUT & KEY_UP) == 0) {
            y--;
            if (y < 0) {
                y = 0;
            }
        }
        if ((REG_KEYINPUT & KEY_DOWN) == 0) {
            y++;
            if (y > 160 - 8) {
                x = 160 - 8;
            }
        }
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                VRAM[(y+j) * 240 + (x+i)] = RGB15(31, 31, 31);
            }
        }
    }
}