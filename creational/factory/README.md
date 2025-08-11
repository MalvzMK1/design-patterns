# 🏭 Factory Pattern

The **Factory Pattern** is a **creational design pattern** that encapsulates object creation, making your code **more flexible, reusable, and maintainable**.

Instead of instantiating classes directly with their constructors, you delegate that responsibility to a **factory method or class**. This way, your client code depends on **interfaces (or abstract base classes)** instead of concrete implementations.

---

## ❌ Problem

When your code is **tightly coupled** to specific classes, introducing a new type often requires changing multiple places in your code.

Example of a direct dependency:

```python
vehicle = Sedan()
```

If you later introduce `SUV`, `Truck`, or `SportsCar`, you have to modify all places where `Sedan()` is hardcoded.

---

## ✅ Solution

The **Factory Pattern** moves the creation logic into a **separate factory function or class**, which decides which object to create.

Instead of:

```python
product = ConcreteProduct()
```

You write:

```python
product = factory.create_product("type")
```

The factory:

- Creates the object internally.
- Returns a **common interface or base class**.
- Keeps client code independent from concrete classes.

---

## 🏗 Structure

1. **Product Interface / Abstract Base Class** — Defines a contract for all products.
2. **Concrete Products** — Different implementations of the product interface.
3. **Factory** — Contains the logic to decide which concrete product to create.

---

## 📌 When to Use It

Use the **Factory Pattern** when:

- You don’t know beforehand which exact class you’ll need.
- You want to **avoid hardcoding class names** in multiple places.
- Object creation involves complex logic that should be kept in one place.
- You want your code to depend on **abstractions** rather than concrete implementations.
- You need to add new types **without modifying existing client code**.

---

## 💡 Real-World Analogy

Think of a **coffee shop**:

- You (the customer) order a drink (`"espresso"` or `"latte"`).
- The **barista (factory)** decides which machine, ingredients, and steps to use.
- You don’t care how it’s made — you just get your coffee (the product).
