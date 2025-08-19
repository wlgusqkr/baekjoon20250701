#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> inputMap;
int N, C, iNum;
vector<pair<int, int>> vec;


void merge(pair<int, int> sorted[], auto& vec, int left, int mid, int right){
    int i = left;
    int j = mid + 1;
    int k = left;
    while(i <= mid && j <= right){
        if((vec[i]).second >= (vec[j]).second){
            sorted[k++] = vec[i++];
        }else{
            sorted[k++] = vec[j++];
        }
    }
    //왼쪽부분을 다 정렬시켜 채워넣었다면 오른쪽 부분만 넣으면 된다.
    if(i > mid){
        for(int l = j; l <= right; l++){
            sorted[k++] = vec[l];
        }
    }else{
    //오른쪽부분을 다 정렬시켜 채워넣었다면 왼쪽 부분을 넣으면 된다.
        for(int l = i; l <= mid; l++){
            sorted[k++] = vec[l];
        }
    }
    //마지막으로 이렇게 정렬 된 것을 기존 배열에 집어 넣는다.
    for(int l = left; l <= right; l++){
        vec[l] = sorted[l];
    }
}
void merge_sort(pair<int, int> sorted[], vector<pair<int, int>>& vec, int left, int right){
    int mid;
    if(left < right){
        mid = (left + right) / 2;
        merge_sort(sorted, vec, left, mid);
        merge_sort(sorted, vec, mid + 1, right);
        merge(sorted, vec, left, mid, right);
    }
}

int main() {
    cin >> N >> C;
    
    pair<int, int> sorted[N];
    
    for(int i = 0 ; i < N; i++) {
        bool bFlag = false;
        cin >> iNum;
        for(pair<int, int>& j : vec) {
            if(iNum == j.first) {
                bFlag = true;
                j.second = j.second + 1;
                break;
            }
        }
        if(bFlag == false) {
            vec.push_back(make_pair(iNum, 1));
        }
    }
    merge_sort(sorted, vec, 0, (int)vec.size() - 1);
 
    for(pair<int, int> i : sorted) {
        for(int j = 0 ; j < i.second; j++) {
            cout << i.first << " ";
        }
    }
    
}
