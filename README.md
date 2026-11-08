A horror game under development with mGBA, for the Game Boy Advance SP.

## Roadmap

- [x] **Hello hardware:** mode 3, fill the screen with dark red
- [x] **Player:** a sprite moved with the D-pad (reading input registers)
- [ ] **The house:** tile map background + wall collision
- [ ] **Flashlight:** windows (WIN0/WIN1) changed per scanline via HDMA / line interrupts for a circle or cone of light
- [ ] **Monster:** state machine (wander → hear → chase → lose you), BFS pathfinding on the tile grid
- [ ] **Atmosphere:** flicker via brightness/blend registers, heartbeat sound, jumpscare, win/lose screens
