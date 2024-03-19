#include "tool.hpp"

#include <string>
#include <vector>
class Tool;

enum RobotState
{
    ACTIVE,
    REBOOTING,
    WORKING,
    FAILING
};

class Robot
{

public:
    virtual ~Robot() = default;
    virtual void active() = 0;
    virtual void reboot() = 0;
    virtual void working() = 0;
    virtual void failing() = 0;

    void dispatch();
    void selfDiagnostics();
    void rebooting();
    void performWork(); 
    virtual std::string getName() const = 0;
    virtual std::string getCallsignID() const = 0;
    virtual std::string getModel() const = 0;
    virtual RobotState getState() const = 0;
    virtual std::vector<Tool *> getTools() const = 0;
    void setState(RobotState state) {
        m_state = state;
    }

protected:
    RobotState m_state;  
};

class HAL900 : public Robot
{
public:
    HAL900(std::string const &name, std::string const &callsign, RobotState status);
    void active() override;
    void reboot() override;
    void working() override;
    void failing() override;
    std::string getName() const override { return m_name; }
    std::string getCallsignID() const override { return m_callsignID; }
    std::string getModel() const { return m_model; }
    RobotState getState() const { return m_status; }
    std::vector<Tool *> getTools() const override { return m_tools; }

private:
    std::vector<Tool *> m_tools;
    std::string m_name;
    std::string m_model;
    std::string m_callsignID;
    RobotState m_status;
};

class Tachikomas : public Robot
{
public:
    Tachikomas(std::string const &name, std::string const &callsign, RobotState status);
    void active() override;
    void reboot() override;
    void working() override;
    void failing() override;
    std::string getName() const override { return m_name; }
    std::string getCallsignID() const override { return m_callsignID; }
    std::string getModel() const override { return m_model; }
    RobotState getState() const override { return m_status; }
    std::vector<Tool *> getTools() const override { return m_tools; }

private:
    std::vector<Tool *> m_tools;
    std::string m_name;
    std::string m_model;
    std::string m_callsignID;
    RobotState m_status;
};

class Johnny5 : public Robot
{
public:
    Johnny5(std::string const &name, std::string const &callsignl, RobotState status);
    void active() override;
    void reboot() override;
    void working() override;
    void failing() override;
    std::string getName() const override { return m_name; }
    std::string getCallsignID() const override { return m_callsignID; }
    std::string getModel() const override { return m_model; }
    RobotState getState() const override { return m_status; }
    std::vector<Tool *> getTools() const override { return m_tools; }

private:
    std::vector<Tool *> m_tools;
    std::string m_name;
    std::string m_model;
    std::string m_callsignID;
    RobotState m_status;
};

class Machinenmensch : public Robot
{
public:
    Machinenmensch(std::string const &name, std::string const &callsign, RobotState status);
    void active() override;
    void reboot() override;
    void working() override;
    void failing() override;
    std::string getName() const override { return m_name; }
    std::string getCallsignID() const override { return m_callsignID; }
    std::string getModel() const override { return m_model; }
    RobotState getState() const override { return m_status; }
    std::vector<Tool *> getTools() const override { return m_tools; }

private:
    std::vector<Tool *> m_tools;
    std::string m_name;
    std::string m_model;
    std::string m_callsignID;
    RobotState m_status;
};
