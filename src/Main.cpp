#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// OOP concepts used:
// Encapsulation: private attributes and controlled public methods.
// Abstraction: Payment is an abstract class with pure virtual pay().
// Inheritance: UpiPayment, CardPayment and CashPayment derive from Payment.
// Runtime polymorphism: Payment& invokes the selected derived pay() implementation.
// Compile-time polymorphism: Movie has overloaded constructors.
// Static member: Booking::nextBookingId generates unique booking IDs.
// this keyword: constructors use the current object's members through initializers.
// Composition: Cinema->Screen, Screen->Seat, Show->ShowSeat.
// Aggregation: Show->Movie and Booking->ShowSeat.
// Association: Customer->BookingService interaction.

#include "Movie.cpp"
#include "Seat.cpp"
#include "Screen.cpp"
#include "Cinema.cpp"
#include "ShowSeat.cpp"
#include "Show.cpp"
#include "Customer.cpp"
#include "Booking.cpp"
#include "Payment.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
#include "PriceCalculator.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"

static void listMovies(const vector<Movie>& movies) {
    cout << "\n--- CURRENTLY PLAYING MOVIES ---\n";
    for (size_t i = 0; i < movies.size(); ++i)
        cout << i + 1 << ". " << movies[i].getTitle()
             << " | " << movies[i].getLanguage()
             << " | " << movies[i].getDuration() << " mins\n";
}

static void listShows(const vector<Movie>& movies, const vector<Show>& shows, int movieChoice) {
    const Movie* selectedMovie = &movies[movieChoice - 1];
    cout << "\n--- AVAILABLE SHOWS ---\n";
    for (const Show& show : shows)
        if (show.getMovie() == selectedMovie)
            cout << show.getShowId() << ". Screen "
                 << show.getScreen()->getScreenNumber() << " | "
                 << show.getStartTime() << '\n';
}

static Show* chooseShow(const vector<Movie>& movies, vector<Show>& shows) {
    listMovies(movies);
    cout << "Choose movie: ";
    int movieChoice;
    cin >> movieChoice;
    if (cin.fail() || movieChoice < 1 || movieChoice > static_cast<int>(movies.size())) {
        cin.clear(); cin.ignore(10000, '\n');
        cout << "Invalid movie choice.\n";
        return nullptr;
    }

    listShows(movies, shows, movieChoice);
    cout << "Choose show: ";
    int showId;
    cin >> showId;
    for (Show& show : shows)
        if (show.getShowId() == showId && show.getMovie() == &movies[movieChoice - 1])
            return &show;
    cout << "Invalid show choice.\n";
    return nullptr;
}

static vector<string> readSeatNumbers() {
    cout << "Enter seat numbers separated by spaces: ";
    string line;
    cin.ignore(10000, '\n');
    getline(cin, line);
    istringstream input(line);
    vector<string> numbers;
    string number;
    while (input >> number) numbers.push_back(number);
    return numbers;
}

static unique_ptr<Payment> choosePayment() {
    cout << "\n--- PAYMENT ---\n1. UPI\n2. Card\n3. Cash\n";
    cout << "Choose payment method: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter UPI ID: ";
        string upi;
        cin >> upi;
        return make_unique<UpiPayment>(upi);
    }
    if (choice == 2) {
        cout << "Enter 16-digit card number: ";
        string card;
        cin >> card;
        return make_unique<CardPayment>(card);
    }
    if (choice == 3) return make_unique<CashPayment>();

    cout << "Invalid payment choice.\n";
    return nullptr;
}

int main() {
    Movie movie1("3 Idiots", "Hindi", 170);
    Movie movie2("Interstellar", "English", 169);
    vector<Movie> movies{movie1, movie2};

    Cinema cinema("Single Cinema");
    Screen screen1(1);
    Screen screen2(2);

    for (int i = 1; i <= 4; ++i) screen1.addSeat(Seat("A" + to_string(i), SeatType::SILVER));
    for (int i = 1; i <= 4; ++i) screen1.addSeat(Seat("B" + to_string(i), SeatType::GOLD));
    for (int i = 1; i <= 2; ++i) screen1.addSeat(Seat("C" + to_string(i), SeatType::PLATINUM));

    for (int i = 1; i <= 2; ++i) screen2.addSeat(Seat("A" + to_string(i), SeatType::SILVER));
    for (int i = 1; i <= 2; ++i) screen2.addSeat(Seat("B" + to_string(i), SeatType::GOLD));
    for (int i = 1; i <= 2; ++i) screen2.addSeat(Seat("C" + to_string(i), SeatType::PLATINUM));

    cinema.addScreen(screen1);
    cinema.addScreen(screen2);

    vector<Screen>& screens = cinema.getScreens();
    vector<Show> shows;
    shows.emplace_back(1, &movies[0], &screens[0], "06:00 PM");
    shows.emplace_back(2, &movies[0], &screens[1], "09:00 PM");
    shows.emplace_back(3, &movies[1], &screens[0], "07:00 PM");

    Customer customer("Demo Customer", "9999999999");
    BookingService bookingService;

    while (true) {
        cout << "\n========================================\n";
        cout << "        MOVIE TICKET BOOKING\n";
        cout << "========================================\n";
        cout << "1. List Movies\n2. View Shows\n3. View Seats\n4. Book Ticket\n5. Cancel Booking\n6. Exit\n";
        cout << "Choose: ";
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); cin.ignore(10000, '\n');
            cout << "Invalid menu choice.\n";
            continue;
        }
        if (choice == 6) break;

        if (choice == 1) {
            listMovies(movies);
        } else if (choice == 2) {
            listMovies(movies);
            cout << "Choose movie: ";
            int movieChoice; cin >> movieChoice;
            if (movieChoice < 1 || movieChoice > static_cast<int>(movies.size())) {
                cout << "Invalid movie choice.\n";
                continue;
            }
            listShows(movies, shows, movieChoice);
        } else if (choice == 3) {
            Show* show = chooseShow(movies, shows);
            if (show) show->displaySeats();
        } else if (choice == 4) {
            Show* show = chooseShow(movies, shows);
            if (!show) continue;
            show->displaySeats();
            vector<string> seats = readSeatNumbers();
            unique_ptr<Payment> payment = choosePayment();
            if (!payment) continue;
            bookingService.createBooking(customer, show, seats, *payment);
        } else if (choice == 5) {
            cout << "Enter booking ID: ";
            int bookingId; cin >> bookingId;
            bookingService.cancelBooking(bookingId);
        } else {
            cout << "Invalid menu choice.\n";
        }
    }
    return 0;
}
