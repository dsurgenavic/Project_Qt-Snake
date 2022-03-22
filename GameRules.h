#ifndef GAMERULES_H
#define GAMERULES_H

enum GameSpeed{SLOW, NORMAL, FAST};

struct GameRules {
    enum GameSpeed gameSpeed = NORMAL;
    bool multiplayer = false;
};

#endif // GAMERULES_H
