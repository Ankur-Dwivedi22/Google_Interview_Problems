// https://leetcode.com/problems/inverse-coin-change/description/

class Solution
{
public:
    vector<int> findCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                int coin = i + 1;
                ans.push_back(coin);
                for (int j = n - 1; j >= i + 1; j--)
                {
                    nums[j] -= nums[j - coin];
                }
                nums[i] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                return {};
            }
        }

        return ans;
    }
};

// TC : O(N * N)
// SC : O(1)