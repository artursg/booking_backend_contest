#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef struct {
    vector<string> passions;
    int won_event;
} person_t;

typedef struct {
    vector<string> passions;
} event_t;


struct {
        bool operator()(person_t a, person_t b)
        {   
            return a.passions.size() < b.passions.size();
        }   
    } personLess;

struct {
    bool operator()(event_t a, event_t b)
    {   
        return a.passions.size() < b.passions.size();
    }   
} eventLess;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n = 0;
    cin >> n;
    vector<person_t> persons(n);
    for (int i = 0; i < n; i++)
    {
        person_t * person = &persons[i];
        int won_event = 0;
        cin >> won_event;
        person->won_event = won_event;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            string passion;
            cin >> passion;
            person->passions.push_back(passion);
        }
    }
    vector<event_t> events(n);
    for (int i = 0; i < n; i++)
    {
        event_t * event = &events[i];
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            string passion;
            cin >> passion;
            event->passions.push_back(passion);
        }
    }
    
    std::sort(persons.begin(), persons.end(), personLess);
    std::sort(events.begin(), events.end(), eventLess);
    
    map<int, int> assignments;
    int satisfied = 0;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (assignments.find(j) != assignments.end())
                continue;
            for(int t = 0; t < persons[i].passions.size(); t++)
                for(int k = 0; k < events[j].passions.size(); k++)
                {
                    if (persons[i].passions[t].compare(events[j].passions[k]) == 0)
                    {
                        assignments[j] = i;
                        satisfied++;
                        goto label;
                    }
                }
        }
label:        
        int y = 0;
    }
    cout << satisfied << endl;
    return 0;
}
