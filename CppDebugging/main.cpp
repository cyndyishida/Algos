#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_map>
using namespace std;
/*
// recursive solution
class Solution {
public:

    int rob_helper(vector<int>& nums, int sum, int i )
    {
        if(i < nums.size() )
        {
            sum += nums[i];
            return max( {rob_helper(nums,sum, i + 2),
                         rob_helper(nums,sum, i + 3), rob_helper(nums, sum,i + 4)} );
        }
        return sum;
    }


    int rob(vector<int>& nums) {


        return max({rob_helper(nums,0, 0),
                    rob_helper(nums,0,1), rob_helper(nums, 0,2)} );
    }
};
*/
/*
// memoized
class Solution {
public:

    using hash_table = std::unordered_map<string, int>;
    int rob_helper(vector<int>& nums, int sum, int i, hash_table& mem )
    {
        string key = to_string(i) + ":" + to_string(sum);
        if (mem.find(key) != mem.end() ) return mem[key];

        else if(i < nums.size() )
        {
            sum += nums[i];
            int result = max( {rob_helper(nums,sum, i + 2, mem),
                           rob_helper(nums,sum, i + 3, mem),
                           rob_helper(nums, sum,i + 4, mem)} );
            mem[key] = result;
            return result;

        }
        return sum;
    }


    int rob(vector<int>& nums) {

        hash_table mem;
        return max({rob_helper(nums,0, 0 , mem),
                    rob_helper(nums,0,1, mem), rob_helper(nums, 0,2, mem)} );
    }
};

*/

class Solution {
public:


    int rob(vector<int>& nums)
    {


        int result = 0;
        if (nums.size() == 0)
        {
            result = 0;
        }
        else if (nums.size() == 1 )
            result = nums[0];
        else if (nums.size() == 2)
            result = max(nums[0],nums[1]);
        else
        {
            std::vector<int> dp(nums.size(), INT_MIN);
            dp[0] = nums[0];
            dp[1] = nums[1];
            dp[2] = nums[0] + nums[2];
            int i = 3;
            for (; i < dp.size() && i >= 0 ; ++i )
            {
                dp[i] = nums[i] + max({dp[i - 2], dp[i - 3], dp[i - 4]});

            }

            result = max({dp[dp.size()-1], dp[dp.size()-2], dp[dp.size()-3]});
        }

        return result;

    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line = "[0,0,0]";
    //while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().rob(nums);

        string out = to_string(ret);
        cout << out << endl;
    //}
    return 0;
}