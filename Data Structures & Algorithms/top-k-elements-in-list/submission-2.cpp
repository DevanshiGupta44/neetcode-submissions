class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<pair<int,int>> vec;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto &it : mpp){
            vec.push_back(it);
        }
        sort(vec.begin() , vec.end() , [](pair<int,int>& a , pair<int,int>& b){
            return a.second > b.second;
        });
        //sort(vec.rbegin(), vec.rend());
        int i = 0;
        k = min( k , (int)vec.size());
        while(k>0){
            ans.push_back(vec[i].first);
            i++;
            k--;
        }
        return ans;
    }
};
//time : o(n log n) ; space : o(n)
