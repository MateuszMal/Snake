//
// Created by student on 15.09.2020.
//

#ifndef SNAKE_GAMEEXCEPTIONS_H
#define SNAKE_GAMEEXCEPTIONS_H


#include <stdexcept>

class GameExceptions : public std::logic_error{
public:
    explicit GameExceptions(const std::string &);
    static const std::string exceptionGameExceptionNoFile;
    static const std::string exceptionGameExceptionWrongValue;
};


#endif //SNAKE_GAMEEXCEPTIONS_H
