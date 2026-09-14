# H. SOLID Mapping

## 1. Single Responsibility Principle (SRP)

Each class has one primary responsibility.

- `Movie` stores movie information.
- `Seat` represents one physical seat.
- `PriceCalculator` calculates prices.
- `TicketPrinter` prints tickets.
- `BookingService` coordinates booking and cancellation.
- Each payment class performs one payment method.

`Booking` does not print tickets; `TicketPrinter` handles printing separately.

## 2. Open/Closed Principle (OCP)

The payment hierarchy is open for extension. A future `NetBankingPayment : public Payment` can implement `pay(double)` without modifying `UpiPayment`, `CardPayment` or `CashPayment`.

The booking workflow uses the abstract `Payment` reference, so the service does not depend on the implementation details of a payment method.

## 3. Liskov Substitution Principle (LSP)

`UpiPayment`, `CardPayment` and `CashPayment` implement the `Payment` contract and can be passed to `BookingService::createBooking()` through a `Payment&`.

## 4. Dependency Inversion Principle (DIP)

`BookingService` depends on the abstract `Payment` interface rather than on a concrete UPI, Card or Cash class for the actual payment operation.

## Deliberately NOT Done

The `Payment` base class does not force a `refund()` method. Refunds are outside the specified assignment scope, and forcing an unsupported operation on every payment type would unnecessarily increase the interface.
