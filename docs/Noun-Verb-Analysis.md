# B. Noun–Verb Analysis

| Noun | Keep as Class? | Reason |
|---|---|---|
| Movie | Yes | Has title, language and duration. |
| Seat | Yes | Represents one physical seat with number, type and price. |
| Screen | Yes | Represents one auditorium and owns its seats. |
| Cinema | Yes | Represents the theatre and owns its screens. |
| Show | Yes | Represents one movie screening on one screen at one time. |
| ShowSeat | Yes | Maintains the status of one seat for one show. |
| Customer | Yes | Stores customer information. |
| Booking | Yes | Represents a booking and its seats, amount and status. |
| Payment | Yes | Defines the common payment contract. |
| UPI Payment | Yes | Implements UPI payment behaviour. |
| Card Payment | Yes | Implements Card payment behaviour. |
| Cash Payment | Yes | Implements Cash payment behaviour. |
| Price Calculator | Yes | Calculates the booking price. |
| Ticket Printer | Yes | Prints the ticket. |
| Booking Service | Yes | Coordinates the booking flow. |
| Seat layout | No | It is a view of ShowSeat objects, not an independent entity. |
| Ticket | No | Printing is required, but a separate Ticket class is unnecessary for the specified scope. |

## Verbs Identified

see, list, pick, display, book, pay, print, cancel, reject, calculate, release.

## Verb to Method Mapping

| Verb | Class / Method |
|---|---|
| List movies | `Main.listMovies()` |
| Display seats | `Show.displaySeats()` |
| Book seats | `BookingService.createBooking()` |
| Pay | `Payment.pay()` |
| Calculate price | `PriceCalculator.calculateTotal()` |
| Print ticket | `TicketPrinter.printTicket()` |
| Cancel booking | `BookingService.cancelBooking()` |
| Release seats | `ShowSeat.cancelSeat()` |
