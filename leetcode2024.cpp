class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int fs = 0, l = 0;
        int maxLen = 0;
        for( int r = 0 ; r < s.size() ; ++r ) {
            if( s[ r ] == 'F' ) ++fs;
            while( fs > k ) {
                if( s[ l ] == 'F' ) --fs;
                ++l;
            }
            maxLen = max( maxLen, r - l + 1 );
        }
        int ts = 0, l2 = 0;
        int maxLen2 = 0;
        for( int r = 0 ; r < s.size() ; ++r ) {
            if( s[ r ] == 'T' ) ++ts;
            while( ts > k ) {
                if( s[ l2 ] == 'T' ) --ts;
                ++l2;
            }
            maxLen2 = max( maxLen2, r - l2 + 1 );
        }
        return max(maxLen,maxLen2);
    }
};