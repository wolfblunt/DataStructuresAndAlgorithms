// Keys and Rooms
class Solution {
public:
    void dfs(vector<vector<int>>& rooms, unordered_set<int> &keys, unordered_set<int> &roomVisit, int currRoom)
    {
        roomVisit.insert(currRoom);
        for(auto a: rooms[currRoom])
        {
            keys.insert(a);
        }
        for(auto a: keys)
        {
            if(roomVisit.find(a)==roomVisit.end())
                dfs(rooms, keys, roomVisit, a);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys;
        unordered_set<int> roomVisit;
        dfs(rooms, keys, roomVisit, 0);
        return roomVisit.size() == rooms.size()?true:false;
    }
};