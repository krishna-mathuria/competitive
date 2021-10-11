class NestedIterator {
    private:
        void flatten(NestedInteger x) {
            if (x.isInteger()) {
                arr.push_back(x.getInteger());
            }
            else {
                for(auto y : x.getList())
                    flatten(y);
            }
        }

        vector<int> arr;
        int i = 0;
    
    public:
        NestedIterator(vector<NestedInteger> &nestedList) {
            for (auto x : nestedList) {
                flatten(x);
            }
        }

        int next() {
            return arr[i++];
        }

        bool hasNext() {
            return i < arr.size();
        }
    

};