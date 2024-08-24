#include<stdio.h>
#include<string.h>
#define N 9
#define M 2
main()
{
	struct product
	{
		char brname[10],proname[10],colour[10],dealer[10],category[10];
		int proid,price,stock,offer;
	}p[N];
	struct details
	{
		int ID;
		char name[20],add[50];
		/*struct list
		{
			char review[100];
			int rating,date,month,year;
		}l*/
	}d[N];
	int i;
	FILE *P;
	//product details input in file
	/*P=fopen("product","w");
	for(i=0;i<N;i++)
	{
		printf("enter category:");
		scanf("%s",&p[i].category);
		printf("enter product name:");
		scanf("%s",&p[i].proname);
		printf("enter brand name:");
		scanf("%s",&p[i].brname);
		printf("enter colour:");
		scanf("%s",&p[i].colour);
		printf("enter dealer name:");
		scanf("%s",&p[i].dealer);
		printf("enter product identification number:");
		scanf("%d",&p[i].proid);
		printf("enter price:");
		scanf("%d",&p[i].price);
		printf("enter stock:");
		scanf("%d",&p[i].stock);
		printf("enter offer:");
		scanf("%d",&p[i].offer);
		fprintf(P,"%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",p[i].category,p[i].proname,p[i].brname,p[i].colour,p[i].dealer,p[i].proid,p[i].price,p[i].stock,p[i].offer);
	}
	fclose(P);
	//purchaser's details input in file
	P=fopen("details","w");
	for(i=0;i<5;i++)
	{
		printf("enter name:");
		scanf("%s",d[i].name);
		printf("enter id:");
		scanf("%d",&d[i].ID);
		printf("enter address:");
		scanf("%s",d[i].add);
		fprintf(P,"%s\t%d\t%s\n",d[i].name,d[i].ID,d[i].add);
	}
	fclose(P);*/
	//Q1.
	P=fopen("product","r");
	for(i=0;i<N;i++)
	{
		fscanf(P,"%s%s%s%s%s%d%d%d%d",&p[i].category,&p[i].proname,&p[i].brname,&p[i].colour,&p[i].dealer,&p[i].proid,&p[i].price,&p[i].stock,&p[i].offer);
	}
		printf("1.Category\n2.product name\n3.colour\n4.Brand name\n");
		printf("search by:");
		int s;
		char cat[10],prname[10],col[10],brname[10];
		scanf("%d",&s);
		switch(s)
		{
			case 1:
				printf("enter category:");
				scanf("%s",cat);
				for(i=0;i<N;i++)
				{
					if(strcmp(cat,p[i].category)==0)
					{
						printf("%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",p[i].proname,p[i].brname,p[i].colour,p[i].dealer,p[i].proid,p[i].price,p[i].stock,p[i].offer);
					}
				}
				break;
			case 2:
				printf("enter product name:");
				scanf("%s",&prname);
				for(i=0;i<N;i++)
				{
					if(strcmp(prname,p[i].proname)==0)
					{
						printf("%s\t\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",p[i].category,p[i].brname,p[i].colour,p[i].dealer,p[i].proid,p[i].price,p[i].stock,p[i].offer);
					}
				}
				break;
			case 3:
				printf("enter colour:");
				scanf("%s",&col);
				for(i=0;i<N;i++)
				{
					if(strcmp(col,p[i].colour)==0)
					{
						printf("%s\t\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",p[i].category,p[i].proname,p[i].brname,p[i].dealer,p[i].proid,p[i].price,p[i].stock,p[i].offer);
					}
				}
				break;
			case 4:
				printf("enter brand name:");
				scanf("%s",&brname);
				for(i=0;i<N;i++)
				{
					if(strcmp(brname,p[i].brname)==0)
					{
						printf("%s\t\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",p[i].category,p[i].proname,p[i].colour,p[i].dealer,p[i].proid,p[i].price,p[i].stock,p[i].offer);
					}
				}
				break;
		
	}
	
	//Q4.Registration
	char r,name[30],add[30];
	int no,id;
	printf("Are you new?(Y/N):");
	scanf("%s",&r);
	if(r=='Y')
	{
		printf("enter name:");
		scanf("%s",&name);
		printf("enter mobile no.:");
		scanf("%d",&no);
		printf("enter address:");
		scanf("%s",&add);
		printf("enter id:");
		scanf("%d",&id);
	}
	
	//Q5.Products with available offer
	printf("Products with available offer:\n");
	for(i=0;i<N;i++)
	{
		if(p[i].offer!=0)
		{
			printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",p[i].category,p[i].proname,p[i].brname,p[i].colour,p[i].dealer,p[i].proid,p[i].price,p[i].stock);
		}
	}
	
	//Q2.Recommendation
	char a[10],b;
	int j;
	printf("Enter product name:");
	scanf("%s",a);
	for(i=0;i<N;i++)
	{
		if(strcmp(a,p[i].proname)==0)
		{
			printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",p[i].category,p[i].proname,p[i].brname,p[i].colour,p[i].dealer,p[i].proid,p[i].price,p[i].stock,p[i].offer);
			printf("Do you want to buy?(Y/N):");
			scanf("%s",&b);
			if(b=='Y')
			{
				for(j=0;j<N;j++)
				{
					if(strcmp(p[i].brname,p[j].brname)==0)
					{
						printf("%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n",p[j].category,p[j].proname,p[j].colour,p[j].dealer,p[j].proid,p[j].price,p[j].stock,p[j].offer);
					}
				}
			}
		}
	}
	fclose(P);
	return 0;
}
