// An efficient method to find maximum value of mat[d]
// - ma[a][b] such that c > a and d > b
#include <bits/stdc++.h>
using namespace std;
#define N 5

// The function returns maximum value A(c,d) - A(a,b)
// over all choices of indexes such that both c > a
// and d > b.
int findMaxValue(int mat[][N])
{
	//stores maximum value
	int maxValue = INT_MIN;

	// maxArr[i][j] stores max of elements in matrix
	// from (i, j) to (N-1, N-1)
	int maxArr[N][N];

	// last element of maxArr will be same's as of
	// the input matrix
	maxArr[N-1][N-1] = mat[N-1][N-1];

	// preprocess last row#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends




int kthSmallest(int matrix[MAX][MAX], int n, int k)
{
  //Your code here
    priority_queue< pair< int, pair< int, int > >, vector < pair < int, pair < int, int >>>, greater< pair < int, pair < int, int >>>> pq;
    for (int i = 0; i < n; i++)
    pq.push({matrix[i][0], {i, 0}});
    int c = k, ans;
    while (c--) {
    int a = pq.top().first;
    int b = pq.top().second.first;
    int c = pq.top().second.second;
    ans = a;
    pq.pop();
    if (c != n - 1)
    pq.push({matrix[b][c + 1], {b, c + 1}});
    }
    return ans;
}

	int maxv = mat[N-1][N-1]; // Initialize max
	for (int j = N - 2; j >= 0; j--)
	{
		if (mat[N-1][j] > maxv)
			maxv = mat[N - 1][j];
		maxArr[N-1][j] = maxv;
	}

	// preprocess last column
	maxv = mat[N - 1][N - 1]; // Initialize max
	for (int i = N - 2; i >= 0; i--)
	{
		if (mat[i][N - 1] > maxv)
			maxv = mat[i][N - 1];
		maxArr[i][N - 1] = maxv;
	}

	// preprocess rest of the matrix from bottom
	for (int i = N-2; i >= 0; i--)
	{
		for (int j = N-2; j >= 0; j--)
		{
			// Update maxValue
			if (maxArr[i+1][j+1] - mat[i][j] >
											maxValue)
				maxValue = maxArr[i + 1][j + 1] - mat[i][j];

			// set maxArr (i, j)
			maxArr[i][j] = max(mat[i][j],
							max(maxArr[i][j + 1],
								maxArr[i + 1][j]) );
		}
	}

	return maxValue;
}

// Driver program to test above function
int main()
{
	int mat[N][N] = {
					{ 1, 2, -1, -4, -20 },
					{ -8, -3, 4, 2, 1 },
					{ 3, 8, 6, 1, 3 },
					{ -4, -1, 1, 7, -6 },
					{ 0, -4, 10, -5, 1 }
					};
	cout << "Maximum Value is "
		<< findMaxValue(mat);

	return 0;
}
