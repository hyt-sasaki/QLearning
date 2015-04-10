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

void Agent::initQTable() {

}
