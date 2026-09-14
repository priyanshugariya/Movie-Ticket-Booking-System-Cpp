class Movie {
private:
    string title;
    string language;
    int durationMinutes;

public:
    Movie(string title, string language, int durationMinutes)
        : title(title), language(language), durationMinutes(durationMinutes) {}

    Movie(string title, int durationMinutes)
        : title(title), language("English"), durationMinutes(durationMinutes) {}

    string getTitle() const { return title; }
    string getLanguage() const { return language; }
    int getDuration() const { return durationMinutes; }
};
