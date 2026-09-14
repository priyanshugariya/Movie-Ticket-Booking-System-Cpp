class TicketPrinter {
public:
    void printTicket(const Booking& booking) const {
        cout << "\n========================================\n";
        cout << "              MOVIE TICKET\n";
        cout << "========================================\n";
        cout << "Booking ID : " << booking.getBookingId() << '\n';
        cout << "Movie      : " << booking.getShow()->getMovie()->getTitle() << '\n';
        cout << "Screen     : " << booking.getShow()->getScreen()->getScreenNumber() << '\n';
        cout << "Time       : " << booking.getShow()->getStartTime() << '\n';
        cout << "Seats      : ";
        for (const ShowSeat* seat : booking.getSeats())
            cout << seat->getSeat()->getNumber() << ' ';
        cout << "\nTotal      : Rs." << fixed << setprecision(2)
             << booking.getTotalAmount() << '\n';
        cout << "Status     : CONFIRMED\n";
        cout << "========================================\n";
    }
};
