class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

    // Min heap of available room numbers
    priority_queue<int, vector<int>, greater<int>> availableRooms;
    for (int i = 0; i < n; ++i) {
        availableRooms.push(i);
    }

    // Min heap of occupied rooms: {endTime, roomNumber}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busyRooms;

    vector<int> roomCount(n, 0);

    for (auto& m : meetings) {
        long long start = m[0], end = m[1];

        // Free up rooms whose meetings have ended
        while (!busyRooms.empty() && busyRooms.top().first <= start) {
            availableRooms.push(busyRooms.top().second);
            busyRooms.pop();
        }

        if (!availableRooms.empty()) {
            int room = availableRooms.top();
            availableRooms.pop();
            roomCount[room]++;
            busyRooms.emplace(end, room);
        } else {
            // Delay the meeting
            auto [freeTime, room] = busyRooms.top();
            busyRooms.pop();
            long long duration = end - start;
            long long newEnd = freeTime + duration;
            roomCount[room]++;
            busyRooms.emplace(newEnd, room);
        }
    }

    // Find the room with the max number of meetings
    int maxMeetings = 0, resultRoom = 0;
    for (int i = 0; i < n; ++i) {
        if (roomCount[i] > maxMeetings) {
            maxMeetings = roomCount[i];
            resultRoom = i;
        }
    }

    return resultRoom;
    }
};