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
    return INTEGER_TO_ACTION.at(rnd() % INTEGER_TO_ACTION.size());
}

void Agent::calcQTable(const Reward& reward) {

}

void Agent::initQTable() {

}
