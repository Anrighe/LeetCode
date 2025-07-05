#include <unordered_map>
#include <vector>
#include <iostream>


class Solution {
public:

    /**
    * Builds a frequency map from the input vector.
    * @param arr A vector of integers
    * @return An unordered_map where each key is a number from the input vector, and the value is its count
    */
    std::unordered_map<int, int> buildFrequencyMap(std::vector<int> arr) {
        std::unordered_map<int, int> frequencyMap;
        std::vector<int>::iterator it;

        for (it = arr.begin(); it != arr.end(); ++it) {
            if (frequencyMap.contains(*it)) {
                std::cout<<"Map contains: "<<*it<<"\n";
                frequencyMap.insert({*it, frequencyMap[*it] += 1});
            } else {
                std::cout<<"Adding "<<*it<<" to the map\n";
                frequencyMap.insert({*it, 1});
            }
        }
        return frequencyMap;
    }

    /**
    * Finds "lucky numbers" in a frequency map.
    * A lucky number is defined as a number whose frequency in the array is equal to its value.
    * @param frequencyMap An unordered_map with number-frequency pairs
    * @return A vector of integers that are considered lucky numbers
    */
    std::vector<int> findLuckyNumbers(std::unordered_map<int, int> frequencyMap) {
        std::vector<int> luckyNumbers;
        for (const std::pair<int, int> &entry : frequencyMap) {
            if (entry.first == entry.second) {
                luckyNumbers.push_back(entry.first);
            }
        }
        return luckyNumbers;
    }

    /**
    * Returns the largest lucky number from the input array
    * @param arr A vector of integers
    * @return The largest lucky number, or -1 if there is no lucky number in the array
    */
    int findLucky(std::vector<int>& arr) {
        std::unordered_map<int, int> frequencyMap = buildFrequencyMap(arr);
        std::vector<int> luckyNumbers = findLuckyNumbers(frequencyMap);

        if (luckyNumbers.empty()) {
            std::cout<<"Empty!\n";
            return -1;
        }
        return *std::max_element(luckyNumbers.begin(), luckyNumbers.end());
    }
};