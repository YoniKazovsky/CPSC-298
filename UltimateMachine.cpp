#include <iostream>

using namespace std;


class CUltimatMachine{
  public:
    CUltimatMachine() : m_bState(false)
    {
        cout<<"CUltimateMachine constructor (ctor) called"<<endl;
    }
    ~CUltimatMachine()
    {
        cout<<"CUltimateMachine constructor (dtor) called"<<endl;
    }
    
    void displayState()
    {
        switch (m_bState) {
            case true:
                cout<<"Ultimate Machine is on"<<endl;
                break;
            case false:
                cout<<"Ultimate Machine is off"<<endl;
                break;
        }
    }
    
    void turnOn()
    {
        m_bState = true;
        displayState();
        if (true == m_bState)
        {
            m_bState = false;
        }
        displayState();
    }
  
  private:
    bool m_bState;   
};
int main()
{
    cout<<"The Ultimate Machine Simulation"<<endl;
    CUltimatMachine ultmach;
    ultmach.displayState();
    ultmach.turnOn();

    return 0;
}
