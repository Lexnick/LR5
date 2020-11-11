#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>

int main() {

    std::cout << "Unordered_MultiMap:" << std::endl;
    std::unordered_multimap<int, std::string> MultiMap = {
            {1,    "ABC"},
            {2,    "BCA"},
            {3,    "QWE"},
            {3,    "RTY"},
            {3,    "DFG"},
            {4,    "HJH"},
            {4,    "KLK"},
            {2,    "UIO"},
            {2,    "DCV"},
            {5,    "VGB"},
            {6,    "HNB"},
            {6,    "KLO"},
            {7,    "WES"},
            {999,  "DSD"},
            {0,    "KIP"},
            {0,    "1WS"},
            {-500, "123"},
            {-100, "1ol"},
            {-200, "156"},
            {-1,   "1ss"},
    };
    std::string String;
    std::cout << std::setw(16) << std::right << "Key";
    std::cout << "||Value" << std::endl;
    std::for_each(MultiMap.begin(), MultiMap.end(), [](const std::pair<int, std::string> &Multi) {
        std::cout << std::setw(16) << std::right << Multi.first;
        std::cout << "||" << Multi.second << std::endl;
    });
    std::cout << std::endl;


    for (int i = 0; i < 3; i++) {
        std::cout << "Enter the new value(string type) for the key '5' (" << i + 1 << "/3)" << std::endl;
        std::getline(std::cin, String);
        MultiMap.insert(std::unordered_multimap<int, std::string>::value_type(5, String));
    }
    std::cout << std::setw(16) << std::right << "Key";
    std::cout << "||Value" << std::endl;
    std::for_each(MultiMap.begin(), MultiMap.end(), [](const std::pair<int, std::string> &Multi) {
        std::cout << std::setw(16) << std::right << Multi.first;
        std::cout << "||" << Multi.second << std::endl;
    });
    std::cout << std::endl;


    auto iter = MultiMap.find(3);
    MultiMap.erase(iter);
    std::cout << std::setw(16) << std::right << "Key";
    std::cout << "||Value" << std::endl;
    std::for_each(MultiMap.begin(), MultiMap.end(), [](const std::pair<int, std::string> &Multi) {
        std::cout << std::setw(16) << std::right << Multi.first;
        std::cout << "||" << Multi.second << std::endl;
    });
    std::cout << std::endl;

    std::cout << "Map:" << std::endl;
    std::map<int, std::string> SortedMap;

    iter = MultiMap.begin();
    for (int i = 0; i < MultiMap.size(); i++) {
        SortedMap.insert(std::map<int, std::string>::value_type(iter->first, iter->second));
        iter++;
    }
    std::cout << std::setw(16) << std::right << "Key";
    std::cout << "||Value" << std::endl;
    std::for_each(SortedMap.begin(), SortedMap.end(), [](const std::pair<int, std::string> &Multi) {
        std::cout << std::setw(16) << std::right << Multi.first;
        std::cout << "||" << Multi.second << std::endl;
    });
    std::cout << std::endl;


    int NumOfElementsIn0_5 = std::count_if(SortedMap.begin(), SortedMap.end(),
                                           [](const std::pair<int, std::string> &MapIter) {
                                               return ((MapIter.first >= 0) && (MapIter.first <= 5));
                                           });
    std::cout << "Number of elements which keys are more or equal than 0 and less or equal than 5 = "
              << NumOfElementsIn0_5 << std::endl;
    std::cout << std::endl;

    std::cout << "Vector:" << std::endl;
    std::vector<int> Vector(SortedMap.size());
    auto ItVector = Vector.begin();

    std::transform(SortedMap.begin(), SortedMap.end(), ItVector, [](const std::pair<int, std::string> &MapIter) {
        return MapIter.first;
    });
    std::for_each(Vector.begin(), Vector.end(), [](const int &ValueVector) {
        std::cout << std::setw(16) << std::right << ValueVector << std::endl;
    });
    std::cout << std::endl;


    std::for_each(Vector.begin(), Vector.end(), [](int &ValueVector) {
        if (ValueVector < 0) ValueVector = 0;
    });
    std::for_each(Vector.begin(), Vector.end(), [](const int &ValueVector) {
        std::cout << std::setw(16) << std::right << ValueVector << std::endl;
    });
    std::cout << std::endl;


    std::sort(Vector.begin(), Vector.end(), std::greater<>());
    std::for_each(Vector.begin(), Vector.end(), [](const int &ValueVector) {
        std::cout << std::setw(16) << std::right << ValueVector << std::endl;
    });
    std::cout << std::endl;

    std::cout<<"Set:"<<std::endl;
    std::set<int> Set;

    ItVector=Vector.begin();
    for (int i=0; i<Vector.size(); i++){
        Set.insert(*ItVector);
        ItVector++;
    }
    std::for_each(Set.begin(), Set.end(), [](const int &SetValue) {
        std::cout << std::setw(16) << std::right << SetValue << std::endl;
    });
    std::cout << std::endl;

    return 0;
}