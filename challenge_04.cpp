#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int x;
    cin >> x;
    vector<bool> output;
    for (int i = 0; i < x; i++)
    {
        int n;
        cin >> n;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
        vector<vector<string>> attractions;
        for (int j = 0; j < n; j++)
        {
            std::string s;
            getline(cin, s);
            std::string delimiter = ",";
            size_t pos = 0;
            std::string token;
            vector<string> memory;
            while ((pos = s.find(delimiter)) != std::string::npos)
            {
                token = s.substr(0, pos);
                memory.push_back(token);
                s.erase(0, pos + delimiter.length());
            }
            memory.push_back(s);
            attractions.push_back(memory);
        }
        bool result = true;
        for(int j = 0; j < attractions.size(); j++)
        {
            
            for(int k = 0; k < attractions[j].size() - 1; k++)
            {
                string from = attractions[j][k];
                for(int t = k + 1; t < attractions[j].size(); t++)
                {
                    string to = attractions[j][t];
                    for(int ij = 0; ij < attractions.size(); ij++)
                    {
                        for(int ik = 0; ik < attractions[ij].size() - 1; ik++)
                        {
                            if (attractions[ij][ik].compare(to) == 0)
                            {
                                for(int it = ik + 1; it < attractions[ij].size(); it++)
                                {
                                    if (attractions[ij][it].compare(from) == 0)
                                    {
                                        result = false;
                                        goto label;
                                    }
                                }
                            }
                        }
                    }
                }     
            } 
        }      
label:        
        output.push_back(result);
    }
    for(int i = 0; i < output.size(); i++)
        if (output[i])
            cout << "ORDER EXISTS" << endl;
        else
            cout << "ORDER VIOLATION" << endl;
    return 0;
}
