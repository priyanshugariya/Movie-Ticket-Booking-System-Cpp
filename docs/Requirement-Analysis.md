# A. Requirement Analysis

## Functional Requirements

### FR1 – List Movies
The system shall display all movies currently playing in the cinema along with their language and duration.

### FR2 – List Shows
The system shall allow the customer to select a movie and display its shows with screen number and start time.

### FR3 – Display Seat Availability
The system shall display the seat layout for a selected show and show each seat as either AVAILABLE or BOOKED.

### FR4 – Book Seats
The system shall allow the customer to select one or more available seats for a show. If any selected seat is already booked, the booking shall be rejected and no selected seat shall remain booked.

### FR5 – Calculate Booking Price
The system shall calculate the total booking amount according to seat type:

- SILVER – ₹150
- GOLD – ₹250
- PLATINUM – ₹400

### FR6 – Make Payment
The system shall support UPI, Card and Cash payment methods. A failed payment shall not confirm the booking and the selected seats shall be released.

### FR7 – Print Ticket
After successful payment, the system shall print a ticket containing booking ID, movie, screen, time, seat numbers and total amount.

### FR8 – Cancel Booking
The system shall allow cancellation of a confirmed booking. After cancellation, all seats belonging to that booking shall become AVAILABLE again.

## Non-Functional Requirements

### NFR1 – Modularity
Each required class shall be implemented in a separate `.cpp` file. No header files shall be used.

### NFR2 – Extensibility
The payment design shall use an abstract `Payment` class so that another payment type can be introduced as a derived class without changing the existing payment implementations.

### NFR3 – Input Validation
Invalid menu choices, invalid seat numbers, already-booked seats and invalid payment details shall produce clear messages without crashing.

### NFR4 – Maintainability
Classes shall have one clear responsibility, methods shall use meaningful names, constants shall be used for fixed prices, and repeated logic shall be avoided.
