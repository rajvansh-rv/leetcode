class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days, int capacity) {

        int currentWeight = 0;
        int daysUsed = 1;

        for (int weight : weights) {

            if (currentWeight + weight <= capacity) {
                currentWeight += weight;
            }
            else {
                daysUsed++;
                currentWeight = weight;

                if (daysUsed > days)
                    return false;
            }
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int start = *max_element(weights.begin(), weights.end());

        int end = accumulate(weights.begin(), weights.end(), 0);

        int ans = end;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (shipWithinDays(weights, days, mid)) {

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