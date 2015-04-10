/**
 * @file Action.h
 * @brief Actionクラスを定義するヘッダファイル
 * @author Hayato Sasaki
 * @version 1
 * @date 2015-04-08
 */
#pragma once

/**
 * @enum Action
 * @brief 迷路タスクにおける行動の列挙型
 *
 * 迷路タスクにおける行動の列挙型で上下左右が定義される.
 */
enum Action {
    UP, RIGHT, DOWN, LEFT, ACTION_NUM,
};
