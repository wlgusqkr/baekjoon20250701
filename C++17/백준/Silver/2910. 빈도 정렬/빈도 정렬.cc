#include <iostream>
#include <algorithm>

using namespace std;

// 숫자 N개로 이루어진 수열
// 모두 C보다 작거나 같다.
// X가 Y보다 많이 등장하면 앞에
// 등장 횟수가 같다면 먼저 나온 것이 앞에
// 빈도가 많은게 제일 앞에 나오게
// 빈도랑 먼저 나온 순서를 기억해야 한다.
// 앞에서부터 읽어서는 알 수 없음.

// 하나씩 읽으면서 정렬 하는 거는 말이 안된다.
// 순회를 해서 기억해놓고 정렬 하는게 맞는 것 같다.
// 순서대로 넣어놓고
// 크기순으로 정렬 하면 끝이네

// 벡터에 맵을 넣어야하나
// 벡터에 맵을 넣는다면 순서는 보장되어 있고
// 크기 봐서 sort알고리즘쓰면 되겠네

// 하나씩 넣을 때
// 지금까지 앞에 있었던 숫자 인지 알려면 for문으로 반복해야함.


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
