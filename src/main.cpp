#include <iostream>

#include "node.hh"
#include "gamestate.hh"

int main()
{
    using namespace std;
    GameState<2> gs;

    gs.place_mark(true,0,0);
    // gs.place_mark(false,1,1);
    gs.place_mark(true,1,0);
    gs.place_mark(false,0,1);
    gs.show_game();
    cout << gs.evaluate_gs();

}

//https://codereview.stackexchange.com/questions/183594/simple-tic-tac-toe-with-minimax-algorithm