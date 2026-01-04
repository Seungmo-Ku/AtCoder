#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calculateGradient(int h1, int h2, int t1, int t2) {
    return (h2 - h1) / (t2 - t1);
}

int main(void) {
    /*
    N 개의 challenge 가 시간 순서대로 있으므로, 각 구간 별로 최대 기울기, 최소 기울기를
    정해 놓고 최대 높이, 최소 높이 안에 목표 구간이 들어가면 됨.
    목표 구간이 들어간다면, 다음 구간을 볼 때 구간 최상단에서 갈 수 있는 최대 높이,
    구간 최하단에서 갈 수 있는 최소 높이를 구해서 다시 범위를 구하고, 그 범위가 안에 있으면 됨.
    */
    int T;
    cin >> T;
    vector<string> outputs;

    for (int c = 0; c < T; c ++) {
        int N, H; // N : 테스트의 수, H : 처음 높이
        cin >> N >> H;

        vector<int> time(N + 1), low(N + 1), high(N + 1), min(N + 1), max(N + 1);

        for (int i = 1; i <= N; i ++) {
            int t, l, h;
            cin >> t >> l >> h;
            time[i] = t;
            low[i] = l;
            high[i] = h;
        }

        bool isAchievable = true;
        for (int i = 1; i <= N; i ++) {
            int maxHeight, minHeight;
            if (i == 1) { // 시작 높이 정해져있음
                maxHeight = H + time[i];
                minHeight = H - time[i];
            } else { // 시작 높이가 범위로 나옴.
                maxHeight = max[i - 1] + time[i] - time[i - 1];
                minHeight = min[i - 1] - (time[i] - time[i - 1]);
            }
            if (low[i] > maxHeight || high[i] < minHeight) {
                isAchievable = false;
                break;
            }
            min[i] = minHeight < low[i] ? low[i] : minHeight;
            max[i] = maxHeight > high[i] ? high[i] : maxHeight;
        }
        outputs.push_back(isAchievable ? "Yes" : "No");
    }

    for(string output : outputs) {
        cout << output << endl;
    }
    return 0;
}