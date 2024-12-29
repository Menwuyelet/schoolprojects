#include <iostream>
#include <vector>
#include <climits> // for setting the initial distance to infinity
#include <string>
#include <iomanip> // For std::setw and std::left presenting the data in a tabular form
using namespace std;
bool start = true; // value to condition the wellcome mesage to be displayed only once
bool cond = false; // value to condition the do while loop i used in choices output

// decleration of some functions 
int main();
void Connections(vector<string> cities, vector<vector<int>> Map);
void shortest_path(vector<string> &cities, vector<vector<int>> &Map);
// Put them here so that they dose not initialize every time the main is called.
// Adjacency matrix representing the map created by 2d vector 
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

// List of cities in the map
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
//

// function to exit the program
void close(){
    cout << "Thank you for using our program. come back again soon. \n";
    exit(0);
}

// about 
void about(){
    cout << "\nHy! ^__^ \n"
            "This program was developed by 'Menwuyelet Temesgen' student of School of Electrical Enginering and Computing section 5 group 3. It was developed as an assignment for \n"
            "Data Structure and Algorithm course. I used adjecency matrix to represent Ethiopian capital cities and used Dijkstra's algorith to find the shortest path between \n"
            "diffrent cities in the data. Additionaly i developed a system that allows the user to interact with the data by entering new cities and their related distance from \n"
            "existing cities to the data and perform tasks such as finding the shortest path between two cities and to see the direct connections a city has.\n"
            "I used vector to form the adjecency matrix to allow dynamicaly increasing the size of the graph. I really hope that you have a greate time using the program. Thank you! \n\n" 
            ;
    int choice;
    do{
        cond = false;
        cout << "1, Home\n"
                "2, Close the program.\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n\n";
            cout << "=====================================================================================================\n";
            main();
            break;
        case 2:
            cout << "\n\n";
            cout << "=====================================================================================================\n";
            close();
            break;
        default:
            cond = true;    
            cout << "\n\n";
            cout << "=====================================================================================================\n";
            cout << "\nPlease chose from the availeble actions.\n";
            break;
        }
    }while (cond);
}

// Function to find the minimum distance vertex
int findMinDistance(vector<int> dist, vector<bool> visited) {
    int minDistance = INT_MAX; // seting infinity to compare 
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
void dijkstra_al(vector<vector<int>> &Map, vector<string> &cities, int start, int end) {
    int n = Map.size(); // gets the size of the map
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
        }
        else {// to eliminate the last "->" ch
            cout << cities[path[i]] << " -> ";
        } 
    }
    cout << "\n\n";
    int choice;
    do{
        cond = false;
        cout << "1, Home\n"
                "2, Find short path again.\n"
                "3, Close the program.\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n\n";
            cout << "=====================================================================================================\n";
            main();
            break;
        case 2:
            cout << "\n\n";
            cout << "=====================================================================================================\n";
            shortest_path(cities, Map);
            break;
        case 3:
            cout << "\n\n";
            cout << "=====================================================================================================\n";
            close();
            break;
        default:
            cond = true;    
            cout << "\n\n";
            cout << "Please choose from the availeble options! \n\n";
            break;
        }
    }while (cond);
}

// Function to get city index
int City_Index(vector<string> &cities, string &city) {
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i] == city) {
            return i;
        }
    }
    return -1; // City not found
}

// Function to add a new city to the data
void Add_City(vector<string>& cities, vector<vector<int>>& Map)// allow the modification of the cities and the map the valuse must be passed by refrence not their copy
{
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

        // Update the corresponding column in the existing cities rows
        Map[i].push_back(distance);
    }

// Add the new city's row to the Map
    Map.push_back(newCityRow);

    cout << "Added new city: " << city << endl;

// Display the updated adjacency matrix for confirmation
    cout << "The updated Data: \n";
    int colWidth = 12;

// Print the column headers
    cout << std::setw(colWidth) << " " << std::left;
    for (int i = 0; i < cities.size(); i++) {
        cout << cities[i] << "\t";  // Print each city name as a header
    }
    cout << "\n";
    for (int i = 0; i < Map.size(); i++) {
        cout << std::setw(colWidth) << std::left << cities[i];
        for (int j = 0; j < Map[i].size(); j++) {
            cout << std::setw(10) << Map[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "1, Shortest path. \n" 
            "2, Connetions of a city. \n"
            "3, Home\n"
            "4, Exit. \n";
    int choice;
    do{
        cond = false;
        cout << "Choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "\n\n";
                cout << "=====================================================================================================\n";
                shortest_path(cities, Map);
                break;
            case 2:
                cout << "\n\n";
                cout << "=====================================================================================================\n";
                Connections(cities, Map);
                break;
            case 3:
                cout << "\n\n";
                cout << "=====================================================================================================\n";
                main();
                break;
            case 4:
                cout << "\n\n";
                cout << "=====================================================================================================\n";
                close();
                break;
            default:
                cond = true;
                cout << "\n\n";
                cout << "Please choose from the availeble options! \n\n";
                break;
        }  
    }while(cond);
}

// the function that calls the dijkstra's algorithm to find the shortest path between two cities after making sure that the city exist
void shortest_path(vector<string> &cities, vector<vector<int>> &Map){
    string city1, city2; // variables for the two cities the user enters
    cout << "Enter the cities from the list: \n\n";
    for (int i = 0; i < cities.size(); i++) {
        cout << cities[i] << endl;
    }
    // the starting city
    cout << "Enter the starting city: ";
    cin.ignore(); 
    getline(cin, city1); // to take names that are separated by space
    int start = City_Index(cities, city1); // calls the function to get the index of the city 
    if (start == -1) // if the city the user enterd dose not exist it offers to add the city or enter again
    {
        int choice;
        cout << city1 << " does not exist.\n";
        do {
            cond = false;
            cout << "1, Enter again\n"
                    "2. Add the city\n"
                    "3. Exit\n";
            int choice;
            cout << "Choice: ";
            cin >> choice ;
            switch (choice)
            {
                case 1:
                    cout << "Enter the starting city: ";
                    cin.ignore();
                    getline(cin, city1);
                    start = City_Index(cities, city1);
                    if (start == -1){
                            cout << "=====================================================================================================\n";
                            cout << "You enterd city name that dose not exist start again.\n\n";
                            main();
                            break;
                        }
                    break;
                case 2:
                    cout << "=====================================================================================================\n";
                    Add_City(cities,Map);
                    return;
                case 3:
                    cout << "=====================================================================================================\n";
                    close();
                    return;
                default:
                    cond = true;
                    cout << "Please choose from the availeble options! \n\n";
                    break;
            } 
        }while(cond);
    }

    // the destination city
    cout << "Enter the destination city: ";
    getline(cin, city2);
    int end = City_Index(cities, city2);
    if (end == -1) {
        cout << city2 << " does not exist.\n";
        cout << "1, Enter again \n"
                "2. Add the city\n"
                "3. Exit\n";
        int choice;
        do {
            cond = false;
            cout << "Choice: ";
            cin >> choice ;
            switch (choice)
            {
                case 1:
                    cout << "\n\n";
                    cout << "Enter the destination city: ";
                    cin.ignore();
                    getline(cin, city2);
                    end = City_Index(cities, city2);
                    if (end == -1){
                        cout << "=====================================================================================================\n";
                        cout << "You enterd city name that dose not exist start again.\n\n";
                        main();
                        break;
                    }
                    break;
                case 2:
                    cout << "\n\n";
                    cout << "=====================================================================================================\n";
                    Add_City(cities,Map);
                    return;
                case 3:
                    cout << "\n\n";
                    cout << "=====================================================================================================\n";
                    main();
                    return;
                default:
                    cond = true;
                    cout << "Please choose from the availeble options! \n\n";
                    break;
                    
            } 
        } while (cond);
    }
    
    cout << "\n";
    dijkstra_al(Map, cities, start, end); // calls the function to find the shortest path between the two cities
    cout << "\n";
    return;
}

// function to find the connections of a city
void Connections(vector<string> cities, vector<vector<int>> Map) {
    cout << "Enter the city from the following list: \n\n";
    for (int i = 0; i < cities.size(); i++) {
        cout << cities[i] << endl;
    }

    cout << "=====================================================================================================\n";
    string city;
    cout << "\nCity name? ";
    cin.ignore();
    getline(cin, city); // to take names that are separated by space
    int cityIndex = City_Index(cities, city);

    // if the city the user enterd dose not exist it says so and offer other options
    if (cityIndex == -1) {
        cout << "The city you enterd is not found!\n" << endl;
        cout << "1, Add new city.\n"
                "2, Shortest path. \n" 
                "3, Connections for other city. \n"
                "4, Home. \n";
        int choice;
        do {
            cond = false;
            cout << "Choice: ";
            cin >> choice;
            switch (choice){
                case 1:
                    cout << "=====================================================================================================\n";
                    Add_City(cities, Map);
                    break;
                case 2:
                    cout << "=====================================================================================================\n";
                    shortest_path(cities, Map);
                    break;
                case 3:
                    cout << "=====================================================================================================\n";
                    Connections(cities, Map);
                    break;
                case 4:
                    cout << "=====================================================================================================\n";
                    main();
                    break;
                default:
                    cond = true;
                    cout << "Please choose from the availeble options! \n\n";
                    break;
            }
        }while (cond);
        return;
    }

    // if the city the user enterd exist in the city list it gives the detail of the connections of that city have.
    bool hasConnections = false; // sets the hasConnections to false 
    for (int i = 0; i < Map[cityIndex].size(); i++) {
        if (Map[cityIndex][i] != -1 && Map[cityIndex][i] != 0) // -1 means no connection, 0 means self connection 
        { 
            if (i==0){
                cout << "\n\nThe connections the city " << city << " have are:\n" << endl;
            }
            cout << cities[i] << ": " << Map[cityIndex][i] << " km" << endl;
            hasConnections = true;
        }
    }

    if (!hasConnections) // if the city user enterd has no connections with the other cities
    {
        cout << "\n\nNo connections found for this city.\n" << endl;
    }
    // after dissplaying the connections wether it have connections or not, it offers the user to choose from the following options
    cout << "\n\n";
    cout << "1, Shortest path. \n" ;
    cout << "2, Connections for other city. \n";
    cout << "3, Home. \n";
    int choice;
    do {
        cond = false;
        cout << "Choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "=====================================================================================================\n";
                shortest_path(cities, Map);
                break;
            case 2:
                cout << "=====================================================================================================\n";
                Connections(cities, Map);
                break;
            case 3:
                cout << "=====================================================================================================\n";
                main();
                break;
            default:
                cond = true;
                cout << "=====================================================================================================\n";
                cout << "Please choose from the availeble options! \n\n";
                break;
        }
    }while (cond);
}

int main() {
    if (start){
        cout << "=====================================================================================================\n";
        cout << "Wellcome to Ethiopian cities map! \n\n" "what do you want to do? \n\n";
    }
    start = false;
    cout << "1, Find the shortest path between two cities.\n" 
            "2, Add new city.\n"
            "3, See connections specific city have.\n"
            "4, About \n"
            "5, Exit\n";
    int choice;
    do {
        cond = false;
        cout << "Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n\n";
            cout << "=====================================================================================================\n";
            shortest_path(cities, Map);
            break;
        case 2:
            cout << "\n\n";
            cout << "=====================================================================================================\n";
            Add_City(cities, Map);
            break;
        case 3:
            cout << "\n\n";
            cout << "=====================================================================================================\n";
            Connections(cities, Map);
            break;
        case 4:
            cout << "\n\n";
            cout << "=====================================================================================================\n";
            about();
            break;
        case 5:
            cout << "\n\n";
            cout << "=====================================================================================================\n";
            close();
            break;
        default:
            cond = true;
            cout << "\n\n";
            cout << "Please choose from the availeble options! \n\n";
            main();
            break;
        }
    }while(cond);
}