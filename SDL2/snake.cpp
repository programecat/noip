#include <iostream>
#include <time.h>
#include <math.h>
#include <deque>
#include <SDL2/SDL.h>
#include <SDL_image.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


const int maxw = 800;
const int maxh = 600;

SDL_Renderer *renderer;
SDL_Window *window;

typedef struct {
	SDL_Rect head;
	SDL_Texture *texture;
	int s;
	int direction;
	deque<SDL_Rect> sp;
}Snake;

Snake snake;
SDL_Rect foodRect{300,500,20,20};

int printFood()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF); //食物颜色 
	SDL_RenderFillRect(renderer, &foodRect);
	SDL_SetRenderDrawColor(renderer, 0, 0x90, 0x70, 0xFF);//背景颜色,四个参数为 渲染器ren,r,g,b,a(透明度)
}

void initSnake() {
	snake.s = 20;
	snake.direction = 1;
	for (int i = 0; i < 5; i++) {
		snake.head = {300, 400 + snake.s * i, snake.s, snake.s};
		snake.sp.push_front(snake.head);
	}
}

int printSnake()//画蛇
{
	if (renderer == NULL) return 0;
	for(int i=0;i<snake.sp.size();i++) {
		SDL_RenderCopy(renderer, snake.texture, NULL,&(snake.sp[i]));
	}
	return 1;
}

int UpMove()//上移
{
	snake.head.y -= snake.s;
	snake.sp.push_front(snake.head);//蛇头前加1节
	snake.sp.pop_back();//蛇尾减少1节
	snake.direction=1;
	//蛇行走原理:蛇头前加1节,蛇尾减少1节
}
int DownMove()//下移
{
	snake.head.y += snake.s;
	snake.sp.push_front(snake.head);//蛇头前加1节
	snake.sp.pop_back();
	snake.direction=2;
}
int LeftMove()//左移
{
	snake.head.x -= snake.s;
	snake.sp.push_front(snake.head);//蛇头前加1节
	snake.sp.pop_back();
	snake.direction=3;
}
int RightMove()//右移
{
	snake.head.x += snake.s;
	snake.sp.push_front(snake.head);//蛇头前加1节
	snake.sp.pop_back();
	snake.direction=4;
}

int addLong()//蛇增长
{
	if(snake.direction==1)
	{
		snake.head.y-=snake.s;
		snake.sp.push_front(snake.head);
		//蛇头前增加1节
	}
	if(snake.direction==2)
	{
		snake.head.y += snake.s;
		snake.sp.push_front(snake.head);
	}
	
	if(snake.direction==3)
	{
		snake.head.x-=snake.s;
		snake.sp.push_front(snake.head);
	}
	if(snake.direction==4)
	{
		snake.head.x += snake.s;
		snake.sp.push_front(snake.head);
	}
}

int init() {

    int result = 1;

    srand(time(NULL));

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("%s\n", SDL_GetError());
        result = 0;
    }

    if (IMG_Init(IMG_INIT_PNG) < 0) {
        printf("%s\n", IMG_GetError());
        result = 0;
    }

    window = SDL_CreateWindow("Snake",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              maxw,
                              maxh,
                              SDL_WINDOW_RESIZABLE);

    if (window == NULL) {
        printf("%s\n", SDL_GetError());
        result = 0;
    }

    // TODO: find out why
    // SDL_RENDERER_ACCELERATED is very slow on mac os.
    // SDL_RENDERER_SOFTWARE seems to work the same way on all 3 platforms
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        printf("%s\n", SDL_GetError());
        result = 0;
    }

    return result;
}

int loadAssets(const char* file) {

    int result = 1;
    
    SDL_Surface* s = IMG_Load(file);
    if (s == NULL) {
        printf("IMG Error: %s\n", IMG_GetError());
        return 0;
    }

    snake.texture = SDL_CreateTextureFromSurface(renderer, s);
    if (snake.texture == NULL) {
        printf("%s\n", SDL_GetError());
        return 0;
    }

    SDL_FreeSurface(s);
    return result;
}


int main(int argc, char** argv) {
    if (!init()) {
        printf("Could not initialize game\n");
        return 2;
    } 
	else 
	{
       if (!loadAssets("1.jpg")) {
           printf("Could not load assets\n");
           return 2;
       }
       
       initSnake();
       
       SDL_Event event;
       int quit = 0;

       while (!quit) {

           while (SDL_PollEvent(&event) != 0) {

               if (event.type == SDL_QUIT) {
                   quit = 1;
               }

               if (event.type == SDL_MOUSEBUTTONDOWN) {
            		initSnake();
            		continue;
               }
               
               if( event.type == SDL_KEYDOWN )
				{
					switch( event.key.keysym.sym )
					{
						case SDLK_UP:
						UpMove();
						break;

						case SDLK_DOWN:
          				DownMove();
          				break;

						case SDLK_LEFT:
						LeftMove();
						break;

						case SDLK_RIGHT:
						RightMove();
						break;

						default:
						break;
					}
				}
           }

           // render
           SDL_RenderClear(renderer);

           printSnake();
           printFood();

           SDL_RenderPresent(renderer);
       }

       IMG_Quit();
	   SDL_DestroyRenderer(renderer);
	   SDL_DestroyWindow(window);
	   SDL_Quit();
    }
	return 0;
}
