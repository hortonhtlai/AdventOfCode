#ifndef SOLUTION19_H
#define SOLUTION19_H

#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution19 {
    public:
        long long solve(string &input);

    private:
        long long sum;
        unordered_map<string, vector<string>> workflowMap;
        void sendThroughWorkflow(const vector<int> &input, const string &workflowName);
        void addRatings(const vector<int> &ratingVector);
        void addCombinations(const vector<int> &ratingVector);
        int makeDecision(const vector<int> &ratingVector, const pair<string, int> &workflow, stack<vector<int>> &partStack, stack<pair<string, int>> &workflowStack);
};

#endif