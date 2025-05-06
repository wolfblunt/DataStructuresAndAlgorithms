The Builder Design Pattern is a creational pattern that separates the construction of a complex object from its representation, allowing the same construction process to create different representations. It’s useful when an object needs to be constructed step-by-step, especially when there are many optional parameters or configurations.

Here’s a simple real-life example in Python: a **House Builder** that constructs different types of houses (e.g., Cottage, Mansion) with customizable features like walls, roof, and garden. The Builder Pattern allows us to build houses step-by-step without exposing the construction details to the client.

```python
from abc import ABC, abstractmethod

# Product: The complex object being built
class House:
    def __init__(self):
        self.walls = None
        self.roof = None
        self.garden = None

    def __str__(self):
        return (f"House with {self.walls} walls, {self.roof} roof, "
                f"{'and a garden' if self.garden else 'and no garden'}")

# Abstract Builder: Defines steps to build the product
class HouseBuilder(ABC):
    @abstractmethod
    def reset(self):
        pass

    @abstractmethod
    def build_walls(self):
        pass

    @abstractmethod
    def build_roof(self):
        pass

    @abstractmethod
    def build_garden(self):
        pass

    @abstractmethod
    def get_house(self):
        pass

# Concrete Builder: Builds a specific type of house (Cottage)
class CottageBuilder(HouseBuilder):
    def __init__(self):
        self.reset()

    def reset(self):
        self._house = House()

    def build_walls(self):
        self._house.walls = "wooden"

    def build_roof(self):
        self._house.roof = "thatched"

    def build_garden(self):
        self._house.garden = True

    def get_house(self):
        house = self._house
        self.reset()  # Reset for next build
        return house

# Concrete Builder: Builds a specific type of house (Mansion)
class MansionBuilder(HouseBuilder):
    def __init__(self):
        self.reset()

    def reset(self):
        self._house = House()

    def build_walls(self):
        self._house.walls = "stone"

    def build_roof(self):
        self._house.roof = "tiled"

    def build_garden(self):
        self._house.garden = True

    def get_house(self):
        house = self._house
        self.reset()  # Reset for next build
        return house

# Director: Controls the construction process
class Architect:
    def __init__(self, builder: HouseBuilder):
        self._builder = builder

    def construct_house(self):
        self._builder.reset()
        self._builder.build_walls()
        self._builder.build_roof()
        self._builder.build_garden()
        return self._builder.get_house()

    def construct_minimal_house(self):
        self._builder.reset()
        self._builder.build_walls()
        self._builder.build_roof()
        return self._builder.get_house()

# Client code
def build_houses():
    # Build a cottage
    cottage_builder = CottageBuilder()
    architect = Architect(cottage_builder)
    cottage = architect.construct_house()
    print(cottage)  # Output: House with wooden walls, thatched roof, and a garden

    # Build a minimal cottage
    minimal_cottage = architect.construct_minimal_house()
    print(minimal_cottage)  # Output: House with wooden walls, thatched roof, and no garden

    # Build a mansion
    mansion_builder = MansionBuilder()
    architect = Architect(mansion_builder)
    mansion = architect.construct_house()
    print(mansion)  # Output: House with stone walls, tiled roof, and a garden

# Usage
build_houses()
```

### Explanation
1. **Product (`House`)**:
   - Represents the complex object being built. It has attributes like `walls`, `roof`, and `garden`.
   - The `__str__` method provides a readable description of the house.

2. **Abstract Builder (`HouseBuilder`)**:
   - An abstract base class defining the interface for building a house (steps like `build_walls`, `build_roof`, `build_garden`).
   - Includes a `reset` method to start a new build and `get_house` to retrieve the final product.

3. **Concrete Builders (`CottageBuilder`, `MansionBuilder`)**:
   - Implement the steps to build specific types of houses (e.g., a cottage with wooden walls and a thatched roof, or a mansion with stone walls and a tiled roof).
   - Each builder maintains its own `House` instance and resets it after delivering the product.

4. **Director (`Architect`)**:
   - Controls the construction process by calling the builder’s methods in a specific order.
   - Provides methods like `construct_house` (full build with all features) and `construct_minimal_house` (partial build without a garden).
   - The director is optional but helps standardize construction processes.

5. **Client Code (`build_houses`)**:
   - The client interacts with the `Architect` and `Builder` to construct different houses.
   - Demonstrates building a full cottage, a minimal cottage, and a mansion.

### Why Use the Builder Pattern Here?
- **Step-by-Step Construction**: Houses are built step-by-step (walls, roof, garden), allowing flexibility in the process.
- **Multiple Representations**: The same construction process can create different houses (Cottage, Mansion) with different materials or features.
- **Encapsulation**: The client doesn’t need to know how a house is built or the details of each component, making the code cleaner and more maintainable.
- **Flexibility**: You can easily add new builders (e.g., `ApartmentBuilder`) or modify construction steps (e.g., add a garage) without changing the client code.

### Real-Life Relevance
This example mirrors real-world scenarios like constructing houses, assembling cars, or preparing customized meals, where objects have multiple components that need to be configured step-by-step. The Builder Pattern is ideal when you want to create complex objects with varying configurations while keeping the construction process clear and reusable.