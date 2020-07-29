
// for cpu and gpu.
class Executor {
  public:
    void Init(const Graph *graph) {}
    void SetUp() {}  // set up env, choose op to run
    void TearDown() {}  // tear down env
    void Run() {}  // 
  private:
    std::vector<Node> nodes_;
    std::queue<Kernel> kernels_;
}

// set up cpu run env.
// and run whatever op
class CPUExecutor : public Executor {

}

// set up gpu run env.
// and run whatever op
class GPUExecutor : public Executor {
}
