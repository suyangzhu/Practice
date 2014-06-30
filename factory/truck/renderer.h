#include <iostream>
#include <string>

class IRenderer
{
public:
    virtual void Render()=0;
    virtual ~IRenderer()
    {
        std::cout<< "delete IRenderer object."<<std::endl;
    }
};

class UserRenderer:public IRenderer
{
public:
    ~UserRenderer() 
    {
        std::cout<< "delete UserRenderer object."<<std::endl;
    }
    bool LoadScene(const std::string &filename) 
    { 
        return true; 
    }

    void SetViewportSize(int w, int h) {}
    void SetCameraPosition(double x, double y, double z) {}
    void SetLookAt(double x, double y, double z) {}
    void Render() 
    { 
        std::cout << "User Render" << std::endl; 
    }
    
    static IRenderer* Create() 
    { 
        return new UserRenderer(); //Pay attention: this method must be static.
    }
    
};


