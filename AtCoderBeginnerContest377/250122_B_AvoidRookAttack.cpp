#include <iostream>

using namespace std;

int main(void) {

    //int grid[8][8] = {0};
    bool rawGrid[8] = {0};
    bool colGrid[8] = {0};

    for(int i = 0; i < 8; i ++) {
        string S;
        cin >> S;
        for(int j = 0; j < 8; j ++) {
            if(S[j] == '#') {
                rawGrid[i] = 1;
                colGrid[j] = 1;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < 8; i ++) {
        if(rawGrid[i] == 1) continue;
        
        for(int j = 0; j < 8; j ++) {
            if(colGrid[j] == 1) continue;
            sum ++;
        }
    }
    
    cout << sum << endl;

    return 0;
}