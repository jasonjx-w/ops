#include "thrid_party/"

namespace ops {
// every op inherbit from kernel.
class Kernel {
  public:
    explicit Kernel(const Node *node);
    virtual ~Kernel();
    virtual void Forward(); 
    virtual void Backward();
}

}
