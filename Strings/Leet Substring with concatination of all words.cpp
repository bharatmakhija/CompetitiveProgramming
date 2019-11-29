/* LeetCode : Substring with concatination of all words
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words 
exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
*/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string>& L) {
    vector<int> result;
    if ( S.size()<=0 || L.size() <=0 ){
        return result;
    }
    
    int n = S.size(), m = L.size(), l = L[0].size();

    //put all of words into a map    
    map<string, int> expected;
    for(int i=0; i<m; i++){
        if (expected.find(L[i])!=expected.end()){
            expected[L[i]]++;
        }else{
            expected[L[i]]=1;
        }
    }

    for (int i=0; i<l; i++){
        map<string, int> actual;
        int count = 0; //total count
        int winLeft = i;
        for (int j=i; j<=n-l; j+=l){
            string word = S.substr(j, l);
           // cout << word << endl;
            //if not found, then restart from j+1;
            if (expected.find(word) == expected.end() ) {
                actual.clear();
                count=0;
                winLeft = j + l;
                continue;
            }
            count++;
            //count the number of "word"
            if (actual.find(word) == actual.end() ) {
                actual[word] = 1;
            }else{
                actual[word]++;
            }
            // If there is more appearance of "word" than expected
            if (actual[word] > expected[word]){
                string tmp;
                do {
                    tmp = S.substr( winLeft, l );
                    count--;
                    actual[tmp]--;
                    winLeft += l; 
                } while(tmp!=word);
            }

            // if total count equals L's size, find one result
            if ( count == m ){
                result.push_back(winLeft);
                string tmp = S.substr( winLeft, l);
                actual[tmp]--;
                winLeft += l;
                count--;
            }
            
        }
    }

    return result;
    }
};
