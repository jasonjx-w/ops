#include "simdjson.h"

namespace ops {

class Graph {
    std::string name_ = "unknown";
    std::vector<Node> nodes_;
  public:
    void Graph(simdjson::dom::element json);
    std::vector<Graph> Partition();
}

}
