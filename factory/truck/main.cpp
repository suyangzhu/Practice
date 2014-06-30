#include <iostream>
#include "rendererfactory.h"

using namespace std;

int main()
{
    //Register a new renderer
    RendererFactory::RegisterRenderer("user", UserRenderer::Create);

    //create an instance of our new renderer
    IRenderer* render = RendererFactory::CreateRenderer("user");
    render->Render();
    delete render; //Remember to release the resources on heap.

    return 0;
}
