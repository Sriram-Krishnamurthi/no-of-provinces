#include <stdio.h>

void dfs(int isConnected[200][200], int n, int visited[200], int city)
{
    visited[city] = 1;
    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(isConnected, n, visited, i);
        }
    }
}
int ifcitycon(int isConnected[200][200], int n, int city)
{
    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1) {
            return 1;
        }
    }
    return 0;
}
int findPro(int isConnected[200][200], int n) {
    int visited[200] = {0};
    int provinces = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && ifcitycon(isConnected, n, i)) {
            dfs(isConnected, n, visited, i);
            provinces++;
        }
    }
    return provinces;
}
int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    int isConnected[200][200];
    printf("Enter the isConnected matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }
    int provinces = findPro(isConnected, n);
    printf("The total number of provinces is: %d\n", provinces);

    return 0;
}
