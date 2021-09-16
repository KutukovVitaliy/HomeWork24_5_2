#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include "functions.h"

int main() {
    std::time_t t;
    std::string currentName;
    std::tm* local;
    std::string nameMonth[12] = {" Jan", " Feb", " Mar", " Apr", " May", " Jun", " Jul", " Aug", " Sep", " Oct", " Nov", " Dec"};
    struct birthday{
        std::string name;
        std::tm time;
    };
    //Объявляем вектор векторов из пар день в месяце-имя. Номер вектора соответствует номеру месяца.
    std::vector<std::vector<std::pair<int, std::string>>> vectorBirthday;
    //Заполняем пустыми векторами
    for(int i=0; i < 12; ++i){
        vectorBirthday.push_back(std::vector<std::pair<int, std::string>>());
    }
    birthday currentBirthday;
    t = std::time(nullptr);
    currentBirthday.time = *std::localtime(&t);
    do {
        std::cout << "Enter the name: ";
        std::cin >> currentBirthday.name;
        if(currentBirthday.name == "end") break;
        std::cout << "Enter the date of birthday(yyy-mm-dd):";
        std::cin >> std::get_time(&currentBirthday.time, "%Y-%m-%d");
        vectorBirthday.at(currentBirthday.time.tm_mon).push_back(std::make_pair(currentBirthday.time.tm_mday, currentBirthday.name));
    } while (true);
    t = std::time(nullptr);
    local = std::localtime(&t);
    int month = searchMonth(vectorBirthday, local->tm_mon);
    //Ищем ближайший номер вектора к текущему месяцу
    if(month  != -1){
        //ищем ближайший день в найденном векторе
        std::vector<std::pair<int, std::string>> day = searchDay(vectorBirthday, month);
        if(!day.empty()){
            for(auto el : day){
                if((local->tm_mon == month) && (local->tm_mday == el.first)) std:: cout << "Happy birthday dear " << el.second << std::endl;
                else {
                    std::cout <<"The nearest birthday for " << el.second << " is " << el.first << nameMonth[month]  << std::endl;
                }
            }
        }

    }
    else{
        std::cout << "There are no upcoming birthdays!" << std::endl;
    }
    return 0;
}