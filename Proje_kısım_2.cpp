#include <stdio.h>
#include <stdlib.h>
//							MUSA G�M�� 040170809 VER� YAPILARI VE PROGRAMLAMA -208 CRN:20882

//�ncelikle i�inde 3 de�i�ken bulunduran bir yap� olu�turuldu biri integer de�eri di�er ikisi pointer bilgilerini tutmak i�in.
typedef struct n {
	int x;
	n* sag;
	n* sol;
}node;

//ikili a�aca gelen bilgileri eklemek i�in bir alt fonksiyon olu�turuldu
node* ekle(node* agac, int deger) {
	//�lk ba�ta a�ac�n i�inde hi� bilgi olmamas� durumu
	if (agac == NULL){
		node* root = (node*)malloc(sizeof(node));
		root->x = deger;
		root->sag = NULL;
		root->sol=NULL;
		return root;
	}
	//De�er girilen de�erden k���k ise sa�a ekleme yapmas� i�in gerekli kod
	//E�er bu durum sa�lanmassa bir alta ge�er 
	if (agac->x < deger) {
		//A�ac�n adresini sa� taraftaki de�erinin adresine e�itliyor ve onu tekrar alt programa g�nderiyor.
		agac->sag=ekle(agac->sag, deger);
		return agac;
	}

	//A�ac�n adresini sol aftaki de�erinin adresine e�itliyor ve onu tekrar alt programa g�nderiyor.
		agac->sol=ekle(agac->sol, deger);
		return agac;
	
}
//Pre-order traversal y�ntemini sa�layan kod
//K�kten ba�layarak t�m soldaki de�erleri basan ve soldakiler sona ula��nca en soldaki solun sa��n� kontrol eder.
//Kod bu �ekilde sol taraf� bitirince sa� tarafada ayn� i�lemi uygular.
void bas(node* root) {

	if (root == NULL)
		return;
	printf("%d\n", root->x);
	bas(root->sol);
	bas(root->sag);
}
	
	 
//A�a�taki t�m de�erleri k���kten b�y��e do�ru s�ralamaya yarayan alt program.
void goster(node *agac) {
	//Hi� de�er yoksa alt program� bitirir.
	if (agac == NULL) {
		return;
	}
	//Burada  a�ac�n en soluna kadar iner ve NULL de�erini g�rd�kten sonra alt komuta ge�er bu d�ng� t�m de�erler yaz�lana kadar s�rer.
	goster(agac->sol);
	printf("%d\n",agac->x);
	goster(agac->sag);	
}
//A�a�taki max de�eri bulmak i�in alt program
int max(node* root) {
	while (root->sag != NULL)
		root = root->sag;
	return root->x;
}
//A�a�taki min de�erini bulmak i�in alt program.
int min(node* root) {
	while (root->sol != NULL)
		root = root->sol;
	return root->x;
}

//Se�ilen 4 haneli de�ere g�re silme yapan alt program
node* silme(node* root, int deger) {
	//ilk ba�ta de�er olup olmad���n� kontrol eder.
	if (root == NULL)
		return NULL;
	//K�k teki de�erin arad���m de�er olma olas�l���na kar�� yaz�lm�� kod.
	if ((root->x)%10000 == deger){
		if (root->sol == NULL && root->sag == NULL)
			return NULL;
		//E�er k�k�n de�eri sildi�imiz de�er ise solun en b�y�k de�eri yada sa��n en k���k de�eri 
		//ba�a ge�er.Bunun i�in yaz�lm�� kodlar.
	if (root->sag != NULL) {
		root->x = min(root->sag);
		root->sag = silme(root->sag, min(root->sag)%10000);
		return root;
		}
	root->x = max(root->sol);
	root->sol = silme(root->sol, max(root->sol)%10000);
	return root;
	}
	//Yukar�daki durumlar de�il ise de�ere g�re adres sa��n yada solun adresine e�itlenip tekrar d�ng�ye sokulur.
	if ((root->x)%10000 < deger) {
		root->sag = silme(root->sag, deger);
		return root;
	}
	root->sol= silme(root->sol, deger);
	return root;

}

int main() {
	int secim = 0;
	//olu�turulan pointer�n de�eri s�f�r olarak belirlendi.
		node* agac=NULL;
		//�stenilen program�n ana men�s�.
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
