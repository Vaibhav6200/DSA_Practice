#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

#include<algorithm>

class Solution
{
    public:
/*
    we will be including those iterms in bag whose P/W ration is maximum
*/

    static bool compare(pair<int, double> &x, pair<int, double> &y){
        return (x.second > y.second);
    }


    double fractionalKnapsack(int total_wt, Item arr[], int n)
    {
        // Step1: Create P/W ratio array
        vector<pair<int, double>> ratio;    // {item, ratio}
        for(int i=0; i<n; i++){
            int profit = arr[i].value;
            int weight = arr[i].weight;

            double x = (double)profit / (double)weight;
            ratio.push_back({i, x});
        }

        sort(ratio.begin(), ratio.end(), compare);

        // for(int i=0; i<n; i++)
        //     cout << ratio[i].first << " " << ratio[i].second << endl;

        double result = 0;
        for(int i=0; i<n; i++)
        {
            // select maximum ratio
            auto p = ratio[i];
            int item = p.first;
            double weight = arr[item].weight;
            double profit = arr[item].value;

            // cout << item << " : " << weight << " : " << profit << endl;

            // Now include that item in your bag
            if(total_wt >= weight){
                total_wt -= weight;
                result += profit;
            }
            else{
                result += profit * (total_wt/weight);
                break;
            }
        }

        return result;
    }
};


int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;

		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}

		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}