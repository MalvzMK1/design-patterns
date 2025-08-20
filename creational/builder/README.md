# 🧱 Builder Pattern

The **Builder Pattern** is a **creational design pattern** that lets you construct **complex objects step by step**.
It separates the construction process from the final representation, allowing the same construction process to create different representations.

---

## ❌ Problem

Creating objects with many optional parameters or complex assembly steps often leads to:

- Long, unreadable constructors (telescoping constructors).
- Repeated construction logic scattered across the codebase.
- Multiple representations of the same product built in similar but slightly different ways.

Example pain point:

```python
# Hard to read and maintain
report = Report(title="Q2", has_cover=True, has_summary=False, format="pdf", include_charts=True)
```

---

## ✅ Solution

The **Builder Pattern** encapsulates the construction of a complex object behind a **Builder interface** with clear steps.

- A **Director** (optional) defines the order of construction steps.
- **Concrete Builders** implement the steps to build different representations.
- The **Client** uses the builder (with or without a director) and retrieves the finished product at the end.

Benefits:

- Clear, readable, step-by-step construction.
- Same process can create different outputs (e.g., HTML vs. PDF reports).
- Avoids huge constructors and duplicated assembly code.

---

## 🏗 Structure

1. **Product** — The complex object being built.
2. **Builder (interface/abstract)** — Declares building steps (e.g., `reset`, `build_part_a`, `build_part_b`).
3. **Concrete Builder** — Implements steps to assemble and track the product representation.
4. **Director (optional)** — Orchestrates calls to the builder to construct products in a specific order.
5. **Client** — Provides the builder to the director or calls the builder directly; retrieves the product.

---

## 📌 When to Use It

Use the **Builder Pattern** when:

- You need to create objects with many optional parts or configurations.
- The construction process must allow different representations of the product.
- The creation involves multiple steps that need to be reused or standardized.
- You want to avoid sprawling constructors or duplicated assembly logic.

---

## 💡 Real-World Analogy

Think of ordering a **custom burger**:

- The **Builder** is the person assembling the burger step by step (bun, patty, cheese, sauces...).
- Different **Concrete Builders** produce different styles (vegan, double, no bun, etc.).
- A **Director** (a set menu) dictates a standard order of steps for a specific burger combo.
- The **Product** is the final burger; the same process yields different results based on the builder.
