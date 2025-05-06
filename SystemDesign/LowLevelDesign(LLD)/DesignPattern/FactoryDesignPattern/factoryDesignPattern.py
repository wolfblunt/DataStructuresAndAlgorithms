from abc import ABC, abstractmethod

class Dish(ABC):
    @abstractmethod
    def prepare(self):
        pass

class Pizza(Dish):
    def prepare(self):
        print("Preparing Delicious Pizza with cheese and paneer toppings")

class Burger(Dish):
    def prepare(self):
        print("Preparing a juic burger with panner and onion")

class Sandwich(Dish):
    def prepare(self):
        print("Preparing a tasty sandwich with spinach and cheese")

class DishFactory:
    @staticmethod
    def create_dish(dish_type):
        if dish_type == "pizza":
            return Pizza()
        elif dish_type == "burger":
            return Burger()
        elif dish_type == "sandwich":
            return Sandwich()
        else:
            raise ValueError("Unknown Dish Type: {}".format(dish_type))

def order_dish(dish_type):
    factory = DishFactory()
    dish = factory.create_dish(dish_type)
    dish.prepare()


order_dish("pizza")
order_dish("burger")
order_dish("sandwich")
