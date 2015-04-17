/**
 * @file main.cpp
 * @brief 迷路タスクをQLearningで解くプログラム
 * @author Hayato Sasaki
 * @version 1
 * @date 2015-04-08
 */
#include "Agent.h"
#include "Environment.h"
#include <vector>
#include <iostream>
#include <ostream>

using namespace std;

int main(int argc, char const* argv[])
{
    ifstream ifs("./testenv4.txt");
    if (ifs.fail()) {
        cout << "ファイル読み込みに失敗しました" << endl;
        return 1;
    }
    ofstream ofs("./result.dat");

    unsigned int episode = 0;
    const unsigned int episodeLimit = 10000;
    const unsigned int split = 10;
    const unsigned int episodeSplit = episodeLimit / split;
    const unsigned int stepLimit = 10000;
    double epsilon[split];
    for (unsigned int i = 1; i <= split; i++) {
        epsilon[i - 1] = 1.0 * (double)(split - i) / (double)split;
    }

    Environment env(ifs);
    Agent agent = Agent();
    while (episode <= episodeLimit) {
        unsigned int step = 0;
        cout << "************************" << endl;
        cout << "episode" << episode << endl;
        cout << "************************" << endl;
        Reward reward;
        while (reward.getReward() != Reward::GOAL_VALUE) {
            State state = env.getAgentState();
            agent.observe(state);
            Action action = agent.getNextAction();
            reward = env.getAgentReward(action);
            if (episode == episodeLimit) {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                env.printEnv();
            }
            env.transNextEnv(action);
            agent.calcQTable(reward);
            step++;
        }
        if (episode == episodeLimit) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            env.printEnv();
        }
        cout << "ゴールまでのステップ数 : " << step << endl;
        ofs << episode << ", " << step << endl;
        env.resetAgentPos();
        episode++;
        if (episode % episodeSplit == 0) {
            agent.setEpsilon(epsilon[episode / episodeSplit]);
        }
    }
    return 0;
}
