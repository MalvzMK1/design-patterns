# 🧬 Prototype Pattern

The **Prototype Pattern** is a **creational design pattern** that lets you copy **existing objects** without making your code dependent on their concrete classes.

---

## ❌ Problem

When you need to duplicate an object, you often end up creating a new instance of the same class and manually copying every property.

Issues with this approach:

- Some objects have **private/internal state** you can’t access safely.
- Client code becomes **dependent on concrete classes** just to clone them.
- It’s brittle if you only know the object’s **interface**, not its implementation.

---

## ✅ Solution

Define a `clone()` method on the object itself. Classes that implement `clone()` are called **prototypes**. The object knows how to create a **correct copy** of itself (including private state when the language allows it).

You can also keep a set of preconfigured prototypes and clone them whenever needed, instead of constructing objects from scratch.

### Prototype Registry

A simple registry maintains frequently used prototypes and returns clones on demand.

- Simple form: a hashmap of `name -> prototype`.
- If you need more complex lookup, implement a richer search mechanism.

---

## 🏗 Structure

1. **Prototype (interface/abstract)** — Declares the `clone()` method.
2. **Concrete Prototype** — Implements `clone()` to return a full copy of itself.
3. **Client** — Works with objects via the prototype interface and asks them to clone themselves.

---

## 📌 When to Use It

Use the **Prototype Pattern** when:

- Your code shouldn’t depend on the concrete class of objects you need to copy (e.g., third‑party objects).
- Creating an object is expensive, and cloning a preconfigured instance is faster.
- You need copies of objects with **private state** that the object itself can replicate correctly.

---

## 💡 Real-World Analogy

Think of **mitotic cell division**: the original cell acts like a prototype and clones itself to produce an identical cell.

