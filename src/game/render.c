#include "render.h"

void refreshRenderer(SDL_Renderer *renderer, TTF_Font *font, HandList *hand){
    char src[] = "Scrabbleboard.jpg";
    char stn[] = "stones_texture_de.png";
    int ii, jj;

    if(font == NULL){
        SDL_Log("font basfqampf qfq");
        exit(1);
    }
    generateBoard(renderer, src);
    //SDL_Log("board generated");
    for(ii=0;ii<15;ii++){
        for(jj=0;jj<15;jj++){
            if(board[ii][jj].Stone != -1){
                //SDL_Log("it szopik");
                drawStone(renderer, stn, board[ii][jj].Stone, board[ii][jj].x, board[ii][jj].y, 55, 55);
            }
        }
    }
    //SDL_Log("Board faszomgecivze");
    drawText(renderer,font,1000,25,300,100,"Scrabble");
    //SDL_Log("textelve 1");
    drawText(renderer, font, 900, 150, 150, 40, "Your hand:");
    drawText(renderer, font, 900, 300, 300, 40, "F - Enter this word");
    drawText(renderer, font, 900, 350, 300, 40, "R - Reset this move");
    drawText(renderer, font, 900, 400, 236, 40, "G - New letters");
    //SDL_Log("szexelve 2");
    drawHand(renderer, hand, stn);
    //SDL_Log("megbaszva 3");

    //drawButton(renderer, font, &ResetButton);
}
