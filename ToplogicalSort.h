#pragma once
/*
�ļ�����ToplogicalSort.h
������ ��������
ʱ�䣺2019.1.6
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
	ArcNode *p = NULL;	//����ָ��
	for (i = 0; i < MAX_VERTEX_NUM; i++)	//��ʼ���������
		indegree[i] = 0;
	for (i = 0; i < G.vexnum; i++)	//������������
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
	//������������ͼ�����ڽӱ�洢
	// ��G�޻�·�������G�����һ���������в�����OK�����򷵻�ERROR
	int i, count, k;
	int indegree[MAX_VERTEX_NUM];	//�������������
	SqStack S;		//���Ϊ���ջ
	ArcNode *p = NULL;
	InitStack(&S);
	FindInDegree(G, indegree);	//�Ը����������
	for (i = 0; i < G.vexnum; i++)	//���Ϊ������ջ
	{
		if (!indegree[i]) Push(&S, i);
	}
	count = 0;
	while (!StackEmpty(&S))
	{
		Pop(&S, &i);
		printf("%c ", G.vretices[i].data);
		count++;
		for (p = G.vretices[i].firstarc; p; p = p->nextarc)	//��i�Ŷ����ÿ���ڽӵ����ȼ�һ
		{
			k = p->adjvex;
			if (!(--indegree[k])) Push(&S, k);	//�����Ϊ�㣬��ջ
		}
	}//while
	if (count < G.vexnum)	return ERROR;
	else return OK;

}

