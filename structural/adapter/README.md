# 🔌 Adapter Pattern

The **Adapter Pattern** is a **structural design pattern** that allows objects with **incompatible interfaces** to work together. It acts as a **bridge** between two interfaces, converting one into another that the client expects.

This pattern helps you integrate third-party classes, legacy code, or systems with mismatched interfaces without modifying their source code.

---

## ❌ Problem

Imagine you’re building a payment system.
Your app is designed to work with a `PaymentProcessor` interface:

```python
class PaymentProcessor:
    def pay(self, amount: float):
        pass
```

But now, you need to integrate with a third-party library that processes payments differently:

```python
class StripeAPI:
    def make_payment(self, money: float):
        print(f"Processing ${money} through Stripe")
```

Directly using `StripeAPI` would require changing your code everywhere. Worse, if you later switch to another provider (e.g., PayPal), you’d need to rewrite everything again.

---

## ✅ Solution

The **Adapter Pattern** solves this by creating a wrapper (the **Adapter**) that translates the interface of the third-party class (`StripeAPI`) into the expected interface (`PaymentProcessor`).

```python
class StripeAdapter(PaymentProcessor):
    def __init__(self, stripe_api: StripeAPI):
        self.stripe_api = stripe_api

    def pay(self, amount: float):
        self.stripe_api.make_payment(amount)
```

Now your client code doesn’t need to know about `StripeAPI`:

```python
# The client works only with the PaymentProcessor interface
processor: PaymentProcessor = StripeAdapter(StripeAPI())
processor.pay(100)  # Works with Stripe seamlessly
```

This way:

* Your code stays decoupled from external libraries.
* You can swap providers without changing client code.
* The adapter acts as a translator between interfaces.

---

## 🏗 Structure

1. **Target (Abstract Interface)** — The expected interface by the client (e.g., `PaymentProcessor`).
2. **Adaptee** — The existing class with an incompatible interface (e.g., `StripeAPI`).
3. **Adapter** — A wrapper that implements the Target interface and delegates work to the Adaptee.
4. **Client** — Uses the Target interface and is unaware of the Adaptee’s details.

---

## 📌 When to Use It

Use the **Adapter Pattern** when:

* You want to use an existing class but its interface doesn’t match what you need.
* You want to integrate third-party libraries or legacy code into your system without modifying them.
* You want to reuse code without rewriting large parts of it to fit a new interface.

---

## 💡 Real-World Analogy

Think of a **power adapter** for traveling:

* Your **laptop charger plug** is the **Adaptee** (it has one shape).
* The **wall socket** in another country is the **Target** (it expects a different shape).
* The **adapter** fits between them, converting the plug into the right format.
* The **client (you)** just plugs in the laptop and doesn’t care about voltage differences or plug shapes — the adapter makes it work.

