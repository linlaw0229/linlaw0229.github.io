#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>

using namespace std;

class BikeMatching{
public:
    BikeMatching(vector<vector<char>>& graph);
    //void init();
    void matching();

    vector<vector<int>> people;
    vector<vector<int>> bikes;
    vector<pair<int, int>> res;
    priority_queue<pair<int, pair<int, int>>> pq;
    unordered_set<int> visited_man, visited_bike;
};

BikeMatching::BikeMatching(vector<vector<char>>& graph){
    if(graph.empty())
        return;

    for (int i = 0; i < graph.size(); i++){
        for (int j = 0; j < graph[0].size(); j++){
            if(graph[i][j] == 'O') continue;
            else if(graph[i][j] == 'P')
                people.push_back(vector<int>{i, j});
            else if(graph[i][j] == 'B')
                bikes.push_back(vector<int>{i, j});
            else
                printf("incorrect input\n");
        }
    }

    for (int i = 0; i < people.size(); i++){
        for (int j = 0; j < bikes.size(); j++){
            int dis = abs(people[i][0]- bikes[j][0]) + abs(people[i][1] - bikes[j][1]);
            pq.push(make_pair(-dis, make_pair(i, j)));
        }
    }
}

void BikeMatching::matching()
{
    while(visited_man.size() != people.size()){
        auto tmp = pq.top(); pq.pop();
        if(visited_man.count(tmp.second.first) || visited_bike.count(tmp.second.second))
            continue;

        visited_man.insert(tmp.second.first);
        visited_bike.insert(tmp.second.second);
        res.push_back(tmp.second);
    }

    for(auto r: res){
        printf("people at (%d, %d), pairs with (%d, %d)\n", people[r.first][0], people[r.first][1], bikes[r.second][0], bikes[r.second][1]);
    }
}

int main()
{
    vector<vector<char>> graph{
        {'O', 'P', 'O', 'B', 'P', 'O', 'P'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'B', 'O', 'O', 'B', 'O', 'O', 'B'}};

    BikeMatching ins(graph);
    ins.matching();
    return 0;
}