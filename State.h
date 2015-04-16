/**
 * @file State.h
 * @brief Stateクラスを定義するヘッダファイル
 * @author Hayato Sasaki
 * @version 1
 * @date 2015-04-08
 */
#pragma once

/**
 * @brief 強化学習におけるエージェントの状態を表すクラス
 *
 * 迷路タスクにおける強化学習でエージェントの状態を表すクラス.
 */
class State {
    /*! @brief エージェントの迷路におけるx座標 */
    int x;
    /*! @brief エージェントの迷路におけるy座標 */
    int y;
public:
    /**
     * @brief Stateクラスのデフォルトコンストラクタ
     */
    State() {
    }

    /**
     * @brief Stateクラスのコンストラクタ
     *
     * @param _x メンバ変数xを初期化するための値
     * @param _y メンバ変数yを初期化するための値
     */
    State(const int _x, const int _y) : x(_x), y(_y) {
    }

    /**
     * @brief エージェントのx座標を返すgetterメソッド
     *
     * @return エージェントのx座標
     */
    int getX() const {
        return this->x;
    }

    /**
     * @brief エージェントのy座標を返すgetterメソッド
     *
     * @return エージェントのy座標
     */
    int getY() const {
        return this->y;
    }
};
