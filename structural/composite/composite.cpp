#include <iostream>
#include <list>
#include <string>

class Component {
protected:
  Component *parent_;
public:
  virtual ~Component() {}
  void SetParent(Component *parent) {
    this->parent_ = parent;
  }
  virtual void Add(Component *component) {}
  virtual void Delete(Component *component) {}
  virtual bool IsComposite() const { return false; }
  virtual std::string Process() const = 0;
};

class Leaf : public Component {
public:
  std::string Process() const override {
    return "Leaf";
  }
};

class Composite : public Component {
protected:
  std::list<Component *> children_;
public:
  bool IsComposite() {
    return true;
  }
  void Add(Component *component) override {
    this->children_.push_back(component);
    component->SetParent(this);
  }

  void Delete(Component *component) override {
    this->children_.remove(component);
    component->SetParent(nullptr);
  }

  std::string Process() const override {
    std::string result;

    for (const Component *c : this->children_) {
      result += c->Process();
    }

    return "Branch(" + result + ")";
  }
};

void print(std::string message) {
  std::cout << message << std::endl;
}

void client_code(Component* component) {
  std::string result = component->Process();
  print(result);
  print("\n\n");
}

int main() {
  auto *leaf = new Leaf();

  print("Client has called leaf");
  client_code(leaf);

  delete leaf;

  auto *root = new Composite();
  auto *branch1 = new Composite();
  auto *branch2 = new Composite();
  auto *leaf1 = new Leaf();
  auto *leaf2 = new Leaf();
  auto *leaf3 = new Leaf();

  branch1->Add(leaf1);
  branch2->Add(leaf2);
  branch2->Add(leaf3);

  root->Add(branch1);
  root->Add(branch2);

  print("Client has called composite element");
  client_code(root);

  delete leaf1;
  delete leaf2;
  delete leaf3;
  delete branch1;
  delete branch2;
  delete root;
}

