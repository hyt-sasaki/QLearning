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
        return INTEGER_TO_ACTION.at(rnd() % INTEGER_TO_ACTION.size());
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
    return INTEGER_TO_ACTION.at(actionIdx);
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
            cout << "(" << x << ", " << y << ")\t";
            for (int a = 0; a < ACTION_NUM; a++) {
                const string action_str = ACTION_TO_STRING.at(INTEGER_TO_ACTION.at(a));
                cout << action_str << " : " << this->qTable[y][x][a] << ", ";
            }
            cout << endl;
        }
    }
}

void Agent::transParameters(const int episodes) {
    const unsigned int episodeSplit = this->episodeLimit / Agent::SPLIT;
    if (episodes % episodeSplit == 0 && episodes / episodeSplit < Agent::SPLIT) {
        this->epsilon = this->epsilonList.at(episodes / episodeSplit);
    }
}

const unsigned int Agent::SPLIT = 10;
