#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define DIVLJACI 20
#define OBROCI 3

sem_t semaforZaPrazanLonac;
sem_t semaforZaPunLonac;
sem_t mutex;

void *fDivljak();
void *fKuvar();

int obroci;
int gotoveNiti;

void *fKuvar() {
    while(1==1) {
        sem_wait(&semaforZaPrazanLonac);
        obroci += OBROCI;

        printf("\n\t===============================\n");
        printf("\tKuvar je ubacio %d obroka u lonac\n", OBROCI);
        printf("\t===============================\n");
        sem_post(&semaforZaPunLonac);
    }

    return;
}

void *fDivljak() {

    sem_wait(&mutex);
    sleep(1);

    if(obroci <= 0) {
        printf("\n\t===============================\n");
        printf("\tNema vise hrane, kuvar je pozvan\n");
        printf("\t===============================\n");        
        sleep(1);
        sem_post(&semaforZaPrazanLonac);
        sem_wait(&semaforZaPunLonac);
    }
        
    obroci--;
        
    sem_post(&mutex);

    sleep(1);
    gotoveNiti++;

    printf("\n\t===============================\n");
    printf("\tDivljak je sit, odlazi da odmara!\n");
    printf("\tOstalo je jos %d gladnih!\n", DIVLJACI-gotoveNiti);
    printf("\t===============================\n");  
    return;
}

int main() {

    obroci = OBROCI;
    gotoveNiti = 0;

    pthread_t divljaci[DIVLJACI];
    pthread_t kuvar;

    sem_init(&mutex, 0, 1);
    sem_init(&semaforZaPrazanLonac, 0, 0);
    sem_init(&semaforZaPunLonac,  0, 0);

    pthread_create(&kuvar, NULL, fKuvar, NULL);

    for(int i=0; i<DIVLJACI; i++) {
        pthread_create(&divljaci[i], NULL, fDivljak, NULL);
    }

    for(int j=0; j<DIVLJACI; j++) {
        pthread_join(divljaci[j], NULL);
    }

    printf("\n\t===============================\n");
    printf("\tSvi su siti! Kuvar ide kuci!\n");
    printf("\t===============================\n");     

}