#include<stdio.h>
#include<queue.h>
//数组表示法
#define MAXN  20

typedef struct{
	char vertec[MAXN];
	char arcs[MAXN][MAXN];
}ArrayGraph;

void Init_G(ArrayGraph *G, int nums)
{
	int i,j;
	
	for(i=0; i<nums; i++){
		for(j=0; j<nums; j++){
			G->arcs[i][j] = 0;
		}
	}
	
	return ;
}

void Creat_G(ArrayGraph *G, int nums)
{
	int i=0,j;
	int k=0;
	
	printf("please enter graph node\n");
	while(k!=nums){
		scanf("%c", &G->vertec[k]);
		k++;
	}
	
	for(i=0; i<nums; i++){
		for(j=i+1; j<nums; j++){
			scanf("%d%d", &G->arcs[i][j]);
			G->arcs[j][i] = G->arcs[i][j];
		}
	}
	
	return ;
}

void ArrayGraph_DFS(ArrayGraph *G, int nums, int start, int *visit)
{
	if(G==NULL || nums<1 || start<0 || visit==NULL){
		return ;
	}
	int i;
	
	printf("this node is %d\n", G->vertec[start]);
	visit[start] = 1;
	
	for(i=0; i<nums; i++){
		if(visit[i]==0&&G->arcs[start][i]!=0){
			ArrayGraph_DFS(G, nums, i, visit);
		}
	}
	for(i=0; i<){
		if(visit[i] == 0){
			ArrayGraph_DFS(G, nums, i, visit);
		}
	}
	
	return ;
}

void DFS(ArrayGraph *G, int nums, int start)
{
	int i;
	int visit[MAXN];
	
	for(i=0; i<nums; i++){
		visit[i] = 0;
	}
	
	ArrayGraph_DFS(G, nums, start, visit);
}

void main()
{
	ArrayGraph G;
	int nums;
	int start;
	
	printf("please enter nums\n");
	scanf("%d", &nums);
	Init_G(&G, nums);
	Creat_G(&G, nums);

	please("please enter start\n");
	scanf("%d", &start);
	DFS(&G, nums, 2);
}
