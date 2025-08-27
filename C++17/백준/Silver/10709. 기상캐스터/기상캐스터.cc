#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <map>

using namespace std;

int H, W;
int main() {
    
    cin >> H >> W;
    int arr[H][W];
    fill(&arr[0][0], &arr[0][0] + W*H, 0);

    for(int i = 0 ; i < H; i++) {
        for(int j = 0 ; j < W; j++) {
            char cha;
            scanf(" %c", &cha);
            if(cha == 'c') {
                arr[i][j] = 0;
            } else {
                arr[i][j] = -1;
            }
        }
    }
    
    for(int i = 0 ; i < H; i++) {
        for(int j = 1; j < W; j++) {
            if(arr[i][j] == -1 && arr[i][j - 1] != -1) {
                arr[i][j] = arr[i][j - 1] + 1;
            }
        }
    }
    
    for(int i = 0 ; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    
}
