# UNIT–I: INTRODUCTION TO NETWORK

## Data Communication & Networking — Exam Master Notes

Your syllabus covers **\*\*Introduction to Networks, Network Types, Topologies, Protocol Layering, OSI Model, TCP/IP Protocol Suite, Physical Layer, Performance, Transmission Media, and Switching\*\***. These are also the major sections listed in your university PPT. 

I’ve structured these as **\*\*exam-writing notes\*\***, not as a PPT summary: formal definitions first, then understanding, working, diagrams, comparisons, advantages/disadvantages, and exam points.

**---**

## 📚 Table of Contents

> Click any topic to jump directly to that section.

- [UNIT–I: INTRODUCTION TO NETWORK](#uniti-introduction-to-network)
  - [Data Communication & Networking — Exam Master Notes](#data-communication-networking-exam-master-notes)
- [1. INTRODUCTION TO COMPUTER NETWORKS](#1-introduction-to-computer-networks)
  - [1.1 Data](#11-data)
    - [Standard Examination Definition](#standard-examination-definition)
    - [In Simple Words](#in-simple-words)
- [1.2 Data Communication](#12-data-communication)
    - [Standard Examination Definition](#standard-examination-definition-1)
    - [Basic Communication Model](#basic-communication-model)
    - [Components of Data Communication](#components-of-data-communication)
    - [1. Sender](#1-sender)
    - [2. Receiver](#2-receiver)
    - [3. Message](#3-message)
    - [4. Transmission Medium](#4-transmission-medium)
    - [5. Protocol](#5-protocol)
- [1.3 Characteristics of Effective Data Communication](#13-characteristics-of-effective-data-communication)
    - [1. Delivery](#1-delivery)
    - [2. Accuracy](#2-accuracy)
    - [3. Timeliness](#3-timeliness)
    - [4. Low Jitter](#4-low-jitter)
    - [Exam Memory Trick](#exam-memory-trick)
- [1.4 Data Flow](#14-data-flow)
  - [A. Simplex](#a-simplex)
  - [B. Half-Duplex](#b-half-duplex)
  - [C. Full-Duplex](#c-full-duplex)
    - [Comparison](#comparison)
- [2. COMPUTER NETWORK](#2-computer-network)
  - [Standard Examination Definition](#standard-examination-definition-2)
    - [Why Do We Need Computer Networks?](#why-do-we-need-computer-networks)
    - [Simple Example](#simple-example)
- [3. NETWORK TYPES](#3-network-types)
- [3.1 LAN — Local Area Network](#31-lan-local-area-network)
    - [Standard Examination Definition](#standard-examination-definition-3)
    - [Coverage](#coverage)
    - [Characteristics](#characteristics)
    - [Diagram](#diagram)
    - [Advantages](#advantages)
    - [Limitations](#limitations)
    - [Example](#example)
- [3.2 MAN — Metropolitan Area Network](#32-man-metropolitan-area-network)
    - [Standard Examination Definition](#standard-examination-definition-4)
    - [Diagram](#diagram-1)
    - [Characteristics](#characteristics-1)
    - [Advantages](#advantages-1)
    - [Limitations](#limitations-1)
    - [Example](#example-1)
- [3.3 WAN — Wide Area Network](#33-wan-wide-area-network)
    - [Standard Examination Definition](#standard-examination-definition-5)
    - [Diagram](#diagram-2)
    - [Characteristics](#characteristics-2)
    - [Advantages](#advantages-2)
    - [Limitations](#limitations-2)
    - [Example](#example-2)
- [LAN vs MAN vs WAN](#lan-vs-man-vs-wan)
    - [Memory Trick](#memory-trick)
- [4. NETWORK TOPOLOGIES](#4-network-topologies)
  - [Standard Examination Definition](#standard-examination-definition-6)
- [4.1 Bus Topology](#41-bus-topology)
    - [Definition](#definition)
    - [Working](#working)
    - [Advantages](#advantages-3)
    - [Disadvantages](#disadvantages)
    - [Exam Keyword](#exam-keyword)
- [4.2 Star Topology](#42-star-topology)
    - [Definition](#definition-1)
    - [Working](#working-1)
    - [Advantages](#advantages-4)
    - [Disadvantages](#disadvantages-1)
    - [Important](#important)
- [4.3 Ring Topology](#43-ring-topology)
    - [Definition](#definition-2)
    - [Working](#working-2)
    - [Advantages](#advantages-5)
    - [Disadvantages](#disadvantages-2)
- [4.4 Mesh Topology](#44-mesh-topology)
    - [Definition](#definition-3)
    - [Full Mesh](#full-mesh)
    - [Diagram](#diagram-3)
    - [Advantages](#advantages-6)
    - [Disadvantages](#disadvantages-3)
    - [Applications](#applications)
- [Topology Comparison](#topology-comparison)
- [5. PROTOCOL LAYERING](#5-protocol-layering)
  - [5.1 Protocol](#51-protocol)
    - [Standard Examination Definition](#standard-examination-definition-7)
    - [Example](#example-3)
- [5.2 What Is Protocol Layering?](#52-what-is-protocol-layering)
    - [Definition](#definition-4)
  - [Why Do We Need Layering?](#why-do-we-need-layering)
    - [Layered Approach](#layered-approach)
  - [Advantages of Protocol Layering](#advantages-of-protocol-layering)
    - [1. Simplicity](#1-simplicity)
    - [2. Modularity](#2-modularity)
    - [3. Troubleshooting](#3-troubleshooting)
    - [4. Easy Upgrades](#4-easy-upgrades)
    - [5. Standardization](#5-standardization)
    - [6. Interoperability](#6-interoperability)
- [6. OSI REFERENCE MODEL](#6-osi-reference-model)
  - [Standard Examination Definition](#standard-examination-definition-8)
- [6.1 Seven Layers of OSI](#61-seven-layers-of-osi)
    - [Mnemonic](#mnemonic)
- [6.2 Layer 7 — Application Layer](#62-layer-7-application-layer)
    - [Function](#function)
    - [Examples](#examples)
    - [Common Protocols](#common-protocols)
    - [Key Point](#key-point)
- [6.3 Layer 6 — Presentation Layer](#63-layer-6-presentation-layer)
    - [Functions](#functions)
    - [Purpose](#purpose)
    - [Example](#example-4)
- [6.4 Layer 5 — Session Layer](#64-layer-5-session-layer)
    - [Functions](#functions-1)
    - [Example Applications](#example-applications)
- [6.5 Layer 4 — Transport Layer](#65-layer-4-transport-layer)
    - [Standard Examination Definition](#standard-examination-definition-9)
    - [Major Functions](#major-functions)
    - [Protocols](#protocols)
    - [Data Unit](#data-unit)
- [6.6 Layer 3 — Network Layer](#66-layer-3-network-layer)
    - [Functions](#functions-2)
    - [Main Protocol](#main-protocol)
    - [Main Device](#main-device)
    - [Data Unit](#data-unit-1)
    - [Important Exam Point](#important-exam-point)
- [6.7 Layer 2 — Data Link Layer](#67-layer-2-data-link-layer)
    - [Functions](#functions-3)
    - [Devices](#devices)
    - [Data Unit](#data-unit-2)
    - [Important Exam Point](#important-exam-point-1)
- [6.8 Layer 1 — Physical Layer](#68-layer-1-physical-layer)
    - [Functions](#functions-4)
    - [Data Unit](#data-unit-3)
    - [Devices](#devices-1)
- [OSI Layer Summary](#osi-layer-summary)
- [6.9 Encapsulation](#69-encapsulation)
    - [At Receiver](#at-receiver)
    - [Memory](#memory)
- [7. TCP/IP PROTOCOL SUITE](#7-tcpip-protocol-suite)
  - [Standard Examination Definition](#standard-examination-definition-10)
- [7.1 Characteristics of TCP/IP](#71-characteristics-of-tcpip)
- [7.2 Four Layers of TCP/IP](#72-four-layers-of-tcpip)
- [7.3 TCP/IP Application Layer](#73-tcpip-application-layer)
    - [Function](#function-1)
    - [Protocols](#protocols-1)
    - [Examples](#examples-1)
- [7.4 TCP/IP Transport Layer](#74-tcpip-transport-layer)
    - [Functions](#functions-5)
    - [Major Protocols](#major-protocols)
- [7.5 Internet Layer](#75-internet-layer)
    - [Main Function](#main-function)
    - [Main Protocol](#main-protocol-1)
    - [Important Correction](#important-correction)
- [7.6 Network Access Layer](#76-network-access-layer)
- [OSI vs TCP/IP](#osi-vs-tcpip)
    - [Layer Mapping](#layer-mapping)
    - [Very Important](#very-important)
- [8. PHYSICAL LAYER](#8-physical-layer)
  - [Standard Examination Definition](#standard-examination-definition-11)
- [8.1 Responsibilities of Physical Layer](#81-responsibilities-of-physical-layer)
    - [1. Bit Transmission](#1-bit-transmission)
    - [2. Physical Media](#2-physical-media)
    - [3. Connectors and Interfaces](#3-connectors-and-interfaces)
    - [4. Signal Representation](#4-signal-representation)
    - [5. Transmission Rate](#5-transmission-rate)
- [8.2 Physical Layer Performance](#82-physical-layer-performance)
    - [Bandwidth](#bandwidth)
    - [Throughput](#throughput)
    - [Latency / Delay](#latency-delay)
    - [Jitter](#jitter)
    - [Bit Rate](#bit-rate)
- [8.3 Important Types of Delay](#83-important-types-of-delay)
    - [1. Processing Delay](#1-processing-delay)
    - [2. Queuing Delay](#2-queuing-delay)
    - [3. Transmission Delay](#3-transmission-delay)
    - [4. Propagation Delay](#4-propagation-delay)
    - [Important Difference](#important-difference)
- [9. TRANSMISSION MEDIA](#9-transmission-media)
- [9.1 Guided Media](#91-guided-media)
- [9.2 Twisted Pair Cable](#92-twisted-pair-cable)
    - [Definition](#definition-5)
    - [Types](#types)
    - [Applications](#applications-1)
    - [Advantages](#advantages-7)
    - [Disadvantages](#disadvantages-4)
- [9.3 Coaxial Cable](#93-coaxial-cable)
    - [Structure](#structure)
    - [Applications](#applications-2)
    - [Advantages](#advantages-8)
    - [Disadvantages](#disadvantages-5)
- [9.4 Optical Fiber](#94-optical-fiber)
    - [Definition](#definition-6)
    - [Basic Structure](#basic-structure)
    - [Working](#working-3)
    - [Types](#types-1)
    - [Advantages](#advantages-9)
    - [Disadvantages](#disadvantages-6)
- [Guided Media Comparison](#guided-media-comparison)
- [10. UNGUIDED / WIRELESS MEDIA](#10-unguided-wireless-media)
- [10.1 Radio Waves](#101-radio-waves)
    - [Characteristics](#characteristics-3)
    - [Applications](#applications-3)
    - [Advantages](#advantages-10)
    - [Limitation](#limitation)
- [10.2 Infrared](#102-infrared)
    - [Characteristics](#characteristics-4)
    - [Applications](#applications-4)
    - [Advantage](#advantage)
    - [Limitation](#limitation-1)
- [10.3 Satellite Communication](#103-satellite-communication)
    - [Definition](#definition-7)
    - [Basic Diagram](#basic-diagram)
    - [Applications](#applications-5)
    - [Advantages](#advantages-11)
    - [Limitations](#limitations-3)
- [11. SWITCHING](#11-switching)
  - [Standard Examination Definition](#standard-examination-definition-12)
    - [Main Types](#main-types)
- [11.1 Circuit Switching](#111-circuit-switching)
    - [Definition](#definition-8)
    - [Three Phases](#three-phases)
    - [Working](#working-4)
    - [Step 1 — Connection Establishment](#step-1-connection-establishment)
    - [Step 2 — Data Transfer](#step-2-data-transfer)
    - [Step 3 — Connection Termination](#step-3-connection-termination)
    - [Example](#example-5)
    - [Advantages](#advantages-12)
    - [Disadvantages](#disadvantages-7)
- [11.2 Packet Switching](#112-packet-switching)
    - [Definition](#definition-9)
    - [Diagram](#diagram-4)
    - [Working](#working-5)
    - [Example](#example-6)
    - [Advantages](#advantages-13)
    - [Disadvantages](#disadvantages-8)
- [11.3 Message Switching](#113-message-switching)
    - [Definition](#definition-10)
    - [Diagram](#diagram-5)
    - [Working](#working-6)
    - [Advantages](#advantages-14)
    - [Disadvantages](#disadvantages-9)
    - [Example](#example-7)
- [Circuit vs Packet vs Message Switching](#circuit-vs-packet-vs-message-switching)
- [⭐ MOST IMPORTANT EXAM COMPARISONS](#most-important-exam-comparisons)
  - [Hub vs Switch vs Router](#hub-vs-switch-vs-router)
- [⭐ VERY IMPORTANT: DATA UNITS](#very-important-data-units)
- [⭐ OSI vs TCP/IP — MUST MEMORIZE](#osi-vs-tcpip-must-memorize)
- [⭐ SWITCHING — MUST MEMORIZE](#switching-must-memorize)
    - [Circuit](#circuit)
    - [Packet](#packet)
    - [Message](#message)
- [⭐ TRANSMISSION MEDIA — MUST MEMORIZE](#transmission-media-must-memorize)
- [⭐ PHYSICAL LAYER — MUST MEMORIZE](#physical-layer-must-memorize)
- [⭐ 2-MARK POTENTIAL QUESTIONS](#2-mark-potential-questions)
    - [Very Short Questions](#very-short-questions)
- [⭐ 5-MARK POTENTIAL QUESTIONS](#5-mark-potential-questions)
- [⭐ 7–10 MARK POTENTIAL QUESTIONS](#710-mark-potential-questions)
    - [Q1. Explain the OSI reference model in detail.](#q1-explain-the-osi-reference-model-in-detail)
    - [Q2. Explain TCP/IP protocol architecture and compare it with OSI.](#q2-explain-tcpip-protocol-architecture-and-compare-it-with-osi)
    - [Q3. Explain different network topologies with diagrams, advantages and disadvantages.](#q3-explain-different-network-topologies-with-diagrams-advantages-and-disadvantages)
    - [Q4. Explain transmission media and classify them into guided and unguided media.](#q4-explain-transmission-media-and-classify-them-into-guided-and-unguided-media)
    - [Q5. Explain different switching techniques.](#q5-explain-different-switching-techniques)
- [🔥 LAST-NIGHT REVISION SHEET](#last-night-revision-sheet)
    - [Network](#network)
    - [Protocol](#protocol)
    - [LAN](#lan)
    - [MAN](#man)
    - [WAN](#wan)
    - [Topologies](#topologies)
    - [OSI](#osi)
    - [OSI Mnemonic](#osi-mnemonic)
    - [TCP/IP](#tcpip)
    - [Data Units](#data-units)
    - [Devices](#devices-2)
    - [Physical Media](#physical-media)
    - [Switching](#switching)
    - [Performance](#performance)
  - [⚠️ Common Exam Confusions](#common-exam-confusions)
    - [1. ISO vs OSI](#1-iso-vs-osi)
    - [2. MAC vs IP](#2-mac-vs-ip)
    - [3. Frame vs Packet](#3-frame-vs-packet)
    - [4. Switch vs Router](#4-switch-vs-router)
    - [5. Transmission vs Propagation Delay](#5-transmission-vs-propagation-delay)
    - [6. TCP vs UDP](#6-tcp-vs-udp)
    - [7. Circuit vs Packet Switching](#7-circuit-vs-packet-switching)
  - [📌 What to Draw in the Exam](#what-to-draw-in-the-exam)
    - [Highest-priority topics for tomorrow](#highest-priority-topics-for-tomorrow)

---
# 1. INTRODUCTION TO COMPUTER NETWORKS

## 1.1 Data

### Standard Examination Definition

**\*\*Data\*\*** is a collection of raw facts, symbols, numbers, text, images, audio, or video that can be processed or communicated between systems.

### In Simple Words

Data is simply the **\*\*information that needs to be communicated\*\***.

Examples:

\* Text message

\* Image

\* Audio file

\* Video

\* Number

\* Document

Your PPT defines data as a collection of raw facts, symbols, numbers, text, images, audio, or video. This appears on **\*\*Page 5\*\***.

**---**

# 1.2 Data Communication

### Standard Examination Definition

**\*\*Data communication\*\*** is the process of exchanging data between two or more devices through a transmission medium using a defined set of communication rules called protocols.

### Basic Communication Model

\`\`\`text

+----------+       Message       +----------+

\|  Sender  | ------------------> | Receiver |

+----------+     Medium/Channel  +----------+

                  ^

                  |

               Protocol

\`\`\`

### Components of Data Communication

Your PPT identifies the following components:

1\. **\*\*Sender\*\***

2\. **\*\*Receiver\*\***

3\. **\*\*Message\*\***

4\. **\*\*Transmission Medium\*\***

5\. **\*\*Protocol\*\***





### 1. Sender

The device that generates and sends the data.

**\*\*Example:\*\*** Your laptop sending an email.

### 2. Receiver

The device that receives the transmitted data.

**\*\*Example:\*\*** The recipient's smartphone.

### 3. Message

The actual information being transmitted.

Examples:

\* Text

\* Image

\* Audio

\* Video

\* File

### 4. Transmission Medium

The physical or wireless path through which data travels.

Examples:

\* Copper cable

\* Optical fiber

\* Wi-Fi

\* Mobile network

### 5. Protocol

A set of rules that controls communication between devices.

Examples:

\* HTTP

\* TCP

\* IP

\* Ethernet

**---**

# 1.3 Characteristics of Effective Data Communication

A good communication system should provide:

### 1. Delivery

Data must reach the **\*\*correct destination\*\***.

### 2. Accuracy

Data should arrive **\*\*without errors or corruption\*\***.

### 3. Timeliness

Data must arrive **\*\*within an acceptable time\*\***.

This is particularly important for real-time applications such as voice and video.

### 4. Low Jitter

**\*\*Jitter\*\*** is the variation in delay between successive packets.

For example:

\`\`\`text

Packet 1 → 10 ms

Packet 2 → 11 ms

Packet 3 → 10 ms

Packet 4 → 50 ms  ← large variation

\`\`\`

Large jitter can cause problems in:

\* Video calls

\* VoIP

\* Online gaming

\* Live streaming

These four characteristics are explicitly given in the PPT on **\*\*Page 6\*\***. 

### Exam Memory Trick

**\*\*D-A-T-J\*\***

\> **\*\*D\*\***elivery

\> **\*\*A\*\***ccuracy

\> **\*\*T\*\***imeliness

\> **\*\*J\*\***itter

**---**

# 1.4 Data Flow

Data can flow between devices in three ways.

## A. Simplex

Communication occurs in **\*\*only one direction\*\***.

\`\`\`text

Sender --------------------> Receiver

          One direction

\`\`\`

Example:

\* Keyboard → Computer

\* Television broadcasting → TV

The receiver cannot send data back through the same communication arrangement.

**---**

## B. Half-Duplex

Communication can occur in **\*\*both directions, but not simultaneously\*\***.

\`\`\`text

Device A ----------------> Device B

Device A <---------------- Device B

          one at a time

\`\`\`

Example:

**\*\*Walkie-talkie\*\***

One person speaks while the other listens.

**---**

## C. Full-Duplex

Communication occurs in **\*\*both directions simultaneously\*\***.

\`\`\`text

Device A <================> Device B

          simultaneous

\`\`\`

Example:

\* Telephone call

\* Video call

### Comparison

\| Feature                    | Simplex      | Half-Duplex   | Full-Duplex |

\| -------------------------- | ------------ | ------------- | ----------- |

\| Direction                  | One-way      | Both ways     | Both ways   |

\| Simultaneous communication | No           | No            | Yes         |

\| Example                    | TV broadcast | Walkie-talkie | Telephone   |

\| Efficiency                 | Lower        | Medium        | Higher      |

The PPT illustrates all three modes on **\*\*Page 8\*\***.

**---**

# 2. COMPUTER NETWORK

## Standard Examination Definition

A **\*\*computer network\*\*** is a collection of interconnected computers and other devices that communicate with one another and share data, resources, and services through communication links and protocols.

The PPT defines a computer network as interconnected computers/devices that communicate and share resources. It lists files, printers, Internet, storage, and applications as examples of shared resources. **\*\*Page 9\*\***.

### Why Do We Need Computer Networks?

Networks allow:

\* **\*\*Resource sharing\*\***

\* **\*\*File sharing\*\***

\* **\*\*Printer sharing\*\***

\* **\*\*Internet access\*\***

\* **\*\*Application sharing\*\***

\* **\*\*Communication\*\***

\* **\*\*Remote access\*\***

\* **\*\*Centralized services\*\***

### Simple Example

In a college:

\`\`\`text

PC 1 ----\\

PC 2 -----\\

PC 3 ------> Switch ----> Internet

PC 4 -----/

Printer --/

\`\`\`

All computers can potentially share:

\* Internet

\* Printer

\* Files

\* Network applications

**---**

# 3. NETWORK TYPES

Networks can be classified according to their **\*\*geographical coverage\*\***.

Your PPT covers:

1\. **\*\*LAN\*\***

2\. **\*\*MAN\*\***

3\. **\*\*WAN\*\***

This classification is given on **\*\*Page 23\*\***. 

**---**

# 3.1 LAN — Local Area Network

### Standard Examination Definition

A **\*\*Local Area Network (LAN)\*\*** is a computer network that interconnects devices within a relatively small geographical area such as a room, office, building, laboratory, or campus.

### Coverage

\* Room

\* Office

\* School

\* Building

### Characteristics

\* Small geographical area

\* High data-transfer speed

\* Low cost

\* Easy maintenance

\* Usually privately owned

\* High reliability

### Diagram

\`\`\`text

 PC1

  |

  |

 PC2 ---- [ SWITCH ] ---- PC3

              |

             PC4

\`\`\`

### Advantages

\* Fast communication

\* Resource sharing

\* Low installation cost

\* Easy troubleshooting

\* High data-transfer rate

### Limitations

\* Limited geographical coverage

\* Cannot directly cover distant cities

\* Expansion over large geographical areas becomes expensive/complex

### Example

A college computer laboratory connected using Ethernet.

**---**

# 3.2 MAN — Metropolitan Area Network

### Standard Examination Definition

A **\*\*Metropolitan Area Network (MAN)\*\*** is a network that interconnects multiple LANs within a city or metropolitan geographical area.

### Diagram

\`\`\`text

       LAN

        |

        |

LAN ---- MAN ---- LAN

        |

        |

       LAN

\`\`\`

### Characteristics

\* Covers a city/metropolitan area

\* Connects multiple LANs

\* Larger than LAN

\* Generally more expensive than LAN

\* Higher installation complexity

\* Often managed by telecom operators or large organizations

### Advantages

\* Covers a larger geographical area

\* Connects multiple LANs

\* High-speed communication

### Limitations

\* Expensive installation

\* More complex maintenance

\* Requires dedicated infrastructure

### Example

A network connecting branches of an organization across a city.

**---**

# 3.3 WAN — Wide Area Network

### Standard Examination Definition

A **\*\*Wide Area Network (WAN)\*\*** is a computer network that connects geographically separated networks across large areas such as countries or continents.

### Diagram

\`\`\`text

       City A

      [ LAN ]

         |

        MAN

         |

      ========

       WAN

      ========

         |

        MAN

         |

      [ LAN ]

       City B

\`\`\`

### Characteristics

\* Largest geographical coverage

\* Can connect multiple LANs and MANs

\* May use public communication infrastructure

\* Higher latency compared with LAN

\* Often involves telecommunications providers/ISPs

### Advantages

\* Global communication

\* Remote access

\* Supports cloud computing

\* Supports online education

\* Connects geographically distributed organizations

### Limitations

\* Higher cost

\* Higher latency

\* More complex management

\* Generally lower performance than a local network for the same technology

### Example

The **\*\*Internet\*\*** is the most prominent example of a global WAN.

**---**

# LAN vs MAN vs WAN

\| Parameter | LAN                   | MAN                       | WAN                      |

\| --------- | --------------------- | ------------------------- | ------------------------ |

\| Full form | Local Area Network    | Metropolitan Area Network | Wide Area Network        |

\| Coverage  | Building/limited area | City                      | Country/continent/global |

\| Size      | Small                 | Medium                    | Very large               |

\| Speed     | Generally high        | Generally high            | Depends on technology    |

\| Cost      | Low                   | Higher                    | High                     |

\| Latency   | Low                   | Moderate                  | Generally higher         |

\| Ownership | Usually private       | Organization/operator     | Multiple operators/ISPs  |

\| Example   | College lab           | City-wide network         | Internet                 |

### Memory Trick

\> **\*\*LAN → Local\*\***

\> **\*\*MAN → Metropolitan/City\*\***

\> **\*\*WAN → Wide/World\*\***

**---**

# 4. NETWORK TOPOLOGIES

## Standard Examination Definition

**\*\*Network topology\*\*** refers to the physical or logical arrangement of nodes, communication links, and networking devices within a computer network.

Topology determines:

\* How devices are connected

\* How data travels

\* Network performance

\* Reliability

\* Installation cost

These points are explicitly included in the PPT on **\*\*Page 31\*\***. 

**---**

# 4.1 Bus Topology

### Definition

In **\*\*Bus topology\*\***, all devices are connected to a single shared communication cable called the **\*\*backbone\*\***.

\`\`\`text

PC1       PC2       PC3

 |         |         |

 |         |         |

\================================

          Backbone

\`\`\`

### Working

1\. Sender places data on the common backbone.

2\. Signal travels along the backbone.

3\. All connected devices can detect the signal.

4\. The intended device accepts the data.

5\. Proper termination is required at the ends of the physical bus.

### Advantages

\* Simple installation

\* Low cost

\* Requires less cable

\* Suitable for small networks

### Disadvantages

\* Backbone failure can affect the entire network

\* Fault detection is difficult

\* Performance decreases as devices increase

\* Collisions can occur

### Exam Keyword

**\*\*Single backbone cable\*\***

**---**

# 4.2 Star Topology

### Definition

In **\*\*Star topology\*\***, each network device has a separate connection to a **\*\*central networking device\*\***, usually a switch.

\`\`\`text

             PC1

              |

              |

PC2 -------- SWITCH -------- PC3

              |

              |

             PC4

\`\`\`

### Working

1\. Sender sends data to the central switch/hub.

2\. Central device receives the data.

3\. A switch determines the appropriate destination port.

4\. Data is forwarded toward the destination.

### Advantages

\* Easy installation

\* Easy troubleshooting

\* Failure of one cable usually affects only one device

\* Easy to expand

\* Good performance with switches

### Disadvantages

\* Requires more cable

\* Higher installation cost

\* Failure of central device can disrupt the network

### Important

Modern Ethernet LANs commonly use **\*\*star or extended-star physical arrangements\*\***.

**---**

# 4.3 Ring Topology

### Definition

In **\*\*Ring topology\*\***, each device is connected to two neighboring devices, forming a closed loop.

\`\`\`text

       PC1 -------- PC2

        |            |

        |            |

       PC4 -------- PC3

\`\`\`

### Working

Data travels around the ring according to the network's access mechanism.

### Advantages

\* Predictable performance

\* Equal access can be provided

\* Traditional token-based implementations can avoid collisions

### Disadvantages

\* A link/node failure can disrupt communication in a basic ring

\* Maintenance is more difficult

\* Adding/removing devices may interrupt communication

**---**

# 4.4 Mesh Topology

### Definition

In **\*\*mesh topology\*\***, devices are interconnected through multiple communication links, providing multiple possible paths between nodes.

### Full Mesh

Every node has a direct link to every other node.

For **\*\*n\*\*** devices:

$$

\text{Number of links}=\frac{n(n-1)}{2}

$$

### Diagram

\`\`\`text

      A -------- B

      |\        /|

      | \      / |

      |  \    /  |

      |   \  /   |

      |    \\/    |

      |    /\    |

      |   /  \   |

      |  /    \  |

      | /      \ |

      C -------- D

\`\`\`

### Advantages

\* High reliability

\* Multiple paths

\* High fault tolerance

\* No single link necessarily becomes the only path

### Disadvantages

\* Very expensive

\* Requires many cables/ports

\* Complex installation

\* Difficult maintenance

### Applications

Useful where **\*\*redundancy and reliability\*\*** are extremely important.

**---**

# Topology Comparison

\| Feature           | Bus              | Star                   | Ring               | Mesh            |

\| ----------------- | ---------------- | ---------------------- | ------------------ | --------------- |

\| Structure         | Single backbone  | Central device         | Closed loop        | Multiple links  |

\| Cable requirement | Low              | Medium                 | Medium             | Very high       |

\| Cost              | Low              | Moderate               | Moderate           | Very high       |

\| Fault tolerance   | Low              | Moderate               | Low/basic ring     | High            |

\| Expansion         | Difficult        | Easy                   | More difficult     | Complex         |

\| Troubleshooting   | Difficult        | Easy                   | Moderate/difficult | Complex         |

\| Major weakness    | Backbone failure | Central device failure | Link/node failure  | Cost/complexity |

**---**

# 5. PROTOCOL LAYERING

## 5.1 Protocol

### Standard Examination Definition

A **\*\*protocol\*\*** is a formally defined set of rules and conventions that governs communication between network entities, including data format, transmission procedures, timing, addressing, error handling, and delivery.

The PPT specifically states that protocols define **\*\*data transmission, data format, timing, error handling, and data delivery\*\***. **\*\*Page 40\*\***.

### Example

When a browser communicates with a web server, several protocols can participate:

\`\`\`text

HTTP/HTTPS

     ↓

TCP

     ↓

IP

     ↓

Ethernet/Wi-Fi

\`\`\`

**---**

# 5.2 What Is Protocol Layering?

### Definition

**\*\*Protocol layering\*\*** is the organization of network communication into multiple hierarchical layers, where each layer performs a specific set of functions, uses services from the layer below, and provides services to the layer above.

The PPT introduces layering on **\*\*Pages 41–43\*\***.

**---**

## Why Do We Need Layering?

Without layering, a single networking program would have to handle:

\* Data formatting

\* Error detection

\* Addressing

\* Routing

\* Physical transmission

\* Delivery

This would make the system:

\* Very large

\* Difficult to design

\* Difficult to maintain

\* Difficult to troubleshoot

### Layered Approach

\`\`\`text

+-----------------------+

\| Application           |

+-----------------------+

\| Transport             |

+-----------------------+

\| Network/Internet      |

+-----------------------+

\| Data Link             |

+-----------------------+

\| Physical              |

+-----------------------+

\`\`\`

Each layer has a **\*\*specific responsibility\*\***.

**---**

## Advantages of Protocol Layering

### 1. Simplicity

Each layer handles a limited task.

### 2. Modularity

A layer can be modified without redesigning the complete network architecture.

### 3. Troubleshooting

Problems can be isolated to a particular layer.

### 4. Easy Upgrades

Technology at one layer can evolve independently.

### 5. Standardization

Different manufacturers can implement compatible networking systems.

### 6. Interoperability

Systems from different vendors can communicate using common protocols.

**---**

# 6. OSI REFERENCE MODEL

## Standard Examination Definition

The **\*\*Open Systems Interconnection (OSI) reference model\*\*** is a seven-layer conceptual framework developed by ISO to standardize and describe the functions involved in network communication.

**\*\*Important:\*\***

**\*\*ISO\*\*** = International Organization for Standardization

**\*\*OSI\*\*** = Open Systems Interconnection

The PPT makes this distinction on **\*\*Page 44\*\***.

**---**

# 6.1 Seven Layers of OSI

\`\`\`text

        +--------------------+

  7     | APPLICATION        |

        +--------------------+

  6     | PRESENTATION       |

        +--------------------+

  5     | SESSION            |

        +--------------------+

  4     | TRANSPORT          |

        +--------------------+

  3     | NETWORK            |

        +--------------------+

  2     | DATA LINK          |

        +--------------------+

  1     | PHYSICAL           |

        +--------------------+

\`\`\`

### Mnemonic

From **\*\*Layer 7 → Layer 1\*\***:

\> **\*\*A\*\***ll **\*\*P\*\***eople **\*\*S\*\***eem **\*\*T\*\***o **\*\*N\*\***eed **\*\*D\*\***ata **\*\*P\*\***rocessing

\* Application

\* Presentation

\* Session

\* Transport

\* Network

\* Data Link

\* Physical

**---**

# 6.2 Layer 7 — Application Layer

### Function

Provides network services directly to applications/users.

### Examples

\* Web browsing

\* Email

\* File transfer

\* Remote login

### Common Protocols

\* HTTP

\* HTTPS

\* FTP

\* SMTP

\* DNS

### Key Point

The Application layer is **\*\*not simply the application itself\*\***; it provides network-oriented services used by applications.

**---**

# 6.3 Layer 6 — Presentation Layer

### Functions

\* Data formatting

\* Translation

\* Encryption

\* Decryption

\* Compression

### Purpose

Ensures that data is represented in a form that the receiving system can interpret.

### Example

\`\`\`text

Application Data

       ↓

Formatting

       ↓

Encryption

       ↓

Transmission

\`\`\`

**---**

# 6.4 Layer 5 — Session Layer

### Functions

\* Establishes sessions

\* Maintains sessions

\* Synchronizes communication

\* Terminates sessions

### Example Applications

\* Video conferencing

\* Remote desktop

\* Long-running communication sessions

**---**

# 6.5 Layer 4 — Transport Layer

### Standard Examination Definition

The **\*\*Transport Layer\*\*** provides end-to-end communication between processes running on different hosts and is responsible for functions such as segmentation, reliability, flow control, and multiplexing using port numbers.

### Major Functions

\* Segmentation

\* Reassembly

\* End-to-end delivery

\* Error recovery

\* Flow control

\* Reliable delivery

\* Port addressing

### Protocols

**\*\*TCP\*\***

\* Connection-oriented

\* Reliable

\* Uses acknowledgements/retransmission mechanisms

**\*\*UDP\*\***

\* Connectionless

\* Lower protocol overhead

\* Does not provide TCP-style reliability

### Data Unit

Usually:

\> **\*\*Segment\*\*** for TCP

\> **\*\*Datagram\*\*** for UDP

**---**

# 6.6 Layer 3 — Network Layer

### Functions

\* Logical addressing

\* Routing

\* Path selection

\* Packet forwarding

### Main Protocol

**\*\*IP — Internet Protocol\*\***

### Main Device

**\*\*Router\*\***

\`\`\`text

Network A                  Network B

PC ---- Switch ---- Router ---- Switch ---- PC

                       ↑

                  Network Layer

\`\`\`

### Data Unit

**\*\*Packet\*\***

### Important Exam Point

\> **\*\*Router → Network Layer → IP address → Packet\*\***

**---**

# 6.7 Layer 2 — Data Link Layer

### Functions

\* Framing

\* MAC addressing

\* Error detection

\* Media access control

\* Local/link-level delivery

### Devices

\* Switch

\* Bridge

\* NIC

### Data Unit

**\*\*Frame\*\***

### Important Exam Point

\> **\*\*Switch → Data Link Layer → MAC address → Frame\*\***

**---**

# 6.8 Layer 1 — Physical Layer

### Functions

\* Transmits raw bits

\* Defines electrical/optical/radio signaling

\* Defines physical interfaces

\* Specifies characteristics of transmission media

Examples include:

\* Cables

\* Connectors

\* Signals

\* Voltages

\* Bit transmission

### Data Unit

**\*\*Bits\*\***

### Devices

\* Repeater

\* Hub

\* Physical transmission equipment

**---**

# OSI Layer Summary

\| Layer | Name         | Major Function                    | Data Unit        |

\| ----: | ------------ | --------------------------------- | ---------------- |

\|     7 | Application  | Network services                  | Data             |

\|     6 | Presentation | Formatting/encryption/compression | Data             |

\|     5 | Session      | Session management                | Data             |

\|     4 | Transport    | End-to-end delivery               | Segment/Datagram |

\|     3 | Network      | Routing/logical addressing        | Packet           |

\|     2 | Data Link    | Framing/MAC                       | Frame            |

\|     1 | Physical     | Bit transmission                  | Bits             |

The PPT gives essentially this layer-function mapping on **\*\*Pages 46–53\*\***.

**---**

# 6.9 Encapsulation

This is **\*\*very important for theory exams\*\***.

When data moves from the application toward the physical layer, each layer adds its own control information.

\`\`\`text

Application

    ↓

   DATA

    ↓

Transport

    ↓

[Transport Header | DATA]

    ↓

Network

    ↓

[Network Header | Transport Header | DATA]

    ↓

Data Link

    ↓

[Frame Header | Packet | Frame Trailer]

    ↓

Physical

    ↓

101101010101...

\`\`\`

### At Receiver

The reverse process occurs:

\> **\*\*Decapsulation\*\***

Each layer removes/interprets information intended for it.

### Memory

**\*\*Sender = Encapsulation\*\***

**\*\*Receiver = Decapsulation\*\***

**---**

# 7. TCP/IP PROTOCOL SUITE

## Standard Examination Definition

The **\*\*TCP/IP protocol suite\*\*** is a collection of standardized communication protocols used to enable communication between interconnected computer systems, forming the fundamental protocol architecture of the Internet.

TCP = **\*\*Transmission Control Protocol\*\***

IP = **\*\*Internet Protocol\*\***

The PPT identifies TCP/IP as a communication protocol suite and associates its development with the U.S. Department of Defense. **\*\*Pages 54–55\*\***.

**---**

# 7.1 Characteristics of TCP/IP

\* Open standard

\* Platform independent

\* Scalable

\* Supports reliable communication through appropriate protocols

\* Widely used on the Internet

**---**

# 7.2 Four Layers of TCP/IP

\`\`\`text

+---------------------------+

\| Application               |

+---------------------------+

\| Transport                 |

+---------------------------+

\| Internet                  |

+---------------------------+

\| Network Access            |

+---------------------------+

\`\`\`

The PPT explicitly uses this **\*\*four-layer architecture\*\*** on Page 56.

**---**

# 7.3 TCP/IP Application Layer

### Function

Provides network services to user applications.

### Protocols

\* HTTP

\* HTTPS

\* FTP

\* SMTP

\* POP3

\* IMAP

\* DNS

\* DHCP

### Examples

Web browsing:

\`\`\`text

Browser → HTTP/HTTPS → Web Server

\`\`\`

Email:

\`\`\`text

Mail Client → SMTP/IMAP/POP3 → Mail Server

\`\`\`

**---**

# 7.4 TCP/IP Transport Layer

### Functions

\* End-to-end communication

\* Segmentation

\* Error checking

\* Flow control

\* Reliable transmission where supported

\* Port addressing

### Major Protocols

#### TCP

\* Connection-oriented

\* Reliable

\* Ordered byte-stream delivery

\* Uses acknowledgements and retransmission

#### UDP

\* Connectionless

\* Lower overhead

\* No TCP-style guaranteed delivery

\* Useful where low latency or application-controlled delivery is important

**---**

# 7.5 Internet Layer

### Main Function

Provides:

\* Logical addressing

\* Routing

\* Packet forwarding

### Main Protocol

**\*\*IP\*\***

Other protocols associated with this part of the TCP/IP architecture include:

\* ICMP

\* IGMP

### Important Correction

Your PPT places **\*\*ARP\*\*** under the Internet layer. In many standard textbook mappings, ARP is treated as a protocol operating at the boundary between the **\*\*Internet/network layer and link/network-access layer\*\***, because it resolves an IP address to a link-layer address. So for an exam, follow your professor's diagram if specifically taught, but understand this distinction.

**---**

# 7.6 Network Access Layer

Responsible for communication over the local physical network.

Includes technologies such as:

\* Ethernet

\* Wi-Fi

\* Fiber-based link technologies

Functions include:

\* MAC addressing

\* Frame creation

\* Error detection

\* Physical transmission

**---**

# OSI vs TCP/IP

\| Parameter            | OSI                          | TCP/IP                                          |

\| -------------------- | ---------------------------- | ----------------------------------------------- |

\| Full form            | Open Systems Interconnection | Transmission Control Protocol/Internet Protocol |

\| Layers               | 7                            | 4 in the common model used in your PPT          |

\| Developed by         | ISO                          | DoD/ARPANET-era Internet research community     |

\| Application          | Separate                     | Combined upper layer                            |

\| Presentation         | Separate                     | Included in Application                         |

\| Session              | Separate                     | Included in Application                         |

\| Transport            | Separate                     | Separate                                        |

\| Network              | Network                      | Internet                                        |

\| Data Link + Physical | Separate                     | Network Access                                  |

\| Usage                | Reference/conceptual model   | Practical Internet protocol suite               |

### Layer Mapping

\`\`\`text

OSI                         TCP/IP

Application  ───────┐

Presentation ───────┤

Session ────────────┤──→ Application

                    │

Transport ─────────────→ Transport

                    │

Network ───────────────→ Internet

                    │

Data Link ──────────┐

Physical ───────────┴──→ Network Access

\`\`\`

### Very Important

Do **\*\*not\*\*** memorize TCP/IP as simply "OSI with fewer layers." Their purposes and historical development are different; the mapping is mainly useful for understanding corresponding functions.

**---**

# 8. PHYSICAL LAYER

## Standard Examination Definition

The **\*\*Physical Layer\*\*** is the lowest layer of the OSI model responsible for transmitting raw bits over a physical communication medium by defining the electrical, optical, radio, mechanical, and interface characteristics required for communication.

The PPT lists physical transmission and the definition of cables, connectors, voltages, and signals as major functions.

**---**

# 8.1 Responsibilities of Physical Layer

### 1. Bit Transmission

Converts bits into appropriate signals and transmits them.

\`\`\`text

Bits

10110101

   ↓

Signals

\~\~\~\~\~\~\~

   ↓

Medium

\`\`\`

### 2. Physical Media

Defines characteristics of:

\* Copper cables

\* Fiber optic cables

\* Wireless transmission

### 3. Connectors and Interfaces

Defines physical connection characteristics.

### 4. Signal Representation

Specifies how binary information is represented through physical signals.

### 5. Transmission Rate

Defines characteristics related to the transmission of bits.

**---**

# 8.2 Physical Layer Performance

Important performance concepts include:

### Bandwidth

The capacity/frequency range of a communication channel.

For digital networking, greater available bandwidth can support a higher data rate, although actual throughput also depends on other factors.

### Throughput

The **\*\*actual rate at which useful data is successfully delivered\*\***.

### Latency / Delay

The time required for data to travel from source to destination.

### Jitter

Variation in packet delay.

### Bit Rate

Number of bits transmitted per second.

$$

\text{Bit Rate}=\frac{\text{Number of bits}}{\text{Transmission time}}

$$

Unit:

**\*\*bits per second (bps)\*\***

**---**

# 8.3 Important Types of Delay

For a packet traveling through a network, total delay can involve:

### 1. Processing Delay

Time required by a device to examine/process the packet.

### 2. Queuing Delay

Time spent waiting in a queue before transmission.

### 3. Transmission Delay

Time required to push all packet bits onto the link.

$$

d\_{trans}=\frac{L}{R}

$$

Where:

\* \\(L\\) = packet length in bits

\* \\(R\\) = transmission rate in bits/second

### 4. Propagation Delay

Time required for the signal to travel through the physical medium.

$$

d\_{prop}=\frac{d}{v}

$$

Where:

\* \\(d\\) = physical distance

\* \\(v\\) = propagation speed

### Important Difference

\> **\*\*Transmission delay = putting the bits onto the link.\*\***

\> **\*\*Propagation delay = signal travelling through the link.\*\***

This is a very common exam question.

**---**

# 9. TRANSMISSION MEDIA

Transmission media are broadly classified as:

\`\`\`text

Transmission Media

       |

       +------------------+

       |                  |

    Guided            Unguided

    /Wired             /Wireless

       |                  |

  ------------       -------------

  Twisted Pair       Radio

  Coaxial            Infrared

  Optical Fiber      Satellite

                     Wi-Fi

\`\`\`

Your PPT gives this classification on **\*\*Page 62\*\***.

**---**

# 9.1 Guided Media

In **\*\*guided transmission\*\***, signals travel through a physical path.

Main types:

1\. Twisted Pair

2\. Coaxial Cable

3\. Optical Fiber

**---**

# 9.2 Twisted Pair Cable

### Definition

A **\*\*twisted-pair cable\*\*** consists of two insulated copper conductors twisted around each other to reduce electromagnetic interference and crosstalk.

### Types

#### UTP — Unshielded Twisted Pair

No additional metallic shielding around the pairs.

Advantages:

\* Low cost

\* Flexible

\* Easy installation

#### STP — Shielded Twisted Pair

Contains additional shielding to reduce electromagnetic interference.

### Applications

\* Telephone systems

\* Ethernet LANs

\* Structured cabling

### Advantages

\* Low cost

\* Easy installation

\* Flexible

\* Easy to terminate

### Disadvantages

\* More susceptible to interference than fiber

\* Limited distance compared with fiber

\* Bandwidth depends on cable category and technology

**---**

# 9.3 Coaxial Cable

### Structure

\`\`\`text

+-------------------------+

\|      Outer Jacket       |

\|  +-------------------+  |

\|  | Metallic Shield   |  |

\|  |  +-------------+  |  |

\|  |  | Insulator   |  |  |

\|  |  |  +-------+  |  |  |

\|  |  |  | Core  |  |  |  |

\|  |  |  +-------+  |  |  |

\|  |  +-------------+  |  |

\|  +-------------------+  |

+-------------------------+

\`\`\`

Main components:

1\. Central conductor

2\. Insulating layer

3\. Metallic shield

4\. Outer protective cover

### Applications

\* Cable TV

\* CCTV

\* Broadband systems

### Advantages

\* Better shielding than ordinary twisted pair

\* Higher bandwidth than traditional twisted-pair systems

\* Can support longer distances than many basic copper-pair installations

### Disadvantages

\* Bulkier

\* More expensive than basic twisted pair

\* Less convenient to install

**---**

# 9.4 Optical Fiber

### Definition

**\*\*Optical fiber\*\*** is a transmission medium that carries information as pulses of light through a thin optical fiber.

### Basic Structure

\`\`\`text

+-----------------------+

\|       Jacket          |

\|  +-----------------+  |

\|  |     Cladding    |  |

\|  |  +-----------+  |  |

\|  |  |   Core    |  |  |

\|  |  +-----------+  |  |

\|  +-----------------+  |

+-----------------------+

\`\`\`

### Working

1\. Electrical data is converted into optical signals.

2\. Light pulses travel through the fiber.

3\. The receiver detects the light.

4\. Optical signals are converted back into electrical/data signals.

### Types

#### Single-Mode Fiber (SMF)

\* Small core

\* Light travels primarily through one propagation mode

\* Suitable for long-distance/high-capacity communication

#### Multi-Mode Fiber (MMF)

\* Larger core

\* Multiple modes of light propagate

\* Common for shorter-distance applications

### Advantages

\* Very high bandwidth

\* Very high data rates

\* Long-distance transmission

\* Immune to electromagnetic interference

\* Low signal attenuation compared with many copper systems

### Disadvantages

\* Higher installation cost

\* Requires specialized installation/splicing equipment

\* More delicate than ordinary copper cabling

**---**

# Guided Media Comparison

\| Feature      | Twisted Pair  | Coaxial                        | Optical Fiber          |

\| ------------ | ------------- | ------------------------------ | ---------------------- |

\| Signal       | Electrical    | Electrical                     | Light                  |

\| Material     | Copper        | Copper + shielding             | Glass/plastic fiber    |

\| EMI immunity | Lower         | Better                         | Excellent              |

\| Bandwidth    | Moderate      | Higher than basic twisted pair | Very high              |

\| Distance     | Limited       | Moderate                       | Long                   |

\| Cost         | Low           | Medium                         | Higher                 |

\| Flexibility  | High          | Lower                          | Installation-dependent |

\| Applications | LAN/telephone | Cable TV/CCTV                  | Backbone/long-distance |

**---**

# 10. UNGUIDED / WIRELESS MEDIA

In unguided transmission, signals propagate through **\*\*air/free space\*\*** rather than a physical cable.

Your PPT includes:

\* Radio waves

\* Infrared

\* Satellite communication

**---**

# 10.1 Radio Waves

### Characteristics

\* Generally omnidirectional

\* Can propagate through some obstacles/walls depending on frequency and conditions

\* Can provide wide-area coverage

### Applications

\* Radio broadcasting

\* Television broadcasting

\* Wi-Fi

\* Wireless communication

### Advantages

\* Wide coverage

\* No physical cable required

\* Useful for mobile communication

### Limitation

Wireless signals can experience:

\* Interference

\* Attenuation

\* Obstacles

\* Security challenges

**---**

# 10.2 Infrared

### Characteristics

\* Short-range

\* Generally line-of-sight or short-range propagation

\* Does not normally penetrate walls effectively

### Applications

\* TV remote controls

\* Wireless keyboards

\* Computer mice

\* Short-range device communication

### Advantage

Less likely to interfere across rooms because walls limit propagation.

### Limitation

Short range and obstruction sensitivity.

**---**

# 10.3 Satellite Communication

### Definition

Satellite communication uses an artificial satellite as a **\*\*relay station\*\*** to receive, amplify/process where applicable, and retransmit communication signals between distant locations.

### Basic Diagram

\`\`\`text

        Satellite

        /       \\

       /         \\

      /           \\

Ground Station → Ground Station

\`\`\`

### Applications

\* GPS

\* DTH television

\* Weather forecasting

\* International communication

### Advantages

\* Very large geographical coverage

\* Useful for remote locations

\* Supports long-distance communication

### Limitations

\* High propagation delay for some satellite orbits

\* Expensive infrastructure

\* Weather/environmental effects can affect some systems

**---**

# 11. SWITCHING

## Standard Examination Definition

**\*\*Switching\*\*** is the technique used in a communication network to transfer data from a source to a destination through intermediate networking nodes by selecting or establishing a path for communication.

The PPT introduces switching as the mechanism for transferring data through intermediate network devices and identifies three techniques on **\*\*Pages 72–79\*\***.

### Main Types

1\. **\*\*Circuit Switching\*\***

2\. **\*\*Packet Switching\*\***

3\. **\*\*Message Switching\*\***

**---**

# 11.1 Circuit Switching

### Definition

**\*\*Circuit switching\*\*** establishes a dedicated communication path between the sender and receiver before data transfer begins.

### Three Phases

\`\`\`text

1\. Connection Establishment

          ↓

2\. Data Transfer

          ↓

3\. Connection Termination

\`\`\`

### Working

Suppose A wants to communicate with B:

\`\`\`text

A ---- S1 ---- S2 ---- S3 ---- B

       <---- Dedicated Path ---->

\`\`\`

### Step 1 — Connection Establishment

A dedicated path is established.

### Step 2 — Data Transfer

Data travels through the established path.

### Step 3 — Connection Termination

The path is released after communication ends.

### Example

Traditional telephone networks.

### Advantages

\* Dedicated path

\* Predictable/constant delay after setup

\* Guaranteed reserved capacity in systems designed that way

\* Suitable for continuous communication

### Disadvantages

\* Bandwidth can be wasted when the sender is idle

\* Connection setup required

\* Less efficient for bursty data

**---**

# 11.2 Packet Switching

### Definition

**\*\*Packet switching\*\*** divides a message into smaller units called **\*\*packets\*\***, which are transmitted through a shared network and reassembled at the destination.

### Diagram

\`\`\`text

Original Message

       |

       ↓

+----+----+----+----+

\| P1 | P2 | P3 | P4 |

+----+----+----+----+

       |

       ↓

     Network

    /   |   \\

   /    |    \\

 P1    P2     P3

   \    |    /

    \   |   /

      P4

       |

       ↓

 Destination

       |

       ↓

Reassembled Message

\`\`\`

### Working

1\. Original data is divided into packets.

2\. Each packet receives necessary control/addressing information.

3\. Packets are forwarded through network nodes.

4\. Packets may follow the same or different paths depending on the network.

5\. Destination receives packets.

6\. Data is reassembled where required.

### Example

The Internet uses packet-based communication.

Applications include:

\* Web browsing

\* Email

\* Video streaming

\* Cloud applications

### Advantages

\* Efficient bandwidth utilization

\* Shared network resources

\* Can reroute traffic around failures/congestion

\* Suitable for bursty data

### Disadvantages

\* Variable delay

\* Queuing can occur

\* Packets can be lost

\* Packets may arrive out of order

\* Additional processing is required

**---**

# 11.3 Message Switching

### Definition

In **\*\*message switching\*\***, the complete message is treated as one unit and is stored at an intermediate node before being forwarded to the next node.

It is therefore called **\*\*store-and-forward switching\*\***.

### Diagram

\`\`\`text

Sender

  |

  ↓

[Node 1]

  |  Store complete message

  ↓

[Node 2]

  |  Store complete message

  ↓

[Node 3]

  |

  ↓

Receiver

\`\`\`

### Working

1\. Sender transmits the complete message.

2\. Intermediate node receives the entire message.

3\. Node stores the complete message.

4\. Node forwards it to the next node when possible.

5\. Process continues until destination is reached.

### Advantages

\* No dedicated path required

\* Efficient link sharing

\* Can store messages before forwarding

### Disadvantages

\* High delay

\* Requires large storage at intermediate nodes

\* Not suitable for real-time communication

### Example

The PPT gives **\*\*email systems\*\*** as an example.

**---**

# Circuit vs Packet vs Message Switching

\| Feature               | Circuit Switching       | Packet Switching              | Message Switching               |

\| --------------------- | ----------------------- | ----------------------------- | ------------------------------- |

\| Connection setup      | Required                | Generally not dedicated setup | Not required                    |

\| Dedicated path        | Yes                     | No                            | No                              |

\| Data unit             | Continuous stream       | Packets                       | Complete message                |

\| Intermediate storage  | Limited/buffering       | Packets may be buffered       | Entire message                  |

\| Delay                 | Predictable after setup | Variable                      | High                            |

\| Bandwidth utilization | Lower when idle         | Efficient                     | Efficient                       |

\| Storage requirement   | Lower                   | Moderate                      | High                            |

\| Best suited for       | Traditional voice       | Internet/data                 | Store-and-forward applications  |

\| Example               | Traditional telephone   | Internet                      | Email/store-and-forward systems |

**---**

# ⭐ MOST IMPORTANT EXAM COMPARISONS

## Hub vs Switch vs Router

\| Feature      | Hub                 | Switch                     | Router               |

\| ------------ | ------------------- | -------------------------- | -------------------- |

\| Main layer   | Physical            | Data Link                  | Network              |

\| Address used | None for forwarding | MAC                        | IP                   |

\| Data unit    | Bits                | Frames                     | Packets              |

\| Forwarding   | Broadcast/repeat    | Selective forwarding       | Routing              |

\| Main purpose | Connect devices     | Connect devices within LAN | Connect networks     |

\| Intelligence | Low                 | Higher                     | Higher/routing-based |

The PPT includes a direct comparison of these devices around **\*\*Page 17\*\***.

**---**

# ⭐ VERY IMPORTANT: DATA UNITS

Memorize this:

\`\`\`text

Application     → DATA

Transport       → SEGMENT / DATAGRAM

Network         → PACKET

Data Link       → FRAME

Physical        → BITS

\`\`\`

This is one of the easiest marks in an OSI question.

**---**

# ⭐ OSI vs TCP/IP — MUST MEMORIZE

\`\`\`text

OSI                         TCP/IP

Application  ───────┐

Presentation ───────┤

Session ────────────┤ → Application

                    │

Transport ─────────────→ Transport

                    │

Network ───────────────→ Internet

                    │

Data Link ──────────┐

Physical ───────────┴ → Network Access

\`\`\`

**---**

# ⭐ SWITCHING — MUST MEMORIZE

### Circuit

\> **\*\*Dedicated path\*\***

### Packet

\> **\*\*Data divided into packets\*\***

### Message

\> **\*\*Complete message stored and forwarded\*\***

Memory:

\> **\*\*Circuit = Reserve\*\***

\> **\*\*Packet = Divide\*\***

\> **\*\*Message = Store\*\***

**---**

# ⭐ TRANSMISSION MEDIA — MUST MEMORIZE

\`\`\`text

                 Transmission Media

                        |

             +----------+----------+

             |                     |

          Guided                Unguided

           Wired                Wireless

             |                     |

     +-------+-------+       +-----+------+

     |       |       |       |     |      |

 Twisted  Coaxial  Fiber    Radio Infrared Satellite

 Pair

\`\`\`

**---**

# ⭐ PHYSICAL LAYER — MUST MEMORIZE

\> **\*\*Physical Layer = Transmission of raw bits over the physical medium.\*\***

Key terms:

\* Bits

\* Signals

\* Cables

\* Connectors

\* Voltages

\* Transmission medium

\* Physical interfaces

**---**

# ⭐ 2-MARK POTENTIAL QUESTIONS

### Very Short Questions

1\. Define a computer network.

2\. Define data communication.

3\. List the components of data communication.

4\. What is a protocol?

5\. Define protocol layering.

6\. What is network topology?

7\. Define LAN.

8\. Define MAN.

9\. Define WAN.

10\. What is bus topology?

11\. What is star topology?

12\. What is mesh topology?

13\. What is the OSI model?

14\. Name the seven OSI layers.

15\. What is the function of the Transport layer?

16\. What is the function of the Network layer?

17\. What is the function of the Physical layer?

18\. What is TCP/IP?

19\. Name the four TCP/IP layers.

20\. What is transmission media?

21\. What is optical fiber?

22\. Define circuit switching.

23\. Define packet switching.

24\. Define message switching.

25\. What is jitter?

26\. What is transmission delay?

27\. What is propagation delay?

**---**

# ⭐ 5-MARK POTENTIAL QUESTIONS

1\. Explain the characteristics of effective data communication.

2\. Explain simplex, half-duplex, and full-duplex communication.

3\. Explain LAN, MAN, and WAN.

4\. Explain bus topology with advantages and disadvantages.

5\. Explain star topology with diagram.

6\. Explain ring topology.

7\. Explain mesh topology.

8\. Explain the need for protocol layering.

9\. Explain the seven layers of the OSI model.

10\. Explain the TCP/IP protocol suite.

11\. Explain guided transmission media.

12\. Explain unguided transmission media.

13\. Explain twisted-pair cable.

14\. Explain coaxial cable.

15\. Explain optical fiber.

16\. Explain circuit switching.

17\. Explain packet switching.

18\. Explain message switching.

**---**

# ⭐ 7–10 MARK POTENTIAL QUESTIONS

### Q1. Explain the OSI reference model in detail.

For a 10-mark answer, draw:

\`\`\`text

Application

Presentation

Session

Transport

Network

Data Link

Physical

\`\`\`

Then explain the **\*\*function of each layer + examples + data units + devices where applicable\*\***.

**---**

### Q2. Explain TCP/IP protocol architecture and compare it with OSI.

Include:

\* Definition

\* Four TCP/IP layers

\* Functions

\* Protocol examples

\* OSI mapping

\* Comparison table

\* Diagram

**---**

### Q3. Explain different network topologies with diagrams, advantages and disadvantages.

Cover:

\* Bus

\* Star

\* Ring

\* Mesh

If your professor expects broader textbook coverage, you can additionally mention **\*\*tree and hybrid topology\*\***, but the provided PPT specifically covers the four above.

**---**

### Q4. Explain transmission media and classify them into guided and unguided media.

Include:

\`\`\`text

Guided

├── Twisted Pair

├── Coaxial

└── Optical Fiber

Unguided

├── Radio

├── Infrared

└── Satellite

\`\`\`

**---**

### Q5. Explain different switching techniques.

Cover:

\* Circuit switching

\* Packet switching

\* Message switching

\* Working

\* Advantages

\* Disadvantages

\* Comparison

**---**

# 🔥 LAST-NIGHT REVISION SHEET

If you have very little time, memorize these first:

### Network

\> Interconnected devices that communicate and share resources.

### Protocol

\> Set of rules governing communication between network entities.

### LAN

\> Small geographical area.

### MAN

\> City/metropolitan area.

### WAN

\> Large geographical area/countries/continents.

### Topologies

\> **\*\*Bus — Star — Ring — Mesh\*\***

### OSI

\> **\*\*Application → Presentation → Session → Transport → Network → Data Link → Physical\*\***

### OSI Mnemonic

\> **\*\*All People Seem To Need Data Processing\*\***

### TCP/IP

\> **\*\*Application → Transport → Internet → Network Access\*\***

### Data Units

\> **\*\*Data → Segment/Datagram → Packet → Frame → Bits\*\***

### Devices

\> **\*\*Hub → Physical\*\***

\> **\*\*Switch → Data Link\*\***

\> **\*\*Router → Network\*\***

### Physical Media

\> **\*\*Twisted Pair → Coaxial → Fiber → Radio → Infrared → Satellite\*\***

### Switching

\> **\*\*Circuit = Dedicated\*\***

\> **\*\*Packet = Divided\*\***

\> **\*\*Message = Whole message stored and forwarded\*\***

### Performance

$$

d\_{trans}=\frac{L}{R}

$$

$$

d\_{prop}=\frac{d}{v}

$$

Remember:

\> **\*\*Transmission = putting bits onto the link\*\***

\> **\*\*Propagation = bits travelling through the medium\*\***

**---**

## ⚠️ Common Exam Confusions

### 1. ISO vs OSI

**\*\*ISO\*\*** = organization

**\*\*OSI\*\*** = networking reference model

### 2. MAC vs IP

**\*\*MAC address → Data Link/local delivery\*\***

**\*\*IP address → Network layer/routing\*\***

### 3. Frame vs Packet

**\*\*Frame → Layer 2\*\***

**\*\*Packet → Layer 3\*\***

### 4. Switch vs Router

**\*\*Switch → connects devices/networks at the link level using MAC-based forwarding\*\***

**\*\*Router → connects IP networks and forwards packets using routing information\*\***

### 5. Transmission vs Propagation Delay

**\*\*Transmission:\*\*** time to place packet bits onto link.

**\*\*Propagation:\*\*** time for signal to travel through the medium.

### 6. TCP vs UDP

**\*\*TCP:\*\*** connection-oriented and reliable.

**\*\*UDP:\*\*** connectionless with lower overhead and no TCP-style reliability guarantees.

### 7. Circuit vs Packet Switching

**\*\*Circuit:\*\*** dedicated path.

**\*\*Packet:\*\*** shared network resources and packets.

**---**

## 📌 What to Draw in the Exam

For this Unit, practice these diagrams **\*\*at least once by hand\*\***:

1\. Basic data communication model

2\. Simplex / half-duplex / full-duplex

3\. LAN

4\. MAN

5\. WAN

6\. Bus topology

7\. Star topology

8\. Ring topology

9\. Mesh topology

10\. OSI 7-layer architecture

11\. TCP/IP architecture

12\. OSI ↔ TCP/IP mapping

13\. Encapsulation

14\. Twisted-pair/coaxial/fiber structure

15\. Circuit switching

16\. Packet switching

17\. Message switching

The university PPT itself uses diagrams heavily for the communication model, data-flow modes, topologies, network devices, and switching, so **\*\*diagram practice is worth prioritizing\*\*** rather than only memorizing definitions. The PPT's contents explicitly include topologies, OSI/TCP-IP, physical-layer responsibilities, performance metrics, transmission media, and switching techniques. 

### Highest-priority topics for tomorrow

**\*\*OSI Model → TCP/IP → Topologies → Switching → Transmission Media → LAN/MAN/WAN → Physical Layer/Performance\*\***

These are the areas where you can generate both short-answer and long-answer responses from the same preparation.