/**
 * @file Agent.cpp
 * @brief
 * @author Hayato Sasaki
 * @version 1
 * @date 2015-04-08
 */
#include "Agent.h"
#include <random>
#include <iostream>

Action Agent::getNextAction() {
    random_device rnd;
    double r = (double)rand() / (double)RAND_MAX;
    if (r < this->epsilon) {
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
    } else {
        return getMaxQAction(this->observation);
    }
}

void Agent::calcQTable(const Action& action, const Reward& reward, const State& state) {
    const int x = this->observation.getX();
    const int y = this->observation.getY();
    double q1 = (1 - this->alpha) * this->qTable[y][x][action];
    double maxQ = getMaxQ(state);
    double q2 = this->alpha * ((double)reward.getReward() + this->gamma * maxQ);
    this->qTable[y][x][action] = q1 + q2;
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

double Agent::getMaxQ(const State& s) const {
    const int x = s.getX();
    const int y = s.getY();
    double maxQ = this->qTable[y][x][0];

    for (int i = 1; i < ACTION_NUM; i++) {
        double q = this->qTable[y][x][i];
        if (q > maxQ) {
            maxQ = q;
        }
    }

    return maxQ;
}

void Agent::printQTable() const {
    for (unsigned int y = 0; y < this->qTable.size(); y++) {
        for (unsigned int x = 0; x < this->qTable[0].size(); x++) {
            for (int a = 0; a < ACTION_NUM; a++) {
                cout << a << " : " << this->qTable[y][x][a] << ", ";
            }
            cout << endl;
        }
    }
}
