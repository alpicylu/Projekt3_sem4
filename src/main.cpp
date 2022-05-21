#include <iostream>

#include "node.hh"
#include "gamestate.hh"

int main()
{
    using namespace std;
    GameState<3> gs;

    gs.show_game();
    gs.place_mark(false,0,0);
}

//https://codereview.stackexchange.com/questions/183594/simple-tic-tac-toe-with-minimax-algorithm