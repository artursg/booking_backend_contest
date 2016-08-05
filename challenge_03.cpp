#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstring>
    
using namespace std;
std::time_t upper_bound, lower_bound;

typedef struct {
    long long int id;
    time_t time;
    string review;
} review_t;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    struct tm tm;
    memset(&tm, 0, sizeof(struct tm));
    time_t lower_bound;
    strptime("16/06/16", "%d/%m/%y", &tm);
    lower_bound = mktime(&tm);
    memset(&tm, 0, sizeof(struct tm));
    time_t upper_bound;
    strptime("16/07/16", "%d/%m/%y", &tm);
    upper_bound = mktime(&tm);
    long long int n(0), m(0);
    cin >> n >> m;
    vector<string> codewords;  
    for (long long int i = 0; i < n; i++)
    {
        string codeword;
        cin >> codeword;
        codewords.push_back(codeword);
    }    
    vector<review_t> reviews(m);
    for (long long int i = 0; i < m; i++)
    {
        cin >> reviews[i].id;
        cin >> reviews[i].time;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, reviews[i].review);
    }
    for (int i = 0; i < n; i++)
    {
        long long int max_score = 0;
        long long int max_id = -1;
        for (long long int j = 0; j < m; j++)
        {
            string data = reviews[j].review;
            std::transform(data.begin(), data.end(), data.begin(), ::tolower);
            string codeword = codewords[i];
            std::transform(codeword.begin(), codeword.end(), codeword.begin(), ::tolower);
            size_t first = data.find(codeword); 
            if (first == string::npos)
                continue;
            long long int score = 0;
            if (reviews[j].time > lower_bound && reviews[j].time < upper_bound)
                score += 20;
            else
                score += 10;
            if (reviews[j].review.size() >= 100)
                score += 20;
            else
                score += 10;
            if (score == max_score)
            {
                if (max_id > reviews[j].id)
                    max_id = reviews[j].id;
            }
            else if (score > max_score)
            {
                max_score = score;
                max_id = reviews[j].id;
            }
        }
        cout << max_id << endl;
    }
    return 0;
}
