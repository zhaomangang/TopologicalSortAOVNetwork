#include"ToplogicalSort.h"

int main()
{
	ALGraph G;
	//maxa();
	CreateDG(&G);
	TopologicalSort(G);
	//maxa(G);
	return 0;
}