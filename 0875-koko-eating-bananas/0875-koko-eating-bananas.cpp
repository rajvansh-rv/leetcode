class Solution {
public:

    bool possible(vector<int>& piles, int h, int speed) {

        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;

            if (hours > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int start = 1;

        int end = *max_element(piles.begin(), piles.end());

        int ans = end;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (possible(piles, h, mid)) {

                ans = mid;
                end = mid - 1;
            }
            else {

                start = mid + 1;
            }
        }

        return ans;
    }
};