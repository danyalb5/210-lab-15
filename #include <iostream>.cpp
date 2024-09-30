#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Movie {
private:
    std::string title;
    int year;
    std::string screenWriter;

public:
    // Constructor
    Movie() : title(""), year(0), screenWriter("") {}

    // Setters
    void setTitle(const std::string& t) { title = t; }
    void setYear(int y) { year = y; }
    void setScreenWriter(const std::string& sw) { screenWriter = sw; }

    // Getters
    std::string getTitle() const { return title; }
    int getYear() const { return year; }
    std::string getScreenWriter() const { return screenWriter; }

    // Print method
    void print() const {
        std::cout << "Movie: " << title << std::endl;
        std::cout << "    Year released: " << year << std::endl;
        std::cout << "    Screenwriter: " << screenWriter << std::endl;
    }
};

int main() {
    std::vector<Movie> movies;
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return 1;
    }

    // Temporary variables to read from file
    std::string title;
    int year;
    std::string screenWriter;

    // Reading data from the input file
    while (getline(inputFile, title) && inputFile >> year && inputFile.ignore() && getline(inputFile, screenWriter)) {
        Movie tempMovie;
        tempMovie.setTitle(title);
        tempMovie.setYear(year);
        tempMovie.setScreenWriter(screenWriter);
        movies.push_back(tempMovie);  // Append to vector

        // Ignore extra new line
        inputFile.ignore();
    }

    inputFile.close();

    // Output the contents of the vector
    for (const auto& movie : movies) {
        movie.print();
        std::cout << std::endl;  // For better formatting
    }

    return 0;
}
