class User:
    def __init__(self, name, gender, age):
        self.name = name
        self.gender = gender
        self.age = age
        self.vehicles = []
        self.rides_offered = 0
        self.rides_taken = 0