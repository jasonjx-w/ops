#ifndef NODE_NODE_H_
#define NODE_NODE_H_
#include <iostream>
#include <vector>
// #include <multimap>
#include <list>

namespace ops {


class Node {
  std::string device_ = "default";
  std::string type_ = "invalid";
  std::string name_ = "unknown";

  // DataType dtype_ = DataType::DEFAULT;
  std::vector<size_t> dims_;
  // std::multimap<std::string, std::string> params_;

  std::list<Node *> in_nodes_;
  std::list<Node *> out_nodes_;
};

}

#endif
