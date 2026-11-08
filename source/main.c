#include "gba.h"

int main() {
    REG_DISPCNT = 0x0403;
    for (int y=0; y<160; y++) {
        for (int x=0; x<240; x++) {
            VRAM[y * 240 + x] = RGB15(10, 0, 0);
        }
    }
    while(1);
}