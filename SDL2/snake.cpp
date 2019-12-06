#include <iostream>
#include <time.h>
#include <math.h>
#include <deque>
#include <SDL2/SDL.h>
using namespace std;


const int maxw = 800;
const int maxh = 600;

SDL_Renderer *renderer;
SDL_Window *window;

typedef struct {
	SDL_Rect head;
	SDL_Texture *texture;
	int s; //每节身体的边长 
	int direction;
	deque<SDL_Rect> sp; //deque我们暂时没有讲到，其实我们也可以用数组来代替 
}Snake;

Snake snake;
SDL_Rect foodRect = {300,500,20,20};  //SDL_Rect代表一个矩形，有四个属性，分别是左顶点的x,y坐标和长度和宽度 

int printFood()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF); //食物的颜色是黑色 
	SDL_RenderFillRect(renderer, &foodRect);
}

//初始化小蛇，有5节身体 
void initSnake() {
	snake.s = 20;
	snake.direction = 1;
	snake.head.w = snake.s;
	snake.head.h = snake.s;
	snake.head.x = 300;
	for (int i = 0; i < 5; i++) {
		snake.head.y = 400 + snake.s * i;
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

//蛇行走原理:蛇头前加1节,蛇尾减少1节
int UpMove()//上移
{
	snake.head.y -= snake.s;
	snake.sp.push_front(snake.head);//蛇头前加1节
	snake.sp.pop_back();//蛇尾减少1节
	snake.direction=1;
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

void addLong()//蛇增长
{
	switch (snake.direction) {
		case 1:
		snake.head.y-=snake.s;
		snake.sp.push_front(snake.head);
		break;
		case 2:	
		snake.head.y += snake.s;
		snake.sp.push_front(snake.head);
		break;
		case 3:
			
		snake.head.x-=snake.s;
		snake.sp.push_front(snake.head);
		break;
		case 4:
			
		snake.head.x += snake.s;
		snake.sp.push_front(snake.head);
		break;
		default:
			break;
	}
}

int init() {

    int result = 1;

    srand(time(NULL));

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("%s\n", SDL_GetError());
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
    
    SDL_Surface* s = SDL_LoadBMP(file);
    if (s == NULL) {
        printf("IMG Error: %s\n", SDL_GetError());
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

bool canEatFood() {
	if ((snake.direction == 1 && snake.head.y - snake.s == foodRect.y && snake.head.x == foodRect.x)
		|| (snake.direction == 2 && snake.head.y + snake.s == foodRect.y && snake.head.x == foodRect.x)
		|| (snake.direction == 3 && snake.head.x - snake.s == foodRect.x && snake.head.y == foodRect.y)
		|| (snake.direction == 4 && snake.head.x + snake.s == foodRect.x && snake.head.y == foodRect.y)) {
		addLong();
		SDL_Log("direction is %d, x = %d, y = %d", snake.direction, snake.head.x, snake.head.y);
		return true;
	}
	return false;
} 

void moveSnake() {
	switch (snake.direction) {
		case 1:
		UpMove();
		break;

		case 2:
		DownMove();
		break;

		case 3:
		LeftMove();
		break;

		case 4:
		RightMove();
		break;

		default:
		break;
	}
}


int main(int argc, char** argv) {
    if (!init()) {
        printf("Could not initialize game\n");
        return 2;
    } 
	else 
	{
       if (!loadAssets("snake.bmp")) {
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
						snake.direction = 1;
						break;

						case SDLK_DOWN:
          				snake.direction = 2;
          				break;

						case SDLK_LEFT:
						snake.direction = 3;
						break;

						case SDLK_RIGHT:
						snake.direction = 4;
						break;

						default:
						break;
					}
					
					SDL_Log("direction change to %d", snake.direction);
				}
           }

           // 设置背景色 
        	SDL_SetRenderDrawColor(renderer, 0, 0x90, 0x70, 0xFF);//背景颜色,四个参数为 渲染器,r,g,b,a(透明度)
        	SDL_RenderClear(renderer);
           
       		moveSnake();
       		SDL_Log("snake head x = %d, y = %d, direction = %d", snake.head.x, snake.head.y, snake.direction);
		   
           if (canEatFood()) {
           		//食物的位置变化 
        		foodRect.x = (rand() % (maxw/20)) * 20;
        		foodRect.y = (rand() % (maxh/20)) * 20;
        		SDL_Log("food x = %d, y = %d", foodRect.x, foodRect.y);
		   }
		   
		   printFood();
           printSnake();
		   SDL_RenderPresent(renderer);
			SDL_Delay(250); //这里控制帧速，delay的时间越短，小蛇速度越快
	   }

	   SDL_DestroyRenderer(renderer);
	   SDL_DestroyWindow(window);
	   SDL_Quit();
    }
	return 0;
}
