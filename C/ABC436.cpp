#include <iostream>
#include <set>

using namespace std;

int main(void) {
    int N;
    int M;
    int result = 0;
    
    cin >> N >> M;

    set<pair<int, int>> grid;

    for (int i = 0; i < M; i ++) {
        int x, y;
        cin >> x >> y;

        pair<int, int> pos1 = { x, y };
        pair<int, int> pos2 = { x + 1, y };
        pair<int, int> pos3 = { x, y + 1 };
        pair<int, int> pos4 = { x + 1, y + 1 };

        if (grid.count(pos1) || grid.count(pos2) || grid.count(pos3) || grid.count(pos4)) continue;
            
        grid.insert(pos1);
        grid.insert(pos2);
        grid.insert(pos3);
        grid.insert(pos4);

        result ++;
    }

    cout << result << endl;
    return 0;
}