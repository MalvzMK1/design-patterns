# Singleton

**Singleton** is a **creational design pattern** that ensures a class has only one instance while providing a global access to this instance.

---

# 🔒 Singleton Pattern

The **Singleton Pattern** ensures a class has **only one instance** and provides **global access** to it.

---

## ❌ Problem

Singleton addresses two common needs:

1) Ensure there is only a single instance of a class.
- Example: a file manager or configuration manager where multiple instances could conflict.

2) Provide a single, globally accessible instance.
- Plain global variables are risky because any code can overwrite them.

---

## ✅ Solution

Implement the class so it controls its instantiation and exposes a single access point:

1) Hide or restrict the default constructor so external code can’t instantiate it directly.
2) Provide a static/class method (e.g., `get_instance()` / `getInstance()`) that creates the instance once and returns the same instance thereafter.

Threaded environments typically require synchronization to ensure the instance is created safely exactly once.

---

## 🏗 Structure

- The Singleton class stores a static reference to its sole instance.
- The constructor is hidden/restricted from client code.
- A static/class accessor returns the same instance on every call.

---

## 📌 When to Use It

- There must be exactly one instance for coordination across the system (e.g., logging, configuration, database connection manager).
- You need centralized, controlled access to a shared resource.

---

## 💡 Real-World Analogy

Think of a country's **official government**: there’s one legitimate governing body at a time, and everyone refers to it.

---

## 📝 Notes

- This pattern can violate the **Single Responsibility Principle** because it addresses two concerns: ensuring a single instance and providing global access.
- Be cautious in tests: singletons can hold state between tests; prefer reset hooks or dependency injection where possible.
- Consider concurrency: ensure thread-safe lazy initialization if needed.
