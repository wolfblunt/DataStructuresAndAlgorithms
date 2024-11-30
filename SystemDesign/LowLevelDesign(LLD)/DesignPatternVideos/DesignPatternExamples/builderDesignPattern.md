The **Builder Design Pattern** is a creational pattern used to construct complex objects step-by-step. Instead of creating an object in a single, large constructor, the builder pattern allows you to construct the object by calling methods on a builder.

---

### **Example Scenario: Building a Burger**

#### Without Builder Pattern
All burger components are specified in a constructor, making it hard to manage for complex configurations.

```python
class Burger:
    def __init__(self, size, cheese, pepperoni, lettuce, tomato):
        self.size = size
        self.cheese = cheese
        self.pepperoni = pepperoni
        self.lettuce = lettuce
        self.tomato = tomato

    def __str__(self):
        return f"Burger(size={self.size}, cheese={self.cheese}, pepperoni={self.pepperoni}, lettuce={self.lettuce}, tomato={self.tomato})"


# Create a burger with all components
burger = Burger(10, True, True, False, True)
print(burger)  # Hard to manage as the number of arguments grows.
```

---

#### With Builder Pattern
The builder separates object creation into multiple steps, improving readability and flexibility.

```python
class Burger:
    def __init__(self, size):
        self.size = size
        self.cheese = False
        self.pepperoni = False
        self.lettuce = False
        self.tomato = False

    def __str__(self):
        return f"Burger(size={self.size}, cheese={self.cheese}, pepperoni={self.pepperoni}, lettuce={self.lettuce}, tomato={self.tomato})"


class BurgerBuilder:
    def __init__(self, size):
        self.burger = Burger(size)

    def add_cheese(self):
        self.burger.cheese = True
        return self  # Enable method chaining

    def add_pepperoni(self):
        self.burger.pepperoni = True
        return self

    def add_lettuce(self):
        self.burger.lettuce = True
        return self

    def add_tomato(self):
        self.burger.tomato = True
        return self

    def build(self):
        return self.burger


# Use the builder to create a custom burger
builder = BurgerBuilder(10)
burger = builder.add_cheese().add_tomato().add_pepperoni().build()
print(burger)
# Output: Burger(size=10, cheese=True, pepperoni=True, lettuce=False, tomato=True)
```

---

### **Advantages**
1. **Readable Code**: The steps to construct the object are explicitly listed.
2. **Customizable Construction**: The builder allows optional features to be added flexibly.
3. **Reusability**: The same builder can be reused to create multiple objects with different configurations.

### **When to Use?**
- When you need to construct an object with many optional attributes or steps.
- When you want to make the object construction process more readable and maintainable.