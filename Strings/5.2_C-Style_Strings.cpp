#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
    // ==================================================
    // 1. CHARACTER STORAGE
    // ==================================================
    //
    // A C-style string is stored inside a character array.
    // C++ stores each character in a separate array index.
    //
    // "Hello" is internally:
    //
    // Index:    0   1   2   3   4    5
    // Value:    H   e   l   l   o   \0
    //
    // '\0' is called the Null Terminator.
    // It tells C++ where the string ends.

    char name[] = "Hello";

    cout << "String: " << name << endl;

    // Example:
    //
    // name[0] = 'H'
    // name[1] = 'e'
    // name[2] = 'l'
    // name[3] = 'l'
    // name[4] = 'o'
    // name[5] = '\0'

    // ==================================================
    // 2. TRAVERSING
    // ==================================================
    //
    // Traversing means moving through the string
    // one character at a time.
    //
    // We start from index 0 and continue until '\0'.

    cout << "\nTraversing the string:\n";

    int i = 0;

    while (name[i] != '\0')
    {
        // Current character:
        // name[i]
        //
        // After processing the character,
        // i++ moves to the next index.

        cout << "Index " << i
             << " = " << name[i] << endl;

        i++;
    }

    // When name[i] becomes '\0',
    // the condition becomes false and the loop stops.

    // ==================================================
    // 3. LENGTH - strlen()
    // ==================================================
    //
    // strlen() counts how many characters exist
    // before the Null Terminator '\0'.
    //
    // It does NOT count '\0'.

    int length = strlen(name);

    cout << "\nLength = " << length << endl;

    // Example backend idea:
    //
    // int count = 0;
    //
    // while (name[count] != '\0')
    // {
    //     count++;
    // }
    //
    // return count;
    //
    // Execution for "Hello":
    //
    // H -> count = 1
    // e -> count = 2
    // l -> count = 3
    // l -> count = 4
    // o -> count = 5
    // \0 -> STOP

    // ==================================================
    // 4. COPYING - strcpy()
    // ==================================================
    //
    // Copying means taking all characters from one
    // string and placing them into another string.

    char source[] = "Apple";
    char destination[20];

    // Before copying:
    //
    // source      = Apple
    // destination = empty/uninitialized storage

    strcpy(destination, source);

    cout << "\nSource      = " << source << endl;
    cout << "Destination = " << destination << endl;

    // Backend idea:
    //
    // source[0] -> destination[0]
    // source[1] -> destination[1]
    // source[2] -> destination[2]
    // ...
    //
    // Finally:
    //
    // '\0' is also copied so destination becomes
    // a complete C-style string.

    // ==================================================
    // 5. CONCATENATION - strcat()
    // ==================================================
    //
    // Concatenation means joining two strings.
    //
    // Example:
    //
    // "Hello " + "World"
    //
    // Result:
    //
    // "Hello World"

    // The first array needs enough space for both strings.

    char first[30] = "Hello ";
    char second[] = "World";

    strcat(first, second);

    cout << "\nAfter concatenation = "
         << first << endl;

    // Backend idea:
    //
    // Step 1:
    // Find '\0' at the end of first.
    //
    // Hello \0
    //       ^
    //
    // Step 2:
    // Start copying second from that position.
    //
    // Copy W
    // Copy o
    // Copy r
    // Copy l
    // Copy d
    //
    // Step 3:
    // Add '\0' at the final position.

    // ==================================================
    // 6. COMPARISON - strcmp()
    // ==================================================
    //
    // strcmp() compares two strings character by character.

    char str1[] = "Apple";
    char str2[] = "Apply";

    int result = strcmp(str1, str2);

    cout << "\nComparison result = "
         << result << endl;

    // Backend idea:
    //
    // A vs A -> Same
    // p vs p -> Same
    // p vs p -> Same
    // l vs l -> Same
    // e vs y -> Different
    //
    // The comparison stops at the first difference.
    //
    // Result:
    //
    // 0  -> Both strings are equal
    // <0 -> First string comes before second
    // >0 -> First string comes after second

    // ==================================================
    // 7. SEARCHING FOR A CHARACTER - strchr()
    // ==================================================
    //
    // strchr() searches for a character inside a string.

    char text[] = "Hello World";

    char *found = strchr(text, 'W');

    if (found != nullptr)
    {
        cout << "\nCharacter 'W' found at index = "
             << found - text << endl;
    }

    // Backend idea:
    //
    // H == W ? No
    // e == W ? No
    // l == W ? No
    // ...
    // W == W ? Yes -> FOUND
    //
    // strchr() returns the address of the found character.

    // ==================================================
    // 8. SEARCHING FOR A SUBSTRING - strstr()
    // ==================================================
    //
    // strstr() searches for one complete string
    // inside another string.

    char *position = strstr(text, "World");

    if (position != nullptr)
    {
        cout << "\n\"World\" found at index = "
             << position - text << endl;
    }

    // Example:
    //
    // Main String:
    //
    // Hello World
    //       ^
    //
    // Search:
    //
    // World
    //
    // When all characters match in sequence,
    // the substring is found.

    // ==================================================
    // 9. MODIFICATION
    // ==================================================
    //
    // Since a C-style string is a character array,
    // individual characters can be changed using indexes.

    char modify[] = "Hello";

    cout << "\nBefore modification = "
         << modify << endl;

    modify[0] = 'J';

    cout << "After modification  = "
         << modify << endl;

    // Internally:
    //
    // Before:
    //
    // H e l l o \0
    // ^
    //
    // Replace H with J
    //
    // After:
    //
    // J e l l o \0

    // ==================================================
    // 10. REVERSING
    // ==================================================
    //
    // Reversing means changing the order of characters.
    //
    // Hello -> olleH

    char reverse[] = "Hello";

    int left = 0;
    int right = strlen(reverse) - 1;

    while (left < right)
    {
        // Store left character temporarily.

        char temp = reverse[left];

        // Put right character on the left.

        reverse[left] = reverse[right];

        // Put original left character on the right.

        reverse[right] = temp;

        // Move both sides inward.

        left++;
        right--;
    }

    cout << "\nReversed string = "
         << reverse << endl;

    // Example:
    //
    // H e l l o
    // ^       ^
    //
    // Swap H and o
    //
    // o e l l H
    //   ^   ^
    //
    // Swap e and l
    //
    // o l l e H

    // ==================================================
    // 11. CASE CONVERSION
    // ==================================================
    //
    // Case conversion works by traversing each character.

    char message[] = "Hello";

    cout << "\nOriginal = "
         << message << endl;

    for (int k = 0; message[k] != '\0'; k++)
    {
        // toupper() converts the current character
        // into uppercase.

        message[k] =
            toupper(static_cast<unsigned char>(message[k]));
    }

    cout << "Uppercase = "
         << message << endl;

    // Backend idea:
    //
    // H -> H
    // e -> E
    // l -> L
    // l -> L
    // o -> O
    // \0 -> STOP

    // ==================================================
    // 12. TOKENIZATION - strtok()
    // ==================================================
    //
    // Tokenization means splitting one string
    // into smaller parts using a delimiter.
    //
    // Example:
    //
    // Apple,Banana,Mango
    //
    // Delimiter = ','

    char fruits[] = "Apple,Banana,Mango";

    char *token = strtok(fruits, ",");

    cout << "\nTokens:\n";

    while (token != nullptr)
    {
        cout << token << endl;

        // Passing nullptr tells strtok() to continue
        // from where the previous search stopped.

        token = strtok(nullptr, ",");
    }

    // Result:
    //
    // Apple
    // Banana
    // Mango
    //
    // Important:
    //
    // strtok() modifies the original character array.

    // ==================================================
    // 13. INPUT AND OUTPUT
    // ==================================================
    //
    // cin.getline() can read spaces into a C-style string.

    char userName[100];

    cout << "\nEnter your full name: ";

    cin.getline(userName, 100);

    cout << "You entered: "
         << userName << endl;

    // Backend idea:
    //
    // User types characters
    //
    //        ↓
    //
    // They are stored one by one:
    //
    // userName[0]
    // userName[1]
    // userName[2]
    // ...
    //
    //        ↓
    //
    // '\0' marks the end of the string.

    return 0;
}