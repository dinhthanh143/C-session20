#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct Product{
	int id;
	char name[50];
	int importPrice;
	int sellPrice;
	int amount;
};
int main(){
	int choice,i,j,position,idSet,quantity,min,check,sellAmount,addAmount;
	int revenue=0;
	struct Product list[50];
	char temp[50];
	char findProduct[50];
	while(choice!=9){
		printf("\n\n MENU\n");
		printf("1. Nhap so luong va thong tin san pham.\n");
		printf("2. Hien thi danh sach san pham.\n");
		printf("3. Nhap san pham.\n");
		printf("4. Cap nhat thong tin san pham.\n");
		printf("5. Sap xep san pham theo gia tang dan.\n");
		printf("6. Tim kiem san pham.\n");
		printf("7. Ban san pham (co the nhap so luong can ban).\n");
		printf("8. Doanh thu hien tai.\n");
		printf("9. Thoat.\n");
		printf("moi nhap lua chon: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("moi nhap so luong: ");
				scanf("%d", &quantity);
				for(i=0;i<quantity;i++){
					printf("\n moi nhap thong tin cho san pham voi id %d: \n",i+1);
					printf("ten san pham: ");
					fflush(stdin);
					fgets(list[i].name,sizeof(list[i].name),stdin);
					list[i].name[strcspn(list[i].name,"\n")]='\0';
					printf("gia nhap: ");
					scanf("%d", &list[i].importPrice);
					printf("gia ban: ");
					scanf("%d", &list[i].sellPrice);
					printf("so luong: ");
					scanf("%d", &list[i].amount);
					revenue = revenue - (list[i].amount*list[i].importPrice);
				}
					idSet=0;
				for (i=0;i<quantity;i++){
					idSet++;
					list[i].id=idSet;
				}
				break;
			case 2:
				for(i=0;i<quantity;i++){
					printf("\n thong tin san pham id %d: \n",i+1);
					printf("ten san pham: %s\n",list[i].name);
					printf("gia nhap: %d $\n",list[i].importPrice );
					printf("gia ban: %d $\n",list[i].sellPrice );
					printf("so luong: %d \n",list[i].amount);
				}
				break;	
			case 3:
					check=0;
					fflush(stdin);
					printf("moi nhap ten cho san pham: ");
					fgets(temp,sizeof(temp),stdin);	
					temp[strcspn(temp, "\n")]='\0';
					for(i=0;i<quantity;i++){
						if(strcmp(list[i].name,temp)==0){
							printf("san pham da co trong danh sach \n");
							printf("moi nhap so luong muon them: ");
							scanf("%d", &addAmount);
							list[i].amount += addAmount;
							check++;
						}
					}
					if(check==0){
					strcpy(list[quantity].name,temp);
					printf("moi nhap gia nhap: ");
					scanf("%d", &list[quantity].importPrice);
					printf("moi nhap gia ban: ");
					scanf("%d", &list[quantity].sellPrice);
					printf("moi nhap so luong: ");
					scanf("%d", &list[quantity].amount);
					quantity++;
					idSet=0;
					for (i=0;i<quantity;i++){
						idSet++;
						list[i].id=idSet;
					}	
					}
					break;
			case 4:
				printf("moi nhap id san pham can cap nhat: ");
				scanf("%d", &position);
				if(position<1 || position >quantity){
					printf("vi tri khong hop le.");
					break;	
				}else{
					position--;
					fflush(stdin);
					revenue = revenue - (list[position].amount*list[position].importPrice);
					printf("moi cap nhat ten cho san pham: ");
					fgets(list[position].name,sizeof(list[position].name),stdin);
					list[position].name[strcspn(list[position].name, "\n")]='\0';
					printf("moi cap nhat gia nhap: ");
					scanf("%d", &list[position].importPrice);
					printf("moi cap nhat gia ban: ");
					scanf("%d", &list[position].sellPrice);
					printf("moi cap nhat so luong: ");
					scanf("%d", &list[position].amount);
					revenue= revenue + (sellAmount*list[position].sellPrice);
				}	
				break;
			
			case 5:
				for(i=0;i<quantity;i++){
					min= list[i].sellPrice;
					for(j=i+1;j<quantity;j++){
						if(list[j].sellPrice<min){
						min= list[j].sellPrice;
						list[j].sellPrice=list[i].sellPrice;
						list[i].sellPrice=min;
						strcpy(temp, list[j].name);
						strcpy(list[j].name, list[i].name);
						strcpy(list[i].name, temp);
						}
					}
				}
				printf("danh sach san pham sau khi sap xep:\n");
				for(i=0;i<quantity;i++){
					printf("\n thong tin san pham id %d: \n",i+1);
					printf("ten san pham: %s\n",list[i].name);
					printf("gia nhap: %d $\n",list[i].importPrice );
					printf("gia ban: %d $\n",list[i].sellPrice );
					printf("so luong: %d \n",list[i].amount);
				}
				break;
			case 6:
					check=0;
					printf("moi nhap ten san pham muon tim: ");
					fflush(stdin);
					fgets(findProduct,sizeof(findProduct),stdin);	
					findProduct[strcspn(findProduct, "\n")]='\0';
				for(i=0;i<quantity;i++){
					if(strcmp(list[i].name,findProduct)==0){
						printf("san pham ban muon tim co id la: %d", list[i].id);
						check++;
					}
				}
				if(check==0){
					printf("\n khong co san pham ban muon tim");
				}	
				break;
				
			case 7:
				printf("moi nhap id san pham muon ban: ");
				scanf("%d", &position);
				if(position<1 || position >quantity){
					printf("id khong hop le.");
					break;	
				}else{
					printf("moi nhap so luong muon ban: ");
					scanf("%d", &sellAmount);
					if(sellAmount>list[position].amount){
						printf("\n khong con du hang");
						break;
					}
					if(sellAmount==0){
						printf("\n het hang");
						break;
					}
					position--;
					list[position].amount -= sellAmount;
					revenue= revenue + (sellAmount*list[position].sellPrice);
				}
				break;
				
			case 8:
				printf("\ndoanh thu hien tai: %d $", revenue);
				break;
				
			case 9:
				return 1;
				
			default:
				printf("\n lua chon khong hop le");
		}
	}

   return 0;
}

