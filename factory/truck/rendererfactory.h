
#include "renderer.h"
#include <string>
#include <map>

class RendererFactory
{
public:
    typedef IRenderer* (*CreateCallback)();
    static void RegisterRenderer(const std::string& type, CreateCallback cb);
    static void UnregisterRender(const std::string& type);
    static IRenderer* CreateRenderer(const std::string& type);

private:
    typedef std::map<std::string, CreateCallback> CallbackMap;
    static CallbackMap mRenderers;
};
