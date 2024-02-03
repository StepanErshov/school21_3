#include <stdio.h>

#define WIDTH_SCRING 80
#define HEIGHT_SCRING 25
#define PADLELEFT_START_Y 12
#define PADLERIGHT_START_Y 12
#define PADLELEFT_START_X 3
#define PADLERIGHT_START_X (WIDTH_SCRING - 3)

int movePadleLeft(char);
int movePadleRight(char);

int main(char temp){
    int PadleLeftY = 12;
    int PadleLeftX = 12;

    for(int x = 0; x < 79; x++){
    
        for(int y = 0; y < 24; y++){
    
        if(y > 0 && y < 24 && x == 1 && y == 1){
        
            PadleLeftY += movePadleLeft(temp);
        
        }
    
        if(y > 0 && y < 24 && x == 78 && y == 1){
        
            PadleLeftX += movePadleRight(temp);
        
        }
    
    }

}
    
    return 0;

}

int movePadleLeft(char temp){
    
    int speed = 0;
    
    if(temp = 'a'){
        speed = -1;
    }
    if(temp = 'z'){
        speed = 1;
    
    };
    
    return speed;

}
    
 int movePadleRight(char temp){

    int speed = 0;
    
    if(temp = 'k'){
        speed = -1;
    }
    if(temp = 'm'){
        speed = 1;
    };
    
    return speed;

}

    