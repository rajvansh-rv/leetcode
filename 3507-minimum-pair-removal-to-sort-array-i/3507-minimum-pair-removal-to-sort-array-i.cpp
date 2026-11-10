class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {

        int operations = 0;

        while (true) {

            // Check if array is sorted
            bool sorted = true;

            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    sorted = false;
                    break;
                }
            }

            if (sorted) return operations;

            // Find minimum adjacent pair sum
            int minSum = INT_MAX;
            int index = 0;

            for (int i = 0; i < nums.size() - 1; i++) {

                int sum = nums[i] + nums[i + 1];

                if (sum < minSum) {
                    minSum = sum;
                    index = i;
                }
            }

            // Merge the pair
            nums[index] = minSum;
            nums.erase(nums.begin() + index + 1);

            operations++;
        }

        return operations;
    }
};