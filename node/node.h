
namespace ops {

enum NodeType {
    SOURCE,  //  子图起始卫兵
    SINK,    //  子图终止卫兵
    LOAD,    //  获取数据, 其中保存数据来源, 如文件或地址, 可用于连接子图或从磁盘读取数据
    STORE,   //  写入数据, 将数据保存至某文件或地址
    PRINT,   //  打印数据

}

class Node {
    Device device_ = Device::DEFAULT;
    NodeType type_ = NodeType::INVALID;
    std::string name_ = "unknown";

    std::vector<size_t> dims_;
    DataType dtype_ = DataType::DEFAULT;
    std::multimap<std::string, std::string> params_;

    std::list<Node *> in_nodes_;
    std::list<Node *> out_nodes_;
}

}
