//给定一个有向图 G（V，E），设计算法判断图 G 是否有环，计算时空复杂度
#define maxlen 50
int visit[maxlen] = {0};

int inDegree[maxlen];

void Count(AdjList G)
{//计算各顶点的入度 
	int i;
	for(i = 1; i <= G.n; i++)
	{
		VHeadNode v = G.adjlist[i];
		EdgeNode *e1 = v.fisrtedge;
		while(e1)
		{
			inDegree[e1 -> adjvex]++;
			e1 = e1 -> next;
		}
	}
}


Bool IsCircuit(AdjList G)
{
	//判断一个有向图是否有环，可以使用拓扑排序
	Count(G);
	InitQueue(Q); 
	VHeadNode v;
	EdgeNode *e;
	int i , flag = 0;
	
	for(i = 1; i <= G.n; i++)
	{//将初始状态下入度为0的节点入队 
		if(inDegree[i] == 0)
		{
			InQueue(G.adjlist[i] , Q);
			visit[i] = 1;
		}	
	}
	
	while(Q)
	{
		DeQueue(v , Q);
		Visit(v);
		e = v.firstedge;
		while(e)
		{
			if(visit[e -> adjvex] == 0)
			{
				InQueue(G.adjlist[e -> adjvex] , Q);
				visit[e -> adjvex] = 1;
			}
			inDegree[e -> adjvex]--;
			e1 = e1 -> next;
		}
	}
	
	for(i = 1; i <= G.n; i++)
	{ 
		if(visit[i] == 0)
			flag = 1;	
	}
	
	if(flag == 1)
		return True;
	else
		return false;
}

