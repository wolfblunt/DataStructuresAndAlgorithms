def most_vacant(rides):
    return max(rides, key=lambda r: r.seats)

def preferred_vehicle(rides, vehicle_model):
    for ride in rides:
        if ride.vehicle.model == vehicle_model:
            return ride
    return None