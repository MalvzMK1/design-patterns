# Bridge Pattern

## 📖 Definition

The **Bridge Pattern** is a **structural design pattern** that decouples an abstraction from its implementation so that both can evolve independently.

Instead of creating a large hierarchy of classes for every possible combination of abstraction and implementation, the Bridge pattern separates them into two different hierarchies, connected by a composition (the "bridge").

---

## 🎯 Intent

> **Decouple an abstraction from its implementation so that the two can vary independently.**

---

## 📌 Motivation

Suppose you are building a drawing application:

* You have shapes (abstractions) such as `Circle`, `Square`, `Triangle`.
* You have rendering APIs (implementations) such as `SVGRenderer` and `CanvasRenderer`.

Without the Bridge pattern, you would need a class for each combination:

* `CircleSvg`, `CircleCanvas`, `SquareSvg`, `SquareCanvas`, …

With the Bridge pattern:

* Shapes (`Circle`, `Square`) hold a reference to a `Renderer`.
* Renderers (`SVGRenderer`, `CanvasRenderer`) define the implementation details.

This way, you avoid **class explosion** and keep the design flexible.

---

## 🏗 Structure

```
          Abstraction ------------------> Implementor
               |                              |
       RefinedAbstraction            ConcreteImplementorA
                                     ConcreteImplementorB
```

* **Abstraction**: Defines the high-level control interface and contains a reference to the Implementor.
* **Implementor**: Declares the interface for implementation classes.
* **RefinedAbstraction**: Extends the Abstraction with more specific behaviors.
* **ConcreteImplementor**: Provides the actual implementation.

---

## ✅ Applicability

Use the Bridge Pattern when:

* You need to avoid a permanent binding between an abstraction and its implementation.
* You want to combine different abstractions with different implementations without creating a large class hierarchy.
* You want to switch implementations at runtime.

---

## ⚖️ Pros and Cons

### ✔ Pros

* Decouples abstraction from implementation.
* Reduces class explosion.
* Improves flexibility by allowing abstraction and implementation to vary independently.

### ❌ Cons

* Increases complexity by introducing more layers.

