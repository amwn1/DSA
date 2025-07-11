#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string sortSentence(string s) {
    string ans;
    vector<string> temp(10);
    string word; 

    for(int i = 0 ; i < s.length() ; i++){
        if(isdigit(s[i])){
            temp[s[i] - '0'] = word + " ";
            word = "";
            i++;
        }
        else{
            word+=s[i];
        }
    }
    for(auto a : temp){
        ans+= a;
    }
    ans.pop_back();
    return ans;
    }
};

int main() {
    string s = "is2 sentence4 This1 a3";
    Solution sol ;
    cout << "Original Sentence: " << s << endl;
    cout << "The final answer: "<< sol.sortSentence(s);

    return 0;
}