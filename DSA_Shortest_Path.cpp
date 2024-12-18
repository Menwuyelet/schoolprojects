#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <iomanip> // For std::setw and std::left
using namespace std;

// decleration of some functions 
int main();
void Connections(vector<string> cities, vector<vector<int>> Map);
void shortest_path(vector<string> cities, vector<vector<int>> Map);

// end
void close(){
    exit(0);
}

// about 
void about(vector<string> cities, vector<vector<int>> Map){
    cout << "Hy! ^_____^ \n"
            "This program was developed by School of Electrical and computing \n"
            "section 5 group 3 students. It was developed as the final project \n"
            "for our Data Structure and Algorithm course.\n"
            "We used graph data structure and Dijkstra's algorith to represent \n"
            "diffrent cities in our country and find the shortest path between two cities. \n"
            "Appart from that we added some additional functionalities to make our program \n"
            "dynamic and easy to use." 
            "Thank you for using our program. we hope you enjoyed it.\n\n"
            ;
        cout << "1, Home\n"
                "2, Find short distance again.\n"
                "3, Close the program.\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        main();
        break;
    case 2:
        shortest_path(cities, Map);
    case 3:
        close();
        break;
    }
}

// Function to find the minimum distance vertex
int findMinDistance(vector<int> dist, vector<bool> visited) {
    int minDistance = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < dist.size(); i++) {
        if (!visited[i] && dist[i] < minDistance) {
            minDistance = dist[i];// if the current distance is shortest than the initial distance it replace it
            minIndex = i;
        }
    }
    return minIndex;
}

// Dijkstra's algorithm implementation
void dijkstra_al(vector<vector<int>> Map, vector<string> cities, int start, int end) {
    int n = Map.size();
    vector<int> dist(n, INT_MAX); // Stores distances from start seting it to infinity
    vector<bool> visited(n, false); // Tracks visited nodes setting all false initialy
    vector<int> parent(n, -1); // Tracks the path

    dist[start] = 0; // Distance to itself is 0

    for (int i = 0; i < n - 1; i++) {
        int u = findMinDistance(dist, visited);
        if (u == -1) {
            break; // No more reachable nodes
        }
        visited[u] = true;// sets the visited value true for that node to track it

        for (int v = 0; v < n; v++) {
            if (Map[u][v] != -1 && !visited[v] && dist[u] + Map[u][v] < dist[v]) {
                dist[v] = dist[u] + Map[u][v];
                parent[v] = u; // Update parent to track the path
            }
        }
    }

    // If the destination is unreachable
    if (dist[end] == INT_MAX) {
        cout << "No path exists between the cities.\n";
        return;
    }

    // Display shortest distance
    cout << "Shortest distance: " << dist[end] << " km\n";

    // Display path
    cout << "Path: ";
    int current = end;
    vector<int> path;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    for (int i = path.size() - 1; i >= 0; i--) {
        if (i == 0) {
            cout << cities[path[i]]; // Display city name
        } else {// to eliminate the last "->" ch
            cout << cities[path[i]] << " -> ";
        } 
    }
    cout << "\n\n";
    cout << endl;
    cout << "1, Home\n"
            "2, Find short distance again.\n"
            "3, Close the program.\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        main();
        break;
    case 2:
        shortest_path(cities, Map);
        break;
    case 3:
        close();
        break;
    }
}

// Function to get city index
int City_Index(vector<string> cities, string city) {
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i] == city) {
            return i;
        }
    }
    return -1; // City not found
}

// Function to add a new city to the data
void Add_City(vector<string> cities, vector<vector<int>> Map) {
    // Add the new city to the list
    string city;
    cout << "City name: ";
    cin >> city;
    cities.push_back(city);

    // Get the number of existing cities
    int n = Map.size();

    // Create a new row for the new city
    vector<int> newCityRow(n + 1, -1);
    newCityRow[n] = 0; // Distance to itself is 0

    // Prompt the user for distances from the new city to existing cities
    cout << "Enter distances from " << city << " to other cities (-1 for no direct connection):\n";
    for (int i = 0; i < n; i++) {
        cout << "Distance to " << cities[i] << ": ";
        int distance;
        cin >> distance;

        // Add the distance to the new city's row
        newCityRow[i] = distance;

        // Update the corresponding column in the existing cities' rows
        Map[i].push_back(distance);
    }

// Add the new city's row to the Map
    Map.push_back(newCityRow);

    cout << "Added new city: " << city << endl;

// Display the updated adjacency matrix for confirmation
    cout << "Updated Adjacency Matrix:\n";
    int colWidth = 12;

// Print the column headers
    cout << std::setw(colWidth) << " " << std::left;
    for (int i = 0; i < cities.size(); i++) {
        cout << cities[i] << "\t";  // Print each city name as a header
    }
    cout << endl;

    for (int i = 0; i < Map.size(); i++) {
        cout << std::setw(colWidth) << std::left << cities[i];
        for (int j = 0; j < Map[i].size(); j++) {
            cout << std::setw(10) << Map[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "1, Shortest path. \n" 
            "2, Connetions of the city. \n"
            "3, Home\n"
            "4, Exit. \n";

    int choice;
    cin >> choice;
    switch (choice){
        case 1:
           shortest_path(cities, Map);
           break;
        case 2:
            Connections(cities, Map);
            break;
        case 3:
            main();
            break;
        case 4:
            close();
            break;
    }
        

}

// shortest paty
void shortest_path(vector<string> cities, vector<vector<int>> Map){
    string city1, city2;
    cout << "Enter the cities from the list: \n\n";
    for (int i = 0; i < cities.size(); i++) {
        cout << cities[i] << endl;
    }


// start 
    cout << "Enter the starting city: ";
    cin.ignore(); 
    getline(cin, city1);
    int start = City_Index(cities, city1);
    if (start == -1) {
        cout << city1 << " does not exist.\n";
        cout << "1, Enter again\n"
                "2. Add the city\n"
                "3. Exit\n";
        int choice;
        cin >> choice ;
        switch (choice)
        {
            case 1:
                cout << "Enter the start city: ";
                cin.ignore();
                getline(cin, city1);
                start = City_Index(cities, city1);
                break;
            case 2:
                Add_City(cities,Map);
                break;
            default:
                main();
                break;
        } 
        start = City_Index(cities, city1);
    }

// destination
    cout << "Enter the destination city: ";
    getline(cin, city2);
    int end = City_Index(cities, city2);
    if (end == -1) {
        cout << city2 << " does not exist.\n";

        cout << "1, Enter again \n"
                "2. Add the city\n"
                "3. Exit\n";
        int choice;
        cin >> choice ;
        switch (choice)
        {
            case 1:
                cout << "Enter the destination city: ";
                cin.ignore();
                getline(cin, city2);
                end = City_Index(cities, city2);
                break;
            case 2:
                Add_City(cities,Map);
                break;
            default:
                main();
                break;
        } 
    }
    
    cout << "\n";

    // Find the shortest path
    dijkstra_al(Map, cities, start, end);

    cout << "\n";

}

// connections
void Connections(vector<string> cities, vector<vector<int>> Map) {
    cout << "Enter the cities from the list: \n\n";
    for (int i = 0; i < cities.size(); i++) {
        cout << cities[i] << endl;
    }

    string city;
    cout << "City name? ";
    cin.ignore();
    getline(cin, city);
    int cityIndex = City_Index(cities, city);

    // Check if the city exists
    if (cityIndex == -1) {
        cout << "The city you enterd is not found!\n" << endl;
        cout << "1, Add new city.\n"
                "2, Shortest path. \n" 
                "3, Connections for other city. \n"
                "4, Home. \n";
        int choice;
        cin >> choice;
        switch (choice){
            case 1:
                Add_City(cities, Map);
            case 2:
                shortest_path(cities, Map);
                break;
            case 3:
                Connections(cities, Map);
                break;
            case 4:
                main();
                break;
        }
        
    }

    // Display the city and its connections
    cout << "\n\nConnections for " << city << " are:\n" << endl;
    bool hasConnections = false;

    for (int i = 0; i < Map[cityIndex].size(); i++) {
        if (Map[cityIndex][i] != -1 && Map[cityIndex][i] != 0) { // -1 means no connection, 0 means self
            cout << cities[i] << ": " << Map[cityIndex][i] << " km" << endl;
            hasConnections = true;
        }
    }

    cout << "\n\n";

    if (!hasConnections) {
        cout << "\n\nNo connections found for this city.\n" << endl;
    }

    cout << "1, Shortest path. \n" ;
    cout << "2, Connections for other city. \n";
    cout << "3, Home. \n";
    int choice;
    cin >> choice;
    switch (choice){
        case 1:
           shortest_path(cities, Map);
           break;
        case 2:
            Connections(cities, Map);
            break;
        case 3:
            main();
            break;
    }

}

int main() {
    // Adjacency matrix representing the map
    vector<vector<int>> Map = {
        {0, 90, 275, 515, 565, -1, 772, -1, 505},// AA
        {90, 0, 180, 360, -1, -1, 840, 424, 452},// Adama
        {275, 180, 0, -1, -1, -1, -1, -1, 248}, // Hawassa
        {515, 360, -1, 0, 1118, 1163, 995, 68, -1}, // Dire Dawa
        {565, -1, -1, 1118, 0, 180, 610, 1125, 1018}, // Bahir Dar
        {-1, -1, -1, 1163, 180, 0, 535, 1169, -1}, // Gondar
        {772, 840, -1, 995, 610, 535, 0, 1000, -1}, // Mekelle
        {-1, 424, -1, 68, 1125, 1169, 1000, 0, -1}, // Harrar
        {505, 452, 248, -1, 1018, -1, -1, -1, 0} // Arba Minch
    };
    
    // List of cities
    vector<string> cities = {
        "Addis Ababa",
        "Adama",
        "Hawassa",
        "Dire Dawa",
        "Bahir Dar",
        "Gondar",
        "Mekelle",
        "Harar",
        "Arba Minch"
    };

    cout << "Wellcome to Ethiopian cities map! \n\n" "what do you want to do? \n\n";
    cout << "1, Find the shortest path between two cities.\n" 
            "2, Add new city.\n"
            "3, See connections specific city have.\n"
            "4, About \n"
            "5, Exit\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        shortest_path(cities, Map);
        break;
    case 2:
        Add_City(cities, Map);
        break;
    case 3:
       Connections(cities, Map);
       break;
    case 4:
        about(cities, Map);
        break;
    case 5:
        close();
        break;
    }
}