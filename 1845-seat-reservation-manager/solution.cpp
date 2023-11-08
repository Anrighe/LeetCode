#include <vector>
#include <queue>

class SeatManager 
{
    public:
        std::priority_queue<int, std::vector<int>, std::greater<int>> available_seats;

        SeatManager(int n) 
        {
            for (std::size_t i = 1; i <= n; ++i)
                available_seats.push(i);
        }
        
        int reserve() 
        {
            int reserved = available_seats.top();
            available_seats.pop();
            return reserved;
        }
        
        void unreserve(int seatNumber) 
        {
            available_seats.push(seatNumber);
        }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */