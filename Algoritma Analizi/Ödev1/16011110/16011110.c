#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
int donus;	//solvable fonksiyonundan d�n�� de�eri 
int tmp1=1000;	//Artt�r�lan ba�lang�� de�eri tmp1
int tmp2=1000;	//Azalt�lan ba�lang�� de�eri de tmp2
int k;
int j=0;
int  solvable(int start,int leapCount[],int n){	
	if(j==n){
		printf("!!!�ok boyutlu loop\n");
		return 0;
	}
	j++;
	if(start<0 || start>=n){ //Start de�i�keninin belirledi�imiz dizi i�inde oldu�unu kontrol ediyor.
		return 0;				
	}
	if(start==n-1){	//Start de�i�keninin son indise ula�t���n� kontrol ediyor.
		return 1;
	}		
	if(leapCount[start]+start>=n){ //start ile indisin de�erinin toplam� n den buyuk olursa bir sola geliyor
		printf("!!!Saga Atla:[%d](+%d):%d(Ooops)\n",start+1,leapCount[start],leapCount[start]+start+1);
		printf("Sola Atla:[%d](-%d):%d\n",start+1,leapCount[start],start-leapCount[start]+1);
		start=start-leapCount[start];
		if(start<0){ //( �rne�in: 1-1-5-1-1) ba�lang�� 3 olarak ayarlan�rsa sa�dan ve soldan s��rama yap�lamaz.
			return 0;
		}	
		tmp1=leapCount[start]; //Artt�r�lan ba�lang�� de�eri tmp1, azalt�lan ba�lang�� de�eri de tmp2 de�i�keninde tutulur.
		if(tmp1==tmp2 ){ //E�er artt�r�mda s�n�r a��l�yorsa ve tmp ler e�it ��karsa bir sola daha kay�l�r.
			if(start+tmp1>=n && start-tmp2<0)
				return 0;				
			else if(start-tmp2>0){ //tmp1 ile tmp2 ayn� de�ilse iki kere sola gidilir
				printf("Sola Atla:[%d](-%d):%d\n",start+1,leapCount[start],start-leapCount[start]+1);
				start=start-leapCount[start];
				donus=solvable(start,leapCount,n);
				if(donus==1) return 1;
				if(donus==0) return 0;				
			}
		}
		else{																	
			donus=solvable(start,leapCount,n);	//tmp1 ile tmp2 ayn� de�ilse bir kere sola gidilir
			if(donus==1) return 1;
			if(donus==0) return 0;
		}
	}
	else{	
		printf("Saga Atla:[%d](+%d):%d\n",start+1,leapCount[start],leapCount[start]+start+1);
		start=leapCount[start]+start;		//start ile indisin de�erinin toplam� n den kucukse		
		tmp2=leapCount[start];		 //Azalt�lan ba�lang�� de�eri tmp2 de�i�keninde tutulur.
		donus=solvable(start,leapCount,n);		//starta yeni de�eri ataniyor
		if(donus==1) return 1;
		if(donus==0) return 0; 
	}	
}
int main(){
					// Dinamik bir dizi yaratmak i�in pointer kullan�l�r.
	int n,i,start,*leapCount;	// Dizimizin kac elemanli olacagini n de, cekirgenin nerden ba�l�yaca��n� startta tutuyorum.i yi indis i�lemlerinde kullan�yorum
	printf( "Cekirgenin atlayacagi tas sayisini giriniz-> ");	// Kullanicidan tas sayisini girmesini istiyoruz.
	scanf( "%d", &n );	//Toplam ta� say�s� girilir
	leapCount= calloc( n, sizeof( int ) );	// calloc( ) fonksiyonuyla dinamik olarak dizi girilen boyuta g�re ayarlan�r. 
	for(i = 0; i < n-1; i++ ){	//Ta�lar�n �st�ndeki say� de�erlerini al�yoruz son ta� haric(0)
		printf( "%d:", i+1 );
		scanf("%d",&leapCount[i]);
	}
	for(i = 0; i < n; i++ ){
		printf( "[%d]:%d--", i+1,leapCount[i] ); //Ta�lar�n �st�ndeki say� de�erlerini yazd�r�yoruz.
	}	
	printf("\nCekirge atlamaya hangi tastan baslasin?[1-%d]:",n); //Start de�i�kenini kullan�c�dan istiyoruz
	scanf("%d",&start);	//Kullan�c� taraf�ndan start de�i�keni giriliyor.
	printf("Start:%d\n", start,leapCount[start]); //Ba�lan�lacak ta�taki bilgi veriliyor
	donus=solvable(start-1,leapCount,n);	//Cekirgenin ta�lardan ��k�p ��kmad��� bilgisi recursive fonksiyon yard�m�yla hesaplan�yor
	if(donus==1){	//Cekirgenin son ta�a ula��p ula�amad��� yazd�r�l�r.
		printf("Exit, cekirge son tasa ulasmayi basardi...\n");	
	}
	else 
		printf("Loop, cekirge son tasa ulasmayi basaramadi...\n");
	free(leapCount);// Dinamik olan diziyi kullandiktan sonra free fonksiyonunu kullan�yorum.
	system("pause");		
	return 0;
	//�mer L�tf� Tortumlu 16011110
}
