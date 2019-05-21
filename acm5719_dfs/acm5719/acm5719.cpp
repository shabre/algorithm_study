//
//  main.cpp
//  acm5719
//
//  Created by Shabre on 2018. 10. 9..
//  Copyright © 2018년 Shabre. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <list>
#include <vector>
#include <algorithm>
#define MAX 501
#define INF 987654321
#define NOT_ROAD -1
using namespace std;
int point[MAX][MAX];
int fastest;
int secondFastest;
int pointMax;

// dfs 로 모든 경로 저장해서 정렬 후 거쳐가는 로드 체크해서 2번째 빠른 길 찾는방식
// 시간 초과 남
// 내일 bfs로 재구현

struct RoadDist{
    int distance;
    vector<int> way;
    bool operator < (const RoadDist& roadDist) const {
        return distance < roadDist.distance;
    }
};

bool rankdRoadDist(const RoadDist &lv, const RoadDist &rv){
    return lv.distance < rv.distance;
}

vector<RoadDist> roadDistVec;

void treeSearch(int curPoint, int dstPoint, int acc, vector<int>& wayList, bool visited[][MAX]) {
    if(acc > secondFastest)
        return;
    wayList.push_back(curPoint);
    if(dstPoint==curPoint) {
        RoadDist roadDist;
        roadDist.distance = acc;
        roadDist.way = wayList;
        roadDistVec.push_back(roadDist);
    }
    for(int i =0; i < pointMax; i ++) {
        if(!visited[curPoint][i] && point[curPoint][i] != NOT_ROAD) {
            visited[curPoint][i] = true;
            treeSearch(i, dstPoint, acc + point[curPoint][i], wayList, visited);
            visited[curPoint][i] = false;
        }
    }
    wayList.pop_back();
    return;
}

void insertRoute(bool visited[][MAX], vector<int> route) {
    for(vector<int>::iterator lit = route.begin(); lit != route.end(); lit++) {
        if(lit+1 != route.end()) {
            visited[*lit][(*(lit+1))] = true;
        }
    }
}

bool isNoDupRoute(bool visited[][MAX], vector<int> route){
    for(vector<int>::iterator lit = route.begin(); lit != route.end(); lit++) {
        if(lit+1 != route.end()) {
            if(visited[*lit][(*(lit+1))] == true) {
                return false;
            }
        }
    }
    return true;
}

int secondFastestRoad(int start, int end){
    fastest = INF;
    secondFastest = INF;
    bool visited[MAX][MAX];
    memset(visited, 0, MAX * MAX * sizeof(bool));
    vector<int> wayList;
    treeSearch(start, end, 0, wayList, visited);
    memset(visited, 0, MAX * MAX * sizeof(bool));
    
    
    sort(roadDistVec.begin(), roadDistVec.end(), rankdRoadDist);
    
    int fastest=-1;
    for(vector<RoadDist>::iterator it = roadDistVec.begin(); it != roadDistVec.end(); it++) {
        if(fastest == -1){
            fastest = (*it).distance;
            insertRoute(visited, (*it).way);
        }
        if (fastest == (*it).distance){
            insertRoute(visited, (*it).way);
        }
        if(isNoDupRoute(visited, (*it).way))
            return (*it).distance;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int pointAmt, roadAmt, sp, ep, srcp, dstp, dist;
    while(true) {
        memset(point, NOT_ROAD, MAX * MAX * sizeof(int));
        roadDistVec.clear();
        cin>>pointAmt>>roadAmt;
        if (pointAmt + roadAmt == 0)
            break;
        cin>>sp>>ep;
        for(int i = 0; i < roadAmt; i++) {
            cin>>srcp>>dstp>>dist;
            point[srcp][dstp] = dist;
        }
        pointMax = pointAmt;
        cout<<secondFastestRoad(sp, ep)<<endl;
    }
    return 0;
}
