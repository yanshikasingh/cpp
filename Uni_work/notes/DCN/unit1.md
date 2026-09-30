# DATA COMMUNICATION & NETWORKING — UNIT 1 EXAM MASTER NOTES

**Course:** Data Communication & Network (26CSEC301)  
**Module:** 1 — Introduction to Network (Overview, Topology, OSI & TCP/IP)

> **Coverage rule:** These notes are built from the complete 80-page university PDF, including information conveyed visually through diagrams/tables, plus standard networking explanations where the PDF is compressed or where a listed syllabus topic needs clarification.

---

# 0. UNIT ROADMAP

The university material covers:

1. Introduction to Computer Networks
2. Types of Networks — PAN, LAN, MAN, WAN
3. Network Topologies
4. Protocol Layering
5. OSI Reference Model
6. TCP/IP Protocol Suite
7. Physical Layer Responsibilities
8. Performance Metrics
9. Transmission Media
10. Switching Techniques

---

# 1. DATA COMMUNICATION

## 1.1 Standard Examination Definition

**Data communication** is the exchange of digital or analog information between two or more devices through a communication medium using an agreed set of rules or protocols.

## 1.2 Data

**Definition:** Data is a collection of raw facts, symbols, numbers, text, images, audio, or video that can be represented and processed by a communication system.

Examples:
- Text message
- Photograph
- Audio recording
- Video
- Numeric sensor reading

## 1.3 Communication

**Definition:** Communication is the process of exchanging information between two or more entities.

A data communication system requires:
- **Sender** — device that originates the data.
- **Receiver** — device that receives the data.
- **Message** — information being communicated.
- **Transmission medium** — physical or wireless path through which data travels.
- **Protocol** — rules governing communication.

Examples of media shown in the material:
- Copper cable
- Optical fiber
- Wi-Fi
- Mobile network

### Basic Communication Diagram

```text
+---------+       Message       +-------------------+       +----------+
| Sender  | ------------------> | Transmission      | ----> | Receiver |
|         |                      | Medium / Channel  |       |          |
+---------+                      +-------------------+       +----------+
       \____________________ Protocol Rules _______________________/
```

**How to draw in exam**
1. Draw Sender and Receiver blocks.
2. Put a line/arrow between them and label it Medium/Channel.
3. Place Message on the arrow.
4. Write Protocol above or below the communication path.

---

# 2. CHARACTERISTICS OF EFFECTIVE DATA COMMUNICATION

A good communication system should satisfy four important requirements.

## 2.1 Delivery

Data must reach the **correct destination**.

If a packet intended for Computer B reaches Computer C, delivery has failed even if the packet is otherwise error-free.

## 2.2 Accuracy

Data must arrive **without unintended errors** introduced during transmission.

## 2.3 Timeliness

Data must arrive **within the required time**. Delay is particularly important for interactive and real-time applications such as voice/video communication.

## 2.4 Low Jitter

**Jitter** is the variation in delay between consecutive packets.

Low jitter means packet arrival times are relatively consistent.

Example:

```text
Packet 1 ---- 20 ms ---->
Packet 2 ---- 21 ms ---->
Packet 3 ---- 20 ms ---->
```

has low jitter, whereas highly varying delays indicate high jitter.

### Exam Points to Remember
- Delivery = correct destination.
- Accuracy = correct data.
- Timeliness = required time.
- Jitter = variation in packet delay.
- These four characteristics appear directly in the university material.

---

# 3. DATA FLOW

Data flow describes the direction in which data can travel between communicating devices.

There are three modes:

1. Simplex
2. Half-duplex
3. Full-duplex

## 3.1 Simplex

**Definition:** In simplex communication, data flows in **only one direction**; one device is always the sender and the other is always the receiver.

```text
+----------+                    +----------+
| Sender   | -----------------> | Receiver |
+----------+     Data           +----------+
```

**Example:** Keyboard → computer is a common conceptual example; traditional broadcast systems are also one-way.

**PDF diagram:** The university slide shows a **mainframe sending data to a monitor** with one directional arrow.

### Advantages
- Simple communication design.
- No need for reverse-channel communication.

### Limitation
- Receiver cannot send data back through the same communication arrangement.

## 3.2 Half-Duplex

**Definition:** In half-duplex communication, data can travel in **both directions**, but not simultaneously.

```text
Time 1:  A --------------------> B
Time 2:  A <-------------------- B
```

**Example:** Walkie-talkie.

The university diagram explicitly shows two stations, with the direction changing between time 1 and time 2.

## 3.3 Full-Duplex

**Definition:** In full-duplex communication, data can travel in **both directions simultaneously**.

```text
A =============================> B
A <============================= B
          simultaneous
```

**Example:** Telephone/voice call.

### Comparison

| Feature | Simplex | Half-Duplex | Full-Duplex |
|---|---|---|---|
| Direction | One way | Both ways | Both ways |
| Simultaneous transmission | No | No | Yes |
| Return communication | Not possible | Possible, alternate | Possible simultaneously |
| Example | Broadcast/display | Walkie-talkie | Telephone |

**Do Not Confuse:** Half-duplex is bidirectional but alternating; full-duplex is bidirectional and simultaneous.

---

# 4. COMPUTER NETWORK

## Standard Examination Definition

A **computer network** is a collection of interconnected computers and other devices that communicate with one another and share resources using communication links and protocols.

## Resources Shared

The university material explicitly lists:
- Files
- Printers
- Internet connectivity
- Storage
- Applications

## Why Networks Are Used

- Resource sharing
- Communication
- Centralized or distributed access to data
- Internet access
- Sharing applications/services
- Remote access

### Simple Network Diagram

```text
          +---------+
          | PC / A  |
          +----+----+
               |
          +----+----+
          | Switch  |
          +--+--+--+
             |  |
        +----+  +----+
        |           |
   +----+----+ +----+----+
   | PC / B  | | Printer |
   +---------+ +---------+
```

---

# 5. NETWORK DEVICES

The university PDF uses visual slides for several devices. The important information below combines the visible diagrams with the accompanying concepts.

## 5.1 Network Interface Card (NIC)

**Definition:** A **Network Interface Card (NIC)** is a hardware interface that enables a computer/device to connect to a network and communicate over it.

The university slide describes it as a physical/data-link-layer device used to connect computers and communicate with other LAN devices.

### MAC Address

A NIC is associated with a **MAC (Media Access Control) address**, a hardware-level identifier used at the data-link layer.

The PDF image gives an example format:

```text
9C-45-3F-26-34-07
```

### Key points
- Provides network connectivity.
- Works primarily at the Physical/Data Link layers.
- Uses a MAC address for local network identification.
- May be Ethernet or wireless.

---

## 5.2 Wi-Fi Card

A **Wi-Fi card/adapter** provides wireless network connectivity to a device.

The PDF visually shows a wireless adapter and describes it as being used to connect a device to a local network wirelessly.

### Uses
- Laptop wireless networking.
- Desktop Wi-Fi connectivity.
- Wireless LAN access.

---

## 5.3 Wi-Fi Access Point (WAP)

A **Wireless Access Point (WAP)** provides wireless access to a network by allowing Wi-Fi-enabled devices to connect to the network.

The PDF's visual slide labels the coverage area as a **Wi-Fi hotspot/access point** and illustrates different coverage distances. The exact practical range varies greatly with equipment, frequency, power, interference, and environment, so the diagram's numbers should be treated as illustrative rather than universal.

### Basic diagram

```text
          Wireless devices
        /      |       \
      PC      Phone    Laptop
        \      |      /
          ))  Wi-Fi  ((
               |
        +---------------+
        | Wi-Fi Access  |
        |     Point     |
        +---------------+
               |
            Network
```

---

## 5.4 Hub

**Definition:** A **hub** is a multiport Physical Layer device that repeats an incoming signal out through its other ports.

The PDF describes it as a Physical Layer device with multiple ports for connecting computers/segments of a LAN.

### Working

If A sends data to B:

```text
             +----> B
             |
A --------> HUB -----> C
             |
             +----> D
```

A hub does not intelligently select only B. It repeats/broadcasts the signal to connected ports.

### Disadvantages shown in the PDF
- Less secure.
- Copying data to all interfaces increases unnecessary traffic.
- Can become slower and more congested.
- Switches are used to overcome these limitations.

---

## 5.5 Switch

**Definition:** A **network switch** is a multiport device that forwards frames selectively toward the appropriate destination port, primarily using MAC-address information.

The PDF contrasts a switch with a hub: a hub simply forwards/broadcasts, whereas a switch performs **filtering and forwarding**.

### Example

```text
A ----\
B -----\
C ------> [ SWITCH ] ---- D
E -----/
```

If A sends to D, the switch attempts to forward the frame toward D rather than sending it unnecessarily to every port.

### Important technical point
A switch is primarily associated with the **Data Link Layer** in the traditional OSI model, although modern multilayer switches can also perform Layer 3 functions.

---

## 5.6 Router

**Definition:** A **router** is a Layer 3 networking device that forwards packets between different networks using logical addressing and routing information.

The PDF describes the router as mainly a **Network Layer** device and shows it connecting a home network to the Internet.

```text
Home Network
 PC ----\
 Laptop -- [Router] -------- Internet
 Printer -/
```

### Main functions
- Connect different IP networks.
- Select/forward packets.
- Use logical IP addressing.
- Maintain/use routing information.

**Do Not Confuse**
- Switch → primarily forwards **frames** using MAC information within a LAN.
- Router → forwards **packets** between networks using IP information.

---

## 5.7 Bridge

**Definition:** A **bridge** is a Data Link Layer device that connects and filters traffic between LAN segments using MAC addresses.

The PDF diagram shows a bridge connecting **LAN 1, LAN 2 and LAN 3**, and lists:
- Filtering
- Forwarding
- Blocking

### Simple diagram

```text
LAN 1 --------\
               \
                [ BRIDGE ] ------ LAN 2
               /
LAN 3 --------/
```

A bridge can reduce unnecessary traffic between connected LAN segments.

---

## 5.8 Gateway

**Definition:** A **gateway** is a device or system that connects networks using different protocols, architectures, or communication environments and can perform protocol translation when required.

The PDF explicitly defines a gateway as a device used to connect **two or more dissimilar networks**.

Its visual example labels:
- Proxy server
- Firewall
- Malware protection

### Diagram

```text
Network 1
   |
   v
+--------+
|Gateway |
+--------+
   |
   v
Network 2
```

**Important:** In practical networking, the word *gateway* has broader meanings. A default gateway is commonly the router through which a host reaches other networks.

---

## 5.9 Repeater

**Definition:** A **repeater** is a Physical Layer device that regenerates/repeats a signal to extend the distance over which it can be transmitted reliably.

The PDF says repeaters are used to extend transmission so the signal can cover longer distances or be received beyond an obstruction.

```text
A ---- Switch ---- [Repeater] ---- Switch ---- B
```

### Key idea
A repeater does not make routing decisions; it works with the physical signal.

---

## 5.10 Hub vs Switch vs Router

| Parameter | Hub | Switch | Router |
|---|---|---|---|
| Primary OSI association | Physical | Data Link | Network |
| Data handled | Bits/signals | Frames | Packets |
| Main identifier | No intelligent MAC forwarding | MAC address | IP/logical address |
| Forwarding | Repeats to ports | Selective forwarding | Routes between networks |
| Network scope | Same LAN segment | LAN | Different networks |
| Collision behavior | More shared traffic | Reduced by dedicated switch ports | Separates networks |
| Intelligence | Low | Higher | Routing intelligence |
| Typical use | Legacy/simple LAN | Modern LAN | Inter-network communication |

**Note on the PDF:** Its slide has a simplified table and states that the router "stores MAC addresses." For exam accuracy, the safer distinction is: **switches learn MAC addresses; routers primarily use IP addresses and routing tables.**

---

# 6. TYPES OF COMPUTER NETWORKS

The PDF classifies networks according to **geographical coverage**.

Main types in the material:
- PAN
- LAN
- MAN
- WAN

The PDF provides detailed slides for LAN, MAN and WAN; PAN is listed in the contents but is not given a dedicated explanatory slide.

## 6.1 PAN — Personal Area Network

**Definition:** A **Personal Area Network (PAN)** is a small network centered around an individual and used to connect personal devices over a short range.

Examples:
- Smartphone ↔ smartwatch
- Phone ↔ Bluetooth earbuds
- Laptop ↔ Bluetooth mouse

Typical technologies include Bluetooth and other short-range wireless technologies.

## 6.2 LAN — Local Area Network

**Definition:** A **Local Area Network (LAN)** is a network that interconnects devices within a relatively small geographical area such as a room, office, school, or building.

### Coverage
- Room
- Office
- School
- Building

### Ownership
Usually privately owned/controlled by a single organization or user.

### Characteristics
- Small geographical area
- High data-transfer speed
- Low cost
- Easy maintenance
- Private ownership
- High reliability

### Advantages
- Fast communication.
- Resource sharing.
- Low installation cost.
- Easy troubleshooting.

### Limitations
- Limited geographical coverage.
- Not suitable for directly connecting distant cities as one small LAN.

### Example
A college computer laboratory connected through Ethernet switches is a LAN.

## 6.3 MAN — Metropolitan Area Network

**Definition:** A **Metropolitan Area Network (MAN)** interconnects multiple LANs across a city or metropolitan region.

### Characteristics
- Covers a city.
- Connects multiple LANs.
- Higher installation cost than LAN.
- Generally faster/lower latency than a WAN spanning a larger region.
- May be managed by telecom companies or large organizations.

### Advantages
- Covers a larger area than LAN.
- Connects many LANs.
- Supports high-speed communication.

### Limitations
- Expensive installation.
- More complex maintenance.
- Requires dedicated infrastructure.

### Example
A network interconnecting branches of an organization throughout a metropolitan city.

## 6.4 WAN — Wide Area Network

**Definition:** A **Wide Area Network (WAN)** interconnects networks over a large geographical region, potentially across countries or continents.

### Characteristics
- Largest geographical coverage among the types listed.
- Can connect multiple MANs and LANs.
- May use public communication networks and carrier infrastructure.
- Generally has higher latency than LAN.
- Commonly depends on telecommunications providers/ISPs.

### Advantages
- Global communication.
- Remote access.
- Supports cloud computing.
- Supports online education and distributed services.

### Limitations
- Higher cost.
- Generally higher latency than LAN.
- More complex management.
- Performance depends on wide-area infrastructure.

### Example
The Internet is a global interconnection of many networks and can be viewed as the world's largest WAN-like system.

## LAN vs MAN vs WAN vs PAN

| Parameter | PAN | LAN | MAN | WAN |
|---|---|---|---|---|
| Main idea | Personal devices | Local site | City/metropolitan area | Large geographical area |
| Coverage | Very small | Room/building/site | City | Country/continent/global |
| Typical ownership | Individual | Private organization/user | Organization/carrier | Multiple carriers/organizations |
| Typical technologies | Bluetooth | Ethernet/Wi-Fi | Metro Ethernet/fiber/carrier networks | MPLS, leased lines, Internet, carrier networks |
| Relative complexity | Low | Low–medium | Medium–high | High |
| Typical example | Phone + smartwatch | College LAN | City-wide organizational network | Internet |

---

# 7. NETWORK TOPOLOGIES

## Standard Examination Definition

**Network topology** is the physical or logical arrangement of computers, communication links, and networking devices within a network.

Topology affects:
- How devices are connected.
- How data travels.
- Network performance.
- Reliability/fault tolerance.
- Installation cost.

## Physical vs Logical Topology

**Physical topology** describes the actual physical arrangement of cables, devices and connections.

**Logical topology** describes how data flows between devices, regardless of the physical arrangement.

---

# 8. BUS TOPOLOGY

## Definition

In **bus topology**, all devices share a single main communication cable called the **backbone**.

The university diagram shows:
- Backbone cable
- Drop lines
- Taps
- Cable ends
- Stations

### Exam-drawable diagram

```text
Cable end                                      Cable end
   |                                               |
   +================================================+
        |                 |                  |
      [Tap]             [Tap]              [Tap]
        |                 |                  |
     Station A         Station B          Station C

                 Backbone cable
```

The PDF shows data traveling along the backbone in both directions.

### Working
1. A station places data on the shared backbone.
2. The signal travels along the backbone.
3. Connected devices receive/inspect the transmission.
4. The intended destination accepts the data.
5. In a shared bus, simultaneous transmissions can create collisions unless controlled.

### Advantages
- Simple installation.
- Low cost.
- Requires less cable.
- Suitable for small networks.

### Disadvantages
- Backbone failure can stop the entire network.
- Fault detection is difficult.
- Performance decreases as more devices share the medium.
- Data collisions may occur.

### How to draw
1. Draw one long horizontal backbone.
2. Add two cable-end marks.
3. Draw taps/drop lines upward.
4. Put stations at the ends of the drop lines.
5. Label the backbone.

---

# 9. STAR TOPOLOGY

## Definition

In **star topology**, every device has a separate link to a central networking device such as a switch or hub.

All communication passes through the central device.

### Diagram

```text
             [PC 1]
                |
                |
[PC 2] ---- [ SWITCH ] ---- [PC 3]
                |
                |
             [PC 4]
```

### Working
1. Sender transmits to the central device.
2. Central device receives the frame/signal.
3. It forwards the traffic toward the appropriate destination.
4. Other devices do not need to receive the traffic when a switch performs selective forwarding.

### Advantages
- Easy installation.
- Easy troubleshooting.
- Failure of one cable generally affects only its connected device.
- Good performance with switches.
- Easy expansion.

### Disadvantages
- Requires more cable than bus topology.
- Higher installation cost.
- Failure of the central device can disconnect the entire network.

### How to draw
1. Draw a switch/hub in the center.
2. Place 4–5 computers around it.
3. Draw one direct link from every computer to the center.
4. Label central device.

---

# 10. RING TOPOLOGY

## Definition

In **ring topology**, each device is connected to two neighboring devices, forming a closed loop.

The PDF says data usually travels in one direction around the ring and visually shows repeaters between stations.

### Diagram

```text
        [A] -------- [B]
         |             |
         |             |
        [D] -------- [C]
```

### Working
1. A station transmits data into the ring.
2. Data moves from node to node around the ring.
3. Each node forwards the data toward the next node.
4. The destination accepts the data.

### Advantages
- No data collisions in a controlled one-direction ring.
- Equal access for devices.
- Predictable performance.

### Disadvantages
- Failure of one cable can affect the entire ring in a basic single-ring design.
- Difficult maintenance.
- Adding/removing devices can interrupt communication.

### How to draw
1. Draw a closed loop.
2. Place stations around it.
3. Connect each station to two neighbors.
4. Add arrows showing one direction of data flow.

---

# 11. MESH TOPOLOGY

## Definition

In **mesh topology**, devices are connected through multiple direct links, and in a full mesh each device has a direct connection to every other device.

### Full Mesh Diagram

```text
       [A]-----------[B]
        |\           /|
        | \         / |
        |  \       /  |
        |   \     /   |
        |    \   /    |
       [C]-----------[D]
        \_____________/
```

A cleaner exam version is simply to connect every node to every other node.

### Key concept
Multiple paths exist between devices, so communication can continue through an alternate path when a link fails.

### Advantages
- Highly reliable.
- No single point of failure in a true full mesh.
- High fault tolerance.
- Can provide strong isolation/redundancy.

### Disadvantages
- Very expensive.
- Requires many cables/links.
- Complex installation.
- Difficult maintenance.

### Important formula — Full Mesh

For **n devices**, the number of direct links in a full mesh is:

\[
L = \frac{n(n-1)}{2}
\]

Example for 5 devices:

\[
L=\frac{5(4)}{2}=10
\]

Each device has:

\[
n-1
\]

direct links.

### How to draw
1. Draw 4–5 stations.
2. Connect every station to every other station.
3. Show multiple paths.
4. Label it "Full Mesh".

---

# 12. TOPOLOGY COMPARISON

| Feature | Bus | Star | Ring | Mesh |
|---|---|---|---|---|
| Structure | Single backbone | Central device | Closed loop | Multiple direct links |
| Cable requirement | Low | Medium/high | Medium | Very high |
| Installation | Simple | Easy | Moderate | Complex |
| Fault tolerance | Low | Medium | Low in single ring | Very high |
| Central failure | No central device; backbone failure critical | Central device failure critical | Not usually central | No single central point |
| Expansion | Becomes difficult as network grows | Easy | Can interrupt ring | Complex |
| Cost | Low | Moderate | Moderate | Very high |
| Typical strength | Low cost | Manageability | Predictable access | Reliability/redundancy |

---

# 13. PROTOCOLS AND PROTOCOL LAYERING

## 13.1 Protocol

**Standard Examination Definition:** A **protocol** is a defined set of rules and conventions that governs communication between network entities, including data format, timing, addressing, sequencing, error handling, and delivery behavior.

The PDF explicitly identifies:
- Data format
- Timing
- Error handling
- Data delivery

## 13.2 Why Protocol Layering Is Needed

If one program performed:
- Data formatting
- Error checking
- Routing
- Addressing
- Physical transmission

the program would become:
- Very large
- Difficult to design
- Difficult to maintain

### Solution
Divide communication responsibilities into **layers**.

## 13.3 Protocol Layering Definition

**Protocol layering** is the division of network communication functions into multiple layers, where each layer performs a specific task and provides services to the layer above while using services of the layer below.

Each layer:
- Performs a dedicated task.
- Communicates with adjacent layers.
- Uses lower-layer services.
- Provides services to upper layers.

## 13.4 Advantages of Layering

- **Simplicity**
- **Modularity**
- **Easy troubleshooting**
- **Easy upgrades**
- **Standardization**
- **Interoperability**

### Layering Diagram

```text
+----------------------+
| Higher-level service |
+----------------------+
          ^
          | service
+----------------------+
|      Layer N         |
+----------------------+
          ^
          |
+----------------------+
|     Layer N - 1      |
+----------------------+
          ^
          |
+----------------------+
|       Lower layer    |
+----------------------+
          |
       Medium
```

---

# 14. OSI REFERENCE MODEL

## 14.1 Definition

The **OSI (Open Systems Interconnection) reference model** is a seven-layer conceptual framework developed under ISO to standardize and describe network communication functions.

### Important clarification
The university material states that ISO was established in **1947** and that the OSI model was introduced in the **late 1970s**. Remember:

- **ISO** = International Organization for Standardization.
- **OSI** = Open Systems Interconnection.
- ISO is the organization; OSI is the networking reference model.

## 14.2 Seven OSI Layers

```text
7  Application
6  Presentation
5  Session
4  Transport
3  Network
2  Data Link
1  Physical
```

### Mnemonic

**A**ll **P**eople **S**eem **T**o **N**eed **D**ata **P**rocessing

or

**A** **P**erson **S**hould **T**ake **N**otes **D**uring **P**ractice

---

# 15. OSI LAYER 7 — APPLICATION

## Definition

The **Application Layer** provides network services and interfaces that are directly accessible to user applications.

### Functions
- Web access
- Email services
- File transfer
- Remote login

### Protocols in the PDF
- HTTP
- HTTPS
- FTP
- SMTP
- DNS

### Example
When a web browser accesses a website, application-layer protocols support the application-level communication.

---

# 16. OSI LAYER 6 — PRESENTATION

## Function

The **Presentation Layer** handles the representation and transformation of data so that communicating systems can interpret it consistently.

The PDF lists:
- Data formatting
- Encryption
- Decryption
- Compression

### Memory hook
**Presentation = how data is represented.**

---

# 17. OSI LAYER 5 — SESSION

## Function

The **Session Layer** establishes, maintains, manages and terminates communication sessions between applications.

PDF examples:
- Video conferencing
- Online gaming
- Remote desktop

### Main responsibilities
- Session establishment.
- Session maintenance.
- Session termination.
- Coordination of dialog between communicating applications.

### Memory hook
**Session = manages the conversation.**

---

# 18. OSI LAYER 4 — TRANSPORT

## Definition

The **Transport Layer** provides end-to-end communication services between applications/processes on communicating hosts.

### Functions
- Segmentation.
- End-to-end communication.
- Error recovery.
- Flow control.
- Reliable delivery when supported by the protocol.

### Protocols
- **TCP**
- **UDP**

### Segmentation

```text
Large application data
        |
        v
+-----+-----+-----+-----+
| Seg1| Seg2| Seg3| Seg4|
+-----+-----+-----+-----+
```

---

# 19. OSI LAYER 3 — NETWORK

## Definition

The **Network Layer** provides logical addressing and routing functions needed to move packets across interconnected networks.

### Functions
- Logical addressing.
- Routing.
- Path selection.
- Packet forwarding.

### Protocol
- IP

### Main device
- Router

### Memory hook
**Network Layer = routes packets between networks.**

---

# 20. OSI LAYER 2 — DATA LINK

## Definition

The **Data Link Layer** provides node-to-node delivery over a link and organizes network-layer data into frames.

### Functions
- Framing.
- Error detection.
- MAC addressing.
- Media access control.

### Devices
- Switch
- Bridge
- NIC

### Frame concept

```text
+----------+------------------+----------+
| Header   | Payload / Data   | Trailer  |
+----------+------------------+----------+
          Data Link Frame
```

---

# 21. OSI LAYER 1 — PHYSICAL

## Definition

The **Physical Layer** is responsible for transmitting raw bits over a physical communication medium and defining physical signaling characteristics.

The PDF identifies:
- Cables
- Connectors
- Voltages
- Signals

Devices/examples:
- Hub
- Repeater
- Cables

---

# 22. OSI LAYER SUMMARY

| Layer | Number | Main function | Typical examples |
|---|---:|---|---|
| Application | 7 | User/network services | HTTP, FTP, SMTP, DNS |
| Presentation | 6 | Formatting, encryption, compression | Data representation |
| Session | 5 | Session management | Application sessions |
| Transport | 4 | End-to-end delivery, segmentation, flow/error control | TCP, UDP |
| Network | 3 | Logical addressing and routing | IP, router |
| Data Link | 2 | Frames, MAC, local delivery | Ethernet, switch, bridge, NIC |
| Physical | 1 | Bits/signals/media | Cables, hub, repeater |

### OSI PDU memory

```text
Application / Presentation / Session -> Data
Transport                         -> Segment (TCP) / Datagram (UDP)
Network                           -> Packet
Data Link                         -> Frame
Physical                          -> Bits
```

---

# 23. OSI ENCAPSULATION

When data travels down the stack, each layer may add its own control information.

```text
Sender

Application:
        DATA
          |
Transport:
      [TH][DATA]       -> Segment
          |
Network:
   [NH][TH][DATA]      -> Packet
          |
Data Link:
[DH][NH][TH][DATA][DT] -> Frame
          |
Physical:
       101101...
          |
        Medium
```

At the receiver, the process is reversed (**decapsulation**).

---

# 24. TCP/IP PROTOCOL SUITE

## Definition

The **TCP/IP protocol suite** is a collection of networking protocols used to enable communication across interconnected networks and forms the fundamental protocol architecture of the Internet.

The PDF states:
- TCP = Transmission Control Protocol.
- IP = Internet Protocol.
- Developed by the U.S. Department of Defense (DoD).

## Characteristics
- Open standard.
- Platform independent.
- Scalable.
- Reliable as a suite (although not every TCP/IP protocol provides reliability).
- Used on the Internet.

---

# 25. TCP/IP FOUR-LAYER ARCHITECTURE

```text
+-----------------------+
|      Application      |
+-----------------------+
|       Transport       |
+-----------------------+
|        Internet       |
+-----------------------+
|     Network Access    |
+-----------------------+
```

## Layer mapping with OSI

| TCP/IP | Rough OSI correspondence |
|---|---|
| Application | OSI 7 + 6 + 5 |
| Transport | OSI 4 |
| Internet | OSI 3 |
| Network Access | OSI 2 + 1 |

---

# 26. TCP/IP APPLICATION LAYER

## Function
Provides services directly to user applications.

### Protocols in the PDF
- HTTP
- HTTPS
- FTP
- SMTP
- POP3
- IMAP
- DNS
- DHCP

### Examples
- HTTP/HTTPS → web communication.
- FTP → file transfer.
- SMTP → sending email.
- POP3/IMAP → email retrieval/access.
- DNS → name resolution.
- DHCP → automatic IP configuration.

---

# 27. TCP/IP TRANSPORT LAYER

## Function
Provides end-to-end communication between applications/processes.

The PDF lists:
- Segmentation.
- Error checking.
- Flow control.
- Reliable transmission.
- Port addressing.

### Port addressing
Ports identify application/process endpoints on a host.

```text
IP address = identifies host/interface
Port       = identifies application/service endpoint
```

## TCP
- Reliable.
- Connection-oriented.
- Uses sequence numbers, acknowledgements, retransmission, flow control and congestion control.

## UDP
- Connectionless.
- Lower-overhead than TCP.
- Does not provide TCP-style reliable delivery.

### TCP vs UDP

| Feature | TCP | UDP |
|---|---|---|
| Connection | Connection-oriented | Connectionless |
| Reliability | Reliable delivery mechanisms | No TCP-style reliability |
| Ordering | Ordered byte-stream delivery | No ordered byte-stream guarantee |
| Retransmission | Yes | No |
| Flow control | Yes | No TCP flow control |
| Congestion control | Yes | No TCP congestion control |
| Overhead | Higher | Lower |
| Typical use | Web/HTTPS, file transfer, many application protocols | DNS queries, real-time applications, gaming, etc. |

---

# 28. TCP/IP INTERNET LAYER

## Function
Responsible for logical addressing and routing.

### Protocols listed in the PDF
- IP
- ICMP
- ARP
- IGMP

### Functions
- Assign/use IP addresses.
- Find/select paths.
- Route packets.

---

# 29. TCP/IP NETWORK ACCESS LAYER

## Function
Handles communication over the local/physical network.

The PDF includes:
- Ethernet
- Wi-Fi
- Fiber

### Functions
- MAC addressing.
- Frame creation.
- Error detection.
- Physical transmission.

It combines responsibilities commonly associated with OSI Data Link + Physical layers.

---

# 30. OSI vs TCP/IP

| Parameter | OSI Model | TCP/IP Suite |
|---|---|---|
| Nature | Reference model | Protocol suite + architecture |
| Layers | 7 | 4 in the university material |
| Upper layers | Application, Presentation, Session | Combined Application |
| Transport | Transport | Transport |
| Network | Network | Internet |
| Lower layers | Data Link + Physical | Network Access |
| Development | ISO framework | Internet/DoD networking development |
| Typical role | Conceptual teaching/reference | Practical Internet architecture |
| Examples | Layer functions | TCP, IP, HTTP, DNS, Ethernet |

### Do Not Confuse
- **OSI is a model**, not a single protocol.
- **TCP/IP is a protocol suite/architecture**, not merely a seven-layer model.
- TCP is not the same thing as the TCP/IP suite.

---

# 31. PHYSICAL LAYER RESPONSIBILITIES

The Physical Layer is responsible for the actual transmission of raw bits over a medium.

## Major responsibilities

### 1. Bit transmission
Converts bit streams into physical signals and transports them.

### 2. Physical characteristics
Defines aspects such as connectors, interfaces and cable characteristics.

### 3. Signaling
Defines how 0 and 1 are represented using electrical, optical or radio signals.

### 4. Data rate
Works with the rate at which bits/symbols are transmitted.

### 5. Transmission medium
Supports communication through copper, fiber and wireless media.

### 6. Synchronization
Sender and receiver need timing/synchronization to interpret transmitted bits correctly.

### Key exam statement
**Physical Layer = transmission of raw bits through the physical medium.**

---

# 32. PERFORMANCE METRICS

The contents page lists **Performance Metrics**, although the PDF does not provide a separate detailed performance-metrics slide. For a complete exam answer, know the following standard metrics.

## 32.1 Bandwidth

**Definition:** Bandwidth is the capacity/range of a communication channel, commonly expressed in **Hz** for analog channel bandwidth.

\[
B=f_{max}-f_{min}
\]

where:
- \(B\) = bandwidth in Hz
- \(f_{max}\) = maximum frequency
- \(f_{min}\) = minimum frequency

In networking, "bandwidth" is also commonly used informally for maximum data capacity in bit/s. Do not confuse this usage with frequency bandwidth.

## 32.2 Bit Rate / Data Rate

\[
\text{Bit Rate}=\frac{\text{Number of bits transmitted}}{\text{Time}}
\]

Unit: **bit/s (bps)**.

## 32.3 Transmission Delay

\[
T_{trans}=\frac{L}{R}
\]

where \(L\) is packet length in bits and \(R\) is link rate in bit/s.

## 32.4 Propagation Delay

\[
T_{prop}=\frac{d}{v}
\]

where \(d\) is distance and \(v\) is signal propagation speed.

## 32.5 Processing Delay
Time needed to examine/process a packet, check errors and determine forwarding action.

## 32.6 Queuing Delay
Time a packet waits in a queue before transmission.

## 32.7 Total Delay

\[
T_{total}=T_{processing}+T_{queuing}+T_{transmission}+T_{propagation}
\]

## 32.8 Throughput
The actual rate at which useful data is successfully delivered.

## 32.9 Latency
The end-to-end time taken for data to travel from source to destination.

## 32.10 Jitter
Variation in packet delay.

## 32.11 Packet Loss
Failure of packets to reach their destination.

### Performance summary

| Metric | Meaning | Typical unit |
|---|---|---|
| Bandwidth | Channel capacity/frequency range | Hz or informal bit/s |
| Bit rate | Bits transmitted per second | bps |
| Throughput | Actual successful delivery rate | bps |
| Transmission delay | Time to place bits on link | s |
| Propagation delay | Signal travel time | s |
| Processing delay | Device processing time | s |
| Queuing delay | Waiting time in queue | s |
| Latency | Overall/end-to-end delay | ms/s |
| Jitter | Delay variation | ms |
| Packet loss | Packets not delivered | % |

---

# 33. TRANSMISSION MEDIA

Two broad categories:

```text
Transmission Media
       |
       +-------------------+
       |                   |
    Guided             Unguided
    / Wired            / Wireless
       |                   |
  Twisted pair         Radio/Wi-Fi
  Coaxial              Bluetooth
  Optical fiber        Satellite
                       Infrared
```

---

# 34. GUIDED MEDIA

**Definition:** Guided media transmit signals through a physical path such as copper cable or optical fiber.

Types:
1. Twisted pair.
2. Coaxial cable.
3. Optical fiber.

---

# 35. TWISTED PAIR CABLE

## Definition
A **twisted-pair cable** consists of two insulated copper wires twisted together to reduce electromagnetic interference and crosstalk.

### Types
- UTP — Unshielded Twisted Pair
- STP — Shielded Twisted Pair

### Uses
- Telephone lines.
- LAN.
- Ethernet.

### Advantages
- Low cost.
- Easy installation.
- Flexible.

### Disadvantages
- Limited bandwidth compared with higher-capacity media.
- Shorter distance.
- Electromagnetic interference.

---

# 36. COAXIAL CABLE

## Definition
A **coaxial cable** consists of a central conductor, insulating layer, metallic shield and outer cover.

### Structure

```text
+----------------------------------+
|        Outer protective cover    |
|  +----------------------------+  |
|  |      Metallic shield       |  |
|  |  +----------------------+  |  |
|  |  | Insulating layer     |  |  |
|  |  |   +--------------+   |  |  |
|  |  |   | Central       |  |  |  |
|  |  |   | conductor     |  |  |  |
|  |  |   +--------------+   |  |  |
|  |  +----------------------+  |  |
|  +----------------------------+  |
+----------------------------------+
```

### Applications
- Cable TV.
- CCTV.
- Broadband Internet.

### Advantages
- Better shielding.
- Higher bandwidth than basic twisted pair in many traditional uses.
- Longer distance than basic twisted pair in comparable contexts.

### Disadvantages
- More expensive.
- Bulkier.

---

# 37. OPTICAL FIBER

## Definition
**Optical fiber** is a guided transmission medium that carries information as pulses of light through a glass or plastic fiber.

### Types
- Single Mode Fiber (SMF).
- Multi Mode Fiber (MMF).

### Basic structure

```text
+----------------------+
| Protective jacket    |
|  +----------------+  |
|  | Cladding       |  |
|  |  +----------+  |  |
|  |  | Core     |  |  |
|  |  | light -> |  |  |
|  |  +----------+  |  |
|  +----------------+  |
+----------------------+
```

### Advantages
- Very high speed.
- Huge bandwidth.
- Long-distance communication.
- Immune to electromagnetic interference.

### Disadvantages
- Costly.
- Difficult installation.
- Fragile.

---

# 38. GUIDED MEDIA COMPARISON

| Feature | Twisted Pair | Coaxial | Optical Fiber |
|---|---|---|---|
| Signal | Electrical | Electrical | Light |
| Main material | Copper | Copper + shield | Glass/plastic |
| Cost | Low | Medium | Higher |
| EMI immunity | Low/moderate | Better shielding | Excellent |
| Bandwidth | Lower | Higher than basic twisted pair | Very high |
| Distance | Shorter | Longer than basic twisted pair | Long |
| Flexibility | High | Lower | Installation can be delicate |
| Typical use | LAN/telephone | Cable TV/CCTV/broadband | High-capacity/backbone links |

---

# 39. UNGUIDED MEDIA

**Definition:** Unguided or wireless media transmit electromagnetic signals through free space rather than along a physical cable.

The PDF covers:
- Radio waves
- Wi-Fi
- Bluetooth
- Satellite
- Infrared

## 39.1 Radio Waves

### Characteristics
- Omnidirectional in many radio systems.
- Can pass through walls depending on frequency/material.
- Can provide long-distance coverage.

### Applications
- FM radio.
- Television broadcasting.
- Wi-Fi.

### Advantages
- Wide coverage.
- Low installation cost compared with laying physical cable in some scenarios.

## 39.2 Wi-Fi
Wi-Fi is a family of wireless LAN technologies based primarily on IEEE 802.11 standards.

It allows devices to communicate wirelessly over a local network using radio signals.

## 39.3 Bluetooth
Bluetooth is a short-range wireless technology designed for personal-area connectivity between nearby devices.

Examples:
- Phone ↔ earbuds.
- Laptop ↔ mouse.
- Phone ↔ keyboard.

---

# 40. INFRARED

The PDF states:
- Short-range communication.
- Cannot pass through walls.

### Applications
- TV remote.
- Wireless keyboard.
- Mouse.

### Key characteristic
Infrared generally requires a suitable line-of-sight or unobstructed path for many common applications.

---

# 41. SATELLITE COMMUNICATION

## Definition
Satellite communication uses a satellite as a relay station to receive and retransmit communication signals between distant locations.

### Diagram

```text
Ground Station A
       |
       | uplink
       v
   +---------+
   |Satellite|
   +---------+
       |
       | downlink
       v
Ground Station B
```

### Applications
- GPS.
- DTH TV.
- Weather forecasting.
- International communication.

### Advantages
- Very wide geographical coverage.
- Useful where terrestrial infrastructure is difficult.

### Limitations
- Significant propagation delay, especially for geostationary satellite systems.
- Expensive infrastructure.
- Some satellite links are affected by weather/frequency conditions.

---

# 42. GUIDED vs UNGUIDED MEDIA

| Parameter | Guided | Unguided |
|---|---|---|
| Path | Physical medium | Free space |
| Examples | Twisted pair, coaxial, fiber | Radio, Wi-Fi, satellite, infrared |
| Mobility | Lower | Higher |
| Installation | Requires cabling | Often easier over open areas |
| EMI/interference | Depends on medium; fiber highly immune | Wireless interference possible |
| Security | Physical access can be controlled | Signals can propagate outside intended area |
| Typical use | Wired LAN/backbone | Wi-Fi, mobile/wireless, broadcasting |

---

# 43. SWITCHING

## Standard Examination Definition

**Switching** is the technique used to transfer data from a source to a destination through intermediate networking nodes by selecting or using communication paths through the network.

Types:
1. Circuit switching.
2. Packet switching.
3. Message switching.

---

# 44. CIRCUIT SWITCHING

## Definition
**Circuit switching** establishes a dedicated communication path between source and destination before data transfer begins.

### Three phases

1. **Connection establishment**
2. **Data transfer**
3. **Connection termination**

### Diagram

```text
A ======= Node 1 ======= Node 2 ======= B
        <--- dedicated circuit --->
```

### Example
Traditional telephone call.

### Advantages
- Guaranteed/reserved bandwidth during the connection.
- Relatively constant/predictable delay after setup.

### Disadvantages
- Bandwidth wasted when the circuit is idle.
- Setup delay.

---

# 45. PACKET SWITCHING

## Definition
**Packet switching** divides data into smaller units called packets, which are transmitted through a shared network and processed/reassembled at the destination.

### Diagram

```text
Message
   |
   v
+----+----+----+
| P1 | P2 | P3 |
+----+----+----+
  |    |    |
  v    v    v
Network paths
 \    / \    /
  \  /   \  /
   Destination
   Reassemble
```

### Working
1. Source divides data into packets.
2. Each packet receives required control information.
3. Network nodes forward packets.
4. In datagram packet switching, packets may use different paths.
5. Destination receives packets.
6. Data is reassembled/processed.

### Examples from the PDF
- Internet communication.
- Email.
- Web browsing.
- Video streaming.

### Advantages
- Efficient bandwidth utilization.
- Shared link utilization.
- Fault tolerance/resilience.
- Suitable for bursty computer data.

### Disadvantages
- Variable delay.
- Packet loss is possible.
- Congestion can affect performance.

---

# 46. MESSAGE SWITCHING

## Definition
**Message switching** transmits the complete message as one unit; intermediate nodes store the complete message before forwarding it.

It is called **store-and-forward switching**.

### Diagram

```text
A ----> [Node 1] ----> [Node 2] ----> B
         STORE            STORE
        message          message
        then forward     then forward
```

### Working
1. Source sends the complete message.
2. Node receives and stores the complete message.
3. Node forwards it when the next link is available.
4. Process repeats until destination.

### Example
The PDF gives email systems.

### Advantages
- No dedicated path.
- Efficient use of links.

### Disadvantages
- High delay.
- Large storage requirement.

---

# 47. SWITCHING COMPARISON

| Feature | Circuit Switching | Packet Switching | Message Switching |
|---|---|---|---|
| Connection setup | Yes | No dedicated setup | No |
| Dedicated path | Yes | No | No |
| Basic data unit | Continuous stream over circuit | Packets | Complete message |
| Store-and-forward | Not defining principle | Packets may be buffered | Entire message |
| Delay | Low/steady after setup | Variable | High |
| Bandwidth utilization | Poor when idle | Good | Good |
| Storage requirement | Lower | Packet buffering | High |
| Typical use | Voice calls | Internet | Store-and-forward applications |

**Accuracy note:** The PDF's final comparison table places "Email, video streaming" under message switching. Modern Internet email and video streaming are **packet-switched** applications; for a technically accurate university answer, use packet switching for modern Internet services and mention the slide's simplified comparison only if your teacher expects its exact wording.

---

# 48. HIGH-VALUE "DO NOT CONFUSE" SECTION

## Hub vs Switch
- Hub repeats/broadcasts signals.
- Switch selectively forwards frames using MAC information.

## Switch vs Router
- Switch → primarily Layer 2, frames, MAC addresses.
- Router → Layer 3, packets, IP addresses, routing.

## MAC vs IP
- MAC = link/local hardware-level address.
- IP = logical network-layer address.

## Transmission Delay vs Propagation Delay
- Transmission delay = time to put all bits onto the link.
- Propagation delay = time for signal to travel through the medium.

## Bandwidth vs Throughput
- Bandwidth = capacity.
- Throughput = actual achieved delivery rate.

## Latency vs Jitter
- Latency = delay.
- Jitter = variation in delay.

## Circuit vs Packet Switching
- Circuit = dedicated path.
- Packet = shared network, packets.

## Message vs Packet Switching
- Message switching stores the entire message.
- Packet switching divides data into smaller packets.

## OSI vs TCP/IP
- OSI = seven-layer reference model.
- TCP/IP = practical protocol suite/architecture.

---

# 49. IMPORTANT EXAM DIAGRAMS — QUICK REVISION SHEET

## Communication model
```text
Sender -> Message -> Medium/Channel -> Receiver
             <---- Protocols ---->
```

## Simplex
```text
A ----------------> B
```

## Half-duplex
```text
A ----------------> B
A <---------------- B
(one direction at a time)
```

## Full-duplex
```text
A =================> B
A <================= B
(simultaneously)
```

## Star
```text
       A
       |
B --- SWITCH --- C
       |
       D
```

## Ring
```text
A ---- B
|      |
D ---- C
```

## Mesh
```text
A-------B
|\     /|
| \   / |
|  \ /  |
|  / \  |
| /   \ |
C-------D
```

## OSI
```text
7 Application
6 Presentation
5 Session
4 Transport
3 Network
2 Data Link
1 Physical
```

## TCP/IP
```text
Application
Transport
Internet
Network Access
```

## Transmission media
```text
Media
 |
 +-- Guided: Twisted Pair / Coaxial / Fiber
 |
 +-- Unguided: Radio / Wi-Fi / Bluetooth / Satellite / Infrared
```

## Circuit switching
```text
Setup -> Data Transfer -> Termination
```

## Packet switching
```text
Message -> P1,P2,P3 -> Network -> Reassemble
```

---

# 50. FORMULA SHEET

### Bandwidth
\[
B=f_{max}-f_{min}
\]

### Bit rate
\[
R=\frac{\text{bits transmitted}}{\text{time}}
\]

### Transmission delay
\[
T_{trans}=\frac{L}{R}
\]

### Propagation delay
\[
T_{prop}=\frac{d}{v}
\]

### Total delay
\[
T_{total}=T_{processing}+T_{queuing}+T_{transmission}+T_{propagation}
\]

### Full mesh links
\[
L=\frac{n(n-1)}{2}
\]

---

# 51. SOLVED NUMERICALS

## Numerical 1 — Transmission Delay

A 12,000-bit packet is transmitted over a 3 Mbps link.

\[
T_{trans}=\frac{12000}{3,000,000}=0.004s=4ms
\]

**Answer: 4 ms**

## Numerical 2 — Propagation Delay

A signal travels 2,000 km through a medium at \(2\times10^8\) m/s.

\[
2000\,km=2,000,000\,m
\]

\[
T_{prop}=\frac{2,000,000}{2\times10^8}
=0.01s=10ms
\]

**Answer: 10 ms**

## Numerical 3 — Full Mesh

For 8 devices:

\[
L=\frac{8(8-1)}{2}=28
\]

**Answer: 28 links**

---

# 52. POTENTIAL EXAM QUESTIONS

## Very Short Questions — 1–2 Marks

1. Define data communication.
2. What is a computer network?
3. List the components of data communication.
4. Define protocol.
5. What is protocol layering?
6. What is a LAN?
7. What is a MAN?
8. What is a WAN?
9. Define network topology.
10. What is a hub?
11. What is a switch?
12. What is a router?
13. What is a bridge?
14. What is a gateway?
15. What is a repeater?
16. What is a NIC?
17. What is a MAC address?
18. Define simplex communication.
19. Define half-duplex communication.
20. Define full-duplex communication.
21. List the seven OSI layers.
22. What is TCP/IP?
23. What is the function of the Physical Layer?
24. Define transmission delay.
25. Define propagation delay.
26. Define jitter.
27. What is optical fiber?
28. What is circuit switching?
29. What is packet switching?
30. What is message switching?

## Short Answer — 3–5 Marks

1. Explain the characteristics of effective data communication.
2. Explain simplex, half-duplex and full-duplex with diagrams.
3. Explain LAN and its characteristics.
4. Explain MAN and its advantages/limitations.
5. Explain WAN and its advantages/limitations.
6. Explain bus topology with diagram.
7. Explain star topology with diagram.
8. Explain ring topology with diagram.
9. Explain mesh topology with diagram.
10. Explain why protocol layering is needed.
11. Explain the advantages of protocol layering.
12. Explain the functions of the Data Link Layer.
13. Explain the functions of the Network Layer.
14. Explain the functions of the Transport Layer.
15. Explain TCP/IP architecture.
16. Explain guided and unguided transmission media.
17. Explain twisted-pair cable.
18. Explain coaxial cable.
19. Explain optical fiber.
20. Explain circuit switching.
21. Explain packet switching.
22. Explain message switching.

## Long Answer — 7–10 Marks

1. Explain the OSI reference model with all seven layers, functions and a diagram.
2. Explain TCP/IP architecture and compare it with OSI.
3. Explain network topologies with diagrams, advantages and disadvantages.
4. Explain network devices and differentiate hub, switch and router.
5. Explain transmission media and compare guided and unguided media.
6. Explain switching techniques and compare circuit, packet and message switching.
7. Explain protocol layering, its need, advantages and relationship with OSI.
8. Explain data communication components and data-flow modes.

## Comparison Questions

1. PAN vs LAN vs MAN vs WAN.
2. Simplex vs half-duplex vs full-duplex.
3. Bus vs star vs ring vs mesh.
4. Hub vs switch.
5. Switch vs router.
6. OSI vs TCP/IP.
7. TCP vs UDP.
8. Guided vs unguided media.
9. Twisted pair vs coaxial vs optical fiber.
10. Circuit vs packet vs message switching.
11. Transmission delay vs propagation delay.
12. Bandwidth vs throughput.
13. Latency vs jitter.

## Diagram-Based Questions

1. Draw and explain the seven-layer OSI model.
2. Draw TCP/IP four-layer architecture.
3. Draw star topology.
4. Draw bus topology.
5. Draw ring topology.
6. Draw mesh topology.
7. Draw simplex/half-duplex/full-duplex communication.
8. Draw the basic communication model.
9. Draw a circuit-switched connection.
10. Draw packet switching and packet reassembly.
11. Draw the structure of a coaxial cable.
12. Draw a simple optical-fiber structure.
13. Draw satellite communication as a relay.

---

# 53. 10-MARK ANSWER BLUEPRINTS

## A. OSI Model
1. Introduction.
2. Formal definition.
3. Seven-layer diagram.
4. Explain Layer 7 → Layer 1.
5. Functions/protocols/devices.
6. Encapsulation.
7. Summary table.
8. Importance of layering.
9. Conclusion.

## B. Network Topologies
1. Define topology.
2. Physical/logical topology.
3. Bus + diagram.
4. Star + diagram.
5. Ring + diagram.
6. Mesh + diagram.
7. Advantages/disadvantages.
8. Comparison.
9. Conclusion.

## C. Switching
1. Define switching.
2. Circuit switching + three phases.
3. Packet switching + packet flow.
4. Message switching + store-and-forward.
5. Comparison.
6. Examples.
7. Advantages/disadvantages.
8. Conclusion.

---

# 54. EXAM POINTS TO REMEMBER — LAST-MINUTE REVISION

1. **Data communication = exchange of information between communicating entities.**
2. Five basic components: **sender, receiver, message, medium, protocol**.
3. Effective communication: **delivery, accuracy, timeliness, low jitter**.
4. Simplex = one-way; half-duplex = two-way but alternating; full-duplex = two-way simultaneous.
5. LAN = small area; MAN = city; WAN = large geographical region.
6. Topologies in the PDF: **bus, star, ring, mesh**.
7. Bus uses one backbone; star uses a central device; ring forms a loop; mesh provides multiple direct paths.
8. Protocol = rules for communication.
9. Layering provides **simplicity, modularity, troubleshooting, upgrades, standardization, interoperability**.
10. OSI has **7 layers**.
11. OSI order top-down: **Application, Presentation, Session, Transport, Network, Data Link, Physical**.
12. Transport = end-to-end delivery; Network = routing; Data Link = framing/MAC; Physical = bits/signals.
13. TCP/IP in the PDF has **4 layers**: Application, Transport, Internet, Network Access.
14. TCP = reliable, connection-oriented; UDP = connectionless and lower overhead.
15. IP handles logical addressing and packet forwarding/routing functions.
16. Guided media = twisted pair, coaxial, fiber.
17. Unguided media = radio, Wi-Fi, Bluetooth, satellite, infrared.
18. Fiber uses **light** and is highly resistant to electromagnetic interference.
19. Circuit switching has **setup → transfer → termination**.
20. Packet switching divides data into packets.
21. Message switching stores and forwards the **entire message**.
22. Transmission delay = \(L/R\).
23. Propagation delay = \(d/v\).
24. Jitter = variation in delay.
25. Full mesh links = \(n(n-1)/2\).

---

# 55. COMMON EXAM MISTAKES

- Do not write that **OSI is a protocol**; it is a reference model.
- Do not write that **TCP/IP has seven layers**; the university PDF uses four layers.
- Do not confuse **MAC address** with **IP address**.
- Do not say a basic hub performs intelligent destination-based forwarding.
- Do not confuse a switch with a router.
- Do not confuse transmission delay with propagation delay.
- Do not define bandwidth only as "speed"; explain capacity/frequency range appropriately.
- Do not call jitter the same thing as latency.
- Do not say packet switching always gives every packet the same delay.
- Do not say optical fiber transmits electrical signals; it carries information as light.
- In a basic bus topology, remember the shared backbone and collision issue.
- In star topology, distinguish failure of an individual link from failure of the central device.
- In a basic ring, one link failure can disrupt communication unless redundancy/bypass exists.
- For a true full mesh, use \(n(n-1)/2\) links.
- Do not reproduce the PDF's simplified "router stores MAC addresses" statement as your main technical distinction; use IP/routing for routers and MAC/frames for switches.

---

# 56. ULTRA-SHORT MEMORY MAP

```text
DATA COMMUNICATION
        |
        +-- Components
        |   Sender / Receiver / Message / Medium / Protocol
        |
        +-- Data Flow
        |   Simplex / Half / Full
        |
        +-- NETWORK
            |
            +-- Devices
            |   NIC / Hub / Switch / Router / Bridge
            |   Gateway / Repeater / WAP
            |
            +-- Types
            |   PAN / LAN / MAN / WAN
            |
            +-- Topologies
            |   Bus / Star / Ring / Mesh
            |
            +-- Layering
            |   OSI (7)
            |   TCP/IP (4)
            |
            +-- Physical
            |   Guided / Unguided
            |
            +-- Performance
            |   Bandwidth / Throughput / Delay / Jitter
            |
            +-- Switching
                Circuit / Packet / Message
```

---

# 57. FINAL 30-SECOND RECALL

**Communication**  
→ Sender + Receiver + Message + Medium + Protocol

**Good communication**  
→ Delivery + Accuracy + Timeliness + Low Jitter

**Data flow**  
→ Simplex / Half / Full

**Network types**  
→ PAN / LAN / MAN / WAN

**Topology**  
→ Bus / Star / Ring / Mesh

**OSI**  
→ 7 layers: Application, Presentation, Session, Transport, Network, Data Link, Physical

**TCP/IP**  
→ Application / Transport / Internet / Network Access

**Physical**  
→ Bits + signals + media

**Media**  
→ Twisted pair / Coax / Fiber + Radio / Wi-Fi / Bluetooth / Satellite / Infrared

**Switching**  
→ Circuit / Packet / Message

**Core formulas**  
→ \(T_{trans}=L/R\), \(T_{prop}=d/v\), \(L_{mesh}=n(n-1)/2\)

---

## SOURCE COVERAGE NOTE

The uploaded university PDF is an 80-page Unit 1 presentation. The notes preserve the major concepts, lists, diagrams, tables, examples and device/topology illustrations across the document. Where a topic is listed in the contents but not developed in a dedicated slide (notably detailed performance metrics and PAN), standard networking material has been added and explicitly identified as supporting knowledge. Visual information from the PDF pages was inspected rather than relying only on the extracted text layer.
