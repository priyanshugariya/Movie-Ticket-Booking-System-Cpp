# Movie Ticket Booking System

A C++ console application for a single cinema that implements the TCS-504 System Design Assignment requirements.

## Features

- List currently playing movies
- List shows for a selected movie
- Display seat layout with AVAILABLE / BOOKED status
- Book one or more seats
- Reject already-booked or invalid seats
- Calculate prices by seat type
- Pay using UPI, Card or Cash
- Prevent confirmation after a failed payment
- Print a ticket
- Cancel a confirmed booking and release seats

## Technologies Used

- C++17
- Object-Oriented Programming (OOP)
- UML
- SOLID Principles
- C++ Standard Library

## Project Structure

```text
Movie-Ticket-Booking-System-Cpp/
│
├── src/
│   ├── Main.cpp
│   ├── Movie.cpp
│   ├── Seat.cpp
│   ├── Screen.cpp
│   ├── Cinema.cpp
│   ├── ShowSeat.cpp
│   ├── Show.cpp
│   ├── Customer.cpp
│   ├── Booking.cpp
│   ├── Payment.cpp
│   ├── UpiPayment.cpp
│   ├── CardPayment.cpp
│   ├── CashPayment.cpp
│   ├── PriceCalculator.cpp
│   ├── TicketPrinter.cpp
│   └── BookingService.cpp
│
├── docs/
│   ├── Requirement-Analysis.md
│   ├── Noun-Verb-Analysis.md
│   ├── Relationship-Table.md
│   ├── SOLID-Mapping.md
│   ├── Class-Diagram.png
│   └── Sequence-Diagram.png
│
└── screenshots/
    ├── 01-Main-Menu.png
    ├── 02-List-Movies.png
    ├── 03-View-Shows.png
    ├── 04-View-Seats.png
    ├── 05-Book-Ticket.png
    └── 06-Cancel-Booking.png
```

## How to Run

Open the `src` folder in a terminal and compile `Main.cpp`.

```bash
g++ -std=c++17 Main.cpp -o MovieTicketBooking
./MovieTicketBooking
```

No header files are used, as required by the assignment. `Main.cpp` includes the `.cpp` files in dependency order.

## Application Menu

```text
========================================
        MOVIE TICKET BOOKING
========================================
1. List Movies
2. View Shows
3. View Seats
4. Book Ticket
5. Cancel Booking
6. Exit
```

## Documentation

The `docs` folder contains the requirement analysis, noun-verb analysis, relationship table, SOLID mapping, class diagram and sequence diagram required by the assignment.

## Conclusion

The project demonstrates the required movie ticket booking flow using C++ classes, encapsulation, abstraction, inheritance, runtime polymorphism, compile-time polymorphism, static members, composition, aggregation and association.
