// Method 1 - Using our own sort function as only lowercase letters
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {

            mp[mysort(s)].push_back(s);
        }

        vector<vector<string>> anagrams;

        for (auto p : mp) {
            anagrams.push_back(p.second);
        }

        return anagrams;
    }
private:
    string mysort(string s) {
        int counter[26] = {0};

        for (char c : s) {
            counter[c - 'a']++;
        }
        
        string t;

        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};
// ==========================================================================================

// Method 2 - Using inbuilt sort
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;

        for (string& s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }

        for (auto& e : m) {
            res.push_back(e.second);
        }

        return res;
    }
};

// ===========================================================================================

