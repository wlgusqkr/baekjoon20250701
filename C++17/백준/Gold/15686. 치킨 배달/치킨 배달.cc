#include <bits/stdc++.h>
#define _GLIBCXX_HOSTED 1

using namespace std;


int N, M;
int arr[52][52];
int chicken_house_count, house_count;
int minDistance = 5555;

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

vector<int> d;

void combi(int start, vector<int> &b){
    
    if(b.size() == M){

        int distanceSum = 0;

        for(int i = 0; i < house_count; i++) {
        
            int first = house[i].first;
            int second = house[i].second;
            
            int tmpMin = 5555;
            for(int j = 0 ; j < b.size(); j++) {
                int y_distance = abs(first - chicken[b[j]].first);
                int x_distance = abs(second - chicken[b[j]].second);
                tmpMin = min(y_distance + x_distance, tmpMin);
            }
            
            distanceSum += tmpMin;
            
            
        }
        
        d.push_back(distanceSum);
        
        for(int i = 0 ; i < M; i++) {
            arr[chicken[b[i]].first][chicken[b[i]].second] = 0;
        }
        
        
        return;
    }
    for(int i = start + 1; i < chicken_house_count; i++){
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}


int main(){
    cin >> N >> M;
    vector<int> b;
    
    for(int i = 0 ; i < N; i++) {
        for(int j = 0 ; j < N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                house.push_back(make_pair(i, j));
                house_count++;
            }
            if(arr[i][j] == 2) {
                arr[i][j] = 0;
                chicken.push_back(make_pair(i, j));
                chicken_house_count++;
            }
        }
    }

    combi(-1, b);
    sort(d.begin(), d.end());
    
    cout << d[0];
}
    
