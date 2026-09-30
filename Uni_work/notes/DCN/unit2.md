# DATA COMMUNICATION & NETWORKING — UNIT II
## Error Detection & Correction · Data Link Control & Protocols · PPP · Multiple Access

---

## CONTENTS

1. Types of Errors
2. Error Detection (Redundancy, Parity, Checksum, CRC)
3. Error Correction (Hamming Code, Hamming Distance)
4. Flow Control and Error Control (Data Link Control)
5. Stop-and-Wait ARQ
6. Go-Back-N ARQ
7. Selective Repeat ARQ
8. HDLC
9. Point-to-Point Protocol (PPP Stack)
10. Multiple Access — Overview
11. Random Access (ALOHA, CSMA, CSMA/CD, CSMA/CA)
12. Controlled Access (Reservation, Polling, Token Passing)
13. Channelization (FDMA, TDMA, CDMA)
14. Master Comparison Tables
15. Formula Sheet
16. Memory Aids
17. Consolidated Potential Exam Questions

> **Position in the layer stack:** Everything in this unit belongs to the **Data Link Layer (Layer 2 of OSI)**. The data link layer has two sublayers:
> - **LLC (Logical Link Control)** — flow control, error control, framing interface to the network layer (Data Link *Control*, DLC).
> - **MAC (Media Access Control)** — decides *who may transmit and when* on a shared medium (Multiple Access).
>
> Unit II = **DLC** (error detection/correction, ARQ, HDLC, PPP) + **MAC** (random, controlled, channelization).

```text
+--------------------------------------------------+
|              DATA LINK LAYER                      |
|  +--------------------------------------------+  |
|  | LLC : Flow control, Error control, Framing |  |  <- Data Link Control (DLC)
|  +--------------------------------------------+  |
|  | MAC : Multiple access (who transmits when) |  |  <- Media Access Control
|  +--------------------------------------------+  |
+--------------------------------------------------+
|              PHYSICAL LAYER                       |
+--------------------------------------------------+
```

---

# 1. TYPES OF ERRORS

## 1.1 Standard Examination Definition
An **error** in data communication is any unintended change in the bit pattern of transmitted data such that the data received at the destination differs from the data transmitted by the source, caused by **noise, attenuation, distortion, or interference** in the transmission medium.

**In Simple Words:** You sent `10110`, but the receiver got `10010`. Some bits got flipped on the way. That is an error.

## 1.2 Why Errors Occur (Causes)
| Cause | Explanation |
|---|---|
| **Thermal (white) noise** | Random motion of electrons in conductors; constant background noise |
| **Impulse noise** | Sudden, short-duration high-energy spike (lightning, power-line switching, relay contacts); the main cause of **burst errors** |
| **Crosstalk** | Signal from one wire/channel induced onto an adjacent one |
| **Attenuation** | Loss of signal strength with distance |
| **Distortion** | Different frequency components travel at different speeds, so the signal shape changes |
| **Intermodulation / Echo / Jitter** | Additional impairments that shift or corrupt signal levels |

## 1.3 Classification of Errors

```text
                    ERRORS
                      |
          +-----------+-----------+
          |                       |
   Single-bit error         Burst error
```

### (A) Single-Bit Error
**Definition:** An error in which **only one bit** of a given data unit (byte, character, packet, frame) is altered from 1 to 0 or from 0 to 1.

```text
Sent     :  0 0 0 0 0 0 1 0
Received :  0 0 0 0 1 0 1 0     <- only one bit changed
                    ^
```
- Least likely in **serial** transmission because the noise duration is usually longer than one bit duration.
- More likely in **parallel** transmission (one wire is affected out of eight).
- Example: 1 bit corrupted in a 1 Mbps link with 1 µs bit duration needs a noise of only 1 µs, which is rare.

### (B) Burst Error
**Definition:** A burst error means that **two or more bits** in the data unit have changed. The **length of the burst** is measured from the **first corrupted bit to the last corrupted bit**; the bits in between need not all be corrupted.

```text
Sent     :  0 1 0 0 0 1 0 0 0 1 1 0 0 1 0 1
Received :  0 1 0 1 1 0 0 0 0 1 1 0 1 1 0 1
                  ^ ^ ^                ^
                  |___|___ burst spans first to last changed bit
Burst length = from bit 4 to bit 6 = 3 bits   (first burst)
```
- Most common in serial transmission because noise lasts for several bit durations.
- **Number of bits affected = Noise duration × Data rate.**

**Numerical example:** Noise lasts 0.01 s; data rate 1 kbps → 1000 × 0.01 = **10 bits** may be affected. If the data rate is 1 Mbps → 1,000,000 × 0.01 = **10,000 bits** affected.

## 1.4 Comparison: Single-Bit vs Burst Error

| Parameter | Single-Bit Error | Burst Error |
|---|---|---|
| Bits affected | Exactly one | Two or more (span from first to last error) |
| Typical cause | Isolated thermal noise | Impulse noise, fading, scratches |
| Occurs mostly in | Parallel transmission | Serial transmission |
| Likelihood at high data rates | Lower | Higher (longer noise covers more bits) |
| Detection difficulty | Easier | Harder |
| Example | 1 bit of a byte flipped | Lightning corrupts 12 consecutive bits |

## 1.5 Bit Error Rate (BER)
**Definition:** BER is the **ratio of the number of erroneous bits to the total number of bits transmitted** over a given interval.
`BER = (Number of bits in error) / (Total number of bits transmitted)`
Example: 5 errors in 1,000,000 bits → BER = 5 × 10⁻⁶.

## 1.6 Redundancy — The Central Idea of Error Handling
Errors cannot be detected or corrected unless **extra bits (redundant bits)** are added by the sender using a known rule and checked by the receiver. These bits carry no new information; they exist only to detect/correct errors and are discarded after checking.

```text
Sender                                         Receiver
+--------+   +---------+  data + redundancy   +---------+   +--------+
| Data   |-->| Generator|-------------------->| Checker |-->| Data   |
+--------+   +---------+   (channel: noise)   +---------+   +--------+
                                                  |
                                     Accept / Discard (detect)
                                     or Correct   (correction)
```

## 1.7 Two Approaches to Handle Errors
| Approach | Idea |
|---|---|
| **Error detection** | Receiver only *finds out* whether an error occurred; recovery by **retransmission** (ARQ) |
| **Error correction** | Receiver *locates and repairs* the erroneous bits itself (**FEC**, Forward Error Correction) |

## Exam Points to Remember (Types of Errors)
1. Two types: **single-bit** and **burst**.
2. Burst length is measured **first corrupted bit → last corrupted bit**, not the count of flipped bits.
3. Burst errors are more likely in **serial** transmission; the higher the data rate, the more bits a given noise burst corrupts.
4. Bits affected = **noise duration × data rate**.
5. All error control relies on **redundancy**.
6. Impulse noise is the main cause of burst errors.

## Potential Exam Questions
- **Very short:** Define error. What is a burst error? Define BER.
- **Short:** Differentiate single-bit and burst errors with diagrams. State the causes of errors.
- **Long:** Explain the types of errors, their causes and the role of redundancy in handling them.
- **Diagram:** Draw and label a single-bit and a burst error showing the burst length.

---

# 2. ERROR DETECTION

## 2.1 Standard Examination Definition
**Error detection** is the process by which a receiver, using **redundant bits** appended by the sender according to a predefined algorithm, determines whether the received data unit has been **corrupted** during transmission, without necessarily identifying the location of the corrupted bits.

**In Simple Words:** The sender attaches a small "proof" (extra bits). The receiver recomputes the proof; if it doesn't match, the data is damaged and is discarded/retransmitted.

## 2.2 Block Coding (Foundation)
In **block coding**, the message is divided into blocks of **k bits (datawords)**. Each dataword is converted into an **n-bit codeword** (n > k) by adding **r = n − k redundant bits**.

- Number of possible datawords = 2ᵏ; number of possible codewords = 2ⁿ.
- Only **2ᵏ** of the 2ⁿ patterns are **valid codewords**; the remaining (2ⁿ − 2ᵏ) are **invalid** (illegal). If the receiver gets an invalid codeword → **error detected**.
- **Code rate** = k / n.

```text
Dataword (k bits) --> [ Encoder ] --> Codeword (n bits) --> Channel --> [ Decoder ]
                                                                        |-> valid: extract dataword
                                                                        |-> invalid: discard (error)
```

### Hamming Distance
**Definition:** The **Hamming distance** between two words of equal length is the **number of bit positions in which they differ** (= number of 1s in their XOR).
Example: `10101` and `11110` → XOR = `01011` → distance = **3**.

**Minimum Hamming distance d_min** of a code = smallest Hamming distance between any pair of valid codewords.

| Requirement | Condition |
|---|---|
| Detect **up to s** errors | d_min ≥ **s + 1** |
| Correct **up to t** errors | d_min ≥ **2t + 1** |

Example: For a simple even-parity code, d_min = 2 → detects 1 error, corrects none.

## 2.3 Detection Techniques — Classification

```text
             ERROR DETECTION METHODS
                       |
   +---------+---------+---------+-----------+
   |         |         |         |           |
 Parity   2-D Parity  Checksum   CRC     (Block codes)
(VRC)      (LRC+VRC)
```

---

## 2.4 SIMPLE PARITY CHECK (VRC — Vertical Redundancy Check)

**Definition:** In a simple parity check, **one extra bit (parity bit)** is appended to a block of data bits so that the total number of 1s in the resulting codeword is **even (even parity)** or **odd (odd parity)**.

**Working (even parity):**
1. Sender counts the 1s in the data bits.
2. If the count is odd, parity bit = 1; if even, parity bit = 0 (so total 1s = even).
3. The (k+1)-bit codeword is transmitted.
4. Receiver counts the 1s. If even → **accepted**; if odd → **rejected** (error).

**Example:** Data = `1011001` (four 1s) → parity = 0 → sent: `10110010`.
Data = `1011011` (five 1s) → parity = 1 → sent: `10110111`.

```text
Sender:   data bits (k)  ---> [Parity Generator: XOR of all bits] ---> data + P ---> channel
Receiver: data + P ---> [Parity Checker] ---> even? accept : reject
```

**Capability**
- Detects **all single-bit errors**, and **any odd number** of bit errors (1, 3, 5…).
- **Fails** for an **even number** of errors (2, 4…) — errors cancel out in parity.
- d_min = 2.
- Cannot **locate** or **correct** the error.

**Example of failure:** Sent `10110010`; received `10011010` (two bits changed) → still four 1s → accepted wrongly.

**Advantages:** Very simple, low overhead (1 bit), hardware-friendly (XOR gates).
**Disadvantages:** Cannot detect even-number errors; poor against burst errors; no correction.
**Applications:** ASCII character transmission (7 data + 1 parity), serial links (RS-232), memory (RAM parity bits).

---

## 2.5 TWO-DIMENSIONAL PARITY CHECK (LRC + VRC)

**Definition:** In a two-dimensional parity check, the data is arranged as a **table of rows and columns**; a **parity bit is calculated for every row and every column**, and the **row of column-parities** is appended to the block.

**Working:**
1. Arrange data in rows (each row = one data unit).
2. Compute **row parity** for each row.
3. Compute **column parity** for each column (including the row-parity column).
4. Send all data rows followed by the **parity row**.
5. Receiver recomputes all row and column parities; any mismatch → error.

**Example (even parity):**

```text
Data rows            Row parity
1 1 0 0 1 1 0   |   0
1 0 1 1 1 0 0   |   0
0 1 1 1 0 0 1   |   0
1 0 0 0 1 1 1   |   0
------------------------
1 0 0 0 1 0 0   |   0      <- column parity row (sent with data)
```
Each row has four 1s (even), so every row parity = 0. Column parities are computed the same way (e.g., column 1 has 1,1,0,1 = three 1s, so parity = 1). In the exam, use any small table (3-4 rows x 7 bits) and show the complete parity row.

**Capability:**
- Detects all 1-, 2- and 3-bit errors and most 4-bit errors.
- A **single-bit error can be located** (the intersection of the failing row and failing column) → can even be **corrected**.
- **Fails** when 4 errors lie at the corners of a rectangle (each affected row and column gets an even number of errors).

**Advantages:** Better burst detection than simple parity; can correct single-bit errors.
**Disadvantages:** Higher overhead; still misses rectangular error patterns.
**Applications:** Magnetic tape (LRC + VRC), block-oriented data storage.

### Comparison: Simple vs 2-D Parity
| Parameter | Simple Parity | 2-D Parity |
|---|---|---|
| Redundancy | 1 bit per block | 1 per row + 1 row |
| Detects | Odd number of errors | 1, 2, 3 bit errors and most 4-bit |
| Correction | No | Single-bit correction possible |
| Burst detection | Poor | Better |
| Complexity | Very low | Low–moderate |

---

## 2.6 CHECKSUM

**Standard Examination Definition:** A **checksum** is an error-detection technique in which the data is divided into **equal-sized segments (k bits)**, the segments are added using **one's complement arithmetic**, and the **complement of the sum** is sent along with the data. The receiver adds all segments including the checksum; if the final complement is **zero**, the data is accepted.

**In Simple Words:** Add up all the chunks, flip the answer, send it along. The receiver adds everything again — if all bits come out as 0 after flipping, no error.

### One's Complement Arithmetic (must-know)
- **Addition:** If a carry appears beyond k bits, it is **wrapped around** and added to the least-significant bits.
- **Complement:** Flip every bit (or subtract from 2ᵏ − 1).

### Working
**Sender:**
1. Divide data into k-bit segments (16-bit in Internet).
2. Add all segments using one's complement addition (wrap the carry).
3. Take the **one's complement of the sum** → this is the **checksum**.
4. Send data segments + checksum.

**Receiver:**
1. Add all received segments **including the checksum** (wrap carries).
2. Complement the result.
3. If result = **0** → accept; otherwise → discard.

```text
Sender:  seg1 + seg2 + ... + segN --> SUM --(complement)--> CHECKSUM --> [data + checksum]
Receiver:[data + checksum] --> add all --> SUM' --(complement)--> 0 ? Accept : Reject
```

### Solved Example (4-bit segments)
Data segments: 7, 11, 12, 0, 6 (max value 15, k = 4).
1. Sum = 7 + 11 + 12 + 0 + 6 = **36** = `100100`.
2. Wrap carry: leftmost 2 bits `10` (=2) added to rightmost 4 bits `0100` (=4) → 4 + 2 = **6** (`0110`).
3. Checksum = complement of `0110` = `1001` = **9** (15 − 6).
4. Sent: 7, 11, 12, 0, 6, **9**.

**Receiver check:** 7 + 11 + 12 + 0 + 6 + 9 = 45 = `101101` → wrap: `10` + `1101` = 2 + 13 = 15 = `1111` → complement = `0000` → **accept**.

### Solved Example (binary, 8-bit segments)
Segments: `10101001` and `00111001`.
- Sum: `10101001 + 00111001 = 11100010`. (no carry out)
- Checksum = complement = `00011101`.
- Receiver: `10101001 + 00111001 + 00011101 = 11111111` → complement = `00000000` → accept.

**Advantages:** Simple, fast in software, low overhead.
**Disadvantages:** Weaker than CRC — cannot detect errors that leave the sum unchanged (e.g., two segments swapped, or a +1 and −1 errors in the same bit positions).
**Applications:** **IPv4 header checksum, TCP, UDP, ICMP** (16-bit one's complement checksum).

**Common mistakes:** Forgetting to wrap the carry; forgetting to complement; using ordinary (two's complement) addition.

---

## 2.7 CYCLIC REDUNDANCY CHECK (CRC)

**Standard Examination Definition:** **CRC** is a powerful error-detection technique based on **binary (modulo-2) polynomial division**, in which the sender appends a **frame check sequence (FCS)** — the remainder obtained by dividing the data (appended with zeros) by a predetermined **generator (divisor) polynomial** — such that the transmitted codeword is **exactly divisible** by the generator; the receiver performs the same division and accepts the frame only if the remainder is zero.

**In Simple Words:** Treat the data as one huge binary number, divide it by an agreed number using XOR-style division, and attach the remainder. The receiver divides again — a non-zero remainder means corruption.

### Key Terms
- **Dataword** (k bits), **Divisor / Generator** (n − k + 1 bits), **Codeword** (n bits), **CRC / FCS / remainder** (n − k bits).
- Modulo-2 arithmetic: addition = subtraction = **XOR** (no carries/borrows).
- Polynomial form: bit string `1101` = **x³ + x² + 1**.

### Working (Step-by-step)
**Sender:**
1. Choose generator G with **r + 1 bits** (degree r).
2. Append **r zeros** to the dataword.
3. Divide (modulo-2) the augmented dataword by G.
4. The **remainder (r bits)** is the CRC.
5. Replace the appended zeros with the CRC → codeword sent.

**Receiver:**
1. Divide the received codeword by G.
2. Remainder **= 0** → accept; **≠ 0** → discard (error).

```text
DATA (k bits) + r zeros
        |
        v
  +-------------+
  | Modulo-2    |<---- Generator (r+1 bits)
  | Division    |
  +-------------+
        |
   Remainder (r bits) = CRC
        |
        v
  Codeword = DATA + CRC  ----> channel ----> Receiver divides by G
                                             remainder 0 ? accept : discard
```

### Solved Example
**Data = 100100, Generator = 1101 (x³ + x² + 1), r = 3.**

1. Append 3 zeros → `100100000`.
2. Modulo-2 division:

```text
Step  Working bits   XOR with        Result       Bring next bit
 1    1001           1101            0100         -> 1000
 2    1000           1101            0101         -> 1010
 3    1010           1101            0111         -> 1110
 4    1110           1101            0011         -> 0110
 5    0110           0000 (leading 0) 0110        -> 1100
 6    1100           1101            0001         (no bits left)

Remainder = 001
```
3. **CRC = 001**.
4. **Transmitted codeword = 100100001**.
5. **Check at receiver:** dividing `100100001` by `1101` yields remainder **000** → accepted.

### Polynomial Representation & Properties of a Good Generator
| Error type | Detected if… |
|---|---|
| **Single-bit errors** | G has more than one term and the x⁰ term is 1 |
| **Two isolated single-bit errors** | G cannot divide xᵗ + 1 for t up to frame length |
| **Odd number of errors** | G contains the factor **(x + 1)** |
| **Burst error of length ≤ r** | Always detected (r = degree of G) |
| **Burst length = r + 1** | Missed with probability 1/2^(r−1) |
| **Burst length > r + 1** | Missed with probability 1/2^r |

### Standard CRC Polynomials
| Name | Bits | Use |
|---|---|---|
| CRC-8 | 8 | ATM header error control |
| CRC-16 / CRC-CCITT | 16 | HDLC, PPP (default FCS) |
| **CRC-32** | 32 | **Ethernet**, Wi-Fi, PPP (optional 32-bit FCS), ZIP |

**Advantages:** Very high burst-error detection; efficient hardware implementation using **shift registers and XOR gates**; low overhead.
**Disadvantages:** Detects but cannot correct; needs retransmission; more complex than parity/checksum; not cryptographically secure (only accidental errors).
**Applications:** Ethernet, Wi-Fi, HDLC, PPP, storage (hard disks, USB), ZIP/PNG files.

### Comparison: Parity vs Checksum vs CRC
| Parameter | Parity | Checksum | CRC |
|---|---|---|---|
| Redundancy | 1 bit/block | 16 bits typically | 8/16/32 bits |
| Arithmetic | XOR count | One's complement addition | Modulo-2 polynomial division |
| Burst detection | Poor | Moderate | **Excellent** |
| Complexity | Lowest | Low (software-friendly) | Moderate (hardware-friendly) |
| Layer of use | Data link/physical | Network/Transport | Data link |
| Example | ASCII + parity | IP, TCP, UDP | Ethernet, HDLC, PPP |

## 2.8 Do Not Confuse
- **Checksum ≠ CRC:** checksum uses *addition*; CRC uses *division*. Checksum is mostly at Network/Transport layers; CRC at the **Data Link** layer.
- **Error detection ≠ error correction:** detection only says "wrong"; correction says "which bit and fix it".
- **Parity bit position:** in parity/CRC/checksum the redundancy is appended at the **end**, but in **Hamming code** parity bits are at **power-of-2 positions**.

## Exam Points to Remember (Error Detection)
1. Detection needs **redundancy**; Hamming distance ≥ s + 1 detects s errors.
2. Simple parity: detects **odd** number of errors only; d_min = 2.
3. 2-D parity: locates and corrects **single-bit** errors; fails on rectangular 4-bit patterns.
4. Checksum: **one's complement**, wrap carry, complement of sum; receiver result **0** = accept. Used in IP/TCP/UDP.
5. CRC: **modulo-2 division**; append r zeros; remainder = CRC; receiver remainder 0 = accept.
6. CRC generator with (x+1) factor detects all odd errors; detects all bursts ≤ r.
7. CRC-32 → Ethernet; CRC-16 → HDLC/PPP.

## Potential Exam Questions
- **Very short:** Define parity bit, checksum, CRC, Hamming distance.
- **Short:** Explain simple parity with example; explain how 2-D parity detects errors; list properties of a good CRC generator.
- **Long:** Explain CRC with the generation and checking process; solve: data 1010001101, divisor 110101 (numerical).
- **Comparison:** Parity vs checksum vs CRC.
- **Diagram:** Block diagram of CRC encoder/decoder; 2-D parity table.

---

# 3. ERROR CORRECTION

## 3.1 Standard Examination Definition
**Error correction** is the process by which the receiver **identifies the exact position of corrupted bits** and **restores** the original data using additional **redundant bits** (error-correcting code) without requesting retransmission, an approach known as **Forward Error Correction (FEC)**.

**In Simple Words:** The extra bits are so cleverly arranged that they don't just say "something is wrong" — they point to *which bit* is wrong so the receiver flips it back.

## 3.2 Two Methods of Error Correction
| Method | Description | Used when |
|---|---|---|
| **Backward Error Correction (Retransmission / ARQ)** | Receiver detects error and asks sender to resend | Reliable, low-delay links (Ethernet, Wi-Fi, TCP) |
| **Forward Error Correction (FEC)** | Receiver corrects errors using redundancy | Long delay/one-way links (satellite, deep-space), real-time streaming, storage (CD/DVD, RAM ECC) |

## 3.3 Why Correction Needs More Redundancy
To **correct** one error the receiver must distinguish **which one of (m + r) positions** is wrong, or that **none** is wrong. This gives the condition:

**2ʳ ≥ m + r + 1**
- m = number of data bits
- r = number of redundant (parity) bits

| m (data) | Minimum r | Codeword n = m + r |
|---|---|---|
| 1 | 2 | 3 |
| 2–4 | 3 | 5–7 |
| 5–11 | 4 | 9–15 |
| 12–26 | 5 | 17–31 |
| 4 (classic) | 3 | **7 → (7,4) Hamming** |
| 7 (ASCII) | 4 | 11 |

## 3.4 HAMMING CODE

**Standard Examination Definition:** **Hamming code** is a **linear block error-correcting code** (designed by R. W. Hamming) in which **r parity bits are inserted at positions that are powers of 2** (1, 2, 4, 8…) of the codeword, each parity bit computing parity over a **specific subset of bit positions**, enabling the receiver to detect and correct any **single-bit error** (and detect double-bit errors with the extended version). Its minimum Hamming distance is **3**.

**In Simple Words:** Extra check bits watch overlapping groups of data bits. When one bit flips, exactly the check bits watching that bit fail, and together their pattern spells out the position of the faulty bit in binary.

### Which parity bit covers which positions
A parity bit at position 2ⁱ checks **all positions whose binary representation has a 1 in the 2ⁱ place**.

| Parity bit | Position | Covers positions (for 7-bit code) |
|---|---|---|
| **P1** | 1 (001) | 1, 3, 5, 7 |
| **P2** | 2 (010) | 2, 3, 6, 7 |
| **P4** | 4 (100) | 4, 5, 6, 7 |

```text
Position :   7    6    5    4    3    2    1
Bit      :   d4   d3   d2   P4   d1   P2   P1
              |    |    |    |    |    |    |
P1 covers:    x    .    x    .    x    .    x    (1,3,5,7)
P2 covers:    x    x    .    .    x    x    .    (2,3,6,7)
P4 covers:    x    x    x    x    .    .    .    (4,5,6,7)
```

### Working — Encoding (even parity)
1. Number bit positions from **1** (from the right/left as per convention; the left-to-right numbering is also accepted — state it clearly).
2. Place parity bits at positions **1, 2, 4, 8…**; put data bits in remaining positions.
3. Compute each parity bit so that its group has **even** number of 1s.
4. Transmit the codeword.

### Working — Decoding & Correction
1. Recompute parity for each group (including the received parity bit) → gives check bits **C1, C2, C4…** (0 = OK, 1 = fail).
2. Form the **syndrome** = C4 C2 C1 (as binary number).
3. **Syndrome = 0** → no error. **Syndrome ≠ 0** → its decimal value is the **position of the erroneous bit**.
4. **Invert** that bit to correct.

### Solved Example
**Data = 1011 (d1 = 1, d2 = 0, d3 = 1, d4 = 1)** — Positions: d1 → 3, d2 → 5, d3 → 6, d4 → 7.

**Encoding:**
- P1 (1,3,5,7): bits at 3,5,7 = 1,0,1 → two 1s → **P1 = 0**
- P2 (2,3,6,7): bits at 3,6,7 = 1,1,1 → three 1s → **P2 = 1**
- P4 (4,5,6,7): bits at 5,6,7 = 0,1,1 → two 1s → **P4 = 0**

```text
Position :  7  6  5  4  3  2  1
Codeword :  1  1  0  0  1  1  0     (d4 d3 d2 P4 d1 P2 P1)  -> transmitted 1100110
```

**Error introduced:** bit at position 6 flipped (1 → 0). **Received** = `1 0 0 0 1 1 0` (positions 7→1).

**Decoding:**
- C1 (1,3,5,7): bits 0,1,0,1 → two 1s (even) → **C1 = 0**
- C2 (2,3,6,7): bits 1,1,0,1 → three 1s (odd) → **C2 = 1**
- C4 (4,5,6,7): bits 0,0,0,1 → one 1 (odd) → **C4 = 1**
- Syndrome = C4 C2 C1 = **110₂ = 6** → error at **position 6** → flip it → original `1100110` restored → data = `1011`.

### Extended Hamming Code (SEC-DED)
Adds **one overall parity bit** → can **correct 1-bit** and **detect 2-bit** errors (used in ECC memory). d_min = 4.

**Advantages:** Corrects single-bit errors without retransmission; simple hardware.
**Disadvantages:** Cannot correct burst or multi-bit errors; overhead grows (r ≈ log₂ n); poor for noisy channels.
**Applications:** ECC RAM, satellite/deep-space links, CD/DVD storage systems (with other codes), memory controllers.

## 3.5 Correction of Burst Errors (Concept)
Hamming corrects only single-bit errors. To correct **burst errors**, **interleaving** is used: several codewords are arranged in rows and **transmitted column-wise**, so a burst affects only **one bit per codeword**, which Hamming can then correct.

```text
Codeword1:  a1 a2 a3 a4 a5 a6 a7
Codeword2:  b1 b2 b3 b4 b5 b6 b7      Transmit column by column:
Codeword3:  c1 c2 c3 c4 c5 c6 c7      a1 b1 c1 | a2 b2 c2 | ...
A burst hitting 3 consecutive transmitted bits -> only 1 bit per codeword damaged.
```
Other codes: **Convolutional codes, Reed–Solomon (CD/DVD/QR), Turbo, LDPC (5G/Wi-Fi)**.

## 3.6 Comparison: Error Detection vs Error Correction
| Parameter | Error Detection | Error Correction |
|---|---|---|
| Purpose | Only finds that an error exists | Finds location and repairs it |
| Redundancy | Fewer bits | More bits |
| Requirement | d_min ≥ s + 1 | d_min ≥ 2t + 1 |
| Recovery | Retransmission (ARQ) | Forward correction (no resend) |
| Complexity | Lower | Higher |
| Examples | Parity, checksum, CRC | Hamming, Reed–Solomon, convolutional |
| Best suited for | Low-error, low-delay links | High delay/noisy/broadcast/storage |

## Do Not Confuse
- **Hamming distance** (between two words) ≠ **Hamming code** (a specific error-correcting code).
- **FEC** (no retransmission) ≠ **ARQ** (retransmission, backward correction).

## Exam Points to Remember (Error Correction)
1. Single-error correction needs **2ʳ ≥ m + r + 1**.
2. Hamming parity bits sit at positions **1, 2, 4, 8…**
3. **Syndrome** value = position of error; 0 = no error.
4. Hamming code: d_min = 3 → **corrects 1, detects 2** errors (SEC); extended: detects 2 while correcting 1.
5. Two methods: **FEC** and **retransmission**.
6. Burst correction uses **interleaving**.
7. Correct t errors → d_min = 2t + 1.

## Potential Exam Questions
- **Very short:** Define Hamming code; state the redundant-bit formula; define FEC.
- **Short:** Explain how error position is found in Hamming code; explain interleaving.
- **Long:** Encode data `1101` with Hamming (7,4) even parity and correct an error at bit 5. Explain generating and correcting process with a diagram.
- **Comparison:** Error detection vs correction.
- **Diagram:** Parity coverage table for the (7,4) Hamming code.

---

# 4. DATA LINK CONTROL — FLOW CONTROL AND ERROR CONTROL

## 4.1 Standard Examination Definitions

**Data Link Control (DLC):** The set of functions of the **data link layer** that manage **framing, flow control and error control** for reliable node-to-node delivery of frames over a link.

**Flow Control:** A set of procedures that **restricts the amount of data a sender may transmit before waiting for acknowledgement**, ensuring that the sender does not overwhelm the receiver's buffer capacity or processing speed.

**Error Control:** A set of mechanisms for **detecting corrupted, lost, duplicated or out-of-order frames** and **retransmitting** them (automatic repeat request), thereby achieving reliable delivery.

**In Simple Words:** Flow control = "Slow down, I can't process that fast." Error control = "That frame is damaged or missing, send it again."

## 4.2 Why It Is Needed
- Receiver has **limited buffer** and processing speed; a fast sender can cause **overflow** and loss.
- Links are noisy → frames are corrupted or lost.
- Ensures **ordered, error-free, non-duplicated** delivery to the network layer.

## 4.3 Flow Control — Mechanisms
- **Stop-and-Wait:** sender sends one frame, waits for ACK.
- **Sliding Window:** sender may send **multiple frames (window)** before ACK; window "slides" as ACKs arrive.

### Sliding Window Concept
- Frames are numbered with **m-bit sequence numbers** (0 to 2ᵐ − 1, modulo 2ᵐ).
- **Sender window:** the set of sequence numbers of frames that may be **outstanding** (sent but unacknowledged) + those that can be sent.
- **Receiver window:** the set of sequence numbers of frames the receiver will **accept**.
- Window slides forward when the ACK arrives (sender) or a correct frame is delivered (receiver).

```text
Sender window (size 4, m = 3, numbers 0-7):

 0   1   2   3   4   5   6   7   0   1 ...
[---------------]
 Sf            Sn
 Sf = first outstanding frame, Sn = next frame to send
 ACK received for 0,1 --> window slides right by 2:
         [---------------]
```

## 4.4 Error Control — Building Blocks
1. **Error detection** (CRC in the frame trailer).
2. **Positive acknowledgement (ACK)** for good frames.
3. **Negative acknowledgement (NAK)** for damaged frames (in some protocols).
4. **Retransmission timer** (time-out) — if no ACK arrives in time, resend.
5. **Sequence numbers** — to identify duplicates/missing/out-of-order frames.
6. **Retransmission** of lost/damaged frames = **ARQ (Automatic Repeat reQuest)**.

**ARQ protocols:** Stop-and-Wait ARQ, Go-Back-N ARQ, Selective Repeat ARQ.

```text
        DATA LINK CONTROL
              |
   +----------+-----------+
   |                      |
Flow control          Error control
   |                      |
Stop-and-wait          ARQ:
Sliding window     Stop-and-Wait ARQ
                   Go-Back-N ARQ
                   Selective Repeat ARQ
```

## 4.5 Important Terms
| Term | Meaning |
|---|---|
| **Piggybacking** | Sending an ACK inside the header of a data frame going in the reverse direction (saves bandwidth) |
| **Cumulative ACK** | ACK n means all frames up to n − 1 are received |
| **Time-out** | Timer expiry that triggers retransmission |
| **Bandwidth–delay product** | Bandwidth × round-trip delay = bits that can be "in the pipe" |
| **Channel utilization/efficiency** | Fraction of time the sender is actually sending useful data |

## 4.6 Comparison: Flow Control vs Error Control
| Parameter | Flow Control | Error Control |
|---|---|---|
| Goal | Prevent receiver overrun | Ensure error-free, complete delivery |
| Tackles | Speed mismatch | Corruption, loss, duplication |
| Mechanisms | Stop-and-wait, sliding window | CRC, ACK/NAK, timers, retransmission |
| Feedback | ACK / RR / RNR | ACK / NAK / timeout |

## Do Not Confuse
- **Flow control ≠ Congestion control.** Flow control is **end-to-end/hop-to-hop between one sender and one receiver** (receiver capacity, **Data Link and Transport** layers). Congestion control deals with **network capacity** (routers overloaded; Network/Transport layer).
- **Data link flow control** works **node-to-node**; TCP flow control works **process-to-process (end-to-end)**.

## Exam Points to Remember
1. DLC = framing + flow control + error control.
2. Sliding window uses **m-bit** sequence numbers modulo 2ᵐ.
3. Error control = **detection + ACK/NAK + timers + retransmission (ARQ)**.
4. **Piggybacking** combines ACK with reverse data.
5. Three ARQ protocols: **Stop-and-Wait, Go-Back-N, Selective Repeat**.

## Potential Exam Questions
- **Very short:** Define flow control/error control/piggybacking/ARQ.
- **Short:** Explain sliding window flow control. Differentiate flow and error control.
- **Long:** Discuss data link control functions, with the role of sequence numbers, timers and acknowledgements.
- **Diagram:** Draw sliding window of sender with Sf and Sn.

---

# 5. STOP-AND-WAIT ARQ

## 5.1 Standard Examination Definition
**Stop-and-Wait ARQ** is an error-control and flow-control protocol in which the sender **transmits one frame at a time**, starts a **retransmission timer**, and **waits for a positive acknowledgement** before sending the next frame; if the ACK does not arrive before time-out (frame lost/corrupted or ACK lost), the sender **retransmits the same frame**. Frames and ACKs carry **1-bit sequence numbers (0 and 1)** to avoid duplicate acceptance.

**In Simple Words:** Send one letter, wait for the receipt. No receipt in time? Send the same letter again.

## 5.2 Characteristics
- Sender window size = **1**, receiver window size = **1**.
- Sequence numbers: **0, 1** (modulo 2).
- **ACK number = number of the next frame expected** (ACK 1 after frame 0 received correctly).
- Sender keeps **copy** of the last frame until ACK arrives.
- One timer.
- **Half-duplex-like usage** of channel (one direction at a time).

## 5.3 Working (Step-by-Step)
1. Sender transmits **Frame 0**, keeps a copy, starts timer.
2. Receiver checks CRC/sequence number.
   - Correct & expected → accepts, sends **ACK 1**.
   - Corrupted → **discards silently**.
   - Duplicate (already received) → discards data but **re-sends ACK**.
3. Sender gets **ACK 1** before time-out → stops timer, discards copy, sends **Frame 1**.
4. If the timer expires → resend the stored frame, restart timer.
5. Continue alternating sequence numbers 0, 1, 0, 1…

### Diagram — Normal Operation
```text
   Sender                              Receiver
     |--------- Frame 0 ---------------->|
     |<-------- ACK 1 -------------------|
     |--------- Frame 1 ---------------->|
     |<-------- ACK 0 -------------------|
     |--------- Frame 0 ---------------->|
```

### Diagram — Lost Frame
```text
   Sender                              Receiver
     |--- Frame 0 ----X (lost)           |
     |  ...timer expires...              |
     |--- Frame 0 (retransmit) --------->|
     |<-------- ACK 1 -------------------|
```

### Diagram — Lost ACK
```text
   Sender                              Receiver
     |--------- Frame 0 ---------------->|  (accepted)
     |   X------- ACK 1 (lost) ----------|
     |  ...timer expires...              |
     |--- Frame 0 (retransmit) --------->|  (duplicate: discard data)
     |<-------- ACK 1 -------------------|  (re-ACK)
     |--------- Frame 1 ---------------->|
```

### Diagram — Delayed ACK
If ACK arrives after time-out, the sender has already resent Frame 0; the receiver identifies the duplicate through sequence number 0 and discards it but ACKs again; sender **ignores the duplicate/late ACK**.

**How to draw in exam:**
1. Draw two vertical lines labelled Sender and Receiver.
2. Draw slanting arrows for Frame 0, ACK 1, Frame 1, ACK 0.
3. Mark an **X** on a lost frame/ACK and write "time-out".
4. Draw the retransmitted frame with the same number.

## 5.4 Efficiency (Channel Utilization)
Let **Tf** = frame transmission time = frame size / bandwidth, **Tp** = one-way propagation delay, **a = Tp / Tf**.
Ignoring ACK transmission time and processing:

**Cycle time = Tf + 2Tp**

**Utilization U = Tf / (Tf + 2Tp) = 1 / (1 + 2a)**

**With frame error probability p:** U = (1 − p) / (1 + 2a)

**Throughput = U × Bandwidth.**

**Solved Example:** Bandwidth = 1 Mbps, frame = 1000 bits, one-way propagation delay = 5 ms.
- Tf = 1000 / 10⁶ = **1 ms**; Tp = 5 ms → a = 5.
- U = 1 / (1 + 10) = **1/11 ≈ 9.09 %**.
- Throughput ≈ 0.0909 × 1 Mbps ≈ **90.9 kbps**.

**Observation:** Efficiency is very poor on **long/high-bandwidth links** (large a), the reason sliding-window protocols exist.

## 5.5 Advantages, Disadvantages, Applications
| Advantages | Disadvantages |
|---|---|
| Simplest ARQ; minimal buffer (1 frame) | Very low efficiency for large bandwidth-delay product |
| Simple sender/receiver logic | Bandwidth wasted while waiting |
| Only 1-bit sequence number needed | Cannot pipeline frames |

**Applications:** Short-delay/low-speed links, simple embedded/serial communication, some wireless (802.11 uses stop-and-wait style ACK per frame).

## Exam Points to Remember
1. Window size = **1**; sequence numbers **0, 1**.
2. **ACK n = next expected frame**.
3. Sender retains a frame copy until ACK; uses timer.
4. Handles **lost frame, lost ACK, delayed ACK, damaged frame** via time-out + sequence numbers.
5. **U = 1 / (1 + 2a)**, a = Tp/Tf.
6. Efficient only when Tp ≪ Tf.

## Potential Exam Questions
- **Very short:** What is ARQ? Why are 1-bit sequence numbers enough in stop-and-wait?
- **Short:** Explain lost frame and lost ACK scenarios with diagrams.
- **Long:** Explain Stop-and-Wait ARQ with operation, diagrams, efficiency and limitations.
- **Numerical:** Calculate the efficiency for a given bandwidth, frame size, distance/delay.

---

# 6. GO-BACK-N ARQ

## 6.1 Standard Examination Definition
**Go-Back-N ARQ** is a **sliding-window** error-control protocol in which the sender may transmit **up to N (window size) consecutive frames without waiting for acknowledgement**, whereas the **receiver accepts only the in-order frame it expects (receiver window = 1)**; if a frame is lost or damaged, the receiver **discards it and all subsequent frames**, and upon time-out the sender **retransmits the erroneous frame and all frames following it** ("goes back N frames").

**In Simple Words:** Keep sending many frames. If frame 3 goes missing, the receiver refuses 4, 5, 6… too, and the sender must restart from 3.

## 6.2 Characteristics
| Feature | Value |
|---|---|
| Sequence numbers | **m bits** → 0 … 2ᵐ − 1 |
| **Maximum sender window size** | **2ᵐ − 1** |
| Receiver window size | **1** |
| ACK type | **Cumulative** (ACK n = all frames before n received; n = next expected) |
| Timer | One timer, for the oldest outstanding frame |
| Out-of-order frames | **Discarded** by receiver |
| Buffer needed | Sender must buffer all outstanding frames; receiver no buffering |

**Why window ≤ 2ᵐ − 1?** If the window equals 2ᵐ, then after all ACKs are lost the receiver expects frame 0 of the *next* cycle but the sender retransmits the *old* frame 0 → the receiver accepts a duplicate as new data. Limiting to 2ᵐ − 1 prevents this ambiguity.

## 6.3 Working (Step-by-Step)
1. Sender sends frames 0, 1, 2, … up to window size N, starts a timer for the oldest unacknowledged frame.
2. Receiver accepts only the frame whose number = **Rn (next expected)**; sends **ACK Rn+1** (cumulative).
3. If a frame arrives out of order (e.g., a lost predecessor) → **discarded**; receiver may resend the last ACK (or NAK).
4. On receiving ACK k, the sender **slides window** to start from k (all frames < k acknowledged).
5. If the timer for the oldest frame expires → sender **retransmits all outstanding frames starting from that frame**.
6. Process continues until all data is delivered.

### Diagram — Lost Frame (window size 4, m = 3)
```text
 Sender                                   Receiver
   |-- F0 -------------------------------->| accept (Rn=1)
   |-- F1 ---------X (lost)                |
   |-- F2 -------------------------------->| discard (expects 1)
   |-- F3 -------------------------------->| discard
   |<-------- ACK 1 ------------------------|
   |  ... time-out for F1 ...
   |-- F1 (resend) ------------------------>| accept
   |-- F2 (resend) ------------------------>| accept
   |-- F3 (resend) ------------------------>| accept
   |<-------- ACK 4 -----------------------|
```

**How to draw in exam:**
1. Two vertical lines; draw F0–F3 as arrows.
2. Put **X** on the lost frame.
3. Show "discard" next to later frames at receiver.
4. Show time-out and resend of lost frame + all later frames.
5. Draw sliding window boxes above sender line (optional, for extra marks).

### Lost ACK
Because ACKs are **cumulative**, a later ACK acknowledges earlier frames too; a lost ACK causes retransmission only if **no subsequent ACK** arrives before the timer expires.

## 6.4 Efficiency
Window N frames, a = Tp/Tf:
- If **N ≥ 1 + 2a** → **U = 1** (channel fully utilized, no errors).
- If **N < 1 + 2a** → **U = N / (1 + 2a)**.
- With frame error probability p (and N ≥ 1+2a): **U = (1 − p) / (1 + 2ap)** (each error costs about 1 + 2a frames of retransmission).

**Solved Example:** Same link as before (a = 5), N = 7: U = 7 / 11 ≈ **63.6 %**. To reach 100 % need N ≥ 11 → m ≥ 4 bits (max window 2⁴ − 1 = 15).

## 6.5 Advantages, Disadvantages, Applications
| Advantages | Disadvantages |
|---|---|
| Pipelining → higher utilization than stop-and-wait | Wastes bandwidth resending good frames on error |
| Receiver very simple (no reorder buffer) | Poor on high error-rate/long links |
| Cumulative ACKs reduce ACK traffic | Requires sender buffer for N frames |

**Applications:** Basis of **HDLC** (with REJ), early TCP behaviour (cumulative ACK), satellite/low-error links with simple receivers.

## Exam Points to Remember
1. Sender window = **2ᵐ − 1**; receiver window = **1**.
2. Receiver **discards out-of-order** frames.
3. **Cumulative ACK**, single timer.
4. On time-out, resend the lost frame **and all following frames**.
5. U = N/(1+2a) if N < 1+2a, else 1.
6. m = 3 → window ≤ 7; m = 4 → window ≤ 15.

## Potential Exam Questions
- **Very short:** Why is window size 2ᵐ − 1 in GBN? What does "Go-Back-N" mean?
- **Short:** Explain the lost-frame scenario with a diagram.
- **Long:** Describe Go-Back-N ARQ with window operation, ACK handling and efficiency.
- **Numerical:** Bandwidth-delay problems, minimum bits for sequence numbers.

---

# 7. SELECTIVE REPEAT ARQ

## 7.1 Standard Examination Definition
**Selective Repeat ARQ** is a **sliding-window** error-control protocol in which both the **sender and receiver maintain windows larger than one**, the receiver **accepts and buffers out-of-order frames** within its window, **individually acknowledges** each correct frame, and the sender **retransmits only the specific frames** that are lost or corrupted, each tracked by an **individual timer**; the buffered frames are delivered to the network layer **in order** once the missing frame arrives.

**In Simple Words:** Only the damaged frame is resent. The receiver keeps the good later frames in a buffer and puts everything in order afterwards.

## 7.2 Characteristics
| Feature | Value |
|---|---|
| Sequence numbers | m bits (0 … 2ᵐ − 1) |
| **Sender window size** | **2ᵐ⁻¹** |
| **Receiver window size** | **2ᵐ⁻¹** |
| ACK type | **Individual (selective)** ACK per frame; **NAK** for a damaged/missing frame |
| Timers | One timer **per outstanding frame** |
| Out-of-order frames | **Buffered** and re-sequenced |
| Buffers | Needed at **both** sender and receiver |

**Why window ≤ 2ᵐ⁻¹?** With window 2ᵐ⁻¹ at both ends, the old and new windows never overlap; if larger, the receiver could mistake a retransmitted old frame for a new one (window overlap ambiguity).

## 7.3 Working (Step-by-Step)
1. Sender transmits frames within its window, starting a timer for each.
2. Receiver accepts **any frame within its window** (in-order or not), stores it, and sends an **ACK for that frame**.
3. If a frame is missing/damaged, the receiver sends **NAK** for it (once) and continues buffering later frames.
4. Sender **retransmits only the NAK'd or timed-out frame**.
5. When the missing frame arrives, the receiver **delivers the contiguous block in order** and slides its window.
6. Sender slides its window as the lowest outstanding frame is ACKed.

### Diagram — Lost Frame
```text
 Sender                                   Receiver
   |-- F0 ---------------------------------->| accept, ACK 0
   |-- F1 ----------X (lost)                 |
   |-- F2 ---------------------------------->| buffer, ACK 2 (out of order)
   |-- F3 ---------------------------------->| buffer, ACK 3
   |<------ NAK 1 ----------------------------|
   |-- F1 (only this resent) ---------------->| accept -> deliver F1,F2,F3 in order
   |<------ ACK 1 ----------------------------|
```

**How to draw in exam:**
1. Two vertical lines; arrows for F0–F3; **X** on F1.
2. Write "buffered" at the receiver for F2, F3.
3. Show NAK 1 (or timer expiry) and **only F1** resent.
4. Mention "delivered in order".

## 7.4 Efficiency
- Without errors: U = 1 if N ≥ 1 + 2a; else N/(1 + 2a) (same as GBN).
- With error probability p: **U = 1 − p** (only bad frames resent) when the window is large enough.

**Example:** p = 0.1 → SR efficiency ≈ 90 %; GBN with a = 5: (1−0.1)/(1+2×5×0.1)=0.9/2 = **45 %**.

## 7.5 Advantages, Disadvantages, Applications
| Advantages | Disadvantages |
|---|---|
| Retransmits only lost frames → best bandwidth efficiency | Complex sender/receiver logic |
| Suitable for noisy/long-delay links | Receiver buffer + reordering needed |
| Fewer retransmissions | Multiple timers; smaller max window (2ᵐ⁻¹) |

**Applications:** **TCP with SACK (selective acknowledgement)**, satellite links, wireless links with high error rate, 802.11 block-ack style mechanisms.

## 7.6 Comparison: Stop-and-Wait vs Go-Back-N vs Selective Repeat
| Parameter | Stop-and-Wait ARQ | Go-Back-N ARQ | Selective Repeat ARQ |
|---|---|---|---|
| Sender window | 1 | 2ᵐ − 1 | 2ᵐ⁻¹ |
| Receiver window | 1 | 1 | 2ᵐ⁻¹ |
| Sequence numbers | 1 bit (0, 1) | m bits | m bits |
| Retransmission on error | That frame | Erroneous frame + all after it | **Only** erroneous frame |
| Out-of-order frames | Not applicable | Discarded | Buffered |
| ACK | Individual | Cumulative | Individual (+NAK) |
| Timers | 1 | 1 (oldest frame) | 1 per frame |
| Receiver complexity | Lowest | Low | High (sorting/buffers) |
| Efficiency (no error) | 1/(1+2a) | N/(1+2a) or 1 | N/(1+2a) or 1 |
| Efficiency (with error p) | (1−p)/(1+2a) | (1−p)/(1+2ap) | (1−p) |
| Bandwidth waste | Idle time | Retransmits good frames | Least |
| Example use | Simple links | HDLC, cumulative-ACK protocols | TCP-SACK, wireless |

## Do Not Confuse
- **ARQ window sizes:** GBN uses **2ᵐ − 1**, SR uses **2ᵐ⁻¹**. Reversing them is a very common mistake.
- **Cumulative ACK (GBN)** vs **individual ACK (SR)**.
- Stop-and-Wait *with* error control (ARQ) ≠ plain stop-and-wait flow control (no error handling).

## Exam Points to Remember
1. SR: sender = receiver window = **2ᵐ⁻¹**.
2. Only the damaged frame is retransmitted; receiver **buffers** the rest.
3. Individual timers + individual ACK/NAK.
4. GBN window 2ᵐ − 1, receiver window 1; SR both 2ᵐ⁻¹.
5. SR best efficiency but highest complexity.
6. TCP uses cumulative ACK with optional SACK.

## Potential Exam Questions
- **Very short:** Why is SR window 2ᵐ⁻¹? What is NAK?
- **Short:** Explain SR operation with diagram.
- **Long:** Explain GBN and SR ARQ with diagrams and differentiate them.
- **Comparison:** Stop-and-Wait vs GBN vs SR.
- **Numerical:** Maximum window size for m = 4 in GBN and SR (15 and 8).

---

# 8. HDLC — HIGH-LEVEL DATA LINK CONTROL

## 8.1 Standard Examination Definition
**HDLC (High-level Data Link Control)** is a **bit-oriented, synchronous data link layer protocol** standardized by **ISO** (derived from IBM's SDLC) that provides **reliable, flow-controlled, error-controlled** transmission of frames over **point-to-point and multipoint links**, using **bit stuffing** for transparency, a **CRC-based Frame Check Sequence**, and **sliding-window (Go-Back-N/Selective-Reject)** ARQ mechanisms.

**In Simple Words:** HDLC is a rulebook for sending frames on a link: it marks frame boundaries with a special flag, checks each frame with CRC, numbers frames, and retransmits lost ones.

## 8.2 Characteristics
- **Bit-oriented** (treats data as a stream of bits, not characters).
- Synchronous transmission; supports **full-duplex** operation with **piggybacking**.
- Supports point-to-point and multipoint configurations.
- Uses **sliding window** (3-bit default, modulo-8; extended 7-bit, modulo-128).
- **Bit stuffing** for data transparency.
- Error detection via **16-bit (or 32-bit) CRC**.

## 8.3 Station Types and Configurations
| Station | Role |
|---|---|
| **Primary** | Controls the link; sends **commands**; can initiate/terminate connection |
| **Secondary** | Operates under the primary; sends **responses** |
| **Combined** | Acts as both primary and secondary; sends both commands and responses |

| Configuration | Description |
|---|---|
| **Unbalanced** | One primary + one or more secondaries (point-to-point or multipoint) |
| **Symmetrical** | Two physical stations each having primary + secondary logical parts |
| **Balanced** | Two **combined** stations on a point-to-point link |

## 8.4 Transfer Modes
| Mode | Full form | Description |
|---|---|---|
| **NRM** | **Normal Response Mode** | Unbalanced. Secondary may transmit **only when polled/permitted by primary**. Used for multipoint/legacy terminals. |
| **ABM** | **Asynchronous Balanced Mode** | Balanced. **Either combined station may initiate transmission** without permission; most common (point-to-point). |
| **ARM** | Asynchronous Response Mode (rarely used) | Secondary may initiate, but primary still controls the link. |

## 8.5 HDLC Frame Structure

```text
+--------+---------+-----------+-------------------+-----------+--------+
|  Flag  | Address |  Control  |   Information     |    FCS    |  Flag  |
| 8 bits | 8 bits  | 8/16 bits |  variable length  | 16/32 bits| 8 bits |
+--------+---------+-----------+-------------------+-----------+--------+
 01111110                                                        01111110
```

| Field | Size | Function |
|---|---|---|
| **Flag** | 8 bits `01111110` | Marks the **start and end** of a frame; synchronization; one flag may serve as end of one frame and start of next |
| **Address** | 8 bits (extendable) | Identifies the **secondary station** (source in a response, destination in a command); all-1s = broadcast |
| **Control** | 8 (or 16) bits | Identifies **frame type**, carries sequence numbers, ACK numbers, poll/final bit, commands |
| **Information** | Variable | User data (network-layer packet) — present in I-frames (and UI frames), absent in S-frames |
| **FCS** | 16 or 32 bits | CRC for **error detection** over Address, Control, Information |

**How to draw in exam:**
1. Draw six adjacent boxes in a row.
2. Label: Flag, Address, Control, Information, FCS, Flag.
3. Write the size below each box, and `01111110` under both flags.

## 8.6 Frame Types (based on Control field)

### Control Field Formats
```text
Bit position:     1     2  3  4     5     6  7  8
I-frame:          0   |   N(S)    | P/F |   N(R)
S-frame:          1  0 | Code(2)  | P/F |   N(R)
U-frame:          1  1 | Code(2)  | P/F | Code(3)
```
- **N(S)** = send sequence number (3 bits); **N(R)** = receive sequence number, i.e., ACK = next frame expected (3 bits).
- **P/F** = **Poll/Final** bit: **Poll** (P) when sent by the primary → "you may transmit"; **Final** (F) when sent by a secondary → "response complete/last frame".

### (A) Information Frame (I-frame)
- Control field starts with **0**.
- Carries **user data** plus **flow and error control** information (N(S), N(R)) → **piggybacking** of ACK.

### (B) Supervisory Frame (S-frame)
- Control field starts with **10**; **no information field**; used for **flow and error control** when piggybacking is not possible.

| S-frame | Code | Function |
|---|---|---|
| **RR** (Receive Ready) | 00 | ACK — ready to receive; N(R) = next expected frame |
| **RNR** (Receive Not Ready) | 10 | ACK + **stop sending** (receiver busy; flow control) |
| **REJ** (Reject) | 01 | **NAK — Go-Back-N**: retransmit from N(R) onwards |
| **SREJ** (Selective Reject) | 11 | **NAK — Selective Repeat**: retransmit only frame N(R) |

### (C) Unnumbered Frame (U-frame)
- Control field starts with **11**; used for **link management** (setup, disconnect, mode setting); no sequence numbers; may carry system info.

| U-frame | Meaning |
|---|---|
| **SNRM** | Set Normal Response Mode |
| **SABM / SABME** | Set Asynchronous Balanced Mode (extended) |
| **DISC** | Disconnect |
| **UA** | Unnumbered Acknowledgement (positive response to a command) |
| **DM** | Disconnected Mode |
| **FRMR** | Frame Reject (invalid frame received, unrecoverable) |
| **UI** | Unnumbered Information |
| **RSET / RD / XID / TEST** | Reset, Request Disconnect, Exchange ID, Test |

## 8.7 Bit Stuffing (Data Transparency)
**Definition:** Bit stuffing is a technique in which the **sender inserts an extra 0 after every occurrence of five consecutive 1s** in the data (between flags), so that the pattern `01111110` **never appears inside the frame data**; the **receiver removes a 0 that follows five consecutive 1s**.

**Example:**
- Original data: `011111101111100111111`
- Rule: scan left to right; after **five consecutive 1s** insert a **0**, then restart the count.

```text
Original : 0 11111 1 0 11111 0 0 111111
Stuffed  : 0 11111 0 1 0 11111 0 0 0 11111 0 1
Result   : 011111010111110001111101      (21 bits -> 24 bits, 3 zeros stuffed)
```
**Receiver (destuffing):** after five consecutive 1s, if the next bit is 0 it is **deleted**; if it is a 1 (sixth one) the receiver checks for a flag `01111110` (frame boundary) or an abort (7+ ones).

**Advantages:** Guarantees uniqueness of the flag; simple.
**Disadvantage:** Variable frame size; slight overhead.

## 8.8 HDLC Operation (Working)
1. **Link setup:** Primary/combined station sends a U-frame (**SABM/SNRM**); the peer responds with **UA**.
2. **Data transfer:** I-frames exchanged with N(S)/N(R), sliding window of size up to 7 (modulo 8). ACK piggybacked in N(R).
3. **Flow control:** Receiver sends **RNR** to stop and **RR** to resume.
4. **Error control:** If an error is detected (FCS/sequence), the receiver sends **REJ** (Go-Back-N) or **SREJ** (Selective Repeat).
5. **Link disconnect:** Sender transmits **DISC**; receiver replies **UA**.

```text
  Station A                        Station B
     |--- SABM ---------------------->|   (set ABM)
     |<-- UA -------------------------|
     |--- I[N(S)=0,N(R)=0] ---------->|
     |<-- I[N(S)=0,N(R)=1] -----------|   (piggybacked ACK)
     |--- I[1,1] -------------------->|
     |<-- RR N(R)=2 ------------------|   (S-frame ACK)
     |--- DISC ---------------------->|
     |<-- UA -------------------------|
```

**Advantages:** Reliable, bit-oriented, transparent, full-duplex, supports multipoint, efficient piggybacking.
**Disadvantages:** Complex compared with simple protocols; not designed for multiprotocol/IP negotiation (why PPP exists); several incompatible vendor variants.
**Applications:** WAN links (X.25, Frame Relay ancestors), ISDN D-channel (LAPD), router-to-router serial links (Cisco HDLC variant), foundation for **PPP, LAPB, LAPD, LLC (IEEE 802.2)**.

## Do Not Confuse
- **HDLC (bit-oriented, bit stuffing)** vs **PPP (byte-oriented, byte/character stuffing)**.
- **N(S)** (sequence of the frame *I am sending*) vs **N(R)** (the frame *I expect next*).
- **REJ** (Go-Back-N NAK) vs **SREJ** (Selective Repeat NAK).
- **P/F bit** is *Poll* from primary, *Final* from secondary.

## Exam Points to Remember (HDLC)
1. Flag = **01111110**; **bit stuffing: insert 0 after five 1s**.
2. Frame: Flag | Address | Control | Info | FCS | Flag.
3. Three frame types: **I, S, U** (control field starts 0, 10, 11).
4. S-frames: **RR, RNR, REJ, SREJ**; U-frames: **SABM, SNRM, UA, DISC, FRMR**.
5. Modes: **NRM, ABM**; stations: **primary, secondary, combined**.
6. P/F bit: Poll (primary→secondary), Final (secondary→primary).
7. Sliding window: 3-bit numbers (window ≤ 7), extended 7-bit.
8. FCS = 16-bit (CRC-CCITT) or 32-bit CRC.

## Potential Exam Questions
- **Very short:** Expand HDLC. What is the flag pattern? What is bit stuffing?
- **Short:** Explain HDLC frame types. Explain NRM and ABM. Bit-stuff a given string.
- **Long:** Explain HDLC frame format, control field, frame types and working with diagrams.
- **Comparison:** HDLC vs PPP.
- **Diagram:** HDLC frame format; control field of I, S, U frames.

---

# 9. POINT-TO-POINT PROTOCOL (PPP) — PPP STACK

## 9.1 Standard Examination Definition
**Point-to-Point Protocol (PPP)** is a **byte-oriented data link layer protocol** (RFC 1661), derived from HDLC, used to provide **framing, link establishment, authentication and multi-protocol network-layer encapsulation** over **point-to-point serial links** such as dial-up modems, DSL and leased lines, using the **Link Control Protocol (LCP)**, **authentication protocols (PAP, CHAP)** and **Network Control Protocols (NCP)**.

**In Simple Words:** PPP is what your modem/ISP link used to set up a connection: agree on link settings, check the username/password, get an IP address, then carry IP packets.

## 9.2 Why PPP? (Need)
- HDLC lacks **authentication**, **multiple network-layer protocol** support, and **IP address negotiation**.
- Homes/offices connect to ISPs over point-to-point links; need **standard, simple, multi-protocol, secure** link.

## 9.3 Services Provided / Not Provided
| Provided | Not provided |
|---|---|
| Framing (delimits frames) | **Flow control** (no sliding window) |
| Link setup/termination (LCP) | **Sophisticated error control** (only error *detection* by CRC; corrupted frames discarded) |
| Authentication (PAP/CHAP) | **Multipoint** links (point-to-point only) |
| Multiple network protocols (IP, IPX, AppleTalk via NCP) | Addressing (no need — only two stations) |
| Network-layer address negotiation (IPCP) | Sequence numbering (in default mode) |
| Multilink PPP (combine several links) | |
| Error detection with CRC | |

## 9.4 PPP Frame Format

```text
+--------+---------+---------+-----------+-------------------+-----------+--------+
|  Flag  | Address | Control | Protocol  |      Payload      |    FCS    |  Flag  |
| 1 byte | 1 byte  | 1 byte  | 1-2 bytes |  variable (1500)  | 2/4 bytes | 1 byte |
+--------+---------+---------+-----------+-------------------+-----------+--------+
 01111110  11111111  00000011                                            01111110
```

| Field | Value / Function |
|---|---|
| **Flag** | `01111110` (7E); frame delimiter |
| **Address** | `11111111` (broadcast; constant, since point-to-point) |
| **Control** | `00000011` (unnumbered frame, i.e., no sequencing/flow control in default) |
| **Protocol** | Identifies payload type: `0xC021` = LCP, `0x8021` = IPCP (NCP for IP), `0xC023` = PAP, `0xC223` = CHAP, `0x0021` = IP datagram |
| **Payload** | User data/control information; default max **1500 bytes** (MRU) |
| **FCS** | 16-bit (default) or 32-bit CRC |

**Byte (character) stuffing:** PPP uses escape byte `01111101` (**0x7D**). If a flag (0x7E) or escape byte appears in data, it is preceded by the escape byte (and modified) so that the flag never appears inside the frame data.

**How to draw in exam:** Seven boxes: Flag, Address, Control, Protocol, Payload, FCS, Flag with byte sizes and the constant values 7E, FF, 03.

## 9.5 PPP Stack (Protocols in PPP)

```text
   Network Layer:   IP  |  IPX  |  AppleTalk ...   (payload data)
                     ^
  ----------------------------------------------------------------
   PPP  |  NCP (IPCP, IPXCP, ...)    <- network layer configuration
        |  Authentication: PAP, CHAP <- verify identity
        |  LCP                        <- link establishment/config/termination
        |  Data link framing + CRC (HDLC-like frame)
  ----------------------------------------------------------------
   Physical Layer:  Modem / DSL / Serial / SONET
```

### (A) Link Control Protocol (LCP)
**Definition:** LCP is responsible for **establishing, configuring, testing, maintaining and terminating** the link, negotiating options such as **maximum receive unit (MRU), authentication protocol, compression and error detection (FCS size)**.

LCP packet types: **Configure-Request, Configure-Ack, Configure-Nak, Configure-Reject, Terminate-Request/Ack, Code-Reject, Protocol-Reject, Echo-Request/Reply, Discard-Request.**

### (B) Authentication Protocols
**1. PAP — Password Authentication Protocol**
- **Two-way handshake**: peer sends **user ID + password** (in **plaintext**) → authenticator replies **accept/reject**.
- **Weak:** password visible on link, no protection from replay, authentication only once.

**2. CHAP — Challenge Handshake Authentication Protocol**
- **Three-way handshake** using **challenge–response with hashing (MD5)**; the password is **never transmitted**.
1. Authenticator sends a **challenge** (random value + ID).
2. Peer replies with **hash(ID + secret + challenge)**.
3. Authenticator compares with its own computed hash → **success/failure**.
- May repeat the challenge **periodically** (protects against hijack).

| Parameter | PAP | CHAP |
|---|---|---|
| Handshake | Two-way | Three-way |
| Password transmission | **Plaintext** | **Never sent (hash)** |
| Initiated by | Peer (client) | Authenticator (server) |
| Repeated challenge | No | Yes (periodic) |
| Security | Weak | Stronger |

### (C) Network Control Protocols (NCP)
**Definition:** PPP defines a **separate NCP for each supported network-layer protocol** (e.g., **IPCP** for IP, IPXCP for IPX) that **configures the network-layer parameters** such as **IP address assignment, DNS server addresses, and header compression**.

## 9.6 PPP Transition Phases (State Diagram)

```text
       +------+   carrier detected   +-----------+   options agreed    +---------------+
       | DEAD |--------------------->| ESTABLISH |-------------------->| AUTHENTICATE  |
       +------+                      |   (LCP)   |                     |  (PAP / CHAP) |
          ^                          +-----------+                     +---------------+
          |                               | fail                              | success
          |                               v                                   v
          |                        +-----------+                      +---------------+
          |<-----------------------| TERMINATE |<---------------------|    NETWORK    |
          |     carrier dropped    +-----------+  done / DISC         |    (NCP)      |
                                          ^                           +---------------+
                                          |                                   |
                                          |                           +---------------+
                                          +---------------------------|     OPEN      |
                                                                      | (data transfer)|
                                                                      +---------------+
```

| Phase | Description |
|---|---|
| **Dead** | No physical link; idle |
| **Establish** | Physical link is up; **LCP** packets negotiate link options |
| **Authenticate** | (Optional) **PAP/CHAP** verify identity |
| **Network** | **NCP** (IPCP) configures network-layer (IP address etc.) |
| **Open** | **Data transfer** — user data and control packets |
| **Terminate** | LCP Terminate packets close the link; back to Dead |

**Working (steps):**
1. Physical connection (modem dials/link up) → leaves **Dead**.
2. **LCP** exchange establishes link parameters.
3. If authentication is required → **PAP/CHAP**.
4. **NCP (IPCP)** assigns IP address and settings.
5. **Open** → IP datagrams exchanged as PPP payload.
6. Either end sends **LCP Terminate-Request** → **Terminate** → Dead.

## 9.7 Multilink PPP (MP)
Combines **multiple physical links** (e.g., several ISDN B-channels or DSL lines) into **one logical link**: a packet is **fragmented**, fragments carry sequence numbers, sent over separate links and **reassembled** at the destination → higher bandwidth.

## 9.8 Extensions / Real-World
- **PPPoE (PPP over Ethernet)** — used by DSL/broadband providers to authenticate subscribers.
- **PPPoA** (over ATM), **L2TP/PPTP VPNs** encapsulate PPP.
- Dial-up Internet, DSL, some cellular data, VPN tunnels, router serial WAN links.

## 9.9 Advantages, Disadvantages
| Advantages | Disadvantages |
|---|---|
| Multiple network protocols | No flow control |
| Authentication (PAP/CHAP) | No reliable delivery (only error detection) |
| IP address assignment (IPCP) | Point-to-point only |
| Link testing/monitoring, options negotiation | PAP insecure; overhead for link setup |
| Multilink support | |

## 9.10 Comparison: HDLC vs PPP
| Parameter | HDLC | PPP |
|---|---|---|
| Orientation | **Bit-oriented** | **Byte-oriented** |
| Stuffing | **Bit stuffing** (0 after five 1s) | **Byte stuffing** (escape 0x7D) |
| Multi-protocol support | No (single network protocol field absent in standard HDLC) | **Yes** (Protocol field) |
| Authentication | None | **PAP, CHAP** |
| Link configuration | Limited (U-frames) | **LCP, NCP** negotiation |
| Flow/error control | Sliding window, ARQ, ACK (reliable) | **Only error detection**, no flow control |
| Link type | Point-to-point & multipoint | **Point-to-point only** |
| Frame fields | Flag, Address, Control, Info, FCS, Flag | Flag, Address, Control, **Protocol**, Payload, FCS, Flag |
| Standard | ISO | IETF (RFC 1661) |
| Use | LAPB/X.25, ISDN, Cisco serial | Dial-up, DSL (PPPoE), VPN |

## Do Not Confuse
- **LCP ≠ NCP:** LCP sets up the **link**; NCP sets up the **network layer**.
- **PPP is data link layer** even though it negotiates IP addresses (IPCP).
- **PAP vs CHAP:** plaintext vs hashed challenge.

## Exam Points to Remember (PPP)
1. PPP: **byte-oriented**, HDLC-derived, **point-to-point**, RFC 1661.
2. Frame: **Flag(7E) | Address(FF) | Control(03) | Protocol | Payload | FCS | Flag**.
3. Stack: **LCP → Authentication (PAP/CHAP) → NCP**.
4. Phases: **Dead → Establish → Authenticate → Network → Open → Terminate**.
5. **No flow control, no error correction** (only CRC detection).
6. **PAP = 2-way, plaintext; CHAP = 3-way, hashed, periodic**.
7. Byte stuffing with escape **0x7D**; **Multilink PPP** bundles links.
8. PPPoE is used in DSL.

## Potential Exam Questions
- **Very short:** Define PPP; what is LCP/NCP; why PPP was developed.
- **Short:** Explain PPP frame format; explain PAP and CHAP; list services not provided by PPP.
- **Long:** Explain PPP with protocol stack, frame format and transition phase diagram.
- **Comparison:** HDLC vs PPP; PAP vs CHAP.
- **Diagram:** PPP frame; PPP transition state diagram; PPP protocol stack.

---

# 10. MULTIPLE ACCESS — OVERVIEW

## 10.1 Standard Examination Definition
**Multiple access** refers to the set of **protocols (MAC — Media Access Control protocols)** that coordinate **how multiple stations share a common broadcast communication channel**, deciding **who may transmit, when, and how collisions are avoided or resolved**, so that the shared medium is used efficiently and fairly.

**In Simple Words:** Many computers share one wire/radio channel. If all talk at once, the messages clash. Multiple-access rules say who speaks and when.

## 10.2 Need
- Shared-link (**broadcast**) networks: LANs (Ethernet bus), Wi-Fi, satellite, cellular.
- Simultaneous transmissions cause **collisions** and corrupt frames.
- Need fair, efficient, low-delay sharing.

## 10.3 Data Link Layer Sublayering
Refer to the sublayer diagram in the introduction: **LLC** (logical link, flow/error control) and **MAC** (multiple access).

## 10.4 Classification

```text
                    MULTIPLE ACCESS PROTOCOLS
                              |
      +-----------------------+------------------------+
      |                       |                        |
 RANDOM ACCESS         CONTROLLED ACCESS         CHANNELIZATION
 (Contention)          (Scheduled)               (Channel partitioning)
      |                       |                        |
 - ALOHA                - Reservation             - FDMA
     Pure                - Polling                - TDMA
     Slotted             - Token passing          - CDMA
 - CSMA
 - CSMA/CD
 - CSMA/CA
```

**How to draw in exam:** Draw a root box "Multiple Access Protocols", three child boxes, and list the protocols beneath each.

## 10.5 Comparison: Three Categories
| Parameter | Random Access | Controlled Access | Channelization |
|---|---|---|---|
| Principle | Stations contend; collisions possible | Stations take turns via permission | Channel divided by frequency/time/code |
| Control | Distributed, no central control | Central controller or token | Fixed allocation |
| Collisions | Yes (resolved by retransmission) | No | No |
| Performance at low load | **Excellent (low delay)** | Overhead of polling/token | Waste if station idle |
| Performance at high load | Poor (collisions) | **Good (predictable)** | Fixed capacity per user |
| Example | ALOHA, Ethernet, Wi-Fi | Token Ring, polling | GSM (TDMA), AMPS (FDMA), CDMA |

## Exam Points to Remember (Overview)
1. Multiple access = **MAC sublayer** functionality of the Data Link Layer.
2. Three families: **Random, Controlled, Channelization**.
3. Random: **no scheduling, collisions possible**; Controlled: **no collisions**; Channelization: **divide channel**.

## Potential Exam Questions
- **Short:** Classify multiple-access protocols. Explain MAC sublayer.
- **Long:** Explain the categories of multiple access with examples.
- **Diagram:** Classification tree.

---

# 11. RANDOM ACCESS

## 11.1 Standard Examination Definition
**Random access (contention) protocols** are MAC protocols in which **no station is superior to another and none is assigned control over another**; any station with data **transmits whenever it has data, subject to a defined procedure**, and if two or more stations transmit simultaneously a **collision** occurs, resolved by **retransmission after a random delay**.

**Two features:** (1) **No scheduled time** for a station to transmit (transmission is random). (2) **No rules specify which station goes next** — stations **compete** for the medium (hence **contention methods**).

**In Simple Words:** Anyone can talk any time; if two talk together, both wait a random time and try again.

## 11.2 ALOHA

### Pure ALOHA
**Definition:** Developed at the **University of Hawaii (1970, Norman Abramson)** — a random access protocol where **each station transmits a frame whenever it has data**, without checking the channel; if the ACK is not received within a time-out, the station assumes collision, **waits a random back-off time** and retransmits.

**Working:**
1. Station sends frame immediately when ready.
2. Waits for ACK for time-out = **2 × Tp** (maximum round-trip propagation delay).
3. No ACK → assume collision → **back-off**: wait random time **TB = R × Tp or R × Tfr** where **R = random integer in [0, 2ᴷ − 1]**, K = number of attempts.
4. Retransmit; after **Kmax = 15** attempts, abort and try later.

```text
 Station A: |=== Frame A1 ===|         (wait ACK)  ---> no ACK -> random wait -> resend
 Station B:        |=== Frame B1 ===|      overlap = collision (both destroyed)
 Time ---->
```

**Vulnerable time (pure ALOHA) = 2 × Tfr** (a frame collides if any other station starts one frame-time before or during it).

**Throughput:** **S = G × e^(−2G)**
- G = average number of frames generated per frame time (offered load).
- S = throughput (successful frames per frame time).
- **Maximum S = 0.184 (18.4 %)** at **G = 0.5**.

**Solved Example:** Frame time Tfr = 1 ms (200-bit frames, 200 kbps).
- Vulnerable time = 2 ms.
- If system generates 500 frames/s → G = 0.5 → S = 0.5 e⁻¹ = 0.184 → **184 frames/s** succeed.
- If 1000 frames/s → G = 1 → S = e⁻² = 0.135 → **135 frames/s**.

### Slotted ALOHA
**Definition:** Improvement by **Roberts (1972)** — **time is divided into discrete slots equal to one frame time (Tfr)**; a station may transmit **only at the beginning of a slot**, requiring **time synchronization** among stations.

- A collision can occur only if two stations pick the **same slot** (complete overlap).
- **Vulnerable time = Tfr** (half of pure ALOHA).
- **Throughput S = G × e^(−G)**; **Maximum S = 0.368 (36.8 %)** at **G = 1**.

**Solved Example:** Tfr = 1 ms, 1000 frames/s → G = 1 → S = e⁻¹ = 0.368 → **368 frames/s**; at 500 frames/s → G = 0.5 → S = 0.5e^(−0.5) = 0.303 → **303 frames/s**.

```text
Time slots:   | slot 1 | slot 2 | slot 3 | slot 4 |
Station A:    |  [A]   |        |        |  [A]   |
Station B:    |        |  [B]   |        |        |
Station C:    |        |        | [C][D] |        |  <- collision (same slot)
```

### Comparison: Pure vs Slotted ALOHA
| Parameter | Pure ALOHA | Slotted ALOHA |
|---|---|---|
| Transmission time | Any time | Only at slot start |
| Synchronization | Not required | **Required** |
| Vulnerable time | **2 × Tfr** | **Tfr** |
| Throughput formula | S = G e^(−2G) | S = G e^(−G) |
| Maximum throughput | **18.4 %** (G = 0.5) | **36.8 %** (G = 1) |
| Complexity | Simple | Slightly higher |
| Collision | Partial overlap | Full overlap only |

**Advantages (ALOHA):** Very simple; no coordination (pure); low delay at light load.
**Disadvantages:** Low efficiency; no carrier sensing; unstable at high load.
**Applications:** Early packet radio (ALOHAnet), satellite networks, RFID tag anti-collision, cellular random-access channels (RACH).

## 11.3 CSMA — Carrier Sense Multiple Access

**Standard Examination Definition:** **CSMA** is a random-access protocol based on the principle **"sense before transmit" (listen before talk)**: a station **senses the medium** for carrier activity and transmits only if the channel is **idle**, thereby reducing (but not eliminating) collisions.

**Why collisions still occur:** **Propagation delay** — a station may sense idle while another station's frame has been transmitted but has not yet reached it.

```text
 A -------------------- shared bus -------------------- B
 A starts at t0; signal reaches B only at t0 + Tp.
 If B senses at t0 + Tp/2 -> channel seems idle -> B transmits -> COLLISION.
```
**Vulnerable time in CSMA = propagation time Tp.**

### Persistence Methods (what to do when channel is busy/idle)
| Method | Behaviour | Characteristics |
|---|---|---|
| **1-Persistent** | Continuously senses; **transmits immediately (probability 1)** when the channel becomes idle | Highest collision chance if several wait; used in **Ethernet** |
| **Non-Persistent** | If busy, **waits a random time** then senses again | Lower collision, **higher delay** and possible idle channel waste |
| **p-Persistent** | Used with **slotted** channels; when idle, transmits with **probability p**, else waits for next slot (with probability q = 1 − p) and rechecks | Balances collision and idle time; used in some wireless |

```text
1-persistent:   busy? --yes--> keep sensing --> idle: SEND NOW
Non-persistent: busy? --yes--> wait random time --> sense again
p-persistent:   idle? --> send with prob p / defer (1-p) to next slot
```

| Parameter | 1-Persistent | Non-Persistent | p-Persistent |
|---|---|---|---|
| Sensing when busy | Continuous | After random wait | Continuous (slot-wise) |
| Send when idle | Immediately | Immediately | With probability p |
| Collision probability | Highest | Lowest | Moderate (tunable) |
| Delay/idle time | Lowest delay | Highest delay | Moderate |
| Used in | Ethernet (CSMA/CD) | Some wireless | Slotted wireless systems |

## 11.4 CSMA/CD — Carrier Sense Multiple Access with Collision Detection

**Standard Examination Definition:** **CSMA/CD** is the MAC protocol of **classic wired Ethernet (IEEE 802.3)** in which a station **senses the carrier before transmission and continues to monitor the medium while transmitting**; if a **collision is detected**, it **immediately aborts, sends a jam signal**, and **retransmits after a random back-off computed by the Binary Exponential Backoff algorithm**.

**In Simple Words:** Listen first; if quiet, talk; keep listening while talking; if you hear a clash, stop, shout "jam!", wait a random time, try again.

### Working (Algorithm)
1. Frame ready → **sense channel**.
2. If **busy** → keep sensing (1-persistent) until idle.
3. If **idle** → **transmit** and **monitor** the channel during transmission.
4. **No collision** until entire frame is sent → **success**.
5. **Collision detected** → stop transmission, send a **48-bit jam signal** so all stations recognise the collision.
6. Increment collision count **K**. If K > 15 (16 attempts) → **abort** and report error.
7. **Binary exponential back-off:** choose random **R ∈ [0, 2ᴷ − 1]** (K capped at 10); wait **R × 51.2 µs** (slot time for 10 Mbps Ethernet) → go to step 1.

```text
      +-----------------+
      | Frame ready     |
      +-----------------+
              |
              v
   +----> [Sense channel]
   |          |
   |     busy |  idle
   |<---------+   |
   |              v
   |        [Transmit frame + monitor]
   |              |
   |      collision?----no----> [Success] -> END
   |              |yes
   |              v
   |        [Send jam signal, stop]
   |              |
   |        K = K + 1 ; K > 15? --yes--> [Abort]
   |              |no
   |              v
   |        [Wait R x slot time, R in 0..2^K - 1]
   +--------------+
```

### Minimum Frame Size (Important Numerical)
For a sender to **detect a collision while it is still transmitting**, the transmission time must be at least the **round-trip time (twice the maximum propagation delay)**:

**Tfr ≥ 2 × Tp** ⇒ **Minimum frame size = Bandwidth × 2 × Tp**

**Solved Example:** LAN 10 Mbps, maximum propagation time Tp = 25.6 µs.
- 2Tp = 51.2 µs (slot time).
- Min frame = 10 × 10⁶ × 51.2 × 10⁻⁶ = **512 bits = 64 bytes** (the Ethernet minimum frame size).

**Numerical (max distance):** If the propagation speed is 2 × 10⁸ m/s and minimum frame = 512 bits at 10 Mbps, Tfr = 51.2 µs ⇒ Tp ≤ 25.6 µs ⇒ max distance = 2 × 10⁸ × 25.6 × 10⁻⁶ = **5120 m** (theoretical, ignoring repeater delays).

**Throughput (Ethernet efficiency):** ≈ **1 / (1 + 6.44 a)** where a = Tp/Tfr (approximate, for large numbers of stations); higher for larger frames and shorter cables.

**Limitations of CSMA/CD:** Works only on **wired**, **half-duplex** shared media; **not used on switched full-duplex Ethernet**, and **not practical for wireless** (stations can't listen while transmitting; hidden terminal problem).

**Advantages:** Efficient at moderate load; fast collision recovery; simple, decentralized; low delay at light load.
**Disadvantages:** Performance drops at heavy load; minimum frame size restriction; no priorities; not for wireless; probabilistic (non-deterministic) delay.
**Applications:** Legacy **10BASE5/10BASE2/10BASE-T and hub-based Ethernet**.

## 11.5 CSMA/CA — Carrier Sense Multiple Access with Collision Avoidance

**Standard Examination Definition:** **CSMA/CA** is the MAC protocol of **IEEE 802.11 wireless LANs (Wi-Fi)** in which stations **avoid collisions rather than detect them**, using **carrier sensing, Inter-Frame Spacing (IFS), a random contention window/back-off, positive acknowledgements**, and optionally the **RTS/CTS handshake with the Network Allocation Vector (NAV)**.

**Why not CD in wireless?** (1) Radio transceivers cannot **transmit and listen simultaneously** (transmit signal overwhelms received signal); (2) **Hidden terminal problem** — sender cannot hear a distant station that collides at the receiver; (3) fading makes "no collision heard" unreliable.

### Key Components
| Component | Function |
|---|---|
| **Interframe Space (IFS)** | Station **waits IFS after finding the channel idle**; shorter IFS = higher priority (SIFS < PIFS < DIFS) |
| **Contention window** | Time divided into slots; station picks **random number of slots** to wait; window size **doubles after each failure (binary exponential)**; timer paused while channel busy |
| **ACK** | Receiver acknowledges each frame after **SIFS**; no ACK → assume collision/error → retransmit |
| **RTS/CTS** | Optional handshake to reserve the channel and solve hidden terminal problem |
| **NAV (Network Allocation Vector)** | Virtual carrier sensing — timer set from the duration field of RTS/CTS telling other stations **how long to stay silent** |

### Working (DCF procedure) — Step by Step
1. Station senses channel; if **idle for DIFS** → may proceed.
2. If **busy** → wait until idle, wait DIFS, then choose **random back-off** in the **contention window**; decrement back-off counter only while channel is idle.
3. When counter = 0, **transmit** (optionally after **RTS → CTS** exchange).
4. Receiver replies with **ACK after SIFS**.
5. **ACK received** → success; else **double contention window** and retry (up to limit).
6. Other stations set **NAV** from RTS/CTS/frame duration and defer.

```text
   Sender                    Receiver                 Other stations
     |---- RTS (duration) ---->|                         (hear RTS -> set NAV)
     |<--- CTS (duration) -----|                         (hear CTS -> set NAV; hidden nodes silenced)
     |---- DATA -------------->|
     |<--- ACK ----------------|                         (NAV expires -> contend again)
   (each gap between frames = SIFS; before contention = DIFS + back-off)
```

**How to draw in exam:** Two vertical lines (Sender, Receiver) + a third for "Other stations"; arrows RTS, CTS, DATA, ACK; write IFS/SIFS gaps and label NAV.

### Hidden and Exposed Terminal Problems
- **Hidden terminal:** A and C both within range of B but **not of each other**; both sense idle and transmit to B → collision at B. **RTS/CTS solves it** (C hears B's CTS).
- **Exposed terminal:** B transmitting to A blocks C from sending to D, although D is out of B's range → wasted capacity.

```text
 (A) <----- (B) -----> (C)      A and C cannot hear each other (hidden from each other)
 A -> B and C -> B collide at B.
```

**Advantages:** Works for wireless; avoids collisions using reservation (RTS/CTS); ACK-based reliability; supports priority via IFS.
**Disadvantages:** Overhead (IFS, ACK, RTS/CTS); lower throughput; exposed terminal issue; contention delay.
**Applications:** **Wi-Fi (IEEE 802.11 a/b/g/n/ac/ax)**, Bluetooth-like ad-hoc networks, wireless sensor networks.

### Comparison: CSMA/CD vs CSMA/CA
| Parameter | CSMA/CD | CSMA/CA |
|---|---|---|
| Full form | Carrier Sense Multiple Access / Collision **Detection** | Carrier Sense Multiple Access / Collision **Avoidance** |
| Standard | IEEE 802.3 (Ethernet) | IEEE 802.11 (Wi-Fi) |
| Medium | Wired | Wireless |
| Collision handling | **Detects** while transmitting, aborts, back-off | **Avoids** by IFS, back-off, RTS/CTS, ACK |
| Collision detection | Yes (sender monitors line) | No (cannot listen while transmitting) |
| Acknowledgement | Not at MAC (higher layers) | **Mandatory ACK** per frame |
| Jam signal | Yes | No |
| Hidden terminal solution | Not applicable | RTS/CTS, NAV |
| Back-off | On collision (binary exponential) | Before every transmission after busy; window doubles on failure |
| Efficiency concern | Min frame size (64 B) | IFS/ACK/RTS overhead |

### Comparison: ALOHA vs CSMA
| Parameter | ALOHA | CSMA |
|---|---|---|
| Carrier sensing | **No** | **Yes** |
| Vulnerable time | 2Tfr (pure), Tfr (slotted) | Tp |
| Max throughput | 18.4 % / 36.8 % | Much higher (depends on persistence, a) |
| Collision probability | High | Lower |

## Do Not Confuse
- **CD (detect) ≠ CA (avoid)**: CD is Ethernet (wired); CA is Wi-Fi (wireless).
- **Vulnerable time:** pure ALOHA = **2Tfr**, slotted ALOHA = **Tfr**, CSMA = **Tp**.
- **Persistence ≠ back-off:** persistence decides behaviour when the channel is *busy/idle*; back-off decides the wait *after collision*.
- **Slot time (51.2 µs)** in Ethernet ≠ slot in slotted ALOHA (frame time).

## Exam Points to Remember (Random Access)
1. Random access: no schedule, no controller, **contention**, collisions resolved by **random back-off**.
2. Pure ALOHA: **S = G e^(−2G)**, max **18.4 %**, vulnerable **2Tfr**; Slotted: **S = G e^(−G)**, max **36.8 %**, vulnerable **Tfr**.
3. CSMA: **listen before talk**; collisions due to **propagation delay**; **vulnerable time = Tp**.
4. Persistence: **1-persistent, non-persistent, p-persistent**.
5. CSMA/CD: sense → send + monitor → **jam** → **binary exponential back-off**; **Tfr ≥ 2Tp**; min frame **512 bits/64 B** at 10 Mbps.
6. CSMA/CA: **IFS, contention window, ACK, RTS/CTS, NAV**; used in **802.11**.
7. Kmax = 15 attempts; back-off R ∈ [0, 2ᴷ − 1].

## Potential Exam Questions
- **Very short:** Define ALOHA; what is vulnerable time; why CD is not used in wireless; define NAV.
- **Short:** Compare pure and slotted ALOHA; explain persistence methods; explain hidden terminal problem.
- **Long:** Explain CSMA/CD with flowchart and minimum frame size derivation; explain CSMA/CA with RTS/CTS.
- **Comparison:** CSMA/CD vs CSMA/CA; Pure vs slotted ALOHA; ALOHA vs CSMA.
- **Diagram:** CSMA/CD flowchart; CSMA/CA timing with IFS and RTS/CTS; vulnerable time in pure ALOHA.
- **Numerical:** ALOHA throughput; CSMA/CD minimum frame size.

---

# 12. CONTROLLED ACCESS

## 12.1 Standard Examination Definition
**Controlled access** protocols are MAC methods in which the **stations consult one another (or a controller) to determine which station has the right to send**; a station may transmit **only when authorized** by the other stations/controller, thereby **eliminating collisions**.

**In Simple Words:** Like a classroom — you can speak only when the teacher points at you or you hold the talking stick.

**Three methods:** **Reservation, Polling, Token Passing.**

## 12.2 Reservation

**Definition:** In the reservation method, a **station must make a reservation before sending data**. Time is divided into **intervals**; at the start of each interval, a **reservation frame** precedes the data frames. If there are **N stations**, the reservation frame has **N minislots**, one per station. A station wishing to send **makes a reservation by setting its minislot to 1**. After the reservation frame, stations that reserved transmit in the order of their minislots.

```text
Interval 1:
| Reservation frame     | Data(st.1) | Data(st.3) | Data(st.4) |
| 1 | 0 | 1 | 1 | 0     |
  S1  S2  S3  S4  S5   (minislots)
Interval 2:
| Reservation frame     | Data(st.2) | Data(st.5) |
| 0 | 1 | 0 | 0 | 1     |
```
**Advantages:** No collisions; fair; predictable; good under heavy load.
**Disadvantages:** Reservation overhead (waste under light load); needs synchronization; fixed N minislots; delay.
**Applications:** **Satellite links, some cable/HFC (DOCSIS) upstream, WiMAX**.

## 12.3 Polling

**Definition:** In polling, **one device is designated the primary station (controller)** and the others are **secondary stations**; **all data exchanges must go through the primary**. The primary controls the link — it **decides who is allowed to use the channel at a given time**; secondaries transmit only when **invited (polled)**.

**Functions:**
- **Poll:** primary asks secondary "**do you have data?**" (used when primary has *no* data to send). Secondary replies with data (if any) or **NAK** (nothing).
- **Select:** used when the **primary has data to send** — it first sends a **SEL** frame to alert the secondary; secondary replies **ACK** if ready; then the primary sends data.

```text
POLL (secondary has data to send):          SELECT (primary has data to send):
Primary          Secondary                   Primary          Secondary
   |--- Poll ------->|                          |--- SEL --------->|
   |<-- Data --------|                          |<-- ACK ----------|
   |--- ACK -------->|                          |--- Data -------->|
                                                |<-- ACK ----------|
(if nothing to send:  Secondary --> NAK)
```

**Advantages:** No collisions; priority possible; simple central control; bounded delay.
**Disadvantages:** **Single point of failure** (primary); polling overhead; secondaries wait even when idle; limits throughput; delay increases with number of stations.
**Applications:** Legacy **mainframe–terminal** systems, **Bluetooth (master polls slaves)**, **802.11 PCF**, industrial control (Modbus), SDLC/HDLC NRM.

## 12.4 Token Passing

**Definition:** In token passing, the stations are organized in a **logical ring**; a special **short control frame called a token** circulates in a predefined order; **only the station holding the token may transmit**, and after sending (or when its token-holding time expires) it **releases the token to the next station**.

**Working:**
1. Token circulates around the logical ring.
2. Station wanting to send **captures the token** and transmits its frame(s).
3. Frame travels around; **destination copies it**; the sender **removes it** (or destination removes) and **releases the token**.
4. If no data, station **passes the token immediately**.

```text
        Station A
       /         \
  token           token
     /             \
Station D          Station B
     \             /
       Station C
   (logical ring; token direction A->B->C->D->A)
```

**Logical ring topologies:** Physical ring, **Dual ring**, **Bus ring (token bus)**, **Star ring** (via hub/MAU).
**Token management issues:** token **loss** (monitor station regenerates), **duplicate tokens**, priority tokens, **token holding time** limit.

**Advantages:** No collisions; deterministic bounded delay; fair; performs well at heavy load; priorities possible.
**Disadvantages:** Token overhead/latency at light load; **token loss** recovery complexity; station failure can break the ring (needs bypass); complexity.
**Applications:** **IEEE 802.5 Token Ring, IEEE 802.4 Token Bus, FDDI**, industrial real-time networks.

## 12.5 Comparison: Reservation vs Polling vs Token Passing
| Parameter | Reservation | Polling | Token Passing |
|---|---|---|---|
| Control | Distributed (reservation slots) | **Centralised primary** | Distributed (token) |
| Permission by | Minislot reservation | Poll/Select from primary | Possession of token |
| Collisions | No | No | No |
| Single point of failure | No | **Yes (primary)** | Token loss/station failure |
| Overhead | Reservation frame | Poll/NAK traffic | Token circulation |
| Suitable topology | Any shared medium | Star/multipoint | Logical ring |
| Example | Satellite, DOCSIS | Bluetooth, mainframe terminals | Token Ring, FDDI |

### Comparison: Random vs Controlled Access
| Parameter | Random Access | Controlled Access |
|---|---|---|
| Access | Contention (whenever data ready) | Permission-based |
| Collision | Possible | **None** |
| Delay | Unpredictable | **Bounded/predictable** |
| Light load | Better | Overhead wasted |
| Heavy load | Worse | **Better** |
| Example | Ethernet, Wi-Fi | Token Ring, polling |

## Exam Points to Remember (Controlled Access)
1. Three methods: **Reservation, Polling, Token passing** — **no collisions**.
2. Reservation: **N minislots** for N stations, then data in order.
3. Polling: **Poll** (primary asks) and **Select** (primary has data); **primary = single point of failure**.
4. Token passing: **logical ring**, token gives right to send; issues: **token loss/duplication**.
5. Controlled access = **deterministic delay** — good for real-time/heavy load.

## Potential Exam Questions
- **Very short:** What is a token? Define polling. What is a minislot?
- **Short:** Explain poll and select functions with diagrams. Explain reservation.
- **Long:** Explain the controlled access methods with diagrams, advantages and disadvantages.
- **Comparison:** Random vs Controlled access; polling vs token passing.
- **Diagram:** Reservation frame timeline; poll/select exchange; token ring.

---

# 13. CHANNELIZATION

## 13.1 Standard Examination Definition
**Channelization** (channel partitioning) is a **multiple-access method in which the available bandwidth of the link is shared in time, frequency or through code among different stations**, giving each station a dedicated portion of the channel resources (frequency band, time slot or unique code) so that stations can transmit **simultaneously without collision**.

**Three methods:** **FDMA, TDMA, CDMA.**

## 13.2 FDMA — Frequency Division Multiple Access

**Definition:** The **available bandwidth is divided into non-overlapping frequency bands**; **each station is allocated its own band** for the entire duration of communication, and stations transmit simultaneously in their bands.

- **Guard bands** between bands prevent interference (crosstalk).
- Each station uses **bandpass filters** to confine its signal.
- Analog technique, but can carry digital data.

```text
Frequency
  ^
  |  ----------- Band 4 (Station 4) ----------
  |  ==== guard band ====
  |  ----------- Band 3 (Station 3) ----------
  |  ==== guard band ====
  |  ----------- Band 2 (Station 2) ----------
  |  ==== guard band ====
  |  ----------- Band 1 (Station 1) ----------
  +--------------------------------------------> Time (all stations transmit continuously)
```

**Advantages:** Simple; no synchronization; continuous transmission; low delay.
**Disadvantages:** Bandwidth wasted when a station is idle; fixed number of users; guard band overhead; inflexible.
**Applications:** **First-generation cellular (AMPS)**, **radio and TV broadcasting**, **satellite channels**.

## 13.3 TDMA — Time Division Multiple Access

**Definition:** The **entire bandwidth is one channel shared in time**; the time is divided into **frames**, each frame into **slots**, and **each station is allotted a slot** in which it may transmit using the **full bandwidth**.

- Requires **synchronization** between stations (a sync bit/preamble in each slot).
- **Guard times** between slots handle propagation-delay differences.
- Digital in nature.

```text
Bandwidth (full)
  ^
  | [S1][S2][S3][S4] | [S1][S2][S3][S4] | ...
  +--------------------------------------------> Time
      |<---- Frame ---->|
```

**Advantages:** Efficient use of hardware/bandwidth per slot; flexible slot allocation; simple digital processing; supports dynamic slot assignment.
**Disadvantages:** Synchronization and guard-time overhead; idle slots wasted; delay = waiting for own slot; fixed number of users.
**Applications:** **GSM (2G)**, **T1/E1 digital telephony (TDM)**, **satellite (VSAT)**, IS-136.

## 13.4 CDMA — Code Division Multiple Access

**Definition:** **CDMA** is a channelization technique in which **all stations transmit simultaneously over the same frequency band and time, each station using a unique orthogonal spreading code (chip sequence)**; the receiver recovers the desired station's data by correlating (**inner product**) the composite signal with that station's code.

**Key ideas:** One channel carries **all transmissions simultaneously**; **no division of bandwidth or time**; **code** separates users (**spread spectrum**).

### Chips and Orthogonal Codes
- Each bit is represented by a sequence of **chips** (e.g., N = 4 chips per bit).
- **Sequences must be orthogonal**: inner product of two different codes = **0**; inner product of a code with itself = **N**.
- Data representation: bit **1 → +1**, bit **0 → −1**, **silence → 0**.
- Codes generated with the **Walsh table**:

```text
W1 = [ +1 ]
W2 = | +1  +1 |        W2N = | WN   WN |
     | +1  -1 |               | WN  -WN |

W4 =  c1: +1 +1 +1 +1
      c2: +1 -1 +1 -1
      c3: +1 +1 -1 -1
      c4: +1 -1 -1 +1
```

### Working (Encoding & Decoding)
**Sending:** Each station multiplies its data (+1/−1/0) by its **chip sequence** → sends.
**Channel:** All signals are **added** to form a composite sequence.
**Receiving:** Receiver multiplies the composite sequence by the chip sequence of the desired station (**inner product**) and **divides by N** → result **+1 (bit 1), −1 (bit 0), or 0 (silent)**.

### Solved Example (N = 4)
Stations 1, 2, 4 transmit; station 3 is silent. Data: **S1 = 1 (+1), S2 = 0 (−1), S4 = 1 (+1)**.

Codes: c1 = [+1,+1,+1,+1], c2 = [+1,−1,+1,−1], c3 = [+1,+1,−1,−1], c4 = [+1,−1,−1,+1].

**Composite channel signal = (+1)c1 + (−1)c2 + (+1)c4**
- Position 1: 1 − 1 + 1 = **1**
- Position 2: 1 + 1 − 1 = **1**
- Position 3: 1 − 1 − 1 = **−1**
- Position 4: 1 + 1 + 1 = **3**

Composite = **[1, 1, −1, 3]**.

**Decoding:**
- Station 1: [1,1,−1,3]·[1,1,1,1] = 1+1−1+3 = 4 → 4/4 = **+1** → bit **1** ✓
- Station 2: [1,1,−1,3]·[1,−1,1,−1] = 1−1−1−3 = −4 → **−1** → bit **0** ✓
- Station 3: [1,1,−1,3]·[1,1,−1,−1] = 1+1+1−3 = 0 → **0** → **silent** ✓
- Station 4: [1,1,−1,3]·[1,−1,−1,1] = 1−1+1+3 = 4 → **+1** → bit **1** ✓

**Advantages:** All users share the full bandwidth simultaneously; **no synchronization between users needed for sharing** (only for spreading code); soft capacity; resistance to interference, jamming and multipath; **privacy** (only code holders decode); frequency reuse factor 1.
**Disadvantages:** Complex hardware (spreading/despreading, power control); **near–far problem**; **self-interference** when codes lose orthogonality; limited by code availability.
**Applications:** **3G cellular (CDMA2000, WCDMA/UMTS)**, **GPS (CDMA codes)**, IS-95 (cdmaOne), military spread-spectrum.

## 13.5 Comparison: FDMA vs TDMA vs CDMA
| Parameter | FDMA | TDMA | CDMA |
|---|---|---|---|
| Resource divided | **Frequency** | **Time** | **Code** (spreading sequences) |
| Transmission | Simultaneous, different bands | Sequential, different slots | Simultaneous, same band & time |
| Bandwidth per user | Fixed sub-band | Full band during slot | Full band all the time |
| Synchronization | Not required | **Required** | Required for chips |
| Guard requirement | Guard bands | Guard times | None (orthogonal codes) |
| Interference | Adjacent-channel | Slot overlap | Multiple-access interference |
| Capacity | Hard limit | Hard limit | **Soft limit** |
| Hardware complexity | Low | Moderate | **High** |
| Signal type | Continuous | Bursts | Spread spectrum |
| Example | AMPS, radio/TV | GSM, T1/E1 | CDMA2000, WCDMA, GPS |

### Comparison: Channelization vs Random Access
| Parameter | Channelization | Random Access |
|---|---|---|
| Sharing | Fixed partition | Dynamic contention |
| Collisions | None | Possible |
| Efficiency for bursty traffic | Poor (idle allocations) | Better |
| Best for | Continuous traffic (voice) | Bursty data (LAN) |

## Exam Points to Remember (Channelization)
1. Three methods: **FDMA (frequency), TDMA (time), CDMA (code)**.
2. FDMA needs **guard bands**; TDMA needs **synchronization and guard times**.
3. CDMA: unique **orthogonal chip sequence**; inner product **= 0** for different, **= N** for same.
4. Bits: **1 → +1, 0 → −1, silence → 0**; Walsh table generates codes.
5. Decoding: composite · code ÷ N.
6. Applications: **FDMA – AMPS; TDMA – GSM; CDMA – 3G/GPS**.
7. Channelization gives **no collisions** but wastes resources when stations are idle.

## Potential Exam Questions
- **Very short:** Define channelization, FDMA, chip sequence; state property of orthogonal codes.
- **Short:** Compare FDMA and TDMA; explain the Walsh table.
- **Long:** Explain FDMA, TDMA, CDMA with diagrams and applications.
- **Numerical:** CDMA encoding/decoding for given data and chip sequences.
- **Comparison:** FDMA vs TDMA vs CDMA.
- **Diagram:** Frequency-time diagrams of FDMA and TDMA; CDMA encode–decode block diagram.

---

# 14. MASTER COMPARISON TABLES (QUICK REVISION)

| Concept Pair | Key Difference (one line) |
|---|---|
| Error detection vs correction | Detection: "is there an error?" (retransmit). Correction: "where is it?" and fix it (needs more redundancy, 2ʳ ≥ m + r + 1) |
| Checksum vs CRC | Checksum = one's complement **addition**; CRC = modulo-2 **division**; CRC far better for bursts |
| Simple vs 2-D parity | 2-D locates/corrects single-bit error, detects more errors |
| GBN vs SR | GBN resends the frame + all after; SR resends only the bad frame; GBN receiver window 1, SR receiver window 2ᵐ⁻¹ |
| HDLC vs PPP | Bit-oriented, bit-stuffed, reliable vs byte-oriented, authenticated, multi-protocol, unreliable |
| PAP vs CHAP | 2-way plaintext vs 3-way hashed periodic |
| Pure vs slotted ALOHA | 2Tfr, 18.4 % vs Tfr, 36.8 % |
| CSMA/CD vs CSMA/CA | Wired Ethernet detect vs Wi-Fi avoid |
| Random vs controlled access | Contention with collisions vs permission without collisions |
| FDMA vs TDMA vs CDMA | Frequency vs time vs code |
| Flow control vs congestion control | Receiver capacity vs network capacity |

---

# 15. FORMULA SHEET

| Concept | Formula |
|---|---|
| Hamming distance (detect s errors) | d_min ≥ s + 1 |
| Hamming distance (correct t errors) | d_min ≥ 2t + 1 |
| Redundant bits for single-error correction | 2ʳ ≥ m + r + 1 |
| Code rate | k / n |
| Number of bits affected by noise | Noise duration × data rate |
| Checksum | Complement of (one's complement sum of segments) |
| CRC bits appended | r = degree of generator polynomial (= divisor bits − 1) |
| Frame transmission time | Tf = Frame size / Bandwidth |
| Propagation delay | Tp = Distance / Propagation speed |
| a | Tp / Tf |
| Stop-and-Wait utilization | U = 1 / (1 + 2a); with errors (1 − p)/(1 + 2a) |
| Sliding window utilization | U = N / (1 + 2a) (N < 1 + 2a), else 1 |
| GBN max sender window | 2ᵐ − 1 |
| SR max sender/receiver window | 2ᵐ⁻¹ |
| GBN efficiency with error p | (1 − p)/(1 + 2ap) |
| SR efficiency with error p | 1 − p |
| Pure ALOHA throughput | S = G e^(−2G), max 0.184 at G = 0.5 |
| Slotted ALOHA throughput | S = G e^(−G), max 0.368 at G = 1 |
| Pure ALOHA vulnerable time | 2 Tfr |
| Slotted ALOHA vulnerable time | Tfr |
| CSMA vulnerable time | Tp |
| CSMA/CD condition | Tfr ≥ 2 Tp; min frame = Bandwidth × 2Tp |
| Ethernet slot time (10 Mbps) | 51.2 µs = 512 bits |
| Binary exponential back-off | R ∈ [0, 2ᴷ − 1]; TB = R × slot time |
| CDMA decode | (Composite · code) / N |

**Common calculation mistakes:** (1) Using bandwidth in Mbps but time in ms without converting to seconds; (2) forgetting the factor **2** in round-trip (2Tp); (3) confusing the windows of GBN and SR; (4) not wrapping the carry in checksum; (5) forgetting to append r zeros before CRC division; (6) mixing up pure and slotted ALOHA maxima.

---

# 16. MEMORY AIDS

| Topic | Mnemonic / Trick |
|---|---|
| Hamming parity positions | **1, 2, 4, 8** — "powers of two are parity" |
| Hamming syndrome | Read **C4 C2 C1** as a binary number → error position |
| Window sizes | **GBN = 2ᵐ − 1 (one less, receiver window 1)**; **SR = 2ᵐ⁻¹ (half)** — "GBN Gets Bigger, SR Splits it in half" |
| ARQ receiver behaviour | **GBN = Garbage after error (discards later frames)**; **SR = Saves them in a buffer** |
| HDLC frame types | **I**nformation = **0**, **S**upervisory = **10**, **U**nnumbered = **11** ("0-10-11" ascending) |
| HDLC S-frames | **R**R, **R**NR, **R**EJ, **S**REJ — "Ready, Not Ready, Reject, Selective Reject" |
| Bit stuffing | "Five 1s, stuff a 0" |
| HDLC vs PPP stuffing | **H**DLC = **B**it; **P**PP = **B**yte/character |
| PPP phases | **D**ead → **E**stablish → **A**uthenticate → **N**etwork → **O**pen → **T**erminate = "**D**onkeys **E**at **A**pples **N**early **O**n **T**uesdays" |
| PPP stack order | **L**CP → **A**uthentication → **N**CP = "**L**ink, **A**uthenticate, **N**etwork" |
| PAP vs CHAP | **PAP = Plain**, **CHAP = Challenge Hashed** (never sends password) |
| ALOHA throughput | Pure: **18** (e⁻²/2 ≈ 0.184); Slotted: **37** (1/e ≈ 0.368) — "slotted doubles pure" |
| CSMA/CD vs CA | **D**etect = **D**ata wire (Ethernet, wired); **A**void = **A**ir (Wi-Fi, wireless) |
| Persistence | 1-persistent = "send at once (prob. 1)"; non-persistent = "back off randomly"; p-persistent = "send with probability p" |
| Controlled access | **R**eservation, **P**olling, **T**oken = "**R**ules **P**revent **T**rouble" |
| Channelization | **F**requency, **T**ime, **C**ode = "**F**irst **T**ime **C**ode" (FDMA, TDMA, CDMA) |
| Error types | **S**ingle-bit vs **B**urst; "Burst length = first to last bad bit" |
| Error detection methods | **P**arity, **C**hecksum, **C**RC = "**P**lease **C**heck **C**arefully" |

---

# 17. CONSOLIDATED POTENTIAL EXAM QUESTIONS

> These are **practice questions** based on the unit topics, not predictions of the actual paper.

### A. Very Short Questions (1–2 marks)
1. Define error. What is a burst error?
2. Define Hamming distance. How many errors can a code with d_min = 5 detect and correct?
3. What is the parity bit? What is even parity?
4. What is a checksum? Where is it used?
5. What is CRC? Write the polynomial for 10011.
6. Define FEC.
7. Define piggybacking. What is ARQ?
8. Why is the window size in GBN 2ᵐ − 1?
9. What is the flag pattern in HDLC? What is bit stuffing?
10. Name the three types of HDLC frames.
11. What are LCP and NCP in PPP?
12. What is CHAP?
13. Define vulnerable time. What is the vulnerable time of slotted ALOHA?
14. What is NAV in CSMA/CA?
15. What is a token? What is polling?
16. Define chip sequence in CDMA.

### B. Short Answer Questions (3–5 marks)
1. Explain single-bit and burst errors with diagrams.
2. Explain the simple parity check and its limitation.
3. Explain the two-dimensional parity check with an example.
4. Explain checksum generation and verification with an example.
5. Explain the Hamming distance and its role in detection/correction.
6. Explain flow control and error control functions of the data link layer.
7. Explain lost frame and lost ACK situations in Stop-and-Wait ARQ.
8. Explain the sliding-window concept.
9. Explain HDLC frame format.
10. Explain the S-frames and U-frames of HDLC.
11. Explain bit stuffing with an example.
12. Explain the PPP frame format.
13. Explain PAP and CHAP.
14. Explain persistence methods in CSMA.
15. Explain hidden terminal problem and its solution.
16. Explain the poll and select functions.
17. Explain reservation access.
18. Explain FDMA and TDMA.

### C. Long Answer Questions (7–10 marks)
1. Explain the different error-detection techniques (parity, checksum, CRC) with examples.
2. Explain CRC generation and checking with a solved example and list properties of a good generator polynomial.
3. Explain the Hamming code with a suitable example for detecting and correcting a single-bit error.
4. Explain Stop-and-Wait ARQ with diagrams and derive its efficiency.
5. Explain Go-Back-N ARQ with sender/receiver windows and diagrams for lost-frame situation.
6. Explain Selective Repeat ARQ with diagrams and compare it with Go-Back-N.
7. Explain HDLC in detail: frame format, control field, frame types, modes and operation.
8. Explain PPP: frame format, protocols (LCP, PAP/CHAP, NCP) and the transition phase diagram.
9. Explain ALOHA (pure and slotted) with throughput derivation/formulae and vulnerable time.
10. Explain CSMA/CD with flowchart, minimum frame size and backoff.
11. Explain CSMA/CA with IFS, contention window, RTS/CTS and NAV.
12. Explain controlled-access methods (reservation, polling, token passing).
13. Explain channelization: FDMA, TDMA and CDMA with diagrams, and a CDMA numerical example.
14. Classify multiple-access protocols and explain each category.

### D. Comparison Questions
1. Error detection vs error correction.
2. Checksum vs CRC vs parity.
3. Simple parity vs two-dimensional parity.
4. Flow control vs error control (and flow vs congestion control).
5. Stop-and-Wait vs Go-Back-N vs Selective Repeat.
6. HDLC vs PPP.
7. PAP vs CHAP.
8. Pure ALOHA vs slotted ALOHA.
9. CSMA vs ALOHA.
10. CSMA/CD vs CSMA/CA.
11. 1-persistent vs non-persistent vs p-persistent.
12. Random access vs controlled access vs channelization.
13. FDMA vs TDMA vs CDMA.
14. Polling vs token passing.

### E. Diagram-Based Questions
1. Burst error showing burst length.
2. Block diagram of CRC encoder and decoder.
3. Hamming (7,4) parity bit coverage table.
4. Stop-and-Wait ARQ: normal, lost frame, lost ACK.
5. Go-Back-N: lost-frame scenario with window.
6. Selective Repeat: lost-frame scenario with NAK.
7. HDLC frame format and control field formats (I, S, U).
8. PPP frame format; PPP phase transition diagram; PPP protocol stack.
9. Classification tree of multiple-access protocols.
10. Vulnerable time in pure and slotted ALOHA.
11. CSMA/CD flowchart.
12. CSMA/CA timing diagram with RTS/CTS and NAV.
13. Poll and select exchanges; token ring.
14. FDMA/TDMA time–frequency diagrams; CDMA encode–decode.

### F. Numerical Practice
1. 8-bit data: compute even-parity bit for `1011001` and `1100110`.
2. Compute the 4-bit checksum for segments 5, 9, 12, 3, 7 and verify at the receiver.
3. CRC: data `1101011011`, generator `10011` — find the transmitted codeword.
4. Hamming (7,4): encode `1001`; flip a bit and find the syndrome.
5. Stop-and-Wait: 2 Mbps link, 2000-bit frames, 10 ms one-way delay → find utilization.
6. Minimum bits for GBN window of 20; SR window of 20 (GBN m = 5; SR m = 6).
7. Pure/slotted ALOHA: frame time 1 ms; find throughput at 250, 500 and 1000 frames/s.
8. CSMA/CD: 100 Mbps, Tp = 2.56 µs → minimum frame size (512 bits).
9. Bit-stuff `01111110111110111111`; then destuff the result.
10. CDMA: decode a composite signal [−1, −1, −3, +1] with the W4 codes.

---

## LAST-MINUTE REVISION CHECKLIST

- [ ] Definitions: error, burst error, Hamming distance, parity, checksum, CRC, FEC, ARQ, flow control, HDLC, PPP, multiple access, ALOHA, CSMA, CSMA/CD, CSMA/CA, polling, token, FDMA/TDMA/CDMA.
- [ ] Can compute: checksum, CRC remainder, Hamming code + syndrome, ARQ utilization, ALOHA throughput, CSMA/CD min frame, CDMA decoding, bit stuffing.
- [ ] Can draw: burst error, CRC block diagram, ARQ timelines (3 protocols), HDLC frame + control field, PPP frame + phases, MAC classification tree, CSMA/CD flowchart, CSMA/CA RTS/CTS, poll/select, token ring, FDMA/TDMA/CDMA figures.
- [ ] Know the **numbers**: window sizes (2ᵐ − 1, 2ᵐ⁻¹), HDLC flag 01111110, PPP flag/address/control (7E/FF/03), ALOHA 18.4 % / 36.8 %, vulnerable times (2Tfr, Tfr, Tp), Ethernet 512 bits / 64 bytes / 51.2 µs, Kmax = 15.