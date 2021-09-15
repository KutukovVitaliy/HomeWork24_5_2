//
// Created by kvitadmin on 15.09.2021.
//

#include "functions.h"

int searchMonth(std::vector<std::vector<std::pair<int, std::string>>>& birthday, int currentMonth){
    //Находим ближайшую запись в векторе
    int min = -1;
    for(int i = currentMonth; i < 12; ++i){
        if(!birthday.at(i).empty()){
            min = i - currentMonth;
            break;
        }
    }
    return min;
}
std::vector<std::pair<int, std::string>> searchDay(std::vector<std::vector<std::pair<int, std::string>>>& birthday){
    std::vector<std::pair<int, std::string>> newVector;
    std::time_t t;
    std::tm* local;
    t = std::time(nullptr);
    local = std::localtime(&t);
    //Находим ближайшую запись в векторе к номеру текущего месяца
    int minMonth = -1;
    for(int i = local->tm_mon; i < 12; ++i){
        if(!birthday.at(i).empty()){
            minMonth = i - local->tm_mon;
            break;
        }
    }
    //Если такая запись есть, то ищем ближайший день рождения
    if(minMonth != -1){
        int minDay = -1;
        for(int i = 0; i < birthday.at(minMonth).size(); ++i){

        }
    }
}