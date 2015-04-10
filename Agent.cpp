/**
 * @file Agent.cpp
 * @brief
 * @author Hayato Sasaki
 * @version 1
 * @date 2015-04-08
 */
#include "Agent.h"
#include <random>

Action Agent::getNextAction() {
    random_device rnd;
    switch (rnd() % 4) {
        case 0:
            return UP;
            break;
        case 1:
            return RIGHT;
            break;
        case 2:
            return DOWN;
            break;
        case 3:
            return LEFT;
            break;
        default:
            break;
    }
}

void Agent::calcQTable(const Reward& reward) {

}

void Agent::initQTable(const int width, const int height) {
    for (int y = 0; y < height; y++) {
        vector<vector<double>> q_y;
        for (int x = 0; x < width; x++) {
            vector<double> q_a(ACTION_NUM, 0);
            q_y.push_back(q_a);
        }
        this->qTable.push_back(q_y);
    }
}
