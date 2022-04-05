#include "lobby.h"

Lobby::Lobby(int _id, QString _name, GameSettings *_gameSettings)
    : game(_gameSettings)
{
    id = _id;
    name = _name;
    gameSettings = _gameSettings;
    state = LobbyState::WAITING;
}

int Lobby::GetId()
{
    return id;
}

QString Lobby::GetName()
{
    return name;
}

GameSettings *Lobby::GetGameSettings()
{
    return gameSettings;
}

LobbyState Lobby::GetState()
{
    return state;
}

Game *Lobby::GetGame()
{
    return &game;
}

bool Lobby::HasPlayer(Player *player)
{
    return (playerX != nullptr && playerX->EqualTo(player))
        || (playerO != nullptr && playerO->EqualTo(player));
}

void Lobby::AddPlayer(Player *player)
{
    if (!HasPlayer(player)) {
        if (playerX == nullptr) {
            playerX = player;
        }
        else if (playerO == nullptr) {
            playerO = player;
            state = LobbyState::GAME;
        }
    }
}

void Lobby::DeletePlayer(Player *player)
{
    if (HasPlayer(player)) {
        if (state == LobbyState::WAITING) {
            if (playerX->EqualTo(player)) {
                playerX = playerO;
                playerO = nullptr;
            }
            else if (playerO->EqualTo(player)) {
                playerO = nullptr;
            }
        }
        else if (state == LobbyState::GAME) {
            if (playerX->EqualTo(player)) {
                playerX = playerO;
                playerO = nullptr;
            }
            else if (playerO->EqualTo(player)) {
                playerO = nullptr;
            }
            state = LobbyState::WAITING;
        }
    }
}
