/**
 * @file Reward.h
 * @brief Rewardクラスを定義するヘッダファイル
 * @author Hayato Sasaki
 * @version 1
 * @date 2015-04-08
 */
#pragma once

/**
 * @brief 強化学習における報酬を表すクラス
 *
 * 迷路タスクにおける強化学習で報酬を表すクラス.
 */
class Reward {
    /*! @brief 報酬を表すメンバ変数 */
    int reward;
public:
    /**
     * @brief Rewardクラスのコンストラクタ
     *
     * Rewardクラスのコンストラクタ.@n
     * メンバ変数であるrewardを初期化する.
     */
    Reward() : reward(0) {
    };
    /**
     * @brief Rewardクラスのコンストラクタ
     *
     * @param _reward メンバ変数rewardを初期化する値
     *
     * Rewardクラスのコンストラクタ.@n
     * メンバ変数であるrewardを初期化する.
     */
    Reward(const int _reward) : reward(_reward) {
    };

    /**
     * @brief 報酬値を返すgetterメソッド
     *
     * @return 報酬値(int型)
     */
    int getReward() const {
        return reward;
    }

    /*! @brief スタート地点での報酬値 */
    static const int START_VALUE;
    /*! @brief ゴール地点での報酬値 */
    static const int GOAL_VALUE;
    /*! @brief 障害物に衝突したときの報酬値 */
    static const int OBS_VALUE;
    /*! @brief スタート・ゴール地点ではなく,障害物にも衝突していないときの報酬値 */
    static const int FREE_VALUE;
};
