enum class SeatType { SILVER, GOLD, PLATINUM };

class Seat {
private:
    string number;
    SeatType type;

public:
    Seat(string number, SeatType type) : number(number), type(type) {}

    string getNumber() const { return number; }
    SeatType getType() const { return type; }

    double getPrice() const {
        const double SILVER_PRICE = 150.0;
        const double GOLD_PRICE = 250.0;
        const double PLATINUM_PRICE = 400.0;

        switch (type) {
            case SeatType::SILVER: return SILVER_PRICE;
            case SeatType::GOLD: return GOLD_PRICE;
            case SeatType::PLATINUM: return PLATINUM_PRICE;
        }
        return 0.0;
    }

    string getTypeName() const {
        switch (type) {
            case SeatType::SILVER: return "SILVER";
            case SeatType::GOLD: return "GOLD";
            case SeatType::PLATINUM: return "PLATINUM";
        }
        return "UNKNOWN";
    }
};
