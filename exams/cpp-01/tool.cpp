#include "tool.hpp"

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>

// I have two different options here, the one that is on ,
//seems to be better...
void Tool::use()  
{  
    double successProbability = rand() / static_cast<double>(RAND_MAX);
    if (successProbability <= 0.8)
    {
        setState(ToolState::MALFUNCTION);
    } else
    {
        setState(ToolState::READY);
    }
    std::cout << "Using tool : " << getName() << std::endl;
}

// void LaserCutter::setState(ToolState state) const {
//     ToolState currentstate = getState();
//     if (currentstate!= state) {
//         setState(state)
//     ;} 
// };

// void Disruptor::setState(ToolState state) const {
//     ToolState currentstate = getState();
//     if (currentstate!= state) {
//         setState(state)
//     ;} 
// };

// void Replicator::setState(ToolState state) const {
//     ToolState currentstate = getState();
//     if (currentstate!= state) {
//         setState(state)
//     ;} 
// };

// void StaticBrush::setState(ToolState state) const {
//     ToolState currentstate = getState();
//     if (currentstate!= state) {
//         setState(state)
//     ;} 
// };



LaserCutter::LaserCutter()
    : Tool()
    , m_name("LaserCutter")
    , m_state(ToolState::READY) {}
    
    
// void LaserCutter::useFunction() const
// {  
//     double successProbability = rand() / static_cast<double>(RAND_MAX);
//     if (successProbability <= 0.8)
//     {
//         setState(ToolState::MALFUNCTION);
//     } else
//     {
//         setState(ToolState::READY);
//     }
//     std::cout << "Using tool : " << getName() << std::endl;
// }
Disruptor::Disruptor()  
    : 
     m_name("Disruptor")
    , m_state(ToolState::READY) {}

// void Disruptor::useFunction() const
// {
//     double successProbability = rand() / static_cast<double>(RAND_MAX);
//     if (successProbability <= 0.8)
//     {setState(ToolState::MALFUNCTION);
//     } else
//     {
//         setState(ToolState::READY);
//     }
//     std::cout << "Using laser cutter tool " << m_name << std::endl;
// }

Replicator::Replicator() 
    : Tool()
    , m_name("Replicator")
    , m_state(ToolState::READY) {}

// void Replicator::useFunction() const
// {
//     double successProbability = rand() / static_cast<double>(RAND_MAX);
//     if (successProbability <= 0.8)
//     {setState(ToolState::MALFUNCTION);
//     } else
//     {
//         setState(ToolState::READY);
//     }    
//     std::cout << "Using laser cutter tool " << m_name << std::endl;
// }

StaticBrush::StaticBrush()
    : Tool()
    , m_name("StaticBrush")
    , m_state(ToolState::READY) {}

// void StaticBrush::useFunction() const
// {
//     double successProbability = rand() / static_cast<double>(RAND_MAX);
//     if (successProbability <= 0.8)
//     {setState(ToolState::MALFUNCTION);
//     } else
//     {
//         setState(ToolState::READY);
//     }    
//     std::cout << "Using laser cutter tool " << m_name << std::endl;
// }

// void Tool::malfunction()
// {
//     if (rand() % 10 < 2)
//     {
//         m_state = false;
//         std::cout << "state:MALFUNCTION" << std::endl;

//     }
// }

// void Tool::repair()
// {
//     m_state = true;
//     std::cout << "state:READY" << std::endl;
// }