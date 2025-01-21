#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {

    int N;

    cin >> N;

    int* A = new int[N];
    int* B = new int[N - 1];

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + N - 1);

    int sizeOfBox = -1;
    int index = -1;

    for(int i = N - 1; i > 0; i --) {
        if(A[i] > B[i - 1]) {
            sizeOfBox = A[i];
            index = i;
            //cout << "i: " << i << "size : " << sizeOfBox << endl;
            for(int j = 0; j < i; j ++) {
                if(A[j] > B[j]) {
                    sizeOfBox = -1;
                    break;
                }
            }
        }
        if(index != -1) break;
    }
    if(index == -1) {
        sizeOfBox = A[0];
        index = 0;
    }
/*
    if(A[N - 1] > B[N - 2]) {
        sizeOfBox = A[N - 1];
        for(int i = 0; i < N - 1; i ++) {
            if(A[i] > B[i]) {
                sizeOfBox = -1;
                break;
            }
        }
    }
*/
    cout << sizeOfBox << endl;

    delete[] A;
    delete[] B;

    return 0;
}