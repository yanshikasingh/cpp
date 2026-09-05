/*
============================================================
TOPIC: Character Functions
LANGUAGE: C
============================================================

PRACTICE PROGRESS

[x] Q01 — Concept / Application
[ ] Q02 — Concept / Application
[ ] Q03 — Medium
[ ] Q04 — Medium
[ ] Q05 — Medium
[ ] Q06 — Medium
[ ] Q07 — Hard
[ ] Q08 — Hard
[ ] Q09 — Hard
[ ] Q10 — Hard

============================================================

QUESTIONS

01–02   Concept / Application
03–06   Medium
07–10   Hard

============================================================

C PRACTICE NOTES
============================================================

Use the C equivalents from <ctype.h> where appropriate.
The same logical requirements as the C++ file must be followed.

This file intentionally contains no solution code.
Write and test one question at a time.

============================================================
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
The includes above are only a minimal starting point.
Add other standard C headers only when your solution genuinely needs them.
*/

/*
============================================================
QUESTION 01 — Input Character Classifier

DIFFICULTY:
Concept / Application

CONCEPTS TESTED:
- isalpha()
- isdigit()
- isalnum()
- islower()
- isupper()
- ispunct()

------------------------------------------------------------
PROBLEM
------------------------------------------------------------

Build a character classifier for a single input character.

Read exactly one character and report every applicable category:
alphabet, digit, alphanumeric, lowercase, uppercase, punctuation, and whitespace.

A character may belong to more than one category. For example, an alphabetic
character can also be alphanumeric.

Do not assume that only one category can be true.

------------------------------------------------------------
INPUT
------------------------------------------------------------

Read one character. The character may be a visible character or whitespace.

------------------------------------------------------------
OUTPUT
------------------------------------------------------------

Print the character's applicable categories. If none of the listed
categories applies, report that no listed category applies.

------------------------------------------------------------
REQUIREMENTS
------------------------------------------------------------

- Use the character classification functions from this topic.
- Do not hard-code ASCII numeric ranges.
- Do not stop after finding the first matching category.

------------------------------------------------------------
CONSTRAINTS
------------------------------------------------------------

Use individual-character input so that a whitespace character can be tested.

------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

Input:
[Write an example input here.]

Output:
[Write the expected output here.]

------------------------------------------------------------
EDGE CASES TO CONSIDER
------------------------------------------------------------

- space, tab, newline
- uppercase/lowercase letters
- digits
- punctuation
- a character matching multiple categories

------------------------------------------------------------
MY APPROACH
------------------------------------------------------------

Write your approach here before coding:




------------------------------------------------------------
MY SOLUTION
------------------------------------------------------------
*/

/*
Write your solution for Question 01 here.

For practice, keep only the question you are currently solving active
when compiling this file.
*/

/*
------------------------------------------------------------
WHAT I LEARNED
------------------------------------------------------------




------------------------------------------------------------
MISTAKES / DEBUGGING NOTES
------------------------------------------------------------




============================================================
END QUESTION 01
============================================================
*/


/*
============================================================
QUESTION 02 — Text Character Statistics

DIFFICULTY:
Concept / Application

CONCEPTS TESTED:
- isalpha()
- isdigit()
- isalnum()
- islower()
- isupper()
- isspace()
- ispunct()

------------------------------------------------------------
PROBLEM
------------------------------------------------------------

Read a line of text and produce a character statistics report.

Count how many characters are alphabets, digits, whitespace characters,
punctuation characters, uppercase letters, and lowercase letters.

The report should also contain the total number of characters and the number
of alphanumeric characters.

------------------------------------------------------------
INPUT
------------------------------------------------------------

A complete line of text, including spaces and punctuation.

------------------------------------------------------------
OUTPUT
------------------------------------------------------------

Print each requested count clearly.

------------------------------------------------------------
REQUIREMENTS
------------------------------------------------------------

- Process the complete line rather than only the first word.
- Use character functions for classification.
- Whitespace must be included in the analysis.

------------------------------------------------------------
CONSTRAINTS
------------------------------------------------------------

The input may contain spaces, repeated punctuation, digits, and mixed case.

------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

Input:
[Write an example input here.]

Output:
[Write the expected output here.]

------------------------------------------------------------
EDGE CASES TO CONSIDER
------------------------------------------------------------

- empty line
- only whitespace
- only punctuation
- mixed letters/digits/symbols
- leading or trailing spaces

------------------------------------------------------------
MY APPROACH
------------------------------------------------------------

Write your approach here before coding:




------------------------------------------------------------
MY SOLUTION
------------------------------------------------------------
*/

/*
Write your solution for Question 02 here.

For practice, keep only the question you are currently solving active
when compiling this file.
*/

/*
------------------------------------------------------------
WHAT I LEARNED
------------------------------------------------------------




------------------------------------------------------------
MISTAKES / DEBUGGING NOTES
------------------------------------------------------------




============================================================
END QUESTION 02
============================================================
*/


/*
============================================================
QUESTION 03 — Username Validator

DIFFICULTY:
Medium

CONCEPTS TESTED:
- isalpha()
- isdigit()
- isalnum()
- islower()
- isupper()
- isspace()
- ispunct()

------------------------------------------------------------
PROBLEM
------------------------------------------------------------

Create a username validation program.

A username is valid only if it follows all of these rules:
- Length is between 6 and 15 characters inclusive.
- Every character is alphanumeric.
- At least one alphabetic character is present.
- At least one digit is present.
- No whitespace or punctuation is allowed.

Report whether the username is valid and, if invalid, report which rules were
violated.

------------------------------------------------------------
INPUT
------------------------------------------------------------

A single username without spaces between separate input fields.

------------------------------------------------------------
OUTPUT
------------------------------------------------------------

Print VALID when every rule passes. Otherwise print INVALID and the violated rules.

------------------------------------------------------------
REQUIREMENTS
------------------------------------------------------------

- Check every character.
- Use character classification rather than ASCII-number comparisons.
- A username can violate multiple rules at the same time.

------------------------------------------------------------
CONSTRAINTS
------------------------------------------------------------

Username length is limited to 15 characters.

------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

Input:
[Write an example input here.]

Output:
[Write the expected output here.]

------------------------------------------------------------
EDGE CASES TO CONSIDER
------------------------------------------------------------

- too short
- too long
- all digits
- all letters
- punctuation
- whitespace
- multiple violations

------------------------------------------------------------
MY APPROACH
------------------------------------------------------------

Write your approach here before coding:




------------------------------------------------------------
MY SOLUTION
------------------------------------------------------------
*/

/*
Write your solution for Question 03 here.

For practice, keep only the question you are currently solving active
when compiling this file.
*/

/*
------------------------------------------------------------
WHAT I LEARNED
------------------------------------------------------------




------------------------------------------------------------
MISTAKES / DEBUGGING NOTES
------------------------------------------------------------




============================================================
END QUESTION 03
============================================================
*/


/*
============================================================
QUESTION 04 — Password Strength Analyzer

DIFFICULTY:
Medium

CONCEPTS TESTED:
- isalpha()
- isdigit()
- isalnum()
- islower()
- isupper()
- ispunct()
- isspace()

------------------------------------------------------------
PROBLEM
------------------------------------------------------------

Build a password strength analyzer.

Analyze a password and report whether it satisfies these requirements:
- At least 8 characters.
- At least one uppercase letter.
- At least one lowercase letter.
- At least one digit.
- At least one punctuation character.
- No whitespace characters.

Classify the password as STRONG when all requirements are satisfied;
otherwise classify it as WEAK and report the missing requirements.

------------------------------------------------------------
INPUT
------------------------------------------------------------

A complete password line.

------------------------------------------------------------
OUTPUT
------------------------------------------------------------

Print the strength classification and the unmet requirements, if any.

------------------------------------------------------------
REQUIREMENTS
------------------------------------------------------------

- Treat punctuation as a character category, not as a specific list of symbols.
- A character may contribute to more than one property.
- Do not reveal or transform the password in the output.

------------------------------------------------------------
CONSTRAINTS
------------------------------------------------------------

Do not impose extra password rules beyond those specified.

------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

Input:
[Write an example input here.]

Output:
[Write the expected output here.]

------------------------------------------------------------
EDGE CASES TO CONSIDER
------------------------------------------------------------

- exactly 8 characters
- multiple missing categories
- whitespace
- only one character category
- punctuation at the beginning/end

------------------------------------------------------------
MY APPROACH
------------------------------------------------------------

Write your approach here before coding:




------------------------------------------------------------
MY SOLUTION
------------------------------------------------------------
*/

/*
Write your solution for Question 04 here.

For practice, keep only the question you are currently solving active
when compiling this file.
*/

/*
------------------------------------------------------------
WHAT I LEARNED
------------------------------------------------------------




------------------------------------------------------------
MISTAKES / DEBUGGING NOTES
------------------------------------------------------------




============================================================
END QUESTION 04
============================================================
*/


/*
============================================================
QUESTION 05 — Text Sanitizer

DIFFICULTY:
Medium

CONCEPTS TESTED:
- isalpha()
- isdigit()
- isalnum()
- isspace()
- ispunct()
- toupper()
- tolower()

------------------------------------------------------------
PROBLEM
------------------------------------------------------------

Create a text sanitizer that processes a complete line.

Produce a normalized version of the text according to these rules:
- Convert alphabetic characters to lowercase.
- Keep digits unchanged.
- Preserve single spaces between words.
- Remove punctuation characters.
- Do not preserve leading or trailing whitespace.
- Consecutive whitespace characters should become one space.

The relative order of all retained characters must remain unchanged.

------------------------------------------------------------
INPUT
------------------------------------------------------------

A complete line of text that may contain letters, digits, punctuation, spaces, tabs, or other whitespace.

------------------------------------------------------------
OUTPUT
------------------------------------------------------------

Print the sanitized text.

------------------------------------------------------------
REQUIREMENTS
------------------------------------------------------------

- Use character classification functions.
- Use tolower() for alphabetic conversion.
- Whitespace normalization must work for more than ordinary spaces.
- Do not change the order of retained characters.

------------------------------------------------------------
CONSTRAINTS
------------------------------------------------------------

The input line may contain arbitrary runs of whitespace and punctuation.

------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

Input:
[Write an example input here.]

Output:
[Write the expected output here.]

------------------------------------------------------------
EDGE CASES TO CONSIDER
------------------------------------------------------------

- empty input
- only punctuation
- only whitespace
- multiple spaces/tabs
- mixed punctuation and words
- digits adjacent to letters

------------------------------------------------------------
MY APPROACH
------------------------------------------------------------

Write your approach here before coding:




------------------------------------------------------------
MY SOLUTION
------------------------------------------------------------
*/

/*
Write your solution for Question 05 here.

For practice, keep only the question you are currently solving active
when compiling this file.
*/

/*
------------------------------------------------------------
WHAT I LEARNED
------------------------------------------------------------




------------------------------------------------------------
MISTAKES / DEBUGGING NOTES
------------------------------------------------------------




============================================================
END QUESTION 05
============================================================
*/


/*
============================================================
QUESTION 06 — Log Line Analyzer

DIFFICULTY:
Medium

CONCEPTS TESTED:
- isalpha()
- isdigit()
- isalnum()
- islower()
- isupper()
- isspace()
- ispunct()
- toupper()
- tolower()

------------------------------------------------------------
PROBLEM
------------------------------------------------------------

Analyze a log line and produce a compact report.

For the supplied line, determine:
- total characters
- alphabetic characters
- digits
- uppercase letters
- lowercase letters
- whitespace characters
- punctuation characters
- the number of alphanumeric characters

Also produce a lowercase normalized copy of the line while preserving
whitespace and punctuation.

Finally, report the percentage of the characters that are alphanumeric.
Handle the case where the input contains zero characters without producing an
invalid calculation.

------------------------------------------------------------
INPUT
------------------------------------------------------------

A complete log line.

------------------------------------------------------------
OUTPUT
------------------------------------------------------------

Print the requested statistics, normalized line, and alphanumeric percentage.

------------------------------------------------------------
REQUIREMENTS
------------------------------------------------------------

- Do not remove characters while producing the normalized copy.
- Use the same classification rules consistently.
- Avoid division by zero.

------------------------------------------------------------
CONSTRAINTS
------------------------------------------------------------

The line length is not specified; design the input handling accordingly.

------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

Input:
[Write an example input here.]

Output:
[Write the expected output here.]

------------------------------------------------------------
EDGE CASES TO CONSIDER
------------------------------------------------------------

- empty line
- all whitespace
- all punctuation
- all alphanumeric
- mixed case
- very short input

------------------------------------------------------------
MY APPROACH
------------------------------------------------------------

Write your approach here before coding:




------------------------------------------------------------
MY SOLUTION
------------------------------------------------------------
*/

/*
Write your solution for Question 06 here.

For practice, keep only the question you are currently solving active
when compiling this file.
*/

/*
------------------------------------------------------------
WHAT I LEARNED
------------------------------------------------------------




------------------------------------------------------------
MISTAKES / DEBUGGING NOTES
------------------------------------------------------------




============================================================
END QUESTION 06
============================================================
*/


/*
============================================================
QUESTION 07 — Command Parser and Validator

DIFFICULTY:
Hard

CONCEPTS TESTED:
- isalpha()
- isdigit()
- isalnum()
- isspace()
- ispunct()
- toupper()
- tolower()

------------------------------------------------------------
PROBLEM
------------------------------------------------------------

Design a small command-line parser for commands written in this form:

COMMAND argument1 argument2 ...

A command must contain alphabetic characters only and is case-insensitive.
Arguments are separated by one or more whitespace characters.

An argument may contain letters and digits only. Punctuation is invalid inside
an argument. Empty arguments caused by repeated whitespace must not be treated
as actual arguments.

Read one complete command line and report:
- whether the command is valid
- the normalized command name in lowercase
- the number of valid arguments
- the first invalid character and its position if invalid

Do not execute the command; this task is only about parsing and validation.

------------------------------------------------------------
INPUT
------------------------------------------------------------

A complete command line.

------------------------------------------------------------
OUTPUT
------------------------------------------------------------

Print the validation result and the requested parsed information.

------------------------------------------------------------
REQUIREMENTS
------------------------------------------------------------

- Handle leading/trailing whitespace.
- Treat runs of whitespace as separators.
- The command and arguments have different validation rules.
- Positions should be defined consistently, such as zero-based or one-based.

------------------------------------------------------------
CONSTRAINTS
------------------------------------------------------------

The input line can contain arbitrary whitespace and punctuation.

------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

Input:
[Write an example input here.]

Output:
[Write the expected output here.]

------------------------------------------------------------
EDGE CASES TO CONSIDER
------------------------------------------------------------

- empty line
- only whitespace
- missing command
- punctuation in command
- punctuation in argument
- digits in command
- multiple separators

------------------------------------------------------------
BEFORE CODING — THINK ABOUT
------------------------------------------------------------

- What information actually needs to be stored while scanning the input?
- Which checks can be performed independently, and which depend on previous characters?
- What should happen when the input contains characters from several categories?
- Which parts of the problem need to continue processing even after an error is found?
- How will you define and handle positions consistently?

------------------------------------------------------------
MY APPROACH
------------------------------------------------------------

Write your approach here before coding:




------------------------------------------------------------
MY SOLUTION
------------------------------------------------------------
*/

/*
Write your solution for Question 07 here.

For practice, keep only the question you are currently solving active
when compiling this file.
*/

/*
------------------------------------------------------------
WHAT I LEARNED
------------------------------------------------------------




------------------------------------------------------------
MISTAKES / DEBUGGING NOTES
------------------------------------------------------------




============================================================
END QUESTION 07
============================================================
*/


/*
============================================================
QUESTION 08 — Character-Property Scanner

DIFFICULTY:
Hard

CONCEPTS TESTED:
- isalpha()
- isdigit()
- isalnum()
- islower()
- isupper()
- isspace()
- ispunct()
- toupper()
- tolower()

------------------------------------------------------------
PROBLEM
------------------------------------------------------------

Build a reusable character-property scanner for a complete text.

For every character, determine its applicable properties and maintain totals for
all supported classification functions. Also maintain counts of uppercase and
lowercase letters.

At the end, print:
- a table-like summary of all category counts
- the character with the highest frequency among alphabetic characters,
  ignoring case
- the uppercase and lowercase forms of that most frequent alphabetic character

If there is a tie, choose the alphabetically earliest character after
case-insensitive comparison.

Do not assume the input contains only letters.

------------------------------------------------------------
INPUT
------------------------------------------------------------

A complete line of text.

------------------------------------------------------------
OUTPUT
------------------------------------------------------------

Print the category totals and the requested most-frequent alphabetic character information.

------------------------------------------------------------
REQUIREMENTS
------------------------------------------------------------

- Do not count punctuation or digits as alphabetic characters.
- Case-insensitive frequency must treat uppercase and lowercase forms as the same letter.
- Handle the absence of alphabetic characters.
- Keep category counting independent because one character can satisfy multiple categories.

------------------------------------------------------------
CONSTRAINTS
------------------------------------------------------------

The input size may be substantially larger than the examples.

------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

Input:
[Write an example input here.]

Output:
[Write the expected output here.]

------------------------------------------------------------
EDGE CASES TO CONSIDER
------------------------------------------------------------

- empty input
- no alphabetic characters
- all letters tied
- mixed case frequency
- large input
- whitespace and punctuation

------------------------------------------------------------
BEFORE CODING — THINK ABOUT
------------------------------------------------------------

- What information actually needs to be stored while scanning the input?
- Which checks can be performed independently, and which depend on previous characters?
- What should happen when the input contains characters from several categories?
- Which parts of the problem need to continue processing even after an error is found?
- How will you define and handle positions consistently?

------------------------------------------------------------
MY APPROACH
------------------------------------------------------------

Write your approach here before coding:




------------------------------------------------------------
MY SOLUTION
------------------------------------------------------------
*/

/*
Write your solution for Question 08 here.

For practice, keep only the question you are currently solving active
when compiling this file.
*/

/*
------------------------------------------------------------
WHAT I LEARNED
------------------------------------------------------------




------------------------------------------------------------
MISTAKES / DEBUGGING NOTES
------------------------------------------------------------




============================================================
END QUESTION 08
============================================================
*/


/*
============================================================
QUESTION 09 — Custom Character Library

DIFFICULTY:
Hard

CONCEPTS TESTED:
- isalpha()
- isdigit()
- isalnum()
- islower()
- isupper()
- toupper()
- tolower()
- custom classification

------------------------------------------------------------
PROBLEM
------------------------------------------------------------

Implement your own small character-classification library and use it to
analyze a line of text.

Create custom versions of the basic classifications covered in the notes:
alphabet, digit, alphanumeric, lowercase, and uppercase. Also create custom
case-conversion functions for uppercase and lowercase conversion.

Then use your custom functions to produce the same kind of statistics as a
character analyzer.

For comparison, run the same input through the standard character functions
and report whether your custom results agree with the standard results for
every character processed.

------------------------------------------------------------
INPUT
------------------------------------------------------------

A complete line of text.

------------------------------------------------------------
OUTPUT
------------------------------------------------------------

Print the custom-library statistics and whether the custom and standard classifications agree.

------------------------------------------------------------
REQUIREMENTS
------------------------------------------------------------

- The custom functions should be your own implementation.
- Do not use the standard classification functions inside the custom classification functions.
- Keep the comparison systematic rather than checking only a few examples.
- Do not rely on hard-coded ASCII numbers when using the standard library side.

------------------------------------------------------------
CONSTRAINTS
------------------------------------------------------------

Keep the scope to the character properties studied in this topic.

------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

Input:
[Write an example input here.]

Output:
[Write the expected output here.]

------------------------------------------------------------
EDGE CASES TO CONSIDER
------------------------------------------------------------

- empty input
- boundary letters
- digits
- punctuation
- mixed case
- whitespace

------------------------------------------------------------
BEFORE CODING — THINK ABOUT
------------------------------------------------------------

- What information actually needs to be stored while scanning the input?
- Which checks can be performed independently, and which depend on previous characters?
- What should happen when the input contains characters from several categories?
- Which parts of the problem need to continue processing even after an error is found?
- How will you define and handle positions consistently?

------------------------------------------------------------
MY APPROACH
------------------------------------------------------------

Write your approach here before coding:




------------------------------------------------------------
MY SOLUTION
------------------------------------------------------------
*/

/*
Write your solution for Question 09 here.

For practice, keep only the question you are currently solving active
when compiling this file.
*/

/*
------------------------------------------------------------
WHAT I LEARNED
------------------------------------------------------------




------------------------------------------------------------
MISTAKES / DEBUGGING NOTES
------------------------------------------------------------




============================================================
END QUESTION 09
============================================================
*/


/*
============================================================
QUESTION 10 — Text Data Quality Analyzer

DIFFICULTY:
Hard

CONCEPTS TESTED:
- all character functions in the topic
- custom vs standard classification
- toupper()
- tolower()
- whitespace handling
- character properties

------------------------------------------------------------
PROBLEM
------------------------------------------------------------

Build a text data-quality analyzer for a complete input line.

The analyzer must produce a quality report containing:
- total characters
- alphabetic, digit, alphanumeric, whitespace, and punctuation counts
- uppercase and lowercase counts
- number of characters that are neither alphanumeric nor whitespace
- percentage of alphanumeric characters
- whether the line contains mixed letter case
- whether the line contains leading or trailing whitespace
- a lowercase normalized copy with repeated whitespace collapsed and
  punctuation removed

In addition, identify the first position where the input violates this data
policy:

1. No punctuation is allowed.
2. No leading or trailing whitespace is allowed.
3. Internal whitespace is allowed but repeated whitespace is considered a
   formatting violation.
4. Letters and digits are allowed.
5. The report must distinguish a character-category violation from a
   formatting violation.

The program should continue scanning after finding the first violation so that
the final report still contains complete statistics.

------------------------------------------------------------
INPUT
------------------------------------------------------------

A complete line of text.

------------------------------------------------------------
OUTPUT
------------------------------------------------------------

Print the complete quality report, the normalized text, and the first policy violation if one exists.

------------------------------------------------------------
REQUIREMENTS
------------------------------------------------------------

- Separate classification from policy validation.
- Continue processing after the first violation.
- Define positions consistently.
- Avoid invalid percentage calculations for empty input.
- Use the topic's character functions rather than manually comparing ASCII values.

------------------------------------------------------------
CONSTRAINTS
------------------------------------------------------------

No maximum input length is imposed by the problem statement.

------------------------------------------------------------
EXAMPLE
------------------------------------------------------------

Input:
[Write an example input here.]

Output:
[Write the expected output here.]

------------------------------------------------------------
EDGE CASES TO CONSIDER
------------------------------------------------------------

- empty input
- leading/trailing whitespace
- repeated whitespace
- punctuation
- only digits
- mixed case
- very long input
- multiple simultaneous violations

------------------------------------------------------------
BEFORE CODING — THINK ABOUT
------------------------------------------------------------

- What information actually needs to be stored while scanning the input?
- Which checks can be performed independently, and which depend on previous characters?
- What should happen when the input contains characters from several categories?
- Which parts of the problem need to continue processing even after an error is found?
- How will you define and handle positions consistently?

------------------------------------------------------------
MY APPROACH
------------------------------------------------------------

Write your approach here before coding:




------------------------------------------------------------
MY SOLUTION
------------------------------------------------------------
*/

/*
Write your solution for Question 10 here.

For practice, keep only the question you are currently solving active
when compiling this file.
*/

/*
------------------------------------------------------------
WHAT I LEARNED
------------------------------------------------------------




------------------------------------------------------------
MISTAKES / DEBUGGING NOTES
------------------------------------------------------------




============================================================
END QUESTION 10
============================================================
*/

/*
============================================================
TOPIC COVERAGE
============================================================

[ ] isalpha()
[ ] isdigit()
[ ] isalnum()
[ ] islower()
[ ] isupper()
[ ] isspace()
[ ] ispunct()
[ ] toupper()
[ ] tolower()
[ ] Character encoding / numeric character representation
[ ] Character classification through properties
[ ] Whitespace-aware character input
[ ] Combining multiple character properties
[ ] Custom character classification
[ ] Custom case conversion
[ ] Lookup-table concept
[ ] Case normalization
[ ] Input validation
[ ] Character statistics
[ ] Edge-case handling

============================================================
END TOPIC PRACTICE
============================================================
*/
