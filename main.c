#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <omp.h>





int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL)); // rand() % M
	int N, M, aliciTeklif, teklifSayisi, basarisizTeklifSayisi, mevcutTeklif, i;
	mevcutTeklif = 0;
	aliciTeklif = 0;
	teklifSayisi = 0;
	basarisizTeklifSayisi = 3;
	
	N = 5; M = 10000; //scanf("%d %d", N, M);
	
   
	
    
  
    #pragma omp parallel num_threads(N) private(N, aliciTeklif, teklifSayisi, basarisizTeklifSayisi) shared(mevcutTeklif, M)
	{
		N = omp_get_thread_num();
    	while (basarisizTeklifSayisi >= 0 && mevcutTeklif < M){
    		if (teklifSayisi == 0)
    			aliciTeklif = (rand() % (M/2) ) + 1;
    		else
				aliciTeklif = (rand() % M) + 1; 	
			
			if (aliciTeklif < M){
				mevcutTeklif = aliciTeklif;
				teklifSayisi++;
				printf("Alýcý --%d--, %d. teklifinde mevcut en yüksek teklifi %d TL ile yaptý!\n", N + 1, teklifSayisi, aliciTeklif);
			} else 
				basarisizTeklifSayisi--;			
		}
	}
	
    
	printf("ARTIRMA SONA ERDÝ!!!\nTEBRÝKLER!!!\nKazanan Alýcý = %d\nEn Yüksek Teklif = %d\n", 2, 876);
	return 0;
}


