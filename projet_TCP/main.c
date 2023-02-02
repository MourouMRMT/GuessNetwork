#include <SDL2/SDL.h>
#include <stdbool.h>

#define WIDTH 300
#define HEIGHT 300
#define MARGIN 50

enum { NOUGHTS, CROSSES, BLANK };

struct Cell {
    int value;
    SDL_Rect rect;
};

struct GameState {
    int turn;
    struct Cell board[3][3];
};

void draw_board(SDL_Renderer *renderer, struct GameState *game) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 1; i < 3; i++) {
        SDL_RenderDrawLine(renderer, MARGIN, i * HEIGHT / 3 + MARGIN, WIDTH - MARGIN, i * HEIGHT / 3 + MARGIN);
        SDL_RenderDrawLine(renderer, i * WIDTH / 3 + MARGIN, MARGIN, i * WIDTH / 3 + MARGIN, HEIGHT - MARGIN);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game->board[i][j].value == NOUGHTS) {
                int x = game->board[i][j].rect.x + MARGIN / 2;
                int y = game->board[i][j].rect.y + MARGIN / 2;
                SDL_RenderDrawLine(renderer, x, y, x + HEIGHT / 3 - MARGIN, y + HEIGHT / 3 - MARGIN);
                SDL_RenderDrawLine(renderer, x + HEIGHT / 3 - MARGIN, y, x, y + HEIGHT / 3 - MARGIN);
            } else if (game->board[i][j].value == CROSSES) {
                SDL_RenderDrawLine(renderer, game->board[i][j].rect.x + MARGIN / 2, game->board[i][j].rect.y + MARGIN / 2,
                                   game->board[i][j].rect.x + HEIGHT / 3 - MARGIN / 2,
                                   game->board[i][j].rect.y + HEIGHT / 3 - MARGIN / 2);
                SDL_RenderDrawLine(renderer, game->board[i][j].rect.x + HEIGHT / 3 - MARGIN / 2, game->board[i][j].rect.y + MARGIN / 2,
                                   game->board[i][j].rect.x + MARGIN / 2,
                                   game->board[i][j].rect.y + HEIGHT / 3 - MARGIN / 2);
            }
        }
    }
    SDL_RenderPresent(renderer);
}

bool has_won(int player, struct GameState *game) {
    for (int i = 0; i < 3; i++) {
        if (game->board[i][0].value == player && game->board[i][1].value == player && game->board[i][2].value == player) {
            return true;
        }
        if (game->board[0][i].value == player && game->board[1][i].value == player && game->board[2][i].value == player) {
            return true;
        }
    }
    if (game->board[0][0].value == player && game->board[1][1].value == player && game->board[2][2].value == player) {
        return true;
    }
    if (game->board[0][2].value == player && game->board[1][1].value == player && game->board[2][0].value == player) {
        return true;
    }
    return false;
}
