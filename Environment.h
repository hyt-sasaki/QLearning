/**
 * @file Environment.h
 * @brief Environmentクラスを定義するヘッダファイル
 * @author Hayato Sasaki
 * @version 1
 * @date 2015-04-08
 */
#pragma once
#include "Action.h"
#include "Reward.h"
#include "State.h"
#include <iostream>
#include <string>
#include <istream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

/**
 * @enum MazeObject
 * @brief 迷路の各マス目の属性を表す列挙型
 */
enum MazeObject {
    WALL, PASSAGE, START, GOAL, AGENT,
};

/**
 * @brief 強化学習における環境を表すクラス
 *
 * 迷路タスクにおける強化学習で環境を表すクラス.
 */
class Environment {
    /*! @brief 迷路を表す動的二次元配列 */
    vector<vector<MazeObject>> maze;
    /*! @brief 迷路中でのエージェントの位置 */
    pair<int, int> agentPos;

    /**
     * @brief 迷路ファイルを元に迷路を作成するプライベートメソッド
     *
     * @param ifs 迷路ファイルのインプットストリーム
     *
     * @return 迷路の二次配列
     *
     * 迷路ファイルを元に,各マスがcharで表される迷路の二次元配列を作成し,その値を返す.
     */
    vector<vector<MazeObject>> createMaze(ifstream& ifs) const;

    /**
     * @brief エージェントが移動可能かを返すプライベートメソッド
     *
     * @param pos エージェントの移動先
     *
     * @return エージェントが移動可能の場合にtrue, それ以外の場合にはfalse
     *
     * エージェントが行動を行った結果,移動可能かを判定する.
     */
    bool isMovable(const pair<int, int>& pos) const;

    /**
     * @brief エージェントが行動した後の移動先を返すプライベートメソッド
     *
     * @param a エージェントの環境に対する行動
     *
     * @return 移動先の座標
     *
     * エージェントが行動した後の移動先の座標を返す.@n
     * この際,その座標に移動可能かは判定しない.
     */
    pair<int, int> getNextPos(const Action& a) const;

    static const map<MazeObject, char> MAZE_OBJECT_OUTPUT_DIC;
    static const map<char, MazeObject> MAZE_OBJECT_INPUT_DIC;
public:
    /**
     * @brief Environmentクラスのコンストラクタ
     *
     * Environmentクラスのコンストラクタ.
     */
    Environment() {
    }

    /**
     * @brief Environmentクラスのコンストラクタ
     *
     * @param ifs 迷路ファイルのインプットストリーム
     *
     * 迷路ファイルを読み込んでメンバ変数mazeを初期化する.
     */
    Environment(ifstream& ifs) {
        this->maze = createMaze(ifs);
        resetAgentPos();
    }

    /**
     * @brief 迷路を標準出力に表示する
     *
     * メンバ変数mazeを元に迷路を標準出力に出力する.
     */
    void printEnv() const;

    /**
     * @brief 環境状態を遷移させるメソッド
     *
     * @param a エージェントの環境に対する行動
     *
     * エージェントの行動に応じて環境の内部状態を遷移させるメソッド.@n
     * 具体的にはエージェントの位置を遷移させる.
     */
    void transNextEnv(const Action& a);
    /**
     * @brief エージェントに対して状態を返すメソッド
     *
     * @return エージェントの状態
     *
     * 環境の内部状態に応じてエージェントの状態を返すメソッド.
     */
    State getAgentState() const;
    /**
     * @brief エージェントに対して報酬を返すメソッド
     *
     * @param a エージェントの環境に対する行動
     *
     * @return 報酬
     *
     * 環境の内部状態に応じてエージェントに報酬を渡すメソッド.@n
     */
    Reward getAgentReward(const Action& a) const;

    /**
     * @brief エージェントの位置をリセットするメソッド
     *
     * エージェントの位置(agentPos)をスタート位置にリセットする.
     */
    void resetAgentPos();
};
