class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string,vector<string>> groupedAnagram;
        
        for(const string& word :arr){
            string sorted_word = word;
            sort(sorted_word.begin(),sorted_word.end());
            groupedAnagram[sorted_word].push_back(word);
        }
        
        vector<vector<string>> result;
        for (auto it = groupedAnagram.begin(); it != groupedAnagram.end(); ++it)
            result.push_back(move(it ->second));
        
        return result;
    }
};