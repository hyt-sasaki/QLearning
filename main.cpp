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
    ifstream ifs("./testenv0.txt");
    if (ifs.fail()) {
        cout << "ファイル読み込みに失敗しました" << endl;
        return 1;
    }
    ofstream ofs("./result.dat");

    Environment env(ifs);
    Agent agent = Agent();
    const pair<int, int> mazeSize = env.getSize();
    agent.initQTable(mazeSize.first, mazeSize.second);

    unsigned int episode = 0;
    const unsigned int episodeLimit = 200;
    while (episode < episodeLimit) {
        unsigned int step = 0;
        cout << "************************" << endl;
        cout << "episode" << episode << endl;
        cout << "************************" << endl;
        Reward reward;
        State state0 = env.getAgentState();
        agent.observe(state0);
        while (reward.getReward() != Reward::GOAL_VALUE && step < stepLimit) {
            Action action = agent.getNextAction();
            reward = env.getAgentReward(action);
            env.transNextEnv(action);
            State state = env.getAgentState();
            agent.calcQTable(action, reward, state);
            agent.observe(state);
            step++;
        }
        cout << "ゴールまでのステップ数 : " << step << endl;
        ofs << episode << ", " << step << endl;
        env.resetAgentPos();
        episode++;
    }
    return 0;
}
