#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

#include "Solution19.h"
#include "StringParser.h"

#define CATEGORY_X 0
#define CATEGORY_M 1
#define CATEGORY_A 2
#define CATEGORY_S 3
#define RANGE_MIN 0
#define RANGE_MAX 1

using namespace std;

long long Solution19::solve(string &input) {
    sum = 0;
    StringParser stringParser;
    vector<string> sectionVector;
    stringParser.split(sectionVector, input, {"\n\n"});

    vector<string> workflowVector;
    stringParser.split(workflowVector, sectionVector[0], {"\n"});
    for (const string &workflow : workflowVector) {
        vector<string> headeredVector;
        stringParser.split(headeredVector, workflow, {"{", "}"});
        vector<string> decisionVector;
        stringParser.split(decisionVector, headeredVector[1], {"{", "}", ":", ","});
        workflowMap[headeredVector[0]] = decisionVector;
    }

    // vector<string> partVector;
    // stringParser.split(partVector, sectionVector[1], {"\n"});
    // for (const string &part : partVector) {
    //     vector<string> termVector;

    //     stringParser.split(termVector, part, {"{", "}", "x", "m", "a", "s", "="});
    //     vector<int> ratingVector;
    //     for (unsigned int rating = 0; rating < termVector.size(); rating++) {
    //         ratingVector.push_back(stoi(termVector[rating]));
    //     }
    //     sendThroughWorkflow(ratingVector, {"in"});

    // }

    vector<int> ratingVector;
    for (int i = 0; i < 4; i++) {
        ratingVector.push_back(1);
        ratingVector.push_back(4000);        
    }
    sendThroughWorkflow(ratingVector, "in");
    return sum;
};

void Solution19::sendThroughWorkflow(const vector<int> &ratingVector, const string &workflowName) {
    stack<vector<int>> partStack;
    stack<pair<string, int>> workflowStack;
    partStack.push(ratingVector);
    workflowStack.push(pair<string, int>(workflowName, 0));

    while (!partStack.empty()) {
        vector<int> currPart = partStack.top();
        pair<string, int> currWorkflow = workflowStack.top();\
        partStack.pop();
        workflowStack.pop();
        string currDecision = workflowMap[currWorkflow.first][currWorkflow.second];

        if (currDecision == "A") {
            // addRatings(ratingVector);
            addCombinations(currPart);
        } else if (currDecision.find("<") != currDecision.npos || currDecision.find(">") != currDecision.npos) {
            int conclusion = makeDecision(currPart, currWorkflow, partStack, workflowStack);
            if (conclusion > 0) {
                partStack.push(currPart);
                workflowStack.push(pair<string, int>(currWorkflow.first, currWorkflow.second + conclusion));
            }
        } else if (currDecision != "R") {
            partStack.push(currPart);
            workflowStack.push(pair<string, int>(currDecision, 0));
        }
    }
};

void Solution19::addRatings(const vector<int> &ratingVector) {
    for (unsigned int category = 0; category < ratingVector.size(); category++) {
        sum = sum + ratingVector[category];
    }
};

void Solution19::addCombinations(const vector<int> &ratingVector) {
    long long product = 1;
    for (int category = 0; category < 4; category++) {
        product = product * (ratingVector[2 * category + RANGE_MAX] - ratingVector[2 * category + RANGE_MIN] + 1);
    }
    sum = sum + product;
};

int Solution19::makeDecision(const vector<int> &ratingVector, const pair<string, int> &workflow, stack<vector<int>> &partStack, stack<pair<string, int>> &workflowStack) {
    int variable;
    string decision = workflowMap[workflow.first][workflow.second];
    if (decision[0] == 'x') {
        variable = CATEGORY_X;
    } else if (decision[0] == 'm') {
        variable = CATEGORY_M;
    } else if (decision[0] == 'a') {
        variable = CATEGORY_A;
    } else if (decision[0] == 's') {
        variable = CATEGORY_S;
    }

    int limit = stoi(decision.substr(2));

    if (decision[1] == '<') {
        if (ratingVector[2 * variable + RANGE_MIN] < limit && ratingVector[2 * variable + RANGE_MAX] >= limit) {
            vector<int> lowerRange = vector<int>(ratingVector);
            lowerRange[2 * variable + RANGE_MAX] = limit - 1;
            partStack.push(lowerRange);
            workflowStack.push(workflow);

            vector<int> upperRange = vector<int>(ratingVector);
            upperRange[2 * variable + RANGE_MIN] = limit;
            partStack.push(upperRange);
            workflowStack.push(workflow);
            return 0;
        } else {
            return ratingVector[2 * variable + RANGE_MAX] < limit ? 1 : 2;
        }
    } else {
        if (ratingVector[2 * variable + RANGE_MIN] <= limit && ratingVector[2 * variable + RANGE_MAX] > limit) {
            vector<int> lowerRange = vector<int>(ratingVector);
            lowerRange[2 * variable + RANGE_MAX] = limit;
            partStack.push(lowerRange);
            workflowStack.push(workflow);

            vector<int> upperRange = vector<int>(ratingVector);
            upperRange[2 * variable + RANGE_MIN] = limit + 1;
            partStack.push(upperRange);
            workflowStack.push(workflow);
            return 0;
        }
        return ratingVector[2 * variable + RANGE_MIN] > limit ? 1 : 2;
    }
};