from services.user_service import UserService
from services.ride_service import RideService

def main():
    user_service = UserService()
    ride_service = RideService(user_service)

    user_service.add_user("Rohan", "M", 36)
    user_service.add_vehicle("Rohan", "Swift", "KA-01-12345")
    user_service.add_user("Shashank", "M", 29)
    user_service.add_vehicle("Shashank", "Baleno", "TS-05-62395")
    user_service.add_user("Nandini", "F", 29)
    user_service.add_user("Shipra", "F", 27)
    user_service.add_vehicle("Shipra", "Polo", "KA-05-41491")
    user_service.add_vehicle("Shipra", "Activa", "KA-12-12332")
    user_service.add_user("Gaurav", "M", 29)
    user_service.add_user("Rahul", "M", 35)
    user_service.add_vehicle("Rahul", "XUV", "KA-05-1234")

    ride_service.offer_ride("Rohan", "Hyderabad", "Bangalore", 1, "Swift", "KA-01-12345")
    ride_service.offer_ride("Shipra", "Bangalore", "Mysore", 1, "Activa", "KA-12-12332")
    ride_service.offer_ride("Shipra", "Bangalore", "Mysore", 2, "Polo", "KA-05-41491")
    ride_service.offer_ride("Shashank", "Hyderabad", "Bangalore", 2, "Baleno", "TS-05-62395")
    ride_service.offer_ride("Rahul", "Hyderabad", "Bangalore", 5, "XUV", "KA-05-1234")
    ride_service.offer_ride("Rohan", "Bangalore", "Pune", 1, "Swift", "KA-01-12345")

    ride_service.select_ride("Nandini", "Bangalore", "Mysore", 1, "Most Vacant")
    ride_service.select_ride("Gaurav", "Bangalore", "Mysore", 1, "Preferred Vehicle", preferred_model="Activa")
    ride_service.select_ride("Shashank", "Mumbai", "Bangalore", 1, "Most Vacant")
    ride_service.select_ride("Rohan", "Hyderabad", "Bangalore", 1, "Preferred Vehicle", preferred_model="Baleno")
    ride_service.select_ride("Shashank", "Hyderabad", "Bangalore", 1, "Preferred Vehicle", preferred_model="Polo")

    ride_service.end_ride(3)
    ride_service.end_ride(2)
    ride_service.end_ride(4)
    ride_service.end_ride(1)

    ride_service.print_ride_stats()

if __name__ == "__main__":
    main()