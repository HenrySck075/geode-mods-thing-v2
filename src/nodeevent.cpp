#include <Geode/Geode.hpp>
#include <algorithm>
#include "../include/event.hpp"

using namespace geode::prelude;



#include <Geode/modify/CCNode.hpp>
class $modify(CCNode) {
  struct Fields {
    CCArrayExt<CCNode*> addedNodes = {};
    CCArrayExt<CCNode*> removedNodes = {};
    CCArrayExt<CCNode*> movedNodes = {};
  };
  void addChild(CCNode *child) {
    CCNode::addChild(child);
    if (std::find(
          m_fields->removedNodes.begin(), 
          m_fields->removedNodes.end(),
          child
       )!=m_fields->removedNodes.end()) {
      m_fields->movedNodes.push_back(child);
      std::remove(m_fields->removedNodes.begin(), m_fields->removedNodes.end(), child); // shut up
    } else {
      m_fields->addedNodes.push_back(child);
    }
  }
  void removeChild(CCNode *child) {
    CCNode::removeChild(child);
    m_fields->removedNodes.push_back(child);
  }
  // atleast call CCNode::update pls thanks you will get your node in the list :)
  void update(float fDelta) {
#define $amogu(l) m_fields->l
#define $amogus(l) $amogu(l).size() != 0
    CCNode::update(fDelta);
    // check if all lists are not empty
    if (
      $amogus(addedNodes) &&
      $amogus(removedNodes) &&
      $amogus(movedNodes)
    ) { 
      // go 
      NodeEvents(
        $amogu(addedNodes), 
        $amogu(removedNodes),
        $amogu(movedNodes)
      ).post();
    }
#undef $amogus
#undef $amogu
  }
};
