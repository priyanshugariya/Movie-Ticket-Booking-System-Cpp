class Screen {
private:
    int screenNumber;
    vector<Seat> seats;

public:
    explicit Screen(int screenNumber) : screenNumber(screenNumber) {}

    void addSeat(const Seat& seat) { seats.push_back(seat); }
    int getScreenNumber() const { return screenNumber; }
    const vector<Seat>& getSeats() const { return seats; }
};
