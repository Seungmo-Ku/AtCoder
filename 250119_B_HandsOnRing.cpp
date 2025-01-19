#include <iostream>

using namespace std;

int main(void) {

    int N, Q;

    cin >> N >> Q;

    int numOfOperation = 0;

    char* H = new char[Q];
    int* T = new int[Q];

    for(int i = 0; i < Q; i++) {
        cin >> H[i] >> T[i];
    }

    int lPos = 1;
    int rPos = 2;

    for(int i = 0; i < Q; i ++) {
        
        if(H[i] == 'L') {
            if(lPos == T[i]) continue;
            bool goRight = true;
            for(int j = lPos + 1; j != T[i]; j ++) {
                if(j == N + 1) j -= N;
                if(j == rPos) {
                    goRight = false;
                    break;
                }
            }
            //cout << "goRight: " << goRight << endl;
            int count  = 0;
            if(goRight) {
                while(lPos != T[i]) {
                    lPos ++;
                    if(lPos == N + 1) lPos = 1;
                    count ++;
                }
            }else {
                while(lPos != T[i]) {
                    lPos --;
                    if(lPos == 0) lPos = N;
                    count ++;
            }
            
            }lPos = T[i];
            numOfOperation += count;
        }else { //R
            if(rPos == T[i]) continue;
            bool goRight = true;
            for(int j = rPos + 1; j != T[i]; j ++) {
                if(j == N + 1) j -= N;
                if(j == lPos) {
                    goRight = false;
                    break;
                }
            }
            int count  = 0;
            if(goRight) {
                while(rPos != T[i]) {
                    rPos ++;
                    if(rPos == N + 1) rPos = 1;
                    count ++;
                    //cout << "count: " << count << endl;
                }
            }else {
                while(rPos != T[i]) {
                    rPos --;
                    if(rPos == 0) rPos = N;
                    count ++;
            }
            
            }
            rPos = T[i];
            numOfOperation += count;
            
        }
    }//cout << "lPos: " << lPos << " rPos: " << rPos << endl;

    cout << numOfOperation << endl;


    delete[] H;
    delete[] T;
    return 0;
}