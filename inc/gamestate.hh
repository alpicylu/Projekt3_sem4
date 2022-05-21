#include <iostream>

template <int N>
class GameState
{
private:
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
                table[i][k] = ' ';
            }
        }
    };

    bool is_placable(int, int);

    void place_mark(bool, int, int);

    void show_game();

};

#include "gamestate.tpp"

