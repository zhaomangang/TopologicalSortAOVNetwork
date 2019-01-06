#pragma once
/*
文件名：ToplogicalSort.h
描述： 拓扑排序
时间：2019.1.6
*/

#include"AdjacencyList.h"
#include"Stack.h"
//#include<stdio.h>
#define OK 1
#define ERROR 0
#define Status _Bool

void FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM])
{
	int i = 0;
	ArcNode *p = NULL;	//遍历指针
	for (i = 0; i < MAX_VERTEX_NUM; i++)	//初始化入度数组
		indegree[i] = 0;
	for (i = 0; i < G.vexnum; i++)	//计算各顶点入度
	{
		p = G.vretices[i].firstarc;
		while (p != NULL)
		{
			indegree[p->adjvex]++;
			p = p->nextarc;
		}

	}
}

Status TopologicalSort(ALGraph G)
{
	//拓扑排序，有向图采用邻接表存储
	// 若G无回路，则输出G顶点的一个拓扑序列并返回OK，否则返回ERROR
	int i, count, k;
	int indegree[MAX_VERTEX_NUM];	//各顶点入度数组
	SqStack S;		//入度为零的栈
	ArcNode *p = NULL;
	InitStack(&S);
	FindInDegree(G, indegree);	//对各顶点求入度
	for (i = 0; i < G.vexnum; i++)	//入度为零者入栈
	{
		if (!indegree[i]) Push(&S, i);
	}
	count = 0;
	while (!StackEmpty(&S))
	{
		Pop(&S, &i);
		printf("%c ", G.vretices[i].data);
		count++;
		for (p = G.vretices[i].firstarc; p; p = p->nextarc)	//对i号顶点的每个邻接点的入度减一
		{
			k = p->adjvex;
			if (!(--indegree[k])) Push(&S, k);	//若入度为零，入栈
		}
	}//while
	if (count < G.vexnum)	return ERROR;
	else return OK;

}

