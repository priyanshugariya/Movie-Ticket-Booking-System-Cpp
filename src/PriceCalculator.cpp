class PriceCalculator {
public:
    double calculateTotal(const vector<ShowSeat*>& seats) const {
        double total = 0.0;
        for (const ShowSeat* seat : seats) total += seat->getSeat()->getPrice();
        return total;
    }
};
