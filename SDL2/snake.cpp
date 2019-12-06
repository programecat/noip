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
	int s; //ÿ������ı߳� 
	int direction;
	deque<SDL_Rect> sp; //deque������ʱû�н�������ʵ����Ҳ���������������� 
}Snake;

Snake snake;
SDL_Rect foodRect = {300,500,20,20};  //SDL_Rect����һ�����Σ����ĸ����ԣ��ֱ����󶥵��x,y����ͳ��ȺͿ�� 

int printFood()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF); //ʳ�����ɫ�Ǻ�ɫ 
	SDL_RenderFillRect(renderer, &foodRect);
}

//��ʼ��С�ߣ���5������ 
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

int printSnake()//����
{
	if (renderer == NULL) return 0;
	for(int i=0;i<snake.sp.size();i++) {
		SDL_RenderCopy(renderer, snake.texture, NULL,&(snake.sp[i]));
	}
	return 1;
}

//������ԭ��:��ͷǰ��1��,��β����1��
int UpMove()//����
{
	snake.head.y -= snake.s;
	snake.sp.push_front(snake.head);//��ͷǰ��1��
	snake.sp.pop_back();//��β����1��
	snake.direction=1;
}
int DownMove()//����
{
	snake.head.y += snake.s;
	snake.sp.push_front(snake.head);//��ͷǰ��1��
	snake.sp.pop_back();
	snake.direction=2;
}
int LeftMove()//����
{
	snake.head.x -= snake.s;
	snake.sp.push_front(snake.head);//��ͷǰ��1��
	snake.sp.pop_back();
	snake.direction=3;
}
int RightMove()//����
{
	snake.head.x += snake.s;
	snake.sp.push_front(snake.head);//��ͷǰ��1��
	snake.sp.pop_back();
	snake.direction=4;
}

void addLong()//������
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

           // ���ñ���ɫ 
        	SDL_SetRenderDrawColor(renderer, 0, 0x90, 0x70, 0xFF);//������ɫ,�ĸ�����Ϊ ��Ⱦ��,r,g,b,a(͸����)
        	SDL_RenderClear(renderer);
           
       		moveSnake();
       		SDL_Log("snake head x = %d, y = %d, direction = %d", snake.head.x, snake.head.y, snake.direction);
		   
           if (canEatFood()) {
           		//ʳ���λ�ñ仯 
        		foodRect.x = (rand() % (maxw/20)) * 20;
        		foodRect.y = (rand() % (maxh/20)) * 20;
        		SDL_Log("food x = %d, y = %d", foodRect.x, foodRect.y);
		   }
		   
		   printFood();
           printSnake();
		   SDL_RenderPresent(renderer);
			SDL_Delay(250); //�������֡�٣�delay��ʱ��Խ�̣�С���ٶ�Խ��
	   }

	   SDL_DestroyRenderer(renderer);
	   SDL_DestroyWindow(window);
	   SDL_Quit();
    }
	return 0;
}
