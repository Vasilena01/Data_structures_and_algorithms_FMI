#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node {
    int x, y, time;
    bool operator>(const Node& rhs) const {
        return time > rhs.time;
    }
};

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

void dijkstra(int n, int m, vector<string>& grid, vector<vector<int>>& distances) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Initialize distances and add boundary cells
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                if (grid[i][j] == '.') {
                    distances[i][j] = 0;
                    pq.push({ i, j, 0 });
                }
                else if (grid[i][j] == '#') {
                    distances[i][j] = 1;
                    pq.push({ i, j, 1 });
                }
            }
        }
    }

    // Dijkstra's algorithm
    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (curr.time > distances[curr.x][curr.y])
            continue;

        for (int d = 0; d < 4; d++) {
            int nx = curr.x + dx[d];
            int ny = curr.y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int newTime = curr.time + (grid[nx][ny] == '#' ? 1 : 0);
                if (newTime < distances[nx][ny]) {
                    distances[nx][ny] = newTime;
                    pq.push({ nx, ny, newTime });
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> distances(n, vector<int>(m, INT_MAX));

    dijkstra(n, m, grid, distances);

    // Find the maximum escape time
    int maxTime = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                maxTime = max(maxTime, distances[i][j]);
            }
        }
    }

    // Count the number of cells with the maximum escape time
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && distances[i][j] == maxTime) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}