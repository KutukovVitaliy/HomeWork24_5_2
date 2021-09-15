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
std::vector<std::pair<int, std::string>> searchDay(std::vector<std::vector<std::pair<int, std::string>>>& birthday, int month){
    std::vector<std::pair<int, std::string>> newVector;
    std::time_t t;
    std::tm* local;
    t = std::time(nullptr);
    local = std::localtime(&t);
    int minDay = 32;
    for(int i = 0; i < birthday.at(month).size(); ++i){
            if(birthday.at(month).at(i).first >= local->tm_mday) {
                if((birthday.at(month).at(i).first - local->tm_mday) < minDay){
                    minDay = birthday.at(month).at(i).first - local->tm_mday;
                }
            }
    }
    if(minDay != 32){
            //Добавляем все записи с этим днем в новый вектор

    }

}