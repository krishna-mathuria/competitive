void diagonalPrintUtil(Node* root, int d,
                map<int, vector<int>> &diagonalPrint)
{
    // Base case
    if (!root)
        return;
    diagonalPrint[d].push_back(root->data);
 

    diagonalPrintUtil(root->left,d + 1, diagonalPrint);

    diagonalPrintUtil(root->right,d, diagonalPrint);
}
 

void diagonalPrint(Node* root)
{
     

    map<int, vector<int> > diagonalPrint;
    diagonalPrintUtil(root, 0, diagonalPrint);
 
    cout << "Diagonal Traversal of binary tree : \n";
    for (auto it :diagonalPrint)
    {
        vector<int> v=it.second;
        for(auto it:v)
          cout<<it<<" ";
        cout<<endl;
    }
}
 