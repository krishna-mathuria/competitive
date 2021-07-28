#include<bits/stdc++.h>
using namespace std;

void constructTree(int node, int l, int r, vector<int> &tree, vector<vector<int>> &nums){
    if(l == r){
        tree[node] = nums[l][1];
        return;
    }
    int m = (l + r) / 2;
    constructTree(node * 2 + 1, l, m, tree, nums);
    constructTree(node * 2 + 2, m + 1, r, tree, nums);
    tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
}

int getMax(int node, int qs, int qe, int ss, int se, vector<int> &tree, vector<vector<int>> &nums){
    if(nums[se][0] < qs || qe < nums[ss][0]){
        return 0;
    if(qs <= nums[ss][0] && nums[se][0] <= qe)
        return tree[node];
    int m = (ss + se) / 2;
    return max(getMax(2 * node + 1, qs, qe, ss, m, tree, nums), getMax(2 * node + 2, qs, qe, m + 1, se, tree, nums));
}

int main(){
    int n, q, size;

    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));

    for(int i = 0; i < n; i++)
        cin >> nums[i][0] >> nums[i][1];
    sort(nums.begin(), nums.end());
    size = 2 * pow(2, ceil(log2(n)));
    vector<int> tree(size);
    constructTree(0, 0, n - 1, tree, nums);

    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << getMax(0, l, r, 0, n - 1, tree, nums) << endl;
    }
    return 0;
}