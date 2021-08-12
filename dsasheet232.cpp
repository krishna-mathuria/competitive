bool comparator(struct meeting m1, meeting m2)
{
    return (m1.end < m2.end);
}
 
// Function for finding maximum meeting in one room
void maxMeeting(int s[], int f[], int n)
{
    struct meeting meet[n];
    for (int i = 0; i < n; i++)
    {
        // Starting time of meeting i.
        meet[i].start = s[i];
         
        // Finishing time of meeting i
        meet[i].end = f[i];
         
        // Original position/index of meeting
        meet[i].pos = i + 1;
    }
 
    // Sorting of meeting according to their finish time.
    sort(meet, meet + n, comparator);
 
    // Vector for storing selected meeting.
    vector<int> m;
 
    // Initially select first meeting.
    m.push_back(meet[0].pos);
 
    // time_limit to check whether new
    // meeting can be conducted or not.
    int time_limit = meet[0].end;
 
    // Check for all meeting whether it
    // can be selected or not.
    for (int i = 1; i < n; i++) {
        if (meet[i].start >= time_limit)
        {
            // Push selected meeting to vector
            m.push_back(meet[i].pos);
             
            // Update time limit.
            time_limit = meet[i].end;
        }
    }
 
    // Print final selected meetings.
    for (int i = 0; i < m.size(); i++) {
        cout << m[i] << " ";
    }
}