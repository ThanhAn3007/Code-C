#include<stdio.h>
#include<conio.h>
#define Maxlength 30

/*========== Khai  bao danh sach dac =========*/
typedef int ElementType;
typedef int Position;
typedef struct{
	ElementType Elements[Maxlength];
	Position Last;
}List;
/*=========== Ket thuc khai bao ===========*/

// Tao rong danh sach
void MakeNull_List(List *L){
	L->Last = 0;
}

//Ham kiem tra danh sach rong
int Empty_List(List L){
	return (L.Last == 0);
}

//Ham kiem tra danh sach day
int Fulll_List(List L){
	return (L.Last == Maxlength);
}

//Ham tra ve vi tri phan tu dua tien trong danh sach
Position FirstList(List L){
	return 1;
}

//Ham tra ve vi tri sau phan tu cuoi trong danh sach
Position EndList(List L){
	return L.Last+1;
}

//Ham tra ve vi tri phan tu ke tiep phan tu P trong danh sach L
Position Next(Position P,List L){
	return P+1;
}

//Ham tra ve vi tri phan tu truoc vi tri P trong danh sach L
Position Previous(Position P, List L){
	return L.Elements[P-1];
}

//Ham tra ve noi dung tai vi tri P trong danh sach L
ElementType Retrieve(Position P,List L){
	return L.Elements[P-1];
}
//Them phan tu co noi dung X vao tia vi tri P trong danh sach L
void Insert_List(ElementType X,Position P,List *L){
	int i=0;
	if(L->Last == Maxlength){
		printf("\nDanh sach day!!!");
	}
	else if ((P<1) ||(P>L->Last+1)){
		printf("\nVi tri khong hop le!!!");
	}
	else{
		for(i=L->Last;i>=P;i--){
			L->Elements[i] = L->Elements[i-1];
		}
		L->Last++;
		L->Elements[P-1] = X;
	}
}

//Xoa phan tu tai vi tri P trong danh sach L
void Delete_List(Position P, List *L){
	if ((P>L->Last) || (P<1)){
		printf("\nVi tri khong hop le!!");
	}
	else{
		if(Empty_List(*L)){
			printf("\nDanh sach rong!");
		}
		else{
			Position i;
			for(i=P;i<L->Last;i++){
				L->Elements[i-1] = L->Elements[i];
			}
			L->Last--;
		}
	}
}

//In danh sach L ra man hinh
void Print_List(List L){
	Position P;
	P= FirstList(L);
	printf("\nBat dau in danh sach ");
	while(P != EndList(L)){
		printf("\n%d ",Retrieve(P,L));
		P=Next(P,L);
	}
	printf("\nKet thuc in danh sach\n");
}

//Nhap danh sach tu ban phim
void Read_List(List *L){
	int i,N;
	ElementType X;
	MakeNull_List(L);
	printf("\nNhap vao so phan tu trong danh sach: ");
	scanf("%d",&N);fflush(stdin);
	for(i=1;i<=N;i++){
		printf("\nPhan tu thu %d la ",i);
		scanf("%d",&X);fflush(stdin);
		Insert_List(X,EndList(*L),L);
	}
}

//Hàm tìm vi trí phan tu dua tien co noi dung X trong danh sach 
Position Locate(ElementType X, List L){
	Position P;
	int found =0;
	P=FirstList(L);
	while(P!=EndList(L) &&(found == 0)){
		if(Retrieve(P,L) == X){
			found =1;
		}
		else{
			P=Next(P,L);
		}
	}
	return P;
}

