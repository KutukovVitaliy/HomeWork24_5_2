#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include "functions.h"

int main() {
    std::time_t t;
    std::string currentName;
    std::tm* local;
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
    //Ищем ближайший номер вектора к текущему месяцу
    if(int month = searchMonth(vectorBirthday, local->tm_mon) != -1){
        //ищем ближайший день в найденном векторе
        std::vector<std::pair<int, std::string>> day = searchDay(vectorBirthday, month);
        if(!day.empty()){
            for(auto el : day){
                if(local->tm_mon == month && local->tm_mday == el.first) std:: cout << "Happy birthday dear " << el.second << std::endl;
                else std::cout <<"The nearest birthday for " << el.second << " is " << el.first << " / " << month << std::endl;
            }
        }
    }
    return 0;
}
