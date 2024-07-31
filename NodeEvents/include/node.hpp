#include <Geode/Geode.hpp> 
#include <optional>

using namespace geode::prelude;

#define $toNode(n) Node::create(n)
#define $toNodeFromObject(n) $toNode(static_cast<CCNode*>(n))

namespace dom {
  class NodeList;
  class Node : public CCObject {
  private:
    CCNode* m_node;
    const std::string m_NodeName;

    std::optional<std::string> m_value = std::nullopt;
  public:
    operator CCNode*() {return m_node;}
    // hopefully it work :plead:
    Node(CCNode* node) : m_node(node) {};
    static Node* create(CCNode* data) {
      Node* r = new Node(data);
      if (r) {
        r->autorelease();
      } else {
        delete r;
        r = nullptr;
      }
      return r;
    }
    Node* firstChild() {
      return $toNodeFromObject(m_node->getChildren()->objectAtIndex(0));
    }
    Node* lastChild() {
      auto a = m_node->getChildren();
      return $toNodeFromObject(a->objectAtIndex(a->count()-1));
    }
    // Returns a Node representing the next node in the tree, or null if there isn't such node.
    Node* nextSibling() {
      auto p = m_node->getParent();
      if (p==nullptr) return nullptr;
      auto c = p->getChildren();
      return $toNodeFromObject(c->objectAtIndex(c->indexOfObject(this)+1));
    }
    CCArrayExt<Node*> childNodes() {
      return m_node->getChildren();
    }
    std::string nodeName() {return m_NodeName;}

    std::optional<std::string> nodeValue() {return m_value;}
    Node* parentNode() {return $toNode(m_node->getParent());}
  };
}

