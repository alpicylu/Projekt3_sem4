#pragma once
#include "gamestate.hh"
#include <memory>
#include <vector>

template <int N>
class Node
{
    GameState<N> current_gs;
    int game_value;
};