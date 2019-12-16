#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAX_LEN 12                	   /* �ַ�����󳤶� */
#define STU_NUM 30                     /* ����ѧ������ */
#define COURSE_NUM 6                   /* ���Ŀ��Կ�Ŀ�� */
#define LEN sizeof(struct Student)     /* ѧ���ṹ����ռ���ֽڴ�С*/

//����ѧ���ṹ��
typedef struct Student
{
	long num;	                    /* ÿ��ѧ����ѧ�� */
	char name[MAX_LEN];            	/* ÿ��ѧ�������� */
	float score[COURSE_NUM];	    /* ÿ��ѧ��COURSE_NUM�Ź��εĳɼ� */
	float sum;                      /* ÿ��ѧ�����ܳɼ� */
	float aver;						/* ÿ��ѧ����ƽ���ɼ� */
	struct Student *next;
}STU;


int Menu(void);                                        //����1�������˵�����
void Print(STU *head, int n, int m);                   //����2����ӡ����

void AverSumofEveryStudent(STU *head);   //����3������ÿ�ſγ̵��ֺܷ�ƽ����
void AverSumofEveryCourse(STU *head);    //����4������ÿ��ѧ�����ֺܷ�ƽ����
void StatisticAnalysis(STU *head, int n, int m);       //����5������𼰱������

STU *SortbyScore(STU *head, int n);				       //����6����ÿ��ѧ�����ܷ��ɸߵ����ų����α�
STU *SortbyScore1(STU *head, int n);                   //����7����ÿ��ѧ�����ܷ��ɵ͵����ų����α�
STU *SortbyNum(STU *head);                             //����8����ѧ����С�����ų��ɼ���
STU *SortbyName(STU *head, int n);                     //����9�����������ֵ�˳���ų��ɼ���
STU *Create(int n, int m);                             //����10����������¼����Ϣ
STU *Creat1(int n, int m);

void SearchbyNum(STU *head, int n, int m);             //����11����ѧ�Ų�ѯѧ���������俼�Գɼ�
void SearchbyName(STU *head, int n, int m);            //����12����������ѯѧ���������俼�Գɼ�

void WritetoFile(STU *head, int n, int m);             //����13����ÿ��ѧ���ļ�¼��Ϣд���ļ�
STU *ReadfromFile(STU *head, int *n, int *m);          //����14�����ļ��ж���ÿ��ѧ���ļ�¼��Ϣ����ʾ
int DeleteFromFile(STU *head, int *n, int *m);          //����15: ����ɾ��(ɾ�����ļ��е�����)
STU* getAllMessageFromFile(STU *head, int count0[], int count1[], int *count2);     //����16����ȡ�ļ������е�ѧ���ɼ����ݣ�����ɵ�����

int main()
{
	int n, m;
	int i;
	STU *head;  //����ͷ�ڵ�
	//head = (STU *)malloc(LEN);
	head = NULL;
	while (true)
	{
		i = Menu(); //��ʼ���˵�����
		if (i == 1) //�˵�1
		{
			system("cls");  //����
			printf("\n\n\n");
			printf("\t\t\t*****************************************************************************************\n");
			printf("\t\t\t������ѧ������(n<50):\n"); //����ѧ����
			printf("\t\t\t");
			scanf("%d", &n);
			printf("\t\t\t�����뿼�Կ�Ŀ����(m<=6):\n");
			printf("\t\t\t");
			scanf("%d", &m);
		}
		switch (i)
		{
		case 1:
			printf("\t\t\t����������ѧ�š������ͳɼ�:\n");
			head = Create(n, m);
			system("cls");  //����
			break;
		case 2:
			system("cls");  //����
			AverSumofEveryStudent(head);
			head = NULL;
			break;
		case 3:
			system("cls");  //����
			AverSumofEveryCourse(head);
			head = NULL;
			break;
		case 4:
			system("cls");  //����
			printf("\n\n\n");
			printf("\t\t\t�ִܷӴ�С��������:\n");
			head = SortbyScore(head, n);
			head = NULL;
			break;
		case 5:
			system("cls");  //����
			printf("\n\n\n");
			printf("\t\t\tSort in ascending order by score:\n");
			head = SortbyScore1(head, n);
			Print(head, n, m);
			break;
		case 6:
			system("cls");  //����
			printf("\n\n\n");
			printf("\t\t\tSort in ascending order by number:\n");
			head = SortbyNum(head);
			Print(head, n, m);
			break;
		case 7:
			system("cls");  //����
			printf("\n\n\n");
			printf("\t\t\tSort in dictionary order by name:\n");
			head = SortbyName(head, n);
			Print(head, n, m);
			break;
		case 8:
			system("cls");  //����
			printf("\n\n\n");
			printf("\t\t\t*****************************************************************************************\n");
			printf("\t\t\tInput the number you want to search:\n");
			SearchbyNum(head, n, m);
			break;
		case 9:
			system("cls");  //����
			printf("\n\n\n");
			printf("\t\t\t*****************************************************************************************\n");
			printf("\t\t\tInput the name you want to search:\n");
			SearchbyName(head, n, m);
			break;
		case 10:
			system("cls");  //����
			StatisticAnalysis(head, n, m);
			break;
		case 11:
			system("cls");  //����
			printf("\n\n\n");
			Print(head, n, m);
			break;
		case 12:
			system("cls");  //����
			WritetoFile(head, n, m);//�־û����ļ���
			head = NULL;//��Ұָ�롣�����ʱ�����ݣ�������α����ظ�����
			break;
		case 13:
			system("cls");  //����
			printf("\n");
			head = ReadfromFile(head, &n, &m);
			head = NULL;
			break;
        case 14:
            system("cls");
            break;
        case 15:
            system("cls");
            printf("\n\n\n");
            printf("\t\t\t*****************************************************************************************\n");
            DeleteFromFile(head, &n, &m);
            head = NULL;
            break;
        case 16:
            system("cls");
            break;
        case 17:
            system("cls");
            break;
		case 0:
			system("cls");  //����
			printf("\n\n\n");
			printf("\t\t\t*****************************************************************************************\n");
			printf("\t\t\t���˳�ϵͳ!\n");
			printf("\t\t\t*****************************************************************************************\n");
			return 0;
		default:
			system("cls");  //����
			printf("\n\n\n");
			printf("\t\t\t*****************************************************************************************\n");
			printf("\t\t\t�������!\n");
			printf("\t\t\t*****************************************************************************************\n");

		}

	}

	return 0;


}
// �����˵�
int Menu(void)
{
	int i;
	system("title �γ����: ѧ���ɼ�����ϵͳ  By 16041321�Ƽ��� and �첮��");
	printf("\n\n");
	printf("\t\t\t                                    ѧ���ɼ�����ϵͳ\n");
	printf("\t\t\t*******************************************************************************************\n");
	printf("\t\t\t*                ϵͳ���ܲ˵���:                                                          *\n");
	printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                1.  ¼���µ�ѧ���ɼ���¼(��ʱ��)       ��                                 *\n");
	printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                2.  ���㲢���ÿ�ſγ̵��ֺܷ�ƽ����   ��                                 *\n");
	printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                3.  ���㲢���ÿλѧ�����ֺܷ�ƽ����   ��                                 *\n");
	printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                4.  ��ѧ���ִܷӸߵ�������             ��                                 *\n");
	printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                5.  ��ѧ���ִܷӵ͵�������                                               *\n");
	printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                6.  ��ѧ��ѧ�Ŵ�С��������                                               *\n");
	printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                7.  ��ѧ���������ֵ�˳������                                             *\n");
	printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                8.  ��ѧ��ѧ�Ų�ѯ�������俼�Գɼ�                                       *\n");
	printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                9.  ��ѧ��������ѯ�������俼�Գɼ�                                       *\n");
	printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                10. ��ÿ�ſγ̵ĳɼ�������зֶ�ͳ��                                     *\n");
	printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                11. ���ÿλѧ����ѧ�š����������ƿ��Գɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ����   *\n");
	printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                12. ����ʱ�����ݱ��浽�ļ��� ��                                           *\n");
	printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                13. ���ļ��ж���ÿ��ѧ���ļ�¼��Ϣ����ʾ ��                               *\n");
	printf("\t\t\t*                                                                                         *\n");
    printf("\t\t\t*                14. �߼�ɾ��ѧ���ɼ���Ϣ(δ���,Ҫ����лָ�����)                        *\n");
    printf("\t\t\t*                                                                                         *\n");
    printf("\t\t\t*                15. ����ɾ��ѧ���ɼ���Ϣ    ��                                            *\n");
    printf("\t\t\t*                                                                                         *\n");
    printf("\t\t\t*                16. �޸�ѧ���ɼ���Ϣ(δ���)                                             *\n");
    printf("\t\t\t*                                                                                         *\n");
	printf("\t\t\t*                0.  �˳�ϵͳ                                                             *\n");
	printf("\t\t\t*******************************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t                          ����������ѡ��:");
	scanf("%d", &i);
	return i;

}

// ����ѧ������
// int n : ѧ������
// int m : ���Կ�Ŀ��
STU *Create(int n, int m) {
	STU *head;
	STU *p1, *p2;
	int i, j;
	for (i = 1; i < n + 1; i++)
	{
		p1 = (STU *)malloc(LEN);
		printf("\t\t\t");
		scanf("%ld", &p1->num);//����ѧ��
		printf("\t\t\t");
		scanf("%s", p1->name);//��������
		for (j = 0; j < m; j++)
		{
			printf("\t\t\t");
			scanf("%f", &p1->score[j]);
		}
		p1->next = NULL;

		//�����ͷ���
		if (i == 1)
		{
			head = p2 = p1;
		}
		else
		{
			p2->next = p1; //��ʱ���
			p2 = p1; //
		}
	}

	//p1 = head;
	//for(i = 0; i < n; i++){
    //    for(j = 0; j < m; j++) {
    //        printf("\t\t\t%f\n", p1->score[j]);
    //    }
    //    p1 = p1->next;
	//}

	return head;
}


STU *Creat1(int n, int m)
{
	STU *head;
	STU *p1, *p2;
	int i, j;
	head = NULL;

	for (i = 0; i < n; i++)
	{
		p1 = (STU *)malloc(LEN);
		p1->next = NULL;
		if (i == 0)
		{
			head = p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
	}

	return head;
}


void  AverSumofEveryStudent(STU *head)
{
    int flag = 0;
    int count = 0;
    int count1[1000],count2[1000];
    float score[COURSE_NUM];
    int num[COURSE_NUM];
    STU *p;
    int i, j, k = 0;
    head = getAllMessageFromFile(head, count1, count2, &count);
    p = head;

    for(i = 0; i < COURSE_NUM; i++)
    {
        score[i] = 0.0;
        num[i] = 0;
    }

    //����Ҳû����
    //printf("count1[0] = %d, count2[0] = %d", count1[0], count2[0]); // 2 1

    if (head != NULL)
    {
        printf("\t\t\t******************************************************************************\n");

        for (i = 0; i < count; i++)  //���� 1
        {
            for (j = 0; j < count1[i]; j++)  //ÿ������ 2
            {
                for (k = 0; k < count2[i]; k++)  //ÿ���˵ķ��� 1
                {
                    score[k] = score[k] + p->score[k];
                    num[k]++;
                }

                p = p->next;
            }
        }

        for(i = 0; i < COURSE_NUM; i++)
        {
            if(num[i] > 0)
                printf("\t\t\t��Ŀ %d:    sum=%.0f , aver=%.0f\n", i + 1, score[i], score[i] / num[i]);
        }

        printf("\t\t\t******************************************************************************\n");

    }
}

void  AverSumofEveryCourse(STU *head)
{
    int count = 0;
    int count1[1000],count2[1000];
    STU *p;
    head = getAllMessageFromFile(head, count1, count2, &count);
    p = head;
    printf("\n\n\n");
    printf("\t\t\t******************************************************************************\n");
    while(p != NULL) {
        printf("\t\t\tѧ��:%ld   ����:%8s    �ܷ�=%3.0f    ƽ����=%3.0f\n", p->num, p->name, p->sum, p->aver);
        p = p->next;
    }

    printf("\t\t\t******************************************************************************\n");

}


STU  *SortbyScore(STU *head, int n)
{
    int count = 0;
    int flag = 0;
    int rank = 1;
    int count1[1000],count2[1000];
	STU *endpt;    //����ѭ���Ƚ�
	STU *cur, *tail, *p;
	float tempSum;
	long tempNum;
	char tempName[1024];


	head = getAllMessageFromFile(head, count1, count2, &count);
	tail = head;
	cur = head;
	p = head;


//    while(p != NULL)
//    {
//
//        printf("\t\t\tѧ��:%ld   ����:%s    �ܷ�=%3.0f    ����:%3d\n", p->num, p->name, p->sum, rank++);
//        p = p->next;
//    }

	//tailָ��Ϊ��
	while (tail != NULL) {
        tail = tail->next;
	}

	//��ѭ��,ѭ������Ϊ��������-1��
	while (p->next != tail) {
        flag = 0;
        cur = head;
        while (cur->next != tail) {
            if(cur->sum < cur->next->sum) {
                //����
                tempSum = cur->sum;
                cur->sum = cur->next->sum;
                cur->next->sum = tempSum;

                //C�����ڲ���������׵�ַ�ǲ����Ա����ĵġ����Բ����ø�ֵ�ķ�ʽȥ����

                strcpy(tempName, cur->name);
                strcpy(cur->name, cur->next->name);
                strcpy(cur->next->name, tempName);


                tempNum = cur->num;
                cur->num = cur->next->num;
                cur->next->num = tempNum;

                flag = 1;
            }
            cur = cur->next;
        }
        //βָ����ǰ�ƶ�
        tail = cur;
	}

    //��������
    while(p != NULL)
    {

        printf("\t\t\tѧ��:%12ld   ����:%8s    �ܷ�=%4.0f    ����:%3d\n", p->num, p->name, p->sum, rank++);
        p = p->next;
    }


	return head;
}


STU  *SortbyScore1(STU *head, int n)
{
	STU *endpt;    //����ѭ���Ƚ�
	STU *p;        //��ʱָ�����
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->sum > p1->next->next->sum)  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}

	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;
}


STU *SortbyNum(STU *head)
{
	STU *first;     //Ϊԭ����ʣ������ֱ�Ӳ�������Ľڵ�ͷָ��
	STU *t;         //��ʱָ�����������ڵ�
	STU *p, *q;     //��ʱָ�����

	first = head->next;      //ԭ����ʣ������ֱ�Ӳ�������Ľڵ������ɸ���ͼ12�����
	head->next = NULL;       //ֻ����һ���ڵ����������������ɸ���ͼ11�����

	while (first != NULL)        //����ʣ�����������
	{
		//ע�⣺����for����������ֱ�Ӳ�������˼��ĵط�
		for (t = first, q = head; ((q != NULL) && (q->num < t->num)); p = q, q = q->next);  //����ڵ��������������Ҳ����λ��

		first = first->next; //���������еĽڵ��뿪���Ա������뵽����������

		if (q == head)      //���ڵ�һ���ڵ�֮ǰ
		{
			head = t;
		}
		else            //p��q��ǰ��
		{
			p->next = t;
		}
		t->next = q;     //��ɲ��붯��
						 //first = first->next;
	}
	return head;
}


STU  *SortbyName(STU *head, int n)
{
	STU *endpt;    //����ѭ���Ƚ�
	STU *p;        //��ʱָ�����
	STU *p1, *p2;

	p1 = (STU *)malloc(LEN);
	p1->next = head;        //ע����⣺��������һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棬��Ҫ��Ϊ�˱��ڱȽϡ���Ϊ��һ���ڵ�û��ǰ�������ǲ��ܽ�����ַ
	head = p1;                 //��headָ��p1�ڵ㣬������ɺ������ٰ�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->name, p1->next->next->name)>0)  //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵ���򽻻�
			{
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;     //��ϵ�4�����
				p = p1->next->next;   //��ϵ�6�����
			}
		}
	}

	p1 = head;              //��p1����Ϣȥ��
	head = head->next;       //��headָ�������ĵ�һ���ڵ�
	free(p1);          //�ͷ�p1
	p1 = NULL;          //p1��ΪNULL����֤��������Ұָ�롱������ַ��ȷ����ָ�����

	return head;
}


void Print(STU *head, int n, int m)
{
	STU *p;
	int i;
	p = head;

	if (head != NULL)        //ֻҪ���ǿ�������������������нڵ�
	{
		printf("\t\t\t*****************************************************************************************\n");
		do
		{

			printf("\t\t\t%ld\t%s\t", p->num, p->name);
			for (i = 0; i<m; i++)
			{
				printf("%6.0f", p->score[i]);
			}
			printf("%6.0f%6.0f\n", p->sum, p->sum / m);//
			p = p->next;     //�Ƶ���һ���ڵ�
		} while (p != NULL);
		printf("\t\t\t*****************************************************************************************\n");
	}
}

void  SearchbyNum(STU *head, int n, int m)
{
	long num;
	int i;
	int flag = 1;
	printf("\t\t\t");
	scanf("%ld", &num);
	STU *p;
	p = head;
	if (head != NULL)
	{
		do {
			if (p->num == num)
			{
				printf("\t\t\t");
				printf("%ld\t%s\t", p->num, p->name);
				for (i = 0; i<m; i++)
				{
					printf("%.0f\t", p->score[i]);
				}
				printf("%.0f\t%.0f\n", p->sum, p->sum / m);
				flag = 0;

			}
			p = p->next;

		} while (p != NULL);
		if (flag)
		{
			printf("\t\t\t");
			printf("Not found!\n");
		}
	}
	printf("\t\t\t******************************************************************************\n");

}

void  SearchbyName(STU *head, int n, int m)
{
	char name[MAX_LEN];
	int i;
	int flag = 1;
	printf("\t\t\t");
	scanf("%s", name);
	STU *p;
	p = head;
	if (head != NULL)
	{
		do {
			if (strcmp(name, p->name) == 0)
			{
				printf("\t\t\t");
				printf("%ld\t%s\t", p->num, p->name);
				for (i = 0; i<m; i++)
				{
					printf("%.0f\t", p->score[i]);
				}
				printf("%.0f\t%.0f\n", p->sum, p->sum / m);
				flag = 0;
			}
			p = p->next;

		} while (p != NULL);
		if (flag)
		{
			printf("\t\t\t");
			printf("Not found!\n");
		}
	}
	printf("\t\t\t******************************************************************************\n");

}

void StatisticAnalysis(STU *head, int n, int m)
{
	int a[6];
	STU *p;
	p = head;
	int i, j;
	for (i = 0; i<m; i++)
	{
		p = head; // ��Ҫ���˳�ʼ������Ȼ��ը
		for (j = 0; j<6; j++)  // ��ʼ��
		{
			a[j] = 0;
		}
		do {
			if (p->score[i]<60)
			{
				a[0]++;
			}
			else if (p->score[i]<70)
			{
				a[1]++;
			}
			else if (p->score[i]<80)
			{
				a[2]++;
			}
			else if (p->score[i]<90)
			{
				a[3]++;
			}
			else if (p->score[i]<100)
			{
				a[4]++;
			}
			else
			{
				a[5]++;
			}

			p = p->next;

		} while (p != NULL);
		printf("\n\n\n");
		printf("\t\t\t*****************************************************************************************\n");
		printf("\t\t\t* For course %d:\n", i + 1);
		printf("\t\t\t* <60\t%d\t%.2f%%\n", a[0], 100 * a[0] / 6.0);
		printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 60, 69, a[1], 100 * a[1] / 6.0);
		printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 70, 79, a[2], 100 * a[2] / 6.0);
		printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 80, 89, a[3], 100 * a[3] / 6.0);
		printf("\t\t\t* %d-%d\t%d\t%.2f%%\n", 90, 99, a[4], 100 * a[4] / 6.0);
		printf("\t\t\t* %d\t%d\t%.2f%%\n", 100, a[5], 100 * a[5] / 6.0);
		printf("\t\t\t*****************************************************************************************\n");

	}
}


//STU *head ѧ������ͷָ��
//int n: ѧ������
//int m: ���Կ�Ŀ����
void  WritetoFile(STU *head, int n, int m)
{
    float sum;
	STU *p,*p1;
	p = head;
	p1 = head;
	sum = 0.0f;
	//for(int i = 0; i < n; i++){
    //    for(int j = 0; j < m; j++) {
    //        printf("\t\t\t%f\n", p1->score[j]);
    //    }
    //    p1 = p1->next;
	//}
	FILE *fp; //�ļ�ָ��
	int i, j;
	printf("\n\n\n");
	printf("\t\t\t*****************************************************************************************\n");
	//if ((fp = fopen("student.txt", "w")) == NULL)//����������ָ���ļ�������;�Ѵ���������ȫ�����
	if ((fp = fopen("student.txt", "a")) == NULL)//�������򴴽���������׷��
	{
		printf("\t\t\t��Ǹ, �޷�����/���ļ� student.txt\n");
		return;
	}

	//printf("\t\t\tdebug1");
	if (p == NULL)
	{
	    printf("\t\t\t��ʱ��û������ �� �ѳɹ����浽�ļ���!\n");
        return;
    }
	//1[tab]2
	fprintf(fp, "%d\t%d\n", n, m);
	//printf("\t\t\tdebug2\n");
	for (i = 0; i<n; i++)
	{
		fprintf(fp, "%12ld%12s", p->num, p->name);//һ������ռ2���ַ�
		//printf("%12ld%12s", p->num, p->name);
		for (j = 0; j < m; j++)
		{
		    sum = sum + p->score[j];
			fprintf(fp, "%12.0f", p->score[j]);//������12��С�������0λ������С����ҲĬ��ȡ��������
			//printf("%12.0f", p->score[j]);
		}
		//fprintf(fp, "%12.0f%12.0f\n", p->sum, p->sum / m);
		fprintf(fp, "%12.0f%12.0f\n", sum, sum / m);
		//printf("%12.0f%12.0f\n", p->sum, p->sum / m);

		sum = 0.0f;
		p = p->next;
	}
	printf("\t\t\t\�����ļ��ɹ��� \n");
	fclose(fp);
	printf("\t\t\t*****************************************************************************************\n");

}



//��������ֱ��������һ���µ�����ȷ������ֱ�Ӷ�ȡ��õ�����
STU *ReadfromFile(STU *head, int *n, int *m)
{
	STU *p;
	FILE *fp;
	int i, j;
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		printf("\t\t\t������ student.txt!\n");
		return NULL;
	}

	if (fgetc(fp) == EOF) {
        printf("\t\t\tstudent.txt û������!\n");
        return NULL;
    }

    fclose(fp);
    fp = fopen("student.txt", "r");

	printf("\n\t\t\t�����ɹ�!\n");
	printf("\t\t\t*****************************************************************************************\n");
    while(!feof(fp))
    {
        fscanf(fp, "%d\t%d\n", n, m);//����ѧ�������Ϳ��Կ�Ŀ����
        head = Creat1(*n, *m);  //������һ�����������Ҹ���head
        p = head;

        for (i = 0; i<*n; i++)
        {
            fscanf(fp, "%12ld", &p->num);
            fscanf(fp, "%12s", &p->name);
            for (j = 0; j<*m; j++)
            {
                fscanf(fp, "%12f", &p->score[j]);
            }
            fscanf(fp, "%12f%12f\n", &p->sum, &p->aver);

            p = p->next;

        }
        i = *n;
        j = *m;

        //fclose(fp);

        Print(head, i, j);

        //��������Ҫ���ͷ������ʡ�ռ�,ʱ��̫�����ˣ�������ʱ��ֱ�Ӹ���Ұָ���ˡ���֮����ʱ����дһ����������������Ż�


        //debug:
        //if(feof(fp)) {
        //    printf("\t\t\t�Ѿ����ļ�ĩβ\n");
        //}

    }
    printf("\t\t\t*****************************************************************************************\n");
	fclose(fp);

	return head;
}


//����ɾ��(�����,�����ȽϷ���)
int DeleteFromFile(STU *head, int *n, int *m) {
    int count0[1000], count1[1000];//���ڱ���ѧ�������Ϳγ���,֧��1000�μ�¼��ȡ
    int count2;
    STU *head1;//head1
    STU *p,*p1,*p2;
    FILE *fp;
    int i,j,k;
    long num;
    if ((fp = fopen("student.txt", "r")) == NULL) {
        printf("\t\t\t�������ļ� student.txt!\n");
        return 0;
    }

    if (fgetc(fp) == EOF) {
        printf("\t\t\tstudent.txt û������!\n");
        return 0;
    }

    fclose(fp);
    fp = fopen("student.txt", "r");

    printf("\t\t\t�������ɾ����¼��ѧ��:");
    scanf("%ld", &num);

    //�Ȱ��ļ������������ȫ�������ڴ��У������һ��ѧ�������ܹ���count2���ύ��¼
    count2 = 0;
    fscanf(fp, "%d\t%d\n", n, m);
    count0[count2] = *n;//count0[0] = 1
    count1[count2] = *m;//count1[0] = 1
    count2++;//1
    head1 = head = Creat1(*n, *m); //����һ�����������Ҹ���head
    p = head;
    for(i = 0; i < *n; i++)
    {
        fscanf(fp, "%12ld", &p->num);//16041321
        fscanf(fp, "%12s", &p->name);//hjs
        for (j = 0; j<*m; j++)
        {
            fscanf(fp, "%12f", &p->score[j]);//100
        }
        fscanf(fp, "%12f%12f\n", &p->sum, &p->aver);//100 100
        if(p->num == num) {
            count0[count2 - 1]--;//count0[0] =  0
        }
        p2 = p;//�����µ�ǰ�ڵ�
        p = p->next;
    }

    while(!feof(fp))
    {
        fscanf(fp, "%d\t%d\n", n, m);// 1 1
        count0[count2] = *n;// 1
        count1[count2] = *m;// 1
        ++count2;//2
        head = Creat1(*n, *m); //����һ�����������Ҹ���head
        p2->next = head;
        p = head;
        for(i = 0; i < *n; i++)
        {
            fscanf(fp, "%12ld", &p->num);//16041333
            fscanf(fp, "%12s", &p->name);//hjj
            for (j = 0; j<*m; j++)
            {
                fscanf(fp, "%12f", &p->score[j]);//89
            }
            fscanf(fp, "%12f%12f\n", &p->sum, &p->aver);//89 89
            if(p->num == num){
                count0[count2-1]--;//count0[1] = 1
            }
            p2 = p;
            p = p->next;
        }
    }
    fclose(fp);

// debug
//    printf("\t\t\t%d\n", count2);
//
//    for(int i = 0; i < count2; i++) {
//        printf("%d\t%d\n",count0[i], count1[i]);
//    }


//    p1 = head1;
//    for(int i = 0; i < count2; i++){
//        for(int j = 0; j < count0[i]; j++) {
//            printf("%ld\t%s\t", p1->num, p1->name);
//            for(int k = 0; k < count1[i]; k++) {
//                    printf("%f\t", p1->score[k]);
//            }
//            printf("%f\t%f", p1->sum, p1->aver);
//            printf("\n");
//            p1 = p1->next;
//        }
//	}


    p = p1 = head1;
    if (head1 != NULL)
    {
        if(p->num == num)//���ɾ������ͷ���
        {
            head1 = p->next;
        }
        else
        {
            while(p != NULL && p->num != num)  //ע������Ҫ���пգ�˳���ܵߵ�...������debug�˺ܾ�
            {
                p1 = p;//�����µ�ǰ�ڵ�
                p = p->next;
            }
            if(p == NULL)
            {
                printf("\t\t\tû�в��ҵ���ؼ�¼ !\n");
                return 0;
            }
            p1->next = p->next;
        }
        free(p);//ɾ���ڵ�
    }



    fp = fopen("student.txt", "w");//����յķ�ʽ���ļ�

    p = head1;
    for (i = 0; i < count2; i++)
    {
        fprintf(fp, "%d\t%d\n", count0[i], count1[i]);
        for (j = 0; j < count0[i]; j++)
        {
            fprintf(fp, "%12ld%12s", p->num, p->name);//һ������ռ2���ַ�
            for (k = 0; k < count1[i]; k++)
            {
                fprintf(fp, "%12.0f", p->score[k]);//������12��С�������0λ������С����ҲĬ��ȡ��������
            }
            fprintf(fp, "%12.0f%12.0f\n", p->sum, p->aver);
            p = p->next;
        }
    }
    printf("\n\t\t\t\ɾ���ɹ��� \n");
    fclose(fp);
    return 1;

}


STU* getAllMessageFromFile(STU *head, int count0[], int count1[], int *count2) {
    int n, m;
    STU *head1;
    STU *d,*p1,*p2;
    FILE *fp;
    int i,j,k;
    int num;
    if ((fp = fopen("student.txt", "r")) == NULL) {
        printf("\t\t\t�������ļ� student.txt!\n");
        return NULL;
    }

    if (fgetc(fp) == EOF) {
        printf("\t\t\tstudent.txt û������!\n");
        return NULL;
    }

    fclose(fp);

    //�Ȱ��ļ������������ȫ�������ڴ��У������һ��ѧ�������ܹ���count2���ύ��¼
    fp = fopen("student.txt", "r");

    (*count2) = 0;
    fscanf(fp, "%d\t%d\n", &n, &m);

    count0[(*count2)] = n;//count0[0] = 2
    count1[(*count2)] = m;//count1[0] = 1
    (*count2)++;//1
    head1 = head = Creat1(n, m); //����һ�����������Ҹ���head
    d = head;

    for(i = 0; i < n; i++)
    {
        fscanf(fp, "%12ld", &d->num);//16041333 16051213
        fscanf(fp, "%12s", &d->name);//zzm cl
        for (j = 0; j<m; j++)
        {
            fscanf(fp, "%12f", &d->score[j]);//96 16
        }
        fscanf(fp, "%12f%12f\n", &d->sum, &d->aver);//100 100
        p2 = d;//�����µ�ǰ�ڵ�
        d = d->next;
    }


    while(!feof(fp))
    {
        fscanf(fp, "%d\t%d\n", &n, &m);// 1 1
        count0[(*count2)] = n;// 1
        count1[(*count2)] = m;// 1
        ++(*count2);//2
        head = Creat1(n, m); //����һ�����������Ҹ���head
        p2->next = head;
        d = head;
        for(i = 0; i < n; i++)
        {
            fscanf(fp, "%12ld", &d->num);//16041333
            fscanf(fp, "%12s", &d->name);//hjj
            for (j = 0; j<m; j++)
            {
                fscanf(fp, "%12f", &d->score[j]);//89

            }
            fscanf(fp, "%12f%12f\n", &d->sum, &d->aver);//89 89
            p2 = d;
            d = d->next;
        }
    }


    fclose(fp);
    return head1;
}
