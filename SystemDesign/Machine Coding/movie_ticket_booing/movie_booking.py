# Movie Ticket Booking System

from enum import Enum
from typing import List, Dict
import uuid

# Enums for status
class SeatStatus(Enum):
    AVAILABLE = "AVAILABLE"
    BOOKED = "BOOKED"

class BookingStatus(Enum):
    PENDING = "PENDING"
    CONFIRMED = "CONFIRMED"
    CANCELLED = "CANCELLED"

# Movie class to store movie details
class Movie:
    def __init__(self, movie_id: str, title: str, duration: int):
        self.movie_id = movie_id
        self.title = title
        self.duration = duration  # Duration in minutes

# Theater class to store theater details
class Theater:
    def __init__(self, theater_id: str, name: str, location: str):
        self.theater_id = theater_id
        self.name = name
        self.location = location
        self.screens: List[Screen] = []

    def add_screen(self, screen: 'Screen'):
        self.screens.append(screen)

# Screen class to store screen details and shows
class Screen:
    def __init__(self, screen_id: str, theater: Theater):
        self.screen_id = screen_id
        self.theater = theater
        self.shows: List[Show] = []

    def add_show(self, show: 'Show'):
        self.shows.append(show)

# Seat class to represent a seat in a screen
class Seat:
    def __init__(self, seat_id: str, row: str, number: int):
        self.seat_id = seat_id
        self.row = row
        self.number = number
        self.status = SeatStatus.AVAILABLE

    def book_seat(self):
        if self.status == SeatStatus.AVAILABLE:
            self.status = SeatStatus.BOOKED
            return True
        return False

    def cancel_booking(self):
        if self.status == SeatStatus.BOOKED:
            self.status = SeatStatus.AVAILABLE
            return True
        return False

# Show class to represent a movie show
class Show:
    def __init__(self, show_id: str, movie: Movie, screen: Screen, start_time: str):
        self.show_id = show_id
        self.movie = movie
        self.screen = screen
        self.start_time = start_time
        self.seats: Dict[str, Seat] = {}

    def add_seat(self, seat: Seat):
        self.seats[seat.seat_id] = seat

    def get_available_seats(self) -> List[Seat]:
        return [seat for seat in self.seats.values() if seat.status == SeatStatus.AVAILABLE]

# Ticket class to represent a booked ticket
class Ticket:
    def __init__(self, ticket_id: str, show: Show, seats: List[Seat], user: str):
        self.ticket_id = ticket_id
        self.show = show
        self.seats = seats
        self.user = user
        self.status = BookingStatus.PENDING

    def confirm_booking(self):
        self.status = BookingStatus.CONFIRMED

    def cancel_booking(self):
        self.status = BookingStatus.CANCELLED
        for seat in self.seats:
            seat.cancel_booking()

# TicketFactory to create tickets
class TicketFactory:
    @staticmethod
    def create_ticket(show: Show, seats: List[Seat], user: str) -> Ticket:
        ticket_id = str(uuid.uuid4())
        return Ticket(ticket_id, show, seats, user)

# Singleton BookingSystem class to manage bookings
class BookingSystem:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(BookingSystem, cls).__new__(cls)
            cls._instance.movies: List[Movie] = []
            cls._instance.theaters: List[Theater] = []
            cls._instance.tickets: Dict[str, Ticket] = {}
        return cls._instance

    def add_movie(self, movie: Movie):
        self.movies.append(movie)

    def add_theater(self, theater: Theater):
        self.theaters.append(theater)

    def find_shows_by_movie(self, movie_id: str) -> List[Show]:
        shows = []
        for theater in self.theaters:
            for screen in theater.screens:
                for show in screen.shows:
                    if show.movie.movie_id == movie_id:
                        shows.append(show)
        return shows

    def book_ticket(self, show: Show, seat_ids: List[str], user: str) -> Ticket:
        # Check if seats are available
        seats_to_book = []
        for seat_id in seat_ids:
            seat = show.seats.get(seat_id)
            if seat and seat.status == SeatStatus.AVAILABLE:
                seat.book_seat()
                seats_to_book.append(seat)
            else:
                # Rollback if any seat is unavailable
                for booked_seat in seats_to_book:
                    booked_seat.cancel_booking()
                raise ValueError(f"Seat {seat_id} is not available")

        # Create ticket
        ticket = TicketFactory.create_ticket(show, seats_to_book, user)
        ticket.confirm_booking()
        self.tickets[ticket.ticket_id] = ticket
        return ticket

    def cancel_ticket(self, ticket_id: str):
        ticket = self.tickets.get(ticket_id)
        if ticket:
            ticket.cancel_booking()
            self.tickets[ticket_id] = ticket
            return True
        return False

# Example usage
def main():
    # Initialize booking system
    booking_system = BookingSystem()

    # Create movie
    movie = Movie("M001", "The Matrix", 120)

    # Create theater and screen
    theater = Theater("T001", "PVR Cinema", "Downtown")
    screen = Screen("S001", theater)
    theater.add_screen(screen)

    # Create show
    show = Show("SH001", movie, screen, "2025-06-16 18:00")
    screen.add_show(show)

    # Add seats to show
    seat1 = Seat("S1", "A", 1)
    seat2 = Seat("S2", "A", 2)
    show.add_seat(seat1)
    show.add_seat(seat2)

    # Add movie and theater to booking system
    booking_system.add_movie(movie)
    booking_system.add_theater(theater)

    # Book a ticket
    try:
        ticket = booking_system.book_ticket(show, ["S1", "S2"], "user123")
        print(f"Ticket booked: {ticket.ticket_id} for {ticket.show.movie.title}")
        print(f"Seats: {[seat.seat_id for seat in ticket.seats]}")
        print(f"Status: {ticket.status}")

        # Cancel ticket
        booking_system.cancel_ticket(ticket.ticket_id)
        print(f"Ticket {ticket.ticket_id} cancelled. Status: {ticket.status}")
    except ValueError as e:
        print(f"Booking failed: {e}")

if __name__ == "__main__":
    main()