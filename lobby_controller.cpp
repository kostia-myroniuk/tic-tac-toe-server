#include "lobby_controller.h"


LobbyController::LobbyController()
{

}

Lobby *LobbyController::GetLobby(int lobbyId)
{
    for (int index = 0; index < lobbies.size(); index++) {
        Lobby* lobby = &lobbies[index];
        if (lobby->GetId() == lobbyId) {
            return lobby;
        }
    }
    return nullptr;
}

Lobby *LobbyController::GetLobby(Player *player)
{
    for (int index = 0; index < lobbies.size(); index++) {
        Lobby* lobby = &lobbies[index];
        if (lobby->HasPlayer(player)) {
            return lobby;
        }
    }
    return nullptr;
}

std::vector<Lobby *> LobbyController::GetLobbyList()
{
    std::vector<Lobby *> lobbyList;
    for (int index = 0; index < lobbies.size(); index++) {
        lobbyList.push_back(&lobbies[index]);
    }
    return lobbyList;
}

int LobbyController::NextLobbyId()
{
    int id = 0;
    for (int index = 0; index < lobbies.size(); index++) {
        Lobby* lobby = &lobbies[index];
        if (lobby->GetId() > id) {
            id = lobby->GetId() + 1;
        }
    }
    return id;
}

void LobbyController::CreateLobby(QString lobbyName, GameSettings* gameSettings)
{
    int nextLobbyId = NextLobbyId();
    lobbies.push_back(Lobby(nextLobbyId, lobbyName, gameSettings));
}
