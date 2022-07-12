#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
	void shortest_distance(vector<vector<int>>&dist){
	    int n = dist.size();

        // this loop is to include all vertices
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                {
                    if(dist[i][k] == -1 || dist[k][j] == -1)
                        continue;

                    if(dist[i][j] == -1)
                        dist[i][j] = dist[i][k] + dist[k][j];

                    else if(dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}