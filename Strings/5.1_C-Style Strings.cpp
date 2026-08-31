#include <iostream>
#include <cctype>

using namespace std;

/*
================================================================================
                    CHARACTER FUNCTIONS IN C++
================================================================================

Character functions are used to check or modify individual characters.

In C++, these functions are available in the <cctype> header file.

Some commonly used character functions are:

    isalpha()   -> Checks whether a character is an alphabet.
    isdigit()   -> Checks whether a character is a digit.
    isalnum()   -> Checks whether a character is alphabet or digit.
    islower()   -> Checks whether a character is lowercase.
    isupper()   -> Checks whether a character is uppercase.
    isspace()   -> Checks whether a character is whitespace.
    ispunct()   -> Checks whether a character is punctuation.
    tolower()   -> Converts a character to lowercase.
    toupper()   -> Converts a character to uppercase.

IMPORTANT IDEA:
----------------

A character is internally represented using a numeric value.

For example, in ASCII:

    'A' = 65
    'B' = 66
    ...
    'Z' = 90

    'a' = 97
    'b' = 98
    ...
    'z' = 122

    '0' = 48
    '1' = 49
    ...
    '9' = 57

Because these characters have consecutive numeric values, we can check
their category using comparisons.

For example:

    ch >= 'A' && ch <= 'Z'

checks whether ch is an uppercase alphabet.

================================================================================
*/


int main()
{
    char ch;

    cout << "Enter a character: ";
    cin >> ch;


    /*
    ============================================================================
                            1. isalpha()
    ============================================================================

    isalpha(ch) checks whether the character is an alphabet.

    It returns TRUE if the character is:

        A to Z
        OR
        a to z

    CONCEPTUAL LOGIC:

        (ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z')

    Example:

        isalpha('A')  -> True
        isalpha('z')  -> True
        isalpha('5')  -> False
        isalpha('@')  -> False

    ============================================================================
    */

    if (isalpha(ch))
    {
        cout << ch << " is an alphabet.\n";
    }
    else
    {
        cout << ch << " is NOT an alphabet.\n";
    }


    /*
    ============================================================================
                            2. isdigit()
    ============================================================================

    isdigit(ch) checks whether the character is a digit.

    A digit is:

        0, 1, 2, 3, 4, 5, 6, 7, 8, or 9

    CONCEPTUAL LOGIC:

        ch >= '0' && ch <= '9'

    Example:

        isdigit('5')  -> True
        isdigit('0')  -> True
        isdigit('A')  -> False

    ============================================================================
    */

    if (isdigit(ch))
    {
        cout << ch << " is a digit.\n";
    }
    else
    {
        cout << ch << " is NOT a digit.\n";
    }


    /*
    ============================================================================
                            3. isalnum()
    ============================================================================

    isalnum(ch) checks whether the character is:

        An alphabet
                OR
        A digit

    It is equivalent conceptually to:

        isalpha(ch) || isdigit(ch)

    Example:

        isalnum('A')  -> True
        isalnum('a')  -> True
        isalnum('7')  -> True
        isalnum('@')  -> False

    ============================================================================
    */

    if (isalnum(ch))
    {
        cout << ch << " is alphanumeric.\n";
    }
    else
    {
        cout << ch << " is NOT alphanumeric.\n";
    }


    /*
    ============================================================================
                            4. islower()
    ============================================================================

    islower(ch) checks whether a character is a lowercase alphabet.

    CONCEPTUAL LOGIC:

        ch >= 'a' && ch <= 'z'

    Example:

        islower('a')  -> True
        islower('z')  -> True
        islower('A')  -> False
        islower('5')  -> False

    ============================================================================
    */

    if (islower(ch))
    {
        cout << ch << " is lowercase.\n";
    }
    else
    {
        cout << ch << " is NOT lowercase.\n";
    }


    /*
    ============================================================================
                            5. isupper()
    ============================================================================

    isupper(ch) checks whether a character is an uppercase alphabet.

    CONCEPTUAL LOGIC:

        ch >= 'A' && ch <= 'Z'

    Example:

        isupper('A')  -> True
        isupper('Z')  -> True
        isupper('a')  -> False

    ============================================================================
    */

    if (isupper(ch))
    {
        cout << ch << " is uppercase.\n";
    }
    else
    {
        cout << ch << " is NOT uppercase.\n";
    }


    /*
    ============================================================================
                            6. isspace()
    ============================================================================

    isspace(ch) checks whether a character represents whitespace.

    Common whitespace characters include:

        ' '   -> Space
        '\n'  -> New line
        '\t'  -> Tab
        '\r'  -> Carriage return

    Note:

    Since cin >> ch ignores normal spaces and newlines, testing isspace()
    properly may require getline() or cin.get().

    CONCEPTUAL LOGIC:

        ch == ' '  ||
        ch == '\n' ||
        ch == '\t' ||
        ch == '\r'

    ============================================================================
    */

    /*
    if (isspace(ch))
    {
        cout << "The character is whitespace.\n";
    }
    */


    /*
    ============================================================================
                            7. ispunct()
    ============================================================================

    ispunct(ch) checks whether a character is a punctuation character.

    Examples include:

        !
        @
        #
        $
        %
        &
        *
        (
        )
        .
        ,
        ?

    Example:

        ispunct('!')  -> True
        ispunct('@')  -> True
        ispunct('A')  -> False
        ispunct('5')  -> False

    ============================================================================
    */

    if (ispunct(ch))
    {
        cout << ch << " is a punctuation character.\n";
    }


    /*
    ============================================================================
                            8. toupper()
    ============================================================================

    toupper(ch) converts a lowercase alphabet into uppercase.

    Example:

        'a' -> 'A'
        'b' -> 'B'
        'z' -> 'Z'

    If the character is already uppercase, it remains unchanged.

    CONCEPTUAL ASCII IDEA:

        'a' = 97
        'A' = 65

        Difference = 32

    Therefore, conceptually:

        'a' - 32 = 'A'

    However, in actual programs, we should use:

        toupper(ch)

    instead of manually adding or subtracting numbers.

    ============================================================================
    */

    cout << "Uppercase version: "
         << static_cast<char>(toupper(ch))
         << endl;


    /*
    ============================================================================
                            9. tolower()
    ============================================================================

    tolower(ch) converts an uppercase alphabet into lowercase.

    Example:

        'A' -> 'a'
        'B' -> 'b'
        'Z' -> 'z'

    If the character is already lowercase, it remains unchanged.

    CONCEPTUAL IDEA:

        'A' = 65
        'a' = 97

        Difference = 32

    Therefore, conceptually:

        'A' + 32 = 'a'

    ============================================================================
    */

    cout << "Lowercase version: "
         << static_cast<char>(tolower(ch))
         << endl;


    /*
    ============================================================================
                    HOW DO THESE FUNCTIONS ACTUALLY WORK?
    ============================================================================

    The basic idea is:

            CHARACTER
                |
                v
        Stored internally as a number
                |
                v
        Function checks its properties
                |
                v
        TRUE or FALSE is returned

    Example:

        char ch = 'G';

    Internally, 'G' has a numeric representation.

    A conceptual alphabet check is:

        (ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z')

    For 'G':

        'G' >= 'A'  -> True
        'G' <= 'Z'  -> True

    Therefore:

        'G' is an alphabet.

    IMPORTANT:

    The actual implementation of <cctype> functions inside the C++ library
    may be more optimized.

    The library may use lookup tables.

    Conceptually:

        Character       Properties
        ------------------------------------------------
        'A'             Alphabet, Uppercase
        'a'             Alphabet, Lowercase
        '5'             Digit
        ' '             Whitespace
        '!'             Punctuation

    Instead of checking many conditions repeatedly, the library can quickly
    look up the properties of the character.

    ============================================================================
    */

    return 0;
}