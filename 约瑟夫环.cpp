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
/*   ��������ѭ������   */   
static void CreaList(NodeType **, const int);   
/*   ����"Լɪ��"����   */   
static void StatGame(NodeType **, int);   
/*   ��ӡѭ������   */   
static void PrntList(const NodeType *);   
/*   �õ�һ�����   */   
static NodeType *GetNode(const int, const int);   
/*   ���������Ƿ�Ϊ��,   ��ΪTRUE���ǿ�ΪFALSE   */   
static unsigned EmptyList(const NodeType *);   

int main(void)   
{
	int n, m;   
	NodeType *pHead=NULL;   
	while(1)   
	{
		printf("�����ܵ����� n(<=%d):",MAX_NODE_NUM);   
		scanf("%d",&n);   
		printf("��ʼѭ��������Ϊ:");   
		scanf("%d",&m);   
		if(n>MAX_NODE_NUM)   
		{
			printf("����̫������������!\n");   
			continue; 
		}   
		else   
		break;   
    }
	CreaList(&pHead,n);   
	printf("\n��ӡ��ԭʼÿ���������кź�����\n");   
	PrntList(pHead);   
	printf("\n����ÿ������˳������кź�����\n");   
	StatGame(&pHead,m);     
	return 0;   
}   
static void CreaList(NodeType **ppHead, const int n)   
{   
	int i,iCipher;   
	NodeType *pNew, *pCur;   
	for(i=1;i<=n;i++)   
	{   
		printf("��%d���˵�����Ϊ:",i);   
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
	printf("����ɽ���ʼ��!\n");   
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
		printf("��%d���˳��������к�Ϊ%d����,������Ϊ:%d\n",i, pDel->number,pDel->password);  
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
		printf("��%d ����,����:%d\n",pCur->number,pCur->password);   
		pCur=pCur->next;   
	}while(pCur!=pHead);   
}    
static NodeType *GetNode(const int iId,const int iCipher)   
{   
	NodeType *pNew;   

	pNew=(NodeType *)malloc(sizeof(NodeType));   
	if(!pNew)   
	{   
		printf("�����ڴ治��!\n");   
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
		printf("�б�Ϊ��!\n");   
		return TRUE;   
	}   
	return FALSE;   
}

