#include <bits/stdc++.h>
using namespace std;

stack<int> st;

int main(){
    while(1){
        string s;
        stack<char> st;
        
        getline(cin, s);
        int len = s.size();
        
        if(s == ".") break;
        
        for(int i=0; i<len; i++){
            if(s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
            
            else if(s[i] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    st.push('n');
                    break;
                }
            }
            
            else if(s[i] == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    st.push('n');
                    break;
                }
            }
        }
        
        if(st.empty()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}
