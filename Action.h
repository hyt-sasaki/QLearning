/**
 * @file Action.h
 * @brief Actionクラスを定義するヘッダファイル
 * @author Hayato Sasaki
 * @version 1
 * @date 2015-04-08
 */
#pragma once

/**
 * @enum
 * @brief 迷路タスクにおける行動の列挙型
 *
 * 迷路タスクにおける行動の列挙型で上下左右が定義される.
 */
enum EMazeAction {
    UP, DOWN, LEFT, RIGHT,
};

/**
 * @brief 強化学習における行動を表すクラス
 *
 * 迷路タスクにおける強化学習でエージェントの行動を表すクラス.
 */
class Action {
    /*! @brief 行動を表すメンバ変数 */
    EMazeAction action;
public:
    /**
     * @brief Actionクラスのコンストラクタ
     *
     * @param _action メンバ変数actionを初期化する値
     *
     * Actionクラスのコンストラクタ.@n
     * メンバ変数であるactionを初期化する.
     */
    Action(const EMazeAction& _action) : action(_action) {
    };

    /**
     * @brief ==演算子のオーバーロード
     *
     * @param a 比較を行うActionオブジェクト
     *
     * @return thisオブジェクトとオブジェクトaが等しいかどうかのbool値
     *
     * ==演算子のオーバーロードで,thisオブジェクトとオブジェクトaの比較を行う.
     */
    bool operator==(const Action& a) const {
        if (this->action == a.action) {
            return true;
        }
        return false;
    }
    /**
     * @brief !=演算子のオーバーロード
     *
     * @param a 比較を行うActionオブジェクト
     *
     * @return thisオブジェクトとオブジェクトaが等しくないかどうかのbool値
     *
     * !=演算子のオーバーロードで,thisオブジェクトとオブジェクトaの比較を行う.
     */
    bool operator!=(const Action& a) const {
        if (this->action == a.action) {
            return false;
        }
        return true;
    }

    /**
     * @brief メンバ変数actionを返すgetterメソッド
     *
     * @return メンバ変数action
     */
    EMazeAction getAction() const {
        return this->action;
    }
};
