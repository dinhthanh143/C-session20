#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct Book{
	int id;
	char name[30];
	char author[30];
	int price;
	
};

int main(){
	int choice,i,j,position,idSet,min;
	char findBook[30];
	char temp[30];
	int check=0;
	int quantity=0;
	struct Book shelf[100];
	while (choice!=8){
		printf("\n\n MENU\n");
		printf("1.Nhap so luong va thong tin sach.\n");
		printf("2.Hien thi thong tin sach.\n");
		printf("3.Them sach vao vi tri.\n");
		printf("4.Xoa sach theo ma sach.\n");
		printf("5.Cap nhat thong tin sach theo ma sach.\n");
		printf("6.Sap xep sach theo gia tang dan.\n");
		printf("7.Tim kiem sach theo ten sach.\n");
		printf("8.Thoat\n");
		printf("moi nhap lua chon: ");
		scanf("%d", &choice);
	
		switch(choice){
			case 1:
				printf("moi nhap so luong: ");
				scanf("%d", &quantity);
				for(i=0;i<quantity;i++){
					printf("\n moi nhap thong tin cho sach voi id %d: \n",i+1);
					printf("ten sach: ");
					fflush(stdin);
					fgets(shelf[i].name,sizeof(shelf[i].name),stdin);
					shelf[i].name[strcspn(shelf[i].name,"\n")]='\0';
					fflush(stdin);
					printf("ten tac gia: ");
					fgets(shelf[i].author,sizeof(shelf[i].author),stdin);
					shelf[i].author[strcspn(shelf[i].author,"\n")]='\0';
					printf("gia: ");
					scanf("%d", &shelf[i].price);
				}
				idSet=0;
				for (i=0;i<quantity;i++){
					idSet++;
					shelf[i].id=idSet;
				}
			
				break;
				
			case 2:
				for(i=0;i<quantity;i++){
					printf("\n thong tin sach id %d: \n",i+1);
					printf("ten sach: %s\n",shelf[i].name);
					printf("ten tac gia: %s\n",shelf[i].author);
					printf("gia: %d $\n",shelf[i].price );
				}
				break;
				
			case 3:
				printf("moi nhap vi tri muon them(id): ");
				scanf("%d", &position);
				if(position<1 || position >quantity+1){
					printf("vi tri khong hop le.");
					break;	
				}else{
					position--;
					for (i=quantity;i>position;i--){
						strcpy(shelf[i].name, shelf[i-1].name);
						strcpy(shelf[i].author, shelf[i-1].author);
						shelf[i].price=shelf[i-1].price;
					}
					fflush(stdin);
					printf("moi nhap ten cho sach muon them: ");
					fgets(shelf[position].name,sizeof(shelf[position].name),stdin);
					shelf[position].name[strcspn(shelf[position].name, "\n")]='\0';
					fflush(stdin);
					printf("moi nhap ten cho tac gia: ");
					fgets(shelf[position].author,sizeof(shelf[position].author),stdin);
					shelf[position].author[strcspn(shelf[position].author, "\n")]='\0';
					printf("moi nhap gia: ");
					scanf("%d", &shelf[position].price);
					quantity++;
					idSet=0;
					for (i=0;i<quantity;i++){
						idSet++;
						shelf[i].id=idSet;
					}
				}
				break;
				
			case 4:
				printf("moi nhap id sach can xoa: ");
				scanf("%d", &position);
				if(position<1 || position >quantity){
					printf("vi tri khong hop le.");	
				}else{
					position--;
					for(i=position;i<quantity;i++){
						strcpy(shelf[i].name, shelf[i+1].name);
						strcpy(shelf[i].author, shelf[i+1].author);
						shelf[i].price=shelf[i+1].price;
					}	
						quantity--;		
					idSet=0;
					for (i=0;i<quantity;i++){
						idSet++;
						shelf[i].id=idSet;
					}
				}
					break;
			case 5:
				printf("moi nhap id sach can cap nhat: ");
				scanf("%d", &position);
				if(position<1 || position >quantity){
					printf("vi tri khong hop le.");
				break;	
				}else{
					position--;
					fflush(stdin);
					printf("moi cap nhat ten cho sach: ");
					fgets(shelf[position].name,sizeof(shelf[position].name),stdin);
					shelf[position].name[strcspn(shelf[position].name, "\n")]='\0';
					fflush(stdin);
					printf("moi cap nhat tac gia cho sach: ");
					fgets(shelf[position].author,sizeof(shelf[position].author),stdin);
					shelf[position].author[strcspn(shelf[position].author, "\n")]='\0';
					printf("moi cap nhat gia: ");
					scanf("%d", &shelf[position].price);
				}	
				break;
			
			case 6:
				for(i=0;i<quantity;i++){
					min= shelf[i].price;
					for(j=i+1;j<quantity;j++){
						if(shelf[j].price<min){
						min= shelf[j].price;
						shelf[j].price=shelf[i].price;
						shelf[i].price=min;
						strcpy(temp, shelf[j].name);
						strcpy(shelf[j].name, shelf[i].name);
						strcpy(shelf[i].name, temp);
						strcpy(temp, shelf[j].author);
						strcpy(shelf[j].author, shelf[i].author);
						strcpy(shelf[i].author, temp);
						}
					}
				}
				printf("danh sach Sach sau khi sap xep:\n");
				for(i=0;i<quantity;i++){
					printf("\n thong tin sach id %d: \n",i+1);
					printf("ten sach: %s\n",shelf[i].name);
					printf("ten tac gia: %s\n",shelf[i].author);
					printf("gia: %d $\n",shelf[i].price );
				}
				break;
			
			case 7:	
					check=0;
					printf("moi nhap ten sach muon tim: ");
					fflush(stdin);
					fgets(findBook,sizeof(findBook),stdin);	
					findBook[strcspn(findBook, "\n")]='\0';
				for(i=0;i<quantity;i++){
					if(strcmp(shelf[i].name,findBook)==0){
						printf("sach ban muon tim co id la: %d", shelf[i].id);
						check++;
					}
				}
				if(check==0){
					printf("\n khong co sach ban muon tim");
				}	
				break;
			
			case 8:
				return 1;
				
			default:
			printf("\nlua chon khong hop le ");	
		}
	}

   return 0;
}

