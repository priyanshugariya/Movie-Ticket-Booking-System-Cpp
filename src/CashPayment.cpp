class CashPayment : public Payment {
public:
    CashPayment() = default;

    bool pay(double amount) override {
        cout << "Cash payment of Rs." << fixed << setprecision(2)
             << amount << " received.\n";
        return true;
    }

    string getMethodName() const override { return "Cash"; }
};
