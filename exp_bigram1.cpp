#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> bigram_counts;

// Function to calculate the probability of a bigram
double calculateBigramProbability(string bigram) {
    // Check if the bigram exists in the corpus
    if (bigram_counts.find(bigram) != bigram_counts.end()) {
        // Get the count of the bigram
        int count = bigram_counts[bigram];
        
        // Assume total bigrams count as 10 for simplicity
        int total_bigrams = 10;
        
        // Calculate probability of the bigram
        return (double)count / total_bigrams;
    } else {
        // If bigram not found, return a very small probability
        return 0.0001; // Adjust as needed
    }
}

int main() {
    // Populate bigram counts from corpus
    bigram_counts["there is"] = 1;
    bigram_counts["is a"] = 1;
    bigram_counts["a big"] = 1;
    bigram_counts["big garden"] = 2;
    bigram_counts["children play"] = 1;
    bigram_counts["play in"] = 1;
    bigram_counts["in a"] = 1;
    bigram_counts["a garden"] = 1;
    bigram_counts["they play"] = 1;
    bigram_counts["play inside"] = 1;
    bigram_counts["inside beautiful"] = 1;
    bigram_counts["beautiful garden"] = 1;
    
    // Calculate the probability of the sentence "they play in a big garden"
    double probability = calculateBigramProbability("they play") * calculateBigramProbability("play in") * calculateBigramProbability("in a") * calculateBigramProbability("a big") * calculateBigramProbability("big garden");
    
    cout << "Probability of the sentence: " << probability << endl;
    
    return 0;
}
