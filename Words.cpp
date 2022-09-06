//
// Created by Muhammad Ashraf on 2/6/22.
//

#include "Words.h"

Words::Words(){
    countPositiveNum = 0;
    countNegativeNum = 0;
    wordContainer = "";
}

void Words::PositiveCount() {
    countPositiveNum++;
    prop = (double)countPositiveNum / (countPositiveNum + countNegativeNum); //set proportion
}

void Words::NegativeCount(){
    countNegativeNum++;
    prop = (double)countNegativeNum / (countPositiveNum + countNegativeNum); //set proportion

}

