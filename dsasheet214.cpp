bool doOVerlap(Interval i1, Interval i2)
{
    if (i1.low < i2.high && i2.low < i1.high)
        return true;
    return false;
}

Interval *overlapSearch(ITNode *root, Interval i)
{
    // Base Case, tree is empty
    if (root == NULL) return NULL;
 
    // If given interval overlaps with root
    if (doOVerlap(*(root->i), i))
        return root->i;
 

    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);
 
    // Else interval can only overlap with right subtree
    return overlapSearch(root->right, i);
}
 
// This function prints all conflicting appointments in a given
// array of apointments.
void printConflicting(Interval appt[], int n)
{
     // Create an empty Interval Search Tree, add first
     // appointment
     ITNode *root = NULL;
     root = insert(root, appt[0]);
 
     // Process rest of the intervals
     for (int i=1; i<n; i++)
     {
         // If current appointment conflicts with any of the
         // existing intervals, print it
         Interval *res = overlapSearch(root, appt[i]);
         if (res != NULL)
            cout << "[" << appt[i].low << "," << appt[i].high
                 << "] Conflicts with [" << res->low << ","
                 << res->high << "]\n";
 
         // Insert this appointment
         root = insert(root, appt[i]);
     }
}