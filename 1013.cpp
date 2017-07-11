#include <cstdio>  
int Tree[1000];  
int findRoot(int x){  
    if (Tree[x] == -1) return x;  
    else{  
        int tmp = findRoot(Tree[x]);  
        Tree[x] = tmp;  
        return tmp;  
    }  
}  
struct w{  
    int x;  
    int y;  
}way[500000];  
int main(){  
    int n, m, k;  
    scanf("%d%d%d", &n, &m, &k);  
    for (int i = 0; i < m; i++){  
        scanf("%d%d", &way[i].x, &way[i].y);  
    }  
    while (k--){  
        for (int i = 1; i <= n; i++)  
            Tree[i] = -1;  
        int c;  
        scanf("%d", &c);  
        for (int i = 0; i < m; i++){  
            if (way[i].x != c && way[i].y != c){  
                int rx = findRoot(way[i].x);  
                int ry = findRoot(way[i].y);  
                if (rx != ry){  
                    Tree[rx] = ry;  
                }  
            }  
        }  
        int group = 0;  
        for (int i = 1; i <= n; i++){  
            if (Tree[i] == -1)  
                group++;  
        }  
        printf("%d\n", group-2);  
    }  
    return 0;  
} 
