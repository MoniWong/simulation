#pragma once

constexpr auto 完全正常 = 0;
constexpr auto 无法打开图文件 = 1;
constexpr auto 无法找到节点 = 2;
constexpr auto session创建失败 = 4;
constexpr auto session关闭失败 = 8;
constexpr auto session删除失败 = 16;
constexpr auto 未创建session = 32;
constexpr auto session运行失败 = 64;
constexpr auto tensor尺寸错误 = 128;