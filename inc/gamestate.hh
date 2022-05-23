#pragma once

#include <iostream>

template <int N>
class GameState
{
private:
    enum GSplayers{
        empty = ' ',
        player = 'X',
        cpu = 'O',
    };
    enum GSoutcome{
        playerWin = 10, //game state value for when the player wins in the current configuration
        cpuWin = -10,    //...when the cpu wins...
        tie = 0,       //...when tie occurs...
        undecided = 1, //...when moves are yet to be made...
    };
    char table[N][N];
    bool current_turn; //true if player, false s cpu
                       //for simplicity's sake, X is always the player and O always the cpu
public:
    GameState()
    {
        for (int i=0; i<N; i++)
        {
            for (int k=0; k<N; k++)
            {
                table[i][k] = GSplayers::empty;
            }
        }
    };

    bool is_placable(int, int);

    void place_mark(bool, int, int);

    void show_game();

    int evaluate_gs();

};

#include "gamestate.tpp"

