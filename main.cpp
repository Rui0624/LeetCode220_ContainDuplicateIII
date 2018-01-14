//
//  main.cpp
//  LeetCode220_ContainsDuplicateIII
//
//  Created by Rui on 1/13/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
#include<cmath>//C语言是math.h

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(i - j > k)
            {
                m.erase(nums[j]);
                j++;
            }
            
            auto a = m.lower_bound((long long)nums[i] - t);
            if(a != m.end() && abs(a->first - nums[i]) <= t)
                return true;
            
            m[nums[i]] = i;
            
        }
        
        return false;
    }
};
