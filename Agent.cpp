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

Action Agent::getMaxQAction(const State& s) const {
    const int x = s.getX();
    const int y = s.getY();
    double maxQ = this->qTable[y][x][0];
    int actionIdx = 0;
    for (int i = 1; i < ACTION_NUM; i++) {
        double q = this->qTable[y][x][i];
        if (q > maxQ) {
            maxQ = q;
            actionIdx = i;
        }
    }
    switch (actionIdx) {
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
