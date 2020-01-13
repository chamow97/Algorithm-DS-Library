#include<bits/stdc++.h>

using namespace std;


class TarjanArticulationPoints {
private:
	//change the size as per the need
	vector<int> adj[1000];
	int n;
	int time;
	map<int, bool> isVisited;
	map<int, int> lowTime;
	map<int, int> visitedTime;
	set<int> articulationPoints;

public:
	TarjanArticulationPoints() {
		time = 1;
	}
	void inputList();
	void DFS(int, int);
	void showArticulationPoints();
};

void TarjanArticulationPoints :: inputList() {
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void TarjanArticulationPoints :: DFS(int current, int parent) {
	isVisited[current] = true;
	visitedTime[current] = time;
	lowTime[current] = time;
	time++;

	int childCount = 0;
	bool isArticulationPoint = false;
	for(auto i : adj[current]) {
		if(i == parent) {
			continue;
		}

		if(!isVisited[i]) {
			childCount++;
			DFS(i, current);

			if(visitedTime[current] <= lowTime[i]) {
				isArticulationPoint = true;
			} else {
				lowTime[current] = min(lowTime[current], lowTime[i]);
			}
		} else {
			lowTime[current] = min(lowTime[current], visitedTime[i]);
		}
	}
	if((parent == -1 && childCount >= 2) || (parent != -1 && isArticulationPoint)) {
		articulationPoints.insert(current);
	}
}

void TarjanArticulationPoints :: showArticulationPoints() {
	cout << "Articulation Points: \n";
	for(auto i : articulationPoints) {
		cout << i << '\n';
	}
}

int main() {
	TarjanArticulationPoints tarjanArticulationPoints;
	tarjanArticulationPoints.inputList();
	tarjanArticulationPoints.DFS(0, -1);
	tarjanArticulationPoints.showArticulationPoints();
	return 0;
}