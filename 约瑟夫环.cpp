#include<stdio.h>
#include<stdlib.h>
#define MAX_NODE_NUM	30
#define TRUE	1
#define FALSE	0
typedef struct NodeType   
{
	int number;             
	int password;   
	struct NodeType *next;   
}NodeType;     
/*   创建单向循环链表   */   
static void CreaList(NodeType **, const int);   
/*   运行"约瑟夫环"问题   */   
static void StatGame(NodeType **, int);   
/*   打印循环链表   */   
static void PrntList(const NodeType *);   
/*   得到一个结点   */   
static NodeType *GetNode(const int, const int);   
/*   测试链表是否为空,   空为TRUE，非空为FALSE   */   
static unsigned EmptyList(const NodeType *);   

int main(void)   
{
	int n, m;   
	NodeType *pHead=NULL;   
	while(1)   
	{
		printf("输入总的人数 n(<=%d):",MAX_NODE_NUM);   
		scanf("%d",&n);   
		printf("初始循环的密码为:");   
		scanf("%d",&m);   
		if(n>MAX_NODE_NUM)   
		{
			printf("数字太大，请重新输入!\n");   
			continue; 
		}   
		else   
		break;   
    }
	CreaList(&pHead,n);   
	printf("\n打印出原始每个结点的序列号和密码\n");   
	PrntList(pHead);   
	printf("\n最终每个结点退出的序列号和密码\n");   
	StatGame(&pHead,m);     
	return 0;   
}   
static void CreaList(NodeType **ppHead, const int n)   
{   
	int i,iCipher;   
	NodeType *pNew, *pCur;   
	for(i=1;i<=n;i++)   
	{   
		printf("第%d个人的密码为:",i);   
		scanf("%d", &iCipher);   
		pNew=GetNode(i,iCipher);   
		if(*ppHead==NULL)   
		{   
			*ppHead=pCur=pNew;   
			pCur->next=*ppHead;   
		}   
		else   
		{   
			pNew->next=pCur->next;   
			pCur->next=pNew;   
			pCur=pNew;   
		}   
	}   
	printf("已完成结点初始化!\n");   
}     
static void StatGame(NodeType **ppHead, int iCipher)   
{   
	int iCounter, iFlag=1,i=1;   
	NodeType *pPrv, *pCur, *pDel;      
	pPrv=pCur=*ppHead;      
	while(pPrv->next!=*ppHead)   
		pPrv=pPrv->next;   
	while(iFlag)    
	{     
		for(iCounter=1;iCounter<iCipher;iCounter++)   
		{   
			pPrv=pCur;   
			pCur=pCur->next;   
		}   
		if(pPrv==pCur)   
			iFlag=0;   
		pDel=pCur;   
		pPrv->next=pCur->next;   
		pCur=pCur->next;   
		iCipher=pDel->password;   
		printf("第%d个退出的是序列号为%d的人,其密码为:%d\n",i, pDel->number,pDel->password);  
		free(pDel);   
		++i;	   
	} 	  
	*ppHead=NULL;      
}     
static void PrntList(const NodeType *pHead)   
{   
	const NodeType *pCur=pHead;   
	
	if(EmptyList(pHead))   
		return;   
	do   
	{   
		printf("第%d 个人,密码:%d\n",pCur->number,pCur->password);   
		pCur=pCur->next;   
	}while(pCur!=pHead);   
}    
static NodeType *GetNode(const int iId,const int iCipher)   
{   
	NodeType *pNew;   

	pNew=(NodeType *)malloc(sizeof(NodeType));   
	if(!pNew)   
	{   
		printf("错误，内存不足!\n");   
		exit(-1);   
	}   
	pNew->number=iId;   
	pNew->password=iCipher;   
	pNew->next=NULL;     
	return pNew;   
}   
static unsigned EmptyList(const NodeType *pHead)   
{
	if(!pHead)
	{   
		printf("列表为空!\n");   
		return TRUE;   
	}   
	return FALSE;   
}

