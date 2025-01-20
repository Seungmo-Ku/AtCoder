#include <iostream>

using namespace std;

int operationNum(int, int, int, int);

int main(void) {

    int N, Q;

    cin >> N >> Q;

    char* H = new char[Q];
    int* T = new int[Q];

    for(int i = 0; i < Q; i++) {
        cin >> H[i] >> T[i];
    }

    int lPos = 1, rPos = 2;

    int sum = 0;

    for(int i = 0; i < Q; i ++) {
        if(H[i] == 'L') {
            sum += operationNum(lPos, T[i], rPos, N);
            lPos = T[i];
        }else { //H[i] == R
            sum += operationNum(rPos, T[i], lPos, N);
            rPos = T[i];
        }
    }

    cout << sum << endl;

    delete[] H;
    delete[] T;

    return 0;
}

int operationNum(int sPos, int dPos, int oPos, int N) {

    int operation = 0;
    if(sPos == dPos) {
        operation = 0;
    }else {
        if(sPos > dPos) swap(sPos, dPos);
        if(sPos < oPos && oPos < dPos) {
            operation = sPos + N - dPos;
        }else {
            operation = dPos - sPos;
        }
    }
    return operation;
}