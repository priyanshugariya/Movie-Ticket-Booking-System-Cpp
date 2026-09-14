class Show {
private:
    int showId;
    const Movie* movie;
    const Screen* screen;
    string startTime;
    vector<ShowSeat> showSeats;

public:
    Show(int showId, const Movie* movie, const Screen* screen, string startTime)
        : showId(showId), movie(movie), screen(screen), startTime(startTime) {
        for (const Seat& seat : screen->getSeats()) {
            showSeats.emplace_back(&seat);
        }
    }

    int getShowId() const { return showId; }
    const Movie* getMovie() const { return movie; }
    const Screen* getScreen() const { return screen; }
    string getStartTime() const { return startTime; }

    ShowSeat* findSeat(const string& number) {
        for (ShowSeat& showSeat : showSeats) {
            if (showSeat.getSeat()->getNumber() == number) return &showSeat;
        }
        return nullptr;
    }

    void displaySeats() const {
        cout << "\n--- SCREEN " << screen->getScreenNumber() << " ---\n";
        for (const ShowSeat& showSeat : showSeats) {
            cout << "Seat " << showSeat.getSeat()->getNumber()
                 << " | " << showSeat.getSeat()->getTypeName()
                 << " | " << (showSeat.isAvailable() ? "AVAILABLE" : "BOOKED")
                 << '\n';
        }
    }
};
