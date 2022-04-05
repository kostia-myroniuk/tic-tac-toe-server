#ifndef LOBBY_H
#define LOBBY_H

#include <QString>

#include <vector>

#include "player.h"
#include "game.h"
#include "game_settings.h"

enum class LobbyState {
    WAITING,
    GAME,
    RESULTS
};

class Lobby
{
public:
    Lobby(int _id, QString _name, GameSettings* _gameSettings);
    int GetId();
    QString GetName();
    GameSettings* GetGameSettings();
    LobbyState GetState();
    Game* GetGame();
    bool HasPlayer(Player* player);
    void AddPlayer(Player* player);
    void DeletePlayer(Player* player);

private:
    int id;
    QString name;
    GameSettings* gameSettings;
    LobbyState state;
    Player* playerX;
    Player* playerO;
    Game game;
};

#endif // LOBBY_H
