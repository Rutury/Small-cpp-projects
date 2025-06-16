#include <iostream>
#include <string>
#include <vector>

using namespace std;
using Field = vector<vector<int>>;

struct Mine
{
    int x;
    int y;

    Mine(int x, int y) : x(x), y(y) {}
};


Field makeField(int height, int width, vector<Mine>& mines) {
    Field field(height + 2, vector<int>(width + 2, 0));
    for (const auto& mine : mines) {
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                field[mine.x + dx][mine.y + dy]++;
            }
        }
    }
    for (const auto& mine : mines) {
        field[mine.x][mine.y] = -1;
    }
    return field;
}

void printField(const Field& field) {
    for (unsigned x = 1; x + 1 < field.size(); ++x) {
        for (unsigned y = 1; y + 1 < field[x].size(); ++y) {
            if (field[x][y] == -1) {
                cout << "*";
            } else {
                cout << field[x][y];
            }
            if (y + 2 != field[x].size()){
                cout << " ";
            }
        }
        cout << endl;
    }
}

vector<Mine> scanMines() {
    vector<Mine> mines;
    int n_mines;
    cin >> n_mines;
    mines.reserve(n_mines);
    for (int i = 0; i < n_mines; ++i) {
        int x, y;
        cin >> x >> y;
        mines.push_back(Mine(x, y));
    }
    return mines;
} 

int main() {
    int height, width;
    cin >> height >> width;
    vector<Mine> mines = scanMines();
    Field field = makeField(height, width, mines);
    printField(field);
    return 0;
}