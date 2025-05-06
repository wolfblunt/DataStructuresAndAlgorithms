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