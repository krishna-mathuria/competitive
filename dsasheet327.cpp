class Solution{   
public:
    string solve(int arr[], int n) {
        string ans = "";
        int carry = 0;
        
        sort(arr , arr+n ,greater<int>());
        int i = 0;
        while(i < n)
        {
            int x = arr[i] , y = 0;
            i++;
            
            if(i < n)
            {
                y = arr[i];
                i++;
            }
            
            int sum = x + y + carry;
            carry = sum/10;
            
            if(sum > 0)
                ans += ((sum % 10) + '0');
        }
        
        if(carry) ans += (carry + '0');
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};