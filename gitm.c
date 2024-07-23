// name: Niyana Yohannes
// unikey: nyoh0352
// SID: 500498752

// code here
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>


#define ROW 19
#define COL 19
#define MAX_BUFF 11
#define HISTORY_MAX_SIZE 19*19*3
#define CONTINUE 0
#define WIN 1
#define TIE 2

//Function for term
void term(void){
	exit(1);
	//Supress history and exit message
}

//Function for resign
void resign (char *playerp){
	if(*playerp == 'B'){
		printf("White wins!\n");
	}
	else if(*playerp == 'W'){
		printf("Black wins!\n");
	}
}

//Function for view
void view(char (*mapp)[COL], int * const mistXp, int * const mistYp){
	
	char view_string[54] = {'\0'}; //Max Length of View String

	//mistX is Letter Coordinate (-1 to get base 0 index)
	char letter = (*mistXp-1) + 'A'; 
	char letter_null_term[] = {letter, '\0'};
	strcat(view_string,letter_null_term);

	//mistY is Integer Coordinate
	char y_as_string[3];
	sprintf(y_as_string, "%d", (*mistYp));
	strcat(view_string, y_as_string);

	//Add ','
	strcat(view_string, ",");

	//Print the mist
	int centre_row = 18 - (*mistYp-1);
	int centre_col = *mistXp - 1;

	//Starting at Top Left of Mist
	int top_left_mist_row = centre_row - 3;
	int top_left_mist_col = centre_col - 3;
	for(int i = top_left_mist_row; i < top_left_mist_row + 7; i++){
		for(int j = top_left_mist_col; j < top_left_mist_col + 7 ; j++){
			if(i < 0 || i > 18)
				strcat(view_string, "x");
			else if (j < 0 || j > 18)
				strcat(view_string, "x");
			else{
				char temp[] = {*(*(mapp+i) + j), '\0'};
				strcat(view_string, temp);
			}
		}
	}

	printf("%s\n", view_string);
}

//Function for history
void history(char *hist){
	printf("%s\n", hist);
}

//Function for end
void end(void){
	printf("Thank you for playing!\n");
	exit(0);
}

//function for win/tie
int wintie(char (*mapp)[COL] ){
	//Tie
	int no_space_remains = 0;
	for (int i = 0; i < ROW; i++) {
	    for (int j = 0; j < COL; j++) {
	    	if (*(*(mapp+i) + j) == '.')
	    		no_space_remains++;
	    }
	}
	if(no_space_remains == 0){
		printf("Wow, a tie!\n");
		return TIE;
	}
	//Horizontal
	for (int i = 0; i < ROW; i++) {
	    for (int j = 0; j < COL - 4; j++) {
	    	if (*(*(mapp+i) + j) == '#' && *(*(mapp+i) + j+1) == '#' 
	      		&& *(*(mapp+i) + j+2) == '#' && *(*(mapp+i) + j+3) == '#' 
	      		&& *(*(mapp+i) + j+4) == '#') {
	        	printf("Black wins!\n");
	        	return WIN;

	      	}
	      	else if (*(*(mapp+i) + j) == 'o' && *(*(mapp+i) + j+1) == 'o' 
	      		&& *(*(mapp+i) + j+2) == 'o' && *(*(mapp+i) + j+3) == 'o' 
	      		&& *(*(mapp+i) + j+4) == 'o') {
	        	printf("White wins!\n");
	        	return WIN;
	      	}
		}
	}
	//Vertical
	for (int i = 0; i < COL; i++) {
	    for (int j = 0; j < ROW - 4; j++) {
	    	if (*(*(mapp+j) + i) == '#' && *(*(mapp+j+1) + i) == '#' 
	      		&& *(*(mapp+j+2) + i) == '#' && *(*(mapp+j+3) + i) == '#' 
	      		&& *(*(mapp+j+4) + i) == '#') {
	        	printf("Black wins!\n");
	        	return WIN;
	      	}
	      	else if (*(*(mapp+j) + i) == 'o' && *(*(mapp+j+1) + i) == 'o' 
	      		&& *(*(mapp+j+2) + i) == 'o' && *(*(mapp+j+3) + i) == 'o' 
	      		&& *(*(mapp+j+4) + i) == 'o') {
	        	printf("White wins!\n");
	        	return WIN;
	      	}
		}
	}	
    //Check diagonals from top-left to bottom-right
    for (int i = 0; i < ROW - 4; i++){
    	for (int j = 0; j < COL - 4; j++){
	    	if (*(*(mapp+i) + j) == '#' && *(*(mapp+i+1) + j+1) == '#' 
	      		&& *(*(mapp+i+2) + j+2) == '#' && *(*(mapp+i+3) + j+3) == '#' 
	      		&& *(*(mapp+i+4) + j+4) == '#') {
	        	printf("Black wins!\n");
	        	return WIN;
	      	}
	      	else if (*(*(mapp+i) + j) == 'o' && *(*(mapp+i+1) + j+1) == 'o' 
	      		&& *(*(mapp+i+2) + j+2) == 'o' && *(*(mapp+i+3) + j+3) == 'o' 
	      		&& *(*(mapp+i+4) + j+4) == 'o') {
	        	printf("White wins!\n");
	        	return WIN;
	      	}
    	}
    } 
    //Check diagonals from top-right to bottom-left
    for (int i = 0; i < ROW - 4; i++){
    	for (int j = COL-1; j > 3; j--){
	    	if (*(*(mapp+i) + j) == '#' && *(*(mapp+i+1) + j-1) == '#' 
	      		&& *(*(mapp+i+2) + j-2) == '#' && *(*(mapp+i+3) + j-3) == '#' 
	      		&& *(*(mapp+i+4) + j-4) == '#') {
	        	printf("Black wins!\n");
	        	return WIN;
	      	}
	      	else if (*(*(mapp+i) + j) == 'o' && *(*(mapp+i+1) + j-1) == 'o' 
	      		&& *(*(mapp+i+2) + j-2) == 'o' && *(*(mapp+i+3) + j-3) == 'o' 
	      		&& *(*(mapp+i+4) + j-4) == 'o') {
	        	printf("White wins!\n");
	        	return WIN;
	      	}
    	}
    }
    //No Win or Tie 
	return CONTINUE;
}

//function for place
char* place(char (*mapp)[COL], char *playerp, char *hist, 
	char letter, int digit, int * const mistXp, int * const mistYp){

	//Convert Character Coordinate to Integer 
	int y = letter - 'A'; 
	int x = -(digit-1) + 18; //Flip x as 1 starts at bottom of map

	//Check if map is unoccupied and fill with character
	if( *(*(mapp+x) + y) == '.'){

		if(*playerp == 'B'){
			*(*(mapp+x) + y) = '#';
			playerp++;
		}
		else if (*playerp == 'W'){
			*(*(mapp+x) + y) = 'o';
			playerp--;
		}
		
		//Add Move to History
		char letter_null_term[2] = {letter, '\0'};
		char digit_as_string[3];
		sprintf(digit_as_string, "%d", digit);
		strcat(hist, letter_null_term);
		strcat(hist, digit_as_string);

		//Check for winner each move
		int game_cond = wintie(mapp);
		if(game_cond == WIN || game_cond == TIE){
			history(hist);
			end();
		}
			
		//Move Mist (hole's centre)
		*mistXp = 1 + (( 5*(digit)*(digit) + 3*(digit) + 4 ) % 19);
		*mistYp = 1 + (( 4*(y+1)*(y+1) + 2*(y+1) - 4 ) % 19);

		//Return pointer to next player	
		return playerp;
	}

	//If map is occupied, return occupied message and pointer to same player
	else{
		printf("Occupied coordinate\n");
		return playerp;
	}
}

int main() {

	//Initialise map 
	char map[ROW][COL];
	for (int i = 0; i < ROW; ++i) { 
    	for (int j = 0; j < COL; ++j) { 
            map[i][j] = '.';
        }
    }

    //Initialise history array
    char hist[HISTORY_MAX_SIZE] = {"\0"};

    //Initialise pointer to map
    char (*mapp)[COL] = map;

	//Initialise current player
	char Player[] = {'B', 'W'};
	char *playerp = Player;

	//Initialise Initial Mist and Pointers to it
	int mistX = 10; 
	int	mistY = 'J' - 'A' + 1; //+1 to get base 1
	int * const mistXp = &mistX;
	int * const mistYp = &mistY;

	//Initialise Buffer Size
	char buff[MAX_BUFF];

	//Loop through user inputs
	while ( fgets(buff, MAX_BUFF,stdin) != NULL){

    	int white_space_counter1 = 0;
		char c;

		//newline does not exist
		if(!strchr(buff, '\n')){    
			//Counting Whitespace for place instructions
			if(strncmp(buff, "place ",6) == 0){
				while( (c = fgetc(stdin)) != '\n'){
					if(c == ' ')
						white_space_counter1++;
				}
	    	}
	    	//Every other instruction
	    	else
	    		while(fgetc(stdin)!='\n'); //discard until newline
    	}

		buff[strcspn(buff, "\n")] = '\0';

		//WHO
		if(strcmp(buff, "who") == 0){
			printf("%c\n", *playerp);
		}
		//TERM
		else if(strcmp(buff, "term") == 0){
			term();
		}
		//RESIGN
		else if(strcmp(buff, "resign") == 0){
			resign(playerp);
			history(hist);
			end();
		}
		//VIEW
		else if(strcmp(buff, "view") == 0){
			view(mapp, mistXp, mistYp);
		}
		//PLACE
		else if(strncmp(buff, "place ",6) == 0){
			int white_space_counter = 0;
			int digit_coordinate_counter = 0;
			int digit_coordinate;
			
			//Whitespace Counter
			for(int i = 0; buff[i] != '\0' ; ++i){
				if(isspace(buff[i])){
					white_space_counter++;
				}
			}
			//Digit Part of Coordinate Counter
			for(int i = 0; buff[i] != '\0'; ++i){
				digit_coordinate_counter++;
			}

			//Invalid and Invalid Coordinate Cases
			if(white_space_counter > 1 || white_space_counter1 > 0){
				printf("Invalid!\n");
			}
			else if(buff[6] == '\0'){
				printf("Invalid!\n");
			}
			else if(!isalpha(buff[6])){
				printf("Invalid coordinate\n");
			}
			else if(digit_coordinate_counter > 9){
				printf("Invalid coordinate\n");
			}
			else{
				//Valid Case
				if ((isdigit(buff[7]) && buff[8] == '\0')  
				|| (isdigit(buff[7]) && isdigit(buff[8]))){
					digit_coordinate = atoi(&buff[7]);
					if(buff[7] == '0'){
						printf("Invalid coordinate\n");
					}
					else if(buff[6] >= 'A' && buff[6] <= 'S' 
					&& digit_coordinate > 0 && digit_coordinate < 20){
						playerp = place(mapp, playerp, hist, buff[6], digit_coordinate, mistXp, mistYp);
					}
					//Invalid char or digit
					else{
						printf("Invalid coordinate\n");
					}
				}
				else{
					printf("Invalid coordinate\n");
				}
			}
		}
		//HISTORY
		else if(strcmp(buff, "history") == 0)
			history(hist);
		//INVALID CASE
		else
			printf("Invalid!\n");
	}
	return 0;
}