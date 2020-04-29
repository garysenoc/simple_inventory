#include <stdio.h>

struct part{
	int number;
	char name[25];
	int on_hand;
}inventory[100];

int num_parts = 0;

void insert();
void update();
void search();
void print();


int main(){

char operation;

while(1){
	system("cls");
	printf("Enter operation code: ");
	fflush(stdin);
	scanf("%c",&operation);
	
	switch(operation){
		case 'i':
			insert();
			break;
		case 's':
			search();
			break;
		case 'u':
			update();
			break;
		case 'p':
			print();
			break;
	}
}

	return 0;
}

void insert(){
	printf("Enter part number: ");
	scanf("%d",&inventory[num_parts].number);
	printf("Enter part name: ");
	fflush(stdin);
	gets(inventory[num_parts].name);
	printf("Enter quantity on hand: ");
	scanf("%d",&inventory[num_parts].on_hand);
	num_parts++;
	getch();
}
	
void search(){
	int num,i,flag=0;
	
	printf("Enter part number: ");
	scanf("%d",&num);
	
	for(i=0;i<num_parts;i++){
		if(inventory[i].number == num){
			printf("Part name: %s: \n",inventory[i].name);
			printf("Quantity on hand: %d",inventory[i].on_hand);
			flag = 1;
			break;
		}
	}
	if(flag==0)
		printf("Part not found.");
	getch();
}

void update(){
	int num,quan,i,flag=0;
	
	printf("Enter part number: ");
	scanf("%d",&num);
	for(i=0;i<num_parts;i++){
		if(num==inventory[i].number){
			printf("Enter change in quantity on hand: ");
			scanf("%d",&quan);
			inventory[i].on_hand +=quan;
			flag=1;
		}
	}
	if(flag==0)
		printf("Part not found.");
		getch();
}
void print(){
	int i;
	
	printf("Part number\tPart Name\tQuantity on Hand\n");
	for(i=0;i<num_parts;i++)
		printf("%5d%18s%20d\n",inventory[i].number,inventory[i].name,inventory[i].on_hand);
		getch();
}

