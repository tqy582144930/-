#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define LEN sizeof(struct student)

struct student{				//����һ���ṹ�� 
	char num[1000];
	char name[1000];
	char age[1000];
	char c_score[1000]; 
	char english_score[1000]; 
	char math_score[1000]; 
	struct student*next;
};
struct usingdata{
	char num[1000];
	char root[1000];
	struct usingdata *next;
};
struct usingdata *heads;
struct student *head;		//ͷ��� 
void check();    //��½ 
int menu();      //��Ŀ¼ 
void luru();     //����¼�� 
void xr();       
void xg();      //�޸� 
void cr();      //���� 
void sc();      //ɾ�� 
int cx_menu();   //������Ŀ¼ 
void cx(); 
void cx1();
void cx2();
void cx3();
int tj_menu();   //�����Ŀ¼ 
void tj();
void tj1();
void tj2();
void tj3();
int px_menu();   //������Ŀ¼ 
void px();
void px1();
void px2();
void px3();

//�û���¼
void xinjianli()
{
	struct usingdata *p = heads;
	while(p->next)
	p = p->next;
	while(1)
	{
		struct usingdata *pp; 
		pp = (struct usingdata*)malloc(sizeof(struct usingdata));
		memset(pp,0,sizeof(pp));
		printf("��������Ҫ�½����˺ţ�");
		scanf("%s",pp->num);
		getchar();
		struct usingdata *q = heads;
		int flag = 1;
		while(q)
		{
			flag = 1;
			if(strcmp(q->num,pp->num) == 0)
			{
				printf("���˺��ѱ������������´���\n");
				flag = 0;
				break;
			}
			q = q->next;
		}
		if(flag == 0)
		{
			continue;
		}
		printf("��������Ҫ���������룺");
		scanf("%s",pp->root);
		getchar(); 
		p->next = pp;
		pp->next = NULL;
		p = p->next;
		
		char cc[1000];
		printf("���Ƿ���Ҫ��������������Y��N��\n");
		scanf("%s",&cc);
		while (strcmp(cc,"Y") != 0 && strcmp(cc,"N") != 0){
			printf("������ȷѡ�\n"); 
			scanf("%s", &cc);
	    }
		if(cc[0] == 'Y')
		{
			while(getchar() != '\n');
			continue;
		} 
		else
		{
			while(getchar() != '\n');
			return;
		}
	}
}

void duqv()
{
	FILE *fp = NULL;
	if ((fp=fopen("ѧ��.txt","r")) == NULL){
     	return;
    }
    else{
    	struct usingdata *q = NULL;
    	q = heads;
   		struct usingdata *p = NULL;
    	while (!feof(fp)){
    		p = (struct usingdata*)malloc(sizeof(struct usingdata));
    		if(p == NULL)
    			return;
    		memset(p,0,sizeof(struct usingdata));
    		fscanf(fp,"%s %s\n",q->num,q->root);
    		q->next = p;
    		q = p;
		}
	}
	fclose(fp);
}

int aaa(char *p,char *q)
{
	struct usingdata *m = heads;
	while(m)
	{
		if ((strcmp(p,m->num)==0) && (strcmp(q,m->root)==0))
		return 1;
		m = m->next;
	}
	return 0;
}

void check()
{
	heads = (struct usingdata*)malloc(sizeof(struct usingdata));
	memset(heads,0,sizeof(struct usingdata));
	duqv();
	char userName[256];//�û��� 
	char userPWD[256];//����  
	int i,sum;
	for(i = 1; i < 4; i++)        
	{  
	  //�û����������Ϊabcde 
	    printf("****             (�û����������Ϊabcde)         ****\n");  
	    printf("****             �����������û���:               ****\n");  
	    gets(userName);  
	      
	    printf("****             ��������������:                 ****\n");   
		int p = 0;  
		char ch; 
	 
		while((ch=getch())!='\r')
		{  
			if(ch==8)  
			{  
				putchar('\b');  
				putchar(' ');  
				putchar('\b');
				if(p>0)
				p--;  
			}  
			if(!isdigit(ch)&&!isalpha(ch))  
				continue;  
				putchar('*');  
				userPWD[p++]=ch; 
		}  
		userPWD[p]=0;
	    
	    if ((strcmp(userName,"abcde")==0) && (strcmp(userPWD,"abcde")==0))//��֤�û���������  
	    {  
	        printf("\n*�û�����������ȷ����ʾ���˵�*\n"); 
			Sleep(1000);
			char c[1000];
			printf("���Ƿ���Ҫ�½��˺ţ���������Y��N��\n");
			scanf("%s",&c);
			while (strcmp(c,"Y") != 0 && strcmp(c,"N") != 0){
				printf("������ȷѡ�\n"); 
				scanf("%s", &c);
		    }
			if(c[0] == 'Y'){
				while(getchar() != '\n');
				xinjianli();
			}else {
				while(getchar() != '\n');
			}
	        return;  
	    }
		else if(aaa(userName,userPWD) == 1)
			return;
	    else  
	    {  
	        if (i < 3)  
	        {    
	            printf("\n�û����������������������!\n");  
	        }  
	        else  
	        {   
	            printf("\n��������3�ν��û������������ϵͳ���˳�!\n");  
	            exit(1);   
	        }  
	    }  
	}  
}

int menu()
{
        char n[1000];
		int n1; 
        do{
        system("cls");
        printf("\t\t\t|-----------------------------------------------------|\n");
        printf("\t\t\t|          *****ѧ������ϵͳ*****                     |\n");
        printf("\t\t\t|-----------------------------------------------------|\n");
        printf("\t\t\t|              1.ѧ���ɼ��޸�                         |\n");
        printf("\t\t\t|              2.ѧ���ɼ�����                         |\n");  
        printf("\t\t\t|              3.ѧ���ɼ�ɾ��                         |\n");
        printf("\t\t\t|              4.ѧ���ɼ���ѯ                         |\n"); 
        printf("\t\t\t|              5.ѧ���ɼ�ͳ��                         |\n");
        printf("\t\t\t|              6.ѧ���ɼ�����                         |\n");
        printf("\t\t\t|              7.�˳�����                             |\n");
        printf("\t\t\t-------------------------------------------------------\n");
        printf("��ѡ��1-7��");
        scanf("%s", &n);
        n1 = atoi(n);
        }while(n1 < 0 || n1 > 7);
        return n1;
        
}

void gaiwenjian()
{
	FILE *fp = NULL;
	if((fp=fopen("ѧ��.txt","w"))==NULL)
    {
        printf("�ļ�������������˳���");
        getch();
        exit(1); 
    }
    else
    {
    	struct usingdata *p = heads;
    	while(p)
    	{
    		fprintf(fp,"%s %s\n",p->num,p->root);
    		p = p->next;
		}
	}
}

int main(void)
{
	
	check();
	head = (struct student *)malloc(LEN);
	memset(head,0,LEN);
	luru();
	xr();
	int x = 1;
	while (x){
		switch (menu()){
			case 1:
				xg();
				break;
			case 2:
				cr();
				break;
			case 3:
				sc(); 
				break;
			case 4:
				cx(); 
				break;
			case 5:
				printf("\n\t\t\t|              6.ѧ���ɼ�ͳ��                         |\n");
				tj();
				break;
			case 6:
				printf("\n\t\t\t|              7.ѧ���ɼ�����                         |\n");
				px();
				break;
			case 7:
				printf("\n\t\t\t|                ллʹ�ã�                           |\n");
				gaiwenjian();
				exit(1);
		}
	}
	gaiwenjian();
} 

//ѧ����Ϣ¼�루����  β�巨 
void luru() 
{ 
	system("CLS");
	printf("\n\t\t\t|                  ѧ���ɼ�¼��                    |\n");
	struct student *current, *prev;
	int num = 0;
	char ch;
	do {	
		num++;
		current = (struct student*)malloc(LEN);	
			
		printf("������ѧ��(8λ)��");
        scanf("%s",current->num);
        float num1 = atoi(current->num);
        while (num1 > 99999999 || num1 < 10000000){
	        printf("______________________\n");
	        printf("____������8λ�Ǹ���___\n");
	        printf("_______________________\n");
	        printf("��������ѧ��:\n ");scanf("%s",&current->num);
	        num1 = atof(current->num);
        }
        
        printf("������������");
        scanf("%s",current->name);
        while (current->name[0] > 0){
            printf("________________________\n");
            printf("______���������뺺��____\n");
            printf("______________________\n");
            printf("������������: \n");scanf("%s",current->name);
        }
        
        printf("���������䣺");
        scanf("%s",current->age);
        int age1 = atoi(current->age);
        while (age1 < 0  || age1 > 100){
            printf("_________________________\n");
            printf("___����������1-100֮��___\n");
            printf("_________________________\n");
            printf("������������\n");
            printf("����: ");scanf("%s",&current->age);
            age1 = atoi(current->age);
        }
        
        printf("������c���Գɼ���");
        scanf("%s",current->c_score);
        float c_score1 = atof(current->c_score);
        while (c_score1 < 1 || c_score1 > 100){
            printf("_________________________\n");
            printf("___�ɼ�������1-100֮��___\n");
            printf("_________________________\n");
            printf("��������ɼ�\n");
            printf("c����: ");scanf("%s",&current->c_score);
            c_score1 = atof(current->c_score);
        } 
        
        printf("������Ӣ��ɼ�:");
        scanf("%s",current->english_score);
        float english_score1 = atof(current->english_score);
        while (english_score1 < 1 || english_score1 > 100){
            printf("_________________________\n");
            printf("___�ɼ�������1-100֮��___\n");
            printf("_________________________\n");
            printf("��������ɼ�\n");
            printf("Ӣ��ɼ�: ");scanf("%s",&current->english_score);
            english_score1 = atof(current->english_score);
        } 
        
		printf("��������ѧ�ɼ�:");
        scanf("%s",current->math_score);
        float math_score1 = atof(current->math_score);
        while (math_score1 < 1 || math_score1 > 100){
            printf("_________________________\n");
            printf("___�ɼ�������1-100֮��___\n");
            printf("_________________________\n");
            printf("��������ɼ�\n");
            printf("��ѧ: ");scanf("%s",&current->math_score);
            math_score1 = atof(current->math_score);
        }
		if (head->next == NULL){
		   	head->next = current;
		} else {
		   	prev->next = current;
		}
		current->next = NULL;
		prev = current;
		printf("�Ƿ����¼��ѧ����Ϣ��Y/N��:\n");
		ch = getch();
		while (ch != 'N' && ch != 'Y'){
			ch = getch();
          }
	}while(ch == 'Y');
	printf("�ѽ���%d������\n", num);
	Sleep(1000);
} 

// ���ݵĴ洢  
void xr()
{
    struct student *current;
    FILE*fp;
    if((fp=fopen("ѧ������ϵͳ.txt","wt"))==NULL)
    {
        printf("�ļ�������������˳���");
        getch();
        exit(1); 
    }
    for(current = head->next; current != NULL; current=current->next)
    {
        fprintf(fp,"%s %s %s %s %s %s\n", current->num, current->name, current->age, current->c_score, current->english_score, current->math_score);
    }
    fclose(fp);
}

//�����ݽ����޸� 
void xg()
{
	system("CLS");
	printf("\n\t\t\t|                 1.ѧ���ɼ��޸�                      |\n");
	struct student *current;
	char ch;
	char a[1000];
    printf("\n\t\t\t|              ��Ϣ�޸ģ�Y���˳�������N��             |\n");
    scanf("%s", a);
    while (strcmp(a,"Y") != 0 && strcmp(a,"N") != 0){
		printf("������ȷѡ�\n"); 
		scanf("%s", &a);
    }
    
    if (a[0] == 'Y'){ 
		do{
		int flag = 0;
		printf("������Ҫ�޸ĵ�ѧ��ѧ��(8λ)��");
		char num[1000];
		scanf("%s", num);
		int num2 = atoi(num);
		while (num2 > 99999999 || num2 < 10000000){
	        printf("______________________\n");
	        printf("____������8λ�Ǹ���___\n");
	        printf("_______________________\n");
	        printf("��������ѧ��:\n ");
			scanf("%s",num);
			num2 = atoi(num);
        }
	
		for (current = head->next; current != NULL; current = current->next){
			int num1 = atoi(current->num);
			if(num1 == num2)
	        {
	            printf("\t\t�Ѿ��鵽��ѧ������Ϣ\n");
	            flag=0;
	            break;
	        }
	        else
	            flag=1;  
		}
		if(flag==1)
	        printf("\t\t��Ǹ��û�в鵽��ѧ������Ϣ\n");
	    if(flag==0)
	    {
	        printf("\t\t��ѧ����ԭ��Ϣ����\n");
		    printf("ѧ��ѧ��:%s\n", current->num);  
	        printf("ѧ������:%s\n",current->name);  
	        printf("ѧ������:%s\n",current->age);
	        printf("ѧ��c���Գɼ�:%s\n",current->c_score); 
			printf("ѧ��Ӣ��ɼ�:%s\n",current->english_score);
			printf("ѧ����ѧ�ɼ�:%s\n",current->math_score);
		    printf("\t\t�����������ѧ������Ϣ\n");	
		    printf("������ѧ��(8λ)��");
	        scanf("%s",&current->num);
	        int num1 = atoi(current->num);
	        while (num1 > 99999999 || num1 < 10000000){
		        printf("______________________\n");
		        printf("____������8λ�Ǹ���___\n");
		        printf("_______________________\n");
		        printf("��������ѧ��:\n ");scanf("%s",&current->num);
		        num1 = atoi(current->num);
	        }
	        
	        printf("������������");
	        scanf("%s",&current->name);
	        while (current->name[0] > 0){
	            printf("________________________\n");
	            printf("______���������뺺��____\n");
	            printf("______________________\n");
	            printf("������������: \n");scanf("%s",current->name);
	        }
	        
	        printf("���������䣺");
	        scanf("%s",&current->age);
	        int age1 = atoi(current->age);
	        while (age1 < 0  || age1 > 100){
	            printf("_________________________\n");
	            printf("___����������1-100֮��___\n");
	            printf("_________________________\n");
	            printf("������������\n");
	            printf("����: ");scanf("%s",&current->age);
	            age1 = atoi(current->age);
	        }
	        
	        printf("������c���Գɼ���");
	        scanf("%s",&current->c_score);
	        float c_score1 = atof(current->c_score);
	        while (c_score1 < 1 || c_score1 > 100){
                printf("_________________________\n");
                printf("___�ɼ�������1-100֮��___\n");
                printf("_________________________\n");
                printf("��������ɼ�\n");
                printf("c����: ");scanf("%s",&current->c_score);
                c_score1 = atof(current->c_score);
	        } 
	        
	        printf("������Ӣ��ɼ�:");
	        scanf("%s",&current->english_score);
	        float english_score1 = atof(current->english_score);
	        while (english_score1 < 1 || english_score1 > 100){
                printf("_________________________\n");
                printf("___�ɼ�������1-100֮��___\n");
                printf("_________________________\n");
                printf("��������ɼ�\n");
                printf("Ӣ��ɼ�: ");scanf("%s",&current->english_score);
                english_score1 = atof(current->english_score);
            } 
            
			printf("��������ѧ�ɼ�:");
	        scanf("%s",&current->math_score);
	        float math_score1 = atof(current->math_score);
	        while (math_score1 < 1 || math_score1 > 100){
                printf("_________________________\n");
                printf("___�ɼ�������1-100֮��___\n");
                printf("_________________________\n");
                printf("��������ɼ�\n");
                printf("��ѧ: ");scanf("%s",&current->math_score);
                math_score1 = atof(current->math_score);
            }
	        printf("\t\t��ѧ����Ϣ���޸�\n");
	        xr();
		}
		printf("�Ƿ�����޸�ѧ����Ϣ��Y/N��:");
			ch = getch();
			while (ch != 'N' && ch != 'Y'){
				ch = getch();
	          }
	    }while(ch == 'Y');
	      if (a[0] == 'N')
	      return;
	} 
}

//�����ݽ��в��� 
void cr()
{
	system("CLS");
	printf("\n\t\t\t|                  2.ѧ���ɼ�����                    |\n");
	char a[1000];
    printf("\n\t\t\t|              ��Ϣ���루Y���˳�������N��             |\n");
    scanf("%s", a);
    while (strcmp(a,"Y") != 0 && strcmp(a,"N") != 0){
		printf("������ȷѡ�\n"); 
		scanf("%s", &a);
    }
    if (a[0] == 'Y'){ 
		struct student *current, *p;
		p = head;
		current = (struct student*)malloc(LEN);
        
		printf("������ѧ��(8λ)��");
        scanf("%s",current->num);
        int num1 = atoi(current->num);
        while (num1 > 99999999 || num1 < 10000000){
	        printf("______________________\n");
	        printf("____������8λ�Ǹ���___\n");
	        printf("_______________________\n");
	        printf("��������ѧ��:\n ");scanf("%s",&current->num);
	        num1 = atoi(current->num);
        }
        int num2 = atoi(p->next->num);
        if (num2 == num1){
        	free(current);
        	printf("����������������Ѵ��ڣ����������룺\n");
        	Sleep(1000);
        	return;
		} 
    
        printf("������������");
        scanf("%s",current->name);
        while (current->name[0] > 0){
            printf("________________________\n");
            printf("______���������뺺��____\n");
            printf("______________________\n");
            printf("������������: \n");scanf("%s",current->name);
        }
        
        printf("���������䣺");
        scanf("%s",current->age);
        int age1 = atoi(current->age);
        while (age1 < 0  || age1 > 100){
            printf("_________________________\n");
            printf("___����������1-100֮��___\n");
            printf("_________________________\n");
            printf("������������\n");
            printf("����: ");scanf("%s",&current->age);
            age1 = atoi(current->age);
        }
        
        printf("������c���Գɼ���");
        scanf("%s",current->c_score);
        float c_score1 = atof(current->c_score);
        while (c_score1 < 1 || c_score1 > 100){
            printf("_________________________\n");
            printf("___�ɼ�������1-100֮��___\n");
            printf("_________________________\n");
            printf("��������ɼ�\n");
            printf("c����: ");scanf("%s",&current->c_score);
            c_score1 = atof(current->c_score);
        } 
        
        printf("������Ӣ��ɼ�:");
        scanf("%s",current->english_score);
        float english_score1 = atof(current->english_score);
        while (english_score1 < 1 || english_score1 > 100){
            printf("_________________________\n");
            printf("___�ɼ�������1-100֮��___\n");
            printf("_________________________\n");
            printf("��������ɼ�\n");
            printf("Ӣ��ɼ�: ");scanf("%s",&current->english_score);
            english_score1 = atof(current->english_score);
        } 
        
		printf("��������ѧ�ɼ�:");
        scanf("%s",current->math_score);
        float math_score1 = atof(current->math_score);
        while (math_score1 < 1 || math_score1 > 100){
                printf("_________________________\n");
                printf("___�ɼ�������1-100֮��___\n");
                printf("_________________________\n");
                printf("��������ɼ�\n");
                printf("��ѧ: ");scanf("%s",&current->math_score);
                math_score1 = atof(current->math_score);
            }
		current->next = head->next;
		head->next = current;
		printf("\t\tѧ����Ϣ�Ѵ���\n");
		Sleep(1000);
	}
	xr();
}

//�����ݽ���ɾ�� 
void sc()
{
	system("CLS");
	printf("\n\t\t\t|                  3.ѧ���ɼ�ɾ��                     |\n");
	char a[1000];
    printf("\n\t\t\t|              ��Ϣ�޸ģ�Y���˳�������N��             |\n");
    scanf("%s", a); 
    while (strcmp(a,"Y") != 0 && strcmp(a,"N") != 0){
		printf("������ȷѡ�\n"); 
		scanf("%s", &a);
    }
    
    if (a[0] == 'Y'){ 
		struct student *current;
		struct student *prev = head;
		int flag = 0, num;
		printf("\t\t������Ҫɾ����ѧ��ѧ�ţ�");
	    scanf("%d",&num);
	
	    current = prev->next;
	    while (current != NULL){
	    	int num1 = atoi(current->num);
	    	if (num1 == num){
			prev->next = current->next;
			free(current); 
			}
			prev = current;
			current = current->next;
		}
		 
		printf("\t\t��ѧ����Ϣ��ɾ��\n");
		Sleep(1000);
	}
    xr();
} 

//�����ݽ��в�ѯ 
int cx_menu()
{
	system("CLS");
    char n[1000];
    int n1;
    do{
    system("CLS");
    printf("\t\t__________________________________________________\n");
    printf("\t\t|                                                |\n");
    printf("\t\t|                   1.��ѧ�Ų�ѯ                 |\n");
    printf("\t\t|                   2.��������ѯ                 |\n");
    printf("\t\t|                                                |\n");
    printf("\t\t|_____________________�˳��밴3__________________|\n");
    printf("\t\t��ѡ��1-��");
    scanf("%s", n);
    n1 = atoi(n);
    }while(n1 < 1 || n1 > 3);
    return n1;  
}

void cx()
{
    system("CLS");
    char n[1000];
	do {
		switch(cx_menu()) {
			case 3:
			    return;
			case 1:
			    cx1();
			    break;
			case 2:
			    system("CLS");
			    cx2();
			    break;
			
		}
		printf("������ѯ�밴Y���˳��밴N��");
		scanf("%s", n);
		while (strcmp(n,"Y") != 0 && strcmp(n,"N") != 0){
				printf("������ȷѡ�\n"); 
				scanf("%s", n);
        	}
		}while(n[0] =='Y');
		if(n[0] == 'N')
		return;
}

//����ѧ�Ŷ����ݲ�ѯ 
void cx1()
{
	system("CLS"); 
	printf("\t\t|                      1.��ѧ�Ų�ѯ                     |\n");
	char num[1000];
	struct student *current;
	printf("��������Ҫ��ѯ��ѧ��ѧ��");
	scanf("%s", num);
	int num2 = atoi(num);
	while (num2 > 99999999 || num2 < 10000000){
        printf("______________________\n");
        printf("____������8λ�Ǹ���___\n");
        printf("_______________________\n");
        printf("��������ѧ��:\n ");scanf("%s",num);
    }
    
	current = head;
	while (current != NULL){
		int num1 = atoi(current->num);
		if (num1 == num2){
			printf("���ҵ���ѧ����Ϣ\n");  
	        printf("ѧ��ѧ��:%s\n", current->num);  
	        printf("ѧ������:%s\n",current->name);  
	        printf("ѧ������:%s\n",current->age);
	        printf("ѧ��c���Գɼ�:%s\n",current->c_score); 
			printf("ѧ��Ӣ��ɼ�:%s\n",current->english_score);
			printf("ѧ����ѧ�ɼ�:%s\n",current->math_score);
			return;
		}
		current = current->next;	 
	}
	printf("δ�ҵ���ѧ����Ϣ��\n");
	Sleep(1000); 
	xr();
}

//�������������ݲ�ѯ 
void cx2()
{
	system("CLS"); 
	printf("\t\t|                      2.��������ѯ                    |\n");
	char num[20];
	struct student *current;
	printf("��������Ҫ��ѯ��ѧ������:");
	scanf("%s", num);
	while (num[0] > 0){
        printf("________________________\n");
        printf("______���������뺺��____\n");
        printf("______________________\n");
        printf("������������: \n");scanf("%s",current->name);
    }
	current = head;
	while (current != NULL){
		if (strcmp(current->name, num) == 0){
			printf("���ҵ���ѧ����Ϣ\n");  
	        printf("ѧ��ѧ��:%s\n", current->num);  
	        printf("ѧ������:%s\n",current->name);  
	        printf("ѧ������:%s\n",current->age);
	        printf("ѧ��c���Գɼ�:%s\n",current->c_score); 
			printf("ѧ��Ӣ��ɼ�:%s\n",current->english_score);
			printf("ѧ����ѧ�ɼ�:%s\n",current->math_score);
			return;
		}
		current = current->next;	 
	}
	printf("δ�ҵ���ѧ����Ϣ��\n");
	Sleep(1000); 
	xr();
}

//�����ݽ���ͳ�� 
int tj_menu()
{
	system("CLS");
    char n[1000];
    int n1;
    do{
    system("CLS");
    printf("\t\t_______________________________________________________\n");
    printf("\t\t|                                                      |\n");
    printf("\t\t|                      1.Ӣ�Ｐ������                  |\n");
    printf("\t\t|                      2.��ѧ��������                  |\n");
    printf("\t\t|                   3.�ִܷﵽһ��������               |\n");
    printf("\t\t|__________________________��4�˳�_____________________|\n");
    printf("\t\t��ѡ��1-4��");
    scanf("%s", n);
    n1 = atoi(n);
    }while(n1 < 1 || n1 > 4);
    return n1;   
}

void tj()
{
	system("CLS");
    char n[1000];
	do {
		switch(tj_menu()) {
			case 4:
			    return;
			case 1:
			    tj1();
			    break;
			case 2:
			    system("CLS");
			    tj2();
			    break;
			case 3:
			    system("CLS");
			    tj3();
			    break;
		}
		printf("����ͳ���밴Y���˳��밴N��");
		scanf("%s", n);
		while (strcmp(n,"Y") != 0 && strcmp(n,"N") != 0){
				printf("������ȷѡ�\n"); 
				scanf("%s", n);
        	}
		}while(n[0] =='Y');
		if(n[0] == 'N')
		return;	
}

//Ӣ�Ｐ��ͳ�� 
void tj1()
{
	system("CLS");
	printf("\t\t|                        1.Ӣ�Ｐ������                    |\n");
	struct student *current;
	int n = 0;
	current = head;
	while (current != NULL){
		int english_score1 = atof(current->english_score);
		if (english_score1 >= 60){
			n++;
		}
		current = current->next;
	}
    printf("\t\t|____________________ѧ���ɼ�ͳ��_________________________|\n");
    printf("\t\tӢ�Ｐ������Ϊ%d\n", n); 
    printf("\t\tͳ�����\n");
	xr();  
}

//��ѧ����ͳ�� 
void tj2()
{
	system("CLS");
	printf("\t\t|                         2.��ѧ��������                     |\n");
	struct student *current;
	int n = 0;
	current = head;
	while (current != NULL){
		int math_score1 = atof(current->math_score);
		if (math_score1 >= 60){
			n++;
		}
		current = current->next;
	}
    printf("\t\t|____________________ѧ���ɼ�ͳ��_________________________|\n");
    printf("\t\t��ѧ��������Ϊ%d\n", n); 
    printf("\t\tͳ�����\n"); 
	xr(); 
}

//�ּܷ���ͳ�� 
void tj3()
{
	system("CLS");
	printf("\t\t|                      3.�ִܷﵽһ��������                  |\n");
	struct student *current;
	char m[1000];
	int m2;
	printf("��Ҫͳ���ܷ������������ϵ��������ܷ���0-300֮�䣩\n");
	scanf("%s", &m); 
	m2 = atoi(m);
	while (m2 < 1 || m2 > 300){
            printf("_________________________\n");
            printf("___�ܷ�������1-300֮��___\n");
            printf("_________________________\n");
            printf("��Ҫͳ���ܷ������������ϵ��������ܷ���0-300֮�䣩\n");scanf("%s",&m);
            m2 = atoi(m);
    }
        
	int n = 0;
	current = head;
	while (current != NULL){
		int m1 = atof(current->english_score) + atof(current->math_score) + atof(current->c_score);
		if (m1 >= m2){
			n++;
		}
		current = current->next;
	}
    printf("\t\t|____________________ѧ���ɼ�ͳ��_________________________|\n");
    printf("\t\t�ִܷﵽ%s���ϵ���Ϊ%d��\n", m, n); 
    printf("\t\tͳ�����\n");
	xr();  	
} 

//�����ݽ������� 
int px_menu()
{
	system("CLS");
    char n[1000];
    int n1;
    do{
    system("CLS");
    printf("\t\t__________________________________________________________\n");
    printf("\t\t|                                                        |\n");
    printf("\t\t|                      1.Ӣ��ɼ�������                  |\n");
    printf("\t\t|                      2.Ӣ��ɼ��Ľ���                  |\n");
    printf("\t\t|                      3.�ܳɼ�������                    |\n");
    printf("\t\t|___________________________��4�˳�______________________|\n");
    printf("\t\t��ѡ��1-4��");
    scanf("%s", n);
    n1 = atoi(n);
    }while(n1 < 1 || n1 > 4);
    return n1;   
}

void px()
{
	system("CLS");
    char n[1000];
	do {
		switch(px_menu()) {
			case 4:
			    return;
			case 1:
			    px1();
			    break;
			case 2:
			    system("CLS");
			    px2();
			    break;
			case 3:
			    system("CLS");
			    px3();
			    break;
		}
		printf("���������밴Y���˳��밴N��");
		scanf("%s", n);
		while (strcmp(n,"Y") != 0 && strcmp(n,"N") != 0){
				printf("������ȷѡ�\n"); 
				scanf("%s", n);
        	}
		}while(n[0] =='Y');
		if(n[0] == 'N')
		return;	
}

//����Ӣ��ɼ������� 
void px1()
{
	system("CLS"); 
	printf("\t\t|                     1.Ӣ��ɼ�������                        |\n");
	struct student *current, *prev, *p, *q, *x, *y;
	p = NULL;
	q = head;
	if (q->next == NULL && q->next->next == NULL){
		return;
	}
	while (p != q->next->next){
		for (prev = q; prev->next->next != p; prev = prev->next){
			int score1 = atoi(prev->next->english_score);
			int score2 = atoi(prev->next->next->english_score);
			if (score1 > score2){
				x = prev->next;
				y = prev->next->next;
				prev->next = y;
				x->next = y->next;
				y->next = x;
			}
		}
		p = prev->next;
	}
    printf("\t\t                      Ӣ��ɼ�������                                   \n");
    printf("\t\t%10s%10s%10s%10s%10s%10s\n","ѧ��","����","����","c����","Ӣ��","��ѧ");
    printf("\t\t--------------------------------------------------------------\n");
    for(current = q->next; current != NULL; current = current ->next)
    {
        printf("\t\t%10s%10s%10s%10s%10s%10s%\n", current->num, current->name, current->age, current->c_score, current->english_score, current->math_score);
    } 
	xr(); 
}

//����Ӣ��ɼ��Ľ���
void px2()
{
	system("CLS");
	printf("\t\t|                   2.Ӣ��ɼ��Ľ���                     |\n");
	struct student *current, *prev, *p, *q, *x, *y;
	p = NULL;
	q = head;
	if (q->next == NULL && q->next->next == NULL){
		return;
	}
	while (p != q->next->next){
		for (prev = q; prev->next->next != p; prev = prev->next){
			int score1 = atoi(prev->next->english_score);
			int score2 = atoi(prev->next->next->english_score);
			if (score1 < score2){
				x = prev->next;
				y = prev->next->next;
				prev->next = y;
				x->next = y->next;
				y->next = x;
			}
		}
		p = prev->next;
	}
    printf("\t\t                      Ӣ��ɼ��Ľ���                                   \n");
    printf("\t\t%10s%10s%10s%10s%10s%10s\n","ѧ��","����","����","c����","Ӣ��","��ѧ");
    printf("\t\t--------------------------------------------------------------\n");
    for(current = q->next; current != NULL; current = current ->next)
    {
        printf("\t\t%10s%10s%10s%10s%10s%10s%\n", current->num, current->name, current->age, current->c_score, current->english_score, current->math_score);
    } 	
    xr(); 
} 
 
//�����ܳɼ������� 
void px3()
{
	system("CLS");
	printf("\t\t|                    3.�ܳɼ�������                       |\n");
	struct student *current, *prev, *p, *q, *x, *y;
	p = NULL;
	q = head;
	if (q->next == NULL && q->next->next == NULL){
		return;
	}
	while (p != q->next->next){
		for (prev = q; prev->next->next != p; prev = prev->next){
			int score1 = atoi(prev->next->english_score);
			int score2 = atoi(prev->next->math_score);
			int score3 = atoi(prev->next->c_score);
			int score4 = atoi(prev->next->next->english_score);
			int score5 = atoi(prev->next->next->math_score);
			int score6 = atoi(prev->next->next->c_score);
			if (score1 + score2 + score3 > score4 + score5 + score6){
				x = prev->next;
				y = prev->next->next;
				prev->next = y;
				x->next = y->next;
				y->next = x;
			}
		}
		p = prev->next;
	}
    printf("\t\t                      �ܳɼ�������                                   \n");
    printf("\t\t%10s%10s%10s%10s%10s%10s\n","ѧ��","����","����","c����","Ӣ��","��ѧ");
    printf("\t\t--------------------------------------------------------------\n");
    for(current = q->next; current != NULL; current = current ->next)
    {
        printf("\t\t%10s%10s%10s%10s%10s%10s%\n", current->num, current->name, current->age, current->c_score, current->english_score, current->math_score);
    } 
    xr();
}


