//
// Created by Muhammad Ashraf on 2/1/22.
//

#include "Parse.h"
#include "Words.h"
#include <map>
#include <fstream>

void Parse::voila(char**file){

    std::ifstream myFile(file[1]);
    map<DSString, Words> myMap;
    if(myFile.is_open()){
        std::cout << "yippee" << std::endl;
        while(!myFile.eof()) {
            char* buffer = new char[1000];
            myFile.getline(buffer, 1000);
            DSString temp(buffer);//do loop for this, also grab ID, and store into vector
            if (temp.getLength() < 51) {
                continue; //skips last line of file if not desired size
            }
            DSString id = temp.substring(2,10); // grab ID

            DSString sentiment = temp.substring(0,1); // grab sentiment
          if(sentiment == "0"){
              sent = false;
          }else{
              sent = true;
          }
            DSString tweetGrab = temp.substring(51, temp.getLength() - 51); //length of string minus characters to get to the tweet

            int index;
            for(int i = 0; i < tweetGrab.getLength(); i++){
                if(tweetGrab[i] == ','){
                    index = i + 1;
                    break;
                }
            } // finds comma before tweet and iterates through it

            DSString tweet = tweetGrab.substring(index, tweetGrab.getLength() - index); // grabs tweet

            splitWord(tweet, sent, myMap);

            delete[] buffer;
        }
        myFile.close();
//        for (map<DSString, Words>::const_iterator it = myMap.begin(); it != myMap.end(); it++) {
//            cout << it->first << " " << it->second.getPositive() << " " << it->second.getNegative() << endl;
//        }// print out map contents with word and count of pos and neg frequency of words
        tweetTest(myMap, file);
    }else{
        std::cout<<"error, file did not open"<<std::endl;
    }
}// end voila

void Parse::splitWord(DSString tweet, bool sentiment, map<DSString, Words>& papaBear) {
    int tweetIndex = 0;
    for(int i = 0; i < tweet.getLength(); i++){
        if(isalpha(tweet[i]) == 0) {
            if (i - tweetIndex == 0) {
                tweetIndex++;
                continue;
            }// if consecutive 0's, skip because not a word
            DSString word = tweet.substring(tweetIndex, i - tweetIndex).toLower();
            tweetIndex = i + 1;
            if (papaBear.find(word) == papaBear.end()) {
                Words temp;
                temp.setContainer(word);
                papaBear[word] = temp;
            } // creates new word object if not already in map
            if (sentiment) {
                papaBear[word].PositiveCount(); //increments count for pos
            } else {
                papaBear[word].NegativeCount(); // increments count for neg
            }
        }//this will skip spaces in the tweet
    }
    if (tweetIndex < tweet.getLength()){
        DSString word = tweet.substring(tweetIndex, tweet.getLength() - tweetIndex).toLower(); //makes words lower case
        if (papaBear.find(word) == papaBear.end()) {
            Words temp;
            temp.setContainer(word);
            papaBear[word] = temp;
        } // creates new word object if not already in map
        if (sentiment) {
            papaBear[word].PositiveCount(); //increments count for pos
        } else {
            papaBear[word].NegativeCount(); // increments count for neg
        }
    } // if a character ends a tweet, it will at the last word

}// end split word

void Parse::tweetTest(map<DSString, Words> &mamaBear, char**file) {
    std::ifstream myFile(file[2]);
    map<DSString, bool> myMap2;
    if (myFile.is_open()) {
        std::cout << "yippee" << std::endl;
        while (!myFile.eof()) {
            char *buffer = new char[1000];
            myFile.getline(buffer, 1000);
            DSString temp(buffer);//do loop for this, also grab ID, and store into vector
            if (temp.getLength() < 51) {
                continue; //skips last line of file if not desired size
            }
            DSString id = temp.substring(0,10); // grab ID

            DSString tweetGrab = temp.substring(51, temp.getLength() - 51); //length of string minus characters to get to the tweet

            int index;
            for(int i = 0; i < tweetGrab.getLength(); i++){
                if(tweetGrab[i] == ','){
                    index = i + 1;
                    break;
                }
            } // finds comma before tweet and iterates through it

            DSString tweet = tweetGrab.substring(index, tweetGrab.getLength() - index); // grabs tweet

            myMap2[id] = tweetTestFunc(tweet, mamaBear); //check how many pos and neg words

            delete[] buffer;
        }
        myFile.close();
        answerSheet(myMap2, file);
////        for (map<DSString, bool>::const_iterator it = myMap2.begin(); it != myMap2.end(); it++) {
////            cout << it->first << " " << it->second << endl;
//        }// print out map contents with id number and bool
    }else{
        std::cout<<"error, file did not open"<<std::endl;
    }

}// end tweetTest

bool Parse::tweetTestFunc(DSString tweet, map<DSString, Words> &mamaBear) { //function compares the id and
    int posCount = 0;                                                       //return bool for the tweets if it matches the sentiment
    int negCount = 0;
    int tweetIndex = 0;
    for(int i = 0; i < tweet.getLength(); i++){
        if(isalpha(tweet[i]) == 0) {
            if (i - tweetIndex == 0) {
                tweetIndex++;
                continue;
            }// if consecutive 0's, skip because not a word
            DSString word = tweet.substring(tweetIndex, i - tweetIndex).toLower();
            tweetIndex = i + 1;
            if (mamaBear.find(word) == mamaBear.end()) {
                continue;
            } // creates new word object if not already in map
         else{

             if (mamaBear[word].getPositive() + mamaBear[word].getNegative() > 6.999999) {
                 if(mamaBear[word].getProp() > 0.61192999){
                     posCount++;//increments pos count if word appears in tweet over 70% based off sent
                 }else if(mamaBear[word].getProp() < 0.445699) {
                     negCount++;//increments neg count if word appears in tweet less than 70% based off sent
                 }
             }
         }
        }//this will skip spaces in the tweet
    }
    if(posCount > negCount){
        return true;
    }else{
        return false;
    }

}//end testTweetFunc

void Parse::answerSheet(map<DSString, bool> &babyBear, char** file) {
    std::ifstream myFile(file[3]);
    if (myFile.is_open()) {
        std::cout << "yippee" << std::endl;
        vector<DSString> wrong;
        vector<DSString> ignore;
        char *buffer = new char[1000];
        myFile.getline(buffer, 1000);
        delete[] buffer;
        while (!myFile.eof()) {
            buffer = new char[1000];
            myFile.getline(buffer, 1000);
            DSString temp(buffer);//do loop for this, also grab ID, and store into vector
          //  std::cout<<temp<<std::endl;
            if (temp.getLength() < 5) {
                continue; //skips last line of file if not desired size
            }
            DSString id = temp.substring(2,10); // grab ID

            DSString sentiment = temp.substring(0,1); // grab sentiment

//            if(babyBear.count("and") > 0 ){
//                ignore.push_back("and");
//            }else if(babyBear.count("the") > 0 ){
//                ignore.push_back("the");
//            }

            if(sentiment == "0" ){
                sent = false;
            }else{
                sent = true;
            }
            if (babyBear[id] != sent) {
                wrong.push_back(id); //error here
            }
            delete[] buffer;

            }

        ofstream answerKey(file[4]);
        double accuracy = (double)(babyBear.size() - wrong.size()) / babyBear.size() * 100;
            answerKey<<accuracy<<std::endl;
            for(int i = 0; i < wrong.size(); i++){
                answerKey<<wrong[i]<<std::endl;

        }

        myFile.close();
    }else{
        std::cout<<"error, file did not open"<<std::endl;
    }

}//end answerSheet



