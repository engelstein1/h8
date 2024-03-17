#include <string>
#include <iostream>
#include <vector>

class Tool {
public:
    Tool(std::string name ="");
    virtual ~Tool();
    void malfunction();
    void repair();
    virtual void function() = 0;

protected:
    std::string m_name;
    bool m_state; 
};


class LaserCutter : public Tool
{
public:
    LaserCutter(std::string const &name, bool &status);
    ~LaserCutter();
    void function() override;
private:
    std::string m_name;
    bool m_state;
};

class Disruptor : public Tool
{
public:
    Disruptor(std::string const &name, bool &status);
    ~Disruptor();
    void function() override;
private:
    std::string m_name;
    bool m_state;
};

class Replicator : public Tool
{
public:
    Replicator(std::string const &name, bool &status);
    ~Replicator();
    void function() override;
private:
    std::string m_name;
    bool m_state;    
};

class StaticBrush : public Tool
{
public:
    StaticBrush(std::string const &name, bool &status);
    ~StaticBrush();
    void function() override;
private:
    std::string m_name;
    bool m_state;
};



