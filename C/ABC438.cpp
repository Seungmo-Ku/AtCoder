#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> A(N + 1);

    for (int i = 1; i <= N; i ++) {
        cin >> A[i];
    }

    int stackSize = 0;
    vector<int> stack;

    for (int i = 1; i <= N; i ++) {
        stack.push_back(A[i]);
        stackSize ++;
        if (stackSize >= 4) {
            if (stack[stackSize - 2] == A[i] && stack[stackSize - 3] == A[i] && stack[stackSize - 4] == A[i]) {
                for (int j = 0; j < 4; j ++) stack.pop_back();
                stackSize -= 4;
            }
        }
    }

    cout << stackSize << endl;

    return 0;
}