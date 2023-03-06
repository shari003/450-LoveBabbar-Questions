#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> visited, vector<vector<int>> m, int n){
    if(x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1){
        return 1;
    }
    return 0;
}

void solve(vector<vector<int>> m, int n, string str, int srcx, int srcy, vector<vector<int>> visited){
    if(srcx == n-1 && srcy == n-1){
        cout << str << endl;
        return;
    }

    visited[srcx][srcy] = 1;

    // DOWN
    int newx = srcx+1;
    int newy = srcy;
    if(isSafe(newx, newy, visited, m, n)){
        str.push_back('D');
        solve(m, n, str, newx, newy, visited);
        str.pop_back();
    }

    // UP
    newx = srcx-1;
    newy = srcy;
    if(isSafe(newx, newy, visited, m, n)){
        str.push_back('U');
        solve(m, n, str, newx, newy, visited);
        str.pop_back();
    }

    // RIGHT
    newx = srcx;
    newy = srcy+1;
    if(isSafe(newx, newy, visited, m, n)){
        str.push_back('R');
        solve(m, n, str, newx, newy, visited);
        str.pop_back();
    }

    // LEFT
    newx = srcx;
    newy = srcy-1;
    if(isSafe(newx, newy, visited, m, n)){
        str.push_back('L');
        solve(m, n, str, newx, newy, visited);
        str.pop_back();
    }

    visited[srcx][srcy] = 0;
}

void ratInMaze(vector<vector<int>> m){
    if(m[0][0] == 0) return;
    string op = "";
    int n = 4;
    vector<vector<int>> visited = m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
    int srcx = 0, srcy = 0;
    solve(m, n, op, srcx, srcy, visited);
}

int main(){
    vector<vector<int>> m = {{1, 0, 0, 0},{1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    ratInMaze(m);
    return 0;
}