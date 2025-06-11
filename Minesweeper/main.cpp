#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Mine
{
    int x;
    int y;

    Mine(int x, int y) : x(x), y(y) {}
};


void printField(vector<Mine>& mines) {

}

vector<Mine> scanMines() {
    vector<Mine> mines;
    int n_mines, X, Y;
    cin >> X >> Y >> n_mines;
    mines.reserve(n_mines);
    for (int i = 0; i < n_mines; ++i) {
        int x, y;
        cin >> x >> y;
        mines.push_back(Mine(X, Y));
    }
    return mines;
} 

int main() {
    return 0;
}