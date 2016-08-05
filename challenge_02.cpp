#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const double COEF = 3.14159265359/180;

double degree2radians(double degree)
{
    return degree*COEF;   
}

double distance_between(double point1_latitude, double  point1_longitude, double point2_latitude, double  point2_longitude) {
    double EARTH_RADIUS = 6371;//in km
    double point1_lat_in_radians  = degree2radians( point1_latitude );
    double point2_lat_in_radians  = degree2radians( point2_latitude );
    double point1_long_in_radians  = degree2radians( point1_longitude );
    double point2_long_in_radians  = degree2radians( point2_longitude );

    return acos( sin( point1_lat_in_radians ) * sin( point2_lat_in_radians ) +
                 cos( point1_lat_in_radians ) * cos( point2_lat_in_radians ) *
                 cos( point2_long_in_radians - point1_long_in_radians) ) * EARTH_RADIUS;
}

map<string, int> passion_map;

typedef struct{
    string name;
    int score;
    double x;
    double y;
} destination_t;

typedef struct{
    double distance;
    int first;
    int second;
} distance_score_t;

vector<destination_t> destinations;

struct {
        bool operator()(destination_t a, destination_t b)
        {   
            return a.score > b.score;
        }   
    } customMore;

struct {
        bool operator()(distance_score_t a, distance_score_t b)
        {   
            return a.distance < b.distance;
        }   
    } customLessDistance;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n_guests = 0;
    cin >> n_guests;
    for(int i = 0; i < n_guests; i++)
    {
        int m = 0;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            std::string p;
            cin >> p;
            passion_map[p] += 1;
        }
    }    
    int n_destinations = 0;
    cin >> n_destinations;
    for(int i = 0; i < n_destinations; i++)
    {
        destination_t destination;
        cin >> destination.name;
        cin >> destination.x;
        cin >> destination.y;
        int m = 0;
        cin >> m;
        int score = 0;
        for (int j = 0; j < m; j++)
        {
            std::string p;
            cin >> p;
            score += passion_map[p];
        }
        destination.score = score;
        destinations.push_back(destination);
    }   
    std::sort(destinations.begin(), destinations.end(), customMore);
    vector<destination_t> candidates;
    bool first_is_in = destinations[0].score == destinations[1].score;
    if (destinations.size() == 2)
    {
        cout << destinations[0].name << " " << destinations[1].name << endl;
        return 0;
    }
    if (!first_is_in && destinations.size() > 2 && destinations[1].score != destinations[2].score)
    {
        cout << destinations[0].name << " " << destinations[1].name << endl;
        return 0;
    }
    if(first_is_in)
        candidates.push_back(destinations[0]);
    int i = 1;
    int disputed_score = destinations[1].score;
    while(i < destinations.size() && destinations[i].score == disputed_score)
    {
        candidates.push_back(destinations[i]);
        i++;
    }
    vector<distance_score_t> scores;
    if (first_is_in)
        for (int i = 0; i < candidates.size(); i++)
        {
            for(int j = i + 1; j <  candidates.size(); j++)
            {
                distance_score_t score;
                double distance = distance_between(candidates[i].x, candidates[i].y, candidates[j].x, candidates[j].y);
                score.first = i;
                score.second = j;
                score.distance = distance;
                scores.push_back(score);
            }
        }
    else
       for (int i = 0; i < candidates.size(); i++)
        {
            distance_score_t score;
            double distance = distance_between(destinations[0].x, destinations[0].y, candidates[i].x, candidates[i].y);
            score.first = 0;
            score.second = i;
            score.distance = distance;
            scores.push_back(score);
        } 
    std::sort(scores.begin(), scores.end(), customLessDistance);
    if (first_is_in)
    {                
        cout << candidates[scores[0].first].name << " " << candidates[scores[0].second].name << endl;
    }
    else
    {
        cout << candidates[0].name << " " << candidates[scores[0].second].name << endl;
    }
    return 0;
}
