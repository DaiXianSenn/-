#include"iostream"
using namespace std;

#define MAXVEX 222 //��󶨵�����Ӧ���û�����
#define INFINITY 65535//��ʾȨֵ������

typedef int EdgeType;//��Ȩֵ���� �û�����
typedef char VertexType;//�������� �û�����

typedef struct {
	VertexType vexs[MAXVEX];//�����
	EdgeType arc[MAXVEX][MAXVEX];//��׾��󣬿ɿ����߱�
	int numNodes, numEdges;//ͼ�е�ǰ�Ķ������ͱ���
}MGraph;
void CreatMGraph(MGraph *Gp) {
	int i, j, k, w;
	cin >> Gp->numNodes >> Gp->numEdges;//���붥�����ͱ���
	/*for (i = 0; i < Gp->numNodes; i++) {
		cin >> Gp->vexs[i];
	}*/
	for (i = 1; i <= Gp->numNodes; i++) {
		for (j = 1; j <= Gp->numNodes; j++) {
			if (i == j)
				Gp->arc[i][j] = 0;//����û�е��Լ��ı�
			else
				Gp->arc[i][j] = INFINITY;//�ڽӾ����ʼ��
		}
	}
	for (k = 0; k < Gp->numEdges; k++) {
		cin >> i >> j >> w;
		Gp->arc[i][j] = w;
		Gp->arc[j][i] = w;
	}
}
//ͨ���������Ͳο����ϵĴ𰸣����ǿ����ø��������㷨���������Ŀ
void ShortTestPath_Floyd(MGraph*G) {//number������
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
		if (s < m) {             //����ʱ������ȷ������Ĵ���Դ�����ʱ��������ĸ�
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