class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        if (firstPlayer > secondPlayer) swap(firstPlayer, secondPlayer);

        map<tuple<int, int, int>, pair<int, int>> memo;

        function<pair<int, int>(int, int, int)> dfs = [&](int n, int a, int b) -> pair<int, int> {
            if (a > b) swap(a, b);
            if (a + b == n + 1) return {1, 1}; // They meet this round

            auto key = make_tuple(n, a, b);
            if (memo.count(key)) return memo[key];

            int minRound = INT_MAX;
            int maxRound = INT_MIN;

            vector<pair<int, int>> matches;
            int mid = -1;
            for (int i = 1; i <= n / 2; ++i) {
                matches.emplace_back(i, n - i + 1);
            }
            if (n % 2 == 1) {
                mid = (n + 1) / 2;
            }

            vector<vector<int>> nextRounds;

            function<void(int, vector<int>)> generate = [&](int idx, vector<int> current) {
                if (idx == matches.size()) {
                    if (mid != -1) current.push_back(mid);
                    sort(current.begin(), current.end());
                    nextRounds.push_back(current);
                    return;
                }

                auto [x, y] = matches[idx];
                if ((x == a && y == b) || (x == b && y == a)) {
                    minRound = 1;
                    maxRound = 1;
                    return;
                }

                if (x == a || x == b) {
                    vector<int> temp = current;
                    temp.push_back(x);
                    generate(idx + 1, temp);
                }
                else if (y == a || y == b) {
                    vector<int> temp = current;
                    temp.push_back(y);
                    generate(idx + 1, temp);
                }
                else {
                    vector<int> temp1 = current;
                    temp1.push_back(x);
                    generate(idx + 1, temp1);

                    vector<int> temp2 = current;
                    temp2.push_back(y);
                    generate(idx + 1, temp2);
                }
            };

            generate(0, {});

            for (auto &next : nextRounds) {
                int na = 0, nb = 0;
                for (int i = 0; i < next.size(); ++i) {
                    if (next[i] == a) na = i + 1;
                    if (next[i] == b) nb = i + 1;
                }
                if (na == 0 || nb == 0) continue;
                auto [mn, mx] = dfs(next.size(), na, nb);
                minRound = min(minRound, 1 + mn);
                maxRound = max(maxRound, 1 + mx);
            }

            return memo[key] = {minRound, maxRound};
        };

        auto [earliest, latest] = dfs(n, firstPlayer, secondPlayer);
        return {earliest, latest};
    }
};