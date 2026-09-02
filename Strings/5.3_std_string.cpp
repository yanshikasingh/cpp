
/*
==================================================
                std::string

This program demonstrates the most important
std::string operations in C++.

Topics Covered:
1. String declaration
2. String initialization
3. String concatenation
4. String comparison
5. String length
6. Character access
7. substr()
8. find()
9. replace()
10. insert()
11. erase()
12. push_back()
13. pop_back()
14. String traversal
15. getline()
16. cin.ignore()
17. Practical combined example
==================================================
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Helper function to print section headings
void printSection(const string &title)
{
    cout << "\n========================================\n";
    cout << title << '\n';
    cout << "========================================\n";
}

int main()
{
    /*
    ==================================================
                1. STRING DECLARATION
    ==================================================
    */

    printSection("1. STRING DECLARATION");

    string name;

    cout << "Declared an empty string.\n";
    cout << "Value: \"" << name << "\"\n";

    /*
    ==================================================
                2. STRING INITIALIZATION
    ==================================================
    */

    printSection("2. STRING INITIALIZATION");

    string language = "C++";

    // Different ways to initialize strings
    string greeting("Hello");
    string copy = greeting;

    cout << "language: " << language << '\n';
    cout << "greeting: " << greeting << '\n';
    cout << "copy: " << copy << '\n';

    /*
    ==================================================
                3. STRING CONCATENATION
    ==================================================
    */

    printSection("3. STRING CONCATENATION");

    string firstName = "Yanshika";
    string lastName = "Singh";

    string fullName = firstName + " " + lastName;

    cout << "First name: " << firstName << '\n';
    cout << "Last name: " << lastName << '\n';
    cout << "Full name: " << fullName << '\n';

    // += modifies the existing string
    string message = "Hello";
    message += ", World!";

    cout << "Using += : " << message << '\n';

    /*
    ==================================================
                4. STRING COMPARISON
    ==================================================
    */

    printSection("4. STRING COMPARISON");

    string str1 = "apple";
    string str2 = "banana";
    string str3 = "apple";

    cout << boolalpha;

    cout << "str1 == str2: " << (str1 == str2) << '\n';
    cout << "str1 == str3: " << (str1 == str3) << '\n';

    // Lexicographical comparison
    cout << "str1 < str2: " << (str1 < str2) << '\n';
    cout << "str2 > str1: " << (str2 > str1) << '\n';

    cout << noboolalpha;

    /*
    ==================================================
                5. STRING LENGTH
    ==================================================
    */

    printSection("5. STRING LENGTH");

    string text = "Hello";

    cout << "String: " << text << '\n';
    cout << "length(): " << text.length() << '\n';
    cout << "size(): " << text.size() << '\n';
    cout << "empty(): " << boolalpha << text.empty() << '\n';

    cout << noboolalpha;

    /*
    ==================================================
                6. CHARACTER ACCESS
    ==================================================
    */

    printSection("6. CHARACTER ACCESS");

    string word = "Hello";

    // [] provides direct access but does not perform bounds checking.
    cout << "word[0]: " << word[0] << '\n';
    cout << "word[1]: " << word[1] << '\n';

    // at() performs bounds checking and can throw an exception.
    cout << "word.at(2): " << word.at(2) << '\n';

    // first() and back() access the first and last character.
    cout << "First character: " << word.front() << '\n';
    cout << "Last character: " << word.back() << '\n';

    // Modifying a character
    word[0] = 'h';

    cout << "After modification: " << word << '\n';

    /*
    ==================================================
                7. substr()
    ==================================================
    */

    printSection("7. substr()");

    string sentence = "I am learning C++";

    // substr(starting_position, number_of_characters)
    string part = sentence.substr(5, 8);

    cout << "Original string: " << sentence << '\n';
    cout << "Substring: " << part << '\n';

    // If the second argument is omitted,
    // characters are taken until the end.
    cout << "From position 14: "
         << sentence.substr(14) << '\n';

    /*
    ==================================================
                8. find()
    ==================================================
    */

    printSection("8. find()");

    string programming = "I am learning C++ programming";

    size_t position = programming.find("C++");

    cout << "String: " << programming << '\n';

    if (position != string::npos)
    {
        cout << "\"C++\" found at index: "
             << position << '\n';
    }
    else
    {
        cout << "\"C++\" was not found.\n";
    }

    // Searching for something that does not exist
    position = programming.find("Python");

    if (position == string::npos)
    {
        cout << "\"Python\" was not found.\n";
    }

    /*
    ==================================================
                9. replace()
    ==================================================
    */

    printSection("9. replace()");

    string replaceText = "I like Java";

    cout << "Before replace: " << replaceText << '\n';

    // replace(start_position, number_of_characters, new_text)
    replaceText.replace(7, 4, "C++");

    cout << "After replace: " << replaceText << '\n';

    /*
    ==================================================
                10. insert()
    ==================================================
    */

    printSection("10. insert()");

    string insertText = "Hello World";

    cout << "Before insert: " << insertText << '\n';

    // Insert text at index 5
    insertText.insert(5, ",");

    cout << "After insert: " << insertText << '\n';

    /*
    ==================================================
                11. erase()
    ==================================================
    */

    printSection("11. erase()");

    string eraseText = "Hello Beautiful World";

    cout << "Before erase: " << eraseText << '\n';

    // erase(start_position, number_of_characters)
    eraseText.erase(6, 10);

    cout << "After erase: " << eraseText << '\n';

    /*
    ==================================================
                12. push_back()
    ==================================================
    */

    printSection("12. push_back()");

    string pushText = "Hell";

    cout << "Before push_back: " << pushText << '\n';

    // Adds one character to the end.
    pushText.push_back('o');

    cout << "After push_back: " << pushText << '\n';

    /*
    ==================================================
                13. pop_back()
    ==================================================
    */

    printSection("13. pop_back()");

    string popText = "Hello!";

    cout << "Before pop_back: " << popText << '\n';

    // Removes the last character.
    popText.pop_back();

    cout << "After pop_back: " << popText << '\n';

    /*
    ==================================================
                14. STRING TRAVERSAL
    ==================================================
    */

    printSection("14. STRING TRAVERSAL");

    string traverseText = "C++";

    // ----------------------------------------------
    // A. Index-based traversal
    // ----------------------------------------------

    cout << "\nA. Index-based traversal:\n";

    for (size_t i = 0; i < traverseText.length(); i++)
    {
        cout << traverseText[i] << ' ';
    }

    cout << '\n';

    // ----------------------------------------------
    // B. Range-based traversal
    // ----------------------------------------------

    cout << "\nB. Range-based traversal:\n";

    for (char ch : traverseText)
    {
        cout << ch << ' ';
    }

    cout << '\n';

    // ----------------------------------------------
    // C. Traversal using references
    // ----------------------------------------------

    cout << "\nC. Traversal using references:\n";

    string modifyText = "hello";

    cout << "Before modification: "
         << modifyText << '\n';

    // ch refers directly to each character.
    for (char &ch : modifyText)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - ('a' - 'A');
        }
    }

    cout << "After modification: "
         << modifyText << '\n';

    /*
    ==================================================
                15. getline()
    ==================================================
    */

    printSection("15. getline()");

    cout << "Enter your full name: ";

    string userName;

    // getline() reads the complete line,
    // including spaces, until '\n'.
    getline(cin, userName);

    cout << "Your name is: "
         << userName << '\n';

    /*
    ==================================================
                16. cin.ignore() WITH getline()
    ==================================================
    */

    printSection("16. cin.ignore() AND getline()");

    int age;

    cout << "Enter your age: ";
    cin >> age;

    /*
    After cin >> age, the newline character remains
    in the input buffer.

    ignore() removes characters until '\n'.
    */
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string city;

    cout << "Enter your city: ";

    getline(cin, city);

    cout << "Age: " << age << '\n';
    cout << "City: " << city << '\n';

    /*
    ==================================================
                17. PRACTICAL COMBINED EXAMPLE
    ==================================================
    */

    printSection("17. PRACTICAL COMBINED EXAMPLE");

    string input;

    cout << "Enter a programming language: ";
    getline(cin, input);

    cout << "\nOriginal input: "
         << input << '\n';

    cout << "Length: "
         << input.length() << '\n';

    // Check whether the string contains "C++".
    size_t found = input.find("C++");

    if (found != string::npos)
    {
        cout << "The input contains C++ at index "
             << found << ".\n";
    }
    else
    {
        cout << "The input does not contain C++.\n";
    }

    // Add a character if needed.
    if (!input.empty())
    {
        input.push_back('!');

        cout << "After push_back: "
             << input << '\n';

        input.pop_back();

        cout << "After pop_back: "
             << input << '\n';
    }

    // Traverse and display every character.
    cout << "\nCharacters:\n";

    for (size_t i = 0; i < input.size(); i++)
    {
        cout << "Index " << i
             << ": " << input[i] << '\n';
    }

    /*
    ==================================================
                PROGRAM COMPLETE
    ==================================================
    */

    printSection("PROGRAM COMPLETE");

    cout << "You have demonstrated the major "
         << "std::string operations.\n";

    return 0;
}
