class Solution {
public:
    vector<int> twoSum(vector<int>& nums_1, int target) {
        // vector<int> result;
        // sort(nums_1.begin(), nums_1.end(), greater<int>()); // ��->С
        // vector<int> nums_2 = nums_1;
        // sort(nums_2.begin(), nums_2.end()); // С->��
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
        //���˼·�������ˣ����������ͺ������±��

        //����n*n��ʱ�临�Ӷ�,nlog(n)
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
