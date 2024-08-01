#include "Geode/utils/cocos.hpp"
#include "node.hpp"
#include <Geode/cocos/include/cocos2d.h>

using namespace cocos2d;
namespace dom {
  class NodeList {
  private:
    Ref<CCArray> m_arr;
  public:
    NodeList(CCArray* a) : m_arr(a) {};
  };
}
