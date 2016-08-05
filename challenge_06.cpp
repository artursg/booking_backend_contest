#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const string delimiter = ",";

typedef struct {
    string name;
    int hours_min;
    vector<string> neighbors;
    vector<int> hours_to_neighbors;
} vertex_t;

map<string, int> city_to_index;
map<string, bool> visited;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<vertex_t> cities;
    vertex_t bevagna;
    bevagna.name = "Bevagna";
    cities.push_back(bevagna);
    for (int i = 0; i < n; i++)
    {
        vertex_t city;
        string line;
        cin >> line;        
        size_t pos = 0;
        pos = line.find(delimiter);
        city.name = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        city.hours_min = atoi(line.c_str());
        city_to_index[city.name] = i + 1;
        cities.push_back(city);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;        
        size_t pos = 0;
        pos = line.find(delimiter);
        string city_1  = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        pos = line.find(delimiter);
        string city_2  = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        int travel_time = atoi(line.c_str());
        cities[city_to_index[city_1]].neighbors.push_back(city_2);
        cities[city_to_index[city_1]].hours_to_neighbors.push_back(travel_time);
        cities[city_to_index[city_2]].neighbors.push_back(city_1);
        cities[city_to_index[city_2]].hours_to_neighbors.push_back(travel_time);
    }
    int total_hours = 80;
    string current_city = "Bevagna";       
    while(true)
    {
        int index_min = min_element(cities[city_to_index[current_city]].hours_to_neighbors.begin(), cities[city_to_index[current_city]].hours_to_neighbors.end()) - cities[city_to_index[current_city]].hours_to_neighbors.begin();
        cout << cities[city_to_index[current_city]].neighbors[index_min];
        return 0;
    }
    return 0;
}
