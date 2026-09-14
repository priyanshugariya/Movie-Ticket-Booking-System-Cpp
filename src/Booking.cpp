enum class BookingStatus { PENDING, CONFIRMED, FAILED, CANCELLED };

class Booking {
private:
    static int nextBookingId;
    int bookingId;
    Customer customer;
    Show* show;
    vector<ShowSeat*> seats;
    double totalAmount;
    BookingStatus status;

public:
    Booking(Customer customer, Show* show, vector<ShowSeat*> seats, double totalAmount)
        : bookingId(nextBookingId++), customer(customer), show(show),
          seats(seats), totalAmount(totalAmount), status(BookingStatus::PENDING) {}

    int getBookingId() const { return bookingId; }
    Show* getShow() const { return show; }
    const vector<ShowSeat*>& getSeats() const { return seats; }
    double getTotalAmount() const { return totalAmount; }
    BookingStatus getStatus() const { return status; }

    void confirm() { status = BookingStatus::CONFIRMED; }
    void fail() { status = BookingStatus::FAILED; }
    void cancel() { status = BookingStatus::CANCELLED; }
};

int Booking::nextBookingId = 1001;
