#include<iostream>
#include<time.h>
#include<string>
#include<vector>
#include<memory>

namespace rbtree
{

using tKeyVal = std::pair<std::string, uint16_t>;
struct node {
  tKeyVal keyVal;
	uint8_t mColor = 'r';
	std::shared_ptr<node> left = nullptr, right = nullptr;

  node(tKeyVal _keyVal){
    keyVal = _keyVal;
  }
};

class rbTree {

private:
std::shared_ptr<node> root;
public:

  rbTree():root(nullptr){

  }

  void BalanceRb(node *cNode) {

    if (root == nullptr){
      root = cNode;
      root->mColor = 'b';
    }

    if (cNode->mColor == 'r')
    {
      if (cNode->parent->mColor == 'r')
      {
        std::shared_ptr<node> sibling = (cNode->parent->parent->left == cNode->parent) ? cNode->parent->parent->right ? cNode->parent->parent->left;
        if(cNode->parent->parent->sibling->mColor == 'r')
        {
          //recolor mechanism
          cNode->parent->parent->sibling->mColor = cNode->parent->mColor = 'b';
        }
        else
        {
          //rotation mechanism
          bool isRootUpdated = false;
          std::shared_ptr<node> subRootPtr = (cNode->parent->parent->parent->left == recordGrandParent) ?
                          cNode->parent->parent->parent->left : cNode->parent->parent->parent->right;
          std::shared_ptr<node> subRootParent = cNode->parent->parent->parent;
          //left-left
          if (cNode == cNode->parent->left && cNode->parent == cNode->parent->parent->left)
          {
            recordSibling = cNode->parent->right;
            subRootPtr = cNode->parent;
            subRootPtr->right = cNode->parent->parent;
            subRootPtr->right->left = recordSibling;
            subRootPtr->right->left->parent = subRootPtr->right;
            cNode->mColor = 'b';
          } 
          //left-right
          else if (cNode == cNode->parent->right && cNode->parent == cNode->parent->parent->left)
          {
            recordChildLeft = cNode->left;
            recordChildRight = cNode->right;
            subRootPtr = cNode;
            cNode->left = cNode->parent;
            cNode->parent->right = recordChildLeft;
            cNode->parent->right->parent = cNode->parent;
            cNode->right = cNode->parent->parent;
            cNode->right->left = recordChildRight;
            cNode->right->left->parent = cNode->right;
            cNode->left->mColor = 'b';
          }
          //right-right
          else if (cNode == cNode->parent->right && cNode->parent == cNode->parent->parent->right)
          {
            recordSibling = cNode->parent->left;
            subRootPtr = cNode->parent;
            subRootPtr->left = cNode->parent->parent;
            subRootPtr->left->right = recordSibling;
            subRootPtr->left->right->parent = subRootPtr->left;
            cNode->mColor = 'b';
          } 
          //left-right
          else if (cNode == cNode->parent->left && cNode->parent == cNode->parent->parent->right)
          {
            recordChildRight = cNode->right;
            recordChildLeft = cNode->left;
            subRootPtr = cNode;
            cNode->right = cNode->parent;
            cNode->parent->left = recordChildRight;
            cNode->parent->left->parent = cNode->parent;
            cNode->left = cNode->parent->parent;
            cNode->left->right = recordChildLeft;
            cNode->left->right->parent = cNode->left;
            cNode->right->mColor = 'b';
          }

          subRootPtr->mColor = 'b';
          subRootPtr->parent = subRootParent;
          subRootPtr->left->parent = subRootPtr->right->parent = subRootPtr;
        }
      }
    }
  }

  std::shared_ptr<node> addHelper(node* cNode, tKeyVal _keyVal) const {

    if(nullptr == cNode){
      return std::make_shared(new node(_keyVal));
    }

    if(cNode->keyVal.first >= _keyVal.first) {
      cNode->left = addHelper(cNode->left, _keyVal);
      BalanceRb(cNode);
    } else {
      cNode->right = addHelper(cNode->right, _keyVal);
      BalanceRb(cNode);
    }
    return cNode;
  }

  bool addNode(tKeyVal _keyVal) const{
    addHelper(root.get(), _keyVal);
  }

  //deletion like reading in level order
  bool deleteNode(uint8_t _level, uint8_t _index) const {

  }

  //return _level and _index, multiple pairs if multiple keys.
  std::vector<std::pair<uint8_t,uint8_t>> findNode(tKeyVal _search) {
  }

};

}

int main() {
  return 0;
}