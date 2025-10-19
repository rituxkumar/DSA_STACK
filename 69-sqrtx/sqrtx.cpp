class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x; // directly return for 0 and 1

        long long left = 0, right = x, ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (mid * mid == x)  // perfect square case
                return mid;

            if (mid * mid < x) { // move right
                ans = mid;       // store nearest possible answer
                left = mid + 1;
            } else {
                right = mid - 1; // move left
            }
        }
        return ans;  // returns floor value of sqrt(x)
    }
};
