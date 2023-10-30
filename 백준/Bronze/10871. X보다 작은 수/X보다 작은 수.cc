#include <cstdio>


int main() {

int n,m;

scanf("%d %d", &n, &m);

while(n--){

int t;

scanf("%d", &t);

if(t<m)

printf("%d ", t);

}
}