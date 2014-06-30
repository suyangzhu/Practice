#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
class IRenderer {
  public:
  virtual void Render () = 0;
  virtual ~IRenderer() {
    std::cout << "Delete IRenderer object " << std::endl;
  }
};

class UserRenderer : public IRenderer {
  public:
  ~UserRenderer() {
    std::cout << "Delete Userrenderer object " << std::endl;
  }

  bool LoadScene (const std::string& filename) {
    return true;
  }

  void SetViewportSize(int w, int h) {}
  void SetCameraPosition(double x, double y, double z) {}
  void SetLookAt(double x, double y, double z) {}

  void Render() {
    std::cout << "User Render" << std::endl;
  }

  static IRenderer* Create() {
    return new UserRenderer(); // this function must be static
  }
};

// Render factory. I put everything together to reduce number 
// of files.
//

class RendererFactory {
  public:
  typedef IRenderer* (*CreateCallBack)();
  static void RegisterRenderer(const std::string& type, CreateCallBack cb){ mRenderers[type] = cb;}
  static void UnregisterRender(const std::string& type) {mRenderers.erase(type);}
  static IRenderer* CreateRenderer(const std::string& type) {
    CallbackMap::iterator it = mRenderers.find(type);
    if (it != mRenderers.end()) {
      return it->second();
    }
    return NULL;
  }
  
  private:
  typedef std::map<std::string, CreateCallBack> CallbackMap;
  static CallbackMap mRenderers;
};

int main() {
  // Register a new renderer
  RendererFactory::RegisterRenderer("user", UserRenderer::Create);

  IRenderer* render = RendererFactory::CreateRenderer("user");
  render->Render();
  delete render;
  return 0;
}











