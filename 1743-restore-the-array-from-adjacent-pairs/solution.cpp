#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

class Solution 
{
public:
    std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs) 
    {
        std::unordered_map<int, std::vector<int>> adjacencyMap;
        std::vector<int> nums;

        for (const auto& pair : adjacentPairs) 
        {
            adjacencyMap[pair[0]].push_back(pair[1]);
            adjacencyMap[pair[1]].push_back(pair[0]);
        }

        for (const auto& entry : adjacencyMap) 
        {
            if (entry.second.size() == 1) 
            {
                nums.push_back(entry.first);
                break;
            }
        }

        int current = nums[0];

        while (adjacencyMap[current].size() > 0) 
        {
            std::cout<<"Current: "<<current<<" Neighbors: ";
            for (std::size_t i = 0; i < adjacencyMap[current].size(); ++i) 
                std::cout<<adjacencyMap[current][i]<<" ";

            std::cout<<std::endl;

            int next = adjacencyMap[current][0];
            nums.push_back(next);

            auto& neighbors = adjacencyMap[next];

            std::cout<<"Removing "<<current<<" from neighbors of "<<next<<std::endl;

            neighbors.erase(std::remove(neighbors.begin(), neighbors.end(), current), neighbors.end());

            current = next;
        }

        return nums;
    }
};

int main() 
{
    Solution s;
    std::vector<std::vector<int>> a = {{2, 1}, {3, 4}, {3, 2}};
    std::vector<int> result = s.restoreArray(a);

    std::cout << "Restored Array: ";
    for (int num : result) 
        std::cout << num << " ";

    std::cout << std::endl;

    return 0;
}
