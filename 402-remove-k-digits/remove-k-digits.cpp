class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        for(int i=0; i<num.size(); i++){
            while(k && !st.empty() && st.top() > (num[i]-'0'))
            {
                st.pop();
                k--;
            }
            st.push(num[i]-'0'); // while pushing we inserted as int so , while checking no need to convert the top
        }
        while(k>0){
                st.pop();
                k--;
            }
        string ans = "";
        while(!st.empty()){
            ans+=(char)(st.top()+'0');
            st.pop();
        }
        while(ans.size()!=0 && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans.empty() ? "0" : ans;
    }
};