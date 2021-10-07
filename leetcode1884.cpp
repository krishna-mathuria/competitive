class Solution {
public:
    int twoEggDrop(int n)
    {
        auto out{0};
        for(auto i{0}; n; --n)
            if(++i>out) out=i, i=1;
        return out;    
    }
};