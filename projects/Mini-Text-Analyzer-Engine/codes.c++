#include <iostream>
using namespace std;

// Function 1: Find length of string (array-based)
int getLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i; // O(n)
}

// Function 2: Reverse string using recursion
void reverse(char str[], int start, int end) {
    if (start >= end) return;

    // swap
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverse(str, start + 1, end - 1); // recursive call
}

// Function 3: Check palindrome using recursion
bool isPalindrome(char str[], int start, int end) {
    if (start >= end) return true;

    if (str[start] != str[end]) return false;

    return isPalindrome(str, start + 1, end - 1);
}

// Function 4: Count words
int countWords(char str[]) {
    int count = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count; // O(n)
}

// Function 5: Most frequent character
char mostFrequent(char str[]) {
    int freq[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i]]++;
    }

    int maxFreq = 0;
    char result;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            result = i;
        }
    }

    return result; // O(n)
}

int main() {
    char str[100];

    cout << "Enter a sentence: ";
    cin.getline(str, 100);

    int length = getLength(str);

    cout << "\nLength: " << length << endl;
    cout << "Words: " << countWords(str) << endl;

    // Palindrome check
    if (isPalindrome(str, 0, length - 1))
        cout << "Palindrome: YES\n";
    else
        cout << "Palindrome: NO\n";

    // Reverse
    reverse(str, 0, length - 1);
    cout << "Reversed: " << str << endl;

    // Most frequent character
    cout << "Most frequent char: " << mostFrequent(str) << endl;

    return 0;
}