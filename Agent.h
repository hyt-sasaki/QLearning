/**
 * @file Agent.h
 * @brief Agentクラスのヘッダファイル
 * @author Hayato Sasaki
 * @version 1
 * @date 2015-04-08
 */
#pragma once
#include "State.h"
#include "Action.h"
#include "Reward.h"
//#include <map>
#include <vector>

using namespace std;

/**
 * @brief 強化学習におけるエージェントを表すクラス
 *
 * 迷路タスクにおける強化学習でエージェントを表すクラス.
 */
class Agent {
    /*! @brief エージェントの現状態 */
    State observation;
    /*! @brief Qテーブル */
    vector<vector<vector<double>>> qTable;
    //map<pair<State, Action>, double> qTable;
    /*! @brief 学習率α */
    double alpha;
    /*! @brief 割引率γ */
    double gamma;
    /*! @brief ε-greedyのε */
    double epsilon;
    /*! @brief εのリスト*/
    vector<double> epsilonList;
    /*! @brief 学習するエピソード数の最大値 */
    const unsigned int episodeLimit;
    /*! @brief epsilonListの要素数 */
    static const unsigned int SPLIT;
    /**
     * @brief ある状態でQ値が最大になる行動を返すプライベートメソッド
     *
     * @param s エージェントの状態
     *
     * @return Q値が最大となっている行動
     *
     * ある状態でQ値が最大になる行動を返す.
     */
    Action getMaxQAction(const State& s) const;
    /**
     * @brief ある状態での最大のQ値を返すプライベートメソッド
     *
     * @param s エージェントの状態
     *
     * @return 状態sでの最大のQ値
     *
     * ある状態sでの最大のQ値を返す.
     */
    double getMaxQ(const State& s) const;
public:
    /**
     * @brief エージェントクラスのコンストラクタ
     *
     * エージェントクラスのデフォルトコンストラクタ.
     */
    Agent() : alpha(0.1), gamma(0.9) , episodeLimit(10000) {
        const unsigned int split = 10;
        for (unsigned int i = 1; i <= split; i++) {
            epsilonList.push_back(1.0 * (double)(split - i) / (double)split);
        }
        this->epsilon = epsilonList.at(0);
    }

    /**
     * @brief Agentクラスのコンストラクタ
     *
     * @param _alpha メンバ変数alphaの初期化値
     * @param _gamma メンバ変数gammaの初期化値
     *
     * Agentクラスのコンストラクタであり,メンバ変数alpha, gammaの値を初期化する.
     */
    Agent(const double _alpha, const double _gamma, const unsigned int _episodeLimit) : alpha(_alpha), gamma(_gamma) , episodeLimit(_episodeLimit) {
        const unsigned int split = 10;
        for (unsigned int i = 1; i <= split; i++) {
            epsilonList.push_back(1.0 * (double)(split - i) / (double)split);
        }
        this->epsilon = epsilonList.at(0);
    }

    /**
     * @brief エージェントの次の行動を決定するメソッド
     *
     * @return エージェントが次に行う行動
     *
     * エージェントの状態やQテーブルの値を元に次の行動を決定する.
     */
    Action getNextAction();

    /**
     * @brief 観測を元にエージェントの状態を決定するメソッド
     *
     * @param state 環境から観測される状態
     *
     * 観測を元にエージェントの状態を決定するメソッドで,メンバ変数observationのsetterメソッドとして働く.
     */
    void observe(const State& state) {
        this->observation = state;
    }

    /**
     * @brief Qテーブルの値を更新するメソッド
     *
     * @param reward 環境から得られる報酬値
     * @param action エージェントが行った行動
     *
     * 環境から得られる報酬とエージェントの行動,現在のQテーブルの値を元に,Qテーブル(メンバ変数qTable)の値を更新する.
     */
    void calcQTable(const Action& action, const Reward& reward, const State& state);

    /**
     * @brief Qテーブルの値を初期化するメソッド
     *
     * @param width 迷路の幅
     * @param height 迷路の高さ
     *
     * Qテーブルの値を初期化する.
     */
    void initQTable(const int width, const int height);

    /**
     * @brief Qテーブルの値を表示する
     */
    void printQTable() const;

    /**
     * @brief エピソード数に応じて学習パラメータを変更するメソッド
     *
     * @param episodes 学習のエピソード数
     *
     * エピソード数に応じてメンバ変数epsilonなどの学習パラメータを調整する.
     */
    void transParameters(const int episodes);
};
