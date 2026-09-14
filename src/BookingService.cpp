class BookingService {
private:
    PriceCalculator priceCalculator;
    TicketPrinter ticketPrinter;
    vector<shared_ptr<Booking>> bookings;

    bool validateSeats(Show* show, const vector<string>& numbers,
                      vector<ShowSeat*>& selected) const {
        if (numbers.empty()) return false;

        for (const string& number : numbers) {
            ShowSeat* seat = show->findSeat(number);
            if (seat == nullptr) {
                cout << "Invalid seat number: " << number << '\n';
                return false;
            }
            if (!seat->isAvailable()) {
                cout << "Seat " << number << " is already BOOKED. Booking rejected.\n";
                return false;
            }
            selected.push_back(seat);
        }
        return true;
    }

public:
    shared_ptr<Booking> createBooking(Customer customer, Show* show,
                                      const vector<string>& numbers,
                                      Payment& payment) {
        vector<ShowSeat*> selected;
        if (!validateSeats(show, numbers, selected)) return nullptr;

        double total = priceCalculator.calculateTotal(selected);
        auto booking = make_shared<Booking>(customer, show, selected, total);

        for (ShowSeat* seat : selected) seat->bookSeat();

        bool paid = payment.pay(total);
        if (!paid) {
            for (ShowSeat* seat : selected) seat->cancelSeat();
            booking->fail();
            bookings.push_back(booking);
            cout << "Payment failed. Booking NOT confirmed; seats released.\n";
            return nullptr;
        }

        booking->confirm();
        bookings.push_back(booking);
        ticketPrinter.printTicket(*booking);
        return booking;
    }

    void cancelBooking(int bookingId) {
        for (const auto& booking : bookings) {
            if (booking->getBookingId() == bookingId) {
                if (booking->getStatus() != BookingStatus::CONFIRMED) {
                    cout << "Only a CONFIRMED booking can be cancelled.\n";
                    return;
                }
                for (ShowSeat* seat : booking->getSeats()) seat->cancelSeat();
                booking->cancel();
                cout << "Booking " << bookingId
                     << " cancelled. Seats are AVAILABLE again.\n";
                return;
            }
        }
        cout << "Booking ID not found.\n";
    }
};
