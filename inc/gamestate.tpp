
template <int N>
bool GameState<N>::is_placable(int row, int col)
{
    if (table[row][col] != ' ') return false;
    return true;
}

template <int N>
void GameState<N>::place_mark(bool turn, int row, int col)
{
    // GSc player_mark = GSconst::player;
    // char cpu_mark = GSconst::cpu;
    if (is_placable(row, col))
    {
        table[row][col] = turn ? GSplayers::player : GSplayers::cpu;
        return;
    }
    std::cerr << "Mark can't be placed here" << std::endl;
}

template <int N>
void GameState<N>::show_game()
{
    using namespace std;
    for (int row=0; row<N; row++)
    {
        for (int col=0; col<N; col++)
        {
            cout << table[row][col];
            if (col == N-1) cout << endl;
            else if (col != N-1) cout << " | ";
        }
        if (row != N-1) cout << "---------" << endl; //fix so that larger games make sense visually
    }

    cout << "__________________________________" << endl;
}

template <int N>
int GameState<N>::evaluate_gs()
{
    //first, check if game is unfinished
    for (int row=0; row<N; row++){
        for (int col=0; col<N; col++){
            if (table[row][col] == GSplayers::empty) return GSoutcome::undecided;
        }
    }

    //the code for checking wether O or X won is the same, so we just iterate over this short array.
    //of course, this method "favours" the player, but getting in a situation where both O and X won is imposible
    char X_and_O[2] = {GSplayers::player, GSplayers::cpu};
    for (int pl=0; pl<2; pl++)
    {
        char mark = X_and_O[pl];

        //first check for diagonals
        for (int i=0; i<N; i++)
        {
            if (table[i][i] != mark) break;
            else if (i == N-1) { return (mark==GSplayers::player) ? GSoutcome::playerWin : GSoutcome::cpuWin; }
        }
        for (int i=0; i<N; i++)
        {
            if (table[N-i][i] != mark) break;
            else if (i == N-1) { return (mark==GSplayers::player) ? GSoutcome::playerWin : GSoutcome::cpuWin; }
        }

        //check for rows
        for (int r=0; r<N; r++){
            
            for (int c=0; c<N; c++){ //iterating over columns in a single row
                if (table[r][c] != mark) break;
                else if (c == N-1) { return (mark==GSplayers::player) ? GSoutcome::playerWin : GSoutcome::cpuWin; }
            }
        }

        //check for cols
        for (int c=0; c<N; c++){
            for (int r=0; r<N; r++){
                if (table[c][r] != mark) break;
                else if (r = N-1) {return (mark==GSplayers::player) ? GSoutcome::playerWin : GSoutcome::cpuWin; }
            }
        }
    }

    return GSoutcome::tie;
}

/*
    cout << table[0][0] << " | " << table[0][1] << " | " << table[0][2] << endl;
    cout << "---------" << endl;
    cout << table[1][0] << " | " << table[1][1] << " | " << table[1][2] << endl;
    cout << "---------" << endl;
    cout << table[2][0] << " | " << table[2][1] << " | " << table[2][2] << endl;
*/
