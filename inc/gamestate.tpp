
template <int N>
bool GameState<N>::is_placable(int row, int col)
{
    if (table[row][col] != ' ') return false;
    return true;
}

template <int N>
void GameState<N>::place_mark(bool turn, int row, int col)
{
    char player_mark = 'X';
    char cpu_mark = 'O';
    if (is_placable(row, col))
    {
        table[row][col] = turn?player_mark:cpu_mark;
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
        if (row != N-1) cout << "---------" << endl;
    }

    cout << "__________________________________" << endl;
}

/*
    cout << table[0][0] << " | " << table[0][1] << " | " << table[0][2] << endl;
    cout << "---------" << endl;
    cout << table[1][0] << " | " << table[1][1] << " | " << table[1][2] << endl;
    cout << "---------" << endl;
    cout << table[2][0] << " | " << table[2][1] << " | " << table[2][2] << endl;
*/
