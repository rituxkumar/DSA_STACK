class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int counter = 1;

        while (top <= bottom && left <= right) {
            // 1️⃣ Left → Right
            for (int i = left; i <= right; i++)
                matrix[top][i] = counter++;
            top++;

            // 2️⃣ Top → Bottom
            for (int i = top; i <= bottom; i++)
                matrix[i][right] = counter++;
            right--;

            // 3️⃣ Right → Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    matrix[bottom][i] = counter++;
                bottom--;
            }

            // 4️⃣ Bottom → Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    matrix[i][left] = counter++;
                left++;
            }
        }

        return matrix;
    }
};