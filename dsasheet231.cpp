void survival(int S, int N, int M)
{
 
    // If we can not buy at least a week
    // supply of food during the first week
    // OR We can not buy a day supply of food
    // on the first day then we can't survive.
    if (((N * 6) < (M * 7) && S > 6) || M > N)
        cout << "No\n";
    else {
        // If we can survive then we can
        // buy ceil(A/N) times where A is
        // total units of food required.
        int days = (M * S) / N;
        if (((M * S) % N) != 0)
            days++;
        cout << "Yes " << days << endl;
    }
}