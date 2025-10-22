class Solution {
public:
    string simplifyPath(string path) {
        string token;
        stringstream ss(path);
        stack<string> st;

        // Split the path by '/'
        while (getline(ss, token, '/')) {
            // Skip empty tokens or current directory symbol "."
            if (token.empty() || token == ".")
                continue;

            // If ".." → go one level up (pop the stack if not empty)
            if (token == "..") {
                if (!st.empty()) st.pop();
            }
            // Otherwise, it's a valid folder name → push it
            else {
                st.push(token);
            }
        }

        // If stack is empty, it means we're at root
        if (st.empty()) return "/";

        // Build the canonical path from stack
        string result;
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result;
    }
};