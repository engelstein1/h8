#include "tool.hpp"

Tool::Tool(std::string name) : m_name(name), m_state(true) {}

Tool::~Tool() {}

LaserCutter::LaserCutter(std::string const &name, bool &status)
    : m_name(name), m_state(status) {}

void LaserCutter::function()
{
    std::cout << "Using laser cutter tool " << m_name << std::endl;
}
Disruptor::Disruptor(std::string const &name, bool &status)
    : m_name(name), m_state(status) {}

void Disruptor::function()
{
    std::cout << "Using laser cutter tool " << m_name << std::endl;
}

Replicator::Replicator(std::string const &name, bool &status)
    : m_name(name), m_state(status) {}

void Replicator::function()
{
    std::cout << "Using laser cutter tool " << m_name << std::endl;
}

StaticBrush::StaticBrush(std::string const &name, bool &status)
    : m_name(name), m_state(status) {}

void StaticBrush::function()
{
    std::cout << "Using laser cutter tool " << m_name << std::endl;
}

void Tool::malfunction()
{
    if (rand() % 10 < 2)
    {
        m_state = false;
        std::cout << "state:MALFUNCTION" << std::endl;

    }
}

void Tool::repair()
{
    m_state = true;
    std::cout << "state:READY" << std::endl;
}