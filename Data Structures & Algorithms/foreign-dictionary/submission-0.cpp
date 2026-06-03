class Solution {
private:
unordered_map<char, unordered_set<char>> adjList;
unordered_map<char, bool> vis; //false - vis True-vis and in path
string res;

bool dfs(char ch) {
    if (vis.find(ch) != vis.end()) {
        return vis[ch]; //true cycle and false no cycle
    }
    vis[ch] = true;
    for(auto c :adjList[ch]) {
        if(dfs(c))
            return true;
    }
    vis[ch] = false;
    res.push_back(ch);
    return false;
}
public:
    string foreignDictionary(vector<string>& words) {
        //Populate the adjList

        for(auto word : words){
            for(auto c : word) {
                adjList[c];
            }
        }

        for(int i = 0; i < words.size()-1; ++i) {
            string w1 = words[i];
            string w2 = words[i+1];
            int minLen = min(w1.length(), w2.length());

            //if the first word is larger and second is a substring then it is
            // it is not possible
            //eg apes and ape.
            if (w1.length() > w2.length() && 
                w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }

            for(int j = 0; j < minLen; ++j ) {
                if(w1[j] != w2[j]){
                    adjList[w1[j]].insert(w2[j]);
                    break;// break at first instance
                }
            }
        }

        //Now traversing the graph via dfs and creating the post order traversal list
        for(auto node : adjList) {
            if(dfs(node.first))
                return "";
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
 