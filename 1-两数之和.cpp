class Solution {
public:
    vector<int> twoSum(vector<int>& nums_1, int target) {
        // vector<int> result;
        // sort(nums_1.begin(), nums_1.end(), greater<int>()); // 大->小
        // vector<int> nums_2 = nums_1;
        // sort(nums_2.begin(), nums_2.end()); // 小->大
        // int i=0;
        // int j=0;
        // while(i<nums_1.size() && j<nums_2.size())
        // {
        //     if (nums_1[i] + nums_2[j] == target)
        //     {
        //         return {int(nums_1.size())-1-i,j};
        //     }
        //     else if (nums_1[i] + nums_2[j]>target)
        //         i = i + 1;
        //     else if(nums_1[i] + nums_2[j]<target)
        //         j = j + 1;
        // }
        // return {i,j}; 
        //这个思路错离谱了，这样根本就忽略了下标号

        //这是n*n的时间复杂度,nlog(n)
        int i = 0;
        int j = 0;
        for(i=0;i<nums_1.size()-1;i++)
        {
            for(j=i+1;j<nums_1.size();j++)
            {
                if(nums_1[i] + nums_1[j] == target)
                    return {i,j};
            }
        }
        return {i,j};
    }
};
