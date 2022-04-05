#ifndef LOBBYCONTROLLER_H
#define LOBBYCONTROLLER_H

#include <vector>

#include "lobby.h"

class LobbyController
{
public:
    LobbyController();
    Lobby* GetLobby(int lobbyId);
    Lobby* GetLobby(Player* player);
    std::vector<Lobby*> GetLobbyList();
    int NextLobbyId();
    void CreateLobby(QString lobbyName, GameSettings* gameSettings);

private:
    std::vector<Lobby> lobbies;
};

#endif // LOBBYCONTROLLER_H
