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
#include <set>
#include <algorithm>
#define MAX 501
#define INF 987654321
#define NOT_ROAD -1
using namespace std;

int point[MAX][MAX];
int d[MAX];
int fastest;
int secondFastest;
int pointMax;

struct fastestRoadInfo{
    int distance;
    int *route;
};

void setDistance(int curPoint, int pointAmt, int* distance, int *route) {
    for(int i =0; i<pointAmt; i++) {
        if (point[curPoint][i] != INF &&
            distance[curPoint] + point[curPoint][i] < distance[i]) {
            distance[i] = distance[curPoint] + point[curPoint][i];
            route[i] = curPoint;
        }
    }
}

int getNextPoint(set<int> notVisited, int distance[], int pointAmt) {
    set<int>::iterator it;
    int fDist=INF;
    int fPoint = -1;
    for(it=notVisited.begin(); it != notVisited.end(); it++) {
        if(distance[(*it)] < fDist){
            fDist = distance[(*it)];
            fPoint = (*it);
        }
    }
    return fPoint;
}

fastestRoadInfo findFastestPathDijkstra(int startPoint, int endPoint, int pointAmt) {
    set<int> notVisited;
    vector<int>::iterator it;
    int distance[pointAmt];
    int *route = new int[pointAmt];
    int nextPoint;
    for(int i = 0; i < pointAmt; i++){
        distance[i] = INF;
    }
    
    for(int i =0; i<pointAmt; i++) {
        notVisited.insert(i);
    }
    
    notVisited.erase(startPoint);
    distance[startPoint] = 0;
    setDistance(startPoint, pointAmt, distance, route);
    int curPoint = startPoint;
    while(notVisited.size() > 0) {
        nextPoint = getNextPoint(notVisited, distance, pointAmt);
        curPoint = nextPoint;
        notVisited.erase(nextPoint);
        setDistance(nextPoint, pointAmt, distance, route);
        
        if (curPoint == endPoint) {
            fastestRoadInfo myFastest;
            myFastest.distance = distance[endPoint];
            myFastest.route = route;
            return myFastest;
        }
    }
    fastestRoadInfo noFastest;
    noFastest.distance = -1;
    return noFastest;
}

void removeFastestRoute(int startPoint, int endPoint, int *route){
    int cur = endPoint;
    int prev;
    while(true) {
        cout<<cur<<" ";
        prev = route[cur];
        point[prev][cur] = INF;
        if(prev == startPoint)
            break;
        cur = prev;
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    int pointAmt, roadAmt, sp, ep, srcp, dstp, dist;
    while(true) {
        cin>>pointAmt>>roadAmt;
        if (pointAmt + roadAmt == 0)
            break;
        for(int i = 0; i < pointAmt; i++){
            for(int j = 0; j<pointAmt; j++) {
                point[i][j] =INF;
            }
        }
        cin>>sp>>ep;
        for(int i = 0; i < roadAmt; i++) {
            cin>>srcp>>dstp>>dist;
            point[srcp][dstp] = dist;
        }
        fastestRoadInfo fastest = findFastestPathDijkstra(sp, ep, pointAmt);
        cout<<fastest.distance<<endl;
        
        if(fastest.distance == -1) {
            cout<<-1<<endl;
            continue;
        }
        
        
        removeFastestRoute(sp, ep, fastest.route);
        fastestRoadInfo second = findFastestPathDijkstra(sp, ep, pointAmt);
        cout<<second.distance<<endl;
    }
    return 0;
}
