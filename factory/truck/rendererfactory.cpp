#include "rendererfactory.h"

RendererFactory::CallbackMap RendererFactory::mRenderers;

void RendererFactory::RegisterRenderer(const std::string &type, RendererFactory::CreateCallback cb)
{
    mRenderers[type] = cb;
}

void RendererFactory::UnregisterRender(const std::string &type)
{
    mRenderers.erase(type);
}

IRenderer* RendererFactory::CreateRenderer(const std::string &type)
{
    CallbackMap::iterator it = mRenderers.find(type);
    if(it!=mRenderers.end())
    {
        return (it->second)();
    }
    return NULL;
}
