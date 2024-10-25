#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main() {
    // Declare the file name
    // Replace "your_text_file.txt" with the name of your text file including the extension
    string filename = "C:/Users/VAGISHA/OneDrive/Desktop/Sample.txt"; // <-- Place your text file name here

    // Open the file
    ifstream file(filename);

    // Check if the file was opened successfully
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return 1; // Exit the program with an error code
    }

    // Variables to hold counts and frequencies
    int wordCount = 0; // To count total words
    int charCount = 0; // To count total characters
    map<string, int> wordFrequency; // To store word frequencies

    string word; // To accumulate characters into words
    char ch;     // To read each character from the file

    // Read the file character by character
    while (file.get(ch)) {
        charCount++; // Increment character count for each character read

        // Check if the character is a letter
        if (isalpha(ch)) {
            // Convert character to lowercase and add to the current word
            word += tolower(ch);
        } else {
            // If we have accumulated a word, process it
            if (!word.empty()) {
                wordCount++; // Increment word count
                wordFrequency[word]++; // Increment frequency for this word
                word.clear(); // Clear the word for the next one
            }
        }
    }

    // After reading the file, check if there is a word left to process
    if (!word.empty()) {
        wordCount++; // Increment word count
        wordFrequency[word]++; // Increment frequency for this word
        word.clear();
    }

    // Output the results
    cout << "Total characters: " << charCount << endl;
    cout << "Total words: " << wordCount << endl;
    cout << "Word frequencies:" << endl;

    // Iterate through the map and print word frequencies
    for (const auto& pair : wordFrequency) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Close the file
    file.close();

    return 0; // Exit the program successfully
}
