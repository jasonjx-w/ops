#include <iostream>
#include "simdjson.h"

int main() {
  
  simdjson::dom::parser parser;
  simdjson::dom::element json = parser.load(filename);
  ops::Graph graph(json); // io node (含load,store和print)和 compute node.
  
  std::vector<ops::Graph> sub_graphs = graph.Partition();
  
  ops::Executor executor(sub_graphs);
  executor.SetUp();
  executor.Watch(sub_graphs[0]);   // 监视子图/节点运行结果
  // executor.Watch(sub_graphs[0].Find("add"));   // 监视节点运行结果
  executor.Run();  // 计算结果放回graph中输出节点
  executor.TearDown();
}