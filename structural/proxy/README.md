# Proxy Pattern

## 📖 Definition

The **Proxy Pattern** is a **structural design pattern** that provides a surrogate or placeholder object, which controls access to another object.

The proxy can add additional behavior—such as lazy initialization, access control, logging, or caching—before or after delegating the request to the real object.

---

## 🎯 Intent

> **Control access to an object by providing a substitute that adds extra functionality.**

---

## 📌 Motivation

Imagine you have a database with very high demand:

* Many clients send requests directly to the database object.
* This can cause spikes in usage, leading to performance issues.

Without the Proxy Pattern:

* All clients communicate directly with the database.
* No checks, validations, or optimizations are applied.
* The database may become overloaded and unstable.

With the Proxy Pattern:

* Clients communicate with a **Proxy** instead of the real database.
* The proxy can validate, cache, or throttle requests before forwarding them.
* The database receives fewer, more optimized requests, improving stability.

---

## 🏗 Structure

```
          +---------+        +----------------+
          |  Client | -----> |  Subject       |
          +---------+        +----------------+
                                 ^      ^
                                 |      |
                  +----------------+   +----------------+
                  |    Proxy       |   | RealSubject    |
                  +----------------+   +----------------+
```

* **Subject (Service Interface)**: Declares the common interface for both the RealSubject and the Proxy.
* **RealSubject (Service)**: The real object that provides the actual business logic.
* **Proxy**: Implements the same interface as RealSubject and controls access to it by adding extra behavior.
* **Client**: Works with objects through the Subject interface and can use either the Proxy or the RealSubject transparently.

---

## 🧩 Types of Proxies

* **Virtual Proxy**: Controls access to an object that is expensive to create (e.g., on-demand loading of large images).
* **Protection Proxy**: Controls access to an object based on access rights or permissions.
* **Remote Proxy**: Represents an object that exists in a different address space (e.g., accessing a remote service over the network).
* **Caching Proxy (Smart Proxy)**: Stores results of expensive operations and returns cached results instead of recalculating them.
* **Logging / Monitoring Proxy**: Adds monitoring, logging, or analytics before/after forwarding requests.

---

## ✅ Applicability

Use the Proxy Pattern when:

* You need to control access to a resource that is **expensive** to create or use.
* You want to add **security checks or access control** before accessing an object.
* You need **lazy initialization** or **on-demand loading** of heavy objects.
* You want to add **logging, caching, or monitoring** around method calls.
* You want to **represent a remote object locally** (Remote Proxy).

---

## ⚖️ Pros and Cons

### ✔ Pros

* Adds **extra functionality** without changing the real object’s code.
* Provides **control over object lifecycle** (lazy initialization, caching).
* Improves **security** by controlling access to sensitive objects.
* Can **reduce system load** by caching or throttling requests.
* Can **abstract remote objects** so clients use them as if they were local.

### ❌ Cons

* Adds **extra complexity** due to an additional layer of abstraction.
* Can **introduce latency** since every call goes through the proxy.
* May **hide the real object’s behavior**, making debugging more difficult.
* Overusing proxies may lead to an **over-engineered system**.

