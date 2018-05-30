#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
const int w = 3, h = 10;
int graph[w][h];
int ans = 0;

map<int, int> Hash;

//检查2x2格子颜色是否相同
bool check_color() {
    for(int i = 0; i < w; i++) 
    for(int j = 0; j < h; j++) {
        if(i+1 < w && j+1 < h) {
            if((graph[i][j]+graph[i][j+1]+graph[i+1][j]+graph[i+1][j+1]) % 4 == 0) 
                return false;
        }
    }
    return true;
}

void fill_with_tile(int x, int y) {
    if(graph[x][y] == -1) {
        //横向摆放
        if(y+1 < h && graph[x][y+1] == -1) {

            for(int i = 0; i < 2; i++) {
                graph[x][y] = graph[x][y+1] = i;
                if(y == h-1) {  //铺下一行
                    fill_with_tile(x+1, 0);
                } else {        //铺当前行的下一个格子
                    fill_with_tile(x, y+1);
                }
                graph[x][y] = graph[x][y+1] = -1;
            }

        }
        //纵向摆放
        if(x+1 < w && graph[x+1][y] == -1) {
            for(int i = 0; i < 2; i++) {
                graph[x][y] = graph[x+1][y] = i;
                if(y == h-1) {  //铺下一行
                    fill_with_tile(x+1, 0);
                } else {        //铺当前行的下一个格子
                    fill_with_tile(x, y+1);
                }
                graph[x][y] = graph[x+1][y] = -1;
            }
        }
    } else {
        if(x == w-1 && y == h-1) { //成功铺满
            if(check_color()) {
                //判断是否出现重复情况
                int ret = 0, bit = 1;
                for(int i = 0; i < w; i++)
                for(int j = 0; j < h; j++) {
                    ret += graph[i][j] * bit;
                    bit *= 2;
                }
                if(!Hash.count(ret)) {
                    Hash[ret] = 1;
                    ans++;
                }
            }
            return;
        }
        if(y == h-1) {          //铺下一行
            fill_with_tile(x+1, 0);
        } else {                //铺当前行的下一个格子
            fill_with_tile(x, y+1);
        }
    }
}

int main() {
    memset(graph, -1, sizeof(graph));
    fill_with_tile(0, 0);
    printf("%d\n", ans);
    return 0;
}