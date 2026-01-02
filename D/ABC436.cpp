#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> maze(H, vector<char>(W));
    vector<vector<int>> count(H, vector<int>(W, -1));
    queue<pair<int, int>> search;
    vector<pair<int, int>> portals[26];

    bool visited_alphabet[26] = { false, };

    for (int i = 0; i < H; i ++) {
        string col;
        cin >> col;
        for (int j = 0; j < W; j ++) {
            maze[i][j] = col[j];
            if (col[j] >= 'a' && col[j] <= 'z') {
                portals[col[j] - 'a'].push_back({ i, j });
            }
        }
    }

    if (maze[H - 1][W - 1] == '#') {
        cout << -1 << endl;
        return 0;
    }

    search.push({ H - 1, W - 1});
    count[H - 1][W - 1] = 0;

    while(!search.empty()) {
        pair<int, int> coordinate = search.front();
        search.pop();

        int x = coordinate.first;
        int y = coordinate.second;

        int nextCount = count[x][y] + 1;

        // portal 처리 
        if (maze[x][y] >= 'a' && maze[x][y] <= 'z' && !visited_alphabet[maze[x][y] - 'a']) {
            visited_alphabet[maze[x][y] - 'a'] = true;
            for (auto p : portals[maze[x][y] - 'a']) {
                if (p.first == x && p.second == y) continue;
                int newX = p.first;
                int newY = p.second;
                if (count[newX][newY] > -1) continue;
                count[newX][newY] = nextCount;
                search.push({ newX, newY });
            }
        }

        if (x + 1 < H) {
            if (count[x + 1][y] == -1 && maze[x + 1][y] != '#') {
                count[x + 1][y] = nextCount;
                search.push({ x + 1, y });
            }
        }
        if (x - 1 >= 0) {
            if (count[x - 1][y] == -1 && maze[x - 1][y] != '#') {
                count[x - 1][y] = nextCount;
                search.push({ x - 1, y });
            }
        }
        if (y + 1 < W) {
            if (count[x][y + 1] == -1 && maze[x][y + 1] != '#') {
                count[x][y + 1] = nextCount;
                search.push({ x, y + 1 });
            }
        }
        if (y - 1 >= 0) {
            if (count[x][y - 1] == -1 && maze[x][y - 1] != '#') {
                count[x][y - 1] = nextCount;
                search.push({ x, y - 1 }); 
            }
        }
    }

    cout << count[0][0] << endl;

    return 0;
}