// Reconstruct Itinerary

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> flightGraph;
    vector<string> itinerary;

    void dfs(string airPort)
    {
        auto &destination = flightGraph[airPort];

        while(!destination.empty())
        {
            string nextDestination = destination.top();
            destination.pop();
            dfs(nextDestination);
        }

        itinerary.push_back(airPort);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        int n = tickets.size();
        for(int i=0;i<n;i++)
        {
            flightGraph[tickets[i][0]].push(tickets[i][1]);
        }

        dfs("JFK");

        reverse(itinerary.begin(), itinerary.end());
        
        return itinerary;
    }
};