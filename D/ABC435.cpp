#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main(void) {
    int N, M, Q;

    cin >> N >> M; // N vertices, M edges

    vector<vector<int>> adjacencyList(N + 1);

    for (int i = 0; i < M; i ++) {
        int in, out;
        cin >> in >> out;
        adjacencyList[out].push_back(in); // 뒤집어서 edge 를 저장
    }

    vector<bool> visited(N + 1, false);
    vector<bool> isBlack(N + 1, false);

    vector<string> outputs;

    cin >> Q;

    for (int i = 0; i < Q; i ++) {
        char type;
        int v;
        cin >> type >> v;
        switch(type) {
            case '1' :
                isBlack[v] = true;
                if (!visited[v]) { // 방문 한 적이 없으므로 BFS 하면서 도달 가능한 노드 업데이트
                    queue<int> bfsQueue;
                    bfsQueue.push(v);
                    while (!bfsQueue.empty()) {
                        int currentNode = bfsQueue.front();
                        visited[currentNode] = true;
                        bfsQueue.pop();
                        for (int nextNode : adjacencyList[currentNode]) {
                            if (!visited[nextNode]) {
                                bfsQueue.push(nextNode);
                            }
                        }
                    }
                }
                break;
            case '2' : 
                outputs.push_back(visited[v] ? "Yes" : "No");
        }
    }

    for (auto output : outputs) {
        cout << output << endl;
    } 

    return 0;
}