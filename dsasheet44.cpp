#include <bits/stdc++.h>
using namespace std;
 
#define N 4
 
void print(int arr[N][N])
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
            cout << arr[i][j] << " ";
             
        cout << '\n';
    }
}
 
void rotate(int arr[N][N])
{
     
    // First rotation
    // with respect to Secondary diagonal
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N - i; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[N - 1 - j][N - 1 - i];
            arr[N - 1 - j][N - 1 - i] = temp;
        }
    }
     
    // Second rotation
    // with respect to middle row
    for(int i = 0; i < N / 2; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[N - 1 - i][j];
            arr[N - 1 - i][j] = temp;
        }
    }
}
 
// Driver code
int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate(arr);
    print(arr);
    return 0;
}