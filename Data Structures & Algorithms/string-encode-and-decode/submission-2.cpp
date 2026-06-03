#include <iostream>
#include <sstream>
class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for (const auto& i : strs) {
            int len = i.size();
/*
reinterpret_cast<const char*>(&len):

len is an integer (most likely a 4-byte integer, assuming it's int).
&len gives the address of the integer len (i.e., the memory location where len is stored).
The reinterpret_cast<const char*> converts the address of len into a const char*. This allows you to treat the integer's raw bytes as a string of characters. Since char represents raw byte data, you can now append these bytes directly to the string.
sizeof(len):

sizeof(len) returns the size of the len variable in bytes. If len is a 32-bit int, this will typically be 4 bytes.
This tells the append() function how many bytes of len to append to the string.
*/
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
/*
s.data() + i:

s.data() returns a pointer to the first byte of the string s.
i is an offset that indicates where in the string s the length data (the 4 bytes) starts. So s.data() + i points to the location in the string where the length is stored.
&len:

&len is the address of the integer len. You want to write the 4 bytes of length data into this variable, so you pass its address.
sizeof(len):

This indicates how many bytes to copy (again, 4 bytes if len is a 32-bit integer).
std::memcpy(...):

This function copies the bytes starting at s.data() + i into the memory location of len.
It reads the 4 bytes from the string s and stores them as an integer in len.
*/
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
