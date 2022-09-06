//
// Created by Muhammad Ashraf on 2/6/22.
//

#include "DSString.h"

#ifndef PA01_SENTIMENT_SPLIT_H
#define PA01_SENTIMENT_SPLIT_H
class Words {
public:

    Words();

    void setContainer (DSString &holder) {wordContainer = holder;}
    DSString getContainer () {return wordContainer;}

    void PositiveCount(); //add positive word count
    void NegativeCount(); //add negative word count

    int getPositive() const {return countPositiveNum;}
    int getNegative() const {return countNegativeNum;}

    double getProp() const {return prop;}

private:

    DSString wordContainer;
    int countPositiveNum;
    int countNegativeNum;
    double prop;

};


#endif //PA01_SENTIMENT_SPLIT_H
