from models.user import User
from models.vehicle import Vehicle

class UserService:
    def __init__(self):
        self.users = {}

    def add_user(self, name, gender, age):
        self.users[name] = User(name, gender, age)

    def add_vehicle(self, name, model, plate):
        if name in self.users:
            vehicle = Vehicle(name, model, plate)
            self.users[name].vehicles.append(vehicle)
            return vehicle
        return None

    def get_user(self, name):
        return self.users.get(name, None)