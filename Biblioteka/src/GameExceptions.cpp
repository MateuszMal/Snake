//
// Created by student on 15.09.2020.
//

#include "GameExceptions.h"

using namespace std;

GameExceptions::GameExceptions(const std::string & arg) : logic_error(arg){}

const string GameExceptions::exceptionGameExceptionNoFile = "FILE NOT FOUND";
const string GameExceptions::exceptionGameExceptionWrongValue = "WRONG VALUE";