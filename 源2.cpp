#include"iostream"
using namespace std;

#define MAXVEX 222 //最大定点数，应由用户定义
#define INFINITY 65535//表示权值的无穷

typedef int EdgeType;//边权值类型 用户定义
typedef char VertexType;//顶点类型 用户定义

typedef struct {
	VertexType vexs[MAXVEX];//顶点表
	EdgeType arc[MAXVEX][MAXVEX];//零阶矩阵，可看作边表
	int numNodes, numEdges;//图中当前的顶点数和边数
}MGraph;
void CreatMGraph(MGraph *Gp) {
	int i, j, k, w;
	cin >> Gp->numNodes >> Gp->numEdges;//输入顶点数和边数
	/*for (i = 0; i < Gp->numNodes; i++) {
		cin >> Gp->vexs[i];
	}*/
	for (i = 1; i <= Gp->numNodes; i++) {
		for (j = 1; j <= Gp->numNodes; j++) {
			if (i == j)
				Gp->arc[i][j] = 0;//顶点没有到自己的边
			else
				Gp->arc[i][j] = INFINITY;//邻接矩阵初始化
		}
	}
	for (k = 0; k < Gp->numEdges; k++) {
		cin >> i >> j >> w;
		Gp->arc[i][j] = w;
		Gp->arc[j][i] = w;
	}
}
//通过分析·和参考网上的答案，我们可以用弗洛伊德算法计算这个题目
void ShortTestPath_Floyd(MGraph*G) {//number顶点数
	int i, j, k,s;
	int m = INFINITY,l;
	for(k=1;k<=G->numNodes;k++)
	for(i=1;i<=G->numNodes;i++)
	for (j = 1; j <= G->numNodes; j++) {
		if (G->arc[i][j] > G->arc[i][k] + G->arc[k][j])
			G->arc[i][j] = G->arc[i][k] + G->arc[k][j];
	}
	for (i = 1; i <= G->numNodes; i++) {
		s = 0;
		for (j = 0; j <= G->numNodes; j++)
			if (G->arc[i][j] > s)s = G->arc[i][j];
		if (s < m) {             //测试时部分正确，错误的答案来源于相等时究竟输出哪个
			m = s;
			l = i;
		}
		
	}
	cout << l;
}

int main() {
	MGraph root;
	CreatMGraph(&root);
	ShortTestPath_Floyd(&root);
}