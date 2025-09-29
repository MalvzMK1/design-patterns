# Chain of Responsibility

## 📖 Definition

The **Chain of Responsibility (CoR)** is a **behavioral design pattern** that allows a request to be passed along a chain of handlers. Each handler decides whether to process the request or forward it to the next handler in the chain.

---

## Problem

Imagine you have an **authorization system** based on roles:

* A client must be **authenticated** to access any route.
* A client must be an **admin** to create a register.
* A client must be a **super admin** to perform all interactions with a register.

**Without CoR:**

* The authorization logic is centralized in one place, and every time a new rule is introduced, the code must be updated, making it rigid and harder to maintain.

**With CoR:**

* Each rule is encapsulated in a separate handler.
* Adding a new rule means adding a new handler to the chain without modifying existing code.
* The logic becomes flexible, reusable, and easier to extend.

---

## Structure

* **Handler Interface**
  Defines a common contract for all handlers. Typically includes an `execute` method to process the request and an optional `setNext` method to define the next handler in the chain.

* **Base Handler (Optional)**
  Provides default implementations for storing the next handler and forwarding requests, reducing boilerplate in concrete handlers.

* **Concrete Handler**
  Contains the actual processing logic. Each handler decides:

  * If it can process the request, handle it.
  * Otherwise, forward it to the next handler.
    Handlers are generally **immutable**, meaning they receive their configuration at construction time.

* **Client**
  Responsible for assembling the chain of handlers. This can be done statically (once at initialization) or dynamically (adjusted at runtime).

---

## Applicability

Use the CoR pattern when:

* You need to process different types of requests in various ways, and the exact processing logic is not known upfront.
* Multiple handlers must process a request in a defined order.
* You want to add, remove, or reorder request-processing logic without modifying existing code.

---

## Pros and Cons

### ✅ Pros

* Flexible control over the **order of request handling**.
* Promotes **Single Responsibility Principle (SRP)** by decoupling request senders from request processors.
* Supports **Open/Closed Principle (OCP)** — new handlers can be added without breaking existing code.

### ❌ Cons

* A request might go through the entire chain without being handled.
* Debugging can be harder since the flow is distributed across multiple handlers.
