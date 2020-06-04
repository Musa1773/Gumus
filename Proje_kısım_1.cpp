#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//										MUSA GÜMÜÞ VERÝ YAPILARI VE PROGRAMLAMA DERSÝ EHB-208 CRN:20882
//n adýnda 2 deðiþkenli bir yapý oluþturuldu.
struct n {
	int x;

	n* next;
};
//n adlý yapý artýk node olarakda adlandýrýldý
typedef n node;

//girilen deðerin sýralý-baðlý liste þeklinde baðlanmasýna yarayan alt program
void ekle(node* r) {
	int sayi;
	printf("Enter school number:");
	scanf("%d", &sayi);
	//r nin next adresini son düðüme kadar öteler
	while (r->next != NULL)
		r = r->next;
		//r nin nextinin adresi NULL iþit ise r nin iþaret ettiði adresde yeni düðüm oluþturlur
	if (r->next == NULL) {
		r->next = (node*)malloc(sizeof(node));
		r = r->next;
		r->x = sayi;
		r->next = NULL;
	}
	printf("\n");
	}

//girilen tüm deðerlerin küçükten büyüðe doðru sýralanmasýna yarayan program 
void sirala(node* t) {
	
	int boyut=0;
	int sayac = 0;
	node *r=t;
	while(r->next != NULL){
		r=r->next;
		boyut++;
	}
	//artan eleman sayýsýna göre artan dizi boyutu
	int *dizi=(int *)malloc(sizeof(int)*boyut*2);
	t = t->next;
	int b=0;
	while (t != NULL) {
		sayac++;
		dizi[b] = t->x;
		t = t->next;
		b++;
	}
	
	//Girilen deðerlerin sýralanmasý için kullanýlan sýralama kodu
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


//Girilen deðerlerin son 4 hanesine göre sýralama yapan kod
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



//Ýstenilen kodun menüsü
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
