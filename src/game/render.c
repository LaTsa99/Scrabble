#include "render.h"

//draws the content of the window
void refreshRenderer(SDL_Renderer *renderer, TTF_Font *font, HandList *hand, t_board board[15][15],
                     char *score_str, t_Stones *Stones, eventTable *events, HandPosition *posOfHands){
    char src[] = "Scrabbleboard.jpg";
    char stn[] = "stones_texture.png";
    int ii, jj;

    //here I take care of jokers as well, so i need these variables
    char input[2];
    char letter;
    SDL_Rect input_pos = {370,350, 80, 40};
    SDL_Color black = {0,0,0};
    SDL_Color white = {255,255,255};
    bool gotit = false;

    //draws board and draws every tiles, that are on the board
    generateBoard(renderer, src);
    for(ii=0;ii<15;ii++){
        for(jj=0;jj<15;jj++){
            if(board[ii][jj].Stone != -1){

                drawStone(renderer, stn, board[ii][jj].Stone, board[ii][jj].x, board[ii][jj].y, 55, 55, Stones);
            }
        }
    }
    //drawing anything that is not on the board
    drawText(renderer,font,1000,25,300,100,"Scrabble");
    drawText(renderer, font, 900, 150, 150, 40, "Your hand:");
    drawText(renderer, font, 900, 300, 300, 40, "F - Enter this word");
    drawText(renderer, font, 900, 350, 300, 40, "R - Reset this move");
    drawText(renderer, font, 900, 400, 450, 40, "G - Change all tiles in hand");
    drawText(renderer, font, 900, 450, 450, 40, "H - Change selected tile in hand");
    drawText(renderer, font, 900, 500, 150, 40, "Esc - Quit");
    drawText(renderer, font, 1100, 800, 100, 60, "Score: ");
    drawText(renderer, font, 1220, 800, 60, 60, score_str);
    drawHand(renderer, hand, stn, Stones, posOfHands);
    if(events->centerError){
        drawText(renderer, font, 900, 600, 500, 40, "Please, place a tile on the star!");
    }
    if(!(events->valid)){
        drawText(renderer, font, 900, 600, 250, 40, "Word isn't valid!");
    }
    if(events->illegal){
        drawText(renderer, font, 900, 600, 210, 40, "Move is illegal!");
    }

    //takes care of placed jokers
    if(events->jokerInput){
        input_text(input, 2, input_pos, black, white, font, renderer, Stones);
        events->jokerInput = 0;
        letter = toupper(input[0]);
        for(ii=0;ii<98 && !gotit;ii++){
            if(Stones[ii].name == letter) gotit = true;
        }
        Stones[events->currentJoker].name = letter;
        Stones[events->currentJoker].x = Stones[ii].x;
        Stones[events->currentJoker].y = Stones[ii].y;
    }

    //makes sure that the background is always black (some sort of bug makes it white sometimes)
    SDL_SetRenderDrawColor(renderer, 0,0,0,0);

}

//FROM INFOC.EET.BME.HU
//I just copied the code from there, modified some statements tho
bool input_text(char *dest, size_t hossz, SDL_Rect teglalap, SDL_Color hatter, SDL_Color szoveg, TTF_Font *font, SDL_Renderer *renderer, t_Stones *Stones) {
    int ii;
    /* Ez tartalmazza az aktualis szerkesztest */
    char composition[SDL_TEXTEDITINGEVENT_TEXT_SIZE];
    composition[0] = '\0';
    /* Ezt a kirajzolas kozben hasznaljuk */
    char textandcomposition[hossz + SDL_TEXTEDITINGEVENT_TEXT_SIZE + 1];
    /* Max hasznalhato szelesseg */
    int maxw = teglalap.w - 2;
    int maxh = teglalap.h - 2;

    dest[0] = '\0';

    bool enter = false;
    bool kilep = false;

    SDL_StartTextInput();
    while (!kilep && !enter) {
        /* doboz kirajzolasa */
        boxRGBA(renderer, teglalap.x, teglalap.y, teglalap.x + teglalap.w - 1, teglalap.y + teglalap.h - 1, hatter.r, hatter.g, hatter.b, 255);
        rectangleRGBA(renderer, teglalap.x, teglalap.y, teglalap.x + teglalap.w - 1, teglalap.y + teglalap.h - 1, szoveg.r, szoveg.g, szoveg.b, 255);
        /* szoveg kirajzolasa */
        int w;
        strcpy(textandcomposition, dest);
        strcat(textandcomposition, composition);
        if (textandcomposition[0] != '\0') {
            SDL_Surface *felirat = TTF_RenderUTF8_Blended(font, textandcomposition, szoveg);
            SDL_Texture *felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
            SDL_Rect cel = { teglalap.x, teglalap.y, felirat->w < maxw ? felirat->w : maxw, felirat->h < maxh ? felirat->h : maxh };
            SDL_RenderCopy(renderer, felirat_t, NULL, &cel);
            SDL_FreeSurface(felirat);
            SDL_DestroyTexture(felirat_t);
            w = cel.w;
        } else {
            w = 0;
        }
        /* kurzor kirajzolasa */
        if (w < maxw) {
            vlineRGBA(renderer, teglalap.x + w + 2, teglalap.y + 2, teglalap.y + teglalap.h - 3, szoveg.r, szoveg.g, szoveg.b, 192);
        }
        /* megjeleniti a képernyon az eddig rajzoltakat */
        SDL_RenderPresent(renderer);

        SDL_Event event;
        SDL_WaitEvent(&event);
        switch (event.type) {
            /* Kulonleges karakter */
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_BACKSPACE) {
                    int textlen = strlen(dest);
                    do {
                        if (textlen == 0) {
                            break;
                        }
                        if ((dest[textlen-1] & 0x80) == 0x00)   {
                            /* Egy bajt */
                            dest[textlen-1] = 0x00;
                            break;
                        }
                        if ((dest[textlen-1] & 0xC0) == 0x80) {
                            /* Bajt, egy tobb-bajtos szekvenciabol */
                            dest[textlen-1] = 0x00;
                            textlen--;
                        }
                        if ((dest[textlen-1] & 0xC0) == 0xC0) {
                            /* Egy tobb-bajtos szekvencia elso bajtja */
                            dest[textlen-1] = 0x00;
                            break;
                        }
                    } while(true);
                }
                if (event.key.keysym.sym == SDLK_RETURN) {
                    for(ii=0;ii<98;ii++){
                        if(toupper(dest[0]) == Stones[ii].name){
                            enter = true;
                        }
                    }

                }
                break;

            /* A feldolgozott szoveg bemenete */
            case SDL_TEXTINPUT:
                if (strlen(dest) + strlen(event.text.text) < hossz) {
                    strcat(dest, event.text.text);
                }

                /* Az eddigi szerkesztes torolheto */
                composition[0] = '\0';
                break;

            /* Szoveg szerkesztese */
            case SDL_TEXTEDITING:
                strcpy(composition, event.edit.text);
                break;

            case SDL_QUIT:
                /* visszatesszuk a sorba ezt az eventet, mert
                 * sok mindent nem tudunk vele kezdeni */
                SDL_PushEvent(&event);
                kilep = true;
                break;
        }
    }

    /* igaz jelzi a helyes beolvasast; = ha enter miatt allt meg a ciklus */
    SDL_StopTextInput();
    return enter;
}
