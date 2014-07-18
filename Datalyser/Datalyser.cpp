#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
struct Data {
	//STRUCTURE TO STORE DATA FROM FILE
	char String[36][25];
	long data[36][20];
	};
struct Data DataStruct[2];//DATA FILES
void Sort(long array[],char string[][25],int start,int end){//QUICK SORT
		char tempchar[25];     	  	
		if(start>=end)       
			return;
		int count = 0;
		int random = (start+end)/2;
		for(int i=start;i<end;i++){
			if(array[i]<array[random]){
				count++;
			}
		}
		count = count+start;
		if(array[count]!=array[random]){
			int temp = array[count];
			strcpy(tempchar,string[count]);
			array[count] = array[random];
			strcpy(string[count],string[random]);
			array[random] = temp;
			strcpy(string[random],tempchar);
			
		}                     
		for(int i = start; i < count; i++){
			if(array[i]>array[count]){
				for(int j = end-1;j>count;j--){
					if(array[j]<array[count]){
						int temp = array[i];
						strcpy(tempchar,string[i]);
						strcpy(string[i],string[j]);
						array[i]=array[j];                                                      
						strcpy(string[j],tempchar);
						array[j] = temp;
					}            
				} 
			}
		}
																							
						
	Sort(array,string,start,count);
	Sort(array,string,count+1,end);
}
int mainSortInc (int data){  //SORTS IN INCREASING ORDER                 
	int i,year;
	long array[36];
	char string[36][25];
	printf("Enter the year");
	scanf("%d",&year);
	for(i=1;i<36;i++){
		array[i] = DataStruct[data].data[i][year%1000];
		strcpy(string[i],DataStruct[data].String[i]);
	}                        
	Sort(array,string,1,36);
	printf("States/Ut            Data");
	for(i=1;i<=35;i++){
		printf("\n%-20s\t%6lu",string[i],array[i]);
	}
	getchar();      
	return 0;                                                       
}                 
int mainSortDec(int data){// SORTS IN DECREASING ORDER
	 int i,year;
	long array[36];
	char string[36][25];
	printf("Enter the year");                          
	scanf("%d",&year);
	for(i=1;i<36;i++){
		array[i] = DataStruct[data].data[i][year%1000];
		strcpy(string[i],DataStruct[data].String[i]);
	}
	printf("\nSorted Data is  \n");
	Sort(array,string,1,36);
	for(i=35;i>=1;i--){            
		printf("\n%-20s\t%6lu",string[i],array[i]);
	}               
	getchar();
	return 0;
}
void barGraph(int data,int k,int noDigits)//PLOTS BAR GRAPH
{
	int gd = DETECT, gm;

   initgraph(&gd, &gm, NULL);

   setcolor(YELLOW);
   rectangle(0,30,639,450);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   setcolor(WHITE);
   outtextxy(150,0,"Bar Graph");

   setlinestyle(SOLID_LINE,0,2);

   line(100,400,100,60);
   line(100,400,600,400);


   outtextxy(95,35,"Y");
   outtextxy(610,405,"X");
   outtextxy(85,415,"O");
   
   setfillstyle(LINE_FILL,BLUE);
   bar(150,400 - abs(((DataStruct[data].data[k][7]*1000)/(pow(10,noDigits))))/2.5,200,399);//Scale Change
   outtextxy(150,415,"2007");
   
   
   setfillstyle(XHATCH_FILL,RED);
   bar(225,400 - abs(((DataStruct[data].data[k][8]*1000)/(pow(10,noDigits))))/2.5,275,399);
   outtextxy(225,415,"2008");

   setfillstyle(WIDE_DOT_FILL,GREEN);
   bar(300,400 - abs(((DataStruct[data].data[k][9]*1000)/(pow(10,noDigits))))/2.5,350,399);
   outtextxy(300,415,"2009");

   setfillstyle(INTERLEAVE_FILL,MAGENTA);
   bar(375,400 - abs(((DataStruct[data].data[k][10]*1000)/(pow(10,noDigits))))/2.5,425,399);
   outtextxy(375,415,"2010");


   setfillstyle(HATCH_FILL,BROWN);
   bar(450,400 - abs(((DataStruct[data].data[k][11]*1000)/(pow(10,noDigits))))/2.5,500,399);
	outtextxy(450,415,"2011");
   getch();
}
void graphmain(int data){//PROVIDES DATA TO PLOT BAR GRAPH
	int i,j,k,invalid = 1,noDigits = 0;
	char state[25];
	while(invalid){
		printf("Enter the name of the State");
		scanf("%s",state);
		for(i = 1;i<36;i++){
			if(strcmp(DataStruct[data].String[i],state) == 0){
				k = i;
				invalid = 0;
				break;
			}
		}
		if(invalid){
			printf("Invalid option.Try Again");
		}
	}
	long n = DataStruct[data].data[k][7];
	while(n!=0){
		noDigits ++;
		n = n/10;
	}
	barGraph(data,k,noDigits);
}
void pieGraph(float array[])
{
   int gd = DETECT, gm, midx, midy,t;

   initgraph(&gd, &gm,NULL);

   setcolor(MAGENTA);
   rectangle(0,40,639,450);
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
   setcolor(WHITE);
   outtextxy(150,10,"Pie Chart");

   midx = getmaxx()/2;
   midy = getmaxy()/2;
	
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(75 , 75 , 90 ,90);
	floodfill( 80,80 , WHITE);
	outtextxy(100, 70, "2007");
	setfillstyle(SOLID_FILL,RED);
	rectangle(75 , 105 , 90 ,120);
	floodfill( 80,110 , WHITE);
	outtextxy(100, 100, "2008");
	setfillstyle(SOLID_FILL,GREEN);
	outtextxy(100, 130, "2009");
	rectangle(75 , 135 , 90 ,150);
	floodfill( 80,140 , WHITE);
	setfillstyle(SOLID_FILL,MAGENTA);
	rectangle(75 , 165 , 90 ,180);
	floodfill( 80,170 , WHITE);
	outtextxy(100, 160, "2010");
	setfillstyle(SOLID_FILL,BROWN);
	rectangle(75 , 195 , 90 ,210);
	floodfill( 80,200 , WHITE);
	outtextxy(100, 190, "2011");				

    setfillstyle(LINE_FILL,BLUE);
    pieslice(midx, midy, 0, array[0], 100);  

    setfillstyle(XHATCH_FILL,RED);
    pieslice(midx, midy, array[0], array[0] + array[1], 100); 
	
	setfillstyle(WIDE_DOT_FILL,GREEN);
    pieslice(midx, midy, array[0] + array[1], array[0] + array[1] + array[2], 100);
	
	setfillstyle(INTERLEAVE_FILL,MAGENTA);
	pieslice(midx, midy,array[0] + array[1] + array[2],array[0] + array[1] + array[2] +array[3], 100);
   
    setfillstyle(HATCH_FILL,BROWN);
	pieslice(midx, midy,array[0] + array[1] + array[2] + array[3], 360, 100);
    
   
   getch();
}
void mainPie(int data){
	int i,j,k,invalid = 1;
	float array[5];
	long total = 0;
	char state[25];
	while(invalid){
		printf("Enter the name of the State");
		scanf("%s",state);
		for(i = 1;i<36;i++){
			if(strcmp(DataStruct[data].String[i],state) == 0){
				k = i;
				invalid = 0;
				break;
			}
		}
		if(invalid){
			printf("Invalid option.Try Again");
		}
	}
	for(i = 7;i <=11;i++){
		total = total + DataStruct[data].data[k][i];
	}
	for(i = 0;i<5;i++){
		array[i] = ((float)DataStruct[data].data[k][i+7]/total)*360;
		printf("%f ",array[i]);
	}
	pieGraph(array);
}
void cumulative(int data){
	int i,j,from,to;
	long sum;
	printf("Finds the cumulative data for all the states for the given years\n");
	printf("Enter year:\nFrom\t");
	scanf("%d",&from);
	printf("\nTo\t");
	scanf("%d",to);
	printf("\n\nState/Ut      Commulative data from %d to %d",from,to);
	for(i=1;i<36;i++){
		sum = 0;      
		for(j = from%1000;j<=to%1000;j++){
			sum = sum + DataStruct[data].data[i][j];
		}
		printf("\n%-20s\t%6lu",DataStruct[data].String[i],sum);
	}                                   
	getchar();
}
void CAW(){
	//FILE INPUT
	int i,j;
	FILE *fp;
	//clrscr();
	fp = fopen("caw.txt","r");
	while(getc(fp)!=EOF){
		for(i = 0;i<36;i++){
			fscanf(fp,"%s",DataStruct[0].String[i]);
			for(j = 1;j<=12;j++){
				fscanf(fp,"%lu ",&DataStruct[0].data[i][j]);
			}
		}
	}
}
void tabularCAW(){
	int i,j;
	//TABULAR REPRESENTATION
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n");
	for(i =0;i<36;i++){
		printf("| %-20s ",DataStruct[0].String[i]);
			printf("|");
			for(j = 1; j <= 12;j++){
				printf("%8lu |",DataStruct[0].data[i][j]);
			}
		printf("\n");
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------");
		printf("\n");
	}
	getchar();
}
void TA(){
	//FILE INPUT
	int i,j;
	FILE *fp;
	fp = fopen("ta.txt","r");
	while(getc(fp)!=EOF){
		for(i = 0;i<36;i++){
			fscanf(fp,"%s",DataStruct[1].String[i]);
			for(j = 3;j<=11;j++){
				fscanf(fp,"%lu",&DataStruct[1].data[i][j]);
			}
		}
	}
}
void tabularTA(){
	int i,j;
	printf("-----------------------------------------------------------------------------------------------------------------------");
	printf("\n");
	for(i =0;i<36;i++){
		printf("| %-25s ",DataStruct[1].String[i]);
		printf("|");
			for(j = 3; j <= 11;j++){
				printf("%8lu |",DataStruct[1].data[i][j]);
			}
			printf("\n");
			printf("----------------------------------------------------------------------------------------------------------------------");
		printf("\n");
	}
	getchar();
}
void hypo(int data){
	int i,j,k,l,invalid = 1,count = 0,minCount;
	char state[25];
	if(data == 0){
		printf("Our hypothesis is that with the increase in year crime against women increase\n");
		j = 1;
		k = 12;
	}
	else{
		printf("Our hypothesis is that with the increase in year total no of person injured in road accident increase\n");
		j = 3;
		k = 11;
	}
	minCount = k-j;
	while(invalid){
		printf("\nEnter the name of the State\n");
		scanf("%s",state);
		for(i = 1;i<36;i++){
			if(strcmp(DataStruct[data].String[i],state) == 0){
				l = i;
				invalid = 0;
				break;
			}
		}
		if(invalid){
			printf("\nInvalid option.Try Again\n");
		}
	}
	for(j;j<k;j++){
		if(DataStruct[data].data[l][j] < DataStruct[data].data[l][j+1])
			count++;
	}
	if(count >= (minCount*7)/10){
		printf("\nHypothesis is true for %s \n",state);
	}
	else{
		printf("\nHypothesis is false\n");
	}
	getchar();
}
void printSummary(int data){
	int i,invalid = 1,j= data==0?1:3,k;
	char state[25];
	k = data==0?12:11;
	printf("\nEnter the name of the state\n");
	while(invalid){
		scanf("%s",state);
		for(i = 0;i<36;i++){
			if(strcmp(DataStruct[data].String[i],state)==0){
				invalid = 0;
				printf(" Year    Data\n");
				for(j;j<=k;j++){
					printf(" %lu   %lu\n",DataStruct[data].data[0][j],DataStruct[data].data[i][j]);
				}
				break;
			}
		}
		if(invalid){
			printf("Invalid State Entered. Please Try Again\n");
		}
	}
	getchar();
}
void search(int data){
	int i,invalid = 1,j,k;
	k = data==0?12:11;
	long element;
	printf("Enter the data you want to search\n");
	while(invalid){
		scanf("%lu",&element);
		printf("STATE                YEAR    DATA\n");
		for(i = 0;i<36;i++){
			for(j = data==0?1:3;j<=k;j++){
				if(DataStruct[data].data[i][j] == element){
					invalid = 0;
					printf("%-20s %lu" "%8lu\n",DataStruct[data].String[i],DataStruct[data].data[0][j],element);
				}
			}
		}
		if(invalid){
			printf("Not found.Try Again\n");
		}
	}
	getchar();
}
long totalColumn(int data , int year){
	int i;
	long sum=0;
	for(i = 1; i < 36;i++){
		sum = sum + DataStruct[data].data[i][year%1000];
	}
	return sum;
}
void overview(int data){
	int j= data==0?1:3,k = data==0?12:11;
	long x,max[1][2] = { 0 , 0},min[1][2] = { 10000000,100};
	printf("Crime Against Women in India during the year 2001 - 2012");
	printf("\n\nOVERVIEW\n\nYEAR : TOTAL CRIMES IN INDIA\n");
	for(j;j<=k;j++){
		x = totalColumn(data,(int)(DataStruct[data].data[0][j]));
		if(max[0][0] < x){
			max[0][0] = x;
			max[0][1] = j;
		}
		if(min[0][0] > x){
			min[0][0] = x;
			min[0][1] = j;
		}
		printf("%lu : %lu \n",DataStruct[data].data[0][j],x);
	}
	printf("\nMax no of crimes are %lu and year is %lu ",max[0][0],DataStruct[data].data[0][max[0][1]]);
	printf("\nMin no of crimes are %lu and year is %lu ",min[0][0],DataStruct[data].data[0][min[0][1]]);
	getchar();
}
void CAWOnly(){
	int a,i,choose,k,invalid = 1;
	CAW();
	getchar();
	system("cls");
	while(invalid){
		printf("Choose the analysis you want to perform.\n\n\n 1.)Tabular Representation\n 2.)Overview\n 3.)Summary\n 4.)Search\n 5.)Sorting in Increasing Order\n 6.)Sorting in Decresing Order\n 7.)Cummulative data\n 8.)Bar Graph\n 9.)Pie Chart\n 10.)Check Hypothesis Accuracy\n ");
		scanf("%d",&choose);
		switch(choose){
			case 1:
				printf("\nTabular Rrepresentation of Data\n");
				tabularCAW();
				getchar();
				system("cls");
				break;
			case 2:
				printf("\nOverview of the DataBase\n");
				overview(0);
				getchar();
				system("cls");
				break;
			case 3:
				printf("\nSummary of State\n");
				printSummary(0);
				getchar();
				system("cls");
				break;
			case 4:
				printf("\nSearch Data\n");
				search(0);
				getchar();
				system("cls");
				break;
			case 5:
				printf("\nSort States in Increasing order according to their corresponding data\n");
				mainSortInc(0);
				getchar();
				system("cls");
				break;
			case 6:
				printf("\nSort States in Decreasing order according to their corresponding data\n");
				mainSortDec(0);
				getchar();
				system("cls");
				break;
			case 7:
				printf("\nSum of data during the given period of a State\n");
				cumulative(0);
				getchar();
				system("cls");
				break;
			case 8:
				printf("\nBar Graph of data of last 5  years of a given state\n");
				graphmain(0);
				getchar();
				system("cls");
				break;
			case 9:printf("\nPie Chart representing percentage of data of 5 given state of any given year\n");
				mainPie(0);
				getchar();
				system("cls");
				break;
			case 10:
				printf("Checks whether the stated Hypothesis is correct or not for a given State\n");
				hypo(0);
				getchar();
				system("cls");
				break;
			default :
				printf("\nInvalid Option.Choose Again\n");
				break;
		}
		printf("Do you want to analyse again?\nPress 1 for yes and 0 for no\n");
		scanf("%d",&invalid);
	}
}
void TAOnly(){
	int a,i,choose,k,years[5],invalid = 1;
	TA();
	getchar();
	system("cls");
	while(invalid){
		printf("Choose the analysis you want to perform.\n\n\n 1.)Tabular Representation\n 2.)Overview\n 3.)Summary\n 4.)Search\n 5.)Sorting in Increasing Order\n 6.)Sorting in Decresing Order\n 7.)Cummulative data\n 8.)Bar Graph\n 9.)Pie Chart\n10.)Check Hypothesis Accuracy\n\n");
		scanf("%d",&choose);
		switch(choose){
			case 1:
				printf("\nTabular Rrepresentation of Data\n");
				tabularTA();
				getchar();
				system("cls");
				break;
			case 2:
				printf("\nOverview of the DataBase\n");
				overview(1);
				getchar();
				system("cls");
				break;
			case 3:
				printf("\nSummary of State\n");
				printSummary(1);
				getchar();
				system("cls");
				break;
			case 4:
				printf("\nSearch Data\n");
				search(1);
				getchar();
				system("cls");
				break;
			case 5:
				printf("\nSort States in Increasing order according to their corresponding data\n");
				mainSortInc(1);
				getchar();
				system("cls");
				break;
			case 6:
				printf("\nSort States in Decreasing order according to their corresponding data\n");
				mainSortDec(1);
				getchar();
				system("cls");
				break;
			case 7:
				printf("\nSum of data during the given period of a State\n");
				cumulative(1);
				getchar();
				system("cls");
				break;
			case 8:
				printf("\nBar Graph of data of last 5  years of a given state\n");
				graphmain(1);
				getchar();
				system("cls");
				break;
			case 9:printf("\nPie Chart representing percentage of data of 5 given state of any given year\n");
				mainPie(1);
				getchar();
				system("cls");
				break;
			case 10:
				printf("Checks whether the stated Hypothesis is correct or not for a given State\n");
				hypo(1);
				getchar();
				//system("cls");
				break;
			default :
				printf("\nInvalid Option.Choose Again\n");
				break;
		}
		printf("Do you want to analyse again?\nPress 1 for yes and 0 for no\n");
		scanf("%d",&invalid);
	}
}
int main(){
	int choose,invalid=1;
	printf("\n\n\n\n\n\n\n\n\n                                        *****************************************************************************\n                                        *    ___            _________                         ___    _____  ____    *\n                                        *   |   \\       /\\      |      /\\      |    \\     /  /   \\  |      |    \\   *\n                                        *   |    |     /  \\     |     /  \\     |     \\   /  |       |      |     |  *\n                                        *   |    |    /    \\    |    /    \\    |      \\ /    \\___   |___   |____/   *\n                                        *   |    |   /------\\   |   /------\\   |       |         \\  |      |  \\     *\n                                        *   |    |  /        \\  |  /        \\  |       |          | |      |   \\    *\n                                        *   |___/  /          \\ | /          \\ |______ |     \\___/  |_____ |    \\   *\n                                        *                                                                           *\n                                        *****************************************************************************\n                                        *                                                                           *\n                                        *                                                                           * \n                                        *    A Project by :   Rohan Arora , Sahib Sethi , Amanpreet Singh Gujral    *\n                                        *                                                                           *\n                                        *                                                                           *\n                                        *****************************************************************************");
	printf("\n\n\n\n\n\n About:\n\n\tAnalysis of data is a process of inspecting, cleaning, transforming, and modeling data with the goal of discovering useful information, suggesting conclusions, and supporting decision making. Data analysis has multiple facets and approaches, encompassing diverse techniques under a variety of names, in different business, science, and social science domains.\n\n\tData mining is a particular data analysis technique that focuses on modeling and knowledge discovery for predictive rather than purely descriptive purposes. Business intelligence covers data analysis that relies heavily on aggregation, focusing on business information.\n\n\tDatalyser is a small level Data Mining Software which can be used to teach the basics of Data Analysis and Data Mining.It tabulates the data , organise or sort it ,  generate useful results and create beautiful graphs. Other queries such as maximum , minimum ,search etc. are also performed by Datalyser.");
	getchar();
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n                                        *****************************************************************************\n                                        *    ___            _________                         ___    _____  ____    *\n                                        *   |   \\       /\\      |      /\\      |    \\     /  /   \\  |      |    \\   *\n                                        *   |    |     /  \\     |     /  \\     |     \\   /  |       |      |     |  *\n                                        *   |    |    /    \\    |    /    \\    |      \\ /    \\___   |___   |____/   *\n                                        *   |    |   /------\\   |   /------\\   |       |         \\  |      |  \\     *\n                                        *   |    |  /        \\  |  /        \\  |       |          | |      |   \\    *\n                                        *   |___/  /          \\ | /          \\ |______ |     \\___/  |_____ |    \\   *\n                                        *                                                                           *\n                                        *****************************************************************************\n                                        *                                                                           *\n                                        *                                                                           * \n                                        *    A Project by :   Sahib Sethi , Amanpreet Singh Gujral , Rohan Arora    *\n                                        *                                                                           *\n                                        *                                                                           *\n                                        *****************************************************************************");
	printf("\n\n\n\n\n\nChoose the Open Data you want to analyse\n\n\n1.)Crime Against Women\n\n\t%c The data refers to State/UT wise crime committed against women  during the years 2001 - 2012 . The different crime heads covered are Rape, Kidnapping And Abduction, Dowry Deaths, Assault On Women With Intent To Outrage Her Modesty, Insult To The Modesty Of Women, Cruelty By Husband Or His Relatives (IPC Section 498A), Importation Of Girls From Foreign Country, Immoral Traffic (P) Act, Dowry Prohibition Act, Indecent Representation Of Women (P) Act, Commission Of Sati Prevention Act and Total Crimes Against Women.\nSource : http://data.gov.in/catalog/crime-against-women\n\n\n2.)Total No of Persons Injured in road accidents\n\n\t%c Data on road accidents in India are collected by Transport Research Wing (TRW) of Ministry of Road Transport & Highways, in terms of 19 items format devised under Asia Pacific Road Accident data (APRAD)/Indian Road Accident Data (IRAD) project of United Nations Economic and Social Commission for the Asia and the Pacific (UN-ESCAP) and are obtained from Police Departments of States/Union Territories in India. The information given in The data refers to State/UTs wise time series data in respect of person injured in road accidents in India during the period.",15,15);
	while(invalid == 1){
		scanf("%d",&choose);
		switch(choose){
			case 1: 
				CAWOnly();
				invalid = 0;
				break;
			case 2: 
				TAOnly();
				invalid = 0;
				break;
			case 3: 
				//Both();
				invalid = 0;
				break;
			default:
				printf("\nInvalid choice choose again\n");
		}
	}
	getchar();
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n                                        *****************************************************************************\n                                        *    ___            _________                         ___    _____  ____    *\n                                        *   |   \\       /\\      |      /\\      |    \\     /  /   \\  |      |    \\   *\n                                        *   |    |     /  \\     |     /  \\     |     \\   /  |       |      |     |  *\n                                        *   |    |    /    \\    |    /    \\    |      \\ /    \\___   |___   |____/   *\n                                        *   |    |   /------\\   |   /------\\   |       |         \\  |      |  \\     *\n                                        *   |    |  /        \\  |  /        \\  |       |          | |      |   \\    *\n                                        *   |___/  /          \\ | /          \\ |______ |     \\___/  |_____ |    \\   *\n                                        *                                                                           *\n                                        *****************************************************************************\n                                        *                                                                           *\n                                        *                                                                           * \n                                        *    A Project by :  Amanpreet Singh Gujral , Rohan Arora , Sahib Sethi     *\n                                        *                                                                           *\n                                        *                                                                           *\n                                        *****************************************************************************");
	printf("\n\n\n\n\n\n\nThanks for taking interest in our Project.\nWe hope you liked it.\nWe will be uploading source code on GitHub so you guys can also contribute towards our project or may leave feedbacks.\nThanks once again :)\nRohan Arora Git handler : https://github.com/rohanraarora");
	getchar();
	return 0;
}
