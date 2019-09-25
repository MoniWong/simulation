#pragma once

constexpr auto 停止动作 = 10000;
constexpr auto 云台_向上 = 10001;
constexpr auto 云台_向下 = 10002;
constexpr auto 云台_向左 = 10003;
constexpr auto 云台_向右 = 10004;
constexpr auto 云台_左上 = 10005;
constexpr auto 云台_右上 = 10006;
constexpr auto 云台_左下 = 10007;
constexpr auto 云台_右下 = 10008;
constexpr auto ZOOM_扩大 = 10009;
constexpr auto ZOOM_缩小 = 10010;
constexpr auto FOCUS_远 = 10011;
constexpr auto FOCUS_近 = 10012;
constexpr auto 打开夜视 = 10013;
constexpr auto 关闭夜视 = 10014;
constexpr auto 设置PTZF = 10015;
constexpr auto 查询PTZF = 10016;

constexpr auto 普通监听 = 20000;
constexpr auto 应答PTZF = 20001;

constexpr auto 开始巡航 = 60000;
constexpr auto 停止巡航 = 60001;

constexpr auto 加载模型 = 50000;
constexpr auto 卸载模型 = 50001;