#include <Geode/Geode.hpp>

using namespace geode::prelude;

class NodeEvents : public Event {
public:
  CCArrayExt<CCNode*> addedNodes;
  CCArrayExt<CCNode*> removedNodes;
  CCArrayExt<CCNode*> movedNodes;

  NodeEvents(
      CCArrayExt<CCNode*> const& added,
      CCArrayExt<CCNode*> const& removed,
      CCArrayExt<CCNode*> const& moved
  ) :
    addedNodes(added),
    removedNodes(removed),
    movedNodes(moved)
    {};
};
