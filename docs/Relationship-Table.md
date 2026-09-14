# C. Relationship Table

| Pair | Relationship | Lifetime-test justification |
|---|---|---|
| Cinema – Screen | Composition | Cinema owns its Screen objects. If the Cinema is destroyed, its owned screens cease to exist as parts of that Cinema. |
| Screen – Seat | Composition | Screen owns its physical Seat objects. If the Screen is destroyed, those owned seats cease to exist with it. |
| Show – Movie | Aggregation | Show uses an existing Movie. The Movie can exist independently and can be used by other Shows. |
| Show – Screen | Association | Show uses an existing Screen for its screening. Destroying a Show does not destroy the Screen. |
| Show – ShowSeat | Composition | Show creates the ShowSeat objects for its own screening. Destroying the Show removes those show-specific seat-status objects. |
| Booking – Customer | Association | Booking is related to a Customer, but destroying the Booking does not destroy the Customer. |
| Booking – ShowSeat | Aggregation | Booking stores references to existing ShowSeat objects. Destroying a Booking does not destroy the ShowSeat objects. |
| Booking – Payment | Association | Payment is used to complete the booking, but neither object owns the other's lifetime. |
| Payment – UpiPayment | Inheritance | UpiPayment is a specialized type of the abstract Payment class. |
| BookingService – Booking | Aggregation | The service stores Booking objects, while a Booking is a separate entity with its own identity and state. |
