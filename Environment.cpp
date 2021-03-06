/**

 * @file Environment.cpp
 * @brief Environmentクラスのソースファイル
 * @author Hayato Sasaki
 * @version 1
 * @date 2015-04-08
 */
#include "Environment.h"
#include <stdexcept>

vector<vector<MazeObject>> Environment::createMaze(ifstream& ifs) const {
    string str;
    vector<vector<MazeObject>> ylist;
    while (getline(ifs, str)) {
        vector<MazeObject> xlist;
        xlist.reserve(str.length());
        for (unsigned int i = 0; i < str.length(); i++) {
            MazeObject mo;
            bool inputCheck = true;
            try {
                mo = Environment::MAZE_OBJECT_INPUT_DIC.at(str[i]);
            } catch (const out_of_range& e) {
                inputCheck = false;
            }
            if (inputCheck) {
                xlist.push_back(mo);
            }
        }
        ylist.push_back(xlist);
    }

    return ylist;
}

void Environment::printEnv() const {
    for (unsigned int y = 0; y < this->maze.size(); y++) {
        for (unsigned int x = 0; x < this->maze[0].size(); x++) {
            if ((int)x == this->agentPos.first && (int)y == this->agentPos.second) {
                cout << Environment::MAZE_OBJECT_OUTPUT_DIC.at(AGENT) << " "; //エージェントの表示
            } else {
                cout << Environment::MAZE_OBJECT_OUTPUT_DIC.at(this->maze[y][x]) << " ";
            }
        }
        cout << endl;
    }
}

bool Environment::isMovable(const pair<int, int>& pos) const {
    MazeObject mo;  //移動先の迷路の属性
    int x = pos.first;  //移動先のx座標
    int y = pos.second; //移動先のy座標
    /* 移動先が範囲外だった場合にはfalseを返す */
    try {
        mo = this->maze.at(y).at(x);    //out_of_rangeの例外をチェックするため[][]ではなく,at().at()で要素にアクセス
    } catch (const out_of_range& e) {
        return false;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    /* 移動先の属性がWALLだった場合にはfalseを返す */
    if (mo == WALL) {
        return false;
    }

    return true;
}
pair<int, int> Environment::getNextPos(const Action& a) const {
    int x = this->agentPos.first;   //移動前のエージェントのx座標
    int y = this->agentPos.second;  //移動前のエージェントのx座標

    int tmpX;   //移動後のエージェントのx座標
    int tmpY;   //移動後のエージェントのy座標

    tmpX = x + ACTION_TO_DIRECTION.at(a).first;
    tmpY = y + ACTION_TO_DIRECTION.at(a).second;

    return pair<int, int>(tmpX, tmpY);
}

void Environment::transNextEnv(const Action& a) {
    pair<int, int> nextPos = getNextPos(a);

    if (isMovable(nextPos)) {
        this->agentPos = nextPos;
    }
}

State Environment::getAgentState() const {
    return State(this->agentPos.first, this->agentPos.second);
}

Reward Environment::getAgentReward(const Action& a) const {
    Reward reward;
    pair<int, int> nextPos = getNextPos(a);

    if (!isMovable(nextPos)) {  //移動不可の場合
        reward = Reward(Reward::OBS_VALUE);
    } else {
        if (this->maze[nextPos.second][nextPos.first] == GOAL) {
            reward = Reward(Reward::GOAL_VALUE);
        } else {
            reward = Reward(Reward::FREE_VALUE);
        }
    }

    return reward;
}

void Environment::resetAgentPos() {
    for (unsigned int y = 0; y < this->maze.size(); y++) {
        for (unsigned int x = 0; x < this->maze.at(0).size(); x++) {
            if (this->maze.at(y).at(x) == START) {
                this->agentPos = pair<int, int>(x, y);
            }
        }
    }
}

pair<int, int> Environment::getSize() const {
    const int width = maze.at(0).size();
    const int height = maze.size();
    return pair<int, int>(width, height);
}

const map<MazeObject, char> Environment::MAZE_OBJECT_OUTPUT_DIC =
{
    {WALL, '#'},
    {PASSAGE, ' '},
    {START, 'S'},
    {GOAL, 'G'},
    {AGENT, '@'},
};

const map<char, MazeObject> Environment::MAZE_OBJECT_INPUT_DIC =
{
    {'X', WALL},
    {'0', PASSAGE},
    {'S', START},
    {'G', GOAL},
};
