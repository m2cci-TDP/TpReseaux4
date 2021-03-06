#ifndef H_UTIL
#define H_UTIL

#define BUFFER_SIZE 2000 /* taille du buffer emission/reception */
#define NB_CON 5 /* nombre de connection serveur TCP */
#define SERVICE_DEFAUT "1111" /* port par défaut */
#define SERVEUR_DEFAUT "127.0.0.1" /* serveur par défaut */

#define CLIENT 1
#define SERVEUR 0

typedef int Mode;

#define PROCESSUS_FILS 0

#define EXIT_CHAR "exit"
#define clearScreen() system("@cls||clear")

char bufferEmission[BUFFER_SIZE+1];
char bufferReception[BUFFER_SIZE+1];

/* cellule de socket */
typedef struct cellSock {
  int socket;
  struct cellSock* pNext;
} cellSock;
typedef cellSock *pCellSock;
/* liste chainée de cellule de socket */
typedef struct {
  int length;
  pCellSock head;
} lSocket;
#define MAP_SIZE sizeof(lSocket)
#define CELL_SIZE sizeof(cellSock)
/* methods */
int getLength (lSocket S); /* return length */
void makeLSocket (lSocket *S); /* constructeur */
void rmLSocket (lSocket *S); /* destructeur */
void addSocket (lSocket *S, int socket); /* add */
void rmSocket (lSocket *S, int socket); /* remove */
int getSocket (lSocket S, int noSocket); /* getter */
void sendToAll (lSocket S, char* message, int bufferSize); /* envoi du message à toutes les sockets en récursif */
void printAll (lSocket S); /* affiche toutes les sockets ouvertes */

void throwSocketReceptionError();
void printUsage();
void exitWithUsage (void);

int isFlag(char* string, char* flag);
int cli (int argc, char *argv[], char **service, char **serveur, Mode* mode);
void getString (char message[]);
void viderBuffer(void);
void sendMessage (int socket, char message[]);
int readPrint (int socket);

#endif
