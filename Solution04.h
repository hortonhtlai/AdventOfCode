#ifndef SOLUTION04_H
#define SOLUTION04_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution04 {
    public:
        int solve(string &input);
    
    private:
        int sum;
        int cardNum;
        unordered_map<int, int> cardPile;
        void winAndAddCopies(vector<string> &winningVector, vector<string> &chosenVector);
        void setAndAddOriginals(vector<string> &headerVector);
        void addCard(int newCardNum, int newCardCount);
};

#endif