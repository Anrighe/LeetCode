#include <vector>
#include <queue>

class SeatManager 
{
    public:
        std::priority_queue<int, std::vector<int>, std::greater<int>> available_seats;


        /// @brief Constructs a SeatManager object that will manage n seats numbered from 1 to n.
        /// @param n Number of seats
        SeatManager(int n) 
        {
            for (std::size_t i = 1; i <= n; ++i)
                available_seats.push(i);
        }
        
        /// @brief Reserves the earliest available seat.
        /// @return The number of the reserved seat
        int reserve() 
        {
            int reserved = available_seats.top();
            available_seats.pop();
            return reserved;
        }
        
        /// @brief Unreserves the seat number seatNumber.
        /// @param seatNumber Number of the seat to unreserve
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