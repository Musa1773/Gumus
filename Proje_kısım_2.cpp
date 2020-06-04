#include <stdio.h>
#include <stdlib.h>
//							MUSA GÜMÜÞ 040170809 VERÝ YAPILARI VE PROGRAMLAMA -208 CRN:20882

//Öncelikle içinde 3 deðiþken bulunduran bir yapý oluþturuldu biri integer deðeri diðer ikisi pointer bilgilerini tutmak için.
typedef struct n {
	int x;
	n* sag;
	n* sol;
}node;

//ikili aðaca gelen bilgileri eklemek için bir alt fonksiyon oluþturuldu
node* ekle(node* agac, int deger) {
	//Ýlk baþta aðacýn içinde hiç bilgi olmamasý durumu
	if (agac == NULL){
		node* root = (node*)malloc(sizeof(node));
		root->x = deger;
		root->sag = NULL;
		root->sol=NULL;
		return root;
	}
	//Deðer girilen deðerden küçük ise saða ekleme yapmasý için gerekli kod
	//Eðer bu durum saðlanmassa bir alta geçer 
	if (agac->x < deger) {
		//Aðacýn adresini sað taraftaki deðerinin adresine eþitliyor ve onu tekrar alt programa gönderiyor.
		agac->sag=ekle(agac->sag, deger);
		return agac;
	}

	//Aðacýn adresini sol aftaki deðerinin adresine eþitliyor ve onu tekrar alt programa gönderiyor.
		agac->sol=ekle(agac->sol, deger);
		return agac;
	
}
//Pre-order traversal yöntemini saðlayan kod
//Kökten baþlayarak tüm soldaki deðerleri basan ve soldakiler sona ulaþýnca en soldaki solun saðýný kontrol eder.
//Kod bu þekilde sol tarafý bitirince sað tarafada ayný iþlemi uygular.
void bas(node* root) {

	if (root == NULL)
		return;
	printf("%d\n", root->x);
	bas(root->sol);
	bas(root->sag);
}
	
	 
//Aðaçtaki tüm deðerleri küçükten büyüðe doðru sýralamaya yarayan alt program.
void goster(node *agac) {
	//Hiç deðer yoksa alt programý bitirir.
	if (agac == NULL) {
		return;
	}
	//Burada  aðacýn en soluna kadar iner ve NULL deðerini gördükten sonra alt komuta geçer bu döngü tüm deðerler yazýlana kadar sürer.
	goster(agac->sol);
	printf("%d\n",agac->x);
	goster(agac->sag);	
}
//Aðaçtaki max deðeri bulmak için alt program
int max(node* root) {
	while (root->sag != NULL)
		root = root->sag;
	return root->x;
}
//Aðaçtaki min deðerini bulmak için alt program.
int min(node* root) {
	while (root->sol != NULL)
		root = root->sol;
	return root->x;
}

//Seçilen 4 haneli deðere göre silme yapan alt program
node* silme(node* root, int deger) {
	//ilk baþta deðer olup olmadýðýný kontrol eder.
	if (root == NULL)
		return NULL;
	//Kök teki deðerin aradýðým deðer olma olasýlýðýna karþý yazýlmýþ kod.
	if ((root->x)%10000 == deger){
		if (root->sol == NULL && root->sag == NULL)
			return NULL;
		//Eðer kökün deðeri sildiðimiz deðer ise solun en büyük deðeri yada saðýn en küçük deðeri 
		//baþa geçer.Bunun için yazýlmýþ kodlar.
	if (root->sag != NULL) {
		root->x = min(root->sag);
		root->sag = silme(root->sag, min(root->sag)%10000);
		return root;
		}
	root->x = max(root->sol);
	root->sol = silme(root->sol, max(root->sol)%10000);
	return root;
	}
	//Yukarýdaki durumlar deðil ise deðere göre adres saðýn yada solun adresine eþitlenip tekrar döngüye sokulur.
	if ((root->x)%10000 < deger) {
		root->sag = silme(root->sag, deger);
		return root;
	}
	root->sol= silme(root->sol, deger);
	return root;

}

int main() {
	int secim = 0;
	//oluþturulan pointerýn deðeri sýfýr olarak belirlendi.
		node* agac=NULL;
		//Ýstenilen programýn ana menüsü.
		printf("1-Enter the school number.\n");
		printf("2-Delete an entry\n");
		printf("3-Visit all the entered school numbers in ascending order.\n");
		printf("4-Pre-order Traversal.\n");
		printf("5-Exit\n\n\n\n");

		while (secim != 5) {
			printf("->Enter choice:");
			scanf("%d", &secim);
			switch (secim)
			{
			case 1:
				printf("Enter the school number:");
				int a;
				scanf("%d", &a);
				agac=ekle(agac,a);
				break;
			case 2:
				if (agac != NULL) {
				printf("Enter the last 4 digits of the school number which want to delete:");
				int b;
					scanf("%d", &b);
					agac = silme(agac, b);
				}
				else
				{
					printf("There are not any value in memory.\n");
				}
				break;
			case 3:
				goster(agac);
				break;
			case 4:
				bas(agac);
				break;
			default:
				break;
			}
		}

		
		return 0;
	}
