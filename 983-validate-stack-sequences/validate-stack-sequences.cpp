class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0;
        int m = pushed.size();
        while (i < m && j < m) {
            st.push(pushed[i]);

            while (!st.empty() && j < m && st.top() == popped[j]) {
                st.pop();
                j++;
            }
            i++;
           
        }
         return st.empty();
    }
};