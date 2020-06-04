#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//										MUSA G�M�� VER� YAPILARI VE PROGRAMLAMA DERS� EHB-208 CRN:20882
//n ad�nda 2 de�i�kenli bir yap� olu�turuldu.
struct n {
	int x;

	n* next;
};
//n adl� yap� art�k node olarakda adland�r�ld�
typedef n node;

//girilen de�erin s�ral�-ba�l� liste �eklinde ba�lanmas�na yarayan alt program
void ekle(node* r) {
	int sayi;
	printf("Enter school number:");
	scanf("%d", &sayi);
	//r nin next adresini son d���me kadar �teler
	while (r->next != NULL)
		r = r->next;
		//r nin nextinin adresi NULL i�it ise r nin i�aret etti�i adresde yeni d���m olu�turlur
	if (r->next == NULL) {
		r->next = (node*)malloc(sizeof(node));
		r = r->next;
		r->x = sayi;
		r->next = NULL;
	}
	printf("\n");
	}

//girilen t�m de�erlerin k���kten b�y��e do�ru s�ralanmas�na yarayan program 
void sirala(node* t) {
	
	int boyut=0;
	int sayac = 0;
	node *r=t;
	while(r->next != NULL){
		r=r->next;
		boyut++;
	}
	//artan eleman say�s�na g�re artan dizi boyutu
	int *dizi=(int *)malloc(sizeof(int)*boyut*2);
	t = t->next;
	int b=0;
	while (t != NULL) {
		sayac++;
		dizi[b] = t->x;
		t = t->next;
		b++;
	}
	
	//Girilen de�erlerin s�ralanmas� i�in kullan�lan s�ralama kodu
	int tut,gecici;
	for (gecici = 1; gecici <= sayac; gecici++)
	{
		for (int i = 0; i < sayac - 1; i++)
		{
			if (dizi[i] > dizi[i + 1])
			{
				tut = dizi[i];
				dizi[i] = dizi[i + 1];
				dizi[i + 1] = tut;
			}
		}
	}
	
	
	
	for (int i = 0; i < sayac; i++) {
		printf("%d\n",dizi[i]);
	}

}


//Girilen de�erlerin son 4 hanesine g�re s�ralama yapan kod
void siralama(node* t) {
	int boyut=0;
	int sayac = 0;
	node *r=t;
	while(r->next != NULL){
		r=r->next;
		boyut++;
	}
	
	int *dizi=(int *)malloc(sizeof(int)*boyut*2);
	t = t->next;
	int b=0;
	while (t != NULL) {
		sayac++;
		dizi[b] = t->x;
		t = t->next;
		b++;
	}
	
	int tut,gecici;
	for (gecici = 1; gecici <= sayac; gecici++)
	{
		for (int i = 0; i < sayac - 1; i++)
		{
			if ((dizi[i]%10000) >( dizi[i + 1]%10000))
			{
				tut = dizi[i];
				dizi[i] = dizi[i + 1];
				dizi[i + 1] = tut;
			}
		}
	}
	
	
	
	for (int i = 0; i < sayac; i++) {
		printf("%d\n",dizi[i]);
	}

}



//�stenilen kodun men�s�
int main() {
	int *dizi;
	int secim = 0;
	node* root;
	root = (node*)malloc(sizeof(node));
	root->next = NULL;
	printf("1-Enter the school number.\n");
	printf("2-Display all school number in ascending order.\n");
	printf("3-Display all school number grouped in year.\n");
	printf("4-Exit\n\n\n\n");

	while (secim != 4) {
		printf("->Enter choice:");
		scanf("%d", &secim);
		switch (secim)
		{
		case 1:
			ekle(root);
			break;
		case 2:
			siralama(root);
			break;
		case 3:
			sirala(root);
			break;
		default:
			break;
		}
	}
	return 0;
}
