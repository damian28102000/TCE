#pragma once

#include "game.h"

#include <vector>
#include <iostream>

class World
{
public:
    Game* game;
	std::vector<std::vector<unsigned int>> map;
    size_t xSize;
    size_t ySize;
    float TILE_SIZE;
    float WALL_STRIP_WIDTH;

	World(float _height, Game* _game)
	{
        this->game = _game;
        map =
        {   
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 3, 3, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 3, 3, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        };

        this->xSize = map[0].size();
        this->ySize = map.size();
        this->TILE_SIZE = _height / ySize;
        this->WALL_STRIP_WIDTH = game->WINDOW_WIDTH / RAYS;
        std::cout << xSize << std::endl;
        std::cout << ySize << std::endl;
	}

    int getWallContentAt(float x, float y) 
    {
        if (x < 0 || x > this->game->WINDOW_WIDTH/2 || y < 0 || y > this->game->WINDOW_HEIGHT) {
            return 0;
        }
        
        unsigned int mapGridIndexX = floor(x / this->TILE_SIZE);
        unsigned int mapGridIndexY = floor(y / this->TILE_SIZE);
        return this->map[mapGridIndexY][mapGridIndexX];
    }
};

