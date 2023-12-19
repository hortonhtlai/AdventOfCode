#include <iostream>
#include <string>
#include <vector>

#include "Solution19.h"
#include "StringParser.h"

using namespace std;

int Solution19::solve(string &input) {
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

    vector<string> partVector;
    stringParser.split(partVector, sectionVector[1], {"\n"});
    for (const string &part : partVector) {
        vector<string> termVector;

        stringParser.split(termVector, part, {"{", "}", "x", "m", "a", "s", "="});
        vector<int> ratingVector;
        for (unsigned int rating = 0; rating < termVector.size(); rating++) {
            ratingVector.push_back(stoi(termVector[rating]));
        }
        sendThroughWorkflow(ratingVector, {"in"});

    }

    return sum;
};

void Solution19::sendThroughWorkflow(const vector<int> &ratingVector, vector<string> workflow) {
    bool outcome = false;
    int step = 0;
    while (!outcome) {
        if (workflow[step] == "A") {
            outcome = true;
            addRatings(ratingVector);
        } else if (workflow[step] == "R") {
            outcome = true;
        } else if (workflow[step].find("<") != workflow[step].npos || workflow[step].find(">") != workflow[step].npos) {
            if (makeDecision(ratingVector, workflow[step])) {
                step++;
            } else {
                step = step + 2;
            }
        } else {
            workflow = workflowMap[workflow[step]];
            step = 0;
        }
    }
};

void Solution19::addRatings(const vector<int> &ratingVector) {
    for (unsigned int category = 0; category < ratingVector.size(); category++) {
        sum = sum + ratingVector[category];
    }
};

int Solution19::makeDecision(const vector<int> &ratingVector, const string &step) {
    int variable;
    if (step[0] == 'x') {
        variable = ratingVector[0];
    } else if (step[0] == 'm') {
        variable = ratingVector[1];
    } else if (step[0] == 'a') {
        variable = ratingVector[2];
    } else if (step[0] == 's') {
        variable = ratingVector[3];
    }

    int limit = stoi(step.substr(2));

    if (step[1] == '<') {
        return variable < limit;
    } else {
        return variable > limit;
    }
};