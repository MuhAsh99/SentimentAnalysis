#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <fstream>
#include "DSString.h"
#include "catch.hpp"
#include "Parse.h"
#define CATCH_CONFIG_MAIN


void runCatch(){
    std::cout << "I'm in here!" << std::endl;
    Catch::Session session = Catch::Session();
    session.run();
}

int main(int argc, char**argv) {


    if(argc == 1){
        //catch
        runCatch();
        return 0;
    }else if(argc == 5){
        //run program
       Parse parser;
       parser.voila(argv);
    }else{
        //print wrong num of command line arg
        return 0;
    }
    return 0;
 }
