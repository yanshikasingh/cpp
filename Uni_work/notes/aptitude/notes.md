# Aptitude Notes: Average — Part 1 & Part 2

I've received both scripts for Average (Part 1 and Part 2). I'll combine them into one set of easy, exam-oriented notes, covering the concepts, shortcuts, formulas, and important question types explained in your videos.

The main focus will be on solving one-line aptitude questions quickly, understanding the deviation method, and handling combined-average problems.

## 1. Basic concept of Average

Definition: Average is the equal share of the total sum among all observations.

\\[ \boxed{\text{Average}=\frac{\text{Sum of observations}}{\text{Number of observations}}} \\]

From this formula, we can derive:

\\[ \boxed{\text{Sum}=\text{Average}\times\text{Number}} \\]

\\[ \boxed{\text{Number}=\frac{\text{Sum}}{\text{Average}}} \\]

Example: The average marks of 5 students is 20.

Total marks \\(=5\times20=100\\).

## 2. Average of natural, even and odd numbers

These are direct-formula questions frequently asked in aptitude exams.

### A. First \\(n\\) natural numbers

Natural numbers: \\(1,2,3,4,\ldots,n\\)

\\[ \boxed{\text{Average}=\frac{n+1}{2}} \\]

Example: Average of the first 100 natural numbers:

\\[ \frac{100+1}{2}=\boxed{50.5} \\]

### B. First \\(n\\) even natural numbers

Even numbers: \\(2,4,6,8,\ldots,2n\\)

\\[ \boxed{\text{Average}=n+1} \\]

Example: Average of the first 100 even numbers:

\\[ 100+1=\boxed{101} \\]

### C. First \\(n\\) odd natural numbers

Odd numbers: \\(1,3,5,7,\ldots,(2n-1)\\)

\\[ \boxed{\text{Average}=n} \\]

Example: Average of the first 100 odd numbers:

\\[ \boxed{100} \\]

Important distinction: The first 100 even numbers are \\(2\\) to \\(200\\), but all even numbers up to 100 are \\(2,4,\ldots,100\\).

\\[ \text{Average of even numbers up to 100} =\frac{2+100}{2}=\boxed{51} \\]

Similarly, the first 100 whole numbers are \\(0\\) to \\(99\\).

\\[ \text{Average}=\frac{0+99}{2}=\boxed{49.5} \\]

## 3. Average of an arithmetic progression (AP)

An arithmetic progression is a sequence in which the difference between consecutive terms is constant.

Examples:

- \\(2,4,6,8,10\\) — common difference \\(2\\).
- \\(10,15,20,25,30\\) — common difference \\(5\\).
- \\(3,7,11,15\\) — common difference \\(4\\).

### Method 1: Find the middle value

For an equally spaced sequence, the average is the middle value when the number of terms is odd.

Example:

\\[ 10,20,30,40,50 \\]

The middle value is \\(30\\).

\\[ \boxed{\text{Average}=30} \\]

If there are an even number of terms, take the average of the two middle values.

Example:

\\[ 10,20,30,40,50,60 \\]

\\[ \text{Average}=\frac{30+40}{2}=\boxed{35} \\]

### Method 2: First term and last term

This works for an AP with equally spaced terms, even when the sequence is very long.

\\[ \boxed{\text{Average}=\frac{\text{First term}+\text{Last term}}{2}} \\]

Example: Find the average of the sequence from 50 to 150, increasing by equal intervals.

\\[ \text{Average}=\frac{50+150}{2}=\boxed{100} \\]

### More examples from the script

| Question                                    | Shortcut       | Answer |
| ------------------------------------------- | -------------- | ------ |
| First 10 even numbers                       | \\(10+1\\)     | 11     |
| First 10 odd numbers                        | \\(n\\)        | 10     |
| Sequence from 1 to 21, with equal intervals | \\((1+21)/2\\) | 11     |
| First 17 multiples of 5                     | \\((5+85)/2\\) | 45     |

## 4. Consecutive numbers: finding the largest or smallest

For consecutive numbers, the average is the middle number if the count is odd.

### Example 1: Find the largest number

The average of five consecutive natural numbers is 21.

The middle number is 21. Therefore, the sequence is:

\\[ 19,20,21,22,23 \\]

Largest number:

\\[ \boxed{23} \\]

### Example 2: Find the smallest odd number

The average of five consecutive odd numbers is 25.

The sequence is:

\\[ 21,23,25,27,29 \\]

Smallest number:

\\[ \boxed{21} \\]

Shortcut: For five consecutive natural numbers with average \\(A\\), the numbers are \\(A-2,A-1,A,A+1,A+2\\). For five consecutive odd numbers, they are \\(A-4,A-2,A,A+2,A+4\\).

## 5. Combined average

Definition: Combined average is the average of two or more groups taken together.

Suppose Group A has \\(n_1\\) people with average \\(A_1\\), and Group B has \\(n_2\\) people with average \\(A_2\\).

\\[ \boxed{ \text{Combined average} =\frac{n_1A_1+n_2A_2}{n_1+n_2} } \\]

For more groups:

\\[ \boxed{\frac{n_1A_1+n_2A_2+n_3A_3}{n_1+n_2+n_3}} \\]

### Example 1: Two classes combined

Class A has 36 students with an average weight of 30 kg. Class B has 24 students with an average weight of 40 kg. Find their combined average.

Step 1: Find the ratio of students.

\\[ 36:24=3:2 \\]

Step 2: Use the ratio as the group sizes.

\\[ \text{Combined average} =\frac{3(30)+2(40)}{3+2} \\]

\\[ =\frac{90+80}{5}=\boxed{34\text{ kg}} \\]

Shortcut: Reduce the group sizes to their simplest ratio before multiplying. This saves calculation time.

### Example 2: Another combined average

Class A has 63 students with an average weight of 32 kg. Class B has 21 students with an average weight of 44 kg.

\\[ 63:21=3:1 \\]

\\[ \text{Combined average} =\frac{3(32)+1(44)}{3+1} \\]

\\[ =\frac{96+44}{4}=\boxed{35\text{ kg}} \\]

### Finding the number who passed

A total of 120 candidates have an average score of 35. The average of those who passed is 39, and the average of those who failed is 15. Find the number who passed.

Let the number who passed be \\(x\\). Then the number who failed is \\(120-x\\).

\\[ 39x+15(120-x)=120(35) \\]

\\[ 39x+1800-15x=4200 \\]

\\[ 24x=2400 \\]

\\[ \boxed{x=100} \\]

Therefore, 100 candidates passed.

## 6. Deviation or equal-distribution approach

This is the main shortcut taught in Part 2.

Concept: When the average changes, the total sum changes by:

\\[ \boxed{\text{Change in sum}=\text{Number of observations}\times\text{Change in average}} \\]

This helps solve questions involving a new person joining, a person leaving, replacement, or incorrect data.

### Case A: A new person joins the group

Example: The average weight of 10 students is 30 kg. When a teacher joins them, the average becomes 33 kg. Find the teacher's weight.

Step 1: Number of people after the teacher joins:

\\[ 10+1=11 \\]

Step 2: Average increases by:

\\[ 33-30=3\text{ kg} \\]

Step 3: Total increase in weight:

\\[ 11\times3=33\text{ kg} \\]

Step 4: Teacher's weight:

\\[ 30+33=\boxed{63\text{ kg}} \\]

The teacher weighs 63 kg because the extra 33 kg is distributed across all 11 people as an increase of 3 kg each.

### Case B: Average increases after a new person joins

The average weight of 24 students is 30 kg. When a teacher joins, the average increases by 1 kg.

Number of people after joining:

\\[ 24+1=25 \\]

Teacher's weight:

\\[ 30+(25\times1)=\boxed{55\text{ kg}} \\]

### Case C: Replacement of one person

The average weight of 8 people increases by 2.5 kg when a person weighing 65 kg is replaced by a new person. Find the new person's weight.

Since the group size remains 8, use 8.

\\[ \text{Increase in total weight}=8\times2.5=20 \\]

\\[ \text{New person's weight}=65+20 \\]

\\[ \boxed{85\text{ kg}} \\]

Remember: If one person replaces another, the number of observations does not change.

### Case D: One person leaves and another joins

A committee of 12 members has an average age of 48 years. A member aged 62 leaves and a member aged 26 joins. Find the new average age.

The total age decreases by:

\\[ 62-26=36 \\]

The group still has 12 members, so the average decreases by:

\\[ \frac{36}{12}=3 \\]

New average:

\\[ 48-3=\boxed{45\text{ years}} \\]

## 7. Replacement of multiple people

When two or more people are replaced, calculate the total change first.

Example: The average age of 10 committee members increases by 3 years when two men aged 25 and 35 are replaced by two new men. Find the average age of the two new men.

Step 1: Total age of the two original men:

\\[ 25+35=60 \\]

Step 2: Increase in the group's total age:

\\[ 10\times3=30 \\]

Step 3: Combined age of the two new men:

\\[ 60+30=90 \\]

Step 4: Their average age:

\\[ \frac{90}{2}=\boxed{45\text{ years}} \\]

You cannot determine each man's individual age from the information given, but their average is 45 years.

## 8. Incorrect entries and correction of average

When a value is entered incorrectly, find the difference between the correct and incorrect values.

\\[ \boxed{\text{Correct average} =\text{Incorrect average} +\frac{\text{Correct value}-\text{Incorrect value}}{n}} \\]

Here, \\(n\\) is the total number of observations.

### Example 1: Marks entered too low

A teacher calculates the average marks of 30 students as 58. One student's marks were entered as 68 instead of 86. Find the correct average.

Difference:

\\[ 86-68=18 \\]

Correction to average:

\\[ \frac{18}{30}=0.6 \\]

Correct average:

\\[ 58+0.6=\boxed{58.6} \\]

### Example 2: Find the number of students

A student's marks were entered as 83 instead of 63. As a result, the class average increased by 2. Find the number of students.

Error in total marks:

\\[ 83-63=20 \\]

Change in average:

\\[ 2=\frac{20}{n} \\]

\\[ n=\frac{20}{2}=\boxed{10} \\]

### Example 3: Multiple incorrect entries

The average marks of some students is 40. Ten students received 60 instead of 90 marks in the calculation. After correcting the entries, the average becomes 50. Find the number of students.

Total correction:

\\[ 10(90-60)=300 \\]

Increase in average:

\\[ 50-40=10 \\]

Number of students:

\\[ n=\frac{300}{10}=\boxed{30} \\]

## 9. Excluding a number from a group

Example: The average of five numbers is 27. When one number is excluded, the average of the remaining four numbers becomes 25. Find the excluded number.

Original sum:

\\[ 5\times27=135 \\]

Sum after exclusion:

\\[ 4\times25=100 \\]

Excluded number:

\\[ 135-100=\boxed{35} \\]

Method: Calculate the original sum and the new sum separately, then subtract.

## 10. Overlapping groups and repeated values

When two groups overlap, do not count the shared observations twice.

Example: The average of seven values is 20. The average of the first four values is 15, and the average of the last four values is 25. Find the fourth value.

Total sum of seven values:

\\[ 7\times20=140 \\]

Sum of the first four:

\\[ 4\times15=60 \\]

Sum of the last four:

\\[ 4\times25=100 \\]

The fourth value is counted in both groups. Therefore:

\\[ 60+100=140+\text{Fourth value} \\]

\\[ \text{Fourth value}=160-140 \\]

\\[ \boxed{20} \\]

## 11. Average in cricket

### A. Batting average

The batting average is the total runs scored divided by the number of dismissals. In the aptitude problem, the focus is on the average across innings.

Example: A batsman scores 85 runs in his 17th innings, increasing his average by 3 runs. Find his previous average and his new average.

Step 1: The average increases by 3 across 17 innings.

\\[ 17\times3=51 \\]

Step 2: The 85-run innings is 51 runs above the previous average.

\\[ \text{Previous average}=85-51=34 \\]

Step 3: New average:

\\[ 34+3=\boxed{37} \\]

Answers:

- Previous average = 34 runs.
- New average = 37 runs.

### B. Bowling average

The bowling average is:

\\[ \boxed{\text{Bowling average}=\frac{\text{Total runs conceded}}{\text{Total wickets taken}}} \\]

It is not calculated by dividing runs by matches.

The script gives this example: a bowler's previous bowling average is 12.4. In the next match, the bowler takes 5 wickets for 26 runs, giving a match bowling average of:

\\[ \frac{26}{5}=5.2 \\]

The overall average becomes 12. Find the total wickets taken.

Using the alligation ratio:

\\[ (12-5.2):(12.4-12) \\]

\\[ =6.8:0.4=17:1 \\]

The ratio of the old wicket count to the new match's 5 wickets is \\(17:1\\).

Thus, previous wickets:

\\[ 17\times5=85 \\]

Total wickets:

\\[ 85+5=\boxed{90} \\]

## 12. Average temperature questions

These questions involve overlapping groups of days. Subtracting their totals cancels the common days.

Example: The average temperature for Monday, Tuesday and Wednesday is \\(34^\circ C\\). The average temperature for Tuesday, Wednesday and Thursday is \\(32^\circ C\\). If Thursday's temperature is \\(28^\circ C\\), find Monday's temperature.

Step 1: Difference between the averages:

\\[ 34-32=2^\circ C \\]

Step 2: Both groups contain three days, so the difference between their sums is:

\\[ 2\times3=6^\circ C \\]

Tuesday and Wednesday cancel out. Therefore:

\\[ \text{Monday}-\text{Thursday}=6 \\]

\\[ \text{Monday}=28+6 \\]

\\[ \boxed{34^\circ C} \\]

### General shortcut

If two groups have the same number of observations and overlap, subtract their total sums. Common observations cancel, leaving only the non-overlapping observations.

For example, when two groups each contain 3 days:

\\[ \text{Difference in sums} =(\text{Difference in averages})\times3 \\]

## 13. Formula revision sheet

| Question type                 | Formula / method                                                                    |
| ----------------------------- | ----------------------------------------------------------------------------------- |
| Basic average                 | Sum ÷ number                                                                        |
| Total sum                     | Average × number                                                                    |
| First \\(n\\) natural numbers | \\((n+1)/2\\)                                                                       |
| First \\(n\\) even numbers    | \\(n+1\\)                                                                           |
| First \\(n\\) odd numbers     | \\(n\\)                                                                             |
| AP average                    | (First + Last) ÷ 2                                                                  |
| Combined average              | Total of group sums ÷ total number                                                  |
| Change in sum                 | Number × change in average                                                          |
| New person joins              | Old average + total increase ÷ new group size, with the correct baseline adjustment |
| Replacement                   | Change in average × unchanged group size                                            |
| Incorrect entry               | Correct the total, then divide by number                                            |
| Excluded number               | Original sum − remaining sum                                                        |
| Bowling average               | Total runs conceded ÷ total wickets                                                 |
| Overlapping groups            | Subtract group totals to cancel common observations                                 |

## 14. Common mistakes to avoid

1. First 100 even numbers are not even numbers up to 100. The first 100 end at 200; even numbers up to 100 end at 100.
2. For a replacement question, the number of people stays the same.
3. When a new person joins, use the new group size to calculate the change in total.
4. For incorrect marks, check whether the entered value is higher or lower than the correct value before adjusting the average.
5. In overlapping groups, identify common values before adding sums.
6. Reduce group ratios before solving combined-average questions.
7. For cricket bowling average, divide total runs conceded by total wickets taken.

## 15. Practice questions

Try these without looking at the notes.

1\. Find the average of the first 20 even natural numbers.

20

21

22

40

2\. The average of five consecutive natural numbers is 18. Find the largest number.

19

20

21

22

3\. The average weight of 15 students is 40 kg. A teacher joins and the average becomes 42 kg. Find the teacher's weight.

62 kg

70 kg

72 kg

75 kg

4\. The average of 8 numbers is 25. One number is excluded and the average of the remaining 7 becomes 24. Find the excluded number.

25

30

32

35

5\. Class A has 20 students with average 30, and Class B has 10 students with average 45. Find the combined average.

32

35

37.5

40

Check answersReset

These notes cover the major concepts and worked examples visible in both scripts. The second script also contains further practice questions beyond the sections summarized here.



CLOCK PROBLEMS — COMPLETE APTITUDE NOTES

Based on the 4 StudyRoof lecture transcripts | Concepts + lecture examples solved step by step


## How to use these notes

The notes follow the lecture order: mirror image, water image, angle moved by each hand, angle between hands, finding the exact time, frequency of angles, and faulty clocks. Some transcript numbers are garbled by automatic speech recognition; calculations below use the intended clock formulas and clearly show the arithmetic.


## 1. Important basics of a clock

- A full circle = 360°.

- The minute hand completes 360° in 60 minutes, so it moves 6° per minute.

- The hour hand completes 360° in 12 hours = 30° per hour = 0.5° per minute.

- The second hand completes 360° in 60 seconds = 6° per second.

- For angle-between-hands questions, use h as the hour number and m as the minutes. At 12 o’clock, use h = 0 for calculation.


## 2. Mirror image of a clock

For an analogue clock, the lecture shortcut is:

Mirror time = 11:60 − given time

For an exact hour, use 12 − hour. For a time with minutes, subtract from 11:60 (equivalent to 12:00) and normalize the result around the clock.


### Examples from Part 1

1. Example 1: Find the mirror image of 2:00.

12 − 2 = 10. Answer: 10:00.

1. Example 2: Find the mirror image of 4:00.

12 − 4 = 8. Answer: 8:00.

1. Example 3: Find the mirror image of 8:20.

11:60 − 8:20 = 3:40. Answer: 3:40.

1. Example 4: Find the mirror image of 3:10.

11:60 − 3:10 = 8:50. Answer: 8:50.

1. Example 5: Find the mirror image of 11:50.

11:60 − 11:50 = 0:10, which is read as 12:10 on the clock. Answer: 12:10.

1. Example 6: Find the mirror image of 2:15.

11:60 − 2:15 = 9:45. Answer: 9:45.

1. Example 7: Find the mirror image of 12:30.

The reflected time is 11:30. Answer: 11:30.

1. Example 8: Find the mirror image of 7:46 4/11.

Write 11:60 − 7:46 4/11. Borrow 1 minute: 60 − 4/11 = 59 7/11, and 11 − 7 = 4 hours; then 59 7/11 − 46 = 13 7/11 minutes. Answer: 4:13 7/11.


## 3. Water image of a clock

The lecture gives this exam shortcut for water-image questions:

Water-image time = 18:30 − given time

The lecture also cautions that “water image” is not a physically standard clock-reading concept in the same way as mirror image; use this shortcut only when the aptitude question explicitly asks for it.


### Examples from Part 1

1. Example 1: Water image of 12:00.

18:30 − 12:00 = 6:30. Answer: 6:30.

1. Example 2: Water image of 8:20.

18:30 − 8:20 = 10:10. Answer: 10:10.


## 4. Angle moved by each hand

Convert all elapsed time to minutes when possible.

- Minute hand: 6° per minute.

- Hour hand: 0.5° per minute.

- Second hand: 360° per minute (or 6° per second).


### Examples from Part 1

Example 1: From 2 PM to 4 PM, how much angle does the hour hand cover?

Elapsed time = 2 hours = 120 minutes. Hour-hand movement = 120 × 0.5° = 60°. Answer: 60°.

Example 2: From 2 PM to 4 PM, how much angle does the minute hand cover?

Elapsed time = 120 minutes. Minute-hand movement = 120 × 6° = 720°. Answer: 720° (two full turns).

Example 3: From 2 PM to 4 PM, how much angle does the second hand cover?

The second hand turns 360° each minute. In 120 minutes: 120 × 360° = 43,200°. Answer: 43,200°.


## 5. Angle between the hour and minute hands

θ = |30h − (11/2)m|

Here h is the hour value (use 0 at 12) and m is the minute value. This expression may give the larger angle; the smaller angle is min(θ, 360° − θ). The reflex angle is the angle greater than 180°: 360° − smaller angle.


### Examples from Part 2

1. Example 1: Angle at 7:30.

h = 7, m = 30. θ = |30×7 − 5.5×30| = |210 − 165| = 45°. Other angle = 360 − 45 = 315°.

1. Example 2: Angle at 5:10.

h = 5, m = 10. θ = |150 − 55| = 95°. Other angle = 360 − 95 = 265°.

1. Example 3: Angle at 5:40.

h = 5, m = 40. θ = |150 − 220| = 70°. Other angle = 360 − 70 = 290°.

1. Example 4: Angle at 12:20.

Use h = 0, m = 20. θ = |0 − 110| = 110°. Other angle = 250°.

1. Example 5: Angle at 4:00.

h = 4, m = 0. θ = |120 − 0| = 120°. Other angle = 240°.

1. Example 6: Reflex angle at 10:25.

h = 10, m = 25. θ = |300 − 137.5| = 162.5°. Reflex angle = 360 − 162.5 = 197.5°. Answer: 197.5°.


## 6. Find the exact time when the angle is given

m = (2/11)(30h ± θ)

Use the lower hour of the stated interval for h (for example, between 7 and 8, use h = 7). Calculate both + and − answers. Keep only the minute values that fit the requested interval (0 ≤ m < 60). If a result is negative or outside the interval, reject it.


### Examples from Part 2

1. Example 1: Between 7 and 8, when is the angle 45°?

h = 7, θ = 45°. m = (2/11)(210 ± 45). Plus: 510/11 = 46 4/11 minutes. Minus: 330/11 = 30 minutes. Answers: 7:46 4/11 and 7:30.

1. Example 2: Between 5 and 6, when is the angle 95°?

h = 5, θ = 95°. m = (2/11)(150 ± 95). Plus: 490/11 = 44 6/11 minutes. Minus: 110/11 = 10 minutes. Answers: 5:44 6/11 and 5:10.

1. Example 3: Between 4 and 5, when is the angle 180°?

h = 4, θ = 180°. m = (2/11)(120 ± 180). Plus gives 600/11 = 54 6/11 minutes. Minus gives a negative value, so reject it. Answer: 4:54 6/11.

1. Example 4: Between 5:30 and 6, when is the angle 70°?

The interval is between 5 and 6, so h = 5 (do not use 5.5). m = (2/11)(150 ± 70). Results: 40 minutes and 160/11 = 14 6/11 minutes. Only 5:40 is after 5:30. Answer: 5:40.


## 7. How many times does a particular angle occur?

For a full 12-hour cycle:

- 0° (hands coincide): 11 times.

- 180° (hands are opposite): 11 times.

- Any other fixed angle between 0° and 180°: generally 22 times in 12 hours (twice per hour across the cycle).

- Over 24 hours, double the 12-hour counts: coincidence 22 times; opposite 22 times; other fixed angles generally 44 times.

- “Straight angle” means both 0° and 180°; over 24 hours this totals 22 + 22 = 44 occurrences.

- “Perpendicular” means 90°; the hands are perpendicular 44 times in 24 hours.


### Interval examples from Part 3

1. Example 1: From 1 PM to 5 PM, how many times is the angle 0°, 180°, and 90°?

Duration = 4 hours. 0°: 4 times (the interval does not cross 12). 180°: 4 times (it does not cross 6). 90°: normally 2 per hour = 8, but the interval crosses 3 o’clock, where one occurrence is lost from the interval count; answer: 7 times.

1. Example 2: From 5 PM to 11 PM, how many times is the angle 0°, 180°, and 90°?

Duration = 6 hours. 0°: 6 times. 180°: 5 times because the interval crosses 6 o’clock. 90°: 12 expected, minus one occurrence at the 9 o’clock boundary crossing = 11 times.

1. Example 3: From 2 PM to 10 PM, how many times is the angle 0°, 180°, and 90°?

Duration = 8 hours. 0°: 8 times. 180°: 7 times because the interval crosses 6 o’clock. 90°: 16 expected, minus one at 3 and one at 9 = 14 times.

Note: For interval questions, count only occurrences strictly inside the requested interval and handle endpoints consistently. The lecture transcript’s audio-to-text has some garbled statements; the results above follow the clock-angle rules.


## 8. Faulty clock problems

A faulty clock may gain (run fast) or lose (run slow) time. Read the wording carefully and compare the faulty clock’s elapsed time with the correct elapsed time.


### Type A — Hands coincide at unusual intervals

On a correct clock, consecutive coincidences occur every 65 5/11 minutes.

Example 1: A clock’s hands coincide every 64 minutes. How much does it gain per day?

Normal interval = 65 5/11 minutes. Difference = 65 5/11 − 64 = 16/11 minutes gained per 64 faulty-clock minutes. In a day, gain = (16/11) × (1440/64) = 360/11 = 32 8/11 minutes. Answer: gains 32 8/11 minutes per day.

Example 2: The lecture also considers a 65-minute coincidence interval.

Difference from the normal interval = 65 5/11 − 65 = 5/11 minute. Using the lecture’s proportional method, daily difference magnitude = (5/11) × (1440/65) = 1440/143 ≈ 10.07 minutes per day. Determine gain/loss from the exact wording and whether the 65 minutes refers to correct elapsed time or the faulty clock’s displayed interval.


### Type B — Clock changes from behind to ahead

If a clock is behind by x minutes at one time and ahead by y minutes later, it must have shown the correct time in between.

1. Example 1: A clock is 5 minutes slow at Sunday 5 PM and 5 minutes fast at Tuesday 5 PM. When was it correct?

It moves from −5 minutes to +5 minutes, a total correction of 10 minutes over 48 hours. It needs to gain only 5 minutes to reach correct time: 48 × 5/10 = 24 hours after Sunday 5 PM. Answer: Monday 5 PM.

1. Example 2: A clock is 8 minutes slow at Sunday 8 PM and 7 minutes fast at Wednesday 8 PM. When was it correct?

Total gain = 8 + 7 = 15 minutes in 72 hours. To recover the initial 8-minute lag: time = 72 × 8/15 = 38.4 hours = 38 hours 24 minutes. From Sunday 8 PM, this is Tuesday 10:24 AM. Answer: Tuesday 10:24 AM.


### Type C — Clock gains a fixed amount over a fixed duration

Example 1: A clock gains 5 seconds in every 3 correct minutes. It is set correctly at 7 AM. What is the true time when it shows 4:15 PM?

Faulty clock runs 185 seconds while correct time runs 180 seconds, so faulty : correct = 37 : 36. From 7:00 AM to the faulty reading 4:15 PM = 9 hours 15 minutes = 555 minutes on the faulty clock. Correct elapsed time = 555 × 36/37 = 540 minutes = 9 hours. True time = 7:00 AM + 9 hours = 4:00 PM. Answer: 4:00 PM.

Example 2: A clock gains 10 minutes in 24 hours. It is set correctly at 8 AM. What is the true time when it shows 1 PM the following day?

In 24 correct hours, the faulty clock shows 24 hours 10 minutes = 1450 minutes, while correct time is 1440 minutes. Faulty : correct = 1450 : 1440 = 145 : 144. From 8 AM to 1 PM the next day is 29 faulty-clock hours. True elapsed time = 29 × 144/145 hours = 28 hours 48 minutes. Add 28 h 48 min to 8 AM: true time is 12:48 PM the following day. Answer: 12:48 PM.


## 9. Quick revision sheet


## 10. Common mistakes to avoid

- Do not use h = 5.5 for the interval 5 to 6; use the lower hour h = 5.

- The formula may give a signed difference. Take the absolute value for the angle.

- The clock has two angles between its hands: θ and 360° − θ. A reflex-angle question asks for the angle greater than 180°.

- When finding exact time, calculate both ± cases and reject any minute value outside the specified hour interval.

- For faulty-clock questions, convert hours to minutes or seconds so both quantities use the same unit.

- A gain means the clock runs ahead; a loss means it falls behind. Confirm direction from the wording before selecting the answer.

End of notes — practise each example once without looking at the solution.


## Quick Revision Table


| Question type | Formula / rule |

| --- | --- |

| Mirror image | 11:60 − given time (or 12 − hour for exact hours) |

| Water image (lecture shortcut) | 18:30 − given time |

| Minute-hand movement | 6° per minute |

| Hour-hand movement | 0.5° per minute |

| Second-hand movement | 360° per minute |

| Angle between hands | θ = \|30h − 11m/2\| |

| Smaller angle | min(θ, 360° − θ) |

| Reflex angle | 360° − smaller angle |

| Find time for angle θ | m = (2/11)(30h ± θ), then check interval |

| Coincidence in 24 hours | 22 times |

| Opposite in 24 hours | 22 times |

| Any other fixed angle in 24 hours | Usually 44 times |

| Correct coincidence interval | 65 5/11 minutes |

| Clock gain/loss proportion | Scale elapsed times using faulty-time : correct-time ratio |

# Calendar Concept (Part 4): Calendar Repetition
**Subject:** Logical Reasoning – Calendar  
**Source:** Study Roof YouTube lecture transcript  
**Purpose:** Exam-ready notes with the lecture's solved examples

---

## 1. What Is Calendar Repetition?

A calendar repeats when **the dates and weekdays match throughout the entire year**. For example, if 1 January is Monday in one year, the calendar repeats in another year only when every date from 1 January to 31 December falls on the same weekday.

The lecture's main method is to compare **odd days** between two years.

### Key rule
A calendar repeats when the **difference in odd days is 0 modulo 7**.

In other words, the total extra days between the two calendar years must be divisible by 7.

---

## 2. Quick Shortcut: The Code `6 – 11 – 11 – 28`

For ordinary year ranges that do **not cross a non-leap century year** (such as 1700, 1800, 1900, 2100), the lecture gives this shortcut:

| Year relative to a leap year | Repeat after | Example from lecture |
|---|---:|---|
| Leap year itself | 28 years | 2012 → 2040 |
| First year after a leap year | 6 years | 2013 → 2019 |
| Second year after a leap year | 11 years | 2014 → 2025 |
| Third year after a leap year | 11 years | 2015 → 2026 |

**Memory code:** `6, 11, 11, 28`

Why it works: the two years must have the same leap-year status and the total odd-day difference between them must be 0 modulo 7.

> **Important:** Treat this as a shortcut, not an unconditional rule. Century years not divisible by 400 are not leap years, so crossing one can break the pattern.

---

## 3. Solved Examples: The `6 – 11 – 11 – 28` Code

### Example 1: When will the calendar of 2012 repeat?

**Step 1:** Identify the year type.  
2012 is a leap year.

**Step 2:** Use the code.  
A leap-year calendar repeats after 28 years.

**Step 3:** Add 28.  
2012 + 28 = **2040**.

**Answer: 2040.**

### Example 2: When will the calendar of 2013 repeat?

2013 is the first year after the leap year 2012.

- First year after a leap year → repeat after 6 years.
- 2013 + 6 = **2019**.

**Answer: 2019.**

**Check using odd days:** From 2013 to 2019 there are 6 years: 5 ordinary years and 1 leap year.  
Odd days = (5 × 1) + (1 × 2) = 7 = 0 odd days after dividing by 7. Therefore, the calendars match.

### Example 3: When will the calendar of 2014 repeat?

2014 is the second year after the leap year 2012.

- Second year after a leap year → repeat after 11 years.
- 2014 + 11 = **2025**.

**Answer: 2025.**

**Check using odd days:** From 2014 to 2025, the lecture counts 11 years and 3 leap years (2016, 2020, 2024).  
Odd days = 11 ordinary-year days + 3 extra leap-year days = 14; 14 ÷ 7 leaves remainder 0.  
**Answer: 2025.**

### Example 4: When will the calendar of 2015 repeat?

2015 is the third year after the leap year 2012.

- Third year after a leap year → repeat after 11 years.
- 2015 + 11 = **2026**.

**Answer: 2026.**

### Example 5: When will the calendar of 2016 repeat?

2016 is a leap year.

- Leap year → repeat after 28 years.
- 2016 + 28 = **2044**.

**Answer: 2044.**

---

## 4. The Odd-Day Method (Conceptual Method)

An **odd day** is the remainder left after counting complete weeks. Since 7 days make a week, divide the total days by 7 and take the remainder.

- Ordinary year = 365 days = 52 weeks + **1 odd day**.
- Leap year = 366 days = 52 weeks + **2 odd days**.

For calendar repetition, the total odd-day difference must be 0 modulo 7.

### Formula

If a period contains:
- \(N\) ordinary years
- \(L\) leap years

Then:

\[
\text{Total odd days} = N + 2L
\]

The calendars can repeat if:

\[
(N + 2L) \bmod 7 = 0
\]

This is the lecture's basic verification method.

---

## 5. Solved Example: Why does 2013 repeat in 2019?

**Question:** Verify that the 2013 calendar repeats in 2019.

**Step 1: Find the year difference.**

\[
2019 - 2013 = 6
\]

**Step 2: Count leap and ordinary years in the interval.**

The six-year period contains one leap year (2016) and five ordinary years.

**Step 3: Calculate odd days.**

\[
(5 \times 1) + (1 \times 2) = 5 + 2 = 7
\]

**Step 4: Find the remainder after division by 7.**

\[
7 \bmod 7 = 0
\]

**Conclusion:** The odd-day difference is zero, so **2013 and 2019 have the same calendar**.

---

## 6. Solved Example: Why does 2014 repeat in 2025?

**Question:** Verify that 2014 repeats in 2025.

**Step 1: Year difference.**

\[
2025 - 2014 = 11
\]

**Step 2: Count leap years.**

The leap years in the interval are 2016, 2020 and 2024: **3 leap years**.

**Step 3: Count ordinary years.**

\[
11 - 3 = 8 \text{ ordinary years}
\]

**Step 4: Calculate odd days.**

\[
(8 \times 1) + (3 \times 2) = 8 + 6 = 14
\]

**Step 5: Divide by 7.**

\[
14 \bmod 7 = 0
\]

**Conclusion:** The calendars match, so **2025** is the repeat year for 2014.

---

## 7. Special Case: Crossing a Non-Leap Century Year

Century years end in `00`. A century year is a leap year only if it is divisible by 400.

- 1600: leap year
- 1700: not a leap year
- 1800: not a leap year
- 1900: not a leap year
- 2000: leap year
- 2100: not a leap year

When crossing a century year that is **not** divisible by 400, do not blindly use the `6 – 11 – 11 – 28` code. Verify the odd days directly, or use the lecture's special shortcut below.

### Special shortcut: `12 and 40`

The lecture gives this memory rule for century-crossing cases involving a century year that is not a leap year:

- **Ordinary year:** repeats after 12 years.
- **Leap year:** repeats after 40 years.

Use this as a shortcut for the relevant century-crossing cases, and verify the odd-day total if uncertain.

### Example 7.1: When does 1897 repeat?

1897 is an ordinary year. Since the interval crosses 1900 (which is not a leap year), use the special shortcut.

\[
1897 + 12 = 1909
\]

Check:
- Difference = 12 years.
- Leap years in the interval: 1904 and 1908 = 2.
- Ordinary years = 12 − 2 = 10.
- Odd days = \(10 + (2 \times 2) = 14\).
- Remainder = \(14 \bmod 7 = 0\).

**Answer: 1909.**

### Example 7.2: When does 1888 repeat?

The lecture's stated shortcut gives:

\[
1888 + 12 = 1900
\]

However, **1900 is not a leap year**, and the calendars do not match: 1888 is a leap year, while 1900 is an ordinary year. So do not apply the ordinary-year shortcut to this leap year. Use the lecture's separate leap-year rule:

\[
1888 + 40 = 1928
\]

**Answer according to the leap-year shortcut: 1928.** Always verify by comparing the weekday alignment and leap-year status.

### Example 7.3: When does the leap-year calendar of 1868 repeat?

1868 is a leap year. Under the special century-crossing shortcut:

\[
1868 + 40 = 1908
\]

**Answer: 1908.**

---

## 8. A Direct Method for Checking an Option

If the options are given, test each candidate year.

1. Calculate the difference between the two years.
2. Count leap years in the interval, paying attention to century exceptions.
3. Count ordinary years.
4. Calculate total odd days:

\[
\text{Odd days} = \text{ordinary years} + 2(\text{leap years})
\]

5. Divide by 7.
6. If the remainder is **0**, the odd-day difference is zero. Then check that the year types match (both ordinary or both leap) before concluding the full calendars repeat.

---

## 9. Important One-Liner: Last Day of a Century

The lecture states that **Tuesday, Thursday and Saturday cannot be the last day (31 December) of a century year**.

Memory code: **T–T–S**
- Tuesday
- Thursday
- Saturday

So the last day of a century year can be one of the other four weekdays, according to the lecture.

---

## 10. Quick Revision Table

| Topic | Rule |
|---|---|
| Ordinary year | 365 days; 1 odd day |
| Leap year | 366 days; 2 odd days |
| Calendar repetition | Odd-day difference = 0 modulo 7 |
| Shortcut for typical years | 6, 11, 11, 28 |
| Special century-crossing shortcut from lecture | 12 for ordinary years; 40 for leap years |
| Century year leap test | Divisible by 400 |
| Century year not divisible by 400 | Not a leap year |
| Last day of a century year | Not Tuesday, Thursday or Saturday (lecture rule) |

---

## 11. Practice Questions

Try these without looking at the answers first.

1. 2013 repeats in which year?
2. 2014 repeats in which year?
3. 2015 repeats in which year?
4. 2016 repeats in which year?
5. Is 1900 a leap year?
6. Is 2000 a leap year?
7. How many odd days are there in 6 years containing 5 ordinary years and 1 leap year?
8. How many odd days are there in 11 years containing 8 ordinary years and 3 leap years?
9. Which weekdays cannot be the last day of a century year according to the lecture?
10. What must the odd-day difference be for two calendars to repeat?

### Answers

1. 2019
2. 2025
3. 2026
4. 2044
5. No
6. Yes
7. 7 total odd days; remainder 0
8. 14 total odd days; remainder 0
9. Tuesday, Thursday and Saturday
10. 0 modulo 7

---

## 12. Exam Tips

- Memorize **`6 – 11 – 11 – 28`** for typical calendar repetition questions.
- Memorize **`12 and 40`** for the lecture's special century-crossing shortcut.
- If a non-leap century year is crossed, prefer counting odd days directly rather than trusting a shortcut blindly.
- Remember that a repeating calendar requires both the same weekday alignment and compatible leap-year status.
- In MCQs, checking each option with the odd-day method can be more reliable than relying only on memory.

Here are the aptitude formulas for divisibility questions like “divisible by neither 7 nor 9.”

## 1. Basic counting formula

Number of integers from \\(a\\) to \\(b\\) divisible by \\(n\\), inclusive:

\\[ \boxed{N(n)=\left\lfloor\frac{b}{n}\right\rfloor- \left\lfloor\frac{a-1}{n}\right\rfloor} \\]

Here, \\(\lfloor x\rfloor\\) means take the integer part.

## 2. Inclusion–Exclusion formulas

Let \\(N\\) be the total number of integers in the given range.

| Condition                                 | Formula                          |
| ----------------------------------------- | -------------------------------- |
| Divisible by neither \\(A\\) nor \\(B\\)  | \\(N-N(A)-N(B)+N(A\cap B)\\)     |
| Divisible by \\(A\\) or \\(B\\) (or both) | \\(N(A)+N(B)-N(A\cap B)\\)       |
| Divisible by both \\(A\\) and \\(B\\)     | \\(N(\operatorname{LCM}(A,B))\\) |
| Divisible by \\(A\\), but not \\(B\\)     | \\(N(A)-N(A\cap B)\\)            |
| Divisible by exactly one of \\(A,B\\)     | \\(N(A)+N(B)-2N(A\cap B)\\)      |

Here, \\(N(A\cap B)\\) means the count of numbers divisible by both \\(A\\) and \\(B\\).

## 3. Special case: Even integers

If the question asks for even integers divisible by neither \\(A\\) nor \\(B\\), first count all even integers, then use:

\\[ \boxed{ \begin{aligned} \text{Required count}={}&N(2)-N(\operatorname{LCM}(2,A))\\\ &-N(\operatorname{LCM}(2,B))\\\ &+N(\operatorname{LCM}(2,A,B)) \end{aligned} } \\]

For your example, even integers from 100 to 200 divisible by neither 7 nor 9:

\\[ \begin{aligned} &51-N(14)-N(18)+N(126)\\\ &=51-7-6+1\\\ &=\boxed{39} \end{aligned} \\]

## 4. For three divisors \\(A,B,C\\)

The number divisible by none of the three is:

\\[ \boxed{ \begin{aligned} N\_{\text{none}}={}&N-N(A)-N(B)-N(C)\\\ &+N(A\cap B)+N(A\cap C)\\\ &+N(B\cap C)-N(A\cap B\cap C) \end{aligned} } \\]

Aptitude trick: For numbers divisible by multiple divisors, use their LCM to count the intersection. Always subtract individual counts, add pairwise intersections, and subtract the triple intersection.

## Unit Digit – Complete Table for Aptitude

| Last digit of base | Unit digit cycle | Cycle length | If remainder = 0, choose |
| ------------------ | ---------------- | ------------ | ------------------------ |
| 0                  | 0                | 1            | 1st digit = 0            |
| 1                  | 1                | 1            | 1st digit = 1            |
| 2                  | 2, 4, 8, 6       | 4            | 4th digit = 6            |
| 3                  | 3, 9, 7, 1       | 4            | 4th digit = 1            |
| 4                  | 4, 6             | 2            | 2nd digit = 6            |
| 5                  | 5                | 1            | 1st digit = 5            |
| 6                  | 6                | 1            | 1st digit = 6            |
| 7                  | 7, 9, 3, 1       | 4            | 4th digit = 1            |
| 8                  | 8, 4, 2, 6       | 4            | 4th digit = 6            |
| 9                  | 9, 1             | 2            | 2nd digit = 1            |

## Remainder Rule

| Remainder after dividing exponent by cycle length | What to do                         |
| ------------------------------------------------- | ---------------------------------- |
| 1                                                 | Choose the 1st digit in the cycle  |
| 2                                                 | Choose the 2nd digit in the cycle  |
| 3                                                 | Choose the 3rd digit in the cycle  |
| 0                                                 | Choose the last digit in the cycle |

Formula:

\\[ R = \text{Exponent} \bmod \text{Cycle length} \\]

- If \\(R\neq0\\), position = \\(R\\).
- If \\(R=0\\), position = cycle length.

## Examples

| Question     | Cycle      | Division      | Remainder | Answer |
| ------------ | ---------- | ------------- | --------- | ------ |
| \\(2^7\\)    | 2, 4, 8, 6 | \\(7\div4\\)  | 3         | 8      |
| \\(3^8\\)    | 3, 9, 7, 1 | \\(8\div4\\)  | 0         | 1      |
| \\(4^5\\)    | 4, 6       | \\(5\div2\\)  | 1         | 4      |
| \\(7^{12}\\) | 7, 9, 3, 1 | \\(12\div4\\) | 0         | 1      |
| \\(8^{11}\\) | 8, 4, 2, 6 | \\(11\div4\\) | 3         | 2      |
| \\(9^6\\)    | 9, 1       | \\(6\div2\\)  | 0         | 1      |

Exam shortcut: Memorize the first table. For any large power, use only the base's last digit, find the cycle, divide the exponent by the cycle length, and select the required digit.