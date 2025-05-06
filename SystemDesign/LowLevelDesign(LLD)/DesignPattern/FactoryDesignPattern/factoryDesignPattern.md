The Factory Design Pattern is a creational pattern that provides a way to create objects without specifying the exact class of object that will be created. It’s useful when you want to delegate object creation to a factory class, making the code more flexible and maintainable.

Here’s a simple real-life example in Python: imagine a **restaurant** that serves different types of dishes (e.g., Pizza, Burger, Sushi). The Factory Pattern can be used to create the appropriate dish based on the customer’s order without directly instantiating the dish classes.

### Example Code
```python
from abc import ABC, abstractmethod

# Abstract product
class Dish(ABC):
    @abstractmethod
    def prepare(self):
        pass

# Concrete products
class Pizza(Dish):
    def prepare(self):
        return "Preparing a delicious Pizza with cheese and toppings!"

class Burger(Dish):
    def prepare(self):
        return "Preparing a juicy Burger with lettuce and tomato!"

class Sushi(Dish):
    def prepare(self):
        return "Preparing fresh Sushi with rice and fish!"

# Factory class
class DishFactory:
    @staticmethod
    def create_dish(dish_type: str) -> Dish:
        if dish_type.lower() == "pizza":
            return Pizza()
        elif dish_type.lower() == "burger":
            return Burger()
        elif dish_type.lower() == "sushi":
            return Sushi()
        else:
            raise ValueError(f"Unknown dish type: {dish_type}")

# Client code
def order_dish(dish_type: str):
    factory = DishFactory()
    dish = factory.create_dish(dish_type)
    print(dish.prepare())

# Usage
order_dish("pizza")  # Output: Preparing a delicious Pizza with cheese and toppings!
order_dish("burger") # Output: Preparing a juicy Burger with lettuce and tomato!
order_dish("sushi")  # Output: Preparing fresh Sushi with rice and fish!
```

### Explanation
1. **Abstract Product (`Dish`)**: An abstract base class (`Dish`) defines the interface for all dishes with a `prepare` method.
2. **Concrete Products (`Pizza`, `Burger`, `Sushi`)**: These are specific dish types that implement the `Dish` interface.
3. **Factory (`DishFactory`)**: The `DishFactory` class has a static method `create_dish` that returns the appropriate dish object based on the input `dish_type`.
4. **Client Code (`order_dish`)**: The client only interacts with the factory to create dishes, without needing to know the specific class of the dish.

### Why Use the Factory Pattern Here?
- **Flexibility**: If the restaurant adds a new dish (e.g., `Taco`), you only need to create a new `Taco` class and update the factory’s `create_dish` method. The client code remains unchanged.
- **Encapsulation**: The creation logic is centralized in the factory, making it easier to manage and modify.
- **Decoupling**: The client doesn’t need to know how dishes are created or their specific classes, reducing dependencies.

This example mirrors a real-life scenario where a system (restaurant) needs to produce different types of objects (dishes) based on user input (orders). The Factory Pattern keeps the code clean and scalable.