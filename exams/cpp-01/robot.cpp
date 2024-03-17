#include "robot.hpp"
#include "tool.hpp"
#include "tool.cpp"
#include <string>

HAL900::HAL900(std::string const &name = "", std::string const &model = "", std::string const &callsign = "", bool status = false,std::vector<Tool> &tool)
    : m_name(name)
    ,m_model(model)
    , m_callsignID(callsign)
    , m_status(status)
    ,m_tool(tool) {}

Tachikomas::Tachikomas(std::string const &name = "", std::string const &model = "Tachikomas", std::string const &callsign = "", bool status = false,std::vector<Tool> &tool)
    : m_name(name)
    ,m_model(model)
    , m_callsignID(callsign)
    , m_status(status)
    ,m_tool(tool) {}


Johnny5::Johnny5(std::string const &name = "", std::string const &model = "Johnny5", std::string const &callsign = "", bool status = false,std::vector<Tool> &tool)
    : m_name(name)
    ,m_model(model)
    , m_callsignID(callsign)
    , m_status(status)
    ,m_tool(tool) {}

Machinenmensch::Machinenmensch(std::string const &name = "", std::string const &model = "Machinenmensch", std::string const &callsign = "", bool status = false,std::vector<Tool> &tool)
    : m_name(name)
    ,m_model(model)
    , m_callsignID(callsign)
    , m_status(status)
    ,m_tool(tool) {}