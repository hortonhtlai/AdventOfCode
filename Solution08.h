#ifndef SOLUTION08_H
#define SOLUTION08_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution08 {
    public:
        int solve(string &input);
    
    private:
        int count;
        string instructions;
        unordered_map<string, pair<string, string>> network;
        unordered_map<string, string> shortcut;
        void generateShortcut();
        void traverseNetwork();
};

#endif