class CardPayment : public Payment {
private:
    string cardNumber;

public:
    explicit CardPayment(string cardNumber) : cardNumber(cardNumber) {}

    bool pay(double amount) override {
        if (cardNumber.size() != 16) return false;
        cout << "Processing Card payment of Rs." << fixed << setprecision(2)
             << amount << "...\n";
        cout << "Card payment successful.\n";
        return true;
    }

    string getMethodName() const override { return "Card"; }
};
