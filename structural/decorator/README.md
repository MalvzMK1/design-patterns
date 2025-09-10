# Decorator Pattern

## 📖 Definition

The **Decorator Pattern** is a **structural design pattern** that allows you to dynamically attach additional responsibilities to an object by placing it inside a wrapper.

Instead of relying on subclassing, decorators provide a flexible alternative for extending functionality.

---

## 🎯 Intent

> **Attach additional responsibilities to objects dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.**

---

## 📌 Motivation

Suppose you have a class that solves a problem in your system. As the system grows, you need to extend this class with more features. A straightforward approach would be creating many subclasses.

Over time:

* The number of subclasses grows uncontrollably.
* The inheritance hierarchy becomes complex and hard to maintain.
* The code gets polluted with duplicated or tangled logic.

With the **Decorator pattern**:

* You wrap the original object with a decorator.
* The decorator follows the same interface as the original object.
* The client interacts with it as if it were the original object, but with extra features added before or after delegating calls.

This keeps the design clean and avoids subclass explosion.

---

## 🏗 Structure

```
       Component <-------------------------+
          ^                                |
          |                                |
  ConcreteComponent              BaseDecorator
                                         ^
                                         |
                              ConcreteDecorator
```

* **Component**: Declares the common interface for both wrapped objects and wrappers.
* **Concrete Component**: The core object that can be wrapped.
* **Base Decorator**: Implements the component interface and stores a reference to a wrapped component.
* **Concrete Decorators**: Add new behaviors either before or after delegating calls to the wrapped object.
* **Client**: Works with components through the common interface, unaware of whether it’s using a plain component or a decorated one.

---

## ✅ Applicability

Use the Decorator Pattern when:

* You want to add responsibilities to objects dynamically, at runtime.
* Extending functionality via inheritance is awkward, impractical, or would cause class explosion.
* You want to combine multiple behaviors flexibly by stacking decorators.

---

## ⚖️ Pros and Cons

### ✔ Pros

* Extends an object’s behavior without creating new subclasses.
* Allows adding or removing responsibilities at runtime.
* Enables combining multiple behaviors through stacked decorators.
* Promotes the **Single Responsibility Principle** by splitting large classes into smaller, specialized ones.

### ❌ Cons

* Hard to remove a specific decorator from a stack of wrappers.
* The order of decorators can affect behavior, making configuration tricky.
* The initial setup code can become cluttered with multiple layers of wrapping.

