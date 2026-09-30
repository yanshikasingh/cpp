# DATA COMMUNICATION & NETWORKING — UNIT 2
# ERROR DETECTION, ERROR CORRECTION, DATA LINK CONTROL, HDLC, PPP & MULTIPLE ACCESS
## Complete Exam-Oriented Master Notes

**Course:** Data Communication & Network — 26CSEC301  
**Module:** 2 — Error Detection & Correction (Errors, Data Link Control & Protocols)  
**Source:** Uploaded 53-page university PDF, including visual diagrams/tables and worked examples.

---

# 0. UNIT SCOPE

The university PDF covers the following connected areas:

1. Data Link Layer and its functions
2. Frames
3. Types of transmission errors
4. Error detection
   - Parity check
   - Checksum
5. Error correction
   - Hamming code
6. Flow control and error control
7. Stop-and-Wait
8. ARQ
9. Sliding Window
10. Go-Back-N ARQ
11. Selective Repeat ARQ
12. HDLC
13. Point-to-Point Protocol (PPP)
14. PPP stack / phases
15. Multiple access
16. Random access
17. ALOHA
18. CSMA
19. CSMA/CD
20. CSMA/CA
21. Controlled access
   - Reservation
   - Polling
   - Token passing
22. Channelization
   - FDMA
   - TDMA
   - CDMA

The PDF's contents slide explicitly lists errors, detection/correction, flow and error control, Stop-and-Wait/ARQ, Go-Back-N, Selective Repeat, HDLC, PPP, multiple access, random/controlled access, and channelization.

---

# 1. DATA LINK LAYER

## 1.1 Standard Examination Definition

The **Data Link Layer** is **OSI Layer 2**, responsible for providing reliable **node-to-node delivery** over a physical link by organizing bits into frames and providing functions such as framing, physical addressing, error control, flow control, and medium access control.

## 1.2 In Simple Words

The Physical Layer moves raw bits. The Data Link Layer gives those bits **structure and control** so that communication over one link can be organized and checked.

The PDF's Layer-2 slide emphasizes:
- Node-to-node delivery over a physical link.
- Grouping raw bits into frames.
- Detection of transmission errors.
- Flow and access control over a shared link.

### Why Data Link Layer is Needed

A raw physical link only transports signals/bits. The Data Link Layer adds:
- **Framing**
- **Error detection/control**
- **Flow control**
- **Physical addressing**
- **Access control**

---

# 2. MAIN FUNCTIONS OF THE DATA LINK LAYER

The visual slide in the PDF groups the main functions into five areas.

## 2.1 Framing

**Definition:** Framing is the process of dividing a continuous stream of bits received from the Network Layer into manageable units called **frames**.

```text
Continuous bit stream
111010101100101010101...
          |
          v
+--------+--------+--------+
| Frame 1| Frame 2| Frame 3|
+--------+--------+--------+
```

### Why framing is needed
- Identifies the beginning/end of data units.
- Makes error detection possible per frame.
- Adds control/addressing information.

---

## 2.2 Error Control

Error control deals with damaged/lost frames.

The PDF describes it as:
- Detecting damaged frames.
- Supporting recovery.

Typical mechanisms include:
- Error detection codes.
- Acknowledgements.
- Retransmission.
- Sequence numbers.
- Timers.
- ARQ protocols.

---

## 2.3 Flow Control

**Definition:** Flow control is the mechanism that prevents a fast sender from transmitting data faster than the receiver can process/store it.

```text
Fast Sender  ---- many frames ---->  Slow Receiver
                    ^
                    |
             Flow control
             limits sending rate
```

The PDF summarizes this as making the sender match the receiver's capacity.

---

## 2.4 Access Control

When multiple devices share the same communication medium, access control decides **which device may use the medium and when**.

Examples:
- ALOHA
- CSMA
- Reservation
- Polling
- Token passing

---

## 2.5 Physical Addressing

The Data Link Layer uses **MAC addresses** for local delivery.

```text
Source MAC  --->  Frame  --->  Destination MAC
```

Physical addressing is concerned with delivery across the local/link-level network, not end-to-end routing across the Internet.

---

# 3. FRAME — SIMPLE VIEW

A **frame** is the Data Link Layer protocol data unit.

The PDF's frame diagram has:

```text
+----------------+----------------+----------------+
|     HEADER     |      DATA      |     TRAILER    |
+----------------+----------------+----------------+
| Address/control| Actual payload | FCS / error chk|
+----------------+----------------+----------------+
```

## Header
Carries:
- Addressing information.
- Control information.

## Data / Payload
Carries the message/data received from the upper layer.

## Trailer
Contains error-detection information such as **FCS (Frame Check Sequence)** in protocols that use it.

### Important exam point

**Complete unit at Layer 2 = Frame.**

---

# 4. TRANSMISSION ERRORS

## 4.1 Standard Examination Definition

A **transmission error** occurs when one or more bits in transmitted data are altered during transmission because of disturbances in the communication medium or system.

The PDF identifies common causes such as:
- Noise
- Attenuation
- Interference/cross-talk

---

# 5. TYPES OF TRANSMISSION ERRORS

The PDF explicitly divides transmission errors into:

1. Single-bit error
2. Burst error

---

# 6. SINGLE-BIT ERROR

## Definition

A **single-bit error** occurs when exactly one bit in a transmitted data unit changes from its original value.

If:

```text
Sent:     101100
Received: 101000
                   ^
              one bit changed
```

then a single-bit error has occurred.

## Visual Example From the PDF

The PDF shows a sender transmitting a bit pattern, a **noise** disturbance in the channel, and the receiver obtaining a pattern differing at one position.

### Characteristics
- Only one bit is altered.
- The changed bit may be 0 → 1 or 1 → 0.
- Detection methods are required to identify that the received data is not the original data.

---

# 7. BURST ERROR

## Definition

A **burst error** occurs when **two or more bits within a block of transmitted data are affected by an error**, with the affected positions spanning a range from the first corrupted bit to the last corrupted bit.

### Important detail

The burst length is measured from the **first corrupted bit to the last corrupted bit**, including positions between them even if some intervening bits happen to remain correct.

### Example

```text
Original:   101101011
Received:   101001111
              ^^^^^
           affected region
```

The PDF emphasizes that a short noise pulse can corrupt a sequence of transmitted bits.

### Difference

```text
Single-bit error → one changed bit

Burst error → multiple affected positions within a span
```

---

# 8. COMMON CAUSES OF TRANSMISSION ERRORS

The PDF specifically identifies:

### 1. Noise
Unwanted electrical/electromagnetic disturbance.

### 2. Attenuation
Loss/reduction of signal strength during transmission.

### 3. Interference / Crosstalk
Unwanted interaction from another signal/channel.

Other networking systems can also experience distortion and other physical impairments, but the above are the causes highlighted in the PDF.

---

# 9. ERROR DETECTION vs ERROR CORRECTION

## Error Detection

**Definition:** Error detection is the process of determining whether received data has been corrupted during transmission.

Question answered:

> **"Is something wrong?"**

Typical action:
- Detect the damaged frame.
- Discard it or request retransmission.

## Error Correction

**Definition:** Error correction is the process of determining the location/nature of an error and recovering the correct data, either at the receiver or through retransmission.

Question answered:

> **"What is wrong, and how can it be fixed?"**

Typical action:
- Correct the error directly, or
- Use retransmission/recovery mechanisms.

### Memory Hook

**Detection → "Something is wrong."**

**Correction → "Where is it, and how do I fix it?"**

---

# 10. PARITY CHECK

## 10.1 Standard Examination Definition

**Parity checking** is an error-detection technique in which one additional bit, called the **parity bit**, is appended to a data unit so that the total number of 1s follows a predefined parity rule.

The PDF presents:
- Even parity
- Odd parity

---

# 11. EVEN PARITY

## Definition

In **even parity**, the parity bit is selected so that the **total number of 1 bits**, including the parity bit, is even.

### Rule

If the data already contains an even number of 1s:

```text
Parity bit = 0
```

If the data contains an odd number of 1s:

```text
Parity bit = 1
```

because adding 1 changes the total count from odd to even.

---

# 12. ODD PARITY

## Definition

In **odd parity**, the parity bit is selected so that the **total number of 1 bits**, including the parity bit, is odd.

### Rule

If data contains an odd number of 1s:

```text
Parity bit = 0
```

If data contains an even number of 1s:

```text
Parity bit = 1
```

---

# 13. PARITY NUMERICAL — EVEN PARITY

The PDF's worked example uses:

```text
Data = 1011001
```

Count the 1s:

```text
1011001 → four 1s
```

Four is already even.

Therefore:

```text
Parity bit P = 0
```

Transmitted sequence:

```text
10110010
```

The PDF's final check verifies that the resulting sequence contains an even number of 1s.

## Exam Method

1. Write the data.
2. Count number of 1s.
3. Decide whether the count is already even.
4. Choose P.
5. Append P.
6. Verify total number of 1s.

---

# 14. PARITY NUMERICAL — ODD PARITY

Again take:

```text
Data = 1011001
```

Number of 1s:

```text
4
```

Four is even, but odd parity requires an odd total.

Therefore:

```text
P = 1
```

Transmitted sequence:

```text
10110011
```

Now total number of 1s = 5, which is odd.

---

# 15. PARITY CHECK — ERROR DETECTION

Suppose even parity is expected.

```text
Sent:     10110010
Received: 10100010
```

The receiver counts the number of 1s.

If the received count violates the expected parity, an error is detected.

### Limitation

A simple parity check **does not identify the exact erroneous bit**.

Also, if an even number of bits changes, the overall parity may remain unchanged, so some error patterns can escape detection.

### Important

**Parity is primarily an error-detection mechanism, not a complete correction mechanism.**

---

# 16. CHECKSUM

## 16.1 Standard Examination Definition

A **checksum** is an error-detection technique in which data is divided into fixed-size words, the words are added using one's-complement arithmetic, and the complement of the final sum is transmitted as the checksum.

The receiver repeats the calculation and checks the result.

---

# 17. CHECKSUM WORKING

The PDF's basic procedure is:

1. Divide data into fixed-size words.
2. Add the words using binary addition.
3. If there is a carry beyond the word size, **wrap the carry around** and add it back to the low-order part.
4. Take the **one's complement** of the final sum.
5. Transmit the checksum with the data.
6. Receiver adds the received words and checksum.
7. If the final result is all 1s, the check passes under the method shown.

### Memory Formula

```text
Add → Wrap carry → Complement → Send → Recalculate
```

---

# 18. CHECKSUM — 4-BIT NUMERICAL FROM THE PDF

The PDF uses 4-bit words:

```text
Word 1 = 1011
Word 2 = 0110
```

### Step 1 — Add

```text
  1011
+ 0110
------
1 0001
```

There is a carry beyond four bits.

### Step 2 — Wrap the carry

Low-order 4 bits:

```text
0001
```

Add carry 1:

```text
  0001
+ 0001
------
  0010
```

### Step 3 — Complement

One's complement of:

```text
0010
```

is:

```text
1101
```

Therefore:

```text
Checksum = 1101
```

### Step 4 — Receiver Verification

Receiver adds:

```text
Data sum = 0010
Checksum = 1101
----------------
           1111
```

All four bits are 1.

Therefore the check passes.

### Exam Procedure

```text
1. Add all words.
2. Wrap carry around.
3. Complement the result.
4. Obtain checksum.
5. Receiver adds data + checksum.
6. All 1s → accepted/check passes.
```

---

# 19. CHECKSUM vs PARITY

| Parameter | Parity | Checksum |
|---|---|---|
| Basic idea | Adds one parity bit | Adds checksum derived from words |
| Operation | Count 1s | One's-complement addition |
| Complexity | Very low | Higher |
| Error detection | Limited | Stronger than simple parity for many patterns |
| Can locate exact bit? | No | No |
| Typical concept | Bit-level/simple check | Word/block-level check |

---

# 20. HAMMING CODE

## 20.1 Standard Examination Definition

**Hamming code** is an error-control coding technique that inserts multiple parity bits at selected positions in a data word so that the receiver can calculate a **syndrome** and identify the position of a single-bit error.

The PDF's central memory idea is:

> **Extra parity bits + syndrome = locate and correct one bit.**

---

# 21. HAMMING CODE — BASIC IDEA

Hamming code:
- Adds multiple parity bits.
- Places parity bits at positions that are powers of 2.
- Uses parity checks over specific groups of positions.
- At the receiver, failed parity checks form the **syndrome**.
- The syndrome gives the position of a single-bit error.

---

# 22. HOW MANY PARITY BITS ARE NEEDED?

For:

- \(m\) = number of data bits
- \(r\) = number of parity bits

the Hamming requirement is:

\[
2^r \ge m+r+1
\]

## Example: 4 data bits

\[
m=4
\]

Try \(r=2\):

\[
2^2=4
\]

but:

\[
m+r+1=4+2+1=7
\]

So 2 parity bits are insufficient.

Try \(r=3\):

\[
2^3=8
\]

and:

\[
m+r+1=4+3+1=8
\]

Therefore 3 parity bits are required.

Total bits:

\[
4+3=7
\]

Hence:

\[
\boxed{\text{Hamming}(7,4)}
\]

---

# 23. HAMMING(7,4) POSITION LAYOUT

Parity bits occupy positions:

\[
1,\;2,\;4
\]

Data bits occupy:

\[
3,\;5,\;6,\;7
\]

### Layout

```text
Position:  1   2   3   4   5   6   7
           -----------------------------
Bit:       P1  P2  D1  P4  D2  D3  D4
```

This exact arrangement is shown visually in the PDF.

---

# 24. WHICH POSITIONS DOES EACH PARITY BIT CHECK?

The PDF gives:

### P1
Checks:

\[
1,3,5,7
\]

### P2
Checks:

\[
2,3,6,7
\]

### P4
Checks:

\[
4,5,6,7
\]

These sets come from the binary representation of the position number.

---

# 25. WHY THE POSITION GROUPS WORK

Write position numbers in binary:

```text
1 = 001
2 = 010
3 = 011
4 = 100
5 = 101
6 = 110
7 = 111
```

- P1 checks positions whose least-significant binary bit is 1.
- P2 checks positions whose middle binary bit is 1.
- P4 checks positions whose high binary bit is 1.

This is why the resulting parity-check failures can identify an error position.

---

# 26. HAMMING(7,4) — COMPLETE PDF WORKED EXAMPLE

The PDF uses:

```text
Data = 1011
```

Place the data bits into positions 3, 5, 6, 7.

```text
Position: 1  2  3  4  5  6  7
           ?  ?  1  ?  0  1  1
```

Thus:

```text
P1 = ?
P2 = ?
D1 = 1
P4 = ?
D2 = 0
D3 = 1
D4 = 1
```

---

# 27. HAMMING STEP 1 — FIND P1

P1 checks:

```text
1, 3, 5, 7
```

The known data bits are:

```text
position 3 = 1
position 5 = 0
position 7 = 1
```

Number of known 1s:

```text
1 + 0 + 1 = 2
```

Two is already even.

For even parity:

```text
P1 = 0
```

Check:

```text
0 + 1 + 0 + 1 = 2 → even
```

---

# 28. HAMMING STEP 2 — FIND P2

P2 checks:

```text
2, 3, 6, 7
```

Known bits:

```text
position 3 = 1
position 6 = 1
position 7 = 1
```

Number of known 1s:

```text
3
```

Three is odd.

For even parity, P2 must be:

```text
P2 = 1
```

Now:

```text
1 + 1 + 1 + 1 = 4 → even
```

---

# 29. HAMMING STEP 3 — FIND P4

P4 checks:

```text
4, 5, 6, 7
```

Known bits:

```text
position 5 = 0
position 6 = 1
position 7 = 1
```

Number of known 1s:

```text
2
```

Already even.

Therefore:

```text
P4 = 0
```

---

# 30. FINAL HAMMING CODE

Positions:

```text
1  2  3  4  5  6  7
0  1  1  0  0  1  1
```

Therefore:

\[
\boxed{0110011}
\]

The PDF explicitly labels this as the final Hamming codeword.

---

# 31. HOW TO DRAW HAMMING(7,4) IN EXAM

1. Draw seven boxes.
2. Number them 1 to 7.
3. Put P1, P2, P4 at positions 1, 2 and 4.
4. Put data bits at 3, 5, 6 and 7.
5. Show the parity-check groups.
6. Calculate parity bits.

---

# 32. HAMMING CODE — SINGLE-BIT ERROR

Suppose the transmitted code is:

```text
0110011
```

and position 5 changes.

Received:

```text
0110111
```

The receiver does not immediately know the error position.

It performs the parity checks again.

---

# 33. SYNDROME

The result of the parity checks is called the **syndrome**.

For the PDF example:

```text
C1 / S1 → fails → 1
C2 / S2 → passes → 0
C4 / S4 → fails → 1
```

Thus:

```text
S4 S2 S1 = 101
```

Binary:

\[
101_2=5_{10}
\]

Therefore:

\[
\boxed{\text{Error is at position 5}}
\]

### Critical Rule

```text
Syndrome = 000 → no detected single-bit error
Non-zero syndrome → syndrome value identifies error position
```

---

# 34. HAMMING ERROR CORRECTION

Once the error position is known:

1. Locate that bit.
2. Flip it.
3. Reconstruct/read the data bits.

For position 5:

```text
Received: 0110111
              ^
            flip
```

Corrected code:

```text
0110011
```

Read data positions 3, 5, 6, 7:

```text
1 0 1 1
```

Recovered data:

\[
\boxed{1011}
\]

### Major advantage

Hamming code can correct a **single-bit error without requiring retransmission of the frame**.

---

# 35. ERROR DETECTION / CORRECTION SUMMARY

| Technique | Main purpose | Basic idea | Exact error location? |
|---|---|---|---|
| Parity | Detection | Add one parity bit | No |
| Checksum | Detection | One's-complement word sum | No |
| Hamming code | Correction | Multiple parity bits + syndrome | Yes, for a single-bit error |

---

# 36. FLOW CONTROL AND ERROR CONTROL

The PDF explicitly distinguishes the concepts.

## Flow Control

Question:

> **"Can the receiver keep up?"**

Purpose:
- Prevent sender from overwhelming receiver.

Methods highlighted:
- Stop-and-Wait.
- Sliding Window.

## Error Control

Question:

> **"Was the data damaged or lost?"**

Purpose:
- Detect/recover from transmission errors.

Methods:
- Acknowledgements.
- Timers.
- Retransmission.
- ARQ protocols.

### Memory Hook

**Flow control = receiver capacity.**

**Error control = damaged/lost data.**

Both are commonly implemented together in Data Link protocols.

---

# 37. ARQ

## Standard Examination Definition

**ARQ (Automatic Repeat reQuest)** is an error-control technique in which the receiver uses acknowledgements and/or negative acknowledgements, together with retransmission mechanisms, to recover from lost or corrupted frames.

### Core components
- Sequence numbers.
- ACK.
- NAK (in protocols that use explicit NAK).
- Timer.
- Retransmission.

### Basic ARQ sequence

```text
Sender                         Receiver
  | -------- Frame --------->     |
  |                              |
  | <--------- ACK -----------   |
  |                              |
  | -------- Next Frame ------>  |
```

If the frame or ACK is lost:

```text
Sender                         Receiver
  | -------- Frame --------->     X
  |                              |
  |        timeout               |
  | -------- retransmit ------>  |
```

---

# 38. STOP-AND-WAIT

## Standard Examination Definition

**Stop-and-Wait** is a flow/error-control protocol in which the sender transmits one frame and waits for its acknowledgement before transmitting the next frame.

The PDF's visual slide states:
- Send one frame.
- Wait for ACK.
- Continue after ACK.
- Very simple but can waste time while waiting.

---

# 39. STOP-AND-WAIT — NORMAL WORKING

```text
Sender                         Receiver
  |                              |
  | -------- Frame 0 ----------> |
  |                              |
  | <--------- ACK 1 ----------- |
  |                              |
  | -------- Frame 1 ----------> |
  |                              |
  | <--------- ACK 0 ----------- |
  |                              |
  | -------- Frame 0 ----------> |
```

The PDF emphasizes alternating sequence numbers, especially **0 and 1**.

## Why sequence numbers?

If a frame is retransmitted after an ACK was lost, the receiver must distinguish:

- New frame
- Duplicate copy of previously accepted frame

---

# 40. STOP-AND-WAIT — FRAME LOSS

If Frame 0 is lost:

```text
Sender                         Receiver
  | -------- Frame 0 ---- X      |
  |                              |
  |        timeout               |
  | -------- Frame 0 ----------> |
  |                              |
  | <--------- ACK 1 ----------- |
```

The sender retransmits after timeout.

---

# 41. STOP-AND-WAIT — ACK LOSS

If the receiver receives the frame but the ACK is lost:

```text
Sender                         Receiver
  | -------- Frame 0 ----------> |
  |                              |
  | <--------- ACK 1 ------- X   |
  |                              |
  |        timeout               |
  | -------- Frame 0 ----------> |
```

The receiver may see a duplicate.

The sequence number lets the receiver recognize that it has already accepted the frame.

---

# 42. STOP-AND-WAIT — ACK DELAY

If an ACK arrives too late, the sender may already have timed out and retransmitted.

Therefore the receiver can see a duplicate even though the original frame was actually delivered.

This is why sequence numbering is essential.

---

# 43. STOP-AND-WAIT ADVANTAGES AND DISADVANTAGES

### Advantages
- Simple.
- Easy to implement.
- Easy to understand.
- Provides basic flow/error control.

### Disadvantages
- Poor link utilization when propagation delay is significant.
- Sender remains idle while waiting.
- Low throughput on long-delay/high-speed links.

### Key idea

**One frame at a time = simple but potentially inefficient.**

---

# 44. SLIDING WINDOW

## Standard Examination Definition

A **sliding-window protocol** allows a sender to have multiple outstanding frames before waiting for acknowledgements, up to a defined **window size**.

### Basic idea

Instead of:

```text
Send 0 → wait
Send 1 → wait
Send 2 → wait
```

the sender can do:

```text
Send 0
Send 1
Send 2
Send 3
... 
```

within the permitted window.

---

# 45. WHY SLIDING WINDOW IS NEEDED

The PDF visually compares a window containing several sequence numbers.

Example:

```text
Before:

[0][1][2][3] [4][5][6][7][8][9]
 \____window____/

After ACKs:

[0][1] [2][3][4][5] [6][7][8][9]
       \____window____/
```

When acknowledgements arrive, the window **slides forward**.

### Benefits
- Better link utilization.
- Multiple frames can be in transit.
- Higher throughput than Stop-and-Wait on long-delay links.

---

# 46. SLIDING WINDOW — KEY TERMS

### Sender window
Frames the sender is permitted to transmit without waiting for further acknowledgements.

### Receiver window
Frames the receiver is prepared/allowed to accept and buffer, depending on the protocol.

### Outstanding frames
Frames transmitted but not yet cumulatively/individually acknowledged.

---

# 47. GO-BACK-N ARQ

## Standard Examination Definition

**Go-Back-N ARQ** is a sliding-window ARQ protocol in which the sender may transmit multiple frames, but when a frame is lost or damaged, the receiver generally discards the out-of-order frames and the sender retransmits the erroneous/missing frame and all subsequent frames in the outstanding sequence.

---

# 48. GO-BACK-N — BASIC WORKING

Suppose the sender transmits:

```text
F0  F1  F2  F3
```

If F2 is lost:

```text
Sender                         Receiver

F0 --------------------------> accept
F1 --------------------------> accept
F2 --------------------------> LOST
F3 --------------------------> out of order
```

The receiver does not accept F3 as the next in-order frame.

It indicates that it is still waiting for F2.

The sender then goes back:

```text
F2 retransmit
F3 retransmit
```

This is the origin of the name **Go-Back-N**.

---

# 49. GO-BACK-N — ACK BEHAVIOR

The PDF explains that acknowledgements can be **cumulative**.

An ACK can indicate the next expected frame.

For example:

```text
ACK 2
```

can mean:

> Frames through 1 have been accepted; frame 2 is expected next.

### Important

The exact ACK numbering convention depends on the protocol notation, so always interpret the teacher's sequence-number convention consistently.

---

# 50. GO-BACK-N — WORKED EXAMPLE

PDF sequence:

| Step | Sender | Receiver |
|---|---|---|
| 1 | Send F0 | Accept F0 |
| 2 | Send F1 | Accept F1 |
| 3 | Send F2 | F2 lost |
| 4 | Send F3 | Waits for F2 |
| 5 | Send F4 | Waits for F2 |
| 6 | Timeout | Retransmit F2, F3, F4 |

### Memory

**F2 is missing → GBN goes back to F2 and resends everything after it.**

---

# 51. GO-BACK-N WINDOW CONDITION

The PDF includes the key relation:

\[
\boxed{\text{Sender window} \le 2^m-1}
\]

where \(m\) is the number of bits used for the sequence number.

The receiver window for the basic GBN scheme is effectively:

\[
\boxed{1}
\]

because it accepts only the next in-order frame.

---

# 52. GO-BACK-N ADVANTAGES

- Better efficiency than Stop-and-Wait.
- Multiple frames can be transmitted before ACKs.
- Receiver buffering requirements are relatively small.
- Cumulative acknowledgements simplify receiver feedback.

## Disadvantage

When one frame is lost, correctly received later frames may be retransmitted unnecessarily.

---

# 53. SELECTIVE REPEAT ARQ

## Standard Examination Definition

**Selective Repeat ARQ** is a sliding-window ARQ protocol in which the receiver can accept and buffer correctly received out-of-order frames, while the sender retransmits only the specific frames that are lost or damaged.

---

# 54. SELECTIVE REPEAT — BASIC WORKING

Suppose:

```text
F0 → received
F1 → received
F2 → lost
F3 → received
```

Unlike GBN, the receiver can:

```text
accept F3
buffer F3
wait for F2
```

The sender retransmits only F2.

After F2 arrives, the receiver can deliver the stored frames in correct order.

---

# 55. SELECTIVE REPEAT — PDF WORKED EXAMPLE

PDF sequence:

| Step | Sender | Receiver |
|---|---|---|
| 1 | Send F0 | Accept F0 |
| 2 | Send F1 | Accept F1 |
| 3 | Send F2 | F2 lost |
| 4 | Send F3 | Store F3 |
| 5 | Send F4 | Store F4 |
| 6 | Resend F2 | Accept F2; deliver F2, F3, F4 |

### Memory

**GBN → resend F2 onward.**

**Selective Repeat → resend F2 only.**

---

# 56. SELECTIVE REPEAT WINDOW CONDITION

The PDF highlights:

\[
\boxed{\text{Sender window} \le 2^{m-1}}
\]

for the usual Selective Repeat sequence-number-space rule.

The reason is to avoid ambiguity between old and new frames when sequence numbers wrap around.

---

# 57. GO-BACK-N vs SELECTIVE REPEAT

| Parameter | Go-Back-N ARQ | Selective Repeat ARQ |
|---|---|---|
| Sender window | Multiple frames | Multiple frames |
| Receiver window | 1 in basic GBN | Multiple |
| Out-of-order frames | Usually discarded | Accepted/buffered |
| ACK style | Often cumulative | Individual/selective acknowledgements |
| On loss | Retransmit lost + following frames | Retransmit only lost/damaged frame |
| Receiver memory | Low | Higher |
| Bandwidth efficiency | Lower when errors occur | Better |
| Complexity | Moderate | Higher |
| Best use | Short/low-error links | Longer/high-error links where retransmitting many frames is costly |

---

# 58. STOP-AND-WAIT vs GBN vs SELECTIVE REPEAT

| Feature | Stop-and-Wait ARQ | Go-Back-N ARQ | Selective Repeat ARQ |
|---|---|---|---|
| Frames in flight | 1 | Up to sender window | Up to sender window |
| Receiver window | 1 | 1 | Multiple |
| On error | Resend same frame | Resend error frame and following outstanding frames | Resend only affected frame |
| Out-of-order buffering | No | No | Yes |
| ACK approach | ACK per frame | Cumulative ACK | Selective/individual ACK |
| Buffer at receiver | One frame | One frame | Many frames |
| Efficiency | Low | Good | Best when errors occur |
| Complexity | Simple | Medium | Highest |
| Suitable for | Short/slow links | General sliding-window use | High-delay/error-prone links |

---

# 59. DATA LINK PROTOCOLS — HDLC

## 59.1 Standard Examination Definition

**HDLC (High-Level Data Link Control)** is a **bit-oriented Data Link Layer protocol** used for reliable communication over point-to-point and multipoint links, providing framing, flow control and error control.

The PDF describes HDLC as:
- Bit-oriented.
- Supporting framing.
- Supporting flow control.
- Supporting error control.
- Using Stop-and-Wait, Go-Back-N or Selective Repeat internally as appropriate.

---

# 60. HDLC CONFIGURATIONS

The PDF shows two configurations.

## 60.1 Unbalanced Configuration

One station is the **primary** station and controls one or more **secondary** stations.

```text
             Secondary
                 |
                 |
Primary ---------+--------- Secondary
```

The primary controls communication.

## 60.2 Balanced Configuration

Stations are treated as combined/peer stations.

```text
Station A <----------------> Station B
```

Both can participate as peers.

---

# 61. HDLC TRANSFER MODES

The PDF shows:

## NRM — Normal Response Mode
A secondary station transmits only when explicitly permitted/polled by the primary.

## ABM — Asynchronous Balanced Mode
Balanced stations can initiate transmission without waiting for a primary to give permission.

### Comparison

| Feature | NRM | ABM |
|---|---|---|
| Configuration | Unbalanced | Balanced |
| Secondary initiation | Requires permission/poll | Peer stations can initiate |
| Typical relationship | Primary-secondary | Peer-to-peer |
| Control | Primary-centered | Distributed |

---

# 62. HDLC FRAME FORMAT

The PDF's visual frame has:

```text
+------+---------+---------+-----------+------+------+
| Flag | Address | Control | Information| FCS  | Flag |
+------+---------+---------+-----------+------+------+
```

## Fields

### Flag
Marks frame boundaries.

The PDF shows the HDLC flag pattern:

```text
01111110
```

### Address
Identifies the station/address involved.

### Control
Carries frame-type/control information.

### Information
Carries user data when present.

### FCS
**Frame Check Sequence** used for error detection.

### Ending Flag
Again marks the end of the frame.

---

# 63. HDLC FRAME TYPES

The first bits of the Control field determine the frame type.

The PDF identifies:

1. I-frame — Information
2. S-frame — Supervisory
3. U-frame — Unnumbered

---

# 64. HDLC I-FRAME

**I-frame = Information frame**

Used to carry user data and sequence/control information.

The PDF notes that it supports:
- User data.
- Piggybacked acknowledgements.
- Send/receive sequence numbers.

### General idea

```text
I-frame = data + sequence/control information
```

---

# 65. HDLC S-FRAME

**S-frame = Supervisory frame**

Used mainly for control functions such as acknowledgements and flow/error management.

The PDF mentions:
- Receive Ready (RR)
- Receive Not Ready (RNR)
- Reject (REJ)
- Selective Reject (SREJ)

### Examples

**RR** → receiver is ready / acknowledges.

**RNR** → receiver is temporarily not ready.

**REJ** → requests retransmission according to the applicable recovery procedure.

**SREJ** → selectively requests retransmission of a particular frame.

---

# 66. HDLC U-FRAME

**U-frame = Unnumbered frame**

Used for link management/control functions rather than ordinary numbered information transfer.

The PDF's table classifies U-frames as:

```text
Control field begins with 11
```

---

# 67. HDLC BIT STUFFING

The PDF includes an important visual note:

The flag is:

```text
01111110
```

To prevent this flag pattern from appearing accidentally inside data, HDLC uses **bit stuffing**.

### Rule

Whenever the sender encounters **five consecutive 1s** in the data, it inserts a **0**.

Example:

```text
Original data:
0111111

After stuffing:
01111101
       ^
    inserted 0
```

At the receiver, after five consecutive 1s, the stuffed 0 is removed.

### Why?

To ensure the special flag pattern remains recognizable.

---

# 68. PPP — POINT-TO-POINT PROTOCOL

## Standard Examination Definition

**PPP (Point-to-Point Protocol)** is a Data Link Layer protocol used to encapsulate and transport network-layer packets across a direct point-to-point link.

The PDF describes PPP as connecting exactly two devices over a single link, with examples including:
- Dial-up modems.
- DSL.
- Broadband links.
- Router-to-router links.

---

# 69. WHAT PPP PROVIDES

The PDF lists:

### 1. Framing with error checking
PPP provides a frame structure with an FCS field.

### 2. Authentication
PPP can support authentication through protocols such as:
- PAP
- CHAP

### 3. Multiple network-layer protocols
PPP can carry different network-layer protocols.

### 4. Dynamic IP address assignment
PPP environments can use network-control mechanisms to negotiate IP parameters.

---

# 70. WHAT PPP DOES NOT PROVIDE

The PDF explicitly warns that PPP does **not itself provide**:

- Flow control.
- Error recovery/retransmission.
- Automatic routing.
- End-to-end congestion control.

This is a very important exam distinction.

PPP provides framing/link establishment and related control; reliable retransmission, routing, and congestion control are not automatically supplied by PPP itself.

---

# 71. PPP FRAME FORMAT

```text
+------+---------+---------+----------+---------+------+
| Flag | Address | Control | Protocol | Payload | FCS  | Flag
+------+---------+---------+----------+---------+------+
```

The PDF shows:
- Flag
- Address
- Control
- Protocol
- Payload
- FCS
- Flag

### Key distinction from HDLC

PPP is byte/character-oriented in its framing conventions and uses an escape mechanism, whereas HDLC is presented in the PDF as a bit-oriented protocol with bit stuffing.

---

# 72. PPP STACK

The PDF says PPP is a protocol family.

## LCP — Link Control Protocol

Used to:
- Establish the link.
- Configure link parameters.
- Test/manage the link.

## Authentication protocols

### PAP
**Password Authentication Protocol**

Simple username/password-style authentication.

### CHAP
**Challenge Handshake Authentication Protocol**

Uses a challenge-response approach.

## NCP — Network Control Protocols

Used to configure network-layer protocols/parameters.

The PDF specifically illustrates NCP for configuring IP-related parameters.

---

# 73. PPP CONNECTION PHASES

The PDF shows this sequence:

```text
DEAD
  |
  v
ESTABLISH
  |
  v
AUTHENTICATE
  |
  v
NETWORK
  |
  v
OPEN
  |
  v
TERMINATE
```

## 1. Dead
No active PPP link.

## 2. Establish
LCP establishes/configures the link.

## 3. Authenticate
Authentication occurs if configured/required.

## 4. Network
NCP negotiates network-layer configuration.

## 5. Open
Data transfer occurs.

## 6. Terminate
The PPP connection is closed.

### Memory

**Dead → Establish → Authenticate → Network → Open → Terminate**

---

# 74. MULTIPLE ACCESS

## Standard Examination Definition

**Multiple access** refers to techniques that allow multiple devices/users to share a common communication medium or channel while controlling access and minimizing or managing collisions.

### Collision concept

If multiple devices transmit on the same shared channel at the same time, their signals can interfere.

The PDF illustrates:

```text
PC1 ----\
PC2 -----+---- Shared medium
PC3 ----/
          X
       COLLISION
```

---

# 75. THREE MAIN MULTIPLE-ACCESS CATEGORIES

The PDF divides access methods into:

```text
Multiple Access
      |
      +-- Random Access
      |
      +-- Controlled Access
      |
      +-- Channelization
```

### Random Access
Stations contend for access.

### Controlled Access
Stations coordinate access through an agreement/control mechanism.

### Channelization
The shared resource is divided among users by frequency, time or code.

---

# 76. RANDOM ACCESS

## Definition

In **random access**, stations compete for access to a shared medium without a fixed predetermined transmission schedule.

The PDF states that collisions are possible and access is attempted according to the protocol's rules.

Examples:
- ALOHA
- Slotted ALOHA
- CSMA
- CSMA/CD
- CSMA/CA

---

# 77. ALOHA

## Standard Examination Definition

**ALOHA** is a random-access MAC protocol in which a station transmits when it has data; if a collision occurs, it waits for a random time and retransmits.

The PDF describes it as one of the oldest random-access methods.

---

# 78. PURE ALOHA

### Working

1. A station transmits whenever it has a frame.
2. It waits for acknowledgement.
3. If collision occurs/no acknowledgement is received, it waits a random time.
4. It retransmits.

### Diagram idea

```text
Time →
A:      [Frame]------X
B:           [Frame]-X
                 collision
```

### Vulnerable period

For Pure ALOHA:

\[
\boxed{2T}
\]

where \(T\) is the frame transmission time.

### Maximum theoretical efficiency

Approximately:

\[
\boxed{18.4\%}
\]

or:

\[
S_{max}=\frac{1}{2e}\approx0.184
\]

---

# 79. SLOTTED ALOHA

Slotted ALOHA divides time into slots.

A station can begin transmission only at the **beginning of a slot**.

### Working

1. Time is divided into equal slots.
2. Stations wait for a slot boundary.
3. Transmission begins at a slot boundary.
4. If multiple stations choose the same slot, collision occurs.
5. After collision, stations wait/retry.

### Vulnerable period

\[
\boxed{T}
\]

### Maximum theoretical efficiency

Approximately:

\[
\boxed{36.8\%}
\]

\[
S_{max}=\frac{1}{e}\approx0.368
\]

### Pure vs Slotted ALOHA

| Parameter | Pure ALOHA | Slotted ALOHA |
|---|---|---|
| Transmission start | Any time | Slot boundary |
| Synchronization | Not required | Required |
| Vulnerable period | 2T | T |
| Maximum efficiency | ~18.4% | ~36.8% |

---

# 80. CSMA

## Standard Examination Definition

**CSMA (Carrier Sense Multiple Access)** is a random-access protocol in which a station senses the shared medium before transmitting and transmits only according to the protocol's carrier-sensing rules.

### Memory

**"Listen before you talk."**

The PDF states:
- A station first senses the link.
- If the channel is idle, it transmits.
- If busy, it follows a persistence/backoff strategy.

### Important

Carrier sensing reduces collisions but does **not eliminate them**, because two stations may sense an apparently idle channel at nearly the same time.

---

# 81. CSMA PERSISTENCE METHODS

The PDF's comparison table shows:

## 1-persistent CSMA

If channel is idle:
- Transmit immediately.

If channel is busy:
- Keep sensing.
- Transmit immediately when it becomes idle.

**Advantage:** Low waiting time.

**Disadvantage:** Higher collision probability when many stations are waiting.

---

## Non-persistent CSMA

If channel is busy:
- Do not continuously sense.
- Wait a random time.
- Sense again.

**Advantage:** Fewer collisions than aggressive persistent behavior.

**Disadvantage:** More delay.

---

## p-persistent CSMA

Used with slotted channels.

When channel becomes idle:
- Transmit with probability \(p\).
- Defer with probability \(1-p\) and try again according to the protocol.

---

# 82. CSMA/CD

## Standard Examination Definition

**CSMA/CD (Carrier Sense Multiple Access with Collision Detection)** is a medium-access technique in which a station senses the channel before transmitting and monitors the medium during transmission to detect collisions.

The PDF associates CSMA/CD with **wired Ethernet**.

### Working

1. Sense the channel.
2. If busy, wait according to the persistence rule.
3. If idle, transmit.
4. Monitor for collision.
5. If collision occurs:
   - Stop transmission.
   - Send/recognize the collision condition as applicable.
   - Wait for a backoff period.
   - Retransmit.

### Memory

**CSMA/CD = listen → transmit → detect collision → back off → retry**

---

# 83. CSMA/CD COLLISION-FREE APPROACHES SHOWN IN THE PDF

The PDF gives three persistence methods in a table:

| Method | Behavior |
|---|---|
| 1-persistent | Keep sensing; transmit immediately when idle |
| Non-persistent | Wait a random time before sensing again |
| p-persistent | In a slotted system, transmit with probability p |

---

# 84. CSMA/CA

## Standard Examination Definition

**CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance)** is a wireless medium-access method that attempts to reduce the probability of collisions by using channel sensing, waiting/backoff, and other coordination mechanisms before/during transmission.

The PDF associates CSMA/CA with **Wi-Fi/wireless networking**.

### Why CA instead of CD?

In wireless networks, detecting a collision while transmitting is difficult because a wireless station's own transmitted signal can overwhelm the received signal.

Therefore Wi-Fi focuses on **collision avoidance**.

---

# 85. CSMA/CA — BASIC WORKING

1. Sense the channel.
2. If busy, defer.
3. If idle, wait according to the protocol's interframe/backoff rules.
4. Choose a random backoff interval.
5. Count down while the channel remains idle.
6. Transmit when the backoff reaches zero.
7. Wait for acknowledgement.
8. If ACK is not received, assume the transmission may have failed and retry according to the protocol.

The PDF emphasizes:
- Random backoff.
- Collision avoidance.
- ACK.
- Hidden-terminal-related considerations.

---

# 86. CSMA/CD vs CSMA/CA

| Parameter | CSMA/CD | CSMA/CA |
|---|---|---|
| Full form | Collision Detection | Collision Avoidance |
| Common association | Traditional wired Ethernet | Wi-Fi/wireless |
| Main idea | Detect collision after transmission begins | Reduce chance of collision before/during transmission |
| ACK central? | Not the defining feature | Important in Wi-Fi |
| Collision detection | Possible in traditional shared Ethernet | Difficult in wireless |
| Backoff | Used after collision | Used to avoid/recover from collision |
| Example | Classic shared Ethernet | IEEE 802.11 Wi-Fi |

---

# 87. CONTROLLED ACCESS

## Definition

In **controlled access**, stations coordinate access to the shared medium so that only the station permitted by the control mechanism transmits at a given time.

The PDF lists three methods:

1. Reservation
2. Polling
3. Token Passing

### Key idea

```text
Random Access → stations contend
Controlled Access → stations take turns by agreement
```

---

# 88. RESERVATION

## Working

1. Stations first indicate whether they need transmission.
2. A reservation mechanism assigns/organizes upcoming transmission opportunities.
3. Reserved stations transmit during their assigned opportunity.

The PDF visually shows a set of stations where reservation slots indicate which stations intend to transmit.

### Advantages
- Collisions can be avoided.
- Order can be organized.

### Disadvantages
- Reservation overhead.
- Less efficient when very few stations have data.

---

# 89. POLLING

## Definition

**Polling** is a controlled-access method in which a central **primary/controller** asks secondary stations, one by one, whether they have data to transmit.

### Diagram

```text
             +-----------+
             |  Primary  |
             +-----------+
              /   |   \
            Poll Poll Poll
            /      |      \
          S1       S2      S3
```

### Working

1. Primary polls S1.
2. S1 transmits if it has data.
3. Primary polls S2.
4. Continue through the stations.

### Advantages
- No collisions when properly controlled.
- Predictable access.

### Disadvantages
- Polling overhead.
- Central controller can become a bottleneck/failure point.

---

# 90. TOKEN PASSING

## Definition

**Token passing** is a controlled-access method in which a special control frame called a **token** circulates among stations, and only the station holding the token is permitted to transmit.

### Diagram

```text
      [S1]
     /    \
   [S4]   [S2]
     \    /
      [S3]

Token → S1 → S2 → S3 → S4 → S1
```

The PDF shows a logical ring of stations and a token moving around the ring.

### Advantages
- Collision-free access.
- Fair access.
- Predictable waiting time.

### Disadvantages
- Token management overhead.
- Token loss requires recovery.
- A failed station/link can affect the logical ring unless redundancy/recovery exists.

---

# 91. CONTROLLED ACCESS TRADE-OFF

The PDF highlights:

> Controlled access wastes little bandwidth on collisions but introduces a small amount of access delay because a station may have to wait for its turn.

This is an important exam explanation.

---

# 92. CHANNELIZATION

## Standard Examination Definition

**Channelization** is a multiple-access technique in which a shared communication medium is divided among users by assigning distinct **frequency bands, time slots, or spreading codes**.

The PDF describes it as dividing a shared medium among multiple users so they do not compete directly for the same resource.

### Three methods

1. FDMA — Frequency
2. TDMA — Time
3. CDMA — Code

### Memory

**FDMA = Frequency**

**TDMA = Time**

**CDMA = Code**

---

# 93. FDMA

## Standard Examination Definition

**FDMA (Frequency Division Multiple Access)** divides the available channel bandwidth into separate frequency bands and assigns different frequency bands to different users.

### Diagram

```text
Frequency
  ^
  | +---------+  User 3
  | +---------+
  | +---------+  User 2
  | +---------+
  | +---------+  User 1
  +--------------------> Time
```

The PDF visual shows users S1, S2 and S3 occupying different frequency bands while operating over the same time period.

### Key idea

**Different frequency + same time**

### Advantages
- Continuous transmission possible.
- Users do not interfere if frequency bands are properly separated.
- Less synchronization than TDMA.

### Disadvantages
- Guard bands are needed between frequency channels.
- Bandwidth can be wasted if a user is idle.
- Less efficient for bursty traffic.

---

# 94. TDMA

## Standard Examination Definition

**TDMA (Time Division Multiple Access)** divides access into repeating time slots and assigns different time slots to users sharing the same frequency.

### Diagram

```text
Time →
+----+----+----+----+
| S1 | S2 | S3 | S1 |
+----+----+----+----+
     Same frequency
```

### Key idea

**Same frequency + different time**

### Advantages
- Efficient sharing of a common frequency.
- No frequency-band separation required for individual users.
- Each user receives a defined transmission opportunity.

### Disadvantages
- Requires synchronization.
- Guard time may be required.
- An idle user's slot may be wasted.

---

# 95. CDMA

## Standard Examination Definition

**CDMA (Code Division Multiple Access)** allows multiple users to share the same frequency band at the same time by assigning each user a distinct spreading code.

### Diagram

```text
Same frequency + same time

S1 ---> Code A ----\
S2 ---> Code B -----+--> Shared channel
S3 ---> Code C ----/          |
                              v
                       Receiver uses
                       correct code
```

The PDF uses the analogy of different people speaking different languages in the same room.

### Key idea

**Same time + same frequency + different code**

### Advantages
- Good resistance to interference.
- Efficient use of frequency resources.
- Multiple users share the same band.

### Disadvantages
- More complex signal processing.
- Requires careful code management/control.
- Receiver must use the correct code.

---

# 96. FDMA vs TDMA vs CDMA

| Parameter | FDMA | TDMA | CDMA |
|---|---|---|---|
| Resource separated by | Frequency | Time | Code |
| Frequency | Different bands | Same | Same |
| Time | Same/continuous | Different slots | Same |
| Key concept | Separate frequency channels | Separate time slots | Separate spreading codes |
| Main requirement | Guard bands | Synchronization/guard time | Code/spreading processing |
| Major limitation | Idle frequency may be wasted | Idle time slots may be wasted | More complex processing |
| PDF memory | Frequency = shared | Time = shared | Same frequency + time, code separates users |

---

# 97. MULTIPLE ACCESS — COMPLETE COMPARISON

| Category | Random Access | Controlled Access | Channelization |
|---|---|---|---|
| Basic idea | Stations compete | Stations take turns by coordination | Channel is divided |
| Collision | Possible | Avoided | Avoided through separation |
| Access | Contention | Reservation/poll/token | Frequency/time/code |
| Examples | ALOHA, CSMA, CSMA/CD, CSMA/CA | Reservation, Polling, Token Passing | FDMA, TDMA, CDMA |
| Main strength | Flexible for bursty traffic | Fair/predictable | Efficient structured sharing |
| Main limitation | Collisions/backoff | Control overhead | Resource allocation overhead |

---

# 98. PAGE 50 — PDF QUICK COMPARISON TABLE

The PDF's visual comparison can be reproduced as:

| Aspect | Random Access | Controlled Access | Channelization |
|---|---|---|---|
| Who decides? | Each station on its own | An agreed turn-taking mechanism | Channel is pre-divided |
| Collisions | Possible | None under proper control | None due to separation |
| Examples | ALOHA, CSMA, CSMA/CD, CSMA/CA | Reservation, Polling, Token Passing | FDMA, TDMA, CDMA |
| Wasted resource | Backoff/collision losses | Waiting/turn overhead | Unused assigned channel portions |
| Main point | Fast/simple but contention | Fair and orderly | Users separated by resource |
| Seen in | Ethernet, Wi-Fi | Token ring, controlled polling, etc. | Mobile/wireless, satellite links |

The PDF's quiz-style memory line is essentially:

**Random access = students shout out.**

**Controlled access = raise your hand and wait for your turn.**

**Channelization = the class is split into groups, each with its own resource.**

---

# 99. ERROR DETECTION vs ERROR CORRECTION vs ARQ

This is one of the most important conceptual distinctions.

| Concept | Main question | Example |
|---|---|---|
| Error detection | Is the data corrupted? | Parity, checksum |
| Error correction | Where is the error and how can it be fixed? | Hamming code |
| ARQ | Can the damaged/lost frame be retransmitted? | Stop-and-Wait ARQ, GBN, SR |

### Relationship

```text
Transmission
     |
     v
Error occurs
     |
     v
Detection
     |
     +------> Direct correction (e.g., Hamming)
     |
     +------> Retransmission/recovery (ARQ)
```

---

# 100. FLOW CONTROL vs ERROR CONTROL

| Parameter | Flow Control | Error Control |
|---|---|---|
| Main problem | Sender too fast for receiver | Data lost/damaged |
| Main goal | Match sender to receiver capacity | Reliable recovery |
| Examples | Stop-and-Wait, Sliding Window | ARQ, ACK, retransmission |
| Main question | "Can receiver keep up?" | "Did data arrive correctly?" |

---

# 101. STOP-AND-WAIT vs SLIDING WINDOW

| Feature | Stop-and-Wait | Sliding Window |
|---|---|---|
| Frames outstanding | One | Multiple |
| Efficiency | Lower | Higher |
| Complexity | Low | Higher |
| Link utilization | Poor on high-delay links | Better |
| Flow control | Basic | Stronger/flexible |
| Error control | Can use ARQ | GBN/SR can use ARQ |

---

# 102. GBN vs SELECTIVE REPEAT — MOST IMPORTANT DIFFERENCE

### Go-Back-N

```text
F0 ✓
F1 ✓
F2 X
F3 ✓ but out-of-order
F4 ✓ but out-of-order

Retransmit:
F2 → F3 → F4
```

### Selective Repeat

```text
F0 ✓
F1 ✓
F2 X
F3 ✓ → buffer
F4 ✓ → buffer

Retransmit:
F2 only
```

**Memory line:**

> **GBN repeats everything after the mistake.**

> **Selective Repeat repeats only the mistake.**

---

# 103. HDLC vs PPP

| Parameter | HDLC | PPP |
|---|---|---|
| Full form | High-Level Data Link Control | Point-to-Point Protocol |
| Layer | Data Link | Data Link |
| Orientation | Bit-oriented | Byte-oriented framing convention |
| Main use | Reliable data-link communication | Point-to-point Internet/data links |
| Frame fields | Flag, Address, Control, Information, FCS, Flag | Flag, Address, Control, Protocol, Payload, FCS, Flag |
| Error check | FCS | FCS |
| Authentication | Not its primary feature | PAP/CHAP supported |
| Bit stuffing | Yes | Uses byte/character escape mechanisms |
| Network-layer configuration | Not its central PPP-style function | NCP |
| Link configuration | HDLC control procedures | LCP |

---

# 104. HDLC vs PPP — IMPORTANT EXAM NOTE

Do not simply write:

> "PPP is a type of HDLC."

A better answer:

> PPP is a separate Data Link Layer protocol designed for point-to-point links. Its framing resembles HDLC framing, but PPP adds features such as protocol identification, LCP, NCP and authentication support.

---

# 105. PURE ALOHA vs SLOTTED ALOHA

| Parameter | Pure ALOHA | Slotted ALOHA |
|---|---|---|
| Start transmission | Any time | Beginning of slot |
| Synchronization | Not required | Required |
| Vulnerable period | 2T | T |
| Maximum efficiency | ~18.4% | ~36.8% |
| Collision probability | Higher | Lower |
| Complexity | Lower | Higher |

---

# 106. RANDOM ACCESS vs CONTROLLED ACCESS

| Parameter | Random Access | Controlled Access |
|---|---|---|
| Access decision | Station contends | Protocol assigns/coordinates turn |
| Collisions | Possible | Avoided |
| Delay | Can be low when lightly loaded | Turn-taking may add delay |
| Examples | ALOHA, CSMA | Polling, reservation, token |
| Suitable for | Bursty/irregular traffic | Predictable/fair shared access |

---

# 107. CSMA/CD vs CSMA/CA

**CD:**

> Detect a collision after/while transmission.

**CA:**

> Try to avoid collision before transmission and recover when needed.

**Exam keyword:**

```text
Wired Ethernet → CSMA/CD (traditional shared Ethernet)
Wi-Fi          → CSMA/CA
```

Modern switched full-duplex Ethernet normally does not use CSMA/CD for ordinary switched links, but the university material teaches CSMA/CD as the classic Ethernet access method.

---

# 108. NUMERICAL FORMULA SHEET

## Hamming parity-bit formula

\[
\boxed{2^r \ge m+r+1}
\]

Where:
- \(m\) = data bits
- \(r\) = parity bits

---

## Pure ALOHA maximum efficiency

\[
\boxed{S_{max}=\frac{1}{2e}\approx18.4\%}
\]

---

## Slotted ALOHA maximum efficiency

\[
\boxed{S_{max}=\frac{1}{e}\approx36.8\%}
\]

---

# 109. EXAM-DRAWABLE DIAGRAMS — QUICK SHEET

## Data Link Layer

```text
Network Layer
     |
     v
+------------------+
|  DATA LINK       |
| framing          |
| error control    |
| flow control     |
| access control   |
+------------------+
     |
     v
Physical Layer
```

## Frame

```text
+--------+---------+----------+
| Header |  Data   | Trailer |
+--------+---------+----------+
```

## Hamming(7,4)

```text
Position: 1  2  3  4  5  6  7
          P1 P2 D1 P4 D2 D3 D4
```

## Stop-and-Wait

```text
Sender                 Receiver
  | ---- Frame 0 -----> |
  | <------ ACK 1 ----- |
  | ---- Frame 1 -----> |
  | <------ ACK 0 ----- |
```

## Go-Back-N

```text
F0 ✓
F1 ✓
F2 X
F3 discarded

Retransmit:
F2 → F3
```

## Selective Repeat

```text
F0 ✓
F1 ✓
F2 X
F3 buffered

Retransmit:
F2 only
```

## HDLC

```text
+------+---------+---------+-------------+------+------+
| Flag | Address | Control | Information | FCS  | Flag |
+------+---------+---------+-------------+------+------+
```

## PPP

```text
+------+---------+---------+----------+---------+------+------+
| Flag | Address | Control | Protocol | Payload | FCS  | Flag |
+------+---------+---------+----------+---------+------+------+
```

## Polling

```text
       Primary
       /  |  \
    Poll Poll Poll
     /     |     \
   S1      S2     S3
```

## Token passing

```text
S1 → S2 → S3 → S4
^               |
|_______________|
       token
```

## FDMA

```text
Frequency
  ^
  | S3 =========
  | S2 =========
  | S1 =========
  +----------------> Time
```

## TDMA

```text
Time →
+----+----+----+----+
| S1 | S2 | S3 | S1 |
+----+----+----+----+
```

## CDMA

```text
Same time + same frequency
S1 → Code A \
S2 → Code B  > Shared channel
S3 → Code C /
```

---

# 110. HOW TO DRAW IMPORTANT DIAGRAMS IN EXAM

## Hamming Code
1. Draw seven boxes.
2. Number 1–7.
3. Put parity at 1, 2, 4.
4. Put data at 3, 5, 6, 7.
5. Show parity groups if required.

## Stop-and-Wait
1. Draw sender and receiver vertical lines.
2. Draw diagonal frame arrow.
3. Draw ACK arrow back.
4. Repeat for next frame.

## GBN/SR
1. Draw sender and receiver.
2. Show frames in sequence.
3. Mark one frame lost.
4. Show receiver behavior.
5. Show retransmission.

## HDLC/PPP
1. Draw rectangular fields.
2. Put Flag at both ends.
3. Label internal fields.
4. For HDLC add Control/Information/FCS.
5. For PPP add Protocol/Payload/FCS.

## Multiple Access
1. Draw shared channel.
2. Add stations.
3. Show the method-specific allocation:
   - ALOHA → random transmissions/collision.
   - Polling → central controller.
   - Token → circular token.
   - FDMA → frequency bands.
   - TDMA → time slots.
   - CDMA → codes.

---

# 111. COMMON MISTAKES

1. **Parity detects but normally does not locate the erroneous bit.**
2. **Hamming code is different from simple parity:** it uses multiple parity bits and a syndrome.
3. Do not confuse **checksum** with parity.
4. Do not confuse **flow control** with **error control**.
5. Do not say Stop-and-Wait allows many unacknowledged frames.
6. Do not say GBN buffers all out-of-order frames; basic GBN receiver window is 1.
7. Do not say Selective Repeat retransmits every frame after the error.
8. Do not forget sequence numbers in Stop-and-Wait ARQ.
9. Do not confuse ACK loss with frame loss.
10. In Hamming code, parity positions are powers of 2.
11. For Hamming(7,4), parity positions are **1, 2, 4**.
12. For Hamming(7,4), data positions are **3, 5, 6, 7**.
13. Syndrome 000 means no detected single-bit error; nonzero syndrome identifies the position in the basic single-bit-error case.
14. HDLC flag = **01111110**.
15. HDLC uses **bit stuffing** after five consecutive 1s.
16. PPP is for **point-to-point links**.
17. PPP uses **LCP** for link control and **NCP** for network-layer configuration.
18. PAP and CHAP are authentication mechanisms associated with PPP.
19. PPP itself does not provide general routing or end-to-end congestion control.
20. ALOHA is random access.
21. CSMA means **listen before transmitting**.
22. CSMA/CD is associated with traditional shared wired Ethernet.
23. CSMA/CA is associated with Wi-Fi.
24. Polling uses a controller.
25. Token passing uses a token.
26. FDMA = frequency.
27. TDMA = time.
28. CDMA = code.
29. Pure ALOHA maximum efficiency ≈ 18.4%.
30. Slotted ALOHA maximum efficiency ≈ 36.8%.

---

# 112. EXAM POINTS TO REMEMBER

## Data Link Layer
- Layer 2.
- Node-to-node delivery.
- Frame.
- Framing.
- Error control.
- Flow control.
- Access control.
- Physical/MAC addressing.

## Errors
- Single-bit.
- Burst.
- Noise.
- Attenuation.
- Interference/crosstalk.

## Detection
- Parity.
- Checksum.

## Correction
- Hamming.
- Syndrome.

## ARQ
- ACK.
- Sequence number.
- Timer.
- Retransmission.
- Stop-and-Wait.
- Go-Back-N.
- Selective Repeat.

## HDLC
- Bit-oriented.
- Flag = 01111110.
- Address.
- Control.
- Information.
- FCS.
- I/S/U frames.
- Bit stuffing.
- NRM/ABM.

## PPP
- Point-to-point.
- LCP.
- PAP/CHAP.
- NCP.
- Frame.
- FCS.
- Phases: Dead → Establish → Authenticate → Network → Open → Terminate.

## Multiple Access
- Random.
- Controlled.
- Channelization.

## Random
- ALOHA.
- Slotted ALOHA.
- CSMA.
- CSMA/CD.
- CSMA/CA.

## Controlled
- Reservation.
- Polling.
- Token passing.

## Channelization
- FDMA.
- TDMA.
- CDMA.

---

# 113. POTENTIAL EXAM QUESTIONS

These are **potential questions**, not claims about the exact examination paper.

## Very Short Questions — 1–2 Marks

1. Define Data Link Layer.
2. What is framing?
3. Define a frame.
4. What is a transmission error?
5. Define single-bit error.
6. Define burst error.
7. What is error detection?
8. What is error correction?
9. Define parity bit.
10. What is even parity?
11. What is odd parity?
12. Define checksum.
13. What is Hamming code?
14. What is a syndrome?
15. State the Hamming parity-bit formula.
16. What is ARQ?
17. Define flow control.
18. Define error control.
19. What is Stop-and-Wait?
20. What is sliding window?
21. Define Go-Back-N ARQ.
22. Define Selective Repeat ARQ.
23. What is HDLC?
24. What is bit stuffing?
25. What is the HDLC flag pattern?
26. List HDLC frame types.
27. What is PPP?
28. What is LCP?
29. What is NCP?
30. What is PAP?
31. What is CHAP?
32. Define multiple access.
33. What is random access?
34. What is CSMA?
35. What is CSMA/CD?
36. What is CSMA/CA?
37. Define polling.
38. What is token passing?
39. Define channelization.
40. What is FDMA?
41. What is TDMA?
42. What is CDMA?

---

# 114. POTENTIAL 3–5 MARK QUESTIONS

1. Explain the functions of the Data Link Layer.
2. Explain the structure of a frame.
3. Explain single-bit and burst errors.
4. Explain parity checking.
5. Solve an even-parity numerical.
6. Solve an odd-parity numerical.
7. Explain checksum with a numerical example.
8. Explain Hamming code.
9. Explain how parity bits are positioned in Hamming(7,4).
10. Solve a Hamming(7,4) encoding problem.
11. Explain syndrome-based error correction.
12. Explain flow control and error control.
13. Explain Stop-and-Wait ARQ.
14. Explain Stop-and-Wait frame loss, ACK loss and delayed ACK.
15. Explain sliding window.
16. Explain Go-Back-N ARQ.
17. Explain Selective Repeat ARQ.
18. Compare GBN and Selective Repeat.
19. Explain HDLC configurations and transfer modes.
20. Explain HDLC frame format.
21. Explain HDLC I, S and U frames.
22. Explain bit stuffing.
23. Explain PPP and its services.
24. Explain PPP stack.
25. Explain PPP connection phases.
26. Explain random access methods.
27. Explain Pure and Slotted ALOHA.
28. Explain CSMA and persistence methods.
29. Explain CSMA/CD.
30. Explain CSMA/CA.
31. Explain controlled access.
32. Explain reservation, polling and token passing.
33. Explain channelization.
34. Explain FDMA, TDMA and CDMA.

---

# 115. POTENTIAL 7–10 MARK QUESTIONS

1. Explain the Data Link Layer and its major functions with a suitable diagram.
2. Explain transmission errors and error-detection/error-correction techniques.
3. Explain parity, checksum and Hamming code with suitable examples.
4. Explain Hamming(7,4) encoding and correction of a single-bit error with a numerical.
5. Explain flow control and error control in the Data Link Layer.
6. Explain Stop-and-Wait ARQ with frame-loss, ACK-loss and delayed-ACK cases.
7. Explain sliding-window protocols and compare Go-Back-N with Selective Repeat.
8. Explain Go-Back-N ARQ with a worked example.
9. Explain Selective Repeat ARQ with a worked example.
10. Explain HDLC architecture, configurations, transfer modes and frame types.
11. Explain HDLC frame format and bit stuffing.
12. Explain PPP, PPP frame format, PPP stack and connection phases.
13. Explain multiple-access protocols and their classification.
14. Explain Pure ALOHA and Slotted ALOHA and compare their efficiencies.
15. Explain CSMA, CSMA/CD and CSMA/CA.
16. Explain controlled-access methods: reservation, polling and token passing.
17. Explain channelization and compare FDMA, TDMA and CDMA.
18. Compare random access, controlled access and channelization.

---

# 116. POTENTIAL COMPARISON QUESTIONS

1. Single-bit error vs burst error.
2. Error detection vs error correction.
3. Parity vs checksum.
4. Checksum vs Hamming code.
5. Flow control vs error control.
6. Stop-and-Wait vs Sliding Window.
7. Stop-and-Wait vs GBN.
8. GBN vs Selective Repeat.
9. HDLC vs PPP.
10. NRM vs ABM.
11. I-frame vs S-frame vs U-frame.
12. Pure ALOHA vs Slotted ALOHA.
13. CSMA/CD vs CSMA/CA.
14. Random access vs controlled access.
15. FDMA vs TDMA vs CDMA.

---

# 117. POTENTIAL DIAGRAM QUESTIONS

1. Draw Data Link Layer functions.
2. Draw a Data Link frame.
3. Draw single-bit error.
4. Draw burst error.
5. Draw parity structure.
6. Draw Hamming(7,4) position layout.
7. Draw Hamming syndrome correction.
8. Draw Stop-and-Wait sequence diagram.
9. Draw frame-loss/ACK-loss cases.
10. Draw sliding-window operation.
11. Draw GBN retransmission.
12. Draw Selective Repeat buffering.
13. Draw HDLC frame.
14. Draw PPP frame.
15. Draw PPP connection phases.
16. Draw polling.
17. Draw token passing.
18. Draw FDMA.
19. Draw TDMA.
20. Draw CDMA.

---

# 118. SOLVED QUICK PRACTICE

## Q1. Find parity bit for even parity

Data:

```text
110101
```

Number of 1s = 4.

Already even.

Therefore:

```text
P = 0
```

Transmitted:

```text
1101010
```

---

## Q2. Find parity bit for odd parity

Data:

```text
110101
```

Number of 1s = 4.

Need odd total.

Therefore:

```text
P = 1
```

Transmitted:

```text
1101011
```

---

## Q3. Hamming parity count

Data bits:

\[
m=8
\]

Find \(r\).

Try \(r=4\):

\[
2^4=16
\]

\[
m+r+1=8+4+1=13
\]

Since:

\[
16\ge13
\]

four parity bits are sufficient.

Total bits:

\[
8+4=12
\]

---

## Q4. Hamming(7,4) error position

Suppose parity check results are:

```text
S4 = 1
S2 = 0
S1 = 1
```

Then:

```text
S4 S2 S1 = 101
```

\[
101_2=5
\]

Therefore:

**Error position = 5**

---

# 119. LAST-MINUTE 60-SECOND REVISION

```text
DATA LINK LAYER
       |
       +-- Framing
       +-- Error control
       +-- Flow control
       +-- Access control
       +-- Physical addressing

ERRORS
       |
       +-- Single-bit
       +-- Burst

DETECTION
       |
       +-- Parity
       +-- Checksum

CORRECTION
       |
       +-- Hamming

ARQ
       |
       +-- Stop-and-Wait
       +-- Go-Back-N
       +-- Selective Repeat

HDLC
       |
       +-- I frame
       +-- S frame
       +-- U frame
       +-- 01111110
       +-- Bit stuffing
       +-- NRM / ABM

PPP
       |
       +-- LCP
       +-- PAP / CHAP
       +-- NCP
       +-- Dead → Establish → Authenticate
           → Network → Open → Terminate

MULTIPLE ACCESS
       |
       +-- Random
       |    +-- ALOHA
       |    +-- CSMA
       |    +-- CSMA/CD
       |    +-- CSMA/CA
       |
       +-- Controlled
       |    +-- Reservation
       |    +-- Polling
       |    +-- Token
       |
       +-- Channelization
            +-- FDMA
            +-- TDMA
            +-- CDMA
```

---

# 120. FINAL MEMORY HOOKS

### Errors
**Single = one changed bit.**

**Burst = multiple affected positions across a span.**

### Detection
**Parity = count 1s.**

**Checksum = add + wrap + complement.**

### Correction
**Hamming = parity positions + syndrome + flip.**

### Flow
**Stop-and-Wait = one at a time.**

**Sliding Window = several at a time.**

### ARQ
**GBN = go back and resend from the error onward.**

**SR = resend only the missing/damaged frame.**

### HDLC
**I = Information**

**S = Supervisory**

**U = Unnumbered**

**Flag = 01111110**

### PPP
**LCP = link**

**PAP/CHAP = authentication**

**NCP = network configuration**

### Multiple Access
**Random = compete**

**Controlled = take turns**

**Channelization = divide the resource**

### Channelization
**FDMA = Frequency**

**TDMA = Time**

**CDMA = Code**

### ALOHA
**Pure = ~18.4%**

**Slotted = ~36.8%**

---

# 121. PDF VISUAL-PAGE COVERAGE MAP

The visual content of the uploaded PDF was explicitly incorporated rather than relying only on its extracted text.

| PDF pages | Visual content incorporated |
|---|---|
| 1–3 | Module title, contents and unit roadmap |
| 4–6 | Data Link Layer role, functions and frame structure |
| 7–10 | Single-bit/burst errors and detection vs correction |
| 11–14 | Parity concept, even/odd parity numerical examples and error detection |
| 15–17 | Checksum procedure, 4-bit worked example and receiver verification |
| 18–20 | Hamming concept, parity-bit formula and Hamming(7,4) layout |
| 21–24 | Complete Hamming(7,4) encoding example |
| 25–27 | Hamming single-bit error, syndrome calculation and correction |
| 28–30 | Flow control, Stop-and-Wait normal operation and loss/ACK cases |
| 31–36 | Sliding Window, GBN, Selective Repeat and comparison table |
| 37–38 | HDLC configurations, transfer modes, frame format and frame types |
| 39–40 | PPP services, limitations, frame, LCP/PAP/CHAP/NCP and connection phases |
| 41–44 | Multiple-access classification, ALOHA, CSMA, CSMA/CD/CA and controlled access |
| 45–49 | Channelization, FDMA, TDMA, CDMA and comparison |
| 50 | Random vs controlled vs channelization comparison |
| 51–53 | Unit overview, quick revision and key takeaway |

---

# 122. FINAL HIGH-PRIORITY EXAM CHECKLIST

Before the exam, make sure you can write/draw these without opening the PDF:

### MUST KNOW DEFINITIONS
- Data Link Layer
- Framing
- Transmission error
- Error detection
- Error correction
- Parity
- Checksum
- Hamming code
- ARQ
- Flow control
- Stop-and-Wait
- Sliding Window
- Go-Back-N
- Selective Repeat
- HDLC
- PPP
- Multiple access
- Random access
- Controlled access
- Channelization
- FDMA
- TDMA
- CDMA

### MUST KNOW NUMERICALS
- Even parity
- Odd parity
- Checksum
- Hamming parity-bit count
- Hamming(7,4)
- Hamming syndrome/error position
- Pure ALOHA efficiency
- Slotted ALOHA efficiency

### MUST DRAW
- Frame
- Hamming(7,4)
- Stop-and-Wait
- GBN
- Selective Repeat
- HDLC frame
- PPP frame
- PPP phases
- Polling
- Token passing
- FDMA
- TDMA
- CDMA

### MUST COMPARE
- Detection vs correction
- Parity vs checksum vs Hamming
- Flow vs error control
- Stop-and-Wait vs GBN vs SR
- HDLC vs PPP
- Pure vs Slotted ALOHA
- CSMA/CD vs CSMA/CA
- Random vs Controlled vs Channelization
- FDMA vs TDMA vs CDMA

---

# 123. FINAL UNIT TAKEAWAY

The entire unit can be remembered as four questions:

### 1. **What went wrong?**
Transmission errors:
- Single-bit
- Burst

### 2. **How do we detect/fix it?**
- Parity
- Checksum
- Hamming
- ARQ

### 3. **How do we control the data link?**
- Flow control
- Error control
- Stop-and-Wait
- Sliding Window
- GBN
- Selective Repeat
- HDLC
- PPP

### 4. **How do many devices share one link?**
- Random access
- Controlled access
- Channelization

**Final memory line:**

> **Detect the error → control the flow → recover the frame → share the link fairly.**
