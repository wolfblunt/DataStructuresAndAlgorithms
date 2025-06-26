from models.ride import Ride
from utils.selection_strategy import most_vacant, preferred_vehicle

class RideService:
    def __init__(self, user_service):
        self.user_service = user_service
        self.rides = []
        self.ride_id_counter = 1

    def offer_ride(self, name, origin, destination, seats, vehicle_model, plate_number):
        user = self.user_service.get_user(name)
        if not user:
            print("User not found.")
            return None

        for vehicle in user.vehicles:
            if vehicle.model == vehicle_model and vehicle.plate_number == plate_number:
                for ride in self.rides:
                    if ride.active and ride.vehicle.plate_number == plate_number:
                        print("Ride already active for this vehicle.")
                        return None

                ride = Ride(self.ride_id_counter, name, vehicle, origin, destination, seats)
                self.rides.append(ride)
                self.ride_id_counter += 1
                print(f"Ride {ride.ride_id} offered successfully.")
                return ride

        print("Vehicle not found for user.")
        return None

    def select_ride(self, name, origin, destination, seats, strategy, preferred_model=None):
        user = self.user_service.get_user(name)
        if not user:
            print("User not found.")
            return None

        available = [r for r in self.rides if r.active and r.origin == origin and r.destination == destination and r.seats >= seats]
        if not available:
            print("No rides found")
            return None

        selected_ride = None
        if strategy == "Most Vacant":
            selected_ride = most_vacant(available)
        elif strategy.startswith("Preferred Vehicle"):
            selected_ride = preferred_vehicle(available, preferred_model)

        if selected_ride:
            selected_ride.seats -= seats
            selected_ride.passenger = name
            user.rides_taken += 1
            print(f"Ride {selected_ride.ride_id} selected")
            return selected_ride
        else:
            print("No rides found")
            return None

    def end_ride(self, ride_id):
        for ride in self.rides:
            if ride.ride_id == ride_id and ride.active:
                ride.active = False
                driver = self.user_service.get_user(ride.driver_name)
                if driver:
                    driver.rides_offered += 1
                print(f"Ride {ride_id} ended")
                return
        print("Ride not found or already ended.")

    def print_ride_stats(self):
        for user in self.user_service.users.values():
            print(f"{user.name}: {user.rides_taken} Taken, {user.rides_offered} Offered")