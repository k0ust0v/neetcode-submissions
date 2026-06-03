#include <iostream>
#include <sstream>
class Solution {
public:

    string encode(vector<string>& strs) {
    string s = "";
    for (const auto& i : strs) {
        int len = i.size();
        
        // Add the length of the string as a 4-byte integer (assuming 32-bit integer)
        s.append(reinterpret_cast<const char*>(&len), sizeof(len));
        
        // Add the actual string
        s.append(i);
    }
    return s;
    }

    vector<string> decode(const string s) {
        vector<string> result;
        size_t i = 0;

        while (i < s.size()) {
            // Extract the length of the next string (first 4 bytes)
            int len;
            std::memcpy(&len, s.data() + i, sizeof(len));
            i += sizeof(len);

            // Extract the string of that length
            string str = s.substr(i, len);
            result.push_back(str);
            i += len;
        }

        return result;
    }
};
