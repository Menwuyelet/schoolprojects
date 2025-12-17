import java.io.*;
import java.net.*;
import java.util.*;
import java.util.concurrent.*;

public class ChatServer {
    private final int port;
    private final Set<ClientHandler> clients = Collections.synchronizedSet(new HashSet<>());
    private final Map<String, ClientHandler> clientsByName = new ConcurrentHashMap<>();

    public ChatServer(int port) {
        this.port = port;
    }

    public void start() {
        System.out.println("ChatServer starting on port " + port + " ...");
        try (ServerSocket serverSocket = new ServerSocket(port)) {
            while (true) {
                Socket socket = serverSocket.accept();
                ClientHandler handler = new ClientHandler(socket);
                clients.add(handler);
                new Thread(handler).start();
            }
        } catch (IOException e) {
            System.err.println("Server exception: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private void broadcast(String message, ClientHandler sender) {
        synchronized (clients) {
            Iterator<ClientHandler> it = clients.iterator();
            while (it.hasNext()) {
                ClientHandler ch = it.next();
                if (!ch.sendMessage(message)) {
                    it.remove();
                }
            }
        }
        System.out.println(message); 
    }

    private void sendPrivate(String message, String recipient, ClientHandler sender) {
        ClientHandler ch = clientsByName.get(recipient);
        if (ch != null) {
            ch.sendMessage("[" + sender.name + " (private)]: " + message);
            sender.sendMessage("You sent a private message to " + recipient + ": " + message);
        } else {
            sender.sendMessage("User " + recipient + " not found.");
        }
    }

    private class ClientHandler implements Runnable {
        private final Socket socket;
        private String name = "Anonymous";
        private PrintWriter out;
        private BufferedReader in;

        ClientHandler(Socket socket) {
            this.socket = socket;
        }

        public boolean sendMessage(String msg) {
            if (out != null) {
                out.println(msg);
                return !out.checkError();
            }
            return false;
        }

        @Override
        public void run() {
            try {
                out = new PrintWriter(new OutputStreamWriter(socket.getOutputStream(), "UTF-8"), true);
                in = new BufferedReader(new InputStreamReader(socket.getInputStream(), "UTF-8"));

                out.println("WELCOME! Please enter your name:");
                String line = in.readLine();
                if (line != null && !line.trim().isEmpty()) {
                    name = line.trim();
                }
                clientsByName.put(name, this);
                broadcast("[" + name + "] joined the chat.", this);
                out.println(
                        "Welcome! Type /list to see users, /to <user> <msg> for private message, or just type a message for broadcast.");

                while ((line = in.readLine()) != null) {
                    line = line.trim();
                    if (line.equalsIgnoreCase("/quit") || line.equalsIgnoreCase("/exit")) {
                        break;
                    }
                    if (line.isEmpty()) {
                        continue;
                    }
                    if (line.equals("/list")) {
                        StringBuilder sb = new StringBuilder("Users: ");
                        synchronized (clientsByName) {
                            for (String user : clientsByName.keySet()) {
                                if (!user.equals(name)) {
                                    sb.append(user).append(", ");
                                }
                            }
                        }
                        if (sb.length() > 7)
                            sb.setLength(sb.length() - 2);
                        sendMessage(sb.toString());
                    } else if (line.startsWith("/to ")) {
                        String[] parts = line.substring(4).split(" ", 2);
                        if (parts.length == 2) {
                            sendPrivate(parts[1], parts[0], this);
                        } else {
                            sendMessage("Usage: /to <user> <message>");
                        }
                    } else {
                        broadcast("[" + name + "]: " + line, this);
                    }
                }
            } catch (IOException e) {
                System.err.println("Connection error with " + socket.getRemoteSocketAddress() + ": " + e.getMessage());
            } finally {
                try {
                    broadcast("[" + name + "] left the chat.", this);
                    clients.remove(this);
                    clientsByName.remove(name);
                    if (socket != null && !socket.isClosed())
                        socket.close();
                } catch (IOException ignored) {
                }
            }
        }
    }

    public static void main(String[] args) {
        int port = 12345;
        if (args.length >= 1) {
            try {
                port = Integer.parseInt(args[0]);
            } catch (NumberFormatException ignored) {
            }
        }
        ChatServer server = new ChatServer(port);
        server.start();
    }
}
