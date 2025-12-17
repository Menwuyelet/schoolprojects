# ChatApp

A simple multi-client chat application built in Java using sockets and threads. Allows users to connect to a server, set a username, and exchange messages either publicly (broadcast) or privately.

## Features

- **Broadcast Messaging**: Send messages to all connected users.
- **Private Messaging**: Send private messages to specific users using `/to <username> <message>`.
- **User List**: View all connected users (excluding yourself) with `/list`.
- **Multi-threaded Server**: Handles multiple clients concurrently.

## Prerequisites

- Java 8 or higher installed on your system.

## Installation

Clone the repository:

```bash
git clone https://github.com/Menwuyelet/schoolprojects
cd schoolprojects/ChatApp
```

## Compilation

Compile the Java files:

```bash
javac ChatServer.java ChatClient.java
```

## Running the Application

### Start the Server

Run the server on a specified port (default: 12345):

```bash
java ChatServer [port]
```

Example:

```bash
java ChatServer 12345
```

The server will start listening for connections.

### Start a Client

Run the client to connect to the server:

```bash
java ChatClient
```


## Usage

1. **Connect and Set Username**:

   - Upon connecting, enter your desired username when prompted.

2. **Commands**:

   - `/list`: Displays a list of all connected users (excluding yourself).
   - `/to <username> <message>`: Sends a private message to the specified user.
   - Type any other message: Broadcasts it to all connected users.
   - `/quit` or `/exit`: Disconnects from the chat.

3. **Example Interaction**:
   - Server welcomes you and explains commands.
   - Send messages as needed.
   - Use `/list` to see other users.
   - Use `/to Mnu Hello` to send "Hello" privately to Mnu.

## Notes

- The server runs indefinitely until manually stopped.
- Clients can connect from different terminals 


- Developed as a simple demonstration of socket programming and multi-threading in Java. by **Menwuyelet Temesgen UGR/34920/16 Sec. 5**