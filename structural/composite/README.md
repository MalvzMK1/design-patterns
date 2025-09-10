# Composite Pattern

## 📖 Definition

The **Composite Pattern** is a **structural design pattern** that lets you treat individual objects and compositions of objects uniformly.

It organizes objects into tree structures, where both **leaf nodes** (individual objects) and **composite nodes** (groups of objects) implement the same interface.

---

## 🎯 Intent

> **Compose objects into tree structures to represent part-whole hierarchies. Allow clients to treat individual objects and compositions of objects uniformly.**

---

## 📌 Motivation

Suppose you are building a graphical editor:

* You have simple shapes such as `Circle` and `Rectangle`.
* You also want to group shapes together into a `Group`.

Without the Composite pattern:

* You would need special logic for handling groups versus single shapes.
* Client code would become more complex, checking if an object is a single shape or a collection.

With the Composite pattern:

* Both `Circle` and `Group` implement the same interface, for example `draw()`.
* A `Group` can contain circles, rectangles, or even other groups.
* The client simply calls `draw()` without worrying whether it is dealing with a single object or a group.

This way, you simplify client code and make your system more flexible.

---

## 🏗 Structure

```
                   Component
                   /      \
              Leaf          Composite
                                |
                           (children: Component[])
```

* **Component**: Declares the interface for both simple and complex objects.
* **Leaf**: Represents a simple element in the structure (no children).
* **Composite**: Represents complex elements that can have children (other Components).
* **Client**: Works with objects through the Component interface, treating leaves and composites uniformly.

---

## ✅ Applicability

Use the Composite Pattern when:

* You want to represent part-whole hierarchies of objects.
* You want clients to treat individual objects and groups of objects in the same way.
* You need to work with recursive structures like trees.

---

## ⚖️ Pros and Cons

### ✔ Pros

* Simplifies client code by treating all objects uniformly.
* Makes it easier to add new kinds of components (open/closed principle).
* Naturally supports recursive structures like trees and hierarchies.

### ❌ Cons

* Can make the design overly general, since it’s not always clear which classes are composites and which are leaves.
* May lead to unexpected behaviors if clients treat composites as simple objects without realizing the recursive nature.

