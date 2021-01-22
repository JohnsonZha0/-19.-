#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#define INF 999999
#define M 20
int dist[M][M];///����
int path[M][M];///·��
int Stack[M];///·��ջ
int top;///ջ��
int counts;///��¼·����
int visited[M];///�������
using namespace std;
struct vertex///������Ϣ�ṹ��
{
    int num;///������
    char name[20];///��������
    char info[300];///�������
};
struct maps
{
    int n;///����
    int m;///����
    vertex v[M];
    int edgs[M][M];///�ڽӾ���
} g; ///����ͼ�Ľṹ��
void Creat_vertex()
{
    g.v[0].num=1;
    strcpy(g.v[0].name,"������");
    strcpy(g.v[0].info,"���彨���������У�����ţ������ڼ�����ſ��ţ�");
    g.v[1].num=2;
    strcpy(g.v[1].name,"����");
    strcpy(g.v[1].info,"˭��������տ���Ӱ�أ�");
    g.v[2].num=3;
    strcpy(g.v[2].name,"������");
    strcpy(g.v[2].info,"�����Ȼ�����");
    g.v[3].num=4;
    strcpy(g.v[3].name,"C60����");
    strcpy(g.v[3].info,"����ϩ");
    g.v[4].num=5;
    strcpy(g.v[4].name,"ʵ��¥");
    strcpy(g.v[4].info,"����ʵ����");
    g.v[5].num=6;
    strcpy(g.v[5].name,"��ˮ�㳡");
    strcpy(g.v[5].info,"��������ĵط�");
    g.v[6].num=7;
    strcpy(g.v[6].name,"�ϴ���");
    strcpy(g.v[6].info,"��˼·999��");
    g.v[7].num=8;
    strcpy(g.v[7].name,"������");
    strcpy(g.v[7].info,"ѧУ�������������ݡ����ݡ���Ӿ�����");
    g.v[8].num=9;
    strcpy(g.v[8].name,"�ϲ���");
    strcpy(g.v[8].info,"�Ա�Ҳ��С����");
    g.v[9].num=10;
    strcpy(g.v[9].name,"��ѧ¥ABCD");
    strcpy(g.v[9].info,"�ϿΡ���ϰ��ȥ����");
    g.v[10].num=11;
    strcpy(g.v[10].name,"������");
    strcpy(g.v[10].info,"�����Ρ��˶��ᶼ�ٲ�������");
    g.v[11].num=12;
    strcpy(g.v[11].name,"һʳ��");
    strcpy(g.v[11].info,"һʳ�������㣬ʳ�����෱�ࡣ");
    g.v[12].num=13;
    strcpy(g.v[12].name,"��ѧ�������");
    strcpy(g.v[12].info,"�������š������š�������֯�ۼ��ء�");
    g.v[13].num = 14;
    strcpy(g.v[13].name, "������վ");
    strcpy(g.v[13].info, "ȡ�����");
    g.v[14].num = 15;
    strcpy(g.v[14].name, "����¥");
    strcpy(g.v[14].info, "�����ѧԺ�����������񴦡�");
    g.v[15].num = 16;
    strcpy(g.v[15].name, "ͼ���");
    strcpy(g.v[15].info, "֪ʶ�ĵ��ã����д�������ͼ��ͼ�������ƽ����ͨ������ʱ��ʱ��Ѽ�ӺͿ�ȸ��ˮ����Ϸ��");
    g.v[16].num = 17;
    strcpy(g.v[16].name, "��Ϣ¥");
    strcpy(g.v[16].info, "������������Ϣʵ�����ġ�����ƽ̨");
    g.v[17].num = 18;
    strcpy(g.v[17].name, "��ʦ��Ԣ");
    strcpy(g.v[17].info, "�ɴ���ξ��೵ǰ���Ϻ���վ�����У��");
    g.v[18].num = 19;
    strcpy(g.v[18].name, "��ʳ��");
    strcpy(g.v[18].info, "������ɹ�ѡ��");
}
void Creat_maps()
{
    int i,j;
    g.n=19;///19������
    g.m=35;///35��˫��·��
    for(i=0; i<g.n; i++) ///��ʼ���ڽӾ���
    {
        for(j=0; j<g.n; j++)
        {
            g.edgs[i][j]=INF;
        }
    }
    g.edgs[0][1]=g.edgs[1][0]=175;  ///д��ߵ���Ϣ
    g.edgs[0][16]=g.edgs[16][0]=300;
    g.edgs[0][18]=g.edgs[18][0]=260;
    g.edgs[0][17]=g.edgs[17][0]=340;
    g.edgs[1][2]=g.edgs[2][1]=130;
    g.edgs[2][3]=g.edgs[3][2] =445;
    g.edgs[2][4]=g.edgs[4][2]=790;
    g.edgs[3][4] = g.edgs[4][3]=340;
    g.edgs[3][18]=g.edgs[18][3]=265;
    g.edgs[3][16]=g.edgs[16][3]=250;
    g.edgs[16][18]=g.edgs[18][16]=140;
    g.edgs[4][5]=g.edgs[5][4]=270;
    g.edgs[4][6]=g.edgs[6][4]=460;
    g.edgs[5][6]=g.edgs[6][5]=170;
    g.edgs[6][7]=g.edgs[7][6]=380;
    g.edgs[7][8]=g.edgs[8][7]=200;
    g.edgs[7][9]=g.edgs[9][7]=280;
    g.edgs[5][9]=g.edgs[9][5]=390;
    g.edgs[5][15]=g.edgs[15][5]=390;
    g.edgs[15][16]=g.edgs[16][15]=270;
    g.edgs[14][16] = g.edgs[16][14] = 250;
    g.edgs[15][14] = g.edgs[14][15] = 110;
    g.edgs[15][9] = g.edgs[9][15] = 215;
    g.edgs[9][14] = g.edgs[14][9] = 225;
    g.edgs[9][10] = g.edgs[10][9] = 180;
    g.edgs[7][10] = g.edgs[10][7] = 230;
    g.edgs[13][14] = g.edgs[14][13] = 290;
    g.edgs[9][13] = g.edgs[13][9] = 460;
    g.edgs[9][11] = g.edgs[11][9] = 310;
    g.edgs[10][11] = g.edgs[11][10] = 340;
    g.edgs[11][13] = g.edgs[13][11] = 240;
    g.edgs[13][17] = g.edgs[17][13] = 170;
    g.edgs[13][12] = g.edgs[12][13] = 300;
    g.edgs[11][12] = g.edgs[12][11] = 300;
    g.edgs[12][17] = g.edgs[17][12] = 320;
}
void Search_info()
{
    int i,n;
    printf("��������ѧ����У���ľ����У�\n");
    for(i=0; i<19; i++)
    {
        printf("%d:%s\n",g.v[i].num,g.v[i].name);
    }
    while(1)
    {
        printf("����������Ҫ��ѯ�ľ����ţ�\n");
        printf("��0�˳�\n\n");
        scanf("%d",&n);
        getchar();
        if(n==0)
        {
            break;
        }
        else if(n<0||n>19)
        {
            printf("�����������������룡����\n\n");
            continue;
        }
        else
        {
            printf("%d:%s\n",g.v[n-1].num,g.v[n-1].name);
            printf("%s\n\n",g.v[n-1].info);
        }
    }
    return ;
}
void Floyd() ///��������
{
    int i,j,k;
    for(i=0; i<g.n; i++) ///��ʼ��������·������
    {
        for(j=0; j<g.n; j++)
        {
            dist[i][j]=g.edgs[i][j];
            if(i!=j&&dist[i][j]<INF)
            {
                path[i][j]=i;
            }
            else
            {
                path[i][j]=-1;///-1�����ɴ�
            }
        }
    }
    //printf("%d\n",g.n);
    for(k=0; k<g.n; k++)
    {
        for(i=0; i<g.n; i++)
        {
            for(j=0; j<g.n; j++)
            {
                if(dist[i][j]>(dist[i][k]+dist[k][j]))
                {
                    dist[i][j]=dist[i][k]+dist[k][j];///����
                    path[i][j]=k;         ///path���ڼ�¼���·���ϵĽ��*/
                }
            }
        }
    }
    return ;
}
void Floyd_print(int s, int e)
{
    if(path[s][e]==-1||path[s][e]==e||path[s][e]==s)///�ݹ���ֹ����
    {
        return;
    }
    else
    {
        Floyd_print(s,path[s][e]);///���м����Ϊ�յ������ӡ·��
        printf("%s->",g.v[path[s][e]].name);///��ӡ�м侰������
        Floyd_print(path[s][e],e);///���м����Ϊ��������ӡ·��
    }
}

void Dfs_allpath(int s,int e)
{
    int dis=0;
    int i,j;
    Stack[top]=s;
    top++;  ///�����ջ
    visited[s]=1;///�����ջ
    for(i=0; i<g.n; i++)
    {
        if(g.edgs[s][i]>0&&g.edgs[s][i]!=INF&&!visited[i])
        {
            ///��������ɴ���δ������
            if(i==e)///DFS�����յ㣬��ӡ·��
            {
                printf("��%d��·:",counts++);
                for(j=0; j<top; j++)
                {
                    printf("%s->",g.v[Stack[j]].name);
                    if(j<top-1)///ͳ��·������
                    {
                        dis=dis+g.edgs[Stack[j]][Stack[j+1]];
                    }
                }
                dis=dis+g.edgs[Stack[top-1]][e];
                printf("%s\n",g.v[e].name);///��ӡ�յ�
                printf("�ܳ����ǣ�%dm\n\n",dis);
            }
            else///�����յ����DFS
            {
                Dfs_allpath(i,e);
                top--;///֧·ȫ������һ��,�����ջ
                visited[i]=0;///��ջ����Ϊ�ѳ�ջ�������´η���
            }
        }
    }
}
void Bestpath_Multispot()
{
    int vNum[M]= {0};
    int i,j,dis;
    j=1;
    dis=0;///ͳ��ȫ���ܳ�
    printf("��������Ҫ�����ĵ�%d������ı�ţ�����-1�������룩��",j);
    scanf("%d",&vNum[j-1]);
    while(vNum[j-1]!=-1&&j<13)
    {
        printf("��������Ҫ�����ĵ�%d�������ţ�",++j);
        scanf("%d", &vNum[j-1]);
        if(vNum[j-1]==-1)
        {
            break;
        }
    }
    printf("\n������ѷ���·����");
    for(i=0; vNum[i]>0&&vNum[i+1]>0; i++)
    {
        printf("%s->",g.v[vNum[i]-1].name);///���·���ϵ����
        Floyd_print(vNum[i]-1,vNum[i+1]-1);///���÷��������㷨
        dis+=dist[vNum[i]-1][vNum[i+1]-1];
    }
    printf("%s\n\n",g.v[vNum[j-2]-1].name);///*���·���ϵ��յ�*/
    printf("ȫ���ܳ�Ϊ��%dm\n\n",dis);
}

void Dis_menu()
{
    printf("\n");
    printf("       **��ӭʹ�û�������ѧ������У����������ѯϵͳ*******\n\n");
    printf("       *****   1.������Ϣ��ѯ             ******************\n");
    printf("       *****   2.����֮�����·��ѯ       ******************\n");
    printf("       *****   3.���������·����ѯ       ******************\n");
    printf("       *****   4.�ྰ������·�߲�ѯ     ******************\n");
    printf("       *****   5.�˳�ϵͳ                 ******************\n");
    printf("       *****************************************************\n");
    return ;
}
void Dis_map()
{
	printf("\t\t****************************************\n");
	printf("\t\t��������ѧ������У������ͼ\n ");
	printf("��������������������������������������������������������������������������\n");
	printf(" ��                   MAP OF ECUST(FENGXIAN CAMPUS)                      ��\n");
	printf(" ��  3         ��2   1     18�X�T�T�T�T�T�h�T�h�T�T�Y13              ��N ��\n");
	printf(" ���X�k�T�T�T�T�T�k�T�p�T�T�T�p�T�T�T�T�T�n�T�n�T�T�k�T�j�T�T�T�T�[      ��\n");
	printf(" ���U          ��    �U      �U          ������        �U         �U     ��\n");
	printf(" ���U          ��    �U      �d�T�T�T�h�T�n�T�n�T�T�T�T�g12        �U    ��\n");
	printf(" ���U          �� 19 �U      �U       14 ������        �d�T�T�T�T�T�T�g  �� \n");
	printf(" ���p�T�T�T�T�T�T�j�T�m�T�T�T�p�T�T�T�T�T�n�T�n�T�T�T�T�p�T�T�[       �U ��\n");
	printf(" ���U        4 ���U   17     �U       15 ������      10�U    �U11      �U��\n");
	printf(" ���d�T�j�T�T�T�T�m�T�T�h�T�T�m�T�T�T�T�T�n�T�n�T�T�T�T�p�T�T�g        �U��\n");
	printf(" ���U  �U      ������  ��            16  ������        �U    �d�T�T�T�T�g��\n");
	printf(" ���U  �U    ���������������������������������b�T�T�T�T�m�T�T�g        �U��\n");
	printf(" ���d�T�g     ������������������������������ ��              �U        �U��\n");
	printf(" ���U  �U       ���������������������������� ��              �U        �U��\n");
	printf(" ���U  �U5        ������������������������  ��               �U        �U��\n");
	printf(" ���U  �c�������������������� 6   ����������                 �U8       �U��\n");
	printf(" ���^�T�m�T�T�T�T�T�T�T�T�T�T�p�p�T�T�T�T�T�T�T�T�T�T�T�T�T�T�m�T�T�T�j�a��\n");
	printf(" ��                            7                                      9  ��\n");
	printf(" ��������������������������������������������������������������������������\n");
}
int main()
{
    int i,n;
    int start,ends;
    Creat_vertex();
    Creat_maps();
    Dis_map();
    while(1)
    {
        Dis_menu();
        printf("��������Ҫ���������\n");
        scanf("%d",&n);
        getchar();
        if(n<1||n>5)
        {
            printf("�����������������룡����\n");
            continue;
        }
        else
        {
            if(n==1)
            {
                Search_info();
            }
            else if(n==2)
            {
                Dis_map();
                printf("���������ľ��㣺\n");
                scanf("%d",&start);
                printf("�������յ�ľ��㣺\n");
                scanf("%d",&ends);
                Floyd();///��������
                printf("��%s��%s��̾����ǣ�%d\n",g.v[start-1].name,g.v[ends-1].name,dist[start-1][ends-1]);
                printf("%s->",g.v[start-1].name);
                Floyd_print(start-1, ends-1);
                printf("%s\n",g.v[ends-1].name);
            }
            else if(n==3)
            {
                Dis_map();
                counts=1;///��ʼ·����Ϊ1
                printf("���������ľ��㣺\n");
                scanf("%d",&start);
                printf("�������յ�ľ��㣺\n");
                scanf("%d",&ends);
                Dfs_allpath(start-1,ends-1);
            }
            else if(n==4)
            {
                Dis_map();
                Floyd();///��������
                Bestpath_Multispot();
            }
            else if(n==5)
            {
                return 0;
            }
        }

    }
    return 0;
}