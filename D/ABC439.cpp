#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    vector<int> A(N + 1);

    map<int, int> rightMap;
    map<int, int> leftMap;
    
    for (int i = 1; i <= N; i ++) {
        cin >> A[i];
        rightMap[A[i]] ++;
    }

    long long output = 0;
    
    for (int i = 1; i <= N; i ++) {
        rightMap[A[i]] --;

        if (A[i] % 5 == 0) {
            int multi = A[i] / 5;
            int multi3 = 3 * multi;
            int multi7 = 7 * multi;
            if (rightMap.count(multi3) && rightMap.count(multi7)) {
                output += rightMap[multi3] * rightMap[multi7];
            }
            if (leftMap.count(multi3) && leftMap.count(multi7)) {
                output += leftMap[multi3] * leftMap[multi7];
            }
        }

        leftMap[A[i]] ++; 
    }

    cout << output << endl;

    return 0;
}