#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 22;

struct Ticket {
    int start;
    int end;
    int passengers;
};

int N, last_station, total;
vector<Ticket> tickets;
int max_earning = 0;
int capacity[MAXN];

void gen_earning(int index, int earning) {
    if (index == tickets.size()) {
        max_earning = max(earning, max_earning);
        return;
    }

    bool can_take = true;
    for (int i = tickets[index].start; i < tickets[index].end; i++) {
        if (capacity[i] + tickets[index].passengers > N) {
            can_take = false;
            break;
        }
    }

    if (can_take) {
        for (int i = tickets[index].start; i < tickets[index].end; i++) {
            capacity[i] += tickets[index].passengers;
        }

        gen_earning(index + 1, earning + (tickets[index].end - tickets[index].start) * tickets[index].passengers);

        for (int i = tickets[index].start; i < tickets[index].end; i++) {
            capacity[i] -= tickets[index].passengers;
        }
    }

    gen_earning(index + 1, earning);
}

int main() {
    while (cin >> N >> last_station >> total && (N || last_station || total)) {
        tickets.clear();
        max_earning = 0;

        for (int i = 0; i < MAXN; i++) {
            capacity[i] = 0;
        }

        int starting, ending, passengers;
        for (int i = 0; i < total; i++) {
            cin >> starting >> ending >> passengers;
            tickets.push_back({starting, ending, passengers});
        }

        gen_earning(0, 0);
        cout << max_earning << endl;
    }
}
