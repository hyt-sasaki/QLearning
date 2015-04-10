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
public:
    /**
     * @brief エージェントクラスのコンストラクタ
     *
     * エージェントクラスのコンストラクタ.
     */
    Agent() {
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
     *
     * 環境から得られる報酬と現在のQテーブルの値を元に,Qテーブル(メンバ変数qTable)の値を更新する.
     */
    void calcQTable(const Reward& reward);

    /**
     * @brief Qテーブルの値を初期化するメソッド
     *
     * Qテーブルの値を初期化する.
     */
    void initQTable();
};
