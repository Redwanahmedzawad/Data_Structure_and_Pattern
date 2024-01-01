
// COS30008, Problem Set 4, 2023

#include <iostream>
#include <string>

#include "PriorityQueue.h"

int main()
{
    using PQ = PriorityQueue<std::string, size_t>;

    std::cout << "Test Priority Queue:" << std::endl;
    
    PQ lPriorityQueue;
        
    lPriorityQueue.insert( "be.", 2 );
    lPriorityQueue.insert( "or", 7 );
    lPriorityQueue.insert( "not", 5 );
    lPriorityQueue.insert( "to", 3 );
    lPriorityQueue.insert( "be", 7 );
    lPriorityQueue.insert( "To", 10 );

    std::cout << "Fetch " << lPriorityQueue.size() << " elements:" << std::endl;
    
    std::optional<std::string> lValue1 = lPriorityQueue.front();
    
    while ( lValue1 )
    {
        std::cout << lValue1.value() << std::endl;
        
        lValue1 = lPriorityQueue.front();
    }

    std::cout << "Elements in priority queue: " << lPriorityQueue.size() << std::endl;

    lPriorityQueue.insert( "to", 2 );
    lPriorityQueue.insert( "be", 7 );
    lPriorityQueue.insert( "or", 5 );
    lPriorityQueue.insert( "not", 3 );
    lPriorityQueue.insert( "To", 7 );
    lPriorityQueue.insert( "be.", 10 );

    lPriorityQueue.update( "be.", 1 );
    
    std::cout << "Fetch " << lPriorityQueue.size() << " elements:" << std::endl;

    std::optional<std::string> lValue2 = lPriorityQueue.front();
    
    while ( lValue2 )
    {
        std::cout << lValue2.value() << std::endl;
        
        lValue2 = lPriorityQueue.front();
    }

    std::cout << "Elements in priority queue: " << lPriorityQueue.size() << std::endl;

    std::cout << "Test Priority Queue complete." << std::endl;
    
    return 0;
}
