class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> checkin;
    unordered_map<string, pair<long long, int>> travelData;

public:
    void checkIn(int id, string stationName, int t) {
        checkin[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
        auto [startStation, startTime] = checkin[id];
        string route = startStation + "->" + stationName;
        travelData[route].first += (t - startTime); // total time
        travelData[route].second += 1;              // count
        checkin.erase(id); // Optional: remove to save space
    }

    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "->" + endStation;
        auto [totalTime, tripCount] = travelData[route];
        return (double)totalTime / tripCount;
    }
};
