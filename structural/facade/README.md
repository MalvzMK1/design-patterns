# Facade

## 📖 Definition

The **Facade Pattern** is a **structural design pattern** that lets you easily work with complex subsystems.

It orchestrates the whole subsystem class so the client don't need to deal with it.

---

## 🎯 Intent

> **Orchestrate the usage of a complex subsystem, providing an easy interface so the client don't need to have a deep knowledge of the subsystem's implemenetation.**

---

## 📌 Motivation

Suppose you are implemnting a complex subsystem of video converter:

* You have a lot of classes that are specific to make some step of the convertion

Without the Facade pattern:

* The client would need to have knowledge of the implementation so it can use the subsystem correctly.

With the Facade pattern:

* The client would only use the Facade instance, with an easy interface that under the hood would instance every class in the correct order and orchestrate the video conversion.

This way, the client code would be much simpler and would have less risk.

---

## 🏗 Structure

* **Facade**: Provides an easy interface to a part of the subsystem's functionality.
* **Additional Facade**: This is optional, but it's good to avoid the *Facade* class to become a god class.
* **Complex Subsystem**: The complex subsystem consists of dozens specific objects which are implemented to a specific purpose. The subsystem's objects are not aware of the Facade, they should work without the Facade's existence.
* **Client**: Should use the Facade for an easier access to the complex subsystem's functionalities.

---

## ✅ Applicability

Use the Facade Pattern when:

* You need a limited but straightforward access to a complex subsystem.
* You want to structure a subsystem into layers.

---

## ⚖️ Pros and Cons

### ✔ Pros

* You can isolate your code form the complexity of a subsystem.

### ❌ Cons

* A Facade can become a god object coupled to all classes of an app.


