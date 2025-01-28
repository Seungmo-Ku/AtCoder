#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Point {
    int x, y;
    bool operator==(const Point &p) const {
        return x == p.x && y == p.y;
    }
    bool operator<(const Point &p) const {
        if(x == p.x) return y < p.y;
        else return x < p.x;
        //return x < p.x || (x == p.x && y < p.y);
    }
};

bool checkValidSquare(int, int, int, vector<Point>);


int main(void) {

    int N, M;

    cin >> N >> M;

    vector<Point> points;

    for(int i = 0; i < M; i ++) {
        Point coord;
        cin >> coord.x >> coord.y;
        coord.x --;
        coord.y --;
        if(checkValidSquare(coord.x, coord.y, N, points))points.push_back(coord);
        //(x, y+1), (x, y-3), (x+1, y), (x+1, y-2), (x-2, y+1), (x-2, y-3), (x-3, y), (x-3, y-2)
        //coord.x ++; coord.y ++;
        if(checkValidSquare(coord.x + 1, coord.y + 2, N, points)) {
            Point coord2 = {coord.x + 1, coord.y + 2};
            points.push_back(coord2);
        }if(checkValidSquare(coord.x + 2, coord.y + 1, N, points)) {
            Point coord2 = {coord.x + 2, coord.y + 1};
            points.push_back(coord2);
        }if(checkValidSquare(coord.x + 2, coord.y - 1, N, points)) {
            Point coord2 = {coord.x + 2, coord.y - 1};
            points.push_back(coord2);
        }if(checkValidSquare(coord.x + 1, coord.y - 2, N, points)) {
            Point coord2 = {coord.x + 1, coord.y - 2};
            points.push_back(coord2);
        }if(checkValidSquare(coord.x - 1, coord.y - 2, N, points)) {
            Point coord2 = {coord.x - 1, coord.y - 2};
            points.push_back(coord2);
        }if(checkValidSquare(coord.x - 2, coord.y - 1, N, points)) {
            Point coord2 = {coord.x - 2, coord.y - 1};
            points.push_back(coord2);
        }if(checkValidSquare(coord.x - 2, coord.y + 1, N, points)) {
            Point coord2 = {coord.x - 2, coord.y + 1};
            points.push_back(coord2);
        }if(checkValidSquare(coord.x - 1, coord.y + 2, N, points)) {
            Point coord2 = {coord.x - 1, coord.y + 2};
            points.push_back(coord2);
        }
        
    }

    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    cout << (long)N*N - points.size() << endl;
    
   

    return 0;
}

bool checkValidSquare(int x, int y, int N, vector<Point> points) {
    //Point coord = {x, y};
    //auto it = find(points.begin(), points.end(), coord);
    //if(it != points.end()) return false;

    return x >= 0 && x < N && y >= 0 && y < N;
}