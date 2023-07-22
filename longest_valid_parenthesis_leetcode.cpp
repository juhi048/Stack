class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // push -1 as initial index to start from
        int maxLength = 0;
        
        for(int i=0; i<s.size(); i++) {
            // if current character is '(', push its index
            if(s[i] == '(') {
                st.push(i);
            }
            else { 
                // if current character is ')', pop the top
                if(!st.empty())
                    st.pop();
                // if stack is not empty, update the maxLength 
                // by the difference of current index and index at the top of the stack
                if(!st.empty()) {
                    maxLength = max(maxLength, i - st.top());
                }
                else {
                    // if stack is empty, push the current index
                    st.push(i);
                }
            }
        }
        
        return maxLength;
    }
};
