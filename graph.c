#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

char cities[MAX][50];     // store city names
int graph[MAX][MAX];      // adjacency matrix for flight costs
int visited[MAX];         
int n;                    // number of cities

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] != 0 && !visited[i]) {
            dfs(i);
        }
    }
}
int isConnected() {
    for (int i = 0; i < n; i++) visited[i] = 0;
    dfs(0);   // start DFS from first city
    for (int i = 0; i < n; i++) {
        if (!visited[i]) return 0;  // if any city not visited, graph not connected
    }
    return 1;
}

int main() {
    int i, j, cost;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter city names:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", cities[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Enter flight costs between cities (0 if no direct flight):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                printf("Cost from %s to %s: ", cities[i], cities[j]);
                scanf("%d", &cost);
                graph[i][j] = cost;
            }
        }
    }

    printf("\nAdjacency Matrix (Flight Costs):\n    ");
    for (i = 0; i < n; i++) {
        printf("%s ", cities[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%s ", cities[i]);
        for (j = 0; j < n; j++) {
            printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }

    if (isConnected()) {
        printf("\nThe flight network is CONNECTED (path exists between all cities).\n");
    } else {
        printf("\nThe flight network is NOT connected.\n");
    }

    return 0;
}
