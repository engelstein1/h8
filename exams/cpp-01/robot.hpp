#include <string>
#include <vector>
class Tool
{
};

class Robot
{
protected:
    Robot()=default;
public:
    ~Robot() {}
    void active();
    void rebooting();
    void working();
    void failing();
};

class HAL900 : public Robot
{
public:
    HAL900(std::string const &name = "", std::string const &model = "HAL900", std::string const &callsign = "", bool status = false,std::vector<Tool> &tool);

private:
    std::vector<Tool> m_tool;
    std::string m_name;
    std::string m_model;
    std::string m_callsignID;
    bool m_status;
};

class Tachikomas : public Robot
{
public:
    Tachikomas(std::string const &name, std::string const &model = "Tachikomas", std::string const &callsign, bool status,std::vector<Tool> &tool);

private:
    std::vector<Tool> m_tool;
    std::string m_name;
    std::string m_model;
    std::string m_callsignID;
    bool m_status;
};

class Johnny5 : public Robot
{
public:
    Johnny5(std::string const &name, std::string const &model = "Johnny5", std::string const &callsign, bool status,std::vector<Tool> &tool);

private:
    std::vector<Tool> m_tool;
    std::string m_name;
    std::string m_model;
    std::string m_callsignID;
    bool m_status;
};

class Machinenmensch : public Robot
{
public:
    Machinenmensch(std::string const &name, std::string const &model = "Machinenmensch", std::string const &callsign, bool status,std::vector<Tool> &tool);

private:
    std::vector<Tool> m_tool;
    std::string m_name;
    std::string m_model;
    std::string m_callsignID;
    bool m_status;
};
