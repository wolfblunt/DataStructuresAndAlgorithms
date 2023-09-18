// Reconstruct Itinerary

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> flightGraph;
    vector<string> itinerary;

    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        int n = tickets.size();
        for(int i=0;i<n;i++)
        {
            flightGraph[tickets[i][0]].push(tickets[i][1]);
        }

        // dfs("JFK");

        stack<string> dfsStack;
        dfsStack.push("JFK");

        while(!dfsStack.empty())
        {
            string currentAirport = dfsStack.top();
            auto &destination = flightGraph[currentAirport];

            if(!destination.empty())
            {
                string nextDestination = destination.top();
                destination.pop();

                dfsStack.push(nextDestination);
            }
            else
            {
                itinerary.push_back(currentAirport);
                dfsStack.pop();
            }
        }

        reverse(itinerary.begin(), itinerary.end());
        
        return itinerary;
    }
};