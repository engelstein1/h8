#include <string>
#include <iostream>
#include <vector>

// I have two different options here, the one that is on ,
//seems to be better...

enum  ToolState {
    READY,
    MALFUNCTION
};
class Tool {
public:
    virtual ~Tool() = default;
    // virtual void useFunction() const = 0;
    virtual std::string getName() const = 0;
    virtual ToolState getState() const = 0; 
    // virtual void setState(ToolState state) const =0;
    void setState(const ToolState state) { m_state = state;}
    void use();  
protected:
    ToolState m_state;
};

class LaserCutter : public Tool
{
public:
    LaserCutter();
    // void useFunction() const override;
    std::string getName() const override {return m_name;};
    ToolState getState() const override {return m_state;};
    // void setState(ToolState state) const override;
    

private:
    std::string m_name;
    ToolState m_state;
};

class Disruptor : public Tool
{
public:
    Disruptor();
    // void useFunction() const override;
    std::string getName() const override {return m_name;};
    ToolState getState() const override {return m_state;};
    // void setState(ToolState state) const override;

private:
    std::string m_name;
    ToolState m_state;
};

class Replicator : public Tool
{
public:
    Replicator();
    // void useFunction() const override;
    std::string getName() const override {return m_name;};
    ToolState getState() const override {return m_state;};
    // void setState(ToolState state) const override;

private:
    std::string m_name;
    ToolState m_state;    
};

class StaticBrush : public Tool
{
public:
    StaticBrush();
    // void useFunction() const override;
    std::string getName() const override {return m_name;};
    ToolState getState() const override {return m_state;};
    // void setState(ToolState state) const override;

private:
    std::string m_name;
    ToolState m_state;
};



