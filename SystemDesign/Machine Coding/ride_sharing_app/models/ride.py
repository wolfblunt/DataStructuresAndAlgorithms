class Ride:
    def __init__(self, ride_id, driver_name, vehicle, origin, destination, seats):
        self.ride_id = ride_id
        self.driver_name = driver_name
        self.vehicle = vehicle
        self.origin = origin
        self.destination = destination
        self.seats = seats
        self.active = True
        self.passenger = None