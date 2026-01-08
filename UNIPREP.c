#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

#define maxQuestions 100

struct Question{
    char question_text[512];
    char option_a[100];
    char option_b[100];
    char option_c[100];
    char option_d[100];
};
typedef struct {
    char name[100];
    char email[100];
    char subject[100];
    int score;
} Record;


struct Question allQuestions[maxQuestions];
char correct[maxQuestions][8];

int compareScore(const void *a, const void *b);
void record(char name[100], char email[100], char subject[100], int score);
int Chemistry();
int Biology();
int BasicMath();
int Maths();
int English();
int Physics();
int IQ();
char askTimedMCQ(struct Question q, char correctAnswer);
bool isValidEmail(char *email);
void leaderboard();

char mcqReader[1024];
int questionCount;
int score;
int lineLength;
  
int main()
{
    char name[100];
    char email[100];
    float intermediate_percentage;
    int field_study;
    int number;
    int topic_number;
    int subnum;
    int score;
    int again;

    printf("Welcome to UNIPREP - Ultimate way to crack entry tests\n\n");
    printf("Enter your details to start the test\n\n");
    printf("Enter your name: ");
    scanf("%s", name);

    while (1)
    {
        printf("\nEnter your email: ");
        scanf("%s", email);
        bool isValid = isValidEmail(email);
        printf("The email is %s\n", isValid ? "Valid" : "Invalid");
        if (isValid)
            break;
    }

    while (1)
    {
        printf("\n\nEnter your intermediate percentage: ");
        scanf("%f", &intermediate_percentage);

        if (intermediate_percentage <= 100 && intermediate_percentage >= 0)
            break;
        else
            printf("You entered wrong intermediate percentage!\n");
    }
    do{
    while (1)
    {
        printf("\n\nChoose your field of study:\n");
        printf("1) Pre-Engineering\n");
        printf("2) Computer Science\n");
        printf("3) Pre-Medical\n");
        printf("Enter the field number: ");
        scanf("%d", &field_study);

        if (field_study == 1)
        {
            if (intermediate_percentage >= 60)
             {
                printf("\nTop Engineering Universities in Pakistan:\n");
                printf("1- National University of Sciences and Technology (NUST)\n");
                printf("2- University of Engineering and Technology (UET)\n");
                printf("3- NED University of Engineering & Technology\n");
                
                printf("\nEnter your desired university number: ");
                scanf("%d", &number);

                printf("\nTest Pattern:\n");
               if (number == 1)
             {
                printf("NUST: Math 40%%, Physics 30%%, Chemistry 10%%, English 10%%, IQ 10%%\n");
                printf("\nSelect a topic for your practice:\n");
                printf("1) Mathematics\n");
                printf("2) Physics\n");
                printf("3) Chemistry\n");
                printf("4) English\n");
                printf("5) IQ\n");
                scanf("%d",&subnum);
        
                if(subnum==1){
                score=Maths();
                record(name,email,"Mathematics",score);}
                else if(subnum==2){
                score=Physics();
                record(name,email,"Physics",score);}
                else if(subnum==3){
                score=Chemistry();
                record(name,email,"CHemistry",score);}
                else if(subnum==4){
                score=English();
                record(name,email,"English",score);}
                else if(subnum==5){
                score=IQ();
                record(name,email,"IQ",score);}
                else
                printf("You entered wrong number");
             }
             else if (number == 2)
             {
                printf("UET: Physics 30%%, Math 30%%, Chemistry 20%%, English 20%%\n");
                printf("\nSelect a topic for your practice:\n");
                printf("1) Physics\n");
                printf("2) Mathematics\n");
                printf("3) Chemistry\n");
                printf("4) English\nOption: ");
                scanf("%d",&subnum);
        
                if(subnum==1){
                score=Physics();
                record(name,email,"Physics",score);}
                else if(subnum==2){
                score=Maths();
                record(name,email,"Mathematics",score);}
                else if(subnum==3){
                score=Chemistry();
                record(name,email,"Chemistry",score);}
                else if(subnum==4){
                score=English();
                record(name,email,"English",score);}
                else
                printf("You entered wrong number");
            }
            else if (number == 3)
            {
                printf("NED: Physics 25%%, Math 25%%, Chemistry 25%%, English 25%%\n");
                printf("\nSelect a topic for your practice:\n");
                printf("1) Physics\n");
                printf("2) Mathematics\n");
                printf("3) Chemistry\n");
                printf("4) English\nOption: ");
                scanf("%d",&subnum);
        
                if(subnum==1){
                score=Physics();
                record(name,email,"Physics",score);}
                else if(subnum==2){
                score=Maths();
                record(name,email,"Mathematics",score);}
                else if(subnum==3){
                score=Chemistry();
                record(name,email,"Chemistry",score);}
                else if(subnum==4){
                score=English();
                record(name,email,"English",score);}
                else
                printf("You entered wrong number");                
            }
        }
            else
            {
                printf("1- Iqra University (Engineering Technology)\n");
                printf("2- Indus University (BS Technology)\n");
                printf("3- Preston University\n");
                printf("\nEnter your desired university number: ");
                scanf("%d", &number);
            
             if(number==1 || number==2 || number==3){
                printf("\nSelect a topic for your practice:\n");
                printf("1) Mathematics\n");
                printf("2) Physics\n");
                printf("3) English\nOption: ");
                scanf("%d",&subnum);
        
                if(subnum==1){
                score=Maths();
                record(name,email,"Mathematics",score);}
                else if(subnum==2){
                score=Physics();
                record(name,email,"Physics",score);}
                else if(subnum==3){
                score=English();
                record(name,email,"English",score);}
                else
                printf("You entered wrong number");
            }
        }
        leaderboard();
        break;
    }
        
        else if (field_study == 2)
        {
            if (intermediate_percentage >= 60)
            {
                printf("\nTop Computer Science Universities in Pakistan:\n");
                printf("1- FAST University (National University of Computer and Emerging Sciences)\n");
                printf("2- COMSATS University Islamabad\n");
                printf("3- National University of Sciences and Technology (NUST)\n");
                
                printf("\nEnter your desired university number: ");
                scanf("%d", &number);

            printf("\nTest Pattern:\n");
            if (number == 1)
            {
                printf("FAST: Advance Math 50%%, IQ 20%%, English 10%%, Basic Math 20%%\n");
                printf("\nSelect a topic for your practice:\n");
                printf("1) Advance Math\n");
                printf("2) Basic Math\n");
                printf("3) IQ\n");
                printf("4) English\nOption: ");
                scanf("%d",&subnum);
        
                if(subnum==1){
                score=Maths();
                record(name,email,"Math",score);}
                else if(subnum==2){
                score=BasicMath();
                record(name,email,"Basic Math",score);}
                else if(subnum==3){
                score=IQ();
                record(name,email,"IQ",score);}
                else if(subnum==4){
                score=English();
                record(name,email,"English",score);}
                else
                printf("You entered wrong number");
            }
            else if (number == 2)
            {
                printf("COMSATS: Math 40%%, English 30%%, IQ 20%%, Physics 10%%\n");
                printf("\nSelect a topic for your practice:\n");
                printf("1) Mathematics\n");
                printf("2) English\n");
                printf("3) IQ\n");
                printf("4) Physics\nOption: ");
                scanf("%d",&subnum);
        
                if(subnum==1){
                score=Maths();
                record(name,email,"Math",score);}
                else if(subnum==2){
                score=English();
                record(name,email,"English",score);}
                else if(subnum==3){
                score=IQ();
                record(name,email,"IQ",score);}
                else if(subnum==4){
                score=Physics();
                record(name,email,"Physics",score);}
                else
                printf("You entered wrong number");
                
            }
            else if (number == 3)
            {
                printf("NUST: Math 40%%, English 30%%, Physics 20%%, IQ 10%%\n");
                printf("\nSelect a topic for your practice:\n");
                printf("1) Mathematics\n");
                printf("2) English\n");
                printf("3) Physics\n");
                printf("4) IQ\nOption: ");
                scanf("%d",&subnum);
        
                if(subnum==1){
                score=Maths();
                record(name,email,"Math",score);}
                else if(subnum==2){
                score=English();
                record(name,email,"English",score);}
                else if(subnum==3){
                score=Physics();
                record(name,email,"Physics",score);}
                else if(subnum==4){
                score=IQ();
                record(name,email,"IQ",score);}
                else
                printf("You entered wrong number");
                
            }

        }
            else
            {
                printf("1- Virtual University of Pakistan (VU)\n");
                printf("2- Iqra University\n");
                printf("3- Preston University\n");
                printf("\nEnter your desired university number: ");
                scanf("%d", &number);
        
                if(number==1 || number==2 || number==3){
                printf("\nSelect a topic for your practice:\n");
                printf("1) Mathematics\n");
                printf("2) English\n");
                printf("3) IQ\nOption: ");
                scanf("%d",&subnum);
        
                if(subnum==1){
                score=Maths();
                record(name,email,"Math",score);}
                else if(subnum==2){
                score=English();
                record(name,email,"English",score);}
                else if(subnum==3){
                score=IQ();
                record(name,email,"IQ",score);}
                else
                printf("You entered wrong number");
            }
        }
        leaderboard();
        break;
    }

        else if (field_study == 3)
        {
            if (intermediate_percentage >= 60)
            {
                printf("\nTop Medical Universities in Pakistan:\n");
                printf("1- Aga Khan University (AKU)\n");
                printf("2- King Edward Medical University (KEMU)\n");
                printf("3- Dow University of Health Sciences (DUHS)\n");
            
			    printf("\nEnter your desired university number: ");
            scanf("%d", &number);

            printf("\nTest Pattern:\n");
            if (number == 1)
            {
                printf("AKU: Biology 40%%, Chemistry 30%%, Physics 20%%, English 10%%\n");
                printf("\nSelect a topic for your practice:\n");
                printf("1) Biology\n");
                printf("2) Chemistry\n");
                printf("3) Physics\n");
                printf("4) English\nOption: ");
                scanf("%d",&subnum);
        
                if(subnum==1){
                score=Biology();
                record(name,email,"Biology",score);}
                else if(subnum==2){
                score=Chemistry();
                record(name,email,"Chemistry",score);}
                else if(subnum==3){
                score=Physics();
                record(name,email,"English",score);}
                else if(subnum==4){
                score=English();
                record(name,email,"English",score);}
                else
                printf("You entered wrong number");
            }
            else if (number == 2)
            {
                printf("KEMU: Biology 40%%, Chemistry 30%%, Physics 20%%, English 10%%\n");
                printf("\nSelect a topic for your practice:\n");
                printf("1) Biology\n");
                printf("2) Chemistry\n");
                printf("3) Physics\n");
                printf("4) English\nOption: ");
                scanf("%d",&subnum);
        
                if(subnum==1){
                score=Biology();
                record(name,email,"Biology",score);}
                else if(subnum==2){
                score=Chemistry();
                record(name,email,"Chemistry",score);}
                else if(subnum==3){
                score=Physics();
                record(name,email,"Physics",score);}
                else if(subnum==4){
                score=English();
                record(name,email,"English",score);}
                else
                printf("You entered wrong number");
                
            }
            else if (number == 3)
            {
                printf("DUHS: Biology 40%%, Chemistry 30%%, English 20%%, IQ 10%%\n");
                printf("\nSelect a topic for your practice:\n");
                printf("1) Biology\n");
                printf("2) Chemistry\n");
                printf("3) English\n");
                printf("4) IQ\nOption: ");
                scanf("%d",&subnum);
        
                if(subnum==1){
                score=Biology();
                record(name,email,"Biology",score);}
                else if(subnum==2){
                score=Chemistry();
                record(name,email,"Chemistry",score);}
                else if(subnum==3){
                score=Physics();
                record(name,email,"Physics",score);}
                else if(subnum==4){
                score=IQ();
                record(name,email,"IQ",score);}
                else
                printf("You entered wrong number");
                
            }
		}
            else
            {
                printf("1- Ziauddin University (BS Medical Technology)\n");
                printf("2- Baqai Medical University\n");
                printf("3- Liaquat National University\n");
                printf("\nEnter your desired university number: ");
                scanf("%d", &number);
                
                if(number==1 || number==2 || number==3){       
                printf("\nSelect a topic for your practice:\n");
                printf("1) Biology\n");
                printf("2) Chemistry\n");
                printf("4) English\nOption: ");
                scanf("%d",&subnum);
         
                if(subnum==1){
                score=Biology();
                record(name,email,"Biology",score);}
                else if(subnum==2){
                score=Chemistry();
                record(name,email,"Chemistry",score);}
                else if(subnum==3){
                score=English();
                record(name,email,"English",score);}
                else
                printf("You entered wrong number");
            }
        }
     leaderboard();
     break;   
    }
    
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }
        printf("\nDo you want to practice more? 1-Yes 2-Exit\nOption: ");
        scanf("%d",&again);
    }while(again!=2);
}

bool isValidEmail(char *email)
{
    int count = 0;
    int i;

    for (i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
            count++;

        if (email[i] == ' ' || email[i] == '/' || email[i] == ':' || email[i] == ';' ||
            email[i] == '<' || email[i] == '>' || email[i] == ',' || email[i] == '[' || email[i] == ']')
            return false;

        if (email[i] >= 'A' && email[i] <= 'Z')
            return false; 
    }

    if (count == 1)
    {
        if (email[0] != '@')
        {
            char *dot = strchr(email, '.');
            if (dot != NULL && dot > strchr(email, '@'))
                return true;
        }
    }
    return false;
}
char askTimedMCQ(struct Question q, char correctAnswer) {
    int time_left = 60;         
    char answer = 0;

    printf("\n%s\n", q.question_text);
    printf("A) %s\n", q.option_a);
    printf("B) %s\n", q.option_b);
    printf("C) %s\n", q.option_c);
    printf("D) %s\n", q.option_d);
    printf("You have 60 second to answer\n");

    while (time_left > 0) {
        if (_kbhit()) {         
            answer = _getch();
            answer = toupper(answer);
            printf("\nYour answer: %c\n", answer);
            return answer;
        }

        Sleep(1000);        
        time_left--;

        printf("\rTime left: %d seconds ", time_left);
        fflush(stdout);
    }

    printf("\nTime up!\n");
    return 0;  
}

int Maths(){
	questionCount = 0;
score = 0;
lineLength = 1024;
memset(allQuestions, 0, sizeof(allQuestions));
memset(correct, 0, sizeof(correct));

    FILE *math;
    math = fopen("math.csv", "r");
    if (math == NULL) {
        perror("Error opening file");
        return 1;
    }

    if(fgets(mcqReader, lineLength, math) == NULL){
        printf("Error reading header line\n");
        fclose(math);
        return 1;
    }

    while(fgets(mcqReader, lineLength, math) != NULL && questionCount<maxQuestions){
        mcqReader[strcspn(mcqReader, "\n")] = '\0';
        char* token = strtok(mcqReader, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].question_text, token);
        }
        token = strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_a, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_b, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_c, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_d, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(correct[questionCount], token);
        }
        questionCount++;
    }
    fclose(math);

    for(questionCount=0;questionCount<25;questionCount++){
        lineLength=rand()%50;
        char userAns = askTimedMCQ(allQuestions[lineLength], correct[lineLength][0]);

if (userAns == correct[lineLength][0]) {
    score++;
}
    }
    printf("Your final score is: %d/25\n", score);
    return score;
}

int English(){
	memset(allQuestions, 0, sizeof(allQuestions));
memset(correct, 0, sizeof(correct));

	questionCount = 0;
score = 0;
lineLength = 1024;

	
    srand(time(NULL));
    FILE *english;
    english = fopen("english.csv", "r");
    if (english == NULL) {
        perror("Error opening file");
        return 1;
    }

    if(fgets(mcqReader, lineLength, english) == NULL){
        printf("Error reading header line\n");
        fclose(english);
        return 1;
    }

    while(fgets(mcqReader, lineLength, english) != NULL && questionCount<maxQuestions){
        mcqReader[strcspn(mcqReader, "\n")] = '\0';
        char* token = strtok(mcqReader, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].question_text, token);
        }
        token = strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_a, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_b, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_c, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_d, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(correct[questionCount], token);
        }
        questionCount++;
    }
    fclose(english);
   

    for(questionCount=0;questionCount<25;questionCount++){
        lineLength=rand()%50;
       char userAns = askTimedMCQ(allQuestions[lineLength], correct[lineLength][0]);

        if(userAns==correct[lineLength][0]){score++;}
    }
    printf("Your final score is: %d/25\n", score);
    return score;
}

int Biology(){
	memset(allQuestions, 0, sizeof(allQuestions));
memset(correct, 0, sizeof(correct));


	questionCount = 0;
score = 0;
lineLength = 1024;

	
    srand(time(NULL));
    FILE *biology;
    biology = fopen("biology.csv", "r");
    if (biology == NULL) {
        perror("Error opening file");
        return 1;
    }

    if(fgets(mcqReader, lineLength, biology) == NULL){
        printf("Error reading header line\n");
        fclose(biology);
        return 1;
    }

    while(fgets(mcqReader, lineLength, biology) != NULL && questionCount<maxQuestions){
        mcqReader[strcspn(mcqReader, "\n")] = '\0';
        char* token = strtok(mcqReader, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].question_text, token);
        }
        token = strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_a, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_b, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_c, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_d, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(correct[questionCount], token);
        }
        questionCount++;
    }
    fclose(biology);


    for(questionCount=0;questionCount<25;questionCount++){
        lineLength=rand()%50;
        char userAns = askTimedMCQ(allQuestions[lineLength], correct[lineLength][0]);

        if(userAns==correct[lineLength][0]){score++;}
    }
    printf("Your final score is: %d/25\n", score);
    return score;
}

int Chemistry(){
	
	memset(allQuestions, 0, sizeof(allQuestions));
memset(correct, 0, sizeof(correct));

	
	questionCount = 0;
score = 0;
lineLength = 1024;

	
    srand(time(NULL));
    FILE *chemistry;
    chemistry = fopen("chemistry.csv", "r");
    if (chemistry == NULL) {
        perror("Error opening file");
        return 1;
    }

    if(fgets(mcqReader, lineLength, chemistry) == NULL){
        printf("Error reading header line\n");
        fclose(chemistry);
        return 1;
    }

    while(fgets(mcqReader, lineLength, chemistry) != NULL && questionCount<maxQuestions){
        mcqReader[strcspn(mcqReader, "\n")] = '\0';
        char* token = strtok(mcqReader, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].question_text, token);
        }
        token = strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_a, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_b, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_c, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_d, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(correct[questionCount], token);
        }
        questionCount++;
    }
    fclose(chemistry);
    

    for(questionCount=0;questionCount<25;questionCount++){
        lineLength=rand()%50;
        char userAns = askTimedMCQ(allQuestions[lineLength], correct[lineLength][0]);

        if(userAns==correct[lineLength][0]){score++;}
    }
    printf("Your final score is: %d/25\n", score);
    return score;
}

int BasicMath(){
	
	memset(allQuestions, 0, sizeof(allQuestions));
memset(correct, 0, sizeof(correct));

	questionCount = 0;
score = 0;
lineLength = 1024;

    srand(time(NULL));
    FILE *basicmath;
    basicmath = fopen("basicmath.csv", "r");
    if (basicmath == NULL) {
        perror("Error opening file");
        return 1;
    }

    if(fgets(mcqReader, lineLength, basicmath) == NULL){
        printf("Error reading header line\n");
        fclose(basicmath);
        return 1;
    }

    while(fgets(mcqReader, lineLength, basicmath) != NULL && questionCount<maxQuestions){
        mcqReader[strcspn(mcqReader, "\n")] = '\0';
        char* token = strtok(mcqReader, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].question_text, token);
        }
        token = strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_a, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_b, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_c, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_d, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(correct[questionCount], token);
        }
        questionCount++;
    }
    fclose(basicmath);


    for(questionCount=0;questionCount<25;questionCount++){
        lineLength=rand()%50;
        char userAns = askTimedMCQ(allQuestions[lineLength], correct[lineLength][0]);

        if(userAns==correct[lineLength][0]){score++;}
    }
    printf("Your final score is: %d/25\n", score);
    return score;
}

int Physics(){
	
	memset(allQuestions, 0, sizeof(allQuestions));
memset(correct, 0, sizeof(correct));

	questionCount = 0;
score = 0;
lineLength = 1024;

	
    srand(time(NULL));
    FILE *physics;
    physics = fopen("physics.csv", "r");
    if (physics == NULL) {
        perror("Error opening file");
        return 1;
    }

    if(fgets(mcqReader, lineLength, physics) == NULL){
        printf("Error reading header line\n");
        fclose(physics);
        return 1;
    }

    while(fgets(mcqReader, lineLength, physics) != NULL && questionCount<maxQuestions){
        mcqReader[strcspn(mcqReader, "\n")] = '\0';
        char* token = strtok(mcqReader, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].question_text, token);
        }
        token = strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_a, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_b, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_c, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_d, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(correct[questionCount], token);
        }
        questionCount++;
    }
    fclose(physics);
 

    for(questionCount=0;questionCount<25;questionCount++){
        lineLength=rand()%50;
        char userAns = askTimedMCQ(allQuestions[lineLength], correct[lineLength][0]);

        if(userAns==correct[lineLength][0]){score++;}
    }
    printf("Your final score is: %d/25\n", score);
    return score;
}

int IQ(){
	
	memset(allQuestions, 0, sizeof(allQuestions));
memset(correct, 0, sizeof(correct));

	questionCount = 0;
score = 0;
lineLength = 1024;

	
    srand(time(NULL));
    FILE *IQ;
    IQ = fopen("IQ.csv", "r");
    if (IQ == NULL) {
        perror("Error opening file");
        return 1;
    }

    if(fgets(mcqReader, lineLength, IQ) == NULL){
        printf("Error reading header line\n");
        fclose(IQ);
        return 1;
    }

    while(fgets(mcqReader, lineLength, IQ) != NULL && questionCount<maxQuestions){
        mcqReader[strcspn(mcqReader, "\n")] = '\0';
        char* token = strtok(mcqReader, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].question_text, token);
        }
        token = strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_a, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_b, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_c, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(allQuestions[questionCount].option_d, token);
        }
        token=strtok(NULL, "|");
        if(token != NULL) {
            strcpy(correct[questionCount], token);
        }
        questionCount++;
    }
    fclose(IQ);


    for(questionCount=0;questionCount<25;questionCount++){
        lineLength=rand()%50;
      char userAns = askTimedMCQ(allQuestions[lineLength], correct[lineLength][0]);

        if(userAns==correct[lineLength][0]){score++;}
    }
    printf("Your final score is: %d/25\n", score);
    return score;
}

void record(char name[100],char email[100], char subject[100],int score){

    FILE *record = fopen("Records.txt", "a");
    if(record==NULL){
        printf("\nError opening file\n");
        return;
    }

    fprintf(record,"\n%s | %s | %s | %d/25",name,email,subject,score);
    fclose(record);

}

void leaderboard() {
    FILE *file = fopen("Records.txt", "r");
    if (!file) {
        printf("No records found.\n");
        return;
    }

    Record records[1000];
    int count = 0;
    char line[200];

    while (fgets(line, sizeof(line), file)) {

        line[strcspn(line, "\n")] = '\0';
        if (sscanf(line, " %[^|] | %[^|] | %[^|] | %d",
                   records[count].name,
                   records[count].email,
                   records[count].subject,
                   &records[count].score) == 4) {
            count++;
        }
    }
    fclose(file);

    if (count == 0) {
        printf("No records found.\n");
        return;
    }
 
    int i;
    
    qsort(records, count, sizeof(Record), compareScore);

    printf("\nLeaderboard:\n");
    printf("Rank | Name                 | Subject      | Score\n");
    printf("------------------------------------------------\n");
    for (i = 0; i < count; i++) {
        printf("%4d | %-20s | %-12s | %d/25\n", i + 1,
               records[i].name, records[i].subject, records[i].score);
    }
}

int compareScore(const void *a, const void *b) {
    Record *r1 = (Record *)a;
    Record *r2 = (Record *)b;
    return r2->score - r1->score;
}


