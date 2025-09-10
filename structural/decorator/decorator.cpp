#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Component {
public:
  ~Component() {}
  virtual void Execute(std::string message) = 0;
};

class ConcreteComponent : public Component {
public:
  void Execute(std::string message) override {
    cout << "Concrete Component logged: " << message.c_str() << endl;
  }
};

class BaseDecorator : public Component {
protected:
  unique_ptr<Component> wrappee;
public:
  ~BaseDecorator() {}
  BaseDecorator(unique_ptr<Component> wrappee_)
    : wrappee(std::move(wrappee_)) {}
  virtual void Execute(std::string message) {
    this->wrappee->Execute(message);
  }
};

class FirstDecorator : public BaseDecorator {
private:
  void ExtraBehavior() {
    cout << "First Decorator said hello" << endl;
  }
public:
  FirstDecorator(unique_ptr<Component> wrappee_)
    : BaseDecorator(std::move(wrappee_)){}
  
  void Execute(std::string message) override {
    this->ExtraBehavior();
    this->wrappee->Execute(message);
  }
};

class SecondDecorator : public BaseDecorator {
private:
  void ExtraBehavior() {
    cout << "Second Decorator said hello" << endl;
  }
public:
  SecondDecorator(unique_ptr<Component> wrappee_)
    : BaseDecorator(std::move(wrappee_)){}
  
  void Execute(std::string message) override {
    this->wrappee->Execute(message);
    this->ExtraBehavior();
  }
};

void ClientCode(Component* component) {
  component->Execute("Client has called a component");
  cout << '\n' << endl;
}

int main() {
  auto simple = make_unique<ConcreteComponent>();
  ClientCode(simple.get()); // unique_ptr.get returns the raw pointer

  auto decorator1 = make_unique<FirstDecorator>(std::move(simple));
  auto decorator2 = make_unique<SecondDecorator>(std::move(decorator1));

  ClientCode(decorator2.get());

  return 0;
}
