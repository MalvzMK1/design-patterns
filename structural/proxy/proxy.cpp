#include <iostream>
#include <memory>

class CommonInterface {
public:
  virtual void doSomething() = 0;
  virtual ~CommonInterface() {}
};

class HighDemandClass : public CommonInterface {
public:
  void doSomething() override {
    std::cout << "Heavy class made something" << std::endl;
  }
};

class HighDemandClassProxy : public CommonInterface {
private:
  std::unique_ptr<CommonInterface> service_;
  void customBehavior() {
    std::cout << "The proxy make something" << std::endl;
  }
public:
  void doSomething() override {
    if (service_ == 0) {
      service_ = std::make_unique<HighDemandClass>();
    }

    customBehavior();
    service_->doSomething();
  }
};

void clientCode(std::unique_ptr<CommonInterface> service) {
  std::cout << "Client will use the service\nService address: " << service.get() << std::endl;
  service->doSomething();
  std::cout << "Client has called the service.\n" << std::endl;
}

int main() {
  auto originalService = std::make_unique<HighDemandClass>();
  auto proxy = std::make_unique<HighDemandClassProxy>();

  clientCode(std::move(originalService));
  clientCode(std::move(proxy));

  return 0;
}
