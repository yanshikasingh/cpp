/*
==============================================================
        INTEGER LITERALS & NUMBER SYSTEMS IN C++
==============================================================

TOPIC:
    Integer Literals
    Decimal, Octal, Hexadecimal and Binary

--------------------------------------------------------------
WHAT IS AN INTEGER LITERAL?
--------------------------------------------------------------

An integer literal is a whole number written directly in
a C/C++ program.

Example:

    int age = 20;

Here:

    20 -> integer literal

The value is written directly in the source code.

C++ allows integer literals to be written in different
number systems (bases).

--------------------------------------------------------------
NUMBER SYSTEMS
--------------------------------------------------------------

1. Decimal       -> Base 10
2. Octal         -> Base 8
3. Hexadecimal   -> Base 16
4. Binary        -> Base 2

The way we WRITE the number tells C++ which number system
we are using.

==============================================================
1. DECIMAL INTEGER LITERAL
==============================================================

Decimal = Base 10

It uses:

    0 1 2 3 4 5 6 7 8 9

Normally, when we write an integer without a special
prefix, C++ treats it as decimal.

Example:

    int a = 500;

Here:

    500 -> Decimal
    Value -> 500

--------------------------------------------------------------
EXAMPLE 1
--------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
    int a = 500;

    cout << "Decimal value: " << a << endl;

    return 0;
}

/*
OUTPUT:

    Decimal value: 500


==============================================================
2. OCTAL INTEGER LITERAL
==============================================================

Octal = Base 8

It uses only:

    0 1 2 3 4 5 6 7

In C/C++, an integer literal beginning with 0 is treated
as an OCTAL integer literal.

Example:

    int a = 0500;

The leading 0 tells C++:

    "This number is written in octal."

IMPORTANT:

    0500 is NOT decimal 500.

--------------------------------------------------------------
CONVERTING 0500 FROM OCTAL TO DECIMAL
--------------------------------------------------------------

    0500 (octal)

    = 5 × 8² + 0 × 8¹ + 0 × 8⁰

    = 5 × 64 + 0 × 8 + 0 × 1

    = 320

Therefore:

    0500 (octal) = 320 (decimal)

--------------------------------------------------------------
EXAMPLE 2
--------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
    int a = 0500;

    cout << "Value of 0500: " << a << endl;

    return 0;
}

/*
OUTPUT:

    Value of 0500: 320

--------------------------------------------------------------
IMPORTANT
--------------------------------------------------------------

C++ is NOT converting decimal 500 into octal here.

Instead:

    0500
      ↓
    C++ sees the leading 0
      ↓
    Interprets it as an octal literal
      ↓
    Its actual integer value is 320
      ↓
    320 is stored in variable 'a'

So:

    int a = 0500;

is effectively storing:

    int a = 320;

==============================================================
3. WHY DOES 0 MEAN OCTAL?
==============================================================

This is a syntax convention inherited from the C language.

The prefix of an integer literal tells C/C++ how the
number should be interpreted.

Examples:

    500       -> Decimal
    0500      -> Octal
    0x500     -> Hexadecimal
    0b1010    -> Binary

This is about the LITERAL itself.

It is NOT related to the data type.

For example:

    int a = 500;
    int b = 0500;

Both 'a' and 'b' are of type:

    int

But their values are different:

    a = 500
    b = 320

==============================================================
4. HEXADECIMAL INTEGER LITERAL
==============================================================

Hexadecimal = Base 16

It uses:

    0 1 2 3 4 5 6 7 8 9 A B C D E F

The prefixes are:

    0x
    0X

Example:

    int a = 0x19;

Conversion:

    0x19

    = 1 × 16¹ + 9 × 16⁰

    = 16 + 9

    = 25

Therefore:

    0x19 = 25 decimal

--------------------------------------------------------------
EXAMPLE 3
--------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
    int a = 0x19;

    cout << "Value of 0x19: " << a << endl;

    return 0;
}

/*
OUTPUT:

    Value of 0x19: 25


==============================================================
5. BINARY INTEGER LITERAL
==============================================================

Binary = Base 2

It uses only:

    0 and 1

C++ supports binary literals using:

    0b
    0B

Example:

    int a = 0b11001;

Conversion:

    0b11001

    = 1 × 2⁴
    + 1 × 2³
    + 0 × 2²
    + 0 × 2¹
    + 1 × 2⁰

    = 16 + 8 + 0 + 0 + 1

    = 25

Therefore:

    0b11001 = 25 decimal

--------------------------------------------------------------
EXAMPLE 4
--------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
    int a = 0b11001;

    cout << "Value of 0b11001: " << a << endl;

    return 0;
}

/*
OUTPUT:

    Value of 0b11001: 25


==============================================================
6. SAME VALUE IN DIFFERENT NUMBER SYSTEMS
==============================================================

The same value can be written in different number systems.

For example, decimal 25 can be represented as:

    Decimal       -> 25
    Octal         -> 031
    Hexadecimal   -> 0x19
    Binary        -> 0b11001

All of them represent:

    25 decimal

--------------------------------------------------------------
EXAMPLE 5
--------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
    int decimal = 25;
    int octal = 031;
    int hexadecimal = 0x19;
    int binary = 0b11001;

    cout << "Decimal:     " << decimal << endl;
    cout << "Octal:       " << octal << endl;
    cout << "Hexadecimal: " << hexadecimal << endl;
    cout << "Binary:      " << binary << endl;

    return 0;
}

/*
OUTPUT:

    Decimal:     25
    Octal:       25
    Hexadecimal: 25
    Binary:      25

Notice that all variables contain the SAME VALUE:

    25

Only the way the literals were WRITTEN was different.

==============================================================
7. IMPORTANT EXAMPLE WITH MAP
==============================================================

Suppose we have:

    map<string, int> student;

This means:

    KEY   -> string
    VALUE -> int

Now consider:

    {"Vaibhav", 0500}

It contains:

    "Vaibhav" -> string
    0500      -> integer literal

The map does NOT convert 0500 into octal.

The compiler has already interpreted 0500 as octal
before the value is stored in the map.

Therefore:

    0500 (octal)
        ↓
    320 (decimal value)
        ↓
    stored in map

So the map actually stores:

    "Vaibhav" -> 320

--------------------------------------------------------------
EXAMPLE 6
--------------------------------------------------------------
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> student =
        {
            {"Yash", 7800},
            {"Yukta", 5555},
            {"Ritesh", 8088},
            {"Vaibhav", 0500}};

    for (map<string, int>::iterator itr = student.begin();
         itr != student.end();
         itr++)
    {
        cout << itr->first << " "
             << itr->second << endl;
    }

    return 0;
}

/*
OUTPUT:

    Ritesh 8088
    Vaibhav 320
    Yash 7800
    Yukta 5555

The important part is:

    {"Vaibhav", 0500}

    0500 (octal)
       ↓
    320 (decimal)
       ↓
    stored as int
       ↓
    output = 320

==============================================================
8. IF YOU ACTUALLY WANT 500
==============================================================

Write:

    {"Vaibhav", 500}

NOT:

    {"Vaibhav", 0500}

Because:

    500  -> decimal 500

while:

    0500 -> octal -> decimal 320

--------------------------------------------------------------
EXAMPLE 7
--------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int main()
{
    int a = 500;
    int b = 0500;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}

/*
OUTPUT:

    a = 500
    b = 320

==============================================================
9. QUICK REFERENCE TABLE
==============================================================

    LITERAL        NUMBER SYSTEM       DECIMAL VALUE

    500            Decimal             500

    0500           Octal               320

    0x500          Hexadecimal         1280

    0b1010         Binary              10


--------------------------------------------------------------
PREFIX RULE
--------------------------------------------------------------

    No special prefix
            ↓
        Decimal

    0
            ↓
        Octal

    0x / 0X
            ↓
        Hexadecimal

    0b / 0B
            ↓
        Binary


==============================================================
10. MOST IMPORTANT THING TO REMEMBER
==============================================================

When C++ sees:

    500

it reads it as:

    Decimal 500


When C++ sees:

    0500

the leading 0 tells it:

    "This literal is OCTAL."

Therefore:

    0500₈ = 320₁₀


When C++ sees:

    0x500

the 0x tells it:

    "This literal is HEXADECIMAL."


When C++ sees:

    0b1010

the 0b tells it:

    "This literal is BINARY."


==============================================================
KEY CONCEPT
==============================================================

The concept is called:

    INTEGER LITERALS
        ↓
    NUMBER SYSTEM / BASE NOTATION
        ↓
    Decimal / Octal / Hexadecimal / Binary


Remember:

    0500 is NOT being converted from decimal to octal.

    0500 is ALREADY written as an octal literal.

    C++ then evaluates its value:

        0500₈ = 320₁₀


Also remember:

    map<string, int>

does NOT cause the octal behavior.

The compiler interprets the integer literal first.


==============================================================
END OF NOTES
==============================================================
*/