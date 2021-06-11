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

  std::shared_ptr<node> addHelper(node* cNode, tKeyVal _keyVal) {

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
    addHelper(root, _keyVal.first);
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