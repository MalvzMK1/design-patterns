# Flyweight Pattern

## 📖 Definition

The **Flyweight Pattern** is a **structural design pattern** that minimizes memory usage by sharing common, immutable parts of objects between multiple instances, instead of storing them redundantly in each object.

---

## 🎯 Intent

> **Use sharing to efficiently support a large number of fine-grained objects.**

---

## 📌 Motivation

Imagine you are building a realistic FPS game with thousands of particles for visual effects.

Each particle has:

* **Intrinsic state** (shared data): color, texture, brightness.
* **Extrinsic state** (unique data): position, velocity, direction.

Without the Flyweight pattern:

* Every particle duplicates all its properties.
* Memory usage explodes, which can degrade performance or even crash the game.

With the Flyweight pattern:

* Intrinsic state is extracted into shared `Flyweight` objects.
* Only the extrinsic state is stored individually.
* Thousands of particles can reuse the same shared data, drastically reducing memory consumption.

---

## 🏗 Structure

```
             +----------------+
             |   Flyweight    |<--------------+
             +----------------+               |
                     ^                        |
          +--------------------+              |
          | ConcreteFlyweight  |              |
          +--------------------+              |
                     ^                        |
             +----------------+               |
             | FlyweightFactory|              |
             +----------------+               |
                     ^                        |
                     |                        |
             +----------------+               |
             |     Client     |---------------+
             +----------------+
```

* **Flyweight**: Declares an interface for shared objects.
* **ConcreteFlyweight**: Implements the flyweight interface and stores the intrinsic (shared) state.
* **Flyweight Factory**: Manages flyweight objects and ensures that existing ones are reused instead of creating duplicates.
* **Context**: Holds extrinsic (unique) state that cannot be shared.
* **Client**: Uses flyweights by combining intrinsic and extrinsic states.

---

## ✅ Applicability

Use the Flyweight Pattern when:

* Your program needs to create **a huge number of similar objects** that would otherwise consume too much RAM.
* Most object states can be **factored into shared data**.
* Objects are **short-lived or frequently created/destroyed**.

---

## ⚖️ Pros and Cons

### ✔ Pros

* **Massive memory savings** when dealing with large numbers of objects.
* Centralized management of shared state makes updates consistent.

### ❌ Cons

* Increases **CPU usage** due to managing extrinsic state at runtime.
* Makes code more complex and harder for new developers to understand.
* Best suited only when memory savings outweigh the added complexity.

