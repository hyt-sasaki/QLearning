/**
 * @file Action.h
 * @brief Actionクラスを定義するヘッダファイル
 * @author Hayato Sasaki
 * @version 1
 * @date 2015-04-08
 */
#pragma once
#include <map>
#include <string>

/**
 * @enum Action
 * @brief 迷路タスクにおける行動の列挙型
 *
 * 迷路タスクにおける行動の列挙型で上下左右が定義される.
 */
enum Action {
    UP, RIGHT, DOWN, LEFT, ACTION_NUM,
};

const std::map<Action, std::pair<int, int>> ACTION_TO_DIRECTION =
{
    {UP, std::pair<int, int>(0, -1)},
    {RIGHT, std::pair<int, int>(1, 0)},
    {DOWN, std::pair<int, int>(0, 1)},
    {LEFT, std::pair<int, int>(-1, 0)},
};

const std::map<int, Action> INTEGER_TO_ACTION =
{
    {0, UP},
    {1, RIGHT},
    {2, DOWN},
    {3, LEFT},
};

const std::map<Action, std::string> ACTION_TO_STRING =
{
    {UP, "UP"},
    {RIGHT, "RIGHT"},
    {DOWN, "DOWN"},
    {LEFT, "LEFT"},
};
