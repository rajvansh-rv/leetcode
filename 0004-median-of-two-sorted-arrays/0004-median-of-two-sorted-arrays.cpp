class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();

        int start = 0;
        int end = m;

        while (start <= end) {

        
            int partitionX = start + (end - start) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            // Left side values
            int leftX;

            if (partitionX == 0)
                leftX = INT_MIN;
            else
                leftX = nums1[partitionX - 1];

            int leftY;

            if (partitionY == 0)
                leftY = INT_MIN;
            else
                leftY = nums2[partitionY - 1];

            // Right side values
            int rightX;

            if (partitionX == m)
                rightX = INT_MAX;
            else
                rightX = nums1[partitionX];

            int rightY;

            if (partitionY == n)
                rightY = INT_MAX;
            else
                rightY = nums2[partitionY];

        
            if (leftX <= rightY && leftY <= rightX) {

                
                if ((m + n) % 2 == 1) {
                    return max(leftX, leftY);
                }
                return (max(leftX, leftY) + min(rightX, rightY)) / 2.0;
            }

            
            else if (leftX > rightY) {
                end = partitionX - 1;
            }
            else {
                start = partitionX + 1;
            }
        }

        return 0.0;
    }
};