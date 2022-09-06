//
// Created by Muhammad Ashraf on 2/1/22.
//

#ifndef PA01_SENTIMENT_PARSE_H
#define PA01_SENTIMENT_PARSE_H

#include <iostream>
#include <vector>
#include "DSString.h"
#include <fstream>
#include <map>
#include "Words.h"
using namespace std;

class Parse{

private:

    DSString line;
    DSString delim;
    bool sent;



public:

    void voila(char**file);//opens file and grabs tweet

    void splitWord(DSString tweet, bool sentiment, map<DSString, Words>& papaBear);

    void tweetTest(map<DSString, Words> &mamaBear, char**file); //reads in file for test dataset and grabs the id

    bool tweetTestFunc(DSString tweet, map<DSString, Words>& mamaBear); //function compares id  and returns bool if id matches sent

    void answerSheet(map<DSString, bool>& babyBear, char**file); //function reads in sentiment dataset



};

#endif //PA01_SENTIMENT_PARSE_H
