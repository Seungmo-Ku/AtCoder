#include <iostream>
#include <queue>

using namespace std;

int main(void) {

    int N, M; //N: number of vertices, M: number of edges

    cin >> N >> M;

    int** edges = new int*[N + 1];
    
    for(int i = 1; i <= N; i++) {
        edges[i] = new int[N + 1];
        for(int j = 1; j <= N; j++) {
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges[a][b] = 1;   
        //if(i == 0) vertex1 = b, destination = a; 
    }//cout << "vertex1: " << vertex1 << " destination: " << destination << endl;
    
    //vertex 1의 도착지에서 BFS를 실행 후에 vertex 1에 도달하면 cycle이 존재
    int minimumEdges = M + 1;
    queue<int> bfsQueue;
    bfsQueue.push(1);

    int* discoverTime = new int[N + 1];
    for(int i = 1; i <= N; i ++) {
        discoverTime[i] = -1;
    }
    discoverTime[1] = 0;

    while(!bfsQueue.empty()) {
        int vertex = bfsQueue.front();
        bfsQueue.pop();
        for(int i = 1; i <= N; i ++) {
            if(edges[vertex][i] == 1) {
                if(i == 1) {
                    if(vertex == 1) {
                        minimumEdges = 1;
                        break;
                    }
                    if(minimumEdges > discoverTime[vertex] + 1) minimumEdges = discoverTime[vertex] + 1;
                    discoverTime[i] = discoverTime[vertex] + 1;
                    break;
                }else {
                    if(discoverTime[i] != -1) continue;
                    discoverTime[i] = discoverTime[vertex] + 1;
                    bfsQueue.push(i);
                }
            }
        }
    }
    
    if(minimumEdges == M+1) minimumEdges = -1;
    
    cout << minimumEdges << endl;

    for(int i = 0; i < N; i ++)
        delete[] edges[i];
    delete[] edges;
    delete[] discoverTime;

    return 0;
}