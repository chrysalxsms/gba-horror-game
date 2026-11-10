#include "gba.h"

void vsync() {
    while(REG_VCOUNT >= 160);
    while (REG_VCOUNT < 160);
}

void hide_all_sprites() {
    for (int i=0; i<128; i++) {
        REG_OAM[i*4] = ATTR0_HIDE;
    }
}

int main() {
    REG_DISPCNT = 0 | SPRITES | MAP_1D;
    PAL_BG[0] = RGB15(10, 0, 0);
    PAL_OBJ[1] = RGB15(31, 31, 31);

    for (int i = 0; i < 8; i++) {
        REG_TILEMEM[i] = 0x11111111;
    }

    hide_all_sprites();

    int x = 120;
    int y = 80;

    REG_OAM[0] = y;
    REG_OAM[1] = x;
    REG_OAM[2] = 0; // tile 0

    while(1) {
        vsync();
        u16 keys_current = ~REG_KEYINPUT & 0x03FF;
        int dx = ((keys_current & KEY_RIGHT) != 0) - ((keys_current & KEY_LEFT) != 0);
        int dy = ((keys_current & KEY_DOWN) != 0) - ((keys_current & KEY_UP) != 0);

        y = y + dy;
        x = x + dx;
        
        if (y > 160 - 8) {
            y = 160 - 8;
        }
        if (y < 0) {
            y = 0;
        }
        if (x < 0) {
            x = 0;
        }
        if (x > 240 - 8) {
            x = 240 - 8;
        }
        
        REG_OAM[0] = y & 0xFF;
        REG_OAM[1] = x & 0x1FF;

    }
}