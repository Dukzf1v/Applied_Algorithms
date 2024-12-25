#include <iostream>
#include <vector>
using namespace std;

bool can_place(vector<vector<int>> &grid, int H, int W, int h, int w, int x, int y){
    if(x + h > H || y + w > W){
        return false;
    }
    for(int i = x; i < x + h; i++){
        for(int j = y; j < y + w; j++){
            if(grid[i][j] == 1){
                return false;
            }
        }
    }
    return true;
}

void placed(vector<vector<int>> &grid, int h, int w, int x, int y, int value){
    for(int i = x; i < x + h; i++){
        for(int j = y; j < y + w; j++){
            grid[i][j] = value;
        }
    }
}

bool backtrack(vector<pair<int, int>> &rectangles, vector<vector<int>> &grid,int H, int W, int index){
    if(index == rectangles.size()){
        return true;
    }   
    int h = rectangles[index].first;
    int w = rectangles[index].second;
    for(int x = 0; x < H; x++){
        for(int y = 0; y < W; y++){
            if(can_place(grid, H, W, h, w, x, y)){
                placed(grid, h, w, x, y, 1);
                if(backtrack(rectangles,grid,H,W,index+1)){
                    return true;
                }
                placed(grid,h,w,x,y,0);
            }

            if(can_place(grid, H, W, w, h, x, y)){
                placed(grid, w, h, x, y, 1);
                if(backtrack(rectangles,grid,H,W,index+1)){
                    return true;
                }
                placed(grid,w,h,x,y,0);
            } 
        }
    }
    return false;
}

int result(int H,int W,vector<pair<int,int>>& rectangles){
    vector<vector<int>> grid(H, vector<int>(W,0));
    return backtrack(rectangles,grid,H,W,0) ? 1 : 0;
}

int main(){
    int H, W;
    cin >> H >> W;

    int n;
    cin >> n;
    vector<pair<int, int>> rectangles(n);
    for(int i = 0; i < n; i++){
        cin >> rectangles[i].first >> rectangles[i].second;
    }
    cout << result(H,W,rectangles);
    return 0;
}