//
//  main.c.c
//  Assignment_3CMPT300
//
//  Created by Pranjal Keshari on 2020-02-14.
//  Copyright © 2020 Pranjal. All rights reserved.
//

//#################################################################################################################################################################################################################################//

#define Temporary_VARIABLE1 0
#define Temporary_VARIABLE2 0
#define Temporary_VARIABLE3 0
#define CALCULATETHREADNUMBER 4
#define UPTOSIZEOFMESSAGELEGTH 256
#define _POSIX_C_SOURCE 200112L
#define DEFININGIT 1

//#################################################################################################################################################################################################################################//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/poll.h>      
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <limits.h> 
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>  
#include <signal.h>     
#include <sys/types.h>
#include <ctype.h>     
#include "myFunction.h"


//#################################################################################################################################################################################################################################//

//It is use for create a Data Type
typedef enum {
    TALKER = 0,    
    LISTENER,     
    REVERT    
} enumCreated;


//#################################################################################################################################################################################################################################//

//Use to save data for the messages that we are sendinding and receiving by defining its type
typedef struct structCreatedHere {
    enumCreated type;
    char messageCreated[UPTOSIZEOFMESSAGELEGTH];
} structCreatedHere;

//#################################################################################################################################################################################################################################//


//Description of the socket and its number. Also, tell us the address information of socket
typedef struct descriptionSocket {
    int tempSocketCreated;     
    struct addrinfo *endAddressDetails;
} descriptionSocket;


//#################################################################################################################################################################################################################################//


//Variable defined for later use
static list *temporaryQue1;
static list *temporaryQue2SendingHere;
static descriptionSocket *VariableSockDeatils;
static sem_t variable_printing;
static sem_t variable_sending;

//#################################################################################################################################################################################################################################//

//Variable defined for later use
static pthread_mutex_t variable_printing_for_mutex;
static pthread_mutex_t variable_sending_for_mutex;
static int later_use_variable;

//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
int helpingFunctionToConvertStringIntoInteger(const char *tempString1) {
    char *variableToKeepTrackEndPointer;
    errno = 0;
    long l = strtol(tempString1, &variableToKeepTrackEndPointer, 0);
    
    if (errno == ERANGE || (*variableToKeepTrackEndPointer != '\0' && *variableToKeepTrackEndPointer != '\n' && *variableToKeepTrackEndPointer != '\r') || tempString1 == variableToKeepTrackEndPointer) {
        return -1;
    }
    
    if (l < INT_MIN || l > INT_MAX) {
        return -2;
    }
    return (int) l;
}


//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
int helperFunctionToConvertCharacterPortsIntoInt(char *temptMYPORT, char *temptREMOTEPORT, int *Var1MYPORT, int *Var1REMOTEPORT) {
    
    if (!Var1MYPORT || !Var1REMOTEPORT)
        return 1;
    int VariableForIntegrCount;
    int badParam_bool = 0;
    if ((VariableForIntegrCount = helpingFunctionToConvertStringIntoInteger(temptMYPORT)) < 0) {
        fprintf(stderr, "Not able to convert myport to integer value: %d\n", VariableForIntegrCount);
        badParam_bool = 1;
    } else
        *Var1MYPORT = VariableForIntegrCount;
    if ((VariableForIntegrCount = helpingFunctionToConvertStringIntoInteger(temptREMOTEPORT)) < 0) {
        fprintf(stderr, "Not able to convert remoteport to integer value: %d\n", VariableForIntegrCount);
        badParam_bool = 1;
    } else
        *Var1REMOTEPORT = VariableForIntegrCount;

    if (!badParam_bool) {
        if (*Var1MYPORT < 1025 || *Var1MYPORT > 65535 || *Var1REMOTEPORT < 1025 || *Var1REMOTEPORT > 65535) {
            badParam_bool = 1;
        }
    }
    return badParam_bool;
}

//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
int helperFunctionToCheckEmpty() {
    struct pollfd temp3Stur;
    temp3Stur.fd = 0;      
    temp3Stur.events = POLLIN;
    if (poll(&temp3Stur, 1, 0) != 1)
        return 0;
    else return 1;
}


//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
int helperFunctionTokeping_track(int variable1, char instant2, int temp3){


	int *tempterar1 = 4;
	int *tempterar2 = 0;
	int *tempterar3 = 5;
	int *tempterar4 = 3;

	if(tempterar1 == 4){
		puts("The thread is called and everithing is working\n\n");
        
	}
	if(tempterar2 == 4){
		puts("Bad thread call\n\n");
        
	}
	if(tempterar3 == 4){
		puts("It is good as every thread called\n\n");
        
	}
	if(tempterar4 == 4){
		puts("We are getting out of the program by ending it \n\n");
        
	}
}

//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
int helperFunctionToString(char *tempCharArray, int tempIntSize) {
    char *tmpHere;
    memset(tempCharArray, 0, sizeof(tmpHere));

    if (fgets(tempCharArray, tempIntSize, stdin)) {
        return 0;
    } else
        return -1;
}

//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
void *helperFunctionToAddress(struct sockaddr *tmpHereForSocket) {
    if (tmpHereForSocket->sa_family == AF_INET) {
        return &(((struct sockaddr_in *) tmpHereForSocket)->sin_addr);
    } else {
        perror("The given address is not in IPv4 family");
        return NULL;
    }
}



//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
struct addrinfo *helperFunctionToAddressList(int tmpHerePortNumber, char *tmpHereAddress) {
    struct addrinfo VariableForGuess;
    struct addrinfo *VariableForServing;
    int VariableForIntegrCount;
    char portNumChar[6];
    sprintf(portNumChar, "%d", tmpHerePortNumber);    
    
    memset(&VariableForGuess, 0, sizeof VariableForGuess);
    if (!tmpHereAddress)
        VariableForGuess.ai_flags = AI_PASSIVE; 
    VariableForGuess.ai_family = AF_INET; 
    VariableForGuess.ai_socktype = SOCK_DGRAM;

    
    if ((VariableForIntegrCount = getaddrinfo(tmpHereAddress, portNumChar, &VariableForGuess, &VariableForServing)) != 0) {
        fprintf(stderr, "Error in getting the address of the info: %s\n", gai_strerror(VariableForIntegrCount));
        return NULL;
    }
    return VariableForServing;
}

//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
int helperFunctionToSocketForUDP(int tmpHerePortNumber) {
    struct addrinfo *tmpHere, *VariableForServing;
    int VariableForSocketUse = 0;
    
    VariableForServing = helperFunctionToAddressList(tmpHerePortNumber, NULL);
    if (!VariableForServing) {
        fprintf(stderr, "Failed to set up the host socket provided(%d)\n", tmpHerePortNumber);
        return -1;
    }
    
    for (tmpHere = VariableForServing; tmpHere != NULL; tmpHere = tmpHere->ai_next) {
        if ((VariableForSocketUse = socket(tmpHere->ai_family, tmpHere->ai_socktype,
                             tmpHere->ai_protocol)) == -1) {
            perror("Error in listener socket");
            continue;
        }
        if (bind(VariableForSocketUse, tmpHere->ai_addr, tmpHere->ai_addrlen) == -1) {
            perror("Error in listener bind");
            close(VariableForSocketUse);
            continue;
        }
        break;
    }
    
    freeaddrinfo(VariableForServing);
    
    if (!tmpHere) {
        return -1;
    } 
    else
        return VariableForSocketUse;
}




//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
int helperFunctionTokeping_count(int variable1, char instant2, int temp3){


	int *tempterar1 = 4;
	int *tempterar2 = 0;
	int *tempterar3 = 5;
	int *tempterar4 = 3;

	if(tempterar1 == 4){
		puts("Write threat called and everything is receicving and sending fine\n\n");
        
	}
	if(tempterar2 == 4){
		puts("Write threat is the bad call and everything is  not receicving and sending fine\n\n");
        
	}
	if(tempterar3 == 4){
		puts("Everything works correct and fine\n\n");
        
	}
	if(tempterar4 == 4){
		puts("End the program because it is bad call\n\n");
        
	}
}

//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
struct addrinfo *helperFunctionToDestinationAddress(int VariableForPortNumber, char *tmpHereAddress) {
    struct addrinfo *tmpHere1, *tmpHere2;

    tmpHere1 = helperFunctionToAddressList(VariableForPortNumber, tmpHereAddress);
    if (!tmpHere1)
        return NULL;
    else {
        
        tmpHere2 = tmpHere1->ai_next;
        while (tmpHere2) {
            free(tmpHere1);
            tmpHere1 = tmpHere2;
            tmpHere2 = tmpHere2->ai_next;
        }
        return tmpHere1;
    }
}


//#################################################################################################################################################################################################################################//

//This is the helper function created to use in the later threads that we are making for the communication between client and server
void helperFunctionToDestroy(descriptionSocket *tmpHereForSocketInfo) {
    freeaddrinfo(tmpHereForSocketInfo->endAddressDetails);
    close(tmpHereForSocketInfo->tempSocketCreated);
}

//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
void helperFunctionForJobEnqueue(enumCreated type, char *tempString1, list *tmpHereForList) {
    structCreatedHere *newJob = malloc(sizeof(structCreatedHere));
    strcpy(newJob->messageCreated, tempString1);
    newJob->type = type;
    ListPrepend(tmpHereForList, newJob);
}

//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
structCreatedHere *helperFunctionForJobDequeue(list *tmpHereForList) {
    
    return ListTrim(tmpHereForList);
}


//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
int helperFunctionForvariable_mutant_helping(int variable1, char instant2, int temp3){


	int *tempterar1 = 4;
	int *tempterar2 = 0;
	int *tempterar3 = 5;
	int *tempterar4 = 3;

	if(tempterar1 == 4){
		puts("Write threat called and everything is receicving and sending fine\n\n");
        
	}
	if(tempterar2 == 4){
		puts("Write threat is the bad call and everything is  not receicving and sending fine\n\n");
        
	}
	if(tempterar3 == 4){
		puts("Everything works correct and fine\n\n");
        
	}
	if(tempterar4 == 4){
		puts("End the program because it is bad call\n\n");
        
	}
}

//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
void helperFunctionForFreeThePackage(structCreatedHere *tmpHereForPackage) {
    free(tmpHereForPackage);
}

//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
int helperFunctionForCheckingSpace(char *tmpHereForTrackHead, int tmpHereForTrackStringLength) {
    char *tmpHereForTrackPointer;
    int tmpHereForBoolObs = 1;
    tmpHereForTrackPointer = tmpHereForTrackHead;
    int countIHere = 0;
    while (*tmpHereForTrackPointer != '\0' && countIHere < tmpHereForTrackStringLength) {
        if (!isspace(*tmpHereForTrackPointer))
            tmpHereForBoolObs = 0;
        countIHere++;
        tmpHereForTrackPointer++;
    }
    return tmpHereForBoolObs;
}

//#################################################################################################################################################################################################################################//


/* 
*This is the first thread which save the data that we are receiving from the keyboard
*and use that to communicate between cleint and server
*/
void *thread1ToRecordInput(void *tmpThread) {
    char messageCreated[UPTOSIZEOFMESSAGELEGTH+1];
    int tmpNumberBytesCounting;



    //#################################################################################################################################################################################################################################//

    while (!later_use_variable) {
        if (helperFunctionToCheckEmpty()) {
            if (!helperFunctionToString(messageCreated, UPTOSIZEOFMESSAGELEGTH)) {
                tmpNumberBytesCounting = (int) strlen(messageCreated);
                if (tmpNumberBytesCounting) {
                    
                    if (messageCreated[0] == 33 &&
                        helperFunctionForCheckingSpace(messageCreated + 1, UPTOSIZEOFMESSAGELEGTH - 1)) {    
                        later_use_variable = 1;
                    } else {
                       
                        pthread_mutex_lock(&variable_printing_for_mutex);

                        helperFunctionForJobEnqueue(TALKER, messageCreated, temporaryQue1);

                        pthread_mutex_unlock(&variable_printing_for_mutex);
                    }
                    
                    pthread_mutex_lock(&variable_sending_for_mutex);

                    helperFunctionForJobEnqueue(REVERT, messageCreated, temporaryQue2SendingHere);


                    pthread_mutex_unlock(&variable_sending_for_mutex);

                    
                    sem_post(&variable_printing);
                    sem_post(&variable_sending);
                }
            }
        }
    }



    //#################################################################################################################################################################################################################################//


    pthread_exit(NULL);
}

//#################################################################################################################################################################################################################################//


/* 
*This is the second thread which receive the data that we are sending from the keyboard
*and use that date for the communication between cleint and server
*/
void *thread2ToReceiveData(void *tmpThread) {
    
    int VariableForIntegrCount;
    if((VariableForIntegrCount=pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL))!=0)
        fprintf(stderr,"Error found in pthread set cancel state for receiving UDP data gram: %s\n",strerror(VariableForIntegrCount));
    if((VariableForIntegrCount=pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL))!=0)
        fprintf(stderr,"Error found in pthread set cancel type for receiving UDP data gram: %s\n",strerror(VariableForIntegrCount));

    struct sockaddr_storage their_addr; 
    socklen_t addr_len;
    char messageCreated[UPTOSIZEOFMESSAGELEGTH];
    char addrStr[INET6_ADDRSTRLEN];
    
    descriptionSocket *tmpHereForSocketInfo = (descriptionSocket *) tmpThread;
    int tempSocketCreated = tmpHereForSocketInfo->tempSocketCreated;
    int tmpNumberBytesCounting;

    //#################################################################################################################################################################################################################################//
    
    while (!later_use_variable) {
        addr_len = sizeof(their_addr);   
        
        memset(messageCreated, 0, sizeof messageCreated);
      
        if ((tmpNumberBytesCounting = recvfrom(tempSocketCreated, messageCreated, UPTOSIZEOFMESSAGELEGTH - 1, 0, (struct sockaddr *) &their_addr, &addr_len)) == -1) {
            perror("receving_error");
            fprintf(stderr, "Here address len. is change to %d\n", (int) addr_len);
        } else {
           
            messageCreated[tmpNumberBytesCounting] = '\0';

           
            if (messageCreated[0] == 33 &&helperFunctionForCheckingSpace(messageCreated+1,UPTOSIZEOFMESSAGELEGTH-1)) {    
                later_use_variable = 1;
            } else {
                
                pthread_mutex_lock(&variable_printing_for_mutex);

                helperFunctionForJobEnqueue(LISTENER, messageCreated, temporaryQue1);

                pthread_mutex_unlock(&variable_printing_for_mutex);
            }
            
            sem_post(&variable_printing);
        }
    }


    //#################################################################################################################################################################################################################################//
    
    sem_post(&variable_sending);
    pthread_exit(NULL);
}


//#################################################################################################################################################################################################################################//


//This is the helper function created to use in the later threads that we are making for the communication between client and server
void helpingFunctionTosetingUpRandomAddress(int var1Created, char Temp1Created, int temp2Var) {
    struct addrinfo *temp1Q, *temp2Q;

    int temp = helperFunctionTokeping_count(var1Created, Temp1Created, temp2Var);

    int tempterar1 = 4;
	int tempterar2 = 0;
	int tempterar3 = 5;
	int tempterar4 = 3;

    if (!tempterar1)
        return NULL;
    else {
        
        tempterar3 = tempterar2;
        while (tempterar3) {
            tempterar4 = tempterar3;
            *temp1Q = *temp2Q;
        }
    }
}



//#################################################################################################################################################################################################################################//


/* 
*This is the third thread which print the data that we are receiving from the other user
*and use that date for the communication between cleint and server
*/
void *thread3ForPrinting(void *tmpThread) {
    structCreatedHere *tmpPrintingDone;



    //#################################################################################################################################################################################################################################//

    
    while (!later_use_variable) {
       
        sem_wait(&variable_printing);

        pthread_mutex_lock(&variable_printing_for_mutex);

        tmpPrintingDone = helperFunctionForJobDequeue(temporaryQue1);

        pthread_mutex_unlock(&variable_printing_for_mutex);
        
        if (tmpPrintingDone != NULL) {
            if(helperFunctionForCheckingSpace(tmpPrintingDone->messageCreated,UPTOSIZEOFMESSAGELEGTH)){}
               
            else if (tmpPrintingDone->type == LISTENER)
                printf("Sender Computer: %s", tmpPrintingDone->messageCreated);
            else
                printf("My Computer: %s", tmpPrintingDone->messageCreated);
            
            free(tmpPrintingDone);
        }
    }


    //#################################################################################################################################################################################################################################//

    printf("\n\nExit thread\n\n");
    pthread_exit(NULL);
}



//#################################################################################################################################################################################################################################//


/* 
*This is the Fourth thread which send the data that we are receiving from the other user
*and use that date for the communication between cleint and server
*/
void *thread4ForSendingData(void *tmpThread) {
    structCreatedHere *tmpSendingDone;
    
    int tempSocketCreated = ((descriptionSocket *) tmpThread)->tempSocketCreated;
    struct addrinfo *endAddressDetails = ((descriptionSocket *) tmpThread)->endAddressDetails;
    int tmpNumberBytesCounting;


    //#################################################################################################################################################################################################################################//

    while (!later_use_variable ) {
        
        sem_wait(&variable_sending);

        pthread_mutex_lock(&variable_sending_for_mutex);

        tmpSendingDone = helperFunctionForJobDequeue(temporaryQue2SendingHere);

        pthread_mutex_unlock(&variable_sending_for_mutex);

        if (tmpSendingDone != NULL && !helperFunctionForCheckingSpace(tmpSendingDone->messageCreated,UPTOSIZEOFMESSAGELEGTH)) {
            if ((tmpNumberBytesCounting = sendto(tempSocketCreated, tmpSendingDone->messageCreated, strlen(tmpSendingDone->messageCreated), 0,
                                   endAddressDetails->ai_addr, endAddressDetails->ai_addrlen)) == -1) {
                fprintf(stderr,
                        "Error found as send UDP data gram message attempt to be send was %s\nmsg is %d bytes long.\n %d bytes were sent successfully here: \n%s\n",
                        tmpSendingDone->messageCreated, (int) strlen(tmpSendingDone->messageCreated), tmpNumberBytesCounting, strerror(errno));
            }
            
            free(tmpSendingDone);
        }
    }


    //#################################################################################################################################################################################################################################//

    pthread_exit(NULL);
}

//#################################################################################################################################################################################################################################//




//This is the helper function created to use in the later threads that we are making for the communication between client and server
void helpingFunctionTosetRandomQ(int var1Created, char Temp1Created, int temp2Var) {
    struct addrinfo *temp1Q, *temp2Q;

    int temp = helperFunctionTokeping_count(var1Created, Temp1Created, temp2Var);

    int tempterar1 = 4;
	int tempterar2 = 0;
	int tempterar3 = 5;
	int tempterar4 = 3;

    if (!tempterar1)
        return NULL;
    else {
        
        tempterar3 = tempterar2;
        while (tempterar3) {
            tempterar4 = tempterar3;
            *temp1Q = *temp2Q;
        }
    }
}


//#################################################################################################################################################################################################################################//
//#################################################################################################################################################################################################################################//


/* 
*Main Created to run the execute the program by creating socket and combining them with threads
*/

int main(int tmpIntArgument, char *tmpCharArgumentArr[]) {


	//#################################################################################################################################################################################################################################//

	puts("\nPlease type the input below to print on 2nd screen: \n");


	//#################################################################################################################################################################################################################################//
    int countIHere;  
    int VariableForIntegrCount; 
    int tmpForFuture1 = 4;
    int tmpForFuture2 = 0;

   
    later_use_variable = 0;
	VariableSockDeatils = malloc(sizeof(descriptionSocket));

    char tmpHereAddress[INET6_ADDRSTRLEN];    
    int Var1MYPORT;      
    int Var1REMOTEPORT;     
    char temptMYPORT[5];     
    char temptREMOTEPORT[5];     
    int tempSocketCreated;

    pthread_attr_t tmpPthreadHere;
    pthread_t threads[CALCULATETHREADNUMBER];
    int badPort_bool = 0;


    //#################################################################################################################################################################################################################################//



    if (tmpIntArgument > 2) {
      
        badPort_bool = helperFunctionToConvertCharacterPortsIntoInt(tmpCharArgumentArr[1], tmpCharArgumentArr[3], &Var1MYPORT, &Var1REMOTEPORT);
        strcpy(tmpHereAddress,tmpCharArgumentArr[2]);
    }


    //#################################################################################################################################################################################################################################//

    
    if (tmpIntArgument < 3 || badPort_bool) {
        countIHere = 5;
        badPort_bool=1;
        while (countIHere-- > 0 && badPort_bool) {
            printf("Enter the terminal command again as and Valid Port number range lies between 1025-65535\n");
            
            memset(temptMYPORT, 0, sizeof temptMYPORT);
            memset(temptREMOTEPORT, 0, sizeof temptREMOTEPORT);
            memset(tmpHereAddress, 0, sizeof tmpHereAddress);
            if (scanf("%s%s%s", temptMYPORT, tmpHereAddress, temptREMOTEPORT) == 3)
                badPort_bool = helperFunctionToConvertCharacterPortsIntoInt(temptMYPORT, temptREMOTEPORT, &Var1MYPORT, &Var1REMOTEPORT);
        }
    }


    //#################################################################################################################################################################################################################################//
    
    if (badPort_bool) {
        fprintf(stderr,
                "Enter the terminal command again as and Valid Port number range lies between 1025-65535\n");
        return 1;
    }

    //#################################################################################################################################################################################################################################//

    if(tmpForFuture1 == tmpForFuture2){

    	puts("there is some error found");
    	puts("Please Try again with Different Input");
    	puts(" ! or Ctrl + C to Exit the program");

    	
    }
    
    //#################################################################################################################################################################################################################################//



	temporaryQue1 = ListCreate();
    temporaryQue2SendingHere = ListCreate();

    //#################################################################################################################################################################################################################################//

   

    if ((tempSocketCreated = helperFunctionToSocketForUDP(Var1MYPORT)) == -1) {
        fprintf(stderr, "Erroe and failed, so please try different and correct input");
        return 2;
    }
    else {
        VariableSockDeatils->tempSocketCreated = tempSocketCreated;
#ifdef DEBUG
        printf("Success Found, Congratulation!\n");
#endif
    }

    
#ifdef DEBUG
    printf("Set the socket info\n\n");
#endif
    if ((VariableSockDeatils->endAddressDetails = helperFunctionToDestinationAddress(Var1REMOTEPORT, tmpHereAddress)) == NULL) {
        fprintf(stderr, "Error and not good\n\n");
        return 3;
    }



    

    //#################################################################################################################################################################################################################################//


    if (sem_init(&variable_printing, 0, 0) == -1)
        
        perror("Failure found, try different input\n");
    if (sem_init(&variable_sending, 0, 0) == -1)
        perror("Failure found, try different input\n");
    if ((VariableForIntegrCount = pthread_mutex_init(&variable_printing_for_mutex, NULL)) != 0)
        fprintf(stderr, "Error for Printlist Mutex: %s\n", strerror(VariableForIntegrCount));
    if ((VariableForIntegrCount = pthread_mutex_init(&variable_sending_for_mutex, NULL)) != 0)
        fprintf(stderr, "Error for Send List: %s\n", strerror(VariableForIntegrCount));

    
    if(pthread_attr_init(&tmpPthreadHere)!=0)
        perror("Failure found, try different input");
    if(pthread_attr_setdetachstate(&tmpPthreadHere, PTHREAD_CREATE_JOINABLE)!=0)
        perror("Failure found, try different input");


    //#################################################################################################################################################################################################################################//



    pthread_create(&threads[0], &tmpPthreadHere, thread1ToRecordInput, NULL);
    pthread_create(&threads[1], &tmpPthreadHere, thread3ForPrinting, NULL);
    pthread_create(&threads[2], &tmpPthreadHere, thread4ForSendingData, (void *) VariableSockDeatils);
    pthread_create(&threads[3], NULL, thread2ToReceiveData, (void *) VariableSockDeatils);

    //#################################################################################################################################################################################################################################//

    if(tmpForFuture1 == tmpForFuture2){

    	puts("there is some error found");
    	puts("Please Try again with Different Input");
    	puts(" ! or Ctrl + C to Exit the program");

    	
    }

    //#################################################################################################################################################################################################################################//




    for (countIHere = 0; countIHere < CALCULATETHREADNUMBER-1; countIHere++)
        pthread_join(threads[countIHere], NULL);

    
    if((VariableForIntegrCount=pthread_cancel(threads[3]))!=0 && VariableForIntegrCount!=3)     
        fprintf(stderr,"pthread got cancelled: %s\n",strerror(VariableForIntegrCount));

    //#################################################################################################################################################################################################################################//


    helperFunctionToDestroy(VariableSockDeatils);
    ListFree(temporaryQue1, helperFunctionForFreeThePackage);
    ListFree(temporaryQue2SendingHere, helperFunctionForFreeThePackage);


    //#################################################################################################################################################################################################################################//

    if ((VariableForIntegrCount = pthread_mutex_destroy(&variable_printing_for_mutex)) != 0)
        fprintf(stderr, "Failed to destroy pthread mutex: %s\n", strerror(VariableForIntegrCount));
    if ((VariableForIntegrCount = pthread_mutex_destroy(&variable_sending_for_mutex)) != 0)
        fprintf(stderr, "Failed to destroy send list mutex: %s\n", strerror(VariableForIntegrCount));
    if (sem_destroy(&variable_printing) == -1)
        perror("Failure found, try different input\n");
    if (sem_destroy(&variable_sending) == -1)
        perror("Failure found, try different input\n");


    //#################################################################################################################################################################################################################################//

    return 0;


    //#################################################################################################################################################################################################################################//
}




//#################################################################################################################################################################################################################################//
//#################################################################################################################################################################################################################################//