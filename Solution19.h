#ifndef SOLUTION19_H
#define SOLUTION19_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution19 {
    public:
        int solve(string &input);

    private:
        int sum;
        unordered_map<string, vector<string>> workflowMap;
        void sendThroughWorkflow(const vector<int> &input, vector<string> workflow);
        void addRatings(const vector<int> &input);
        int makeDecision(const vector<int> &ratingVector, const string &step);
};

#endif