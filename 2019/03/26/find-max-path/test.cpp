#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> maxMoney(vector<vector<int>> moneys) {
		// assume: moneys is not null, width and length are equal
	int n = moneys.size();
	if (n == 0)
		return vector<vector<int>>();
	// base case
	for (int j = 1; j < n; j++) {
		moneys[0][j] = -(abs(moneys[0][j-1]) + moneys[0][j]);
	}

	for (int i = 1 ; i < n ; i++) {
		moneys[i][0] = moneys[i-1][0] + moneys[i][0];
	}
	for(int i = 1; i < n ; i++) {
		for(int j = 1; j < n ; j++) {
			int top = abs(moneys[i-1][j]) + moneys[i][j];
			int left = abs(moneys[i][j-1]) + moneys[i][j];
			if(top >= left) moneys[i][j] = top;
			else moneys[i][j] = -left;
		} 
	}
    printf("Max path sum= %d\n", moneys[n - 1][n - 1]);
    //System.out.println("Max path sum = " + Math.abs(moneys[n - 1][n - 1]));
    vector<vector<int>> path;
    //List<List<Integer>> path = new ArrayList<>();
    int curri = n-1;
	int currj = n-1;
	while (curri > 0 || currj > 0) {
		//path.add(Arrays.asList(curri, currj));
        path.push_back(vector<int>{curri, currj});
        if (moneys[curri][currj] < 0)
            currj -= 1;
		else 
            curri -= 1;
	}
	//path.add(Arrays.asList(0, 0));
    path.push_back(vector<int>{0, 0});
    return path;
}

int main(){
    vector<vector<int>> graph{
        {5, 10, 15},
        {15, 20, 25},
        {50, 10, 5}};

    vector<vector<int>> res = maxMoney(graph);
    printf("size= %lu\n", res.size());
    for (auto v : res)
        printf("%d, %d\n", v[0], v[1]);

    return 0;
}