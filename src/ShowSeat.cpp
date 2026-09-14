enum class SeatStatus { AVAILABLE, BOOKED };

class ShowSeat {
private:
    const Seat* seat;
    SeatStatus status;

public:
    explicit ShowSeat(const Seat* seat)
        : seat(seat), status(SeatStatus::AVAILABLE) {}

    const Seat* getSeat() const { return seat; }
    SeatStatus getStatus() const { return status; }
    bool isAvailable() const { return status == SeatStatus::AVAILABLE; }

    bool bookSeat() {
        if (!isAvailable()) return false;
        status = SeatStatus::BOOKED;
        return true;
    }

    void cancelSeat() { status = SeatStatus::AVAILABLE; }
};
