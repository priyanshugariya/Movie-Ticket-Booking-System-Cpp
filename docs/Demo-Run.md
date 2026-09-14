# Demo Run

The program was compiled with:

```bash
g++ -std=c++17 Main.cpp -o MovieTicketBooking
```

A successful booking using UPI prints a ticket containing the booking ID, movie, screen, time, seat and total amount.

The implementation also checks the mandatory edge cases:

1. Already-booked seat → rejected, with no change to the booking state.
2. Invalid payment details → payment fails, booking is not confirmed and seats are released.
3. Cancellation → confirmed booking becomes cancelled and its seats become AVAILABLE.
4. Invalid seat/menu choice → clear message and no crash.
