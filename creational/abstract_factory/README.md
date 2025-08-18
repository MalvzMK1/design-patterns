# 🎨 Abstract Factory Pattern

The **Abstract Factory Pattern** is a **creational design pattern** that provides an interface for creating **families of related or dependent objects** without specifying their concrete classes. It's like a factory that creates other factories.

This pattern helps you manage the creation of objects that belong together, ensuring that the products from one factory are compatible with each other.

---

## ❌ Problem

Imagine you're building an application that needs to support multiple UI themes (e.g., Light Mode and Dark Mode). Each theme has its own set of components: buttons, checkboxes, and windows.

If you create these components directly, your code becomes tightly coupled to the concrete classes of a specific theme:

```python
# Tightly coupled to Light theme components
button = LightButton()
checkbox = LightCheckbox()
```

Switching to a Dark Mode would require changing every single instantiation. Furthermore, there’s no guarantee that you won’t accidentally mix components, like using a `LightButton` with a `DarkCheckbox`, leading to an inconsistent UI.

---

## ✅ Solution

The **Abstract Factory Pattern** solves this by defining an interface (`GUIFactory`) for creating a family of related products (e.g., `create_button`, `create_checkbox`).

Then, you create concrete factory classes (`LightFactory`, `DarkFactory`) that implement this interface. Each factory is responsible for creating components for a specific theme.

Your client code works with the factories and products through their **abstract interfaces**:

```python
# The client code doesn't know which factory it's getting
factory = get_factory_for_current_theme()

# It uses the factory to create a consistent family of products
button = factory.create_button()
checkbox = factory.create_checkbox()
```

This way:
- The client code is decoupled from concrete product classes.
- You can easily switch between product families (themes) by changing the factory instance.
- It guarantees that products created by a factory are compatible with each other.

---

## 🏗 Structure

1.  **Abstract Product** — Defines an interface for a type of product (e.g., `Button`, `Checkbox`).
2.  **Concrete Product** — Implements the abstract product interface for a specific variant (e.g., `LightButton`, `DarkButton`).
3.  **Abstract Factory** — Declares a set of methods for creating abstract products (e.g., `create_button()`, `create_checkbox()`).
4.  **Concrete Factory** — Implements the creation methods of the abstract factory to produce a family of concrete products (e.g., `LightFactory` creates `LightButton` and `LightCheckbox`).
5.  **Client** — Uses only the abstract factory and abstract product interfaces.

---

## 📌 When to Use It

Use the **Abstract Factory Pattern** when:

- Your system needs to be independent of how its products are created, composed, and represented.
- You need to create **families of related objects** (e.g., UI components for a specific theme).
- You want to enforce that products from the same family are used together.
- You want to provide a library of products but only reveal their interfaces, not their implementations.

---

## 💡 Real-World Analogy

Think of an **IKEA furniture series** (e.g., "Poäng" or "Malm").

- Each series is an **Abstract Factory** for a family of matching furniture.
- The specific series you choose (Poäng) is a **Concrete Factory**.
- It creates products that belong together: a Poäng armchair, a Poäng footstool, etc. (the **Concrete Products**).
- You don't mix a Poäng armchair with a Malm dresser if you want a consistent style. The factory ensures you get a matching set.
