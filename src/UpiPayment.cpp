class UpiPayment : public Payment {
private:
    string upiId;

public:
    explicit UpiPayment(string upiId) : upiId(upiId) {}

    bool pay(double amount) override {
        if (upiId.empty() || upiId.find('@') == string::npos) return false;
        cout << "Processing UPI payment of Rs." << fixed << setprecision(2)
             << amount << "...\n";
        cout << "UPI payment successful.\n";
        return true;
    }

    string getMethodName() const override { return "UPI"; }
};
