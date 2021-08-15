void kStacks::push(int item, int sn)
{
    // Overflow check
    if (isFull())
    {
        cout << "\nStack Overflow\n";
        return;
    }
  
    int i = free;      // Store index of first free slot
  
    // Update index of free slot to index of next slot in free list
    free = next[i];
  
    // Update next of top and then top for stack number 'sn'
    next[i] = top[sn];
    top[sn] = i;
  
    // Put the item in array
    arr[i] = item;
}
  
// To pop an from stack number 'sn' where sn is from 0 to k-1
int kStacks::pop(int sn)
{
    // Underflow check
    if (isEmpty(sn))
    {
         cout << "\nStack Underflow\n";
         return INT_MAX;
    }
  
  
    // Find index of top item in stack number 'sn'
    int i = top[sn];
  
    top[sn] = next[i];  // Change top to store next of previous top
  
    // Attach the previous top to the beginning of free list
    next[i] = free;
    free = i;
  
    // Return the previous top item
    return arr[i];
}