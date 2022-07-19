/*
    *** APPROACH ***
1. calculate net amount of each person
    netAmount = (sum of all credits) - (sum of all debits)

2. Now we have to Find 2 person
    (i) Having highest credit   (mxCredit)
    (ii) Having Highest Debit   (mxDebit)

3. Now Find minimum of the amounts of both the persons (take absolute values)
    minAmount = min(amount[mxCredit], amount[mxDebit]);

4. Now Pay minAmount from maxDebitor to maxCreditor and update their amounts like this:
    amount[mxDebit] += minAmount        // NOTE: debitor's account was in -ve numbers and if he has payed minAmount to a creditor then relax its account balance
    amount[mxCredit] -= minAmount       // Creditor got some money so now he require less money as compared to earlier
*/

#include<bits/stdc++.h>
using namespace std;


int getMax(int arr[], int n){
    int maxi = INT_MIN;
    int idx = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
            idx = i;
        }
    }
    return idx;
}

int getMin(int arr[], int n){
    int mini = INT_MAX;
    int idx = 0;
    for(int i=0; i<n; i++){
        if(arr[i] < mini){
            mini = arr[i];
            idx = i;
        }
    }
    return idx;
}


void minCashFlow(int amount[], int n){
    // find max Creditor and max Debitor
    int mxCredit = getMax(amount, n);
    int mxDebit = getMin(amount, n);

    // x and y holds the absolute value of max credit and max debit
    int x = abs(amount[mxCredit]);
    int y = abs(amount[mxDebit]);

    // BASE CONDITION
    if(x==0 && y==0)        // means all cash flow settled
        return;

    // find minimum of both
    int minAmount = min(x, y);

    // update account balance of both max creditor and max debitor
    amount[mxDebit] += minAmount;
    amount[mxCredit] -= minAmount;

    cout << "Debitor " << mxDebit << " Pays " << minAmount << " To " << mxCredit << endl;

    minCashFlow(amount, n);
}


// graph[i][j] indicates the amount that person i needs to pay person j
void minCashFlow(vector<vector<int>> graph, int n)
{
    // Create an array amount[], initialize all value in it as 0.
    int amount[n] = {0};

    // Calculate the net amount to be paid to person 'p', and  stores it in amount[p].
    // The value of amount[p] can be calculated like this:
    // netAmount = (sum of all credits) - (sum of all debits)
    for (int p=0; p<n; p++)
       for (int i=0; i<n; i++)
          amount[p] += (graph[i][p] -  graph[p][i]);

    minCashFlow(amount, n);
}

int main()
{
    int n = 3;      // Number of persons
    vector<vector<int>> graph = {
                        {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0}};

    // Print the solution
    minCashFlow(graph, n);

    return 0;
}