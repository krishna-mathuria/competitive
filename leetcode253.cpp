class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */

    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        int n = intervals.size();
        vector<int> starts(n), ends(n);
		for(int i = 0; i < n; i++) {
				starts[i] = intervals[i].start;
				ends[i] = intervals[i].end;
		}
		sort(starts.begin(), starts.end());
		sort(ends.begin(), ends.end());
		int i = 0, j = 0, cur = 0, res = 0;
		while(i < n) {
				if(starts[i] < ends[j]) {
						res = max(res, ++cur);
						i++;
				} else {
						--cur;
						j++;
				}
		}
		return res;
}
        
};