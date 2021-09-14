#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>


int main() {
    std::time_t t;
    std::string currentName;
    std::tm* local;
    struct birthday{
        std::string name;
        std::tm time;
    };

    std::vector<std::vector<std::pair<int, std::string>>> vectorBirthday;
    for(int i=0; i < 12; ++i){
        vectorBirthday.push_back(std::vector<std::pair<int, std::string>>());
    }
    birthday currentBirthday;
    t = std::time(nullptr);
    currentBirthday.time = *std::localtime(&t);
    do {
        std::cout << "Enter the name: ";
        std::cin >> currentBirthday.name;
        if(currentName == "end") break;
        std::cout << "Enter the date of birthday(yyy-mm-dd):";
        std::cin >> std::get_time(&currentBirthday.time, "%Y-%m-%d");
        vectorBirthday.at(currentBirthday.time.tm_mon).push_back(std::make_pair(currentBirthday.time.tm_mday, currentBirthday.name));
    } while (true);
    t = std::time(nullptr);
    local = std::localtime(&t);


    return 0;
}
