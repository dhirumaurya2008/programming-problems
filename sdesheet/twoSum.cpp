 vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;
        vector<int> res;
        for (int i=0; i<nums.size(); i++)
        {
            if ( mp.find(nums[i]) == mp.end())
                mp[nums[i]] = i;
        }

        for (int i=0; i<nums.size(); i++)
        {
            unordered_map<int, int>::iterator it = mp.find(target - nums[i]);

            if (it != mp.end() && (it->second != i))
            {
                res.push_back(i);
                res.push_back(it->second);
                break;
            }
        }
        return res;
    }
