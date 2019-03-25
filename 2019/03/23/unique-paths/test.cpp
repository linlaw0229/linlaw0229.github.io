#include <bits/stdc++.h>
using namespace std;

int findPossiblePaths(vector<vector<int> >& grid){
    //given an array, find the number of paths that can go from top-right to top-left
    //direction can only be top-left, left, bottom-left

    /*{
        {1, 1, 2, 4, 9},
        {0, 1, 2, 5, 12},
        {0, 0, 1, 3, 9},
        {0, 0, 0, 1, 4},
        {0, 0, 0, 0, 1}
    };*/

    int row = grid.size(), col = grid[0].size();
    vector<int> dp(row, 0);
    dp[0] = 1;
    vector<int> tmp(row, 0);
    //tmp[i] = dp[i-1]+ dp[i]+ dp[i+1]

    for (int j = 1; j < col; j++){
        for (int i = 0; i< row; i++){
            int val1 = i - 1 >= 0 ? dp[i - 1] : 0;
            int val2 = dp[i];
            int val3 = i + 1 < row ? dp[i + 1] : 0;
            tmp[i] = val1 + val2 + val3;
        }
        dp.swap(tmp);
    }
    return dp[0];
}

bool VerifyToPoints(vector<vector<int> >& points){
    vector<vector<int>> list;
    list.push_back(vector<int>{0, 0});
    for(auto point: points)
        list.push_back(point);
    sort(list.begin(), list.end(), [](vector<int> a, vector<int> b) { return a[1] < b[1]; });
    for(auto point:list){
        printf("%d, %d\n", point[0], point[1]);
    }

    for (int i = 1; i < list.size(); i++){
        vector<int> cur= list[i];
        vector<int> pre= list[i-1];
        if(cur[1] == pre[1])
            return false;
        int len = cur[1] - pre[1];
        int upper = pre[0] - len;
        int lower = pre[0] + len;
        if(cur[0]<= lower && cur[0] >= upper)
            continue;
        else
            return false;
    }
    
    return true;
}

int main(){

    vector<vector<int> > grid(5, vector<int>(5, 0));
    
    /*{
        {1, 1, 2, 4, 9},
        {0, 1, 2, 5, 12},
        {0, 0, 1, 3, 9},
        {0, 0, 0, 1, 4},
        {0, 0, 0, 0, 1}
    };*/
    printf("findPossiblePaths from top-left to top-right= %d\n", findPossiblePaths(grid));

    vector<vector<int> > points;
    points.push_back(vector<int>{1, 3}); points.push_back(vector<int>{0, 1}); points.push_back(vector<int>{3, 5});
    /*
        {*, *, 0, 0, 0, 0},
        {0, 0, 0, *, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, *},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    */
    if(VerifyToPoints(points))
        printf("can reach\n");
    else
        printf("can not reach\n");
    

    return 0;
}